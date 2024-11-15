#include <iostream>
#include <fstream>
#include "user.h"
#include "module.h" 

using namespace std;

int main() {
    users userProject;
    module moduleProject; 

    bool loggedIn = false;

    while (!loggedIn) {
        loggedIn = userProject.login(); // Will be directed to the login function 

        if (!loggedIn) {
            cout << "Login failed. Please try again" << endl;
        }
    }

    // Determine the user's role and display the corresponding menu
    if (userProject.use_category == "student") {
        userProject.studentMenu();
    }
    else if (userProject.use_category == "teacher") {
        userProject.teacherMenu();
    }
    else if (userProject.use_category == "staff") {
        userProject.staffMenu();
    }
    else {
        cout << "Invalid user role. Exiting." << endl;
        return 1; // Exit with an error code
    }

    return 0;
}
