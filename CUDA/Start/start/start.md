# Start #
1. CUDA编程基本：
- [An Even Easier Introduction to CUDA](https://developer.nvidia.com/blog/even-easier-introduction-cuda/) 
- [CUDA C++ Programming Guide](https://docs.nvidia.com/cuda/cuda-c-programming-guide/) （无需从头读到尾，在实践过程中查阅）
2. 编程实现在GPU上做矩阵乘法：
- [matrixMul - Matrix Multiplication (CUDA Runtime API Version)](https://github.com/NVIDIA/cuda-samples/tree/master/Samples/0_Introduction/matrixMul)
- [Matrix Multiplication Background User’s Guide
](https://docs.nvidia.com/deeplearning/performance/dl-performance-matrix-multiplication/index.html)

### 一些有用的资料 ###
[《CUDA C Programming Guide》(《CUDA C 编程指南》)导读](https://zhuanlan.zhihu.com/p/53773183)

[（新手向）从零开始使用Colab进行机器/深度学习详细教程](https://blog.csdn.net/qq_38736504/article/details/105964226)

[使用Google colab免费GPU训练模型攻略](https://zhuanlan.zhihu.com/p/129663051)

### 使用Colab编译和运行CUDA ###
1. 导入Google硬盘

        from google.colab import drive
        drive.mount('/content/drive/')

2. 打开目标文件夹

        %cd '/content/drive/MyDrive'
        !dir

3. 编译CUDA文件
   
        !nvcc 源文件名 -o 输出编译文件名

4. 运行CUDA编译文件

        !./编译文件名

5. 查看运行详细信息
   
        !nvprof ./编译文件名

6. 查看配置

        !nvcc --version
        !nvidia-smi

### Markdown ###

[Markdown Tables Generator](https://www.tablesgenerator.com/markdown_tables)
