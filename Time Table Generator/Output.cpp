#include "Output.h"

void instructorTimeTable(class Course *courses, int NumberOfCourses){
    string instName;
    string instSurname;

    cout << "\n\nEnter instructor name and surname to get his/her time table: ";
    cin >> instName;
    cin>>instSurname;
    string inst= instName+" "+instSurname;
    fstream myfile("InstructorTimeTable.txt", ios::out);
    myfile<<setw(50)<<inst;

    for(int i=0; i < NumberOfCourses; i++){
        if(courses[i].getInstructor() == inst){
            if(myfile.is_open()){
                myfile <<endl <<courses[i].getID()<< " ";
                myfile<<"Day: ";
                myfile<<setw(10)<<left;
                switch(courses[i].getDay()){

                case 0:
                    myfile << "Monday";
                    break;
                case 1:
                    myfile << "Tuesday";
                    break;
                case 2:
                    myfile << "Wednesday";
                    break;
                case 3:
                    myfile << "Thursday";
                    break;
                case 4:
                    myfile << "Friday";
                    break;
                default:
                    myfile << "Error!!!";
                    break;
                }

                myfile<<"Time: ";
                switch(courses[i].getTime()){
                case 0:
                    myfile << "09:00 - 11:00";
                    break;
                case 1:
                    myfile << "11:00 - 13:00";
                    break;
                case 2:
                    myfile << "14:00 - 16:00";
                    break;
                case 3:
                    myfile << "16:00 - 18:00";
                    break;
                default:
                    myfile << "Error!!!";
                    break;
                }

                myfile<<"  Room: ";
                myfile<<courses[i].getRoom();
            }
        }
    }
    cout << endl<<"You can find "<<inst<<"'s time table in InstructorTimeTable.txt";
}

void output(class Course courses[], int NumberOfCourses){
    ofstream myfile ("TimeTable.txt", ios::out);
    if(myfile.is_open()){
        myfile << "\n+";
            for(int j = 0; j < 61; j++)
                myfile << "-";
            myfile << "+";
            for(int j = 0; j < 43; j++)
                myfile << "-";
            myfile << "+";
            for(int j = 0; j < 11; j++)
                myfile << "-";
            myfile << "+";
            for(int j = 0; j < 15; j++)
                myfile << "-";
            myfile << "+";
            for(int j = 0; j < 14; j++)
                myfile << "-";
            myfile << "+";
            for(int j = 0; j < 26; j++)
                myfile << "-";
            myfile << "+\n";
            myfile << left << setw(62) << "| Course";
            myfile << setw(44) << "| Instructor";
            myfile << setw(12) << "| Day";
            myfile << setw(16) << "| Time";
            myfile << setw(15) << "| Room";
            myfile << setw(27) << "| Groups";
            myfile << "|";
            for(int i = 0; i < NumberOfCourses; i++){
                myfile << "\n+";
                for(int j = 0; j < 61; j++)
                    myfile << "-";
                myfile << "+";
                for(int j = 0; j < 43; j++)
                    myfile << "-";
                myfile << "+";
                for(int j = 0; j < 11; j++)
                    myfile << "-";
                myfile << "+";
                for(int j = 0; j < 15; j++)
                    myfile << "-";
                myfile << "+";
                for(int j = 0; j < 14; j++)
                    myfile << "-";
                myfile << "+";
                for(int j = 0; j < 26; j++)
                    myfile << "-";
                myfile << "+";
                myfile << endl << "| " << setw(60) << courses[i].getID();
                myfile << "| " << setw(42) << courses[i].getInstructor();
                myfile << "| " << setw(10);
                switch(courses[i].getDay()){
                case 0:
                    myfile << "Monday";
                    break;
                case 1:
                    myfile << "Tuesday";
                    break;
                case 2:
                    myfile << "Wednesday";
                    break;
                case 3:
                    myfile << "Thursday";
                    break;
                case 4:
                    myfile << "Friday";
                    break;
                default:
                    myfile << "Error!!!";
                    break;
                }
                myfile << "| " << setw(14);
                switch(courses[i].getTime()){
                case 0:
                    myfile << "09:00 - 11:00";
                    break;
                case 1:
                    myfile << "11:00 - 13:00";
                    break;
                case 2:
                    myfile << "14:00 - 16:00";
                    break;
                case 3:
                    myfile << "16:00 - 18:00";
                    break;
                default:
                    myfile << "Error!!!";
                    break;
                }
                myfile << "| " << setw(13) << courses[i].getRoom();
                myfile << "| ";
                for(int j = 0; j < 5; j++){
                    if(courses[i].getGroup(j) != "none"){
                        myfile << courses[i].getGroup(j) << "  ";
                    }else{
                        myfile << "     ";
                    }
                }
                myfile << "|";
                for(int i = 0; i < 1500000; i++);
            }

            myfile << "\n+";
            for(int j = 0; j < 61; j++)
                myfile << "-";
            myfile << "+";
            for(int j = 0; j < 43; j++)
                myfile << "-";
            myfile << "+";
            for(int j = 0; j < 11; j++)
                myfile << "-";
            myfile << "+";
            for(int j = 0; j < 15; j++)
                myfile << "-";
            myfile << "+";
            for(int j = 0; j < 14; j++)
                myfile << "-";
            myfile << "+";
            for(int j = 0; j < 26; j++)
                myfile << "-";
            myfile << "+\n";
    }

    cout << endl << "You can find time table in TimeTable.txt" << endl;
}
