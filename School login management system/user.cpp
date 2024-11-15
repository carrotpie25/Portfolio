#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <cstdlib>
#include "user.h"

using namespace std;

users::users() {
	isLoggedIn = false; // Initialize login status as false
}

bool users::login() {
	string userid, userpassword;
	system("cls");

	cout << "School Management System" << endl;
	cout << "Please Login to your account" << endl;
	cout << "User ID: ";
	cin >> userid;
	cout << "Password: ";
	cin >> userpassword;

	fstream file("user.txt");
	bool userFound = false;

	while (file >> use_id >> use_name >> use_password >> use_category >> use_phone >> use_address)
	{
		if (userid == use_id && userpassword == use_password) {
			userFound = true;
			isLoggedIn = true;
			cout << "Login successful!" << endl;
			break;
		}
	}
	file.close();

	if (!userFound) {
		cout << "Login failed. Invalid credentials!" << endl;
		return false; 
	}
	return true; 
}

void users::studentMenu() {
	int choice;
	string newPhone = ""; // Initialize with an empty string
	string newAddress = ""; // Initialize with an empty string

	while (true) {
		system("cls");
		cout << "Student Menu" << endl;
		cout << "1. Update Personal Information" << endl;
		cout << "2. View available modules" << endl;
		cout << "3. Exit" << endl;
		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice) {
		case 1:
			cout << "Update phone number: ";
			cin >> newPhone;
			cout << "Update address: ";
			cin.ignore();
			getline(cin, newAddress);
			studentModify(newPhone, newAddress);
			cout << "Information updated successfully!" << endl;
			break;
		case 2:
			// Implement viewing available modules
			break;
		case 3:
			exit(0);
		default:
			cout << "Invalid choice. Please try again." << endl;
		}
	}
}

void users::studentModify(const string& newPhone, const string& newAddress) {
	// Open user.txt for reading and writing
	fstream file("user.txt", ios::in | ios::out);
	if (!file.is_open()) {
		cout << "Error: Unable to open user.txt for updating." << endl;
		return;
	}

	string tempFileName = "temp_user.txt";
	ofstream tempFile(tempFileName);

	if (!tempFile.is_open()) {
		cout << "Error: Unable to create a temporary file for updating." << endl;
		file.close();
		return;
	}

	string userId = "specific_id"; // Change this to the ID you want to update

	string use_id, use_name, use_password, use_category, use_phone, use_address;

	bool found = false;
	while (file >> use_id >> use_name >> use_password >> use_category >> use_phone >> use_address) {
		if (use_id == userId) {
			// Update the phone number and address
			use_phone = newPhone;
			use_address = newAddress;
			found = true;
		}

		tempFile << use_id << " " << use_name << " " << use_password << " " << use_category << " " << use_phone << " " << use_address << "\n";
	}

	// Close the original user.txt and temporary file
	file.close();
	tempFile.close();

	if (!found) {
		cout << "Error: User with ID " << userId << " not found." << endl;
		return;
	}

	// Replace the original file with the temporary file
	if (remove("user.txt") != 0) {
		cout << "Error: Unable to delete original user.txt." << endl;
		return;
	}

	if (rename(tempFileName.c_str(), "user.txt") != 0) {
		cout << "Error: Unable to update user.txt." << endl;
	}
	else {
		cout << "Information updated successfully!" << endl;
	}
}




void users::teacherMenu() {
	// Implement options for teachers (e.g., modify personal info, etc
	cout << "Teacher Menu" << endl;
usermainmenu:
	int choice;
	char x;
	// Clear console screen
	system("cls");

	cout << "Student Menu" << endl;
	cout << "1. Update Personal Information" << endl;
	cout << "2. View modules" << endl;
	cout << "3. Add student grades" << endl;
	cout << "4. Exit" << endl;

	cout << "Enter your choice: " << endl;
	cin >> choice;

	switch (choice)
	{
	case 1:
		break;
	case 2:
		break;
	case 3:
		break;
	case 4:
		exit(0);
		break;
	default:
		cout << "Invalid choice. Please try again. ";
		break;
	}
}

void users::staffMenu()
{
	usermainmenu:
	int choice;
	char x;
	// Clear console screen
	system("cls");

	 while (true) {
		 system("cls");

		 cout << "Staff Menu" << endl;
		 cout << "1. User Management" << endl;
		 cout << "2. Module Management" << endl; // Add a new option for modules
		 cout << "3. Exit" << endl;

		 cout << "Enter your choice: ";
		 cin >> choice;

		 switch (choice) {
		 case 1:
			//User Managemet menu
			 while (true) {
				 system("cls");
				 cout << "Staff Menu" << endl;
				 cout << "1. Add User Information" << endl;
				 cout << "2. Modify User" << endl;
				 cout << "3. Delete User" << endl;
				 cout << "4. Back to previous page" << endl;
				 cout << "5. Exit" << endl;

				 cout << "Enter your choice: " << endl;
				 cin >> choice;

				 switch (choice)
				 {
				 case 1:
					 do
					 {	//To add user information
						 staffInsert();
						 cout << "Add another user information (Y,N): ";
						 cin >> x;
					 } while (x == 'y' || x == 'Y');
					 break;
				 case 2:
					 staffModify();
					 break;
				 case 3:
					 staffErase();
					 break;
				 case 4:
					 return;
				 case 5:
					 exit(0);
					 break;
				 default:
					 cout << "Invalid choice. Please try again. ";
					 break;
				 }

				 cout << "\n Press Enter to return to the menu... ";
				 cin.get();  // Wait for the user to press Enter 
				 cin.ignore(); // Discard any leftover newline character

				 goto usermainmenu;
			 }

			 }

		 }
	 }

void users::staffInsert() // Add user information
{
	system("cls");
	fstream file;
	cout << "Add User Information" << endl;
	cout << "Enter ID: ";
	cin >> use_id;
	cout << "Enter Name: ";
	cin >> use_name;
	cout << "Enter Password: ";
	cin >> use_password;
	cout << "Enter Category: ";
	cin >> use_category;
	cout << "Enter Phone Number: ";
	cin >> use_phone;
	cout << "Enter Address: ";
	cin >> use_address;
	file.open("user.txt", ios::app | ios::out);
	file << " " << use_id << " " << use_name << " " << use_password << " " << use_category
		<< " " << use_phone << " " << use_address;
	file.close();
}

void users::staffModify()
{
	system("cls");

	// File streams for reading and writing user data
	fstream file, file1;

	// Store user's input for user's ID to be modified
	string userid;
	int found = 0;

	cout << "Modify User Information " << endl;

	file.open("user.txt", ios::in);

	if (!file.is_open()) // Check if the file is open
	{
		cout << "Data Not Found";
		return; 
	}

	cout << "Enter the student's ID you wish to modify: ";
	cin >> userid;

	file1.open("user2.txt", ios::out); // Open for writing

	bool userFound = false; // To track if the user is found
	// Loop to modify user data
	while (file >> use_id >> use_name >> use_password >> use_category >> use_phone >> use_address)
	{
		if (userid != use_id)
		{
			// Copy existing data to user2.txt if the IDs do not match
			file1 << " " << use_id << " " << use_name << " " << use_password << " " << use_category
				<< " " << use_phone << " " << use_address << endl; // Ensure a newline
		}
		else
		{
			userFound = true;
			// Add data
			cout << "Modify ID: ";
			cin >> use_id;
			cout << "Modify Name: ";
			cin >> use_name;
			cout << "Modify Password: ";
			cin >> use_password;
			cout << "Modify Category: ";
			cin >> use_category;
			cout << "Modify Phone Number: ";
			cin >> use_phone;
			cout << "Modify Address: ";
			cin >> use_address;

			// Write the modified data to user2.txt and increment the found variable
			file1 << " " << use_id << " " << use_name << " " << use_password << " " << use_category
				<< " " << use_phone << " " << use_address << endl; // Ensure a newline
			found++;
		}
	}

	// If student not found
	if (!userFound)
	{
		cout << "Student ID Not Found" << endl;
	}

	file1.close();
	file.close();

	// Replace "user.txt" with the modified data in "user2.txt"
	remove("user.txt");
	if (rename("user2.txt", "user.txt") == 0) {
		cout << " " << endl;
	}
}

void users::staffErase()
{
	system("cls");
	// File streams for reading and writing user data
	fstream file, file1;
	// Store user's input for user's ID to be erased
	string userid;
	int found = 0;
	cout << "Erase User Information " << endl;
	file.open("user.txt", ios::in);

	if (!file)
	{
		cout << "Data Not Found";
		file.close();
	}
	else {
		cout << "\n Please Enter User ID Number to Erase Data: ";
		cin >> userid;
		file1.open("user2.txt", ios::app | ios::out);

		file >> use_id >> use_name >> use_password >> use_category >> use_phone >> use_address;

		// To loop and erase user data
		while (!file.eof())
		{
			if (userid != use_id)
			{// Copy existing file to user2.txt if the IDs do not match
				file1 << " " << use_id << " " << use_name << " " << use_password << " " << use_category
					<< " " << use_phone << " " << use_address;
			}
			else {
				found = 1; //Matchind ID founded
			}

			//Read the next set of user data from 'file'
			file >> use_id >> use_name >> use_password >> use_category >> use_phone >> use_address;
		}
		if (found == 0)
		{
			cout << "Student ID Not Found" << endl;
		} 
		else{
			cout << "User Data Successfully Deleted" << endl;
		}
		file1.close();
		file.close();
		// Replace "user.txt" with the modified data in "user2.txt"
		remove("user.txt");
		if (rename("user2.txt", "user.txt") == 0) {
			cout << " " << endl;
		}
	}
}