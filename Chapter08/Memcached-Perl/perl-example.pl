#!/usr/bin/perl
use Cache::Memcached;
use Data::Dumper;

# Configure the memcached server
my $memcache = new Cache::Memcached {
    'servers' => [ 'localhost:11211']
};

my $contactId=$ARGV[0];
my $firstName=$ARGV[1];
my $lastName=$ARGV[2];
my $emailAddress=$ARGV[3];
my $mobileNumber=$ARGV[4];
my $companyName=$ARGV[5];

#Store contact Information
$contactData = $firstName . ",". $lastName . "," . $emailAddress . "," . $mobileNumber . "," . $companyName;
$memcache->set($contactId,$contactData))

#Fetch contact information to check if it stored or not
my $contact = $cache->get($contactId);
if (defined($contact)) 
{
	print "$contact\n";
}
else
{
	print STDERR "Contact Information does not stored";
}