#include "Input.h"


string substrings[10];
string groups[5];
string tut_groups[5];

void InputCourse(class Course *courses){
    string line,n;
    ifstream myCourse("CourseList.txt");
    static int k=0,u=0,y=0,z=0;
    int m=0;
    string tutorial;
    if(myCourse.is_open()){
        while(getline(myCourse, line)){
            splitline(line);
            if(substrings[0].substr(1,1)=="L"){

                if(y==1){
                    courses[k].setTut(tutorial);
                    for(m=0;m<u;m++){
                        courses[k].setGroup(groups[m],m);
                        }
                y=0;
                u=0;
                }
                    else {
                        if(substrings[0].substr(0,1)=="1"){
                            for(int y=0;y<z;y++){
                                courses[k].setGroup(tut_groups[y],y);
                                }
                            z=0;

                            }
                        else{
                            courses[k].setTut(tutorial);
                            tutorial=" ";
                        }
                    }
            }
           else if(substrings[1].substr(0,3)=="Lab"){
                    groups[u]=substrings[0];
                    courses[k].setGroup(substrings[0],0);
                    courses[k].setRoom(substrings[3]);
                    y=1;
                    u++;
                    }
           else{
                    if(y==1){
                        courses[k].setTut(substrings[0]);
                        tutorial=substrings[0];
                        for(m=0;m<u;m++){
                        courses[k].setGroup(groups[m],m);
                       }
                    }
                    else{
                        if(substrings[0].substr(0,1)=="1"){
                            courses[k].setGroup(substrings[0],0);
                            tut_groups[z]=substrings[0];
                            z++;
                        }
                        else{
                            tutorial=substrings[0];
                            courses[k].setTut(substrings[0]);
                            }

                        }
                }
                courses[k].setID(substrings[1]);
                courses[k].setInstructor(substrings[2]);
                k++;
       }

            for(u=0;u<5;u++){
                groups[u]="none";
            }
            for(int i=0;i<k;i++)
            {
                if(courses[i].getGroup(0)=="none")
                {
                    for(int j=0;j<k;j++){
                        if(courses[j].getTut()==courses[i].getTut() && courses[j].getGroup(0)!="none"){
                            for(u=0;u<5;u++)
                            {
                                courses[i].setGroup(courses[j].getGroup(u),u);
                            }
                        }
                    }
                }
            }

        }

    else{
        cout<<"The Course List cannot be opened. Check your file and try again.";
    }
}

void InputGroup(class Group *groups){
    string line;
    ifstream myGroup("GroupList.txt");
    static int k=0;
    if(myGroup.is_open()){
        groups[0].setID("none");
        groups[0].setSizeOfGroup(0);
        k++;
        while(getline(myGroup, line)){
            splitline(line);
            groups[k].setID(substrings[0]);
            int h;
            istringstream convert(substrings[1]);
            convert.imbue(locale::classic());
            convert >> h;
            groups[k].setSizeOfGroup(h);
            k++;
        }
    }
    else{
        cout<<"The Group List cannot be opened. Check your file and try again.";
    }
}

void InputRoom(class Room *rooms){
    string line;
    ifstream myRoom("RoomList.txt");
    static int k=0;
    if(myRoom.is_open()){
        while(getline(myRoom, line)){
            splitline(line);
            rooms[k].setRoomNumber(substrings[0]);
            int h;
            istringstream convert(substrings[1]);
            convert.imbue(locale::classic());
            convert >> h;
            rooms[k].setCapacity(h);
            k++;
        }
    }
    else{
        cout<<"The Room List cannot be opened. Check your file and try again.";
    }
}

void InputInstructor(class Instructor *instructors){
    string line;
    ifstream myInstructor("InstructorList.txt");
    static int k=0;
    if(myInstructor.is_open()){
        while(getline(myInstructor, line)){
            splitline(line);
            instructors[k].setID(substrings[0]);
            k++;
        }
    }
    else{
        cout<<"The Room List cannot be opened. Check your file and try again.";
    }
}


/*
int countline(int n, char s[]);
int readline(int n,  char s[]) {
fstream myfile (s);
string line;
int counter=1;
if(myfile.is_open()){
    while (getline(myfile, line))
    {
    counter++;
    return counter++;
    }
}
}
*/

/*

string readline(int n,  char s[]) {
fstream myfile (s);
string line;
int counter=1;
if(myfile.is_open()){
    while (getline(myfile, line))
    {
    if (counter==n){return line; break;}
    counter++;
    }
}
}

void settutorials(class Course courses[]){
char s[20]="Tutorials.txt";
for (int i=0; i<5; i++){
    courses[i].setID(readline(4*i+1, s));
    courses[i].setGroup(readline(4*i+2, s),0);
    courses[i].setGroup("none",1);
    courses[i].setGroup("none",2);
    courses[i].setGroup("none",3);
    courses[i].setGroup("none",4);
    courses[i].setInstructor(readline(4*i+3, s));
}
}


void setlectures(class Course courses[]){
    char s[20] = "Lectures.txt";
    int i = 0;
    while(courses[i].getTime() == -1)
        i++;
    for(int k = 0; k < 5; k++, i++){
        courses[i].setID(readline(8 * k + 1 ,s));
        courses[i].setGroup(readline(8 * k + 2, s),0);
        courses[i].setGroup(readline(8 * k + 3, s),1);
        courses[i].setGroup(readline(8 * k + 4, s),2);
        courses[i].setGroup(readline(8 * k + 5, s),3);
        courses[i].setGroup(readline(8 * k + 6, s),4);
        courses[i].setInstructor(readline(8 * k + 7 ,s));
    }
}
*/
