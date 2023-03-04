#!/usr/bin/python3
#功能导入txt文件中的坐标点并显示其数据
import matplotlib.pyplot as plt
import numpy as np

fig, ax = plt.subplots()
# x = np.linspace(0,2,100)
# y1 = x
# ax.plot(x, y1, label='linear')
# y2 = x ** 2
# ax.plot(x, y2, label='quadratic')
# y3 = x ** 3
# ax.plot(x, y3, label='cubic')

#f = open("./location_out.txt")
a = np.loadtxt('location_out.txt')
b = a[0]
c = a[1]
m = np.loadtxt('location_updated_out.txt');
m_x = m[0]
m_y = m[1]
ax.plot(m_x,m_y,color='r',markerfacecolor='blue',marker='o',label='updated data')
ax.plot(b,c,color='r',markerfacecolor='green',marker='o',label='origin data')     #用于显示坐标点
for a, b in zip(m_x, m_y):                                        #用于显示坐标点的数据
    plt.text(a, b, (a,b),ha='center', va='bottom', fontsize=10)
ax.set_xlabel('x label')       #设置坐标系
ax.set_ylabel('y label')
ax.set_title('Simple Plot')
ax.legend()

plt.show()    #用于显示
