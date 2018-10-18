#ifndef INSTRUCTOR_H_INCLUDED
#define INSTRUCTOR_H_INCLUDED

#include <string>
using namespace std;

class Instructor{
private:
    string id; // instructor name and surname
    string course;
    int timetable[5][4]; // instructor availability array, 1 stand for busy, 0 for free in array slot
public:
    string getID();   //return instructor ID
    void setID(string id0); // sets instructors id

    string getCourse();
    void setCourse(string course0);

    int getTimeTable(int day, int timeslot); // returns 1 if instructor is busy at this time and 0 if free
    void setTimeTable(int day, int timeslot); // sets 1 to instructor availability array at this time

    Instructor(); // initialize availability timetable with 0, this means that instructor initially if free at any time
};

#endif // INSTRUCTOR_H_INCLUDED
