import sys
import memcache
memcached = memcache.Client(['127.0.0.1:11211'], debug=1);

# Fetch contact information by id
def getContactById(contactId):
	contact = memcached.get(contactId)
	print(contact)

# Get contact id from the command line
contactId= sys.argv[0]
getContactById(contactId)