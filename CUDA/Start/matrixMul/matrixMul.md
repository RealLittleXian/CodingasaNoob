## MatrixMulCUDA() ##
1. 线程和块索引：首先，通过blockIdx和threadIdx获取当前线程在块中的位置。
2. 矩阵分块：将矩阵A和B分成多个小块，每个块的大小为BLOCK_SIZE。这样可以将大矩阵的乘法分解为多个小矩阵的乘法，从而利用GPU的并行计算能力。
3. 共享内存：使用共享内存（`__shared__`）来存储当前块需要处理的小矩阵A和B，以减少全局内存的访问次数，提高性能。
4. 矩阵乘法：每个线程负责计算C矩阵的一个元素，通过循环遍历A和B的小块，进行矩阵乘法运算。
5. 同步：在加载新的子矩阵之前，使用`__syncthreads()`同步线程，确保所有线程都完成了当前步的计算。
   
- `cuda_runtime.h`头文件定义了 CUDA 运行时 API，这些 API 提供了与 GPU 交互的功能。

- `cuda_profiler_api.h`头文件用于分析和优化 CUDA 程序的性能。可以收集和查看 CUDA 程序的运行时性能数据。

- 模板声明：`template <int BLOCK_SIZE>` 表示这是一个模板函数，BLOCK_SIZE 是一个模板参数，可以在调用函数时指定具体的块大小。

- `blockIdx.x`表示当前线程块在网格中的x维度索引。

- 在CUDA编程中，一个网格（grid）由多个线程块（block）组成，每个线程块又由多个线程（thread）组成。`blockIdx`是一个内置变量，它是一个3维的索引，分别表示线程块在网格中的x、y和z维度索引。`blockIdx.x`表示线程块在网格的x维度上的索引。`blockIdx.x`的值范围是从0到gridDim.x-1，其中`gridDim.x`表示网格在x维度上的大小。

- `__shared__`用于声明在共享内存中存储的变量。共享内存是 GPU 上的一个高速缓存区域，用于在同一个线程块中的线程之间共享数据。与全局内存相比，共享内存的访问速度更快，因此可以显著提高 GPU 程序的性能。当多个线程需要共享数据时，使用共享内存可以减少全局内存的访问次数，从而提高数据传输的效率。

- `__syncthreads()`用于同步线程块内的所有线程。为了确保所有线程都完成了某个操作，或者为了防止数据竞争，需要使用同步机制。__syncthreads() 函数在设备代码中执行时，会暂停当前线程块中的所有线程，直到该块中的所有线程都到达这一行代码。一旦所有线程都执行了 __syncthreads()，它们会同时继续执行后续的代码。

- `#pragma unroll` 指令告诉编译器将指定的循环展开。例如，如果你有一个循环，编译器会将其展开为多个迭代，从而减少循环控制指令（如 for 循环的迭代计数和条件检查）的开销。

## MatrixMultiply() ##
- `int argc`：表示命令行参数的数量。
- `char **argv`：指向命令行参数的指针数组。每个元素都是一个字符串，表示一个命令行参数。
- `const dim3 &dimsA`用于定义一个常量引用类型的变量dimsA，其类型为dim3。在Cuda编程中，dim3是一个结构体，用于表示三维空间中的维度，通常用于指定线程块和网格的维度。
    ```cpp
    struct dim3 {
        int x;
        int y;
        int z;
    };
    ```

- `checkCudaErrors()`：这是一个宏或函数，用于检查CUDA函数调用的返回值。如果CUDA函数调用失败，它会打印错误信息并终止程序。这个宏或函数通常定义在CUDA示例代码中，用于简化错误处理。
- `cudaMallocHost()`：用于分配主机内存。与设备内存（由cudaMalloc分配）不同，主机内存是CPU可以直接访问的内存，不需要通过GPU进行数据传输。
- `cudaStream_t` 是一个指向 CUDA 流对象的指针。CUDA 流是一种抽象，用于管理 GPU 上的操作顺序。通过使用流，开发者可以控制哪些操作在何时执行，从而实现并行计算。
- `cudaMalloc`：用于在GPU上分配内存。它的原型是：
  ```cpp
  cudaError_t cudaMalloc(void** devPtr, size_t size);
  ```
  >devPtr是一个指向指针的指针，用于存储分配的内存地址；
  >size是分配的内存大小，以字节为单位。
- `reinterpret_cast<void **>(&d_A)`：这部分代码将d_A的地址强制转换为void**类型。d_A是一个指针变量，指向GPU上的内存地址。reinterpret_cast是一种C++的类型转换操作符，用于将一个指针类型转换为另一个指针类型。
- `cudaEvent_t`是CUDA中用于表示事件的数据类型。事件在CUDA编程中用于标记时间点，可以用于测量代码执行时间、同步线程等。start和stop是两个cudaEvent_t类型的变量，用于记录时间点。

    >这段代码的用途通常是在CUDA程序中测量某个代码段的执行时间。具体步骤如下：
    >
    >1. 创建事件：使用`cudaEventCreate`函数创建start和stop事件。
    >2. 记录时间点：使用`cudaEventRecord`函数在start和stop事件处记录时间点。
    >3. 等待事件：使用`cudaEventSynchronize`函数等待事件完成，确保事件记录的时间点已经到达。
    >4. 计算时间差：使用`cudaEventElapsedTime`函数计算两个事件之间的时间差，即代码段的执行时间。

- `cudaStreamCreateWithFlags`：用于创建一个 CUDA 流。函数原型：
    ```cpp
    cudaError_t cudaStreamCreateWithFlags(cudaStream_t* pStream, unsigned int flags);
    ```
    >pStream：指向 cudaStream_t 类型的指针，用于存储创建的流的句柄。
    >flags：用于指定流的创建标志。
