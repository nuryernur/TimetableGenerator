This project creates Timetable for the School of Engineering at Nazarbayev University using the input data from .txt files.  
 
How to run the code:
1) Provide required input(read below)
2) Launch program in IDE

By default sample inputs are provided for all Nazarbayev University School of Engineering courses in CourseList.txt , InstructorList.txt , 
GroupList.txt , RoomList.txt. 
 
Courses schedule can be viewed in TimeTable.txt

To add/change data follow the manual below.

1.To add a new group to the program:
	1.	Open GroupList.txt file
	2.	Enter the group number and size, each followed by comma, no free space between data.
	Example:
	Group Number,Size,
	1T1,48,
1T1— first character stands for year of study,
            second character stands for type of the course,
		types of courses:
				t-Lab 
				T-Tutorial 
				L-Lecture
            last character stands for group number.
2.To add a new Instructor:
	1.	Open InstructorList.txt file
	2.	Enter the full name followed by comma.
	Example:
	Full Name,
	Vipin Kizheppatt,

3.To add a new room:
	1.	Open RoomList.txt file
	2.	Enter the Room Number and Capacity of this room, each followed by comma,
	Example:
	Room Number,Capacity,
	6.522,70,

4.To add a new course to the program:
	1.	Open CourseList.txt file 

	For the 1st Year students:

	1.	Enter the group which is taking course, name of the course and Instructor of the course and every data should be followed by comma.
	Remember there should not be free space between data.
	Example:
	Group,Course Name,Instructor,
	1T1,Engineering Programming,Vipin Kizheppatt,

	2.	Move to the next line to enter the next new course.

	For the 2nd, 3rd, 4th Year students:

	1.	First enter the lab groups corresponding to the group, course and enter its lab room.
	2.	Then if the course has tutorial, enter the tutorial.
	3.	Enter the lecture.
	Example:
	2t1,Lab Microelectronic Devices and Circuits,Alex James,6.427,
	2t2,Lab Microelectronic Devices and Circuits,Alex James,6.427,
	2t3,Lab Microelectronic Devices and Circuits,Alex James,6.427,
	2T1,Microelectronic Devices and Circuits,Alex James,
	2L1,Microelectronic Devices and Circuits Lecture,Alex James,




