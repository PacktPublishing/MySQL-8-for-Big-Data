var nosql = require('mysql-js'); 

var Contact = function(contactId, firstName, lastName, emailAddress, mobileNumber, companyName) {
    if (contactId) this.contactId = contactId;
    if (firstName) this.firstName = firstName;
	if (lastName) this.lastName = lastName;
	if (emailAddress) this.emailAddress = emailAddress;
	if (mobileNumber) this.mobileNumber = mobileNumber;
	if (companyName) this.companyName = companyName;	
};

// Map class with the Table
var annotations = new nosql.TableMapping('Contacts').applyToClass(Contact);

// This function will be automatically called whenever connection successfully established.
var onOpenSession = function(err, session) {
    
	if (err) {
		console.log('Error while opening session');
        console.log(err);
        process.exit(0);
    } else {
		console.log('Connection established successfully');
		
		// Store contact information
		var contact = new Contact(123, 'Jaydip', 'Lakhatariya', 'jaydip.lakh@gmail.com', '9111111111', 'Knowarth Tech');
        session.persist(contact, onInsert, contact, session);
    }
};

// This function will be automatically called whenever a new record has been inserted
var onInsert = function(err, object, session) {
    
    if (err) {
		console.log("Error occurred while inserting new contact")
        console.log(err);
    } else {
        console.log('Contact Inserted Successfully: ' + JSON.stringify(object));

        // Find the contact from the database
        session.find(Contact, 123, onFindContact);
    }
};

var onFindContact = function(err, contact) {
    
    if (err) {
		console.log("Error while fetching contact")
        console.log(err);
    } else {
        console.log('Contact information is: ' + JSON.stringify(contact));
		
		// Delete the respective contact
		session.remove(contact, onDeleteContact, contact.contactId);
    }
};

// Call whenever deletion happens on record
var onDeleteContact = function(err, object) {
	
	if (err) {
		console.log("Error while deleting contact");
		console.log(err);
	} else {
		console.log('Successfully deleted contact: ' + JSON.stringify(object));
	}
	process.exit(0);
};

// Initialize the database properties
var dbProperties = nosql.ConnectionProperties('ndb');

// Connect to the database
nosql.openSession(dbProperties, Contact, onOpenSession);