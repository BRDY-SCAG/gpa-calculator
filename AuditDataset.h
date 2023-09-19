//
// Declaration of WeatherDataset class
//
#ifndef AUDITDATASET_H
#define AUDITDATASET_H
#include <string>
#include <vector>
#include "Course.h"

class AuditDataset
{
public:
   AuditDataset();
   bool readAudit(char* filename);
   void printData();
   double calcGPA();
   void CreditsCounter();
private:
   // the data is stored in a vector, which acts as a list
   // or kind-of like a variable-sized array
   std::vector<Course *> data; // data is Course Objects

};
#endif // WEATHERDATASET_H
