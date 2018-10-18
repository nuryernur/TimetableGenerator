#ifndef OUTPUT_H_INCLUDED
#define OUTPUT_H_INCLUDED
#include <fstream>
#include "Course.h"
#include <iostream>
#include <iomanip>

using namespace std;

void instructorTimeTable(class Course *courses, int NumberOfCourses); // Outputs specific instructor time table to InstructorTimeTable.txt

void output(class Course courses[], int NumberOfCourses); // Outputs all courses time table to Output.txt

#endif // OUTPUT_H_INCLUDED
