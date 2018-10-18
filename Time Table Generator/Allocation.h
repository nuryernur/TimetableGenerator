#ifndef ALLOCATION_H_INCLUDED
#define ALLOCATION_H_INCLUDED
#include "Course.h"
#include "Group.h"
#include "Instructor.h"
#include "Room.h"
#include <iostream>
#include <stdlib.h>
#include <fstream>

using namespace std;

void alphabeticalOrder(class Course *courses, int NumberOfCourses);
void orderCourses(class Course *courses, int NumberOfCourses, int i, int j, int k);

int countLine(char s[]);

void lectureSort(class Course *courses, int NumberOfCourses);

int findAvailableRoom(class Room *room, int day, int timeslot, int sizeOfGroup, int NumberOfRooms);

void randomAlloc(class Course *courses, class Group *groups, class Instructor *instructors, class Room *rooms, int i, int NumberOfCourses, int NumberOfRooms);
void orderAlloc(class Course *courses, class Group *groups, class Instructor *instructors, class Room *rooms, int i, int NumberOfCourses, int NumberOfRooms);

#endif // ALLOCATION_H_INCLUDED
