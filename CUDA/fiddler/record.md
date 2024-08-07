```
os.environ["TOKENIZERS_PARALLELISM"] = "true"
self.latency_cpu = 1
self.latency_gpu = 10
free_mem = total_mem * 0.95 - torch.cuda.memory_allocated(self.dev) # TODO: magic number
torch.set_num_threads(32)
```

```
root@job-651f5df8-zt6sd:/workspace# python ./fiddler/infer.py --model /share/models/Mixtral-8x7V-v0.1 --input 'Hello, I am' --n-token 5
Loading checkpoint shards: 100%|████████████████████████████████████████████████████████| 19/19 [00:02<00:00,  8.41it/s]
Number of experts on GPU: 56/256

Model is ready.
<s> Hello, I am
testing ...
layer 1 inference time = 8602.8583984375 ms
layer 2 inference time = 10997.8486328125 ms
layer 3 inference time = 8832.8369140625 ms
layer 4 inference time = 10439.43359375 ms
layer 5 inference time = 10648.8310546875 ms
layer 6 inference time = 14645.9755859375 ms
layer 7 inference time = 14576.482421875 ms
layer 8 inference time = 6349.60400390625 ms
layer 9 inference time = 10030.083984375 ms
layer 10 inference time = 4780.8623046875 ms
layer 11 inference time = 8219.9345703125 ms
layer 12 inference time = 1729.6107177734375 ms
layer 13 inference time = 10217.8671875 ms
layer 14 inference time = 6160.4658203125 ms
layer 15 inference time = 8688.9501953125 ms
layer 16 inference time = 6076.6240234375 ms
layer 17 inference time = 12375.6064453125 ms
layer 18 inference time = 9390.1953125 ms
layer 19 inference time = 11459.474609375 ms
layer 20 inference time = 12706.8447265625 ms
layer 21 inference time = 11032.365234375 ms
layer 22 inference time = 11581.5419921875 ms
layer 23 inference time = 6843.08984375 ms
layer 24 inference time = 9711.1220703125 ms
layer 25 inference time = 12640.654296875 ms
layer 26 inference time = 10650.5126953125 ms
layer 27 inference time = 9477.6220703125 ms
layer 28 inference time = 9774.40625 ms
layer 29 inference time = 12688.6748046875 ms
layer 30 inference time = 15793.8408203125 ms
layer 31 inference time = 12859.1533203125 ms
layer 32 inference time = 11461.5263671875 ms
to generate the word -
total inference time = 321444.9002685547 ms
avg layer inference time = 10045.153133392334 ms

a
testing ...
layer 1 inference time = 1751.468017578125 ms
layer 2 inference time = 171.8988800048828 ms
layer 3 inference time = 957.4922485351562 ms
layer 4 inference time = 7.823296070098877 ms
layer 5 inference time = 785.1314086914062 ms
layer 6 inference time = 18807.255859375 ms
layer 7 inference time = 7.625728130340576 ms
layer 8 inference time = 21915.03515625 ms
layer 9 inference time = 3086.951416015625 ms
layer 10 inference time = 7.2478718757629395 ms
layer 11 inference time = 2850.59375 ms
layer 12 inference time = 8.10598373413086 ms
layer 13 inference time = 2968.77880859375 ms
layer 14 inference time = 1172.9755859375 ms
layer 15 inference time = 1519.10302734375 ms
layer 16 inference time = 6.3763837814331055 ms
layer 17 inference time = 279.1577453613281 ms
layer 18 inference time = 265.27130126953125 ms
layer 19 inference time = 2509.854736328125 ms
layer 20 inference time = 2107.842529296875 ms
layer 21 inference time = 1697.975341796875 ms
layer 22 inference time = 995.472412109375 ms
layer 23 inference time = 2031.642578125 ms
layer 24 inference time = 1769.500732421875 ms
layer 25 inference time = 1755.5179443359375 ms
layer 26 inference time = 856.1767578125 ms
layer 27 inference time = 1446.287353515625 ms
layer 28 inference time = 6.250495910644531 ms
layer 29 inference time = 4752.71044921875 ms
layer 30 inference time = 719.8966064453125 ms
layer 31 inference time = 2940.621826171875 ms
layer 32 inference time = 3964.67822265625 ms
to generate the word -
total inference time = 84122.72045469284 ms
avg layer inference time = 2628.8350142091513 ms

new
testing ...
layer 1 inference time = 6125.39599609375 ms
layer 2 inference time = 143.66822814941406 ms
layer 3 inference time = 2073.387939453125 ms
layer 4 inference time = 866.7330322265625 ms
layer 5 inference time = 5395.3134765625 ms
layer 6 inference time = 353.4785461425781 ms
layer 7 inference time = 4.114367961883545 ms
layer 8 inference time = 2631.299072265625 ms
layer 9 inference time = 648.4470825195312 ms
layer 10 inference time = 4.114431858062744 ms
layer 11 inference time = 2339.11083984375 ms
layer 12 inference time = 7.489535808563232 ms
layer 13 inference time = 2757.084228515625 ms
layer 14 inference time = 2599.77001953125 ms
layer 15 inference time = 3512.700927734375 ms
layer 16 inference time = 7.49567985534668 ms
layer 17 inference time = 2355.80517578125 ms
layer 18 inference time = 2418.420654296875 ms
layer 19 inference time = 3460.792236328125 ms
layer 20 inference time = 1468.9342041015625 ms
layer 21 inference time = 3222.82080078125 ms
layer 22 inference time = 2326.5166015625 ms
layer 23 inference time = 3194.712158203125 ms
layer 24 inference time = 1835.56396484375 ms
layer 25 inference time = 3504.616455078125 ms
layer 26 inference time = 314.0075378417969 ms
layer 27 inference time = 2734.991455078125 ms
layer 28 inference time = 7.720928192138672 ms
layer 29 inference time = 7.246880054473877 ms
layer 30 inference time = 3644.10986328125 ms
layer 31 inference time = 1017.3163452148438 ms
layer 32 inference time = 1997.676513671875 ms
to generate the word -
total inference time = 62980.85517883301 ms
avg layer inference time = 1968.1517243385315 ms

bie
testing ...
layer 1 inference time = 301.1748352050781 ms
layer 2 inference time = 3065.0625 ms
layer 3 inference time = 1810.85595703125 ms
layer 4 inference time = 2468.15234375 ms
layer 5 inference time = 3542.754150390625 ms
layer 6 inference time = 282.9168701171875 ms
layer 7 inference time = 4.099071979522705 ms
layer 8 inference time = 126.62886047363281 ms
layer 9 inference time = 155.3797149658203 ms
layer 10 inference time = 2804.83740234375 ms
layer 11 inference time = 793.1709594726562 ms
layer 12 inference time = 2683.7001953125 ms
layer 13 inference time = 5864.80419921875 ms
layer 14 inference time = 1604.955078125 ms
layer 15 inference time = 7393.27587890625 ms
layer 16 inference time = 6.403071880340576 ms
layer 17 inference time = 2965.30126953125 ms
layer 18 inference time = 5051.81396484375 ms
layer 19 inference time = 5038.85595703125 ms
layer 20 inference time = 2989.635498046875 ms
layer 21 inference time = 5805.41748046875 ms
layer 22 inference time = 1362.9000244140625 ms
layer 23 inference time = 3611.864013671875 ms
layer 24 inference time = 4684.8984375 ms
layer 25 inference time = 2242.177978515625 ms
layer 26 inference time = 2170.267578125 ms
layer 27 inference time = 3160.731689453125 ms
layer 28 inference time = 3007.153076171875 ms
layer 29 inference time = 2337.93017578125 ms
layer 30 inference time = 1196.8931884765625 ms
layer 31 inference time = 813.749267578125 ms
layer 32 inference time = 167.1526336669922 ms
to generate the word -
total inference time = 79514.91332244873 ms
avg layer inference time = 2484.841041326523 ms

to
testing ...
layer 1 inference time = 5525.01025390625 ms
layer 2 inference time = 1523.2593994140625 ms
layer 3 inference time = 2720.3388671875 ms
layer 4 inference time = 695.3175048828125 ms
layer 5 inference time = 549.2459716796875 ms
layer 6 inference time = 4764.91748046875 ms
layer 7 inference time = 2881.408935546875 ms
layer 8 inference time = 343.2458190917969 ms
layer 9 inference time = 126.77017974853516 ms
layer 10 inference time = 2975.18701171875 ms
layer 11 inference time = 1424.7291259765625 ms
layer 12 inference time = 6.07539176940918 ms
layer 13 inference time = 1404.91064453125 ms
layer 14 inference time = 3424.543701171875 ms
layer 15 inference time = 3044.296630859375 ms
layer 16 inference time = 3179.144287109375 ms
layer 17 inference time = 196.66738891601562 ms
layer 18 inference time = 4119.150390625 ms
layer 19 inference time = 3618.704345703125 ms
layer 20 inference time = 4076.5439453125 ms
layer 21 inference time = 4581.7978515625 ms
layer 22 inference time = 3333.65869140625 ms
layer 23 inference time = 2013.50244140625 ms
layer 24 inference time = 1884.610595703125 ms
layer 25 inference time = 6068.720703125 ms
layer 26 inference time = 2450.532470703125 ms
layer 27 inference time = 1958.0784912109375 ms
layer 28 inference time = 2620.577880859375 ms
layer 29 inference time = 3016.82080078125 ms
layer 30 inference time = 2282.50830078125 ms
layer 31 inference time = 3863.867431640625 ms
layer 32 inference time = 2101.4169921875 ms
to generate the word -
total inference time = 82775.5599269867 ms
avg layer inference time = 2586.736247718334 ms

--------------------
Input: Hello, I am
Output:  a new bie to
prefill_time: 321.4914712905884, decode_time: 309.41642928123474, hit_rate: 0.28125
```

