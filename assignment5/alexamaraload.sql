/*modified 1/2018 by G Brown for 466/566 use */
drop table if exists ServiceRequest;
drop table if exists MarinaSlip;

drop table if exists Owner;
drop table if exists ServiceCategory;
drop table if exists Marina;

CREATE TABLE Marina
(MarinaNum int auto_increment PRIMARY KEY,
Name CHAR(20),
Address CHAR(15),
City CHAR(15),
State CHAR(2),
Zip CHAR(5) );

CREATE TABLE Owner
(OwnerNum int auto_increment PRIMARY KEY,
LastName CHAR(50),
FirstName CHAR(20),
Address CHAR(15),
City CHAR(15),
State CHAR(2),
Zip CHAR(5) );

CREATE TABLE ServiceCategory
(CategoryNum int auto_increment PRIMARY KEY,
CategoryDescription CHAR(255) );

CREATE TABLE MarinaSlip
(SlipID int auto_increment PRIMARY KEY,
MarinaNum int,
SlipNum CHAR(4),
Length DECIMAL(4,0),
RentalFee DECIMAL(8,2),
BoatName CHAR(50),
BoatType CHAR(50),
OwnerNum int,
foreign key (MarinaNum) references Marina(MarinaNum) );

CREATE TABLE ServiceRequest
(ServiceID int auto_increment PRIMARY KEY,
SlipID int,
CategoryNum int,
Description CHAR(255),
Status CHAR(255),
EstHours DECIMAL(4,2),
SpentHours DECIMAL(4,2),
NextServiceDate DATE,
foreign key (SlipID) references MarinaSlip(SlipID),
foreign key (CategoryNum) references ServiceCategory(CategoryNum) );

INSERT INTO Marina (Name,Address,City,State,Zip) VALUES
('Alexamara East','108 2nd Ave','Brinman','FL','32273'),  /*1*/
('Alexamara Central','283 Branston','W Brinman','FL','32274'),  /*2*/
('Alexamara South','2 Branston Court','W Brinman','FL','32274');   /*3*/

INSERT INTO MarinaSlip (MarinaNum, SlipNum,Length,RentalFee,BoatName,BoatType,OwnerNum) VALUES
('1','A1',40,3800.00,'Anderson II','Sprite 4000',1),	/*1*/
('1','A2',40,3800.00,'Our Toy','Ray 4025',2),			 /*2*/
('1','A3',40,3600.00,'Escape','Sprite 4000',3),		 /*3*/
('1','B1',30,2400.00,'Gypsy','Dolphin 28',5),			 /*4*/
('1','B2',30,2600.00,'Anderson III','Sprite 3000',4),	 /*5*/
('2','1',25,1800.00,'Bravo','Dolphin 25',1),			 /*6*/
('2','2',25,1800.00,'Chinook','Dolphin 22',7),			 /*7*/
('2','3',25,2000.00,'Listy','Dolphin 25',10),			 /*8*/
('2','4',30,2500.00,'Mermaid','Dolphin 28',8),			 /*9*/
('2','5',40,4200.00,'Axxon II','Dolphin 40',5),		 /*10*/
('2','6',40,4200.00,'Karvel','Ray 4025',9),			 /*11*/
('3','C1',40,4200.00,'Axxon IV','Dolphin 40',6),		 /*12*/
('3','C2',40,4200.00,'Krispy','Ray 4025',3);			 /*13*/


INSERT INTO Owner (LastName,FirstName,Address,City,State,Zip) VALUES
('Adney','Bruce and Doris','208 Citrus','Bowton','FL','31313'),	 		/*1*/
('Anderson','Bill','18 Wilcox','Glander Bay','FL','31044'),		 		/*2*/	
('Blake','Mary Jane','2672 Commodore','Bowton','FL','31313'),		 		/*3*/
('Elend','Mary and Bill','462 Riverside','Rivard','FL','31062'),	 	/*4*/
('Feenstra','Daniel','7822 Coventry','Kaleva','FL','32521'),		 	/*5*/
('Juarez','Maria','8922 Oak','Rivard','FL','31062'),				 	/*6*/
('Kelly','Alyssa','5271 Waters','Bowton','FL','31313'),				 	/*7*/
('Smith','Peter','2811 Lakewood','Lewiston','FL','32765'),			 	/*8*/
('Smeltz','Becky and Dave','922 Garland','Glander Bay','FL','31044'),	 /*9*/
('Trent','Ashton','922 Crest','Bay Shores','FL','30992'); 				/*10*/

INSERT INTO ServiceCategory (CategoryDescription) VALUES
('Routine engine maintenance'),		/*1*/
('Engine repair'),					/*2*/
('Air conditioning'),				/*3*/
('Electrical systems'),				/*4*/
('Fiberglass repair'),				/*5*/
('Canvas installation'),			/*6*/
('Canvas repair'),					/*7*/
('Electronic systems (radar, GPS, autopilots, etc.)'); /*8*/

INSERT INTO ServiceRequest (SlipId, CategoryNum,Description,Status,EstHours,SpentHours,NextServiceDate) VALUES
(13,7,'Canvas leaks around zippers in heavy rain. Install overlap around zippers to prevent leaks.','Overlap has been created. Installation has been scheduled.','8','3','2013-07-17'),
(1,3,'Air conditioner periodically stops with code indicating low coolant level. Diagnose and repair.','Technician has verified the problem. Air conditioning specialist has been called.','4','2','2013-07-12'),
(5,4,'Fuse on port motor blown on two occasions. Diagnose and repair.','Open','2','0','2013-07-12'),
(4,1,'Oil change and general routine maintenance (check fluid levels, clean sea strainers etc.).','Service call has been scheduled.','1','0','2013-07-16'),
(1,2,'Engine oil level has been dropping drastically. Diagnose and repair.','Open','2','0','2013-07-13'),
(12,3,'Air conditioning unit shuts down with HHH showing on the control panel.','Technician not able to replicate the problem. Air conditioning unit ran fine through multiple tests. Owner to notify technician if the problem recurs.','1','1','2020-12-31'),
(11,4,'Electric-flush system periodically stops functioning. Diagnose and repair.','Open','3','0','2020-12-31'),
(6,2,'Engine overheating. Loss of coolant. Diagnose and repair.','Open','2','0','2013-07-13'),
(6,2,'Heat exchanger not operating correctly.','Technician has determined that the exchanger is faulty. New exchanger has been ordered.','4','1','2013-07-17'),
(7,6,'Canvas severely damaged in windstorm. Order and install new canvas.','Open','8','0','2013-07-16'),
(2,8,'Install new GPS and chart plotter.','Scheduled','7','0','2013-07-17'),
(2,3,'Air conditioning unit shuts down with HHH showing on the control panel.','Technician not able to replicate the problem. Air conditioning unit ran fine through multiple tests. Owner to notify technician if the problem recurs.','1','1','2020-12-31'),
(4,8,'Both speed and depth readings on data unit are significantly less than the owner thinks they should be.','Technician has scheduled appointment with owner to attempt to verify the problem.','2','0','2013-07-16'),
(8,2,'Customer describes engine as making a clattering sound.','Technician suspects problem with either propeller or shaft and has scheduled the boat to be pulled from the water for further investigation.','5','2','2013-07-12'),
(7,5,'Owner accident caused damage to forward portion of port side.','Technician has scheduled repair.','6','0','2013-07-13'),
(11,7,'Canvas leaks around zippers in heavy rain. Install overlap around zippers to prevent leaks.','Overlap has been created. Installation has been scheduled.','8','3','2013-07-17');


