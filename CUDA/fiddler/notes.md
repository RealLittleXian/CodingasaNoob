参考资料

[The Correct Way to Measure Inference Time of Deep Neural Networks | by Amnon Geifman | Towards Data Science](https://towardsdatascience.com/the-correct-way-to-measure-inference-time-of-deep-neural-networks-304a54e5187f)

[如何正确测量 PyTorch 模型的推理时间 - 知乎 (zhihu.com)](https://zhuanlan.zhihu.com/p/460524015) 是对上文的简单总结

[torch.profiler — PyTorch 2.4 文档 - PyTorch 中文](https://pytorch.ac.cn/docs/stable/profiler.html)

[使用PyTorch Profiler进行模型性能分析，改善并加速PyTorch训练_profiler优化pytorch性能-CSDN博客](https://blog.csdn.net/deephub/article/details/139622843)

## 测量 inference time

常见错误（由于GPU 执行机制 - 异步执行；GPU 预热）：

1. 在主机和设备之间传输数据。常见错误涉及在进行时间测量时在 CPU 和 GPU 之间传输数据。
2. 不使用 GPU 预热。
3. 使用标准CPU时序。常犯错误是测量时间而不同步。
4. 取1个样品。

```python
model = EfficientNet.from_pretrained(‘efficientnet-b0’)
device = torch.device(“cuda”)
model.to(device)
dummy_input = torch.randn(1, 3,224,224,dtype=torch.float).to(device)
starter, ender = torch.cuda.Event(enable_timing=True), torch.cuda.Event(enable_timing=True)
repetitions = 300
timings=np.zeros((repetitions,1))
#GPU-WARM-UP
for _ in range(10):
   _ = model(dummy_input)
# MEASURE PERFORMANCE
with torch.no_grad():
  for rep in range(repetitions):
     starter.record()
     _ = model(dummy_input)
     ender.record()
     # WAIT FOR GPU SYNC
     torch.cuda.synchronize()
     curr_time = starter.elapsed_time(ender)
     timings[rep] = curr_time
mean_syn = np.sum(timings) / repetitions
std_syn = np.std(timings)
print(mean_syn)
```



## 测量 throughput

神经网络的吞吐量定义为网络可以在一个单位（例如，一秒）内处理的最大输入实例数。了正确测量吞吐量，我们执行以下两个步骤：（1）估计允许最大并行度的最佳 batch size;（2），给定这个最佳batch size，测量网络在一秒钟内可以处理的实例数量。

为了找到最佳的批量大小，一个好的经验法则是达到给定数据类型的 GPU 的内存限制。当然，这个大小取决于硬件类型和网络的大小。找到此最大批量大小的最快方法是执行二进制搜索。

找到最佳批量大小后，我们计算实际吞吐量。为此，我们希望处理许多批次（100 个批次就足够了），然后使用以下公式：

(number of batches X batch size)/(total time in seconds).

这个公式给出了我们的网络在一秒钟内可以处理的样本数量。下面的代码提供了一种执行上述计算的简单方法（给定最佳批量大小）：

```python
model = EfficientNet.from_pretrained(‘efficientnet-b0’)
device = torch.device(“cuda”)
model.to(device)
dummy_input = torch.randn(optimal_batch_size, 3,224,224, dtype=torch.float).to(device)
repetitions=100
total_time = 0
with torch.no_grad():
  for rep in range(repetitions):
     starter, ender = torch.cuda.Event(enable_timing=True),          torch.cuda.Event(enable_timing=True)
     starter.record()
     _ = model(dummy_input)
     ender.record()
     torch.cuda.synchronize()
     curr_time = starter.elapsed_time(ender)/1000
     total_time += curr_time
Throughput = (repetitions*optimal_batch_size)/total_time
print(‘Final Throughput:’,Throughput)
```

# fiddler 源码解释

## infer.py

1. **prefill_time**：在请求处理之前,预填充缓存的耗时。当系统需要处理一个请求时,如果事先将相关的数据预先加载到缓存中,就可以减少处理请求时的延迟。prefill_time就是指这个预填充缓存的耗时。

2. **decode_time**：解码请求数据的耗时。当系统接收到一个请求时,需要首先对请求数据进行解码,才能进行后续的处理。decode_time就是指这个解码过程的耗时。

3. **hit_rate**：缓存命中率。当系统需要处理一个请求时,如果请求的数据已经存在于缓存中,就可以直接从缓存中获取,不需要再次从数据源获取。hit_rate就是指缓存命中的比例,反映了缓存的使用效率。

## mixtral.py

TODO config



```python
    def __init__(self, args):
    ...
        # TODO: find this value based on device config
        self.latency_cpu = 1
        self.latency_gpu = 10
```

```python
    def calc_n_expert_on_gpu(self):
    ...
            free_mem = total_mem * 0.95 - torch.cuda.memory_allocated(self.dev) # TODO: magic number
```

```python
    def generate(self, text=None, output_token=20, input_token=None):
        torch.set_num_threads(16) # TODO: set appropriately
        ...
                if self.beam_width == 1:
                print(self.tokenizer.decode(input_ids[0]))
                # TODO: streaming output for beam search
```
