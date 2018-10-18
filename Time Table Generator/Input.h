#ifndef INPUT_H_INCLUDED
#define INPUT_H_INCLUDED
#include "Course.h"
#include "Group.h"
#include "Instructor.h"
#include "Room.h"

#include <cstring>
#include <sstream>
#include <iostream>
#include <fstream>
#include "splitline.h"

using namespace std;



void InputCourse(class Course *courses);
void InputLab(class Course *courses);
void InputGroup(class Group *groups);
void InputRoom(class Room *rooms);
void InputInstructor(class Instructor *instructors);

#endif // INPUT_H_INCLUDED
