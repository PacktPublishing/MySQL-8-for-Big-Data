import sys
import memcache
memcached = memcache.Client(['127.0.0.1:11211'], debug=1);

# Insert Contact Detail
def addContact(contactId, firstName, lastName, emailAddress, mobileNumber, companyName):
	
	valueTobeStore = firstName + ","
	valueTobeStore = lastName + ","
	valueTobeStore = emailAddress + ","
	valueTobeStore = mobileNumber + ","
	valueTobeStore = companyName
	
	memcached.set(contactId,valueTobeStore)
	print "Contact information has stored successfully"
	

# Get contact information pass from the command line
contactId= sys.argv[0]
firstName= sys.argv[1]
lastName= sys.argv[2]
emailAddress = sys.argv[3]
mobileNumber = sys.argv[4]
companyName = sys.argv[5]

# Call addContact method to store contact information
addContact(contactId, firstName, lastName, emailAddress, mobileNumber, companyName)


