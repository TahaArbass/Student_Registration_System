/*-- Student.cpp-----------------------------------------------------------

   This file implements Student member functions.
-------------------------------------------------------------------------*/

#include "Student.h"
#include <iomanip>

using namespace std;

//--- Definition of class constructor with arguments
Student::Student(const string& studentID,
    const string& firstName,
    const string& lastName,
    double gpa)
{
    setID(studentID);
    setFirstName(firstName);
    setLastName(lastName);
    setGpa(gpa);
}
//--- Definition of class no arg constructor
Student::Student()
    : studentID("undefined"),
    firstName("undefined"),
    lastName("undefined"),
    gpa(0)
{
    updateAcademicStatus();
}

//--- Getters
//
//--- Definition of getID
string Student::getID() const
{
    return studentID;
}

//--- Definition of getFirstName
string Student::getFirstName() const
{
    return firstName;
}

//--- Definition of getLasttName
string Student::getLastName() const
{
    return lastName;
}

//--- Definition of getGpa
double Student::getGpa() const
{
    return gpa;
}

//--- Definition of getMajor
string Student::getMajor() const
{
    return major;
}

//--- Definition of getAcademicStatus
AcademicStatus Student::getAcademicStatus() const
{
    return academicStatus;
}

//--- Definition of getSize
int Student::getSize() const
{
    return registerdCoursesIDs.getSize();
}

//---Setters

//--- Definition of setID
void Student::setID(const string& id)
{
    this->studentID = id;
}

//--- Definition of setFirstName
void Student::setFirstName(const string& first)
{
    this->firstName = first;
}

//--- Definition of setLastName
void Student::setLastName(const string& last)
{
    this->lastName = last;
}

//--- Definition of setGpa
void Student::setGpa(const double& gpa)
{
    if (gpa < 0.0)
    {
        this->gpa = 0.0;
    }
    else if (gpa > 4.0)
    {
        this->gpa = 4.0;
    }
    else
    {
        this->gpa = gpa;
    }
    updateAcademicStatus();
}

//--- Definition of setMajor
void Student::setMajor(const string& major)
{
    this->major = major;
}

//--- Definition of UpdateAcademicStatus
void Student::updateAcademicStatus()
{
    if (gpa < 2.0)
    {
        academicStatus = PROBATION;
    }
    else
    {
        academicStatus = REGULAR;
    }
}

//--- Definition of registerCourse
void Student::registerCourse(const Course& course)
{
    registerdCoursesIDs.addAtBeg(course.getCode());
}

//--- Definition of dropFromCourse
void Student::dropFromCourse(const Course& course)
{
    registerdCoursesIDs.deleteElement(course.getCode());
}

//--- Definition of displayStudent
void Student::displayStudent(ostream& os) const
{
    string fullName = lastName + ", " + firstName;
    os << left << setw(12) << studentID
        << setw(25) << fullName
        << setw(6) << fixed << setprecision(1) << gpa
        << setw(15) << (getAcademicStatus() == 0 ? "Regular" : "Probation")
        << endl;
}

//--- Definition of displayInfo
//--- the only difference that I am mentioning the major (diff format)
void Student::displayInfo(ostream& os) const
{
    os << "\nStudent: \n"
        << "\tID: " << studentID << "\n"
        << "\tName: " << firstName << " " << lastName << "\n"
        << "\tMajor: " << major << "\n"
        << "\tGPA: " << gpa << " \n\n";
}

//--- Definition of displayRegisterdCourses
//--- choice 5
void Student::displayRegisterdCourses(ostream& os)
{
    os << "\nStudent: " << studentID << " - " << firstName << " " << lastName
        << "\n\nCourses:\n\n";

    int size = registerdCoursesIDs.getSize();

    // list empty
    if (size == 0)
    {
        os << "No Registered Courses\n\n";
        return;
    }

    for (int i = 0; i < size; i++)
    {
        os << "-   " << registerdCoursesIDs.getDataAtPos(i) << "\n";
    }
}

//--- Definition of overloaded operator ==
//--- we compare students by their IDs
bool Student::operator==(const string& studentID)
{
    return this->studentID == studentID;
}

//--- Definition of overloaded operator >>
istream& operator>>(istream& is, Student& student)
{
    getline(is, student.studentID);
    getline(is, student.firstName);
    getline(is, student.lastName);
    is >> student.gpa;
    return is;
}

//--- Definition of overloaded operator <<
ostream& operator<<(ostream& os, const Student& student)
{
    student.displayStudent(os);
    return os;
}
