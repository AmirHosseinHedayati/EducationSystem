#include "LeafMenu.h"
#include <fstream>
#include <iterator>
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

    else if(name == "ReadMembersFromFile") {

        string command;
        char *cmd = new char[1000];
        ifstream input("members.txt");
        for (size_t i{1}; i <= 6; ++i) {
            input.getline(cmd, 1000);
            command = (string) cmd;
            istringstream iss{command};
            vector<string> results{istream_iterator<string>{iss}, istream_iterator<string>()};

            if(results[0] == "P"){
                Person *person;
                double wh = (double&)results[5];
             person = new Professor (results[1], results[2], results[3], wh  ,results[4]);
              controller.mathClass.push_back(person);
            }
            else if(results[0] == "S"){
                Person *person;
                std::map<std::string, double> csc {0,0};
                std::vector<std::string> pc {0};
                double wh = (double&)results[4];
              person = new Student (results[1] , results[2] , results[3] , wh , pc , csc);
              controller.mathClass.push_back(person);

            }
            else if(results[0] == "D"){
                Person *person;
                std::map<std::string, double> csc {0,0};
                std::vector<std::string> pc {0};
                double wh = (double&)results[4];
              person = new DoubleMajorStudent (results[1] , results[2] , results[3] , wh , pc , csc);
              controller.mathClass.push_back(person);
            }
        }
    }
    else if(name == "Calculate Total Salary"){

    }

    else{
        throw invalid_argument("This Menu hase not been defined!!");
    }
}