```
root@job-651f5df8-zt6sd:/workspace# python ./fiddler/infer.py --model /share/models/Mixtral-8x7V-v0.1 --input 'Hello, I am' --n-token 5
Loading checkpoint shards: 100%|████████████████████████████████████████████████████████| 19/19 [00:02<00:00,  9.05it/s]
Number of experts on GPU: 56/256

Model is ready.
<s> Hello, I am
testing ...
layer 1 inference time = 12337.4951171875 ms
layer 2 inference time = 12272.4033203125 ms
layer 3 inference time = 11047.125 ms
layer 4 inference time = 13004.67578125 ms
layer 5 inference time = 13124.3017578125 ms
layer 6 inference time = 18952.607421875 ms
layer 7 inference time = 15846.8388671875 ms
layer 8 inference time = 5983.12548828125 ms
layer 9 inference time = 9392.5498046875 ms
layer 10 inference time = 4921.025390625 ms
layer 11 inference time = 8084.9990234375 ms
layer 12 inference time = 2245.2685546875 ms
layer 13 inference time = 10524.2744140625 ms
layer 14 inference time = 6711.2509765625 ms
layer 15 inference time = 9663.662109375 ms
layer 16 inference time = 6029.9599609375 ms
layer 17 inference time = 14109.52734375 ms
layer 18 inference time = 9385.701171875 ms
layer 19 inference time = 12114.9794921875 ms
layer 20 inference time = 12180.0517578125 ms
layer 21 inference time = 9966.9072265625 ms
layer 22 inference time = 10386.1484375 ms
layer 23 inference time = 6639.73876953125 ms
layer 24 inference time = 9771.9326171875 ms
layer 25 inference time = 9395.34375 ms
layer 26 inference time = 8775.16015625 ms
layer 27 inference time = 10559.9033203125 ms
layer 28 inference time = 13590.009765625 ms
layer 29 inference time = 15302.197265625 ms
layer 30 inference time = 12701.078125 ms
layer 31 inference time = 10992.44140625 ms
layer 32 inference time = 11364.5146484375 ms
to generate the word -
total inference time = 337377.1982421875 ms
avg layer inference time = 10543.03744506836 ms

a
testing ...
layer 1 inference time = 6100.55908203125 ms
layer 2 inference time = 3032.77978515625 ms
layer 3 inference time = 3010.5107421875 ms
layer 4 inference time = 7.724031925201416 ms
layer 5 inference time = 4243.265625 ms
layer 6 inference time = 3341.18505859375 ms
layer 7 inference time = 7.7649922370910645 ms
layer 8 inference time = 967.4506225585938 ms
layer 9 inference time = 3004.396484375 ms
layer 10 inference time = 6.2259202003479 ms
layer 11 inference time = 1445.5029296875 ms
layer 12 inference time = 7.583744049072266 ms
layer 13 inference time = 2966.498291015625 ms
layer 14 inference time = 1264.7291259765625 ms
layer 15 inference time = 2904.056884765625 ms
layer 16 inference time = 7.8919677734375 ms
layer 17 inference time = 309.5878601074219 ms
layer 18 inference time = 1546.435546875 ms
layer 19 inference time = 2161.502197265625 ms
layer 20 inference time = 2675.265625 ms
layer 21 inference time = 1604.1185302734375 ms
layer 22 inference time = 772.6192626953125 ms
layer 23 inference time = 2000.753662109375 ms
layer 24 inference time = 1246.982177734375 ms
layer 25 inference time = 810.9865112304688 ms
layer 26 inference time = 1381.3115234375 ms
layer 27 inference time = 808.7797241210938 ms
layer 28 inference time = 6.315008163452148 ms
layer 29 inference time = 1829.5194091796875 ms
layer 30 inference time = 994.07666015625 ms
layer 31 inference time = 2515.13134765625 ms
layer 32 inference time = 3744.468017578125 ms
to generate the word -
total inference time = 56725.97835111618 ms
avg layer inference time = 1772.6868234723806 ms

new
testing ...
layer 1 inference time = 6061.09814453125 ms
layer 2 inference time = 637.8670043945312 ms
layer 3 inference time = 1956.927490234375 ms
layer 4 inference time = 612.6233520507812 ms
layer 5 inference time = 5353.24560546875 ms
layer 6 inference time = 606.2847900390625 ms
layer 7 inference time = 8.158207893371582 ms
layer 8 inference time = 1460.3131103515625 ms
layer 9 inference time = 723.5174560546875 ms
layer 10 inference time = 7.728127956390381 ms
layer 11 inference time = 1304.995849609375 ms
layer 12 inference time = 8.101887702941895 ms
layer 13 inference time = 9170.1259765625 ms
layer 14 inference time = 1456.1761474609375 ms
layer 15 inference time = 3426.85498046875 ms
layer 16 inference time = 6.748159885406494 ms
layer 17 inference time = 2716.93408203125 ms
layer 18 inference time = 2400.858154296875 ms
layer 19 inference time = 1841.90673828125 ms
layer 20 inference time = 1156.5352783203125 ms
layer 21 inference time = 3302.653076171875 ms
layer 22 inference time = 1755.5220947265625 ms
layer 23 inference time = 1894.7030029296875 ms
layer 24 inference time = 1278.097412109375 ms
layer 25 inference time = 2187.302001953125 ms
layer 26 inference time = 559.9088745117188 ms
layer 27 inference time = 2283.373779296875 ms
layer 28 inference time = 7.710720062255859 ms
layer 29 inference time = 7.313407897949219 ms
layer 30 inference time = 3736.393798828125 ms
layer 31 inference time = 767.7552490234375 ms
layer 32 inference time = 1802.673095703125 ms
to generate the word -
total inference time = 60500.40705680847 ms
avg layer inference time = 1890.6377205252647 ms

bie
testing ...
layer 1 inference time = 749.6478881835938 ms
layer 2 inference time = 3110.41845703125 ms
layer 3 inference time = 1401.2569580078125 ms
layer 4 inference time = 1569.9384765625 ms
layer 5 inference time = 2254.609375 ms
layer 6 inference time = 242.3408660888672 ms
layer 7 inference time = 4.093952178955078 ms
layer 8 inference time = 118.57510375976562 ms
layer 9 inference time = 443.7340087890625 ms
layer 10 inference time = 995.42724609375 ms
layer 11 inference time = 676.4278564453125 ms
layer 12 inference time = 1661.305908203125 ms
layer 13 inference time = 3860.170654296875 ms
layer 14 inference time = 1537.671142578125 ms
layer 15 inference time = 4679.7763671875 ms
layer 16 inference time = 7.880703926086426 ms
layer 17 inference time = 1500.8388671875 ms
layer 18 inference time = 4133.34814453125 ms
layer 19 inference time = 2445.18505859375 ms
layer 20 inference time = 2037.02880859375 ms
layer 21 inference time = 4984.21337890625 ms
layer 22 inference time = 1577.2816162109375 ms
layer 23 inference time = 3531.765869140625 ms
layer 24 inference time = 3743.794189453125 ms
layer 25 inference time = 1727.131591796875 ms
layer 26 inference time = 1616.5089111328125 ms
layer 27 inference time = 3177.882568359375 ms
layer 28 inference time = 3172.255859375 ms
layer 29 inference time = 1850.2962646484375 ms
layer 30 inference time = 1140.3837890625 ms
layer 31 inference time = 358.3948669433594 ms
layer 32 inference time = 161.66400146484375 ms
to generate the word -
total inference time = 60471.24874973297 ms
avg layer inference time = 1889.7265234291553 ms

to
testing ...
layer 1 inference time = 4985.91015625 ms
layer 2 inference time = 1471.698974609375 ms
layer 3 inference time = 2338.0439453125 ms
layer 4 inference time = 413.2537536621094 ms
layer 5 inference time = 930.908203125 ms
layer 6 inference time = 4308.5927734375 ms
layer 7 inference time = 2882.303955078125 ms
layer 8 inference time = 547.2163696289062 ms
layer 9 inference time = 115.67001342773438 ms
layer 10 inference time = 2389.80810546875 ms
layer 11 inference time = 603.0182495117188 ms
layer 12 inference time = 3.993472099304199 ms
layer 13 inference time = 1149.7513427734375 ms
layer 14 inference time = 3003.317138671875 ms
layer 15 inference time = 2497.37841796875 ms
layer 16 inference time = 3008.0615234375 ms
layer 17 inference time = 133.14866638183594 ms
layer 18 inference time = 2239.003662109375 ms
layer 19 inference time = 3027.5205078125 ms
layer 20 inference time = 3001.587646484375 ms
layer 21 inference time = 3628.810302734375 ms
layer 22 inference time = 3173.655517578125 ms
layer 23 inference time = 342.24542236328125 ms
layer 24 inference time = 4067.696533203125 ms
layer 25 inference time = 4869.22119140625 ms
layer 26 inference time = 3618.9296875 ms
layer 27 inference time = 1231.1591796875 ms
layer 28 inference time = 2159.513671875 ms
layer 29 inference time = 267.35308837890625 ms
layer 30 inference time = 1619.04736328125 ms
layer 31 inference time = 2369.955810546875 ms
layer 32 inference time = 1374.91455078125 ms
to generate the word -
total inference time = 67772.68919658661 ms
avg layer inference time = 2117.8965373933315 ms

--------------------
Input: Hello, I am
Output:  a new bie to
prefill_time: 337.5215711593628, decode_time: 245.50192713737488, hit_rate: 0.28125
root@job-651f5df8-zt6sd:/workspace# python ./fiddler/infer.py --model /share/models/Mixtral-8x7V-v0.1 --input 'Hello, I am' --n-token 5
Loading checkpoint shards: 100%|████████████████████████████████████████████████████████| 19/19 [00:02<00:00,  8.49it/s]
Number of experts on GPU: 56/256

Model is ready.
<s> Hello, I am
testing ...
layer 1 inference time = 10807.890625 ms
layer 2 inference time = 12493.19921875 ms
layer 3 inference time = 8374.8056640625 ms
layer 4 inference time = 14638.888671875 ms
layer 5 inference time = 15338.5771484375 ms
layer 6 inference time = 13012.40625 ms
layer 7 inference time = 15314.1552734375 ms
layer 8 inference time = 5970.98486328125 ms
layer 9 inference time = 8663.041015625 ms
layer 10 inference time = 2454.20654296875 ms
layer 11 inference time = 6841.76708984375 ms
layer 12 inference time = 645.5643920898438 ms
layer 13 inference time = 8276.77734375 ms
layer 14 inference time = 4958.38720703125 ms
layer 15 inference time = 7293.22802734375 ms
layer 16 inference time = 6350.248046875 ms
layer 17 inference time = 14087.5615234375 ms
layer 18 inference time = 8463.4951171875 ms
layer 19 inference time = 9932.5263671875 ms
layer 20 inference time = 11732.14453125 ms
layer 21 inference time = 7920.8037109375 ms
layer 22 inference time = 9204.3671875 ms
layer 23 inference time = 3859.498046875 ms
layer 24 inference time = 8617.1201171875 ms
layer 25 inference time = 10094.8466796875 ms
layer 26 inference time = 9280.591796875 ms
layer 27 inference time = 9907.892578125 ms
layer 28 inference time = 10568.33984375 ms
layer 29 inference time = 14273.458984375 ms
layer 30 inference time = 16595.28515625 ms
layer 31 inference time = 14013.890625 ms
layer 32 inference time = 10913.98046875 ms
to generate the word -
total inference time = 310899.9301147461 ms
avg layer inference time = 9715.622816085815 ms

a
testing ...
layer 1 inference time = 2779.68896484375 ms
layer 2 inference time = 1043.0975341796875 ms
layer 3 inference time = 1475.5133056640625 ms
layer 4 inference time = 6.02726411819458 ms
layer 5 inference time = 2801.17431640625 ms
layer 6 inference time = 1660.55224609375 ms
layer 7 inference time = 6.0478081703186035 ms
layer 8 inference time = 375.54278564453125 ms
layer 9 inference time = 1011.8143920898438 ms
layer 10 inference time = 7.797760009765625 ms
layer 11 inference time = 3145.238525390625 ms
layer 12 inference time = 7.667712211608887 ms
layer 13 inference time = 1154.1298828125 ms
layer 14 inference time = 144.11570739746094 ms
layer 15 inference time = 624.3123168945312 ms
layer 16 inference time = 8.062975883483887 ms
layer 17 inference time = 160.31015014648438 ms
layer 18 inference time = 938.9127807617188 ms
layer 19 inference time = 1438.940185546875 ms
layer 20 inference time = 1661.8782958984375 ms
layer 21 inference time = 2728.944580078125 ms
layer 22 inference time = 591.7716064453125 ms
layer 23 inference time = 934.1439819335938 ms
layer 24 inference time = 1375.9232177734375 ms
layer 25 inference time = 1098.3045654296875 ms
layer 26 inference time = 483.9977111816406 ms
layer 27 inference time = 907.3796997070312 ms
layer 28 inference time = 6.217728137969971 ms
layer 29 inference time = 835.8287353515625 ms
layer 30 inference time = 3078.5546875 ms
layer 31 inference time = 1898.535888671875 ms
layer 32 inference time = 3672.08544921875 ms
to generate the word -
total inference time = 38062.512761592865 ms
avg layer inference time = 1189.453523799777 ms

new
testing ...
layer 1 inference time = 4510.310546875 ms
layer 2 inference time = 344.2196350097656 ms
layer 3 inference time = 1039.7674560546875 ms
layer 4 inference time = 2816.05224609375 ms
layer 5 inference time = 2669.218994140625 ms
layer 6 inference time = 712.975341796875 ms
layer 7 inference time = 6.098944187164307 ms
layer 8 inference time = 1304.5145263671875 ms
layer 9 inference time = 2535.04296875 ms
layer 10 inference time = 6.096767902374268 ms
layer 11 inference time = 785.122314453125 ms
layer 12 inference time = 5.983232021331787 ms
layer 13 inference time = 2154.262451171875 ms
layer 14 inference time = 1094.1358642578125 ms
layer 15 inference time = 6098.5888671875 ms
layer 16 inference time = 7.791615962982178 ms
layer 17 inference time = 2065.5185546875 ms
layer 18 inference time = 2180.844482421875 ms
layer 19 inference time = 1805.1697998046875 ms
layer 20 inference time = 2095.38671875 ms
layer 21 inference time = 3390.326904296875 ms
layer 22 inference time = 1400.2503662109375 ms
layer 23 inference time = 1694.3974609375 ms
layer 24 inference time = 1165.264892578125 ms
layer 25 inference time = 1308.9627685546875 ms
layer 26 inference time = 323.2173156738281 ms
layer 27 inference time = 1192.880126953125 ms
layer 28 inference time = 4.072447776794434 ms
layer 29 inference time = 3.664896011352539 ms
layer 30 inference time = 3365.57373046875 ms
layer 31 inference time = 735.2504272460938 ms
layer 32 inference time = 1707.2763671875 ms
to generate the word -
total inference time = 50528.23903179169 ms
avg layer inference time = 1579.0074697434902 ms

bie
testing ...
layer 1 inference time = 273.14996337890625 ms
layer 2 inference time = 3006.80908203125 ms
layer 3 inference time = 701.2874145507812 ms
layer 4 inference time = 1025.685546875 ms
layer 5 inference time = 1883.7279052734375 ms
layer 6 inference time = 225.98963928222656 ms
layer 7 inference time = 4.082687854766846 ms
layer 8 inference time = 114.75468444824219 ms
layer 9 inference time = 120.16230773925781 ms
layer 10 inference time = 599.404541015625 ms
layer 11 inference time = 170.59327697753906 ms
layer 12 inference time = 1142.7808837890625 ms
layer 13 inference time = 3608.7275390625 ms
layer 14 inference time = 859.01416015625 ms
layer 15 inference time = 3684.250732421875 ms
layer 16 inference time = 6.857728004455566 ms
layer 17 inference time = 892.099609375 ms
layer 18 inference time = 5032.61572265625 ms
layer 19 inference time = 1613.7677001953125 ms
layer 20 inference time = 1431.2314453125 ms
layer 21 inference time = 4405.416015625 ms
layer 22 inference time = 1014.1563110351562 ms
layer 23 inference time = 2568.052734375 ms
layer 24 inference time = 3515.005859375 ms
layer 25 inference time = 2266.9189453125 ms
layer 26 inference time = 2446.84912109375 ms
layer 27 inference time = 3153.787841796875 ms
layer 28 inference time = 3006.718017578125 ms
layer 29 inference time = 2188.598388671875 ms
layer 30 inference time = 2483.211181640625 ms
layer 31 inference time = 560.1187133789062 ms
layer 32 inference time = 117.6012191772461 ms
to generate the word -
total inference time = 54123.4269194603 ms
avg layer inference time = 1691.3570912331343 ms

to
testing ...
layer 1 inference time = 5730.36328125 ms
layer 2 inference time = 2064.15966796875 ms
layer 3 inference time = 2799.599609375 ms
layer 4 inference time = 840.5975952148438 ms
layer 5 inference time = 1451.5343017578125 ms
layer 6 inference time = 4991.49609375 ms
layer 7 inference time = 3184.53662109375 ms
layer 8 inference time = 735.5084838867188 ms
layer 9 inference time = 125.25990295410156 ms
layer 10 inference time = 1648.4608154296875 ms
layer 11 inference time = 227.5246124267578 ms
layer 12 inference time = 3.989504098892212 ms
layer 13 inference time = 723.5000610351562 ms
layer 14 inference time = 3019.3857421875 ms
layer 15 inference time = 2075.54052734375 ms
layer 16 inference time = 3161.83447265625 ms
layer 17 inference time = 884.3099975585938 ms
layer 18 inference time = 2151.15478515625 ms
layer 19 inference time = 3405.41455078125 ms
layer 20 inference time = 3306.262451171875 ms
layer 21 inference time = 3818.31787109375 ms
layer 22 inference time = 3158.161376953125 ms
layer 23 inference time = 342.64678955078125 ms
layer 24 inference time = 3453.476806640625 ms
layer 25 inference time = 6138.38134765625 ms
layer 26 inference time = 3626.50830078125 ms
layer 27 inference time = 982.6969604492188 ms
layer 28 inference time = 3128.607666015625 ms
layer 29 inference time = 867.4641723632812 ms
layer 30 inference time = 2731.925537109375 ms
layer 31 inference time = 3846.318115234375 ms
layer 32 inference time = 3694.3779296875 ms
to generate the word -
total inference time = 78319.3159506321 ms
avg layer inference time = 2447.478623457253 ms

--------------------
Input: Hello, I am
Output:  a new bie to
prefill_time: 310.95818066596985, decode_time: 221.06209301948547, hit_rate: 0.28125
root@job-651f5df8-zt6sd:/workspace# python ./fiddler/infer.py --model /share/models/Mixtral-8x7V-v0.1 --input 'Hello, I am' --n-token 5
Loading checkpoint shards: 100%|████████████████████████████████████████████████████████| 19/19 [00:02<00:00,  7.13it/s]
Number of experts on GPU: 56/256

Model is ready.
<s> Hello, I am
testing ...
layer 1 inference time = 11384.8466796875 ms
layer 2 inference time = 12353.087890625 ms
layer 3 inference time = 8445.875 ms
layer 4 inference time = 9919.1962890625 ms
layer 5 inference time = 11481.1630859375 ms
layer 6 inference time = 13485.73828125 ms
layer 7 inference time = 15614.5419921875 ms
layer 8 inference time = 7085.615234375 ms
layer 9 inference time = 9622.2998046875 ms
layer 10 inference time = 2475.724853515625 ms
layer 11 inference time = 8110.85009765625 ms
layer 12 inference time = 1230.497802734375 ms
layer 13 inference time = 10320.044921875 ms
layer 14 inference time = 6129.7490234375 ms
layer 15 inference time = 8015.64453125 ms
layer 16 inference time = 6171.1533203125 ms
layer 17 inference time = 12631.892578125 ms
layer 18 inference time = 8965.0947265625 ms
layer 19 inference time = 10982.4638671875 ms
layer 20 inference time = 12321.818359375 ms
layer 21 inference time = 8551.9052734375 ms
layer 22 inference time = 9598.8173828125 ms
layer 23 inference time = 4312.533203125 ms
layer 24 inference time = 9870.95703125 ms
layer 25 inference time = 9140.955078125 ms
layer 26 inference time = 7826.71240234375 ms
layer 27 inference time = 10522.3974609375 ms
layer 28 inference time = 10136.1298828125 ms
layer 29 inference time = 13250.841796875 ms
layer 30 inference time = 11686.986328125 ms
layer 31 inference time = 10192.4677734375 ms
layer 32 inference time = 10572.1640625 ms
to generate the word -
total inference time = 302410.166015625 ms
avg layer inference time = 9450.317687988281 ms

a
testing ...
layer 1 inference time = 2099.70068359375 ms
layer 2 inference time = 1145.1739501953125 ms
layer 3 inference time = 1626.29833984375 ms
layer 4 inference time = 6.092800140380859 ms
layer 5 inference time = 2484.27734375 ms
layer 6 inference time = 4628.4072265625 ms
layer 7 inference time = 7.807007789611816 ms
layer 8 inference time = 822.781982421875 ms
layer 9 inference time = 2686.76904296875 ms
layer 10 inference time = 6.302720069885254 ms
layer 11 inference time = 766.8633422851562 ms
layer 12 inference time = 6.037504196166992 ms
layer 13 inference time = 2434.8671875 ms
layer 14 inference time = 1603.6485595703125 ms
layer 15 inference time = 2357.708740234375 ms
layer 16 inference time = 8.295424461364746 ms
layer 17 inference time = 333.02740478515625 ms
layer 18 inference time = 2341.191650390625 ms
layer 19 inference time = 3145.110595703125 ms
layer 20 inference time = 3342.36865234375 ms
layer 21 inference time = 3066.04541015625 ms
layer 22 inference time = 937.8386840820312 ms
layer 23 inference time = 2740.513916015625 ms
layer 24 inference time = 1954.255859375 ms
layer 25 inference time = 507.5999450683594 ms
layer 26 inference time = 941.1337890625 ms
layer 27 inference time = 674.9501342773438 ms
layer 28 inference time = 4.196288108825684 ms
layer 29 inference time = 465.7366943359375 ms
layer 30 inference time = 2231.160888671875 ms
layer 31 inference time = 2396.873779296875 ms
layer 32 inference time = 4478.19873046875 ms
to generate the word -
total inference time = 52251.23427772522 ms
avg layer inference time = 1632.8510711789131 ms

new
testing ...
layer 1 inference time = 3982.57275390625 ms
layer 2 inference time = 432.2641906738281 ms
layer 3 inference time = 2499.515380859375 ms
layer 4 inference time = 1565.581298828125 ms
layer 5 inference time = 2863.029296875 ms
layer 6 inference time = 1328.2396240234375 ms
layer 7 inference time = 6.091807842254639 ms
layer 8 inference time = 581.5296020507812 ms
layer 9 inference time = 2276.22705078125 ms
layer 10 inference time = 6.091648101806641 ms
layer 11 inference time = 1298.3121337890625 ms
layer 12 inference time = 7.4967041015625 ms
layer 13 inference time = 1027.9925537109375 ms
layer 14 inference time = 1540.6551513671875 ms
layer 15 inference time = 3662.804931640625 ms
layer 16 inference time = 7.868415832519531 ms
layer 17 inference time = 1780.1175537109375 ms
layer 18 inference time = 2108.7734375 ms
layer 19 inference time = 2431.71630859375 ms
layer 20 inference time = 1752.8544921875 ms
layer 21 inference time = 3530.48681640625 ms
layer 22 inference time = 2409.651123046875 ms
layer 23 inference time = 2128.660400390625 ms
layer 24 inference time = 2489.885498046875 ms
layer 25 inference time = 2030.5838623046875 ms
layer 26 inference time = 656.4833374023438 ms
layer 27 inference time = 1056.805908203125 ms
layer 28 inference time = 6.141952037811279 ms
layer 29 inference time = 4.994048118591309 ms
layer 30 inference time = 4084.632568359375 ms
layer 31 inference time = 646.793212890625 ms
layer 32 inference time = 1702.998046875 ms
to generate the word -
total inference time = 51907.851110458374 ms
avg layer inference time = 1622.1203472018242 ms

bie
testing ...
layer 1 inference time = 285.3447570800781 ms
layer 2 inference time = 3009.027099609375 ms
layer 3 inference time = 1726.6513671875 ms
layer 4 inference time = 2492.94140625 ms
layer 5 inference time = 3216.11376953125 ms
layer 6 inference time = 300.91058349609375 ms
layer 7 inference time = 4.184063911437988 ms
layer 8 inference time = 175.42962646484375 ms
layer 9 inference time = 552.995849609375 ms
layer 10 inference time = 2898.736083984375 ms
layer 11 inference time = 183.38201904296875 ms
layer 12 inference time = 2763.10107421875 ms
layer 13 inference time = 5990.79443359375 ms
layer 14 inference time = 305.6763000488281 ms
layer 15 inference time = 5205.8349609375 ms
layer 16 inference time = 7.664639949798584 ms
layer 17 inference time = 1653.55517578125 ms
layer 18 inference time = 4938.57080078125 ms
layer 19 inference time = 3625.025634765625 ms
layer 20 inference time = 1363.0177001953125 ms
layer 21 inference time = 4800.44970703125 ms
layer 22 inference time = 271.28216552734375 ms
layer 23 inference time = 2109.286376953125 ms
layer 24 inference time = 3955.778564453125 ms
layer 25 inference time = 2126.42724609375 ms
layer 26 inference time = 2050.994140625 ms
layer 27 inference time = 3189.92578125 ms
layer 28 inference time = 3168.1064453125 ms
layer 29 inference time = 1987.36279296875 ms
layer 30 inference time = 2097.765380859375 ms
layer 31 inference time = 1072.779296875 ms
layer 32 inference time = 129.07725524902344 ms
to generate the word -
total inference time = 67658.1924996376 ms
avg layer inference time = 2114.318515613675 ms

to
testing ...
layer 1 inference time = 4570.83203125 ms
layer 2 inference time = 728.0414428710938 ms
layer 3 inference time = 2072.88427734375 ms
layer 4 inference time = 605.2136840820312 ms
layer 5 inference time = 1290.4530029296875 ms
layer 6 inference time = 2948.117431640625 ms
layer 7 inference time = 3079.19677734375 ms
layer 8 inference time = 960.0369262695312 ms
layer 9 inference time = 127.99180603027344 ms
layer 10 inference time = 1745.650634765625 ms
layer 11 inference time = 438.1685791015625 ms
layer 12 inference time = 7.988224029541016 ms
layer 13 inference time = 589.7081909179688 ms
layer 14 inference time = 3100.190673828125 ms
layer 15 inference time = 2439.255126953125 ms
layer 16 inference time = 3026.934814453125 ms
layer 17 inference time = 198.17062377929688 ms
layer 18 inference time = 3696.902099609375 ms
layer 19 inference time = 3356.505126953125 ms
layer 20 inference time = 3053.68994140625 ms
layer 21 inference time = 3337.03076171875 ms
layer 22 inference time = 3034.87060546875 ms
layer 23 inference time = 131.75091552734375 ms
layer 24 inference time = 3528.8330078125 ms
layer 25 inference time = 4996.365234375 ms
layer 26 inference time = 3515.6142578125 ms
layer 27 inference time = 391.6810302734375 ms
layer 28 inference time = 1539.69970703125 ms
layer 29 inference time = 607.046630859375 ms
layer 30 inference time = 1800.8258056640625 ms
layer 31 inference time = 2651.7216796875 ms
layer 32 inference time = 3101.920166015625 ms
to generate the word -
total inference time = 66673.29121780396 ms
avg layer inference time = 2083.5403505563736 ms

--------------------
Input: Hello, I am
Output:  a new bie to
prefill_time: 302.591046333313, decode_time: 238.521488904953, hit_rate: 0.28125
root@job-651f5df8-zt6sd:/workspace#
```