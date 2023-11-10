//
// Created by User on 10/31/2023.
//

#ifndef STUDENT_H
#define STUDENT_H
#include "LListWithDummyNode.h"
#include "Course.h"
#include <string>
#include <iostream>

using namespace std;

/**
 * class Student
 *
 * Represents a student with their academic details.
 *
 * This class provides functionalities to set and get details of a student.
 * It encapsulates details such as student ID, first name, last name, gpa,
 * and academic status.
 *
 * Constructors:
 *  - A default constructor that initializes all fields with default values.
 *  - Constructors that accept various combinations of student details.
 *  - A copy constructor to create a student object based on another student object.
 *
 * Accessors:
 *  - Get methods for ID, first name, last name, gpa, and academic status.
 *
 * Mutators:
 *  - Set methods for ID, first name, last name, and gpa. Setting the gpa also updates
 *    the academic status accordingly.
 *
 * Other Methods:
 *  - A  private method to update the academic status based on current gpa.
 *  - A method to return a string representation of the student's details.
 *
 * Note: The gpa is constrained between [0.0, 4.0]. The academic status is "Regular" if
 *       gpa >= 2.0 or "Probation" if gpa < 2.0.
 */
enum AcademicStatus { REGULAR, PROBATION };

class Course;
class Student
{
public:

    Student(const string &studentID, const string &firstName, const string &lastName, double gpa);
    Student();

    string getID() const;
    string getFirstName() const;
    string getLastName() const;
    double getGpa() const;
    string getMajor()const;
    AcademicStatus getAcademicStatus() const;
    int getSize()const;

    void setID(const string &id);
    void setFirstName(const string &first);
    void setLastName(const string &last);
    void setGpa(const double &gpa);
    void setMajor(const string& major);

    void registerCourse(const Course &Course);
    void dropFromCourse(const Course &Course);

    void displayRegisterdCourses(ostream& os);
    void displayStudent(ostream& os) const;
    void displayInfo(ostream& os)const;

    bool operator==(const Student &student);
    friend istream &operator>>(istream &is,Student &student);
    friend ostream &operator<<(ostream &os, const Student &student);

private:
    string studentID;
    string firstName;
    string lastName;
    double gpa;
    string major;
    AcademicStatus academicStatus;
    LListWithDummyNode<Course> registerdCourses;

    void updateAcademicStatus();
};

#endif
