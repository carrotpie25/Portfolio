# Airline Booking Database Management System (MySQL & Oracle APEX)
## Introduction
Airline booking system is the database management system for an airline company. It allows the company to keep track of passenger’s and staff’s details, ticket prices, flight schedules,  transactions, etc. With so much data and details, airline booking management system helps company to manage and keep track of the data through automation by database. An airline database system allows customers to retrieve information from database and update it automatically without the hassle and manual labor. Without a centralized database, airlines would struggle to manage bookings efficiently, leading to delays, overbooking, and bad customer experience.

## Business Assumptions
1.	A passenger must have a contact detail. Each contact detail must belong only to one passenger.
2.	A passenger can make one or more transaction. But each transaction must belong to only one passenger. 
3.	A transaction may or may not have a fine. Each fine must be associated with a transaction. 
4.	A transaction may or may not have a sale. Each sale must be associated with a transaction. 
5.	A transaction must have a schedule. A schedule may or may not have a transaction (if nobody books the flight). 
6.	A transaction must have flight staff. A flight staff may or may not be associated with a transaction (for example if they are on leave/ break).
7.	Each flight staff must be associated with a branch where they belong to. Each branch may have one to many flight staffs. 
8.	A city may have many office branches or none. Each office branches must be located in a particular city.
9.	Each country must have one or many cities. Each city must be located in a particular country.
10.	Each flight must have a ticket price and each ticket price must refer to a flight. Each flight can have many ticket prices, but each ticket prices must only be associated with a particular flight.
11.	Each schedule must have a ticket price. Each ticket price can be associated with one or more schedules. 
12.	An airplane can have many schedules, or none. But each schedule must be associated with an airplane.
13.	A passenger’s contact detail must include a city. A city can be present in many passenger’s contact detail

## Entity Relationship Diagram 

## Files
* [DDL.sql](DDL.sql) - Creating table statements
* [QueryScirpt](QueryScript.sql) - Query statements
* [data.sql](data.sql) - Insert data statements
