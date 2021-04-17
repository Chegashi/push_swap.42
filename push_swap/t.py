#Three lines to make our compiler able to draw:
import sys
import matplotlib
import  math

import matplotlib.pyplot as plt
import numpy as np

Nj = np.array(range(0, 365))
 
B = (360 * (Nj - 81)) / 364
phi = 32.24
D = 23.45 * math.sin(math.radians(360 * (284+Nj) / 365))
ET = 9.87 * math.sind(math.radians(2 * B )) - 7.53 * math.cos(math.radians(B))-1.5 * math.sin(math.radians(B))
TL = np.array(start=8, stop=20, step=0.5)
L = -7.959
Lref = 0
C = 1.0
for i in range(1,len(Nj)):
    TSV(i,:) = TL - C + (L - Lref) / 15 + ET(i) / 60
   W(i,:)=15*(TSV(i,:)-12)
   sf=sind(phi)*sind(D(i))+cosd(phi)*cosd(D(i))*cosd(W(i,:))
   f(i,:)=asind(sf(i,:))
   sina(i,:)=cosd(D(i))*sind(W(i,:))./cosd(f(i,:))
   a(i,:)=asind(sina(i,:))
   plot(a(i,:),f(i,:))
   hold on 
end