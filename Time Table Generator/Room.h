#ifndef ROOM_H_INCLUDED
#define ROOM_H_INCLUDED

#include <string>
using namespace std;

class Room{
private:
    string roomNumber; // stores room number e.g. 6.522
    unsigned int capacity;  //stores room capacity
    int availability[5][4]; // timetable which stores 1 and 0. 1 stands for busy, 0 stands for free
public:
    void setRoomNumber(string num); //to set room number
    string getRoomNumber(); // to get room number
    void setCapacity(int cap);// to set room capacity
    int getCapacity(); //to get room capacity
    void setAvailability(int day, int timeslot); // to change availability of room to busy at this time
    int getAvailability(int day, int timeslot); //return 1 if room is busy and 0 if room is free
    void clearAvailability(); //initializes all time slots to 0 - room is free at any time, used in constructor
    Room();
};


#endif // ROOM_H_INCLUDED
