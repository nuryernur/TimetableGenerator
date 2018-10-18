#include "Instructor.h"
#include "Room.h"
#include "Group.h"
#include "Course.h"
#include "Input.h"
#include "Allocation.h"
#include "Output.h"
#include "splitline.h"
#include "IndexDistribution.h"

#include <iostream>
#include <stdlib.h>
#include <time.h>


using namespace std;
int main(){
    int NumberOfCourses;
    int NumberOfGroups;
    int NumberOfRooms;
    int NumberOfInstructors;

    srand(static_cast<unsigned int>(time(0)));
    class Course *courses;
    class Group *groups;
    class Room *rooms;
    class Instructor *instructors;

    NumberOfCourses= countLine("CourseList.txt");           // function countLine counts number of lines in txt file
    NumberOfGroups=countLine("GroupList.txt");              // then these values are assigned
    NumberOfInstructors=countLine("InstructorList.txt");    // to the corresponding variable which represents total number of courses, instructors, rooms...
    NumberOfRooms=countLine("RoomList.txt");


    cout <<"NumberOfCourses: "<< NumberOfCourses<<endl;
    cout <<"NumberOfGroups: "<< NumberOfGroups<<endl;
    cout <<"NumberOfRooms: "<<NumberOfRooms<<endl;
    cout <<"NumberOfInstructors: "<<NumberOfInstructors<<endl;


    courses = new class Course[NumberOfCourses];     // dynamically creates list of objects for class Course, Instructor, Group, Room...
    groups = new class Group[NumberOfGroups+1];
    groups[0].setID("none");                         // this object groups[0] will be  used in algorithm
    groups[0].setSizeOfGroup(0);
    rooms = new class Room[NumberOfRooms];
    instructors = new class Instructor[NumberOfInstructors];

    InputCourse(courses);          //These input functions initialize objects courses, groups, rooms, instructors with the required parameters from txt files.
    InputGroup(groups);
    InputRoom(rooms);
    InputInstructor(instructors);

    indexDistribution(courses, groups, instructors, rooms, NumberOfCourses, NumberOfGroups, NumberOfInstructors, NumberOfRooms); // this function distribute indexes

    setSizesOfCourses(groups, courses, NumberOfCourses); // this function calculates total size of groups which take this course


    lectureSort(courses, NumberOfCourses); // this function sorts courses based on number of groups
                                            //such that courses with the greatest number of groups are stored in first objects

    randomAlloc(courses, groups, instructors, rooms, 0, NumberOfCourses, NumberOfRooms); // algorithm starts
    alphabeticalOrder(courses,NumberOfCourses);   // function to sort objects in alphabetical order based on objects ID
   //instructorTimeTable(courses, NumberOfCourses);    // asks instructor name and output instructor's timetable in instructorTimeTable.txt

    output(courses, NumberOfCourses); // outputs all courses in Output.txt
}



