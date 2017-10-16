#include <NdbApi.hpp>
#include <stdio.h>
#include <iostream>

static void run_application(Ndb_cluster_connection &);

#define PRINT_ERROR(code,msg)
  std::cout << "Error occurred: " << code << ", Message: " << message << std::endl

#define APIERROR(error) {
  PRINT_ERROR(error.code,error.message);
  exit(-1); 
}

int main(int argc, char** argv)
{
	// Initialize ndb
	ndb_init();

  // Connect MySQL Cluster
  {
    const char *connection_string = "localhost:1186";
    Ndb_cluster_connection cluster_connection(connection_string);

    // Connect to cluster management server (ndb_mgmd)
    if (cluster_connection.connect(4, 5, 1))
    {
      std::cout << "A management server is not ready yet.\n";
      exit(-1);
    }

    // Connects to the storage nodes (ndbd's) 
    if (cluster_connection.wait_until_ready(30,0) < 0)
    {
      std::cout << "Data nodes are not ready yet.\n";
      exit(-1);
    }

    // Run the application code
    run_application(cluster_connection);
  }

  ndb_end(0);

  return 0;
}

static void create_table(MYSQL &);
static void do_insert(Ndb &);
static void do_update(Ndb &);
static void do_delete(Ndb &);
static void do_read(Ndb &);

static void run_application(Ndb_cluster_connection &cluster_connection)
{
	// Connect to database via NDB API
	Ndb myNdb( &cluster_connection, "demodb" );
	if (myNdb.init()) APIERROR(myNdb.getNdbError());

	//Do different operations on database
	do_insert(myNdb);
	do_update(myNdb);
	do_delete(myNdb);
	do_read(myNdb);
}

static void do_insert(Ndb &myNdb)
{
	const NdbDictionary::Dictionary* myDict= myNdb.getDictionary();
	const NdbDictionary::Table *myTable= myDict->getTable("Contacts");
	if (myTable == NULL) APIERROR(myDict->getNdbError());

	NdbTransaction *myTransaction= myNdb.startTransaction();
	if (myTransaction == NULL) APIERROR(myNdb.getNdbError());
  
	NdbOperation *myOperation= myTransaction->getNdbOperation(myTable);
	if (myOperation == NULL) APIERROR(myTransaction->getNdbError());
  
	myOperation->insertTuple();
    myOperation->equal("id", 123);
    myOperation->setValue("firstName", "Jaydip");
	myOperation->setValue("lastName", "Lakhatariya");
	myOperation->setValue("emailAddress", "jaydip.lakh@gmail.com");
	myOperation->setValue("mobileNumber", "9724371151");
	myOperation->setValue("companyName", "Knowarth");

	if (myTransaction->execute( NdbTransaction::Commit ) == -1)
		APIERROR(myTransaction->getNdbError());
  
	myNdb.closeTransaction(myTransaction);
}

static void do_update(Ndb &myNdb)
{
	const NdbDictionary::Dictionary* myDict= myNdb.getDictionary();
	const NdbDictionary::Table *myTable= myDict->getTable("Contacts");
	if (myTable == NULL) APIERROR(myDict->getNdbError());

    NdbTransaction *myTransaction= myNdb.startTransaction();
    if (myTransaction == NULL) APIERROR(myNdb.getNdbError());

    NdbOperation *myOperation= myTransaction->getNdbOperation(myTable);
    if (myOperation == NULL) APIERROR(myTransaction->getNdbError());

    myOperation->updateTuple();
    myOperation->equal( "id", 123);
    myOperation->setValue("firstName", "Keyur");
	myOperation->setValue("lastName", "Lakhatariya");
	myOperation->setValue("emailAddress", "Keyur.lakh@gmail.com");
	myOperation->setValue("mobileNumber", "9998887771");
	myOperation->setValue("companyName", "Knowarth");

    if( myTransaction->execute( NdbTransaction::Commit ) == -1 )
		APIERROR(myTransaction->getNdbError());

    myNdb.closeTransaction(myTransaction);
}

static void do_delete(Ndb &myNdb)
{
  const NdbDictionary::Dictionary* myDict= myNdb.getDictionary();
  const NdbDictionary::Table *myTable= myDict->getTable("Contacts");

  if (myTable == NULL)
    APIERROR(myDict->getNdbError());

  NdbTransaction *myTransaction= myNdb.startTransaction();
  if (myTransaction == NULL) APIERROR(myNdb.getNdbError());

  NdbOperation *myOperation= myTransaction->getNdbOperation(myTable);
  if (myOperation == NULL) APIERROR(myTransaction->getNdbError());

  myOperation->deleteTuple();
  myOperation->equal( "id", 123);

  if (myTransaction->execute(NdbTransaction::Commit) == -1)
    APIERROR(myTransaction->getNdbError());

  myNdb.closeTransaction(myTransaction);
}

static void do_read(Ndb &myNdb)
{
	const NdbDictionary::Dictionary* myDict= myNdb.getDictionary();
	const NdbDictionary::Table *myTable= myDict->getTable("Contacts");

	if (myTable == NULL)
		APIERROR(myDict->getNdbError());

    NdbTransaction *myTransaction= myNdb.startTransaction();
    if (myTransaction == NULL) APIERROR(myNdb.getNdbError());

    NdbOperation *myOperation= myTransaction->getNdbOperation(myTable);
    if (myOperation == NULL) APIERROR(myTransaction->getNdbError());

    myOperation->readTuple(NdbOperation::LM_Read);
    myOperation->equal("id", 123);

    NdbRecAttr *emailRecAttr= myOperation->getValue("emailAddress", NULL);
	NdbRecAttr *mobileRecAttr= myOperation->getValue("mobileNumber", NULL);
	
    if (emailRecAttr == NULL) APIERROR(myTransaction->getNdbError());
	if (mobileRecAttr == NULL) APIERROR(myTransaction->getNdbError());

    if(myTransaction->execute( NdbTransaction::Commit ) == -1)
      APIERROR(myTransaction->getNdbError());

	printf("FirstName is: \n", emailRecAttr->aRef());
	printf("Mobile Number is: \n", mobileRecAttr->aRef());
	
	myNdb.closeTransaction(myTransaction);
}