```
+-----------------------------------------------------------------------------------------+
| NVIDIA-SMI 550.67                 Driver Version: 550.67         CUDA Version: 12.4     |
|-----------------------------------------+------------------------+----------------------+
| GPU  Name                 Persistence-M | Bus-Id          Disp.A | Volatile Uncorr. ECC |
| Fan  Temp   Perf          Pwr:Usage/Cap |           Memory-Usage | GPU-Util  Compute M. |
|                                         |                        |               MIG M. |
|=========================================+========================+======================|
|   0  NVIDIA GeForce RTX 3090        On  |   00000000:C1:00.0 Off |                  N/A |
| 30%   23C    P8             21W /  350W |       1MiB /  24576MiB |      0%      Default |
|                                         |                        |                  N/A |
+-----------------------------------------+------------------------+----------------------+

+-----------------------------------------------------------------------------------------+
| Processes:                                                                              |
|  GPU   GI   CI        PID   Type   Process name                              GPU Memory |
|        ID   ID                                                               Usage      |
|=========================================================================================|
|  No running processes found                                                             |
+-----------------------------------------------------------------------------------------+
```

# default

os.environ["TOKENIZERS_PARALLELISM"] = "false"

self.latency_cpu = 7

self.latency_gpu = 70

free_mem = total_mem * 0.95 - torch.cuda.memory_allocated(self.dev) # TODO: magic number

torch.set_num_threads(16)

```
root@job-651f5df8-zt6sd:/workspace# python ./fiddler/infer.py --model /share/models/Mixtral-8x7V-v0.1 --n-token 5
Loading checkpoint shards: 100%|████████████████████████████████████████████████████████| 19/19 [00:01<00:00, 12.28it/s]
Number of experts on GPU: 56/256
set_expert_loc time=0.04633599892258644
Model is ready.
tokenize time=99.87104034423828

<s> University of Washington is
to generate the word ---
total inference time = 144395.494140625 ms
avg layer inference time = 4512.359191894531 ms
a
to generate the word ---
total inference time = 41656.37512397766 ms
avg layer inference time = 1301.761722624302 ms
higher
to generate the word ---
total inference time = 31619.56340789795 ms
avg layer inference time = 988.1113564968109 ms
education
to generate the word ---
total inference time = 26992.310933113098 ms
avg layer inference time = 843.5097166597843 ms
institution
to generate the word ---
total inference time = 32563.673027038574 ms
avg layer inference time = 1017.6147820949554 ms
--------------------
Input: University of Washington is
Output:  a higher education institution
generate time=277428.59375
prefill_time: 144.55478477478027, decode_time: 132.85277843475342, hit_rate: 0.2777777777777778

root@job-651f5df8-zt6sd:/workspace# python ./fiddler/infer.py --model /share/models/Mixtral-8x7V-v0.1 --n-token 5
Loading checkpoint shards: 100%|████████████████████████████████████████████████████████| 19/19 [00:01<00:00, 10.49it/s]
Number of experts on GPU: 56/256
set_expert_loc time=0.04403200000524521
Model is ready.
tokenize time=100.50392188374553

<s> University of Washington is
to generate the word ---
total inference time = 136568.5092163086 ms
avg layer inference time = 4267.765913009644 ms
a
to generate the word ---
total inference time = 30322.645772218704 ms
avg layer inference time = 947.5826803818345 ms
higher
to generate the word ---
total inference time = 35916.21817445755 ms
avg layer inference time = 1122.3818179517984 ms
education
to generate the word ---
total inference time = 26997.713928222656 ms
avg layer inference time = 843.678560256958 ms
institution
to generate the word ---
total inference time = 33719.95524597168 ms
avg layer inference time = 1053.748601436615 ms
--------------------
Input: University of Washington is
Output:  a higher education institution

generate time=263873.87

prefill_time: 136.70327401161194, decode_time: 126.97280287742615, hit_rate: 0.2777777777777778

```

# TOKENIZERS_PARALLELISM

os.environ["TOKENIZERS_PARALLELISM"] = "true"

