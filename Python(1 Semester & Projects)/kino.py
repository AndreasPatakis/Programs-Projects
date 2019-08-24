import urllib2
import json
import datetime

today=datetime.date.today()
todaystr= today.strftime("%d-%m-%Y")
endstr=today.strftime("01-%m-%Y")

start_date = datetime.datetime.strptime(todaystr, "%d-%m-%Y")
end_date = datetime.datetime.strptime(endstr,"%d-%m-%Y")

my_numbers=[5,10,15,20,25,30,35,40,45,50]
days=[]
results=[]
while start_date>=end_date:
    a=0
    response = urllib2.urlopen('http://applications.opap.gr/DrawsRestServices/kino/drawDate/%s.json'%todaystr)
    data = response.read()
    datastr=json.loads(data)
    lottery=datastr['draws']['draw']
    for apotelesma in range(len(lottery)):
        p=0

        for arithmos in range(len(my_numbers)):
            p+=lottery[apotelesma]['results'].count(my_numbers[arithmos])

        if (p>=4):
            a+=1
    results.append(a)
    days.append(todaystr)
    start_date = start_date - datetime.timedelta(days=1)
    todaystr= start_date.strftime("%d-%m-%Y")


best_result=results[::-1]
best_day=days[::-1]

for mera in range(len(best_result)):
    if (max(best_result)==best_result[mera]):
        print "To kalutero score vrethike htan: ",best_result[mera],"  kai vrethike stis: ",best_day[mera],"."
