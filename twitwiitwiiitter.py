import tweepy
from tweepy import OAuthHandler

consumer_key = 'RIei9UXWx800R3X8ioPcW7HSA'
consumer_secret = 'L7qL94GrSxIPQnEpD3Tj07iSpCkppDGBUOjacM77QOKHxkMLRl'
access_token = '246712918-hxqIC7PdvKN74Gtid4MYENrF2Qm1njrBzM21aMwx'
access_secret = 'YkSMPZi5F5XswZdLay8jwvRKRpMP3BSsFmKLgPIhlEi0o'
auth = OAuthHandler(consumer_key, consumer_secret)
auth.set_access_token(access_token, access_secret)
api = tweepy.API(auth)
print "I'm using python to mine twitter!"
user=api.me()
print user.name,user.friends_count
def on_status(self, status):
        # Prints the text of the tweet
        print('Tweet text: ' + status.text)
