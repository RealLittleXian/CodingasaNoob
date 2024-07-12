matrixMul - 矩阵乘法（CUDA Runtime API版本）
描述
此示例实现了矩阵乘法，与编程指南中的第6章完全相同。它被编写为便于说明各种CUDA编程原则，而不是为了提供最具性能的通用矩阵乘法核心。为了展示GPU矩阵乘性能，此示例还展示了如何使用新的CUDA 4.0界面用于CUBLAS，以展示高性能矩阵乘法。

关键概念
CUDA Runtime API，线性代数

支持的SM架构
SM 5.0、SM 5.2、SM 5.3、SM 6.0、SM 6.1、SM 7.0、SM 7.2、SM 7.5、SM 8.0、SM 8.6、SM 8.7、SM 8.9、SM 9.0

支持的操作系统
Linux、Windows

支持的CPU架构
x86_64、ppc64le、armv7l、aarch64

涉及的CUDA API
CUDA Runtime API
cudaStreamCreateWithFlags、cudaProfilerStop、cudaMalloc、cudaFree、cudaMallocHost、cudaProfilerStart、cudaEventSynchronize、cudaEventRecord、cudaFreeHost、cudaStreamSynchronize、cudaEventDestroy、cudaEventElapsedTime、cudaMemcpyAsync、cudaEventCreate

先决条件
下载并安装相应平台的CUDA Toolkit 12.4。

构建和运行
Windows
Windows示例使用Visual Studio IDE构建。提供了每个受支持的Visual Studio版本的解决方案文件（.sln），格式为：

*_vs<version>.sln - 适用于Visual Studio <version>
每个单独样本在其目录中有一组解决方案文件：

要一次构建/检查所有样本，应使用完整的解决方案文件。要构建/检查单个样本，应使用各自的样本解决方案文件。

注意：某些示例要求安装Microsoft DirectX SDK（2010年6月或更新版本）并正确设置VC++目录路径（工具 > 选项...）。在"DirectX Dependencies"部分查看详细信息。

Linux
Linux示例使用makefiles构建。要使用makefiles，将当前目录更改为要构建的示例目录，然后运行make：

$ cd <sample_dir>
$ make
样本makefiles可以利用某些选项：

TARGET_ARCH= - 交叉编译以针对特定架构。允许的架构有x86_64、ppc64le、armv7l、aarch64。默认情况下，TARGET_ARCH设为HOST_ARCH。在x86_64机器上，不设置TARGET_ARCH等同于设置TARGET_ARCH=x86_64。
$ make TARGET_ARCH=x86_64
$ make TARGET_ARCH=ppc64le
$ make TARGET_ARCH=armv7l
$ make TARGET_ARCH=aarch64
点击此处了解更多详细信息。

dbg=1 - 使用调试符号构建

$ make dbg=1
SMS="A B ..." - 覆盖要构建样本的SM架构，其中“A B ...”是SM架构的以空格分隔的列表。例如，要生成SM 50和SM 60的SASS，使用SMS="50 60"。

$ make SMS="50 60"
HOST_COMPILER=<host_compiler> - 覆盖默认的g++主机编译器。请参阅Linux安装指南，了解支持的主机编译器列表。

    $ make HOST_COMPILER=g++
参考资料（更多详细信息）