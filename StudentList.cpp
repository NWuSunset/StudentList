#include <iostream>
#include <vector>

using namespace std;

/*
  Create a struct.  It will have a first name (character array), a last name (character array), a number for the student id (int), and decimal for GPA (float).

 

Your program should have a vector of struct pointers passed by reference, or a vector pointer (which will point to a vector of struct pointers). (20 points)

 

Your program will allow you to read in students, print them out, and delete them.  Each of these functions should be in a different method.

 

When you type in: ADD

You should create a new entry for a student.  After you type in add, the program should prompt for first name, last name, student id, and GPA.  That student should then be added to the vector of students (well, student pointers!). (20 points)


When you type in: PRINT

Your program should print out all the students currently stored.  For example:

 

Jason Galbraith, 487329, 5.00

John Elstad, 903826, 3.25

Kevin Jin, 468921, 0.12

 

The GPA should be shown to two decimal places. I recommend looking up how iterators work; regular for loops do not work with vectors. (20 points)

 

When you type in: DELETE

Prompt the user for the student id number to delete, and remove that struct from the vector. Be sure to delete the data. (20 points)

 

By the way, your program should finish with a "QUIT" command.
 */

//pointers with star point to the value
//Without star points to spot in memory

void Add(vector<Student*> &);
void Print(vector<Student*> &);
void Delete(vector<Student*> &);


struct Student {
  char firstName[10];
  char lastName[10];
  int id;
  float gpa;
}; 

int main() {
  cout << "test" << endl;
  vector<Student*> stuVec; //vector of student pointers 
  char usrChoice[7];
  cout << "Create, Print out, or Delete a student" << endl;
  cin.get(usrChoice, 7);
  cin.get();

  
  if (usrChoice == "create") {
    cout << "creates" << endl;
    Add(stuVec); 
  } else if (usrChoice == "print") {
    cout << "pritns" << endl;
    Print();
  } else if (usrChoice == "delete") {
    cout << "deltes" << endl;
    Delete();
  } else {
    cout << "invalid input" << endl;
  }
  
  
  
  return 0;
}

void Add(vector<Student*> &stuVec) {
  
}

void Print(vector<Student*> &stuVec) { //pass in the the vector of student pointers (list of pointers to students) 
  for (vector<Student*>::iterator it = 
}

void Delete(vector<Student*> &stuVec) {

}
