import com.whalin.MemCached.MemCachedClient;
import com.whalin.MemCached.SockIOPool;
import java.util.Map;


public class ContactMemcachedClient {
	
		private static String[] servers = {"localhost:11211"};
		private static Integer[] weights = { 1 };
		private MemCachedClient memcachedClient;
		public static final String NAMESPACE = "@@contacts_table";
 
		/**
		* Initialize connection
		*/
		public ContactMemcachedClient() {
		 
			SockIOPool pool = SockIOPool.getInstance();
			pool.setServers(servers);
			pool.setWeights( weights );
			if (!pool.isInitialized()) {
				pool.setInitConn(5);
				pool.setMinConn(5);
				pool.setMaxConn(250);
				pool.initialize();
			}
			MemCachedClient memCachedClient = new MemCachedClient();
			this.memcachedClient = memCachedClient;
		}
 
		 /**
		 * Add/Update value of specified key
		 * @param key
		 * @param value
		 */
		 public void set(String key, Object value) {
			memcachedClient.set(key, value);
		 }
 
		 /**
		 * Fetch value by key
		 * @param key
		 * @return
		 */
		public Object get(String key) {
			return memcachedClient.get(key);
		}
		
		/**
		* Delete value by key
		* @param key
		* @return
		*/
		public Object delete(String key) {
			return memcachedClient.delete(key);
		}
 
		 /**
		 * Fetch values as map from the multiple keys
		 * @param keys
		 * @return
		 */
		 public Map<String, Object> getAllByKey(String[] keys) {
			return memcachedClient.getMulti(keys);
		 }
		 
		 /**
		 * Check weather value exists against key or not
		 * @param key
		 * @return
		 */
		public boolean isKeyExists(String key) {
			return memcachedClient.keyExists(key);
		}
}
