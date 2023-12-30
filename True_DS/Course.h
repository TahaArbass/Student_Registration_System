/******************************************************************************
 * Implementation of Course class:
 *
 * Course: defualt constructor.
 * Course: with-arg constructor.
 * getCode: getter of the Course's Code.
 * getTitle: getter of the Course's Title.
 * getCredits: getter of the Course's credit.
 * getNumOfStudents: getter of the Course's Credits.
 * getCapacity: getter of the Course's Capacity.
 * setCode: setter of the Course Code.
 * setTitle: setter of the Course Title.
 * setCredits: setter of the Course Credits.
 * setCapacity: setter of the Course Capacity.
 * setCourse: setter of the Course.
 * registerStudent: enroll the student in the course.
 * removeStudent: drop the student from the course.
 * displayCourse: display the course.
 * displayTheCourseWithRegisteredStudents:
 * display a given course with its students enrolled.
 * displatRegisteredStudents: display the students registred in the course.
 * isFull:                  check if the course is full.
 * isStudentEnrolled:        check wether the student enrolled in the
 *                             course or not.
 * friend operator<<: display the course object.
 * friend operator>>: uses cin to get user input related to the course.
 * operator==: check two course if they are equal.
 * ****************************************************************************
 * */

#ifndef COURSE_H
#define COURSE_H

#include <iostream>
#include <string>
#include "DoublyLinkedList.h"
#include "Student.h"

using namespace std;
class Student; // forward class student
class Course
{

public:
    /******** Function Members ********/

    /***** class constructor *****/
    Course(const string& code,
        const string& title,
        const int& credits, const int& capacity);

    /*-------------------------------------------------------------------------
      Construct a Course object with the given parameters.

      Precondition:  The 'code' parameter is a valid course code,
      the 'title' is a non-empty title for the course,
                     'credits' is a positive integer,
                     and 'capacity' is a positive integer representing
                      the course capacity.
      Postcondition: A Course object is created with the specified code,
                     title, credits,and capacity.
    -------------------------------------------------------------------------*/

    Course();
    /*-------------------------------------------------------------------------
  Construct a Course object with default values.

  Precondition:  None.
  Postcondition: An empty Course object is constructed with default values for
                code,title, credits, and capacity.
  ----------------------------------------------------------------------------*/

  /***** Accessors *****/

  /***** Set Course Title *****/
    string getCode() const;
    /*-------------------------------------------------------------------------
  Retrieve the code of the course.

  Precondition:  None.
  Postcondition: The course code is returned as a string.
  ----------------------------------------------------------------------------*/

  /***** Get Course Title *****/
    string getTitle() const;
    /*-------------------------------------------------------------------------
  Retrieve the title of the course.

  Precondition:  None.
  Postcondition: The course title is returned as a string.
  ----------------------------------------------------------------------------*/

  /***** Get Course Credits *****/
    int getCredits() const;
    /*---------------------------------------------------------------------------
    Retrieve the number of credits for the course.

    Precondition:  None.
    Postcondition: The number of course credits is returned as an integer.
  ----------------------------------------------------------------------------*/

  /***** Get Number of Enrolled Students *****/
    int getNumOfStudents() const;
    /*---------------------------------------------------------------------------
    Retrieve the number of students currently enrolled in the course.

    Precondition:  None.
    Postcondition: The number of enrolled students is returned as an integer.
  ----------------------------------------------------------------------------*/

  /***** Get Course Capacity *****/
    int getCapacity() const;
    /*---------------------------------------------------------------------------
    Retrieve the maximum capacity of the course.

    Precondition:  None.
    Postcondition: The course capacity is returned as an integer.
  ----------------------------------------------------------------------------*/

  /***** Accessors *****/

  /***** Set Course Title *****/
    void setCode(const string& code);
    /*-----------------------------------------------------------------------
    Set the code of the course.

    Precondition:  The 'code' parameter is a valid course code.
    Postcondition: The course code is updated to the specified value.
  ------------------------------------------------------------------------*/

  /***** Set Course Title *****/
    void setTitle(const string& title);
    /*-----------------------------------------------------------------------
    Set the title of the course.

    Precondition:  The 'title' parameter is a non-empty title for the course.
    Postcondition: The course title is updated to the specified value.
  ------------------------------------------------------------------------*/

  /***** Set Course Credits *****/
    void setCredits(const int& credits);
    /*-----------------------------------------------------------------------
    Set the number of credits for the course.

    Precondition:  The 'credits' parameter is a positive integer.
    Postcondition: The number of course credits is updated
                     to the specified value.
  ------------------------------------------------------------------------*/

