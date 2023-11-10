#include "Course.h"
#include <cctype>
#include <algorithm>
#include <iomanip>

using namespace std;

Course::Course(): Course("undefined", "undefined", 3, 20)
{
}

Course::Course(const string &code,
               const string &title,
               const int &credits, const int &capacity)
{
    setCourse(code, title, credits, capacity);
}

string Course::getCode() const
{
    return this->code;
}

string Course::getTitle()const
{
    return this->title;
}

int Course::getCredits() const
{
    return this->numOfCredits;
}

int Course::getNumOfStudents() const
{
    return registeredStudents.getSize();
}

int Course::getCapacity() const
{
    return this->capacity;
}

void Course::setCode(const string &code)
{
    this->code = code;
    transform(this->code.begin(),
              this->code.end(), this->code.begin(),
              ::toupper);
}
void Course::setTitle(const string &title)
{
    this->title = title;
}
void Course::setCredits(const int &credits)
{
    if (credits < 0)
    {
        this->numOfCredits = 3;
    }
    this->numOfCredits = credits;
}

void Course::setCourse(const string &code, const string &title,
                       const int &credit,
                       const int &capacity)
{
    setTitle(title);
    setCode(code);
    setCredits(credit);
    setCapacity(capacity);
}

void Course::setCapacity(const int &capacity)
{
    if (capacity < 0)
    {
        this->capacity = 20;
    }
    this->capacity = capacity;
}

inline bool Course::isFull() const
{
    return registeredStudents.getSize() >= capacity;
}

bool Course::isStudentEnrolled(const string &studentID)
{
    int size = registeredStudents.getSize();
    for (int i = 0; i < size; i++)
    {
        if (registeredStudents.getDataAtPos(i)->getID() == studentID)
            return true;
    }

    // else not found
    return false;
}

void Course::registerStudent(const Student &student)
{
    registeredStudents.insertAtFirst(student);
}

void Course::removeStudent(const Student &student)
{
    registeredStudents.deleteElement(student);
}

void Course::displayCourse(ostream& os) const
{
    os << left << setw(10) << code << setw(40)
       << title << setw(15) << numOfCredits
       << setw(15) << registeredStudents.getSize()
       << setw(15) << capacity << endl;
    
}

void Course::displayRegisteredStudents(ostream& os){
    if (registeredStudents.isEmpty())
        os << "\nNo Registered Students\n";
    else {
        int size = registeredStudents.getSize();
        for (int i = 0; i < size; i++){
            Student* studentPtr = registeredStudents.getDataAtPos(i);
            os << studentPtr->getID() << " ";
            os << studentPtr->getLastName() << ", ";
            os << studentPtr->getFirstName() << "\n";
        }
    }
    os << "\n\n";
}

// choice 4
void Course::displayCourseWithRegisteredStudents(ostream& os) 
{
    os << "Course: " << code << " - " << title << "\n\n";
    displayRegisteredStudents(os);
}

ostream& operator<<(ostream& os, Course& course)
{
    course.displayCourse(os);
    return os;
}

istream &operator>>(istream &is, Course &course)
{
    cout << "Enter Course Code: ";
    string code;
    is >> code;
    course.setCode(code);

    cout << "Enter Course Title:";
    string title;
    is.ignore(); // Clear the newline character from the buffer
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

bool Course::operator==(const Course &course) const
{
    return code == course.code;
}
