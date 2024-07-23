```
!nvprof ./add
            Type  Time(%)      Time     Calls       Avg       Min       Max  Name
 GPU activities:  100.00%  109.62ms         1  109.62ms  109.62ms  109.62ms  add(int, float*, float*)
```
```
!nvprof ./add_block
            Type  Time(%)      Time     Calls       Avg       Min       Max  Name
 GPU activities:  100.00%  3.6718ms         1  3.6718ms  3.6718ms  3.6718ms  add(int, float*, float*)
```
```
!nvprof ./add_grid
            Type  Time(%)      Time     Calls       Avg       Min       Max  Name
            Type  Time(%)      Time     Calls       Avg       Min       Max  Name
 GPU activities:  100.00%  2.6171ms         1  2.6171ms  2.6171ms  2.6171ms  add(int, float*, float*)
```
性能确有提升：109.62ms -> 3.6718ms -> 2.6171ms

> 令人疑惑的是add_grid中预期数据应为us级别，差异较大

Update 7.18 改进：做多次循环取平均时间，评估add()函数的耗时。
```
!nvprof ./add_grid
            Type  Time(%)      Time     Calls       Avg       Min       Max  Name
 GPU activities:  100.00%  8.3871ms       100  83.870us  56.607us  2.7490ms  add(int, float*, float*)
 ```
配置：
```
Fri Jul 12 05:44:56 2024       
+---------------------------------------------------------------------------------------+
| NVIDIA-SMI 535.104.05             Driver Version: 535.104.05   CUDA Version: 12.2     |
|-----------------------------------------+----------------------+----------------------+
| GPU  Name                 Persistence-M | Bus-Id        Disp.A | Volatile Uncorr. ECC |
| Fan  Temp   Perf          Pwr:Usage/Cap |         Memory-Usage | GPU-Util  Compute M. |
|                                         |                      |               MIG M. |
|=========================================+======================+======================|
|   0  Tesla T4                       Off | 00000000:00:04.0 Off |                    0 |
| N/A   40C    P8              10W /  70W |      0MiB / 15360MiB |      0%      Default |
|                                         |                      |                  N/A |
+-----------------------------------------+----------------------+----------------------+
                                                                                         
+---------------------------------------------------------------------------------------+
| Processes:                                                                            |
|  GPU   GI   CI        PID   Type   Process name                            GPU Memory |
|        ID   ID                                                             Usage      |
|=======================================================================================|
|  No running processes found                                                           |
+---------------------------------------------------------------------------------------+
```     