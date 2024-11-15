#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <cstdlib>
#include "module.h"

using namespace std;

void module::staffmenu()
{
modulemainmenu:
	int choice;
	char x;
	system("cls");
	cout << "Module Management" << endl;
	cout << "1. Add Module Information" << endl;
	cout << "2. Modify Module" << endl;
	cout << "3. Delete Module" << endl;
	cout << "4. Manage Grades" << endl;
	cout << "5. Back to previous page" << endl;
	cout << "6. Exit" << endl;

	cout << "Enter your choice: " << endl;
	cin >> choice;

	switch (choice)
	{
	case 1:
		do
		{	//To add module information
			staffinsert();
			cout << "Add Another Module Information (Y,N): ";
			cin >> x;
		} while (x == 'y' || x == 'Y');
		break;
	case 2:
		staffmodify();
		break;
	case 3:
		stafferase();
		break;
	case 4:
		//manageGrades();
		break;
	case 5:
		return;
	case 6:
		exit(0);
	default:
		cout << "Invalid choice. Please try again. ";

	}
	cin.get();  // Wait for the user to press Enter 
	cin.ignore(); // Discard any leftover newline character
	goto modulemainmenu;
}

void module::staffinsert()
{
	system("cls");
	fstream file;
	cout << "Add Module Information" << endl;
	cout << "Module ID: ";
	cin >> module_id;
	cout << "Module Name: ";
	cin >> module_name;
	cout << "Teacher ID: ";
	cin >> teacher_id;
	cout << "Student ID: ";
	cin >> student_id;
	file.open("module.txt", ios::app);
	file << " " << module_id << " " << module_name << " " << teacher_id << " " << student_id
		<< " " << use_grades << " " << status;
	file.close();
}

void module::staffmodify()
{
	system("cls");
	fstream file, file1;
	int found = 0;
	string moduleid;

	cout << "Modify Module Information " << endl;
	file.open("module.txt", ios::in);
	if (!file.is_open()) // Check if the file is open
	{
		cout << "Data Not Found";
		file.close();
	}
	else {
		cout << "Enter The Module ID you wish to Modify:  ";
		cin >> moduleid; 
		file1.open("module.txt", ios::in | ios::out);
		file >> module_id >> module_name >> teacher_id >> student_id >> use_grades >> status;
		while (!file.eof())
		{
			if (moduleid != module_id)
			{
				file << " " << module_id << " " << module_name << " " << teacher_id << " " << student_id
					<< " " << use_grades << " " << status << "\n";
			}
			else {
				cout << "Module ID: ";
				cin >> module_id;
				cout << "Module Name: ";
				cin >> module_name;
				cout << "Teacher ID: ";
				cin >> teacher_id;
				cout << "Student ID: ";
				cin >> student_id;
				cin >> status;
				file << " " << module_id << " " << module_name << "  " << teacher_id << " " << student_id
					<< " " << use_grades << " " << status << "\n";
				found++;
			}
		file >> module_id >> module_name >> teacher_id >> student_id >> use_grades >> status;
		if (found == 0)
		{
			cout << "Module ID Not Found";
		}
		}
		file1.close();
		file.close();
		remove("module.txt");
		if (rename("user2.txt", "user.txt") == 0) {
			cout << " " << endl;
		}
	}
}

void module::stafferase()
{
	system("cls");
	fstream file, file1;
	string moduleid;
	int found = 0;
	cout << "Delete Module Infomration" << endl;
	file.open("module.txt", ios::in);
	if (!file.is_open()) // Check if the file is open
	{
		cout << "Data Not Found";
		file.close();
	}
	else {
		cout << "\n Please Enter Module ID to Erase Data: ";
		cin >> moduleid;
		file1.open("module.txt", ios::in | ios::out);
		file >> module_id >> module_name >> teacher_id >> student_id >> use_grades >> status;
		while (!file.eof())
		{
			if (moduleid != module_id)
			{
				file << " " << module_id << " " << module_name << "  " << teacher_id << " " << student_id
					<< " " << use_grades << " " << status << "\n"; 
			}
			file >> module_id >> module_name >> teacher_id >> student_id >> use_grades >> status;
		}
		if (found == 0)
		{
			cout << "Module ID Not Found";
		}
		file1.close();
		file1.close();
		remove("module.txt");
		if (rename("user2.txt", "user.txt") == 0) {
			cout << " " << endl;
		}
	}
}

/**
void module::staffmanageGrades() {
	system("cls");
	cout << "Manage Module Grades" << endl;

	int choice;
	cout << "1. Publish Grades" << endl;
	cout << "2. Retrieve Grades" << endl;
	cout << "3. Previous page" << endl; 
	cout << "Enter your choice: ";
	cin >> choice;

	if (choice == 1) {
		publishGrade();
	}
	else if (choice == 2) {
		retrieveGrade();
	}
	else if (choice == 3) {
		return;
	}
	else {
		cout << "Invalid choice. Please try again." << endl;
	}
}

void module::staffpublishGrade()
{
	system("cls");
	cout << "Publish Module Grades" << std::endl;
	cout << "Enter Module ID: ";
	cin >> module_id;

	// Prompt staff to set the release status
	char x;
	cout << "Set Release Status (Y for Released, N for Not Released): ";
	cin >> x;
	status = (x == 'Y' || x == 'y');

	// Save the updated release status to "module.txt" or your data file
	ofstream file("module.txt", ios::app | ios::out);
	if (file.is_open()) {
		// Append the updated release status to the file
		file << " " << module_id << " " << module_name << " " << teacher_id << " " << student_id
			<< " " << use_grades << " " << /**(status ? "Released" : "Not Released")  "\n";
		file.close();

		cout << "Grades successfully published!" << endl;
		cout << "Press Enter to Return." << endl;
	}
	else {
		cout << "Error: Unable to open the file for writing." << std::endl;
	}
}

void module::retrieveGrade() {
	system("cls");
	cout << "Retrieve Module Grades" << endl;

	// Prompt for the module ID
	cout << "Enter Module ID: ";
	cin >> module_id;

	// Open the file for reading
	ifstream file("module.txt", ios::in);
	if (!file.is_open()) {
		cout << "Data Not Found" << endl;
		return;
	}

	bool moduleFound = false;

	// Read and display module information
	string temp_module_id, temp_module_name, temp_teacher_id, temp_student_id, temp_use_grades, temp_status;

	while (file >> temp_module_id) {
		// Read the module name which may contain spaces
		getline(file, temp_module_name, '\t');
		file >> temp_teacher_id >> temp_student_id >> temp_use_grades >> temp_status;

		if (temp_module_id == module_id) {
			moduleFound = true;
			cout << "Module ID: " << temp_module_id << endl;
			cout << "Module Name: " << temp_module_name << endl;
			cout << "Teacher ID: " << temp_teacher_id << endl;
			cout << "Student ID: " << temp_student_id << endl;
			cout << "Released Status: " << temp_status << endl;

			// Read and display student grades
			if (temp_status == "Released") {
				cout << "Student Grades:" << endl;
				while (file >> temp_student_id) {
					file >> temp_use_grades >> temp_status;
					if (temp_module_id != module_id) {
						break;
					}
					cout << "Student ID: " << temp_student_id << endl;
					cout << "Grade: " << temp_use_grades << endl;
					cout << "Grade Status: " << temp_status << endl;
					cout << "---" << endl;
				}
			}
		}
	}

	file.close();

	if (!moduleFound) {
		cout << "Module ID Not Found" << endl;
	}
}**/
