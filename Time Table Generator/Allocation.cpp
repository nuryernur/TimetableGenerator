#include "Allocation.h"

void alphabeticalOrder(class Course *courses, int NumberOfCourses){ // function to sort objects in alphabetical order based on objects ID
    for(int i = 0; i < NumberOfCourses - 1; i++){ // dummy variable of first course
        for(int j = i + 1; j < NumberOfCourses; j++){ // dummy variable of second course
            orderCourses(courses, NumberOfCourses, i, j, 0); // function compares the names of courses letter by letter, and swaps them to be in alphabetical order
        }
    }
}

void orderCourses(class Course *courses, int NumberOfCourses, int i, int j, int k){ // function that recursively compares the names of two courses letter by letter, and orders them alphabetically
    if(courses[i].getID()[k] > courses[j].getID()[k]){ // compares ASCI codes. If in the alphabet the kth letter of first course stays after the kth letter of second - swap.
        swap(courses[i], courses[j]); // swaps two objects in array, if above condition is true
    }
    else if(courses[i].getID()[k] == courses[j].getID()[k]){ // if kth letters are the same, calls itself and compares the (k + 1)th letters
        orderCourses(courses, NumberOfCourses, i, j , k + 1);
    }
}

int countLine(char s[]){ // function to count total number of lines in txt file
    fstream myfile (s);
    int counter = 0;
    string line;
    if(myfile.is_open()){
        while(getline(myfile, line)){
            counter++;
        }
        return counter;
    }
}

void lectureSort(class Course *courses, int NumberOfCourses){   // this function sorts courses based on number of groups
                                                                //such that courses with the greatest number of groups(lectures) are stored in first objects
                                                                //then after lectures labs are placed, and finally tutorials
    for(int i = 0; i < NumberOfCourses; i++){
        if(courses[i].getRoom()!="none"){        //this loop initialize variable lab of class courses to true if it lab
            courses[i].setLabTrue();
        }
    }

    for(int b = 0; b < NumberOfCourses; b++){       //this loops sorts lectures
        int counter1 = 0;
        for(int k = 0; k < 5; k++){
            if(courses[b].getGroupIndex(k)!=0){
                counter1 += 1;
            }      // counts number of groups in the first course
        }

        for(int i = b+1; i < NumberOfCourses; i++){
            int counter2 = 0;

            for(int k = 0; k < 5; k++){
                if(courses[i].getGroupIndex(k) != 0){
                    counter2 += 1;
                } // counts number of groups in the second course
            }

            if(counter2 > counter1){
                class Course temp;
                temp = courses[b];
                courses[b] = courses[i];                //swap courses if number of groups in the second is greater than in the first
                courses[i] = temp;
                counter1 = counter2;
            }
        }
    }

    int position =0;

    for(int i = 0; i < NumberOfCourses; i++){ //this loops finds position in array of course objects. This position indicates where lectures ended
        int counter1 = 0;
        for(int k = 0; k < 5; k++){
            if (courses[i].getGroupIndex(k)!=0){
                counter1 += 1;
            }      // counts number of groups in the first course
        }
        if(counter1 == 1){
            position = i;
            break;
        }
    }

    for(int i = position; i < NumberOfCourses; i++){ //from this position labs are placed
        for (int j = i + 1; j < NumberOfCourses; j++){
            if(courses[j].getRoom() != "none"){
                swap(courses[i],courses[j]);
            }
        }
    } //after this loop the remaining objects after labs are tutorials
}

int findAvailableRoom(class Room *room, int day, int timeslot, int sizeOfGroup, int NumberOfRooms){    //find available room at this time with required capacity
    int i = 0;
    for(i = 0; i < NumberOfRooms; i++){
        if(room[i].getAvailability(day, timeslot) == 0 && room[i].getCapacity() >= sizeOfGroup){ // Checks if room is available and has enough capacity
            return i; // returns room index
        }
    }
    return -1; // Returns -1 if no room is available
}

// this function checks all days and time slots and chooses the
//first one for which all conditions (groups, instructors and room are available) are satisfied.


