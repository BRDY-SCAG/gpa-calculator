#ifndef AUDITDATA_H
#define AUDITDATA_H
#include <iostream>
#include <fstream>
#include <sstream>
#include "AuditDataset.h"



AuditDataset::AuditDataset()
{
    //Default constructor;
}


bool AuditDataset::readAudit(char* filename)
{
    // create an input stream object for the filename given as an argument;
    // this also opens the file for reading
    //filename = std::ifstream inFile(argv[1]);
    std::ifstream inFile(filename);
    if (!inFile) {
        std::cerr << "Error: file " << filename << " cannot be opened\n";
        return false;
    }
    std::string line;
    std::string term;
    std::string coursePrefix;
    std::string courseNumber;
    std::string grade;
    // read the file line by line; this is safer than trying to 
    // parse the lines as you read the data in
    while (std::getline(inFile, line)) {
        // std::cout << "line is [" << line << "]\n";
        if (line.length() < 2)
            continue; // probably at end of file
        // create a "stream" for the line itself so that we
        // can use the ">>" input directly into variables
        std::istringstream lineStream(line);
        // variables for the data pieces
        std::string term, coursePrefix, courseNumber, grade;
        double credits;
        // read input line to our data variables
        lineStream >> term >> coursePrefix >> courseNumber >> credits >> grade;
        // print them out just to show it works
        //std::cout << term << " | " << coursePrefix << " | " << 
              //courseNumber << " | " << credits << " | " << grade << "\n";
    
    Course *courses = new Course(term, coursePrefix, courseNumber, credits, grade);
    data.push_back(courses);
    }
    inFile.close();
    std::cout << "Done processing the file." << "\n";
    return true;
}

void AuditDataset::printData()
{
    std::cout <<" Total number of courses:" << data.size() << "\n";
}
double AuditDataset::calcGPA()
{
    double totPoints = 0.0;
    double CSPoints = 0.0;
    double totCredHours = 0.0;
    double CSCredHours = 0.0;
    double GPA = 0.0;
    double CSGPA = 0.0;
    int IPindex = 0;
    for(Course* courses : data)
    {
        if(courses->CSDept())
        {
            totPoints += courses->getCourseCredits() * courses->getGradeVal();
            totCredHours += courses->getCourseCredits();
            CSPoints += (courses->getCourseCredits() * courses->getGradeVal());
            CSCredHours += courses->getCourseCredits();
            //std::cout << CSPoints << "\n";
            //std::cout << CSCredHours << "\n";
            //std::cout << "CSGPA " << (CSPoints/CSCredHours) << "\n";
        }
        else{
            totPoints += courses->getCourseCredits() * courses->getGradeVal();
            totCredHours += courses->getCourseCredits();
        }
        if(!courses->isIP())
        {
            continue;
        }
        else{
            IPindex++;
        }
        //std::cout << "Overall GPA: "<< (totPoints/totCredHours) << "\n"; 
        
    }    
    CSGPA = (CSPoints/CSCredHours);
    GPA = (totPoints/totCredHours);
    GPA = std::round(GPA * 100) / 100.0;
    CSGPA = std::round(CSGPA * 100) / 100.0;
    //std::cout << "Total number of courses: " << data.size() << "\n";
    std::cout << "Courses in Progress: " << IPindex << "\n";
    std::cout << "Total GPA credit hours earned: " << totCredHours << "\n";
    std::cout << "Overall GPA: "<< GPA << "\n";
    std::cout << "CS GPA: " << CSGPA << "\n";
    return 0.0;
}

void AuditDataset::CreditsCounter()
{
    int noCredit {0};
    int creditCourses{0};
    for(Course* courses : data)
    {
        if(courses->getCourseCredits() == 0.0 && (!courses->isIP()))
        {
            noCredit++;
        }
        else{
            continue;
        }
    }
    for(Course* courses : data)
    {
        if(courses->getCourseCredits() != 0.0)
        {
            creditCourses++;
        }
        else{
            continue;
        }
    }
    std::cout << "Total number of courses: "  << data.size() << "\n";
    std::cout <<"Courses receiving credit: " << creditCourses << "\n";
    std::cout <<"Courses not receiving credit: " << noCredit << "\n";
}

#endif
