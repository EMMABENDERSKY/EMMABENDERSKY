#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>

using namespace std;

class Student
{
 public:
  Student(char*, char*, int, double);
  char* getFirstName();
  char* getLastName();
  int getID();
  double getGPA();
  
 private:
  char* firstName;
  char* lastName;
  int ID;
  double GPA;
};
#endif