void orderAlloc(class Course *courses, class Group *groups, class Instructor *instructors, class Room *rooms, int i, int NumberOfCourses, int NumberOfRooms){
    if(i == NumberOfCourses){
        return;
    }
    for(int day = 0; day < 5; day++){
        for(int time =0; time <4; time++){
            if(courses[i].getLab() == true){              // for labs
                if (groups[courses[i].getGroupIndex(0)].getTimeTable(day,time) == 0 && // if group 1,2,3,4,5 and instructor are free
                    groups[courses[i].getGroupIndex(1)].getTimeTable(day,time) == 0 &&
                    groups[courses[i].getGroupIndex(2)].getTimeTable(day,time) == 0 &&
                    groups[courses[i].getGroupIndex(3)].getTimeTable(day,time) == 0 &&
                    groups[courses[i].getGroupIndex(4)].getTimeTable(day,time) == 0 &&
                    instructors[courses[i].getInstructorIndex()].getTimeTable(day,time) == 0&&
                    rooms[courses[i].getRoomIndex()].getAvailability(day,time)==0){
                        courses[i].setSchedule();
                        courses[i].setTime(time);            // allocation of course
                        courses[i].setDay(day);
                        rooms[courses[i].getRoomIndex()].setAvailability(day, time);
                        instructors[courses[i].getInstructorIndex()].setTimeTable(day,time);
                        if(courses[i].getGroupIndex(0) != 0){
                            groups[courses[i].getGroupIndex(0)].setTimeTable(day,time);
                        } // allocation of group indexes
                        if(courses[i].getGroupIndex(1) != 0){
                            groups[courses[i].getGroupIndex(1)].setTimeTable(day,time);
                        }
                        if(courses[i].getGroupIndex(2) != 0){
                            groups[courses[i].getGroupIndex(2)].setTimeTable(day,time);
                        }
                        if(courses[i].getGroupIndex(3) != 0){
                            groups[courses[i].getGroupIndex(3)].setTimeTable(day,time);
                        }
                        if(courses[i].getGroupIndex(4) != 0){
                            groups[courses[i].getGroupIndex(4)].setTimeTable(day,time);
                        }
                        day = 5;    // to terminate  outer loop
                        time = 4; //to terminate inner loop
                        randomAlloc(courses, groups, instructors, rooms, i+1, NumberOfCourses, NumberOfRooms);return;
                }
                else{
                    if(day==4 && time==3){                         //to test, and show errors
                        cout << courses[i].getID()<<endl;
                        cout << "Inst ID "<< instructors[courses[i].getInstructorIndex()].getID()<<endl;
                        for (int j=0; j<5; j++){
                            for (int k=0; k<4; k++){
                                cout << instructors[courses[i].getInstructorIndex()].getTimeTable(j,k)<< " ";
                            }
                        }
                        cout << endl;
                        for (int j=0; j<5; j++){
                            for (int k=0; k<4; k++){
                                cout << groups[courses[i].getGroupIndex(0)].getTimeTable(j,k)<< " ";
                            }
                        }
                        cout << endl;
                        for (int j=0; j<5; j++){
                            for (int k=0; k<4; k++){
                                cout << groups[courses[i].getGroupIndex(1)].getTimeTable(j,k)<< " ";
                            }
                        }
                        cout<< endl;
                        for (int j=0; j<5; j++){
                            for (int k=0; k<4; k++){
                                cout << groups[courses[i].getGroupIndex(2)].getTimeTable(j,k)<< " ";
                            }
                        }
                        cout<< endl;
                        for (int j=0; j<5; j++){
                            for (int k=0; k<4; k++){
                                cout << groups[courses[i].getGroupIndex(3)].getTimeTable(j,k)<< " ";
                            }
                        }
                        cout<< endl;
                        for (int j=0; j<5; j++){
                            for (int k=0; k<4; k++){
                                cout << groups[courses[i].getGroupIndex(4)].getTimeTable(j,k)<< " ";
                            }
                        }
                        cout << endl;
                        cout << rooms[courses[i].getRoomIndex()].getRoomNumber() << endl;
                        for(int j = 0; j < 5; j++){
                            for (int k = 0; k < 4; k++){
                                cout << rooms[courses[i].getRoomIndex()].getAvailability(j,k)<< " ";
                            }
                        }
                        cout <<endl;
                        randomAlloc(courses, groups, instructors, rooms, i+1, NumberOfCourses, NumberOfRooms); //random allocation of next course in case
                    }
                }
            }

            if(courses[i].getLab() == false){          // for other courses except labs
                if(groups[courses[i].getGroupIndex(0)].getTimeTable(day,time) == 0 && // if group 1,2,3,4,5 and instructor are free
                   groups[courses[i].getGroupIndex(1)].getTimeTable(day,time) == 0 &&
                   groups[courses[i].getGroupIndex(2)].getTimeTable(day,time) == 0 &&
                   groups[courses[i].getGroupIndex(3)].getTimeTable(day,time) == 0 &&
                   groups[courses[i].getGroupIndex(4)].getTimeTable(day,time) == 0 &&
                   instructors[courses[i].getInstructorIndex()].getTimeTable(day,time) == 0){

                    int rmindex = findAvailableRoom(rooms, day, time, courses[i].getCourseSize(), NumberOfRooms);
                    if(rmindex != -1 && rooms[rmindex].getCapacity()>100 && courses[i].getCourseSize()<100){
                        continue;
                    } // this condition prevents allocation of big rooms for tutorials
                    if(rmindex != -1){ //rmindex is index of room available at this time with this capacity
                        courses[i].setSchedule();
                        courses[i].setRoom(rooms[rmindex].getRoomNumber()); // allocation of course
                        courses[i].setTime(time);
                        courses[i].setDay(day);
                        rooms[rmindex].setAvailability(day, time);
                        instructors[courses[i].getInstructorIndex()].setTimeTable(day,time);
                        if(courses[i].getGroupIndex(0)!=0){
                            groups[courses[i].getGroupIndex(0)].setTimeTable(day,time);
                        } // setting group availability to busy at this time
                        if(courses[i].getGroupIndex(1)!=0){
                            groups[courses[i].getGroupIndex(1)].setTimeTable(day,time);
                        }
                        if(courses[i].getGroupIndex(2)!=0){
                            groups[courses[i].getGroupIndex(2)].setTimeTable(day,time);
                        }
                        if(courses[i].getGroupIndex(3)!=0){
                            groups[courses[i].getGroupIndex(3)].setTimeTable(day,time);
                        }
                        if(courses[i].getGroupIndex(4)!=0){
                            groups[courses[i].getGroupIndex(4)].setTimeTable(day,time);
                        }

                        day = 5;  //  to terminate both outer
                        time = 4; // to terminate both inner
                        randomAlloc(courses, groups, instructors, rooms, i+1, NumberOfCourses, NumberOfRooms); return;// random allocation of next course in case of successful allocation of current course
                    }
                    if(rmindex == -1 && day == 4 && time == 3){
                        cout << "No room " << i<<endl;      //displaying error
                        randomAlloc(courses, groups, instructors, rooms, i+1, NumberOfCourses, NumberOfRooms);return; //random allocation of next course in case of unsuccessful allocation of current course
                    }
                }
                else{
                    if(day==4 && time==3){                         //to test, and show errors
                        cout << "Groups Instructors are busy: " << i << endl;
                        cout << "Inst ID " << instructors[courses[i].getInstructorIndex()].getID()<<endl;
                        for (int j = 0; j < 5; j++){
                            for (int k=0; k<4; k++){
                                cout << instructors[courses[i].getInstructorIndex()].getTimeTable(j,k)<< " ";
                            }
                        }
                        cout << endl;
                        for (int j = 0; j < 5; j++){
                            for (int k=0; k<4; k++){
                                cout << groups[courses[i].getGroupIndex(0)].getTimeTable(j,k)<< " ";
                            }
                        }
                        cout << endl;
                        for (int j = 0; j < 5; j++){
                            for (int k=0; k<4; k++){
                                cout << groups[courses[i].getGroupIndex(1)].getTimeTable(j,k)<< " ";
                            }
                        }
                        cout<< endl;
                        for (int j = 0; j < 5; j++){
                            for (int k=0; k<4; k++){
                                cout << groups[courses[i].getGroupIndex(2)].getTimeTable(j,k)<< " ";
                            }
                        }
                        cout<< endl;
                        for (int j = 0; j < 5; j++){
                            for(int k=0; k<4; k++){
                                cout << groups[courses[i].getGroupIndex(3)].getTimeTable(j,k)<< " ";
                            }
                        }
                        cout<< endl;
                        for (int j=0; j<5; j++){
                            for (int k=0; k<4; k++){
                                cout << groups[courses[i].getGroupIndex(4)].getTimeTable(j,k)<< " ";
                            }
                        }
                        cout <<endl;
                        randomAlloc(courses, groups, instructors, rooms, i+1, NumberOfCourses, NumberOfRooms);return; //random allocation of next course in case
                    }
                }                                                                                     //if allocation of current course is failed due to instructor and group unavailability
            }

        } //time loop
    } //day loop
}

