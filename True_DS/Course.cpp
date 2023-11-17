/*-- Course.cpp-----------------------------------------------------------

   This file implements Course member functions.
-------------------------------------------------------------------------*/


#include "Course.h"
#include <cctype>
#include <algorithm>
#include <iomanip>

using namespace std;

//--- Definition of class no arg constructor
Course::Course() : Course("undefined", "undefined", 3, 20)
{
}

//--- Definition of class constructor with arguments
Course::Course(const string& code,
    const string& title,
    const int& credits, const int& capacity)
{
    setCourse(code, title, credits, capacity);
}

//--- Getters
//--Definition of getCode
string Course::getCode() const
{
    return this->code;
}

//--Definition of getTitle
string Course::getTitle() const
{
    return this->title;
}

//--Definition of getCredits
int Course::getCredits() const
{
    return this->numOfCredits;
}

//--Definition of getNumOfStudent
int Course::getNumOfStudents() const
{
    return registeredStudents.getSize();
}

//--Definition of getCapacity
int Course::getCapacity() const
{
    return this->capacity;
}

//---Setters

//--Definition of setCode
void Course::setCode(const string& code)
{
    this->code = code;

    //transforming small letters to upper case
    transform(this->code.begin(),
        this->code.end(), this->code.begin(),
        ::toupper);
}

//--Definition of setTitle
void Course::setTitle(const string& title)
{
    this->title = title;
}

//--Definition of setCredits
void Course::setCredits(const int& credits)
{
    // if the input is <0 , credits are set to thei defualt value
    if (credits < 0)
    {
        this->numOfCredits = 3;
    }
    this->numOfCredits = credits;
}

//--Definition of setCourse
void Course::setCourse(const string& code, const string& title,
    const int& credit,
    const int& capacity)
{
    setTitle(title);
    setCode(code);
    setCredits(credit);
    setCapacity(capacity);
}


//--Definition of setCapacity
void Course::setCapacity(const int& capacity)
{
    // Assuming that the defualt value Course's capacity is 20.
    // if the input is negative
    if (capacity < 0)
    {
        this->capacity = 20;
    }
    this->capacity = capacity;
}

//--Definition of isFull
inline bool Course::isFull() const
{
    return registeredStudents.getSize() >= capacity;
}


//--Definition of isStudentEnrolled
bool Course::isStudentEnrolled(const string& studentID)
{
    // getting the size from the list of registeredStudents
    int size = registeredStudents.getSize();

    // for loop to get each studentID at their indices
    for (int i = 0; i < size; i++)
    {
        // if the student found in the course then he/she is enrolled
        if (registeredStudents.getDataAtPos(i)->getID() == studentID)
            return true;
    }

    // else not found
    return false;
}

//--Definition of registerStudent
void Course::registerStudent(const Student& student)
{
    // making sure that the course is not full
    if (!isFull())
    {
        registeredStudents.insertAtFirst(student);
    }

}


//--Definition of removeStudent 
void Course::removeStudent(const Student& student)
{
    registeredStudents.deleteElement(student);
}


//--Definition of displayCourse 
void Course::displayCourse(ostream& os) const
{
    os << left << setw(10) << code << setw(40)
        << title << setw(15) << numOfCredits
        << setw(15) << registeredStudents.getSize()
        << setw(15) << capacity << endl;
}


//--Definition of displayRegisteredStudents
void Course::displayRegisteredStudents(ostream& os)
{
    // if the list of registered students is empty 
    if (registeredStudents.isEmpty())
        os << "\nNo Registered Students\n";
    else
    {
        // getting the size of registered students
        int size = registeredStudents.getSize();

        //for loop to display students with their attribute
        for (int i = 0; i < size; i++)
        {
            Student* studentPtr = registeredStudents.getDataAtPos(i);
            os << studentPtr->getID() << " ";
            os << studentPtr->getLastName() << ", ";
            os << studentPtr->getFirstName() << "\n";
        }
    }
    os << "\n\n";
}

// choice 4
//--Definition of displayCourseWithRegisteredStudents
void Course::displayCourseWithRegisteredStudents(ostream& os)
{
    os << "Course: " << code << " - " << title << "\n\n";
    displayRegisteredStudents(os);
}

//--Definition of << operator
ostream& operator<<(ostream& os, Course& course)
{
    course.displayCourse(os);
    return os;
}

//--Definition of >> operator
istream& operator>>(istream& is, Course& course)
{
    cout << "Enter Course Code: ";
    string code;
    is >> code;
    course.setCode(code);

    cout << "Enter Course Title:";
    string title;
    is.ignore();
    getline(is, title);
    course.setTitle(title);

    cout << "Enter Course's Number Of Credits:";
    int numOfCredits;
    is >> numOfCredits;
    course.setCredits(numOfCredits);

    cout << "Enter Course's Capacity:";
    int capacity;
    is >> capacity;
    course.setCapacity(capacity);

    return is;
}

//Definition of overloaded operator==
// comparing by the course's code
bool Course::operator==(const Course& course) const
{
    return code == course.code;
}