- `cudaMemcpyAsync`：这是CUDA提供的用于异步内存复制的函数。异步复制意味着数据传输不会阻塞CPU，CPU可以继续执行其他任务，而数据传输在后台进行。函数原型：
    ```cpp
    cudaError_t cudaMemcpyAsync(const void* dst, const void* src, size_t count, cudaMemcpyKind kind, cudaStream_t stream);
    ```
    >dst：目标内存地址，即设备内存的地址，数据将被复制到这个地址。
    >src：源内存地址，即主机内存的地址，数据将从这个地址复制。
    >count：要复制的内存大小，以字节为单位。
    >kind：指定数据传输的方向，可以是以下值之一：
    >   cudaMemcpyHostToHost：主机到主机。
    >   cudaMemcpyHostToDevice：主机到设备。
    >   cudaMemcpyDeviceToHost：设备到主机。
    >   cudaMemcpyDeviceToDevice：设备到设备。
    >stream：CUDA流对象，用于管理多个CUDA操作（包括内存复制、核函数执行等）的执行顺序。通过使用流，可以并行执行多个操作，提高程序的性能。
- `nIter` 是一个常见的变量名，通常用于表示迭代次数。在 CUDA 编程中，它可能用于控制循环的执行次数，特别是在并行计算中，用于指定每个线程或块需要执行的操作次数。
-   调用矩阵乘法CUDA内核。
    ```cpp
    MatrixMulCUDA<16>
        <<<grid, threads, 0, stream>>>(d_C, d_A, d_B, dimsA.x, dimsB.x);
    ```

    1. CUDA内核调用：MatrixMulCUDA<16>和MatrixMulCUDA<32>是两个模板化的CUDA内核函数，分别用于处理块大小为16和32的情况。这些内核函数的定义和实现不在提供的代码片段中，但可以推测它们会根据传入的矩阵数据（d_C, d_A, d_B）和维度（dimsA.x, dimsB.x）进行矩阵乘法运算。
    2. CUDA执行配置：<<<grid, threads, 0, stream>>>是CUDA执行配置语法，用于指定内核函数的执行配置。其中，grid和threads分别表示网格和线程的维度，0表示不使用共享内存，stream表示CUDA流，用于控制CUDA操作的执行顺序。

- `cudaEventRecord()`用于记录 CUDA 事件。CUDA 事件可以用于测量 CUDA 程序中不同部分的执行时间，或者用于同步 CUDA 线程。
    ```cpp
    cudaError_t cudaEventRecord(cudaEvent_t event, cudaStream_t stream = 0);
    ```
    >event：要记录的事件。
    >stream：事件将被记录到的 CUDA 流。默认值为 0，表示默认流。
- `cudaEventSynchronize()`用于同步 CUDA 事件。当调用 cudaEventSynchronize 时，CUDA 运行时系统会检查事件的状态，如果事件已经完成，则函数立即返回；如果事件尚未完成，则函数会阻塞调用线程，直到事件完成。
- `cudaEventElapsedTime`用于测量两个 CUDA 事件之间的时间间隔。这个函数在性能分析和优化中非常有用。
    ```cpp
    cudaError_t cudaEventElapsedTime(float* ms, cudaEvent_t start, cudaEvent_t stop);
    ```
    >ms：指向一个 float 类型的指针，用于存储计算得到的时间间隔（以毫秒为单位）。
    >start：开始事件的句柄。
    >stop：结束事件的句柄。

- 
    >每秒的浮点运算次数 gigaFlops
    >每次矩阵乘法操作的平均时间 msecPerMatrixMul
    >矩阵乘法的基本运算次数 flopsPerMatrixMul
    >工作组的线程数 threads.x * threads.y

-   这段代码是用C++编写的，用于测试在CUDA平台上执行矩阵乘法操作时，CPU和GPU计算结果的相对误差。具体来说，它通过比较CPU和GPU计算出的结果，判断计算结果的准确性。以下是代码的详细解释：

    实现原理
    相对误差计算公式：

    使用公式 |<x, y>_cpu - <x,y>_gpu| / <|x|, |y|> < eps 来计算相对误差。
    其中 <x, y> 表示两个向量的点积，eps 是一个很小的数，用于判断误差是否在可接受范围内。
    循环遍历结果数组：

    使用一个循环遍历CPU和GPU计算出的结果数组 h_C。
    对于每个元素，计算其绝对误差 abs_err，即 |h_C[i] - (dimsA.x * valB)|。
    计算点积长度 dot_length，即 dimsA.x。
    计算绝对值 abs_val，即 |h_C[i]|。
    计算相对误差 rel_err，即 abs_err / abs_val / dot_length。
    判断相对误差是否超过阈值：

    如果相对误差 rel_err 大于预设的阈值 eps，则输出错误信息，并设置 correct 为 false。
    输出测试结果：

    根据最终的 correct 值，输出测试结果为“PASS”或“FAIL”。
    用途
    这段代码的用途是在CUDA平台上进行矩阵乘法操作后，验证GPU计算结果的准确性。通过比较CPU和GPU的计算结果，可以确保GPU计算的正确性，从而提高程序的可靠性。

## main() ##
- `findCudaDevice`函数的主要用途是帮助开发者选择一个合适的 CUDA 设备（即 GPU）来执行计算任务。
- `cudaProfilerStart() & cudaProfilerStop()`启动或停止CUDA的性能分析器。CUDA性能分析器可以用来收集和显示CUDA代码的性能数据，比如GPU的利用率、内存带宽等。
