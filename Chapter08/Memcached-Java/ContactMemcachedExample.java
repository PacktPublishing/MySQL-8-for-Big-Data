

public class ContactMemcachedExample {
	
	public static void main(String[] args) {
		
		ContactMemcachedClient contactMemcachedClient = new ContactMemcachedClient();
		
		// Store contact details
		String valueTobeStored = "jaydip,lakhatariya,jaydip@knowarth.com,9111111111,knowarth";
		contactMemcachedClient.set(ContactMemcachedClient.NAMESPACE + "101",valueTobeStored);
		
		// Fetch contact detail
		contactMemcachedClient.get(ContactMemcachedClient.NAMESPACE + "101");
		
		// Delete contact detail
		contactMemcachedClient.delete(ContactMemcachedClient.NAMESPACE + "101");
	}
}