//chooses a random day and timeslot, then
//checks whether groups and instructor which participate in this course are available at this time.
void randomAlloc(class Course *courses, class Group *groups, class Instructor *instructors, class Room *rooms, int i, int NumberOfCourses, int NumberOfRooms){
    if(i == NumberOfCourses){
        return;
    }

    if(courses[i].getSchedule()){
        randomAlloc(courses, groups, instructors, rooms, i+1, NumberOfCourses, NumberOfRooms);
    } //if course is already scheduled, schedule next course
    else{
        int day=0;
        int time=0;

        day = rand() % 5;  //random day and time
        time = rand() % 4;
        if(courses[i].getLab()== true){              // for labs
             if(groups[courses[i].getGroupIndex(0)].getTimeTable(day,time) == 0 && // if group 1,2,3,4,5 and instructor are free
                groups[courses[i].getGroupIndex(1)].getTimeTable(day,time) == 0 &&
                groups[courses[i].getGroupIndex(2)].getTimeTable(day,time) == 0 &&
                groups[courses[i].getGroupIndex(3)].getTimeTable(day,time) == 0 &&
                groups[courses[i].getGroupIndex(4)].getTimeTable(day,time) == 0 &&
                instructors[courses[i].getInstructorIndex()].getTimeTable(day,time) == 0&&
                rooms[courses[i].getRoomIndex()].getAvailability(day,time) == 0){
                    courses[i].setSchedule();
                    courses[i].setTime(time);
                    courses[i].setDay(day);
                    rooms[courses[i].getRoomIndex()].setAvailability(day, time);
                    instructors[courses[i].getInstructorIndex()].setTimeTable(day,time);
                    if(courses[i].getGroupIndex(0)!= 0){
                        groups[courses[i].getGroupIndex(0)].setTimeTable(day,time);
                    } // setting group availability to busy
                    if(courses[i].getGroupIndex(1)!= 0){
                        groups[courses[i].getGroupIndex(1)].setTimeTable(day,time);
                    }
                    if(courses[i].getGroupIndex(2)!= 0){
                        groups[courses[i].getGroupIndex(2)].setTimeTable(day,time);
                    }
                    if(courses[i].getGroupIndex(3)!= 0){
                        groups[courses[i].getGroupIndex(3)].setTimeTable(day,time);
                    }
                    if(courses[i].getGroupIndex(4)!= 0){
                        groups[courses[i].getGroupIndex(4)].setTimeTable(day,time);
                    }
                    randomAlloc(courses, groups, instructors, rooms, i+1, NumberOfCourses, NumberOfRooms);//if current course is successfully allocated, allocates next course randomly
                    return;
            }
            else{
                orderAlloc(courses, groups, instructors, rooms, i, NumberOfCourses, NumberOfRooms);// if random allocation fails starts ordered allocation
                return;
            }
        }

        if(courses[i].getLab() == false){                                                                  // for other courses except labs
            if(groups[courses[i].getGroupIndex(0)].getTimeTable(day,time) == 0 && // if group 1,2,3,4,5 and instructor are free
               groups[courses[i].getGroupIndex(1)].getTimeTable(day,time) == 0 &&
               groups[courses[i].getGroupIndex(2)].getTimeTable(day,time) == 0 &&
               groups[courses[i].getGroupIndex(3)].getTimeTable(day,time) == 0 &&
               groups[courses[i].getGroupIndex(4)].getTimeTable(day,time) == 0 &&
               instructors[courses[i].getInstructorIndex()].getTimeTable(day,time) == 0){

                int rmindex=findAvailableRoom(rooms, day, time, courses[i].getCourseSize(), NumberOfRooms);

                if(rmindex != -1){ //rmindex is index of room available at this time with this capacity
                    if(rooms[rmindex].getCapacity() > 100 && courses[i].getCourseSize() < 100){
                        orderAlloc(courses, groups, instructors, rooms, i, NumberOfCourses, NumberOfRooms);
                        return;
                    }
                    courses[i].setSchedule();
                    courses[i].setRoom(rooms[rmindex].getRoomNumber());
                    courses[i].setTime(time);
                    courses[i].setDay(day);
                    rooms[rmindex].setAvailability(day, time);
                    instructors[courses[i].getInstructorIndex()].setTimeTable(day,time);
                    if(courses[i].getGroupIndex(0)!= 0){
                        groups[courses[i].getGroupIndex(0)].setTimeTable(day,time);
                    }
                    if(courses[i].getGroupIndex(1)!= 0){
                        groups[courses[i].getGroupIndex(1)].setTimeTable(day,time);
                    }
                    if(courses[i].getGroupIndex(2)!= 0){
                        groups[courses[i].getGroupIndex(2)].setTimeTable(day,time);
                    }
                    if(courses[i].getGroupIndex(3)!= 0){
                        groups[courses[i].getGroupIndex(3)].setTimeTable(day,time);
                    }
                    if(courses[i].getGroupIndex(4)!= 0){
                        groups[courses[i].getGroupIndex(4)].setTimeTable(day,time);
                    }
                    randomAlloc(courses, groups, instructors, rooms, i+1, NumberOfCourses, NumberOfRooms);
                    return;
                }
                if(rmindex == -1){
                    orderAlloc(courses, groups, instructors, rooms, i, NumberOfCourses, NumberOfRooms); return;// if room is not found for random allocation
                                                                                                //starts ordered allocation
                }
            }
            else{
                //if groups and instructors are busy starts ordered allocation
                orderAlloc(courses, groups, instructors, rooms, i, NumberOfCourses, NumberOfRooms);
                return;
            }
        }
    }
    //if (i==NumberOfCourses-1) cout << "\n\nAll courses are successfully allocated"<<endl;
}
