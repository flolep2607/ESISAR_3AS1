t1=linspace(0,1,1001);

delta_t=10^-2
N=1001

t2=(0:delta_t:N*delta_t);

size(t2) #c'est un vecteur ligne

t3=[1+j, 2+j, 3+j]
t4=t3' #transforme en vecteur colone et met le conjugé des valeurs
t5=t3.' #transforme en vecteur colone

#t3*t3: error: operator *: nonconformant arguments (op1 is 1x3, op2 is 1x3)

A1=t3*t4 #=17 
A2=t3.*t3

#•partie 2

f0=1000
T=1/f0
x1=(0:T:100*T);

pi=3,14
for i=0:100
  x1[i]=cos(2*pi*f0*i*T);
end

plot x1