self.latency_cpu = 7

self.latency_gpu = 70

free_mem = total_mem * 0.95 - torch.cuda.memory_allocated(self.dev) # TODO: magic number

torch.set_num_threads(16)

```
root@job-651f5df8-zt6sd:/workspace# python ./fiddler/infer.py --model /share/models/Mixtral-8x7V-v0.1 --n-token 5
Loading checkpoint shards: 100%|████████████████████████████████████████████████████████| 19/19 [00:02<00:00,  6.77it/s]
Number of experts on GPU: 56/256
set_expert_loc time=0.057312000542879105
Model is ready.
tokenize time=10.408023920507098

<s> University of Washington is
to generate the word ---
total inference time = 131856.54888916016 ms
avg layer inference time = 4120.517152786255 ms
a
to generate the word ---
total inference time = 25952.32841205597 ms
avg layer inference time = 811.010262876749 ms
higher
to generate the word ---
total inference time = 26143.945729732513 ms
avg layer inference time = 816.998304054141 ms
education
to generate the word ---
total inference time = 22824.19302368164 ms
avg layer inference time = 713.2560319900513 ms
institution
to generate the word ---
total inference time = 28363.91438293457 ms
avg layer inference time = 886.3723244667053 ms
--------------------
Input: University of Washington is
Output:  a higher education institution
generate time=235402.703125
prefill_time: 131.91867327690125, decode_time: 103.29853558540344, hit_rate: 0.2777777777777778

root@job-651f5df8-zt6sd:/workspace# python ./fiddler/infer.py --model /share/models/Mixtral-8x7V-v0.1 --n-token 5
Loading checkpoint shards: 100%|████████████████████████████████████████████████████████| 19/19 [00:01<00:00,  9.83it/s]
Number of experts on GPU: 56/256
set_expert_loc time=0.0541439987719059
Model is ready.
tokenize time=10.508831977844238

<s> University of Washington is
to generate the word ---
total inference time = 119006.32110595703 ms
avg layer inference time = 3718.947534561157 ms
a
to generate the word ---
total inference time = 25181.797223091125 ms
avg layer inference time = 786.9311632215977 ms
higher
to generate the word ---
total inference time = 22464.716179847717 ms
avg layer inference time = 702.0223806202412 ms
education
to generate the word ---
total inference time = 19833.09011077881 ms
avg layer inference time = 619.7840659618378 ms
institution
to generate the word ---
total inference time = 27430.298110961914 ms
avg layer inference time = 857.1968159675598 ms
--------------------
Input: University of Washington is
Output:  a higher education institution

generate time=214233.859375

prefill_time: 119.11945104598999, decode_time: 94.92473649978638, hit_rate: 0.2777777777777778


```

# self.latency_cpu self.latency_gpu

```
                        # expected latency at CPU: number of token * cost_at_cpu
                        # expected latency at GPU: cost_at_gpu (constant)
```

os.environ["TOKENIZERS_PARALLELISM"] = "true"

self.latency_cpu = 1

self.latency_gpu = 1

free_mem = total_mem * 0.95 - torch.cuda.memory_allocated(self.dev) # TODO: magic number

torch.set_num_threads(16)

```
root@job-651f5df8-zt6sd:/workspace# python ./fiddler/infer.py --model /share/models/Mixtral-8x7V-v0.1 --n-token 5
Loading checkpoint shards: 100%|████████████████████████████████████████████████████████| 19/19 [00:02<00:00,  9.41it/s]
Number of experts on GPU: 56/256
set_expert_loc time=0.053247999399900436
Model is ready.
tokenize time=102.13702392578125
<s> University of Washington is
to generate the word ---
total inference time = 108341.34283447266 ms
avg layer inference time = 3385.6669635772705 ms
a
to generate the word ---
total inference time = 24612.54362821579 ms
avg layer inference time = 769.1419883817434 ms
higher
to generate the word ---
total inference time = 23993.401304721832 ms
avg layer inference time = 749.7937907725573 ms
education
to generate the word ---
total inference time = 21291.17935371399 ms
avg layer inference time = 665.3493548035622 ms
institution
to generate the word ---
total inference time = 27291.22797393799 ms
avg layer inference time = 852.8508741855621 ms
--------------------
Input: University of Washington is
Output:  a higher education institution

generate time=205767.703125

prefill_time: 108.41323614120483, decode_time: 97.20320081710815, hit_rate: 0.2777777777777778

```

