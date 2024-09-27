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


struct Student {
  char firstName[10];
  char lastName[10];
  int id;
  float gpa;
};

void Add(vector<Student*> &);
void Print(vector<Student*> &);
void Delete(vector<Student*> &);


int main() {
  cout << "test" << endl;
  vector<Student*> stuVec; //vector of student pointers 

  //Test student
  Student* bob = new Student; //to make a student point you have to make a new one in the heap? So bob is a pointer to a student object
  bob->firstName[0] = 'b'; //now use -> operator to get the structure member with a pointer
 bob->firstName[1] = 'o';
 bob->firstName[2] = 'b';
 bob->firstName[3] = '\0';
 bob->lastName[0] = 'o';
 bob->lastName[1] = 'n';
 bob->lastName[2] = 'e';
 bob->lastName[3] = '\0';
 bob->id = 1234;
 bob->gpa = 4.00;

 stuVec.push_back(bob);
 
 Print(stuVec);

  bool validIn = false;
  while (!validIn) {

 char usrChoice;
  cout << "Create (c), Print out (p), or Delete (d) a student" << endl;
  cin >> usrChoice;
  //cin.get(usrChoice, 7);
  //cin.get();

  if (usrChoice == 'c') {
    cout << "creates" << endl;
    validIn = true;
    Add(stuVec); 
  } else if (usrChoice == 'p') {
    cout << "pritns" << endl;
    Print(stuVec);
    validIn = true;
  } else if (usrChoice == 'd') {
    cout << "deltes" << endl;
    Delete(stuVec);
    validIn = true;
  } else {
    cout << "invalid input" << endl;
    }
  } 
  
  
  return 0;
}

void Add(vector<Student*> &stuVec) {
  cout << "not implimented" << endl;
  //Student* anon = new Student; 
  
  cout << "Student first name: " << endl;
    
}

//Prints out all of the currently stored student data.
void Print(vector<Student*> &stuVec) { //pass in the the vector of student pointers (list of pointers to students)
  //The iterator 'it' is a pointer to Student*, and Student* points to the Student objects 
  for (vector<Student*>::iterator it = stuVec.begin(); it != stuVec.end(); it++) {
    //print out the information for a student.
    cout.setf(ios::showpoint); //show zeros in the decimal places
    cout.precision(3); //to 2 decimal places
    cout << (*it)->firstName << " " << (*it)->lastName << ", " << (*it)->id << ", " << (*it)->gpa << endl;
  }
}

void Delete(vector<Student*> &stuVec) {
  int idIn = 0;
  int idIndex = -1;
  bool isId = false;
  //prompt for which to delete

  while (!isId) {
  cout << "Enter the id of the student you want to remove" << endl;
  cin >> idIn;
  //loop through the student list
  for (vector<Student*>::iterator it = stuVec.begin(); it != stuVec.end(); it++) {
    if ((*it)->id == idIn) { //if id match
      isId = true;
      idIndex = it - stuVec.begin(); //store the index of where that id is (so we can use it outside the loop)
      it = stuVec.end(); //break out of loop (without a break statement)
    }
  }
  if (!isId) { cout << "Invalid Id, try again" << endl; }
  }

  cout << "Are you sure you want to delete that student? (y/n)" << endl;
  char choice;
  cin >> choice;
  if (choice == 'y') {
  delete(stuVec.at(idIndex));
  stuVec.erase(stuVec.begin() + idIndex);
  } 
}
