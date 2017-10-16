# MySQL 8 for Big Data
This is the code repository for [MySQL 8 for Big Data](https://www.packtpub.com/big-data-and-business-intelligence/mysql-8-big-data?utm_source=github&utm_medium=repository&utm_campaign=9781788397186), published by [Packt](https://www.packtpub.com/?utm_source=github). It contains all the supporting project files necessary to work through the book from start to finish.
## About the Book
MySQL is one of the most popular relational databases in the world today, and has become a popular choice of tool to handle vast amounts of structured data - that is, structured Big Data. This book will demonstrate how you can dabble with large amounts of data using MySQL 8. It also highlights topics such as integrating MySQL 8 and a Big Data solution like Apache Hadoop using different tools like Apache Sqoop and MySQL Applier. With practical examples and use-cases, you will get a better clarity on how you can leverage the offerings of MySQL 8 to build a robust Big Data solution.
## Instructions and Navigation
All of the code is organized into folders. Each folder starts with a number followed by the application name. For example, Chapter02.



The code will look like the following:
```
CREATE TABLE access_log ( 
log_id INT NOT NULL, 
type VARCHAR(100), 
access_url VARCHAR(100), 
access_date TIMESTAMP NOT NULL, 
response_time INT NOT NULL,
access_by INT NOT NULL
)
PARTITION BY RANGE (UNIX_TIMESTAMP(access_date)) ( 
PARTITION p0 VALUES LESS THAN (UNIX_TIMESTAMP('2017-05-01 00:00:00')), 
PARTITION p1 VALUES LESS THAN (UNIX_TIMESTAMP('2017-09-01 00:00:00')), 
PARTITION p2 VALUES LESS THAN (UNIX_TIMESTAMP('2018-01-01 00:00:00')), 
PARTITION p3 VALUES LESS THAN (UNIX_TIMESTAMP('2018-05-01 00:00:00')), 
PARTITION p4 VALUES LESS THAN (UNIX_TIMESTAMP('2018-09-01 00:00:00')), 
PARTITION p5 VALUES LESS THAN (UNIX_TIMESTAMP('2019-01-01 00:00:00')), 
);
```

This book will guide you through the installation of all the tools that you need to follow the examples. You will need to install the following software to effectively run the code samples present in this book:

MySQL 8.0.3
Hadoop 2.8.1
Apache Sqoop 1.4.6

## Related Products
* [MySQL 8 Cookbook](https://www.packtpub.com/big-data-and-business-intelligence/mysql-8-cookbook?utm_source=github&utm_medium=repository&utm_campaign=9781788395809)

* [MySQL for Python](https://www.packtpub.com/big-data-and-business-intelligence/mysql-python?utm_source=github&utm_medium=repository&utm_campaign=9781849510189)

* [Mastering phpMyAdmin for Effective MySQL Management ](https://www.packtpub.com/big-data-and-business-intelligence/mastering-phpmyadmin-effective-mysql-management?utm_source=github&utm_medium=repository&utm_campaign=9781904811039)

### Suggestions and Feedback
[Click here](https://docs.google.com/forms/d/e/1FAIpQLSe5qwunkGf6PUvzPirPDtuy1Du5Rlzew23UBp2S-P3wB-GcwQ/viewform) if you have any feedback or suggestions.
