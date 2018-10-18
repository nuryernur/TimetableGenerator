#ifndef INDEXDISTRIBUTION_H_INCLUDED
#define INDEXDISTRIBUTION_H_INCLUDED

#include "Course.h"
#include "Group.h"
#include "Instructor.h"
#include "Room.h"
// indexes were introduced to optimize performance of programm
//in algorithm to check whether group or instructors are free the program should check group and instructor timetable
// for this purpose it should know the position of instructor or group in array of objects of instructors and groups
//this would require a function which search group or instructor position in array of objects
//instead of each time search for this position this is done only once at the begining of the program after input
//and all indexes are stored in class course, this significantly decreases number of calculations which program performs
void indexDistribution(class Course courses[], class Group groups[], class Instructor instructors[], class Room rooms[], int NumberOfCourses, int NumberOfGroups, int NumberOfInstructors, int NumberOfRooms);

#endif // INDEXDISTRIBUTION_H_INCLUDED
