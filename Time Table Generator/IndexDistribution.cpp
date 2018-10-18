#include "IndexDistribution.h"

void indexDistribution(class Course courses[], class Group groups[], class Instructor instructors[], class Room rooms[], int NumberOfCourses, int NumberOfGroups, int NumberOfInstructors, int NumberOfRooms){
    for(int i = 0; i < NumberOfCourses; i++){
        for(int k=0; k<NumberOfGroups+1; k++){
            if(courses[i].getGroup(0)==groups[k].getID()){
                    courses[i].setGroupIndex(0,k);
            }
            if(courses[i].getGroup(1)==groups[k].getID()){
                    courses[i].setGroupIndex(1,k);
            }
            if(courses[i].getGroup(2)==groups[k].getID()){
                    courses[i].setGroupIndex(2,k);
            }
            if(courses[i].getGroup(3)==groups[k].getID()){
                    courses[i].setGroupIndex(3,k);
            }
            if(courses[i].getGroup(4)==groups[k].getID()){
                    courses[i].setGroupIndex(4,k);
            }
        }

        for (int k=0; k < NumberOfInstructors; k++){
            if (courses[i].getInstructor() == instructors[k].getID()){
                    courses[i].setInstructorIndex(k);
            }
        }
            for(int k=0; k<NumberOfRooms; k++){
                    if(courses[i].getRoom()!="none"){
                if(courses[i].getRoom() == rooms[k].getRoomNumber()){
                        courses[i].setRoomIndex(k);
                }
              }
            }
        }
    }

