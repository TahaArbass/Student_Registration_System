/******************************************************************************
 * Student Class Documentation
 *
 * - Student: Default constructor.
 * - Student: Constructor with arguments.
 * - getId: Getter for student's ID.
 * - getFirstName: Getter for the student's first name.
 * - getLastName: Getter for the student's last name.
 * - getGpa: Getter for the student's GPA.
 * - getMajor: Getter for the student's major.
 * - getAcademicStatus: Getter for the student's academic status.
 * - getSize: Getter for the number of registered courses.
 * - setId: Setter for the student's ID.
 * - setFirstName: Setter for the student's first name.
 * - setLastName: Setter for the student's last name.
 * - setGpa: Setter for the student's GPA.
 * - setMajor: Setter for the student's major.
 * - registerCourse: Register the student in a given course.
 * - dropFromCourse: Drop the student from a given course.
 * - displayRegisteredCourses: Display the list of registered
 *                                    courses for the student.
 * - displayStudent: Display detailed information about the student.
 * - displayInfo: Display the student's information with major.
 * - operator==: Check if two students are equal.
 * - friend operator>>: Read user input related to the student object from cin.
 * - friend operator<<: Display a student object.
 * - updateAcademicStatus: Update the student's academic status.
 *****************************************************************************/
#ifndef STUDENT_H
#define STUDENT_H
#include "LListWithDummyNode.h"
#include "Course.h"
#include <string>
#include <iostream>

using namespace std;

// enum for the student's academic result
enum AcademicStatus
{
    REGULAR,
    PROBATION
};

class Course; // forward class course
class Student
{
public:
    /******** Function Members ********/

