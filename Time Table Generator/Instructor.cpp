#include "Instructor.h"

string Instructor::getID(){
    return id;
}
void Instructor::setID(string id0){
    id = id0;
}

string Instructor::getCourse(){
    return course;
}
void Instructor::setCourse(string course0){
    course = course0;
}

int Instructor::getTimeTable(int day, int timeslot){
    return timetable[day][timeslot];
}
void Instructor::setTimeTable(int day, int timeslot){
    timetable[day][timeslot] = 1;
}

Instructor::Instructor(){
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 4; j++){
            timetable[i][j] = 0; // 0 free; 1 not free
        }
    }
}
