## Instruction ##

- [start.md](start.md) 一些学习CUDA前的准备工作
- [An Even Easier Introduction to CUDA.md](An%20Even%20Easier%20Introduction%20to%20CUDA.md) CUDA入门教程 笔记
- [record.md](record.md) 根据文档在Colab复现 实验数据记录

## Update ##

- 2024.7.11

    中午收到任务，开始第一次的科研学习。在摸索中前进。

    学会使用Google云端硬盘和Colab。

    因为期望电子版笔记，学习了Markdown语法。

- 2024.7.12

    根据 [An Even Easier Introduction to CUDA](https://developer.nvidia.com/blog/even-easier-introduction-cuda/#memory-allocation) 进行学习，复现了文章的内容。学会GPU上实现矩阵加法。

- 2024.7.17
    由于实验是在Colab上进行的，遇到了一些库需要每次下载的问题。可以使用cuda-sample的代码，要用的时候头文件指过去。

- 2024.7.18

    改进add_grid.cu，做多次循环取平均时间，评估add()函数的耗时。结果准确。