import com.mysql.clusterj.ClusterJHelper;
import com.mysql.clusterj.SessionFactory;
import com.mysql.clusterj.Session;
import com.mysql.clusterj.Query;
import com.mysql.clusterj.query.QueryBuilder;
import com.mysql.clusterj.query.QueryDomainType;
import java.io.File;
import java.io.InputStream;
import java.io.FileInputStream;
import java.io.*;
import java.util.Properties;
import java.util.List;

public class ClusterJ {

	private static Session session;
	
	public static void main (String[] args) {
		
		// Load the properties from the clusterj.properties file
		File propsFile = null;
		InputStream inStream = null;
		Properties props = null;
		props.load(inStream);
		try {
			propsFile = new File("clusterj.properties");
			inStream = new FileInputStream(propsFile);
			props = new Properties();
			props.load(inStream);
		} catch(Exception e) {
			System.err.println(e);
			return;
		}		
		
		// Connect to database and create session
		SessionFactory factory = ClusterJHelper.getSessionFactory(props);
		session = factory.getSession();
		if(session != null) {
			System.out.println("Connection Established Successfully");
		}
		saveContact(123, "Jaydip", "Lakhatariya", "jaydip.lakh@gmail.com", "9724371151", "Knowarth");
		findByContactId(123);
		deleteContactById(123);
	}
}

/* Save Contact Details */
private static void saveContact(int contactId, String firstName, String lastName, String emailAddress, String mobileNumber, String companyName) {
	
	// Create and initialise Contact information
	Contact newContact = session.newInstance(Contact.class);
	newContact.setId(contactId);
	newContact.setFirstName(firstName);
	newContact.setLastName(lastName);
	newContact.setEmailAddress(emailAddress);
	newContact.setMobileNumber(mobileNumber);
	newContact.setCompanyName(companyName);
	
	// Store contact information to the database
	session.persist(newContact);
	System.out.println("Contact information has been saved successfully");
}

/* Fetch the contact detail by id */
private static void findByContactId(int contactId) {
	
	Contact contact = session.find(Contact.class, contactId);
	if(contact != null) {
		System.out.println("Contact found with name: " + contact.getFirstName + " " + contact.getLastName());
	} else {
		System.out.println("No contact found with the ID " + contactId);
	}
}

/* Delete contact by id */
private static void deleteContactById(int contactId) {
	session.deletePersistent(Contact.class, contactId);
	System.out.prinln("Deleted contact detail of id: " + contactId);
}