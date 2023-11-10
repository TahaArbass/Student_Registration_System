#include "Course.h"
#include "Student.h"
#include "DoublyLinkedList.h"
#include "LListWithDummyNode.h"

#include <fstream>
#include <iomanip>
#include <iostream>
#include <cctype>

using namespace std;

/*-------------------------------------------------------------------------
   Function to fill courses list using txt file.

   Precondition:  None.
   Postcondition: The offered courses list will be filled.
-------------------------------------------------------------------------*/
void inputOfferedCourses(LListWithDummyNode<Course>& offeredCourses);

/*-------------------------------------------------------------------------
   Function to fill students list using txt file.

   Precondition:  None.
   Postcondition: The unregistered students list will be filled.
-------------------------------------------------------------------------*/
void inputUnregisteredStudents(DoublyLinkedList<Student>& students);

int main()
{
	// Create a linked list to store offered courses and fill it from the file
	LListWithDummyNode<Course> offeredCourses;
	inputOfferedCourses(offeredCourses);

	// create a doubly linked list to store unregistered students and fill it
	DoublyLinkedList<Student> unregisteredStudents;
	inputUnregisteredStudents(unregisteredStudents);

	int sizeOfStudentList; // variable to store size of list students
	int sizeOfCL;		   // variable to store size of list courses
	int counter = 0;	   // variable to termin
	string id;
	string code;
	bool found; // boolean to check if a student or course were found
	while (counter < 1)
	{
		// display the list
		cout << "===========================================================\n"
			<< "1. Display the list of non - registered students.\n"
			<< "2. Display the list of offered courses.\n"
			<< "3. Display the list of registered students "
			<< "with the registered courses.\n"
			<< "4. Display the list of offered courses "
			<< "with the registered students.\n"
			<< "5. Display the registered courses for a student.\n"
			<< "6. Display the list of students registered in a course.\n"
			<< "7. Display the information related to a specific student.\n"
			<< "8. Register a student.\n"
			<< "9. Choose a student to add / drop a course for him / her.\n"
			<< "10. Quit the application.\n\n";

		found = false;
		int choice;
		cout << "Enter your choice: ";
		cin >> choice;

		// ensuring that the user does not input a different data type value
		 if (cin.fail()) {
		 	cin.clear(); // clear the fail state

			// discard input
		 	cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
		 	choice = -1; // it will go to the default state like this
		 }

		switch (choice)
		{

		//1. Display the list of non - registered students
		case 1:
			// show unregistered students
			// basically if a student registered a course he won't appear
			// but he is still in the list
			cout << endl;
			cout << left << setw(12) << "ID"
				<< setw(25) << "Name"
				<< setw(6) << "GPA"
				<< setw(15) << "Academic Status" << endl;
			sizeOfStudentList = unregisteredStudents.getSize();

			for (int i = 0; i < sizeOfStudentList; i++)
			{
				Student* studentPtr = unregisteredStudents.getDataAtPos(i);
				if (studentPtr->getSize() == 0)
					studentPtr->displayStudent(cout);
			}
			cout << "\n";
			break;
		
		//2. Display the list of offered courses
		case 2:
			sizeOfCL = offeredCourses.getSize();

			// print the header
			cout << endl;
			cout << left << setw(10) << "Code" << setw(40) << "Title"
				<< setw(15) << "# Credits" << setw(15) << "Enrolled"
				<< setw(15) << "Capacity" << endl;

			//print courses characteristics
			for (int i = 0; i < sizeOfCL; i++)
			{
				Course* coursePtr = offeredCourses.getDataAtPos(i);
				cout << left << setw(10) << coursePtr->getCode() << setw(40)
					<< coursePtr->getTitle() << setw(15) << coursePtr->getCredits()
					<< setw(15) << coursePtr->getNumOfStudents()
					<< setw(15) << coursePtr->getCapacity() << endl;
			}
			cout << "\n\n";
			break;

		// 3. Display the list of registered students
		case 3:

			sizeOfStudentList = unregisteredStudents.getSize();

			for (int i = 0; i < sizeOfStudentList; i++)
			{
				Student* studentPtr = unregisteredStudents.getDataAtPos(i);
				if (studentPtr->getSize() != 0)
				{
					studentPtr->displayRegisterdCourses(cout);
					found = true; //student found
				}
			}

			if (!found)
				cout << "\nThere are no registered students.";

			cout << "\n\n";
			break;

		//	4. Display the list of offered courses 
		//		with the registered students
		case 4:
			cout << endl;
			sizeOfCL = offeredCourses.getSize();

			for (int i = 0; i < sizeOfCL; i++)
			{
				offeredCourses.getDataAtPos(i)->
					displayCourseWithRegisteredStudents(cout);
			}
			break;
		
		//5. Display the registered courses for a student
		case 5:
			sizeOfStudentList = unregisteredStudents.getSize();
			cout << "Enter the student ID: ";
			cin >> id;

			for (int i = 0; i < sizeOfStudentList; i++)
			{
				Student* studentPtr = unregisteredStudents.getDataAtPos(i);
				if (studentPtr->getID() == id)
				{
					studentPtr->displayRegisterdCourses(cout);
					found = true;
					break;
				}
			}

			if (!found)
				cout << "Student Not Found.\n\n";
			break;


		//6. Display the list of students registered in a course
		case 6:
			sizeOfCL = offeredCourses.getSize();
			cout << "Enter course code: ";
			cin >> code;

			// for (char &ch : id)
			// {
			//     ch = toupper(ch);
			// }

			// search for the course
			for (int i = 0; i < sizeOfCL; i++)
			{
				Course* coursePtr = offeredCourses.getDataAtPos(i);
				if (coursePtr->getCode() == code)
				{
					coursePtr->displayRegisteredStudents(cout);
					break;
				}
				// missing else that ensure to ouput no found
			}
			break;

		// 7. Display the information related to a specific student
		case 7:
			sizeOfStudentList = unregisteredStudents.getSize();
			cout << "Enter the student ID: ";
			cin >> id;

			// Search for the student
			for (int i = 0; i < sizeOfStudentList; i++)
			{
				Student* studentPtr = unregisteredStudents.getDataAtPos(i);
				if (studentPtr->getID() == id)
				{
					// display student's info
					studentPtr->displayInfo(cout);
					found = true;
					break;
				}
			}

			if (!found)
				cout << "Student Not Found.\n\n";
			break;


		// 8. Register a student
		case 8:

			sizeOfStudentList = unregisteredStudents.getSize();
			cout << "Enter the student ID: ";
			cin >> id;

			// search for a student by his ID
			for (int i = 0; i < sizeOfStudentList; i++)
			{
				Student* studentPtr = unregisteredStudents.getDataAtPos(i);
				if (studentPtr->getID() == id)
				{
					found = true; // student found

					sizeOfCL = offeredCourses.getSize();
					cout << "Enter course code: ";
					cin >> code;

					bool courseFound = false;

					// search for a course by its code
					for (int j = 0; j < sizeOfCL; j++)
					{
						Course* coursePtr = offeredCourses.getDataAtPos(j);
						if (coursePtr->getCode() == code)
						{
							// check if course is full
							if (!coursePtr->isFull())
							{

								// check if student is registered
								if (!coursePtr->isStudentEnrolled
									(studentPtr->getID()))
								{
									coursePtr->registerStudent(*studentPtr);
									studentPtr->registerCourse(*coursePtr);

									cout << "\nStudent registered!\n";
								}
								else
								{
									cout << "\nStudent is already registered.\n";
								}
							}
							else
							{
								cout << "\nCannot register,course is full.\n";
							}

							courseFound = true;
							break;
						}
					}

					if (!courseFound)
						cout << "\nCourse not Found.\n\n";
					break;
				}
			}

			// student not found
			if (!found)
			{
				cout << "\nStudent Not Found.\n\n";
				break;
			}
			break;
		

		// 9. Choose a student to add / drop a course for him / her
		case 9:
			sizeOfStudentList = unregisteredStudents.getSize();
			sizeOfCL = offeredCourses.getSize();

			cout << "Enter the students-ID: ";
			cin >> id;

			// finding the student by his ID
			for (int i = 0; i < sizeOfStudentList; i++)
			{
				Student* studentPtr = unregisteredStudents.getDataAtPos(i);
				if (studentPtr->getID() == id)
				{
					char choiceTOContinue = 'y';

					// while the user is choosing yes
					while (choiceTOContinue == 'Y' || choiceTOContinue == 'y')
					{

						char choiceOfTheUser;

						studentPtr->displayRegisterdCourses(cout);

						cout << "\nAdd course[A]or Drop course[D]:";
						cin >> choiceOfTheUser;

						cout << "\n\n";
						found = true; // studnt found

						// choice to drop a course
						if (choiceOfTheUser == 'D' || choiceOfTheUser == 'd')
						{
							cout << "choose course code : ";
							cin >> code;

							cout << "\n\n";

							// assuming course not found
							bool foundCourse = false; 

							// searching for the course by its code
							for (int j = 0; j < sizeOfCL; j++)
							{
								Course* coursePtr = offeredCourses.getDataAtPos(j);
								if (coursePtr->getCode() == code)
								{
									foundCourse = true;

									// check if the student is enrolled
									if (coursePtr->isStudentEnrolled(studentPtr->getID()))
									{

										coursePtr->removeStudent(*studentPtr);

										studentPtr->dropFromCourse(*coursePtr);

										cout << "Course dropped successfully." << endl;
									}
									else
									{
										cout <<"\nStudent is already not "
											<< "enrolled in the course\n";
									}
									break;
								}
							}

							if (!foundCourse)
							{
								cout << "Course not found." << endl;
							}
						}

						// choice to add course
						else if (choiceOfTheUser == 'A' || choiceOfTheUser == 'a')
						{
							cout << "Enter course code: ";
							cin >> code;
							cout << endl;

							// assuming the course is not found
							bool courseFound = false;
							for (int j = 0; j < sizeOfCL; j++)
							{
								Course* coursePtr = offeredCourses.getDataAtPos(j);

								if (coursePtr->getCode() == code)
								{
									courseFound = true;

									// check if student is enrolled
									if (!coursePtr->isStudentEnrolled
										(studentPtr->getID()))
									{

										// check if the course is full
										if (!coursePtr->isFull())
										{

											coursePtr->registerStudent(*studentPtr);

											studentPtr->registerCourse(*coursePtr);

											cout << "\nStudent registered!\n\n";
										}
										else
										{
											cout << "cannor register,course is full.";
											cout << "\n"
												<< endl;
										}
									}
									else
									{
										cout << "\nStudent is already "
											<< "registered.\n";
									}

									// course was found
									courseFound = true;
									break;
								}
							}

							if (!courseFound)
								cout << "\nCourse not Found.\n\n";
						}
						else
						{
							cout << "Invalid input.";

							// discard input
							cin.ignore(numeric_limits<streamsize>::max(), '\n');
						}

						cout << "Do you want to continue? Y/N: ";
						cin >> choiceTOContinue;
					}
				}
			}
			
			if (!found)
			{
				cout << "Student not found (invalid ID)." << endl;
			}

			cout << "\n";
			break;

		//10. Quit the application
		case 10:
			cout << endl
				<< "You exited the system. Bye Bye ;)\n\n";
			exit(0);

		default:
			cout << "Invalid choice!\n";
		}
	}
}