os.environ["TOKENIZERS_PARALLELISM"] = "true"

self.latency_cpu = 5

self.latency_gpu = 1

free_mem = total_mem * 0.95 - torch.cuda.memory_allocated(self.dev) # TODO: magic number

torch.set_num_threads(16)

```
root@job-651f5df8-zt6sd:/workspace# python ./fiddler/infer.py --model /share/models/Mixtral-8x7V-v0.1 --n-token 5
Loading checkpoint shards: 100%|████████████████████████████████████████████████████████| 19/19 [00:01<00:00,  9.87it/s]
Number of experts on GPU: 56/256
set_expert_loc time=0.05526399984955788
Model is ready.
tokenize time=11.250399589538574
<s> University of Washington is
to generate the word ---
total inference time = 103678.03268432617 ms
avg layer inference time = 3239.938521385193 ms
a
to generate the word ---
total inference time = 21899.93655347824 ms
avg layer inference time = 684.373017296195 ms
higher
to generate the word ---
total inference time = 25061.27757024765 ms
avg layer inference time = 783.1649240702391 ms
education
to generate the word ---
total inference time = 21482.987637996674 ms
avg layer inference time = 671.343363687396 ms
institution
to generate the word ---
total inference time = 26667.802242279053 ms
avg layer inference time = 833.3688200712204 ms
--------------------
Input: University of Washington is
Output:  a higher education institution

generate time=199270.578125

prefill_time: 103.73384070396423, decode_time: 95.12999486923218, hit_rate: 0.2777777777777778

```

os.environ["TOKENIZERS_PARALLELISM"] = "true"

self.latency_cpu = 7

self.latency_gpu = 1

free_mem = total_mem * 0.95 - torch.cuda.memory_allocated(self.dev) # TODO: magic number

torch.set_num_threads(16)

```
root@job-651f5df8-zt6sd:/workspace# python ./fiddler/infer.py --model /share/models/Mixtral-8x7V-v0.1 --n-token 5
Loading checkpoint shards: 100%|████████████████████████████████████████████████████████| 19/19 [00:01<00:00, 10.79it/s]
Number of experts on GPU: 56/256
set_expert_loc time=0.05222399905323982
Model is ready.
tokenize time=62.71014404296875
<s> University of Washington is
to generate the word ---
total inference time = 87627.55731201172 ms
avg layer inference time = 2738.361166000366 ms
a
to generate the word ---
total inference time = 21635.72096681595 ms
avg layer inference time = 676.1162802129984 ms
higher
to generate the word ---
total inference time = 17673.612332344055 ms
avg layer inference time = 552.3003853857517 ms
education
to generate the word ---
total inference time = 16101.560450077057 ms
avg layer inference time = 503.173764064908 ms
institution
to generate the word ---
total inference time = 18896.894207000732 ms
avg layer inference time = 590.5279439687729 ms
--------------------
Input: University of Washington is
Output:  a higher education institution

generate time=162159.890625

prefill_time: 87.76103806495667, decode_time: 74.32474875450134, hit_rate: 0.2777777777777778

```

os.environ["TOKENIZERS_PARALLELISM"] = "true"

self.latency_cpu = 10

self.latency_gpu = 1

free_mem = total_mem * 0.95 - torch.cuda.memory_allocated(self.dev) # TODO: magic number

torch.set_num_threads(16)

