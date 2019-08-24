import random

text=[]
with open('text.txt') as keimeno:
        text=keimeno.read()
        text=text.replace(',',' ')
        text=text.replace('.',' ')
        text=text.replace(')',' ')
        text=text.replace('(',' ')
        text=text.replace('"',' ')
        text=text.split(' ')

while text.count(''):
    text.remove('')



lista=[]
for i in range(len(text)):
    if (any(letter.isupper() for letter in text[i])):
        pass
    else:
        lista.append(text[i])
lista.remove(lista[-1])

lastletter=lista[-1]

triades=[]
temp=[]
for leksi in range(2,len(lista)):
    temp.append(lista[leksi-2])
    temp.append(lista[leksi-1])
    temp.append(lista[leksi])
    triades.append(temp)
    temp=[]

triades=random.sample(triades,len(triades))



telos=''
telos=triades[0]

leksis=0
while leksis<=196:
	temp=[]	
 	for thesi in range(len(triades)):
		if telos[-1]==lastletter:
			temp1=random.sample(triades,len(triades))
			while lastletter==temp1[0][2]:
				temp1=random.sample(temp,len(temp))
			if leksis==197:
				telos.append(temp1[0][0])
			else:
				telos.append(temp1[0][0])
				telos.append(temp1[0][1])
			leksis+=1
			break
        	elif (telos[-2]==triades[thesi][0] and telos[-1]==triades[thesi][1]):
       			temp.append(triades[thesi][2]) 
        	thesi+=1

	if len(temp)!=0:
    		temp=random.sample(temp,len(temp))
    		telos.append(temp[0])
 	leksis+=1



print len(telos)
print telos		


