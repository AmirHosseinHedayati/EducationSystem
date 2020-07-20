#include "LeafMenu.h"

using namespace std;

LeafMenu::LeafMenu(std::string name, Menu* parent)
    : Menu{move(name), parent} {}

void LeafMenu:: showSubMenus() const {}

void LeafMenu::run() {
    setCurrentMenu(parent);

    if(name == "Show This Semester Courses"){
        controller.showCurrentSemesterCourses();
    }

    else if(name == "Take Course"){
        string ID;
        cout<<"Enter Your Student ID: "<<endl;
        cin>>ID;
        string cn;
        cout<<"Enter your courseName: "<<endl;
        cin>>cn;
        controller.takeCourse(ID,cn);
    }

    else if(name == "Drop Course"){
        string ID;
        cout<<"Enter Your Student ID: "<<endl;
        cin>>ID;
        string cn;
        cout<<"Enter your courseName: "<<endl;
        cin>>cn;
        controller.dropCourse(ID,cn);
    }

    else if(name == "Show Student Courses In Current Semester"){
     string ID;
     cout<<"Enter Your Student ID: ";
     cin>>ID;
        controller.showStudentCurrentSemesterCourses(ID);
    }

    else if(name == "Calculate Student Salary"){
     double wh;
     cout<<"Enter the work hours: ";
     cin>>wh;
     Student st;
     st.setWorkHours(wh);
     cout<<"Total Salary: "<<st.calculateSalary()<<"\n\n";
    }

    else if(name == "Show Professor Courses In Current Semester"){

    }

    else if(name == "Submit Grade"){

    }

    else if(name == "Calculate Professor Salary"){

    }

    else if(name == "Add Professor"){

    }

    else if(name == "Show Professors"){

    }

    else if(name == "Add Student"){
        string ID;
        cout << "Enter student number: ";
        cin >> ID;
        string first;
        cout << "Enter First Name: ";
        cin >> first;
        string last;
        cout << "Enter Last Name: ";
        cin >> last;
        controller.addStudent(ID, first, last);
    }

    else if(name == "Show Students"){

    }

    else if(name == "Add Course"){

    }

    else if(name == "Show All Courses"){

    }

    else{
        throw invalid_argument("This Menu hase not been defined!!");
    }
}