```
root@job-651f5df8-zt6sd:/workspace# python ./fiddler/infer.py --model /share/models/Mixtral-8x7V-v0.1 --n-token 5
Loading checkpoint shards: 100%|████████████████████████████████████████████████████████| 19/19 [00:02<00:00,  7.31it/s]
Number of experts on GPU: 56/256
set_expert_loc time=0.040832001715898514
Model is ready.
tokenize time=9.032320022583008
<s> University of Washington is
to generate the word ---
total inference time = 102548.02062988281 ms
avg layer inference time = 3204.625644683838 ms
a
to generate the word ---
total inference time = 22816.03492331505 ms
avg layer inference time = 713.0010913535953 ms
higher
to generate the word ---
total inference time = 26419.32949447632 ms
avg layer inference time = 825.604046702385 ms
education
to generate the word ---
total inference time = 16951.502548217773 ms
avg layer inference time = 529.7344546318054 ms
institution
to generate the word ---
total inference time = 20241.66486930847 ms
avg layer inference time = 632.5520271658897 ms
--------------------
Input: University of Washington is
Output:  a higher education institution

generate time=189478.53125

prefill_time: 102.66236090660095, decode_time: 86.44568157196045, hit_rate: 0.2777777777777778

```





# torch.set_num_threads

os.environ["TOKENIZERS_PARALLELISM"] = "true"

self.latency_cpu = 7

self.latency_gpu = 1

free_mem = total_mem * 0.95 - torch.cuda.memory_allocated(self.dev) # TODO: magic number

torch.set_num_threads(32)

```
root@job-651f5df8-zt6sd:/workspace# python ./fiddler/infer.py --model /share/models/Mixtral-8x7V-v0.1 --n-token 5
Loading checkpoint shards: 100%|████████████████████████████████████████████████████████| 19/19 [00:02<00:00,  8.76it/s]
Number of experts on GPU: 56/256
set_expert_loc time=0.05427199974656105
Model is ready.
tokenize time=12.035584449768066
<s> University of Washington is
to generate the word ---
total inference time = 107874.29711914062 ms
avg layer inference time = 3371.0717849731445 ms
a
to generate the word ---
total inference time = 20721.47493171692 ms
avg layer inference time = 647.5460916161537 ms
higher
to generate the word ---
total inference time = 27877.60933494568 ms
avg layer inference time = 871.1752917170525 ms
education
to generate the word ---
total inference time = 22773.151164531708 ms
avg layer inference time = 711.6609738916159 ms
institution
to generate the word ---
total inference time = 25219.46658706665 ms
avg layer inference time = 788.1083308458328 ms
--------------------
Input: University of Washington is
Output:  a higher education institution

generate time=205026.5

prefill_time: 107.9558036327362, decode_time: 96.60821914672852, hit_rate: 0.2777777777777778

```

os.environ["TOKENIZERS_PARALLELISM"] = "true"

self.latency_cpu = 7

self.latency_gpu = 1

free_mem = total_mem * 0.95 - torch.cuda.memory_allocated(self.dev) # TODO: magic number

torch.set_num_threads(8)

```
root@job-651f5df8-zt6sd:/workspace# python ./fiddler/infer.py --model /share/models/Mixtral-8x7V-v0.1 --n-token 5
Loading checkpoint shards: 100%|████████████████████████████████████████████████████████| 19/19 [00:01<00:00, 10.28it/s]
Number of experts on GPU: 56/256
set_expert_loc time=0.05119999870657921
Model is ready.
tokenize time=11.659392356872559
<s> University of Washington is
to generate the word ---
total inference time = 103468.03100585938 ms
avg layer inference time = 3233.3759689331055 ms
a
to generate the word ---
total inference time = 20883.382551670074 ms
avg layer inference time = 652.6057047396898 ms
higher
to generate the word ---
total inference time = 27073.384989261627 ms
avg layer inference time = 846.0432809144258 ms
education
to generate the word ---
total inference time = 24102.034299850464 ms
avg layer inference time = 753.188571870327 ms
institution
to generate the word ---
total inference time = 24210.237270355225 ms
avg layer inference time = 756.5699146986008 ms
--------------------
Input: University of Washington is
Output:  a higher education institution

generate time=200020.171875

prefill_time: 103.53702211380005, decode_time: 96.2875657081604, hit_rate: 0.2777777777777778

```


