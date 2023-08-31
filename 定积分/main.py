import numpy as np

N=1000
x=np.zeros([1,N])
y=np.zeros([1,N])
z=np.zeros([1,N])
w=np.zeros([1,N])
j=0
for i in range(0,999):
#####生成三个0~1的均匀分布的数字，因为x,y,z均在0~1之间，所以这里直接生成随机数就可以使用
    r=np.random.rand(1,4)
    x[0,j]=r[0,0]
    y[0,j]=r[0,1]
    z[0,j]=r[0,2]
    w[0,j]=r[0,3]
    j+=1
s=1/N*np.sum(np.log(1+x+y+z+w))
print(s)