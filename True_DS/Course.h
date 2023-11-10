/************************************************************
 * Implementation of Course class:
 *
 * Course(code, title, credits, capacity): with-arg constructor
 * getCode() const: getter of the Course's Code
 * getTitle() const: getter of the Course's Title
 * getCredits() const: getter of the Course's Credits
 * getEnrolled() const: getter of the Course's Enrolled
 * getCapacity() const: getter of the Course's Capacity
 * setCode(): setter of the Course Code
 * setTitle(): setter of the Course Title
 * setCredits(): setter of the Course Credits
 * setCapacity(): setter of the Course Capacity
 * setStudentEnrolled(): setter of the Course Enrolled
 * setCourse(): setter of the Course
 * isFull(): check if the Course is full
 * friend operator<<(): display the details of the course
 * ***********************************************************
 * */

#ifndef COURSE_H
#define COURSE_H

#include <iostream>
#include <string>
#include "DoublyLinkedList.h"
#include "Student.h"

using namespace std;
class Student;
class Course
{

private:
    string code;      // code of the course
    string title;     // title of the course
    int numOfCredits; // credits number of the course
    int capacity;     // capacity of the course
    DoublyLinkedList<Student> registeredStudents;

public:
    Course();
    // with-arg constructor
    Course(const string &code,
           const string &title,
           const int &credits, const int &capacity);

    string getCode() const;
    string getTitle() const;
    int getCredits() const;
    int getNumOfStudents() const;
    int getCapacity() const;

    void setCode(const string &code);
    void setTitle(const string &title);
    void setCredits(const int &credits);
    void setCapacity(const int &capacity);
    void setCourse(const string &code,
                   const string &title,
                   const int &credit,
                   const int &capcity);

    void registerStudent(const Student &student);
    void removeStudent(const Student &student);

    void displayCourse(ostream& os) const;
    void displayCourseWithRegisteredStudents(ostream& os) ;
    void displayRegisteredStudents(ostream& os);

    bool isFull() const;

    bool isStudentEnrolled(const string &studentID);

    friend ostream &operator<<(ostream &os, Course &course);
    friend istream &operator>>(istream &is, const Course &course);
    bool operator==(const Course &course) const;
};

#endif