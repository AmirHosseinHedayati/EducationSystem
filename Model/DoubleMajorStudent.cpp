#include "DoubleMajorStudent.h"


DoubleMajorStudent::DoubleMajorStudent(const std::string& studentId, std::string first, std::string last , double workHours,
                   std::vector<std::string> passedCourses, std::map<std::string, double> currentSemesterCourses , std::string mj2)
                   :Student(studentId,first,last,workHours,passedCourses,currentSemesterCourses) , major2 {mj2}
{}

double DoubleMajorStudent::calculateSalary() const{
    return 6500 * getWorkHours();
}

