#include "DoubleMajorStudent.h"
#include <stdexcept>

Student::Student(const std::string& studentId, std::string first, std::string last , double workHours,
                 std::vector<std::string> passedCourses, std::map<std::string, double> currentSemesterCourses)
        : Person((std::move(first)), (std::move(last)), workHours ),
          passedCourses{std::move (passedCourses)}, currentSemesterCourses{std::move(currentSemesterCourses)}
{
    if( !validate( studentId, "\\d{9}") ) {
        throw std::invalid_argument("Student ID must have 9 digits!!");
    }
    this->studentId = studentId;
}
double Student::calculateSalary() const{
    return 6500 * getWorkHours();
}