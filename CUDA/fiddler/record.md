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


```
root@job-9e568ffa-j289l:/workspace# nvidia-smi
Thu Aug 15 15:17:12 2024
+-----------------------------------------------------------------------------------------+
| NVIDIA-SMI 550.67                 Driver Version: 550.67         CUDA Version: 12.4     |
|-----------------------------------------+------------------------+----------------------+
| GPU  Name                 Persistence-M | Bus-Id          Disp.A | Volatile Uncorr. ECC |
| Fan  Temp   Perf          Pwr:Usage/Cap |           Memory-Usage | GPU-Util  Compute M. |
|                                         |                        |               MIG M. |
|=========================================+========================+======================|
|   0  NVIDIA RTX A6000               Off |   00000000:50:00.0 Off |                  Off |
| 30%   33C    P8             25W /  300W |       1MiB /  49140MiB |      0%      Default |
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


```
root@job-9e568ffa-j289l:/workspace# python /workspace/fiddler/infer.py --model /share/models/Mixtral-8x7V-v0.1 --n-token 5 --beam-width 5
Loading checkpoint shards: 100%|████████████████████████████████████████████████████████| 19/19 [00:03<00:00,  5.17it/s]
Number of experts on GPU: 125/256
set_expert_loc time=0.043136000633239746
Model is ready.
tokenize time=98.99199676513672
to generate the word ---
total inference time = 144535.6319580078 ms
avg layer inference time = 4516.738498687744 ms
to generate the word ---
total inference time = 55197.53887939453 ms
avg layer inference time = 1724.923089981079 ms
to generate the word ---
total inference time = 42539.26184940338 ms
avg layer inference time = 1329.3519327938557 ms
to generate the word ---
total inference time = 20983.411754608154 ms
avg layer inference time = 655.7316173315048 ms
to generate the word ---
total inference time = 36424.05732727051 ms
avg layer inference time = 1138.2517914772034 ms
--------------------
Input: University of Washington is
Output:  a higher education institution

generate time=300042.875

prefill_time: 144.59259963035583, decode_time: 155.16042757034302, hit_rate: 0.5628472222222223

root@job-9e568ffa-j289l:/workspace# python /workspace/fiddler/infer.py --model /share/models/Mixtral-8x7V-v0.1 --n-token 9 --beam-width 3
Loading checkpoint shards: 100%|████████████████████████████████████████████████████████| 19/19 [00:01<00:00, 17.89it/s]
Number of experts on GPU: 125/256
set_expert_loc time=0.03743999823927879
Model is ready.
tokenize time=17.29155158996582
to generate the word ---
total inference time = 25206.334144592285 ms
avg layer inference time = 787.6979420185089 ms
to generate the word ---
total inference time = 13193.937543869019 ms
avg layer inference time = 412.31054824590683 ms
to generate the word ---
total inference time = 8808.562959194183 ms
avg layer inference time = 275.26759247481823 ms
to generate the word ---
total inference time = 16072.373579025269 ms
avg layer inference time = 502.26167434453964 ms
to generate the word ---
total inference time = 22475.304527282715 ms
avg layer inference time = 702.3532664775848 ms
to generate the word ---
total inference time = 19397.470160245895 ms
avg layer inference time = 606.1709425076842 ms
to generate the word ---
total inference time = 14033.538375854492 ms
avg layer inference time = 438.5480742454529 ms
to generate the word ---
total inference time = 13617.35901260376 ms
avg layer inference time = 425.5424691438675 ms
to generate the word ---
total inference time = 15374.896589756012 ms
avg layer inference time = 480.4655184298754 ms
--------------------
Input: University of Washington is
Output:  a higher education institution located in King County

generate time=148447.5625

prefill_time: 25.349875450134277, decode_time: 123.00440526008606, hit_rate: 0.5641025641025641