//--- Definiton of inputOfferedCourses
void inputOfferedCourses(LListWithDummyNode<Course>& offeredCourses)
{
	ifstream inputFile("courses.txt"); // Open the input file

	if (!inputFile)
	{
		cerr << "Error: Unable to open the file courses.txt." << endl;
		return;
	}

	int numCourses;
	inputFile >> numCourses; // Read the number of courses from the file
	inputFile.ignore();		 // Ignore the newline character after numCourses

	for (int i = 0; i < numCourses; ++i)
	{
		string code, title, word;
		int credits, capacity;

		inputFile >> code; // Read the course code

		// Read the title until a non-alphabetical character is encountered
		while (inputFile >> word)
		{
			if (isalpha(word[0]))
			{
				title += (title.empty() ? "" : " ") + word;
			}
			else
			{
				// If a non-alphabetical character is encountered
				// put it back and break the loop
				inputFile.unget();
				break;
			}
		}

		// Read credits and capacity
		inputFile >> credits >> capacity;
		// Create a Course object and add it to the linked list
		Course newCourse(code, title, credits, capacity);
		offeredCourses.addAtEnd(newCourse);
	}
}


//--- Definiton of inputUnregisteredStudents
void inputUnregisteredStudents(DoublyLinkedList<Student>& students)
{
	ifstream inputFile("Students.txt"); // Open the input file

	if (!inputFile)
	{
		cerr << "Error: Unable to open the file courses.txt." << endl;
		return;
	}

	int numCourses;
	inputFile >> numCourses; // Read the number of courses from the file
	inputFile.ignore();		 // Ignore the newline character after numCourses

	for (int i = 0; i < numCourses; ++i)
	{
		string id, firstName, lastName;
		double gpa;

		inputFile >> id >> firstName >> lastName >> gpa;

		// Create a Course object and add it to the linked list
		Student newStudent(id, firstName, lastName, gpa);

		// I think you forgot about the major in the txt file
		// so I put them all in the same major.
		newStudent.setMajor("Computer Science");

		students.insertAtEnd(newStudent);
	}
}
