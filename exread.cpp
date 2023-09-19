/******************************************************************
 * Example for reading the course data produced by the 
 * reduce.py program
 * - usage: provide the filename as a command line argument
******************************************************************/
#include <iostream>
#include "AuditDataset.h"


int main(int argc, char* argv[])
{   
    AuditDataset* dataset = new AuditDataset();
    dataset->readAudit(argv[1]); 
    dataset->CreditsCounter();
    dataset->calcGPA();
    if (argc != 2) {
        return -1;
    }
    return 0;
}
