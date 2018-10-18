#include "Room.h"

void Room::setRoomNumber(string num){
    roomNumber = num;
}

string Room::getRoomNumber(){
    return roomNumber;
}

void Room::setCapacity(int cap){
    capacity = cap;
}
int Room::getCapacity(){
    return capacity;
}

void Room::setAvailability(int day, int timeslot){
    availability[day][timeslot] = 1;
}
int Room::getAvailability(int day, int timeslot){
    return availability[day][timeslot];
}

void Room::clearAvailability(){
    for(int day = 0; day < 5; day++){
        for(int timeslot = 0; timeslot < 4; timeslot++){
            availability[day][timeslot] = 0;
        }
    }
}

Room::Room(){
    clearAvailability();
}
