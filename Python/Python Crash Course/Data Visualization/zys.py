import matplotlib.pyplot as plt
from matplotlib.pyplot import MultipleLocator 
import numpy as np
plt.style.available

plt.style.use('seaborn-v0_8')
plt.xticks() 
plt.yticks()
plt.xlim(10,100)
plt.ylim(-200,200)
ax=plt.gca();#获得坐标轴的句柄
x=np.linspace(0,100,50)
y=-x
plt.plot(x,y,color='red',linewidth=1.0,linestyle='--')
ax.spines['bottom'].set_linewidth(1)
ax.spines['left'].set_linewidth(1)
# 图表标题、坐标轴加上标签

ax.set_title("IQ of zys")
ax.set_xlabel("Value", fontsize=14)
ax.set_ylabel("IQ")
font = {'family' : 'Times New Roman',
'weight' : 'normal',
'size'   : 18,
}
plt.xlabel("Age",font)         
plt.ylabel(r"IQ",font)
x_major_locator=MultipleLocator(10)#以每15显示
y_major_locator=MultipleLocator(50)#以每3显示
ax=plt.gca()
ax.xaxis.set_major_locator(x_major_locator)
ax.yaxis.set_major_locator(y_major_locator)
#  刻度标记大小
ax.tick_params(axis='both')

plt.show()