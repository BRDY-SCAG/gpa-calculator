/*
* Implementing Course Definitons; 
*/
#include <string>
#include <map>
#include "Course.h"

Course::Course( std::string term,std::string coursePrefix,std::string courseNumber,float credits,std::string grade)
{
    this->term = term;
    this->coursePrefix = coursePrefix;
    this->courseNumber = courseNumber;
    this->credits = credits;
    this->grade = grade;    
}
bool Course::isIP()
{   
    if(grade == "IP")
    {
        return true;
    }
    else{
        return false;
    }
}
// define a map for the course Grade
const std::map<std::string, double> GRADE_POINT_MAP = {
    {"A+", 4.0},
    {"A", 4.0},
    {"A-", 3.7},
    {"B+", 3.3},
    {"B", 3.0},
    {"B-", 2.7},
    {"C+", 2.3},
    {"C", 2.0},
    {"C-", 2.0},
    {"D+", 1.0},
    {"D", 1.0},
    {"D-", 1.0},
    {"F", 0.0},
    {"IP", 0.0},
    {"W", 0.0},
    {"CR", 0.0}
};

// implementation of the getGradeval method
double Course::getGradeVal() const {
    auto it = GRADE_POINT_MAP.find(grade); // find the grade on map
    if (it != GRADE_POINT_MAP.end()) { 
        return it->second;
    } else {
        return 0.0;
    }
}
double Course::getCourseCredits()
{
    if (grade == "IP") {
        return 0.0;
    } else if (grade == "W") {
        return 0.0;
    } else if (grade == "CR"){
        return 0.0;
    } else if (grade == "F"){
        return 0.0;
    }
    else{
        return credits;
    }
   }
bool Course::CSDept()
{
    if(coursePrefix == "C-S")
    {
        return true;
    }
    else{
        return false;
    }
}

/* double Course::getCourseGradeVal()
{    
    double gradePoints = 0.0;
    switch (grade)
    {
    case "A+":	
        gradePoints= 4.0;
        break;
    case 'A':
    	gradePoints=  4.0;
        break;
    case "A-":
    	gradePoints= 3.7;  
        break; 
    case "B+":
    	gradePoints= 3.3;
        break;
    case 'B':
    	gradePoints= 3.0;
        break;
    case "B-":	
        gradePoints= 2.7;
        break;
    case "C+":
    	gradePoints= 2.3;
        break;
    case 'C':
    	gradePoints= 2.0;
        break;
    case "C-":	
        gradePoints= 2.0;
        break;
    case "D+":
        gradePoints= 1.0;
        break;
    case 'D':
        gradePoints= 1.0;
        break;
    case "D-":
        gradePoints= 1.0;
        break;
    case 'F':
        gradePoints= 0.0;
        break;
    case 'W':
        gradePoints= 0.0;
        break;
    case "IP":
        gradePoints= 0.0;
        break;
    case "CR":
        gradePoints= 0.0;
        break;
    default:
        gradePoints= 0.0;
        break;
    }
    return gradePoints;
}
*/