root@job-9e568ffa-j289l:/workspace# python /workspace/fiddler/infer.py --model /share/models/Mixtral-8x7V-v0.1 --n-token 100 --beam-width 10
Loading checkpoint shards: 100%|████████████████████████████████████████████████████████| 19/19 [00:01<00:00, 18.86it/s]
Number of experts on GPU: 125/256
set_expert_loc time=0.04198399931192398
Model is ready.
tokenize time=21.81395149230957
to generate the word ---
total inference time = 38430.43920135498 ms
avg layer inference time = 1200.9512250423431 ms
to generate the word ---
total inference time = 56904.75966453552 ms
avg layer inference time = 1778.273739516735 ms
to generate the word ---
total inference time = 32014.099319458008 ms
avg layer inference time = 1000.4406037330627 ms
to generate the word ---
total inference time = 26098.265045166016 ms
avg layer inference time = 815.570782661438 ms
to generate the word ---
total inference time = 19591.575485229492 ms
avg layer inference time = 612.2367339134216 ms
to generate the word ---
total inference time = 27480.637100219727 ms
avg layer inference time = 858.7699093818665 ms
to generate the word ---
total inference time = 20427.586265563965 ms
avg layer inference time = 638.3620707988739 ms
to generate the word ---
total inference time = 26190.90887451172 ms
avg layer inference time = 818.4659023284912 ms
to generate the word ---
total inference time = 18634.16307067871 ms
avg layer inference time = 582.3175959587097 ms
to generate the word ---
total inference time = 26307.246337890625 ms
avg layer inference time = 822.101448059082 ms
to generate the word ---
total inference time = 17999.743255615234 ms
avg layer inference time = 562.4919767379761 ms
to generate the word ---
total inference time = 26543.30825805664 ms
avg layer inference time = 829.47838306427 ms
to generate the word ---
total inference time = 20608.697063446045 ms
avg layer inference time = 644.0217832326889 ms
to generate the word ---
total inference time = 22497.64715576172 ms
avg layer inference time = 703.0514736175537 ms
to generate the word ---
total inference time = 20906.310470581055 ms
avg layer inference time = 653.322202205658 ms
to generate the word ---
total inference time = 25316.858428955078 ms
avg layer inference time = 791.1518259048462 ms
to generate the word ---
total inference time = 20440.027172088623 ms
avg layer inference time = 638.7508491277695 ms
to generate the word ---
total inference time = 22246.256774902344 ms
avg layer inference time = 695.1955242156982 ms
to generate the word ---
total inference time = 22802.927947998047 ms
avg layer inference time = 712.591498374939 ms
to generate the word ---
total inference time = 23709.590759277344 ms
avg layer inference time = 740.924711227417 ms
to generate the word ---
total inference time = 22761.69384765625 ms
avg layer inference time = 711.3029327392578 ms
to generate the word ---
total inference time = 21603.478622436523 ms
avg layer inference time = 675.1087069511414 ms
to generate the word ---
total inference time = 23235.863883972168 ms
avg layer inference time = 726.1207463741302 ms
to generate the word ---
total inference time = 23272.753356933594 ms
avg layer inference time = 727.2735424041748 ms
to generate the word ---
total inference time = 22904.97095489502 ms
avg layer inference time = 715.7803423404694 ms
to generate the word ---
total inference time = 21387.651626586914 ms
avg layer inference time = 668.3641133308411 ms
to generate the word ---
total inference time = 24767.12973022461 ms
avg layer inference time = 773.972804069519 ms
to generate the word ---
total inference time = 22815.995193481445 ms
avg layer inference time = 712.9998497962952 ms
to generate the word ---
total inference time = 26022.94889831543 ms
avg layer inference time = 813.2171530723572 ms
to generate the word ---
total inference time = 33660.21139526367 ms
avg layer inference time = 1051.8816061019897 ms
to generate the word ---
total inference time = 16663.59008026123 ms
avg layer inference time = 520.7371900081635 ms
to generate the word ---
total inference time = 32545.263732910156 ms
avg layer inference time = 1017.0394916534424 ms
to generate the word ---
total inference time = 18997.050415039062 ms
avg layer inference time = 593.6578254699707 ms
to generate the word ---
total inference time = 30714.222732543945 ms
avg layer inference time = 959.8194603919983 ms
to generate the word ---
total inference time = 37231.768493652344 ms
avg layer inference time = 1163.4927654266357 ms
to generate the word ---
total inference time = 35159.07159423828 ms
avg layer inference time = 1098.7209873199463 ms
to generate the word ---
total inference time = 16790.039321899414 ms
avg layer inference time = 524.6887288093567 ms
to generate the word ---
total inference time = 31677.417358398438 ms
avg layer inference time = 989.9192924499512 ms
to generate the word ---
total inference time = 18072.42172241211 ms
avg layer inference time = 564.7631788253784 ms
to generate the word ---
total inference time = 28760.483520507812 ms
avg layer inference time = 898.7651100158691 ms
to generate the word ---
total inference time = 19558.392875671387 ms
avg layer inference time = 611.1997773647308 ms
to generate the word ---
total inference time = 25689.19171142578 ms
avg layer inference time = 802.7872409820557 ms
to generate the word ---
total inference time = 17725.227912902832 ms
avg layer inference time = 553.9133722782135 ms
to generate the word ---
total inference time = 24366.637725830078 ms
avg layer inference time = 761.4574289321899 ms
to generate the word ---
total inference time = 18925.136360168457 ms
avg layer inference time = 591.4105112552643 ms
to generate the word ---
total inference time = 23787.052474975586 ms
avg layer inference time = 743.3453898429871 ms
to generate the word ---
total inference time = 18903.907821655273 ms
avg layer inference time = 590.7471194267273 ms
to generate the word ---
total inference time = 25461.456657409668 ms
avg layer inference time = 795.6705205440521 ms
to generate the word ---
total inference time = 19456.680351257324 ms
avg layer inference time = 608.0212609767914 ms
to generate the word ---
total inference time = 23200.642059326172 ms
avg layer inference time = 725.0200643539429 ms
to generate the word ---
total inference time = 20919.20199584961 ms
avg layer inference time = 653.7250623703003 ms
to generate the word ---
total inference time = 23156.679779052734 ms
avg layer inference time = 723.646243095398 ms
to generate the word ---
total inference time = 21979.871505737305 ms
avg layer inference time = 686.8709845542908 ms
to generate the word ---
total inference time = 22595.613395690918 ms
avg layer inference time = 706.1129186153412 ms
to generate the word ---
total inference time = 20604.83278656006 ms
avg layer inference time = 643.9010245800018 ms
to generate the word ---
total inference time = 20953.03426361084 ms
avg layer inference time = 654.7823207378387 ms
to generate the word ---
total inference time = 21515.702339172363 ms
avg layer inference time = 672.3656980991364 ms
to generate the word ---
total inference time = 21275.601486206055 ms
avg layer inference time = 664.8625464439392 ms
to generate the word ---
total inference time = 23797.753791809082 ms
avg layer inference time = 743.6798059940338 ms
to generate the word ---
total inference time = 22975.120681762695 ms
avg layer inference time = 717.9725213050842 ms
to generate the word ---
total inference time = 24270.51414489746 ms
avg layer inference time = 758.4535670280457 ms
to generate the word ---
total inference time = 21368.466888427734 ms
avg layer inference time = 667.7645902633667 ms
to generate the word ---
total inference time = 24649.92430114746 ms
avg layer inference time = 770.3101344108582 ms
to generate the word ---
total inference time = 21252.72593688965 ms
avg layer inference time = 664.1476855278015 ms
to generate the word ---
total inference time = 26128.323112487793 ms
avg layer inference time = 816.5100972652435 ms
to generate the word ---
total inference time = 22404.277725219727 ms
avg layer inference time = 700.1336789131165 ms
to generate the word ---
total inference time = 24016.103477478027 ms
avg layer inference time = 750.5032336711884 ms
to generate the word ---
total inference time = 20671.435317993164 ms
avg layer inference time = 645.9823536872864 ms
to generate the word ---
total inference time = 25877.215606689453 ms
avg layer inference time = 808.6629877090454 ms
to generate the word ---
total inference time = 19281.18620300293 ms
avg layer inference time = 602.5370688438416 ms
to generate the word ---
total inference time = 24974.71947479248 ms
avg layer inference time = 780.459983587265 ms
to generate the word ---
total inference time = 21663.041175842285 ms
avg layer inference time = 676.9700367450714 ms
to generate the word ---
total inference time = 25187.571159362793 ms
avg layer inference time = 787.1115987300873 ms
to generate the word ---
total inference time = 21050.95379638672 ms
avg layer inference time = 657.842306137085 ms
to generate the word ---
total inference time = 24468.962356567383 ms
avg layer inference time = 764.6550736427307 ms
to generate the word ---
total inference time = 19027.585357666016 ms
avg layer inference time = 594.612042427063 ms
to generate the word ---
total inference time = 25980.165786743164 ms
avg layer inference time = 811.8801808357239 ms
to generate the word ---
total inference time = 21175.6556930542 ms
avg layer inference time = 661.7392404079437 ms
to generate the word ---
total inference time = 26133.73323059082 ms
avg layer inference time = 816.6791634559631 ms
to generate the word ---
total inference time = 19827.796585083008 ms
avg layer inference time = 619.618643283844 ms
to generate the word ---
total inference time = 25654.212310791016 ms
avg layer inference time = 801.6941347122192 ms
to generate the word ---
total inference time = 19142.0160446167 ms
avg layer inference time = 598.1880013942719 ms
to generate the word ---
total inference time = 26738.688598632812 ms
avg layer inference time = 835.5840187072754 ms
to generate the word ---
total inference time = 20776.591262817383 ms
avg layer inference time = 649.2684769630432 ms
to generate the word ---
total inference time = 25283.802734375 ms
avg layer inference time = 790.1188354492188 ms
to generate the word ---
total inference time = 21192.894287109375 ms
avg layer inference time = 662.277946472168 ms
to generate the word ---
total inference time = 24282.5753326416 ms
avg layer inference time = 758.83047914505 ms
to generate the word ---
total inference time = 22187.304817199707 ms
avg layer inference time = 693.3532755374908 ms
to generate the word ---
total inference time = 21307.564331054688 ms
avg layer inference time = 665.861385345459 ms
to generate the word ---
total inference time = 21952.716438293457 ms
avg layer inference time = 686.0223886966705 ms
to generate the word ---
total inference time = 22251.914070129395 ms
avg layer inference time = 695.3723146915436 ms
to generate the word ---
total inference time = 22805.042686462402 ms
avg layer inference time = 712.6575839519501 ms
to generate the word ---
total inference time = 19872.95677947998 ms
avg layer inference time = 621.0298993587494 ms
to generate the word ---
total inference time = 23285.796325683594 ms
avg layer inference time = 727.6811351776123 ms
to generate the word ---
total inference time = 19995.595916748047 ms
avg layer inference time = 624.8623723983765 ms
to generate the word ---
total inference time = 24628.935089111328 ms
avg layer inference time = 769.654221534729 ms
to generate the word ---
total inference time = 18538.36492919922 ms
avg layer inference time = 579.3239040374756 ms
to generate the word ---
total inference time = 23619.055603027344 ms
avg layer inference time = 738.0954875946045 ms
to generate the word ---
total inference time = 18681.63363647461 ms
avg layer inference time = 583.8010511398315 ms
to generate the word ---
total inference time = 27087.454620361328 ms
avg layer inference time = 846.4829568862915 ms
--------------------
Input: University of Washington is
Output:  located in Seattle , Washington .

 It is ranked as # 5 8 in Best National University .

 K i pl inger ranking is  1 0 .

 It is a public University .

 Univers ity of Washington offers following types of degrees and certificate programs :

 - Bachelor ' s degree
 - Post b ac cal a ure ate certificate
 - Master ' s degree
 - Post - master ' s certificate
 - Doctor ' s degree in research
 - Doctor ' s

generate time=2370554.75

prefill_time: 38.581463098526, decode_time: 2331.719617128372, hit_rate: 0.5088040865384615

root@job-9e568ffa-j289l:/workspace#
```