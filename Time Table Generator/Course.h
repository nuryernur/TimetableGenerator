#ifndef COURSE_H_INCLUDED
#define COURSE_H_INCLUDED

#include "Group.h"

#include <string>
using namespace std;

class Course{
private:
    bool lab; // true for labs and false for lectures and tutorials
    bool scheduled; // true if course is scheduled, false if not scheduled
    string ID; // name of a course
    string group[5]; // Tutorial groups that should attend the course
    string instructor; // Instructor name
    string room; // Room number
    string tut;
    int day; // the day when the lecture is assigned (Monday = 0, Tuesday = 1 etc)
    int time; // the number of timeslot ( 0 - 09:00 - 11:00, 1 - 11:00 - 13:00 etc)

    unsigned int course_size; // The number of students that should attend the course
    unsigned int roomIndex; // the index of room object in array, in which information for room where this course takes place is stored
    unsigned int instructorIndex; // the index of instructor object in array, in which information for instructor is stored
    unsigned int groupIndex[5]; // the indexes of group objects in array, in which information for groups is stored
public:
    bool getLab();
    void setLabFalse();
    void setLabTrue();
     void setRoom(string num);
    string getRoom();

    void setTut(string tut);
    string getTut();

    void setID(string id);
    string getID();

    void setGroup(string gr, int i);
    string getGroup(int);

    void setInstructor(string instr);
    string getInstructor();

    void setDay(int i);
    int getDay();

    void setTime(int i);
    int getTime();

    void setCourseSize(int siz);
    unsigned int getCourseSize();

    void setRoomIndex(int index);
    unsigned int getRoomIndex();

    void setInstructorIndex(int index);
    unsigned int getInstructorIndex();

    void setGroupIndex(int i, int index);
    int getGroupIndex(int);
    void setSchedule();
    bool getSchedule();
    Course();
};

void setSizesOfCourses(class Group *groups, class Course *courses, int NumberOfCourses); // sums the number of students in each tutorial group that attends this course

#endif // COURSE_H_INCLUDED
