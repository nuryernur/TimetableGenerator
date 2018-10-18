#include "Group.h"

string Group::getID(){
    return ID;
}
void Group::setID(string id0){
    ID = id0;
}

int Group::getSizeOfGroup(){
    return sizeOfGroup;
}
void Group::setSizeOfGroup(int siz){
    sizeOfGroup = siz;
}

int Group::getTimeTable(int day, int timeslot){
    return timetable[day][timeslot];
}
void Group::setTimeTable(int day, int timeslot){
    timetable[day][timeslot] = 1;
}

Group::Group(){
    sizeOfGroup = 0; // the number of students in group is initialized to 0
    for(int i = 0; i < 5; i++){ // all timeslots are initialized to free
        for(int j = 0; j < 4; j++){
            timetable[i][j] = 0; // 0 stands for free; 1 for busy
        }
    }
}
