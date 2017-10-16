CREATE DATABASE IF NOT EXISTS hadoop_bigdata;
CREATE TABLE 
 `hadoop_bigdata`.`users` ( 
`user_id` INT NOT NULL AUTO_INCREMENT , 
`email` VARCHAR(200) NOT NULL , 
`date_of_joining` DATE NOT NULL , 
`date_of_birth` DATE NOT NULL , 
`first_name` VARCHAR(200) NOT NULL , 
PRIMARY KEY (`user_id`)
) ENGINE = InnoDB;