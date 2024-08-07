import torch
print("Torch version:", torch.__version__)
print("torch.CUDA version:", torch.version.cuda)
print("CUDA available:", torch.cuda.is_available())
if torch.cuda.is_available():
    print("CUDA device:", torch.cuda.get_device_name(torch.cuda.current_device()))
    print(torch.cuda.get_device_name(0))

# python infer.py --model /share/models/Mixtral-8x7V-v0.1
# python ./fiddler/infer.py --model /share/models/Mixtral-8x7V-v0.1 --input 'Hello, I am' --n-token 5