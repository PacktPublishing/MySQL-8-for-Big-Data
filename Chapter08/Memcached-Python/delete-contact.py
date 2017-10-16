import sys
import memcache
memcached = memcache.Client(['127.0.0.1:11211'], debug=1);

def deleteContact(contactId)
	memcached.delete(contactId)
	print "Contact information has been deleted successfully"


# Get contact information pass from the command line
contactId= sys.argv[0]
deleteContact(contactId)