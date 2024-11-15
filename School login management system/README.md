# School Login Data Management System (C++)

This code was run on visual studio 2022. The system covers three categories of personnel: academic staff, module teachers, and students, as well as functions such as student object, teacher object, and staff object. The following is a detailed description of each role's functionality.

**Student's object:**
1. Students can log in to the system through their account and password on the login interface
2. Students can modify their phone and address after selecting personal information
3. Students can see a list of all elective modules on their personal homepage
4. Students can select a module to view final grade of the module

**Teacher's object:**
1. Teachers can log in to the system through their account and password on the login interface;
2. Teachers can modify their phone and address after selecting personal information;
3. Teachers can see a list of all modules taught on their personal homepage;
4. Teachers can select a module, then enter and modify the students’ grades. Once the students’ grades are published, teachers are not allowed to modify the student’s grades for one module.

**Staff's object:**
1. Staff can log in to the system through their account and password on the login interface;
2. Staff can add, modify, and delete the information in user table (user.txt), including adding all personal information about staff, students and teachers;
3. Staff can add, modify, and delete module information (module.txt) in the module table, including module ID, module name, use name, use category, and use grades;
4. Staff can publish or retrieve module grades on the module interface.

## Related Files
**main.cpp:** Contains the logic to initialize the login system and connect all the files together <br>
**module.cpp:** Contains the implementation of module-related functionalities <br>
**user.cpp:** Contains the implementation of user-related functionalities <br>
**module.h:** Contains the functions, classes, and constants for module.cpp <br>
**user.h:** Contains the functions, classes, and constants for user.cpp <br>
**module.txt:** Contains module information database <br>
**user.txt:** Contains user information database <br>
