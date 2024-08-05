[Run Mixtral-8x7B models in Colab or consumer desktops](https://github.com/dvmazur/mixtral-offloading) 初版，可见 `./benchmarks/mixtral-offloading`

- 2024.7.24 任务：复现[ fiddler ](https://github.com/efeslab/fiddler)的内容
> fiddler 使用 CPU-GPU 编排 快速推理 MoE 模型
- 2024.7.26 了解huggingface，wine，尝试了一些远程环境(Colab, AutoDL, Azure, Kaggle, etc.)
- 2024.7.28 本地试运行了 Mistral-7B
- 2024.8.2 未能解决一些意料之外的bug，改用远程环境。记录先前的踩坑于[problems.md](./problems.md)
- 2024.8.3 成功运行fiddler。接下来测试它的inference time和throughput