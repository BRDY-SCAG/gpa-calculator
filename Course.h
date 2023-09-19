#ifndef COURSE_H
#define COURSE_H
#include <vector>
#include <string>

#include <string>

class Course 
{
    public:
        Course(std::string term, std::string coursePrefix, std::string courseNumber, float credits ,std::string grade);
        double getGradeVal() const;
        double getCourseCredits();
        bool CSDept();
        bool isIP();

    private:
        std::string term;
        std::string coursePrefix;
        std::string courseNumber;
        double credits; 
        std::string grade;

};
#endif



