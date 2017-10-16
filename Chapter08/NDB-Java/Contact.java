import com.mysql.clusterj.annotation.Column;
import com.mysql.clusterj.annotation.PersistenceCapable;
import com.mysql.clusterj.annotation.PrimaryKey;

@PersistenceCapable(table="Contacts")
public interface Contact {
	
	@PrimaryKey
	public int getId();
    public void setId(int id);

	@Column(name="firstName")  
    public String getFirstName();
    public String setFirstName(String firstName);
    
	@Column(name="lastName")  
    public String getLastName();
    public String setLastName(String lastName);
    
	@Column(name="emailAddress")  
    public String getEmailAddress();
    public String setEmailAddress(String emailAddress);
    
	@Column(name="mobileNumber")  
    public String getMobileNumber();
    public String setMobileNumber(String mobileNumber);
    
	@Column(name="companyName")
    public String getCompanyName();
    public String setCompanyName(String companyName);
}