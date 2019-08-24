import random

a='ABCDEFGHIJKLMNOPQRSTUVWXYZ'
shuffle=[]
for gramma in a:
    shuffle.append(gramma)

abet=random.sample(shuffle,len(shuffle))

for i in range(1,len(abet)):
    abet[0]=abet[0]+abet[1]
    abet.remove(abet[1])

lista=''
lista+=abet[0]
tetragwno=[]

for i in range(100):
    for j in range(74):
        shuffle=random.sample(shuffle,len(shuffle))
        lista=lista+shuffle[-1]
    tetragwno.append(lista)
    lista=lista[74:]


katheta=[]
for i in range(100):
     katheta.append(tetragwno[0][i])
     for j in range(1,100):
         katheta[i]+=tetragwno[j][i]

text=[]
with open('keimeno.txt') as inputfile:
    for grammi in (inputfile):
        text.append(grammi.strip())

text.remove('')



orizontia_apotelesma=[]
katheta_apotelesma=[]
for j in range(len(text)):
    orizontia_apotelesma.append(tetragwno[0].count(text[j]))
    katheta_apotelesma.append(katheta[0].count(text[j]))
    for i in range(1,100):
        orizontia_apotelesma[j]+=tetragwno[i].count(text[j])
        katheta_apotelesma[j]+=katheta[i].count(text[j])

for i in range(len(orizontia_apotelesma)):
    print 'H leksi ',text[i],'vrethike ',orizontia_apotelesma[i],' fores orizontia kai ',katheta_apotelesma[i],'fores katheta,ston pinaka mas.'