    /**********class constructor**************/
    Student(const string& studentID,
        const string& firstName,
        const string& lastName, double gpa);
    /*-------------------------------------------------------------------------
Construct a Student object.

Precondition:  studentID is a string of 8 characters starting with 'A' followed
                 by 7 digits, firstName and lastName are non-empty strings, and
                 gpa is a floating-point number in the range [0, 4].

 Postcondition: A Student object is created with the specified studentID,
                 firstName, lastName, and GPA.
----------------------------------------------------------------------------*/

/***** Default Constructor *****/
    Student();
    /*-------------------------------------------------------------------------
  Construct a Student object with default values.

  Precondition:  None.
  Postcondition: An empty Student object is constructed with default values for
                 studentID, firstName, lastName, and GPA.
----------------------------------------------------------------------------*/

/***** Accessors *****/
    string getID() const;
    /*---------------------------------------------------------------------
Retrieve the student's unique identifier (ID).

Precondition:  None.
Postcondition: The student's ID is returned as a string.
----------------------------------------------------------------------------*/
    string getFirstName() const;
    /*------------------------------------------------------------------------
 Retrieve the student's first name.

 Precondition:  None.
 Postcondition: The student's first name is returned as a string.
----------------------------------------------------------------------------*/
    string getLastName() const;
    /*------------------------------------------------------------------------
 Retrieve the student's last name.

 Precondition:  None.
 Postcondition: The student's last name is returned as a string.
----------------------------------------------------------------------------*/
    double getGpa() const;
    /*------------------------------------------------------------------------
 Retrieve the student's grade point average (GPA).

 Precondition:  None.
 Postcondition: The student's GPA is returned as a floating-point number.
----------------------------------------------------------------------------*/
    string getMajor() const;
    /*------------------------------------------------------------------------
  Retrieve the student's major.

  Precondition:  None.
  Postcondition: The student's major is returned as a string.
----------------------------------------------------------------------------*/
    AcademicStatus getAcademicStatus() const;
    /*------------------------------------------------------------------------
  Retrieve the student's academic status.

  Precondition:  None.
  Postcondition: The student's academic status is returned as an
                 AcademicStatus enum value.
----------------------------------------------------------------------------*/
    int getSize() const;
    /*------------------------------------------------------------------------
  Retrieve the size of the student data.

  Precondition:  None.
  Postcondition: The size of the student data is returned as an integer.
----------------------------------------------------------------------------*/

// Mutators*
    void setID(const string& id);
    /*--------------------------------------------------------------------
Set the student's unique identifier (ID).

Precondition:  The 'id' parameter is a string of 8 characters starting
               with 'A' followed by 7 digits.
Postcondition: The student's ID is updated to the specified value.
------------------------------------------------------------------------*/
    void setFirstName(const string& first);
    /*------------------------------------------------------------------------
 Set the student's first name.

 Precondition:  The 'first' parameter is a non-empty string.
 Postcondition: The student's first name is updated to the specified value.
----------------------------------------------------------------------------*/
    void setLastName(const string& last);
    /*-----------------------------------------------------------------------
  Set the student's last name.

  Precondition:  The 'last' parameter is a non-empty string.
  Postcondition: The student's last name is updated to the specified value.
----------------------------------------------------------------------------*/
    void setGpa(const double& gpa);
    /*-----------------------------------------------------------------------
  Set the student's grade point average (GPA).

  Precondition:  The 'gpa' parameter is a double number in the range
                 [0, 4].
  Postcondition: The student's GPA is updated to the specified value.
----------------------------------------------------------------------------*/
    void setMajor(const string& major);
    /*------------------------------------------------------------------------
  Set the student's major.

  Precondition:  The 'major' parameter is a non-empty string.
  Postcondition: The student's major is updated to the specified value.
-----------------------------------------------------------------------------*/

/***** Register Course *****/
    void registerCourse(const Course& Course);
    /*-----------------------------------------------------------------------
  Register the student for a course.

  Precondition:  The 'Course' parameter is a valid Course object.
  Postcondition: The student is registered for the specified course.
----------------------------------------------------------------------------*/

/***** Drop from Course *****/
    void dropFromCourse(const Course& Course);
    /*------------------------------------------------------------------------
  Drop the student from a course.

  Precondition:  The 'Course' parameter is a valid Course object.
  Postcondition: The student is dropped from the specified course.
----------------------------------------------------------------------------*/
/***** Display Registered Courses *****/
    void displayRegisterdCourses(ostream& os);
    /*-------------------------------------------------------------------
Display the list of courses registered by the student.

Precondition:  The 'os' parameter is a valid output stream.
Postcondition: The list of registered courses is displayed on the output
             stream.
---------------------------------------------------------------------------*/

/***** Display Student *****/
    void displayStudent(ostream& os) const;
    /*---------------------------------------------------------------------
Display detailed information about the student.

Precondition:  The 'os' parameter is a valid output stream.
Postcondition: The student's information is displayed on the output stream.
----------------------------------------------------------------------------*/

/***** Display Info *****/
    void displayInfo(ostream& os) const;
    /*-------------------------------------------------------------------------
  Display basic information about the student.

  Precondition:  The 'os' parameter is a valid output stream.
  Postcondition: The student's basic information is displayed on the output
                 stream.
----------------------------------------------------------------------------*/

/***** Equality Operator *****/
    bool operator==(const Student& student);
    /*------------------------------------------------------------------------
  Compare two students for equality.

  Precondition:  The 'student' parameter is a valid Student object.
  Postcondition: Returns true if the students have the same attributes, false
                otherwise.
----------------------------------------------------------------------------*/

/***** Input Stream Operator *****/
    friend istream& operator>>(istream& is, Student& student);
    /*------------------------------------------------------------------------
  Overload the input stream operator to read a Student object from an
    input stream.

  Precondition:  The 'is' parameter is a valid input stream. The 'student'
                 parameter is a valid Student object.
  Postcondition: Reads student data from the input stream and populates the
                                                            'student' object.
----------------------------------------------------------------------------*/

/***** Output Stream Operator *****/
    friend ostream& operator<<(ostream& os, const Student& student);
    /*---------------------------------------------------------------------
Overload the output stream operator to write a Student object to an output
     stream.

Precondition:  The 'os' parameter is a valid output stream. The 'student'
              parameter is a valid Student object.
Postcondition: Writes student information to the output stream.
-----------------------------------------------------------------------------*/

/***** Data Members *****/
private:
    string studentID;                            // ID of the student
    string firstName;                            // first name of the student
    string lastName;                             // last name of the student
    double gpa;                                  // gpa of the student
    string major;                                // major of the student
    AcademicStatus academicStatus;               // student's academic status
    LListWithDummyNode<Course> registerdCourses; // student's registerdCourses

    /***** Update Academic Status *****/
    void updateAcademicStatus();

    /*----------------------------------------------------------------------
Update the student's academic status based on their GPA and other criteria.

Precondition:  This is a private function used internally by the class.
Postcondition: The student's academic status is updated.
----------------------------------------------------------------------------*/
};

#endif // END OF THE HEADER FILE
