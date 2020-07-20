#ifndef TA_19_CONTROLLER_H
#define TA_19_CONTROLLER_H

#include <string>
#include <vector>
#include "../Model/Student.h"
#include "../Model/Professor.h"
#include "../Model/Course.h"

class Controller {
    friend class Menu;
    friend class CommandsFromFileMenu;
    friend class LeafMenu;
private:
    std::string currentSemester;
    std::vector<Student> students;
    std::vector<Professor> professors;
    std::vector<Course> courses;
    std::vector<Course> currentSemesterCourses;
    std::vector<Person*> mathClass;
    Controller() = default;

public:
    explicit Controller(std::string currentSemester);
    void load();
    void save() const;

    void addStudent(std::string ID, std::string first, std::string last);
    void addProfessor(std::string ID, std::string first, std::string last, std::string title);
    void addCourse(std::string courseName, std::string profLast, std::string semester,
            std::vector<std::string> pre);
    void takeCourse(const std::string& studentID, const std::string& courseName);
    Student& findStudent(std::string ID);
    void dropCourse(const std::string& studentID, const std::string& courseName);
    void showCurrentSemesterCourses();
    void showStudentCurrentSemesterCourses(const std::string& studentID);


    bool inStudents(const std::string& ID) const;
    bool inPassedCourse( const std::string& ID , std::string courseName) ;
    bool inCurrentSemesterCourse( const std::string& ID , std::string courseName) ;
    bool inProfessors(const std::string& ID) const;
    bool inProfessorsByLastName(const std::string& last) const;
    bool inCourses(const std::string& courseName) const;
    bool ispassedPreCourses(std::vector<std::string> v1, std::vector<std::string> v2);
};


#endif //TA_19_CONTROLLER_H
