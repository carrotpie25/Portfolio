#ifndef USER_H
#define USER_H

#include <fstream>
#include <string>

using namespace std; 

class users
{
private:
	string use_id, use_name, use_password, use_phone, use_address;
	bool isLoggedIn;
public:
	string use_category;

	users();
	bool login();
	void studentMenu();
	void studentModify(const string& newPhone, const string& newAddress);
	void teacherMenu();
	void staffMenu();
	void staffInsert();
	void staffModify();
	void staffErase();
};

#endif 