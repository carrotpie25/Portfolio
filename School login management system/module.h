#ifndef MODULE_H
#define MODULE_H

#include <fstream>
#include <string>
#include <vector>

using namespace std;

class module
{
private:
	string module_id, module_name, teacher_id, student_id, use_grades, status;
	//bool status = false;

public:
	void staffmenu();
	void staffinsert();
	void staffmodify();
	void stafferase();
	/**void manageGrades();
	void staffpublishGrade();
	void staffretrieveGrade();**/
};

#endif 