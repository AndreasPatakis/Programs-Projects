import urllib2
from bs4 import BeautifulSoup as soup
import json
import webbrowser
import re



product_keyphrase_list = ['lap','microphones']
product_type_list=['laptop','pro_microphones']
product_name_list=['Apple MacBook Pro 13.3" (i5/8GB/128GB) (2017)','OEM BM-700']
product_shop_list=[]
product_shopurl_list=[]
product_price_list=[]

the_url = 'https://www.skroutz.gr'

for product in range(len(product_keyphrase_list)):
    url = 'https://www.skroutz.gr/search?keyphrase=%s&from=autocomplete'%product_keyphrase_list[product]


    urlopen = urllib2.urlopen(url)
    data = urlopen.read()

    data_soup = soup(data, 'html.parser')

    all_li = data_soup.body.main.ul.findAll('li')

    product_href=[]

    for i in range (len(all_li)):
        product_href.append(all_li[i].a['href'])

    for i in range (len(product_href)):
        if (product_type_list[product] in product_href[i]):
            product_href[i] = product_href[i].split('?')
            type_link=the_url + product_href[i][0]
            break

    urlopen = urllib2.urlopen(type_link)
    data = urlopen.read()

    data_soup = soup(data, 'html.parser')

    page_ol = data_soup.body.main.div.section.findAll('ol',{'id':'sku-list'})
    all_li = page_ol[0].findAll('li')

    product_href=[]




    for i in range (len(all_li)):
        #print all_li[i]
        temp = all_li[i].find(title=product_name_list[product])
        product_href.append(temp['href'])
        temp = the_url + temp['href']
        product_link = temp
        break


    urlopen = urllib2.urlopen(temp)
    data = urlopen.read()
    data_soup = soup(data, 'html.parser')

    page_div = data_soup.body.main.findAll('div',{'class':'prices js-prices section content'})
    page_li = page_div[0].ol.li
    temp = page_li.div.a.img['alt']
    product_shop_list.append(temp)
    temp = page_li.findAll('div',{'class':'price'})
    temp = temp[0].div.findAll('a',{'rel':'nofollow'})

    product_shopurl_list.append(the_url+temp[0]['href'])
    product_price_list.append(temp[0].text)

    print ' '
    print 'Product name: ',product_name_list[product]
    print 'First Price Appeared: ',product_price_list[product]
    print 'First Shop Appeared: ',product_shop_list[product]
    print 'Shop link: ',product_shopurl_list[product]
    print ' '