  /***** Set Course Capacity *****/
    void setCapacity(const int& capacity);
    /*-----------------------------------------------------------------------
    Set the maximum capacity of the course.

    Precondition:  The 'capacity' parameter is a positive integer.
    Postcondition: The course capacity is updated to the specified value.
  ------------------------------------------------------------------------*/

  /***** Set Course *****/
    void setCourse(const string& code,
        const string& title,
        const int& credit,
        const int& capcity);
    /*-----------------------------------------------------------------------
    Set the course with the given parameters.

    Precondition:            The 'code' is a valid course code,
                                  'title' is a non-empty title,
                                'credit' is a positive integer,
                           and 'capacity' is a positive integer
                              representing the course capacity.
    Postcondition: The course is updated with the specified code,
                       title, credits, and capacity.
  ------------------------------------------------------------------------*/

  /***** Register Student *****/
    void registerStudent(const Student& student);
    /*-----------------------------------------------------------------------
    Register a student for the course.

    Precondition:  The 'student' parameter represents a valid Student object.
    Postcondition: The student is registered for the course.
  ------------------------------------------------------------------------*/

  /***** Remove Student *****/
    void removeStudent(const Student& student);
    /*-----------------------------------------------------------------------
      Remove a student from the course.

      Precondition:  The 'student' parameter represents a valid Student object.
      Postcondition: The student is removed from the course.
    ------------------------------------------------------------------------*/

    /***** Display Course *****/
    void displayCourse(ostream& os) const;
    /*---------------------------------------------------------------------------
    Display basic information about the course.

    Precondition:  The 'os' parameter is a valid output stream.
    Postcondition: Basic course information is displayed on the output stream.
  ----------------------------------------------------------------------------*/

  /***** Display Course with Registered Students *****/
    void displayCourseWithRegisteredStudents(ostream& os);
    /*---------------------------------------------------------------------------
    Display course information along with the list of registered students.

    Precondition:  The 'os' parameter is a valid output stream.
    Postcondition: Course information and the list of registered students
              are displayed on the output stream.
  ----------------------------------------------------------------------------*/

  /***** Display Registered Students *****/
  // void displayRegisteredStudents(ostream &os);
  /*---------------------------------------------------------------------------
  Display the list of students registered for the course.

  Precondition:  The 'os' parameter is a valid output stream.
  Postcondition: The list of registered students is displayed
                  on the output stream.
----------------------------------------------------------------------------*/

/***** Check if Course is Full *****/
    bool isFull() const;
    /*-----------------------------------------------------------------------
    Check if the course has reached its maximum capacity.

    Precondition:  None.
    Postcondition: Returns true if the course is at full capacity,
                   false otherwise.
  ------------------------------------------------------------------------*/

  /***** Check if Student is Enrolled *****/
    bool isStudentEnrolled(const string& studentID);
    /*---------------------------------------------------------------------------
    Check if a student with the given ID is enrolled in the course.

    Precondition:  The 'studentID' parameter is a valid(a string of 8 characters
     starting with 'A'followed by 7 digits) student ID.
    Postcondition: Returns true if a student with the specified ID is enrolled in
                   the course, false otherwise.
  ----------------------------------------------------------------------------*/

  /***** Friend Output Stream Operator *****/
    friend ostream& operator<<(ostream& os, Course& course);
    /*---------------------------------------------------------------------------
    Overload the output stream operator to write course information
                                                to an output stream.

    Precondition:  The 'os' parameter is a valid output stream. The 'course'
                   parameter is a valid Course object.
    Postcondition: Course information is written to the output stream.
  ----------------------------------------------------------------------------*/

  /***** Friend Input Stream Operator *****/
    friend istream& operator>>(istream& is, const Course& course);
    /*---------------------------------------------------------------------------
    Overload the input stream operator to read course information from
                                                               an input stream.

    Precondition:  The 'is' parameter is a valid input stream. The 'course'
                   parameter is a valid Course object.
    Postcondition: Reads course information from the input stream and populates
                   the 'course' object.
  ----------------------------------------------------------------------------*/

  /***** Equality Operator *****/
    bool operator==(const string& courseId);

    /*---------------------------------------------------------------------------
    Compare two courses for equality.

    Precondition:  The 'course' parameter is a valid Course object.
    Postcondition: Returns true if the courses have the same attributes,
                                                         false otherwise.
  ----------------------------------------------------------------------------*/

private:
    string code;                                 // code of the course
    string title;                                // title of the course
    int numOfCredits;                            // credits number of the course
    int capacity;                                // capacity of the course
    DoublyLinkedList<string> registerStudentIDs; /**Course's list of registered
                                                               students*/
};

#endif // END OF THE HEADER FILE