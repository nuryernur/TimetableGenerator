#ifndef GROUP_H_INCLUDED
#define GROUP_H_INCLUDED

#include <string>
using namespace std;

class Group{
private:
    string ID; // Group name (1T1, 1T2, etc)
    int sizeOfGroup; // the number of students in the group
    int timetable[5][4]; // the availability timetable of the group; 5 days, 4 timeslots (2 hours each) ( stores 0 if free, 1 if busy)
public:
    string getID();
    void setID(string id0);

    int getSizeOfGroup();
    void setSizeOfGroup(int siz);

    int getTimeTable(int day, int timeslot);
    void setTimeTable(int day, int timeslot);

    Group();
};


#endif // GROUP_H_INCLUDED
