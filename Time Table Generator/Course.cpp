#include "Course.h"
#include <iostream>

Course::Course(){
    for(int i = 0; i < 5; i++){
        setGroupIndex(i,0); // initializes the group indexes to 0 (object groups[0] does not specify any group)
        setGroup("none", i); // initializes the group names that should attend the course to "none", which will be used to check if a course is lecture, lab or tutorial
    }
   setLabFalse(); // labs are set to false by default
    day = -1; // day is initialized to -1, which stands for non allocated
    time = -1; // timeslot is initialized to -1
    scheduled = false; // courses are initialized as unscheduled
    setRoom("none"); // Room is initialized to "none"
}
bool Course::getLab(){
return lab;
};
void Course::setLabFalse(){
lab=false;
};
void Course::setLabTrue(){
lab=true;
};
bool Course::getSchedule(){
    return scheduled;
}

void Course::setSchedule(){
    scheduled = true; // true, if scheduled
}

void Course::setID(string id){
    ID = id;
}

string Course::getID(){
    return ID;
}

void Course::setGroup(string gr, int i){
    group[i] = gr;
}

string Course::getGroup(int n){
    return group[n];
}

void Course::setInstructor(string instr){
    instructor = instr;
}

string Course::getInstructor(){
    return instructor;
}

void Course::setRoom(string num){
    room = num;
}

string Course::getRoom(){
    return room;
}

void Course::setDay(int i){
    day = i;
}

int Course::getDay(){
    return day;
}

void Course::setTime(int i){
    time = i;
}

int Course::getTime(){
    return time;
}

void Course::setCourseSize(int siz){
    course_size = siz;
}

unsigned int Course::getCourseSize(){
    return course_size;
}

void Course::setRoomIndex(int index){
    roomIndex = index;
}

unsigned int Course::getRoomIndex(){
    return roomIndex;
}

void Course::setInstructorIndex(int index){
    instructorIndex = index;
}

unsigned int Course::getInstructorIndex(){
    return instructorIndex;
}

void Course::setGroupIndex(int i, int index){
    groupIndex[i] = index;
}

int Course::getGroupIndex(int n){
    return groupIndex[n];
}
  void Course::setTut(string t){
    tut = t;
}
 void setTut(string tut);
    string getTut();

string Course::getTut(){
    return tut;
}


void setSizesOfCourses(class Group *groups, class Course *courses, int NumberOfCourses){ // function that calculates the number of students that should attend the course

    for(int i = 0; i < NumberOfCourses; i++){ // sets size of all courses
        int course_size = 0; // variable to store the number of students
        course_size += groups[courses[i].getGroupIndex(0)].getSizeOfGroup(); // gets index of group that attends this course from object courses
        course_size += groups[courses[i].getGroupIndex(1)].getSizeOfGroup(); // and gets size of this group from array groups[] and adds it to total
        course_size += groups[courses[i].getGroupIndex(2)].getSizeOfGroup(); // number of students that should attend this course
        course_size += groups[courses[i].getGroupIndex(3)].getSizeOfGroup();
        course_size += groups[courses[i].getGroupIndex(4)].getSizeOfGroup();

        courses[i].setCourseSize(course_size); // sets the number of students  calculated above to attribute course_size in courses object
    }
}
