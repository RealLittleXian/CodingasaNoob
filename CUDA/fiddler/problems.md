problems.md记录配置环境、运行程序时遇到的各种问题，仅供参考。



## 7.25

Access to model mistralai/Mixtral-8x7B-Instruct-v0.1 is restricted. You must be authenticated to access it.

418 - Hugging Face

Colab

## 7.26

401 Client Error: Unauthorized for url: huggingface

Colab Pro

Azure

## 7.27

AutoDL

'export' �����ڲ����ⲿ���Ҳ���ǿ����еĳ��� ���������ļ���

WARNING: Failed to write executable - trying to use .deleteme logic ERROR: Could not install packages due to an OSError: [WinError 2] 系统找不到指定的文件。: 'C:\\Python312\\Scripts\\huggingface-cli.exe' -> 'C:\\Python312\\Scripts\\huggingface-cli.exe.deleteme'



## 7.28

Kaggle

nvcc : 无法将“nvcc”项识别为 cmdlet、函数、脚本文件或可运行程序的名称。请检查名称的拼写，如果包括路径，请确保路径正确 ，然后再试一次

## 7.29

colab磁盘不足

Loading checkpoint shards:

model_id = 下载的文件在哪

huggingface-cli 静默下载

blobs mistralai/Mixtral-8x7B

docker

## 7.30

hqq_aten package not installed. HQQBackend.ATEN backend will not work unless you install the hqq_aten lib in hqq/kernels.

typeerror: mixtralblocksparsetop2mlp.forward() takes 2 positional arguments but 3 were given

PyTorch

Anaconda

Traceback (most recent call last): File "<stdin>", line 1, in <module> File "C:\Users\GenLi\AppData\Roaming\Python\Python312\site-packages\torch\__init__.py", line 148, in <module> raise err OSError: [WinError 126] 找不到指定的模块。 Error loading "C:\Users\GenLi\AppData\Roaming\Python\Python312\site-packages\torch\lib\fbgemm.dll" or one of its dependencies.

## 7.31

A module that was compiled using NumPy 1.x cannot be run in NumPy 2.0.1 as it may crash. To support both 1.x and 2.x versions of NumPy, modules must be compiled with NumPy 2.0. Some module may need to rebuild instead e.g. with 'pybind11>=2.12'. If you are a user of the module, the easiest solution will be to downgrade to 'numpy<2' or try to upgrade the affected module. We expect that some modules will need time to support NumPy 2.

torch.cuda.is_available() = false

Ubuntu 访问windows数据

cuda pytorch版本对应

## 8.1

cuda切换版本

Verifying transaction: failed

## 8.2

ssh

## 8.4

CondaVerificationError: The package for pytorch located at C:\Users\GenLi\anaconda3\pkgs\pytorch-2.4.0-py3.12_cuda11.8_cudnn9_0 appears to be corrupted. The path 'Lib/site-packages/functorch/_C.cp312-win_amd64.pyd'

Downloading and Extracting Packages: | 0%

## 8.6















