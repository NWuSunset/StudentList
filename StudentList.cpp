#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

struct Student {
  char firstName[10];
  char lastName[10];
  int id;
  float gpa;
};

//Methods initizalized here 
bool userSelection(vector<Student*> &);
void Add(vector<Student*> &);
void Print(vector<Student*> &);
void Delete(vector<Student*> &);
void setLowerCase(char cstring[]);

int main() {
  vector<Student*> stuVec; //vector of student pointers 

  //Test student
  Student* bob = new Student; //Makes a student pointer 'bob' that points to a new Student object 
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

 
  //Keep looping till the user inputs quit command
  while (!userSelection(stuVec)); 
  
  return 0;
}


//Menu where user selects what they want to do.
bool userSelection(vector<Student*> &stuVec) {
  bool validIn = false;
  while (!validIn) {
    char input[7]; 
    char usrChoice;
    cout << "Create (c), Print out (p), or Delete (d) a student. Quit (q)" << endl;
    
    cin.get(input, 7);
    setLowerCase(input); //set the letters to lowercase
    cin.ignore();
    //Checks which input the user did.
    if (strcmp(input, "create") == 0 || strcmp(input, "c") == 0) {
      cout << "creates" << endl;
      validIn = true;
      Add(stuVec);
    } else if (strcmp(input, "print") == 0 || strcmp(input, "p") == 0) {
      cout << "pritns" << endl;
      Print(stuVec);
      validIn = true;
    } else if (strcmp(input, "delete") == 0 || strcmp(input, "d") == 0) {
      cout << "deltes" << endl;
      Delete(stuVec);
      validIn = true;
    } else if (strcmp(input, "quit") == 0 || strcmp(input, "q") == 0) {
      return true;
    } else {
      cout << "invalid input" << endl;
    }
    //return true;
  }
  return false; 
}

//Adds a new student to the list, user assigns student data.
void Add(vector<Student*> &stuVec) {
  cout << "not implimented" << endl;
  Student* anon = new Student; //create a new student pointer
  cout << "Student first name: " << endl;
  cin.get(anon->firstName, 10);
  cin.get();
  cout << "Student last name: " << endl;
  cin.get(anon->lastName, 10);
  cin.get();
  cout << "Student id: " << endl;
  cin >> anon->id;
  cin.ignore();
  cout << "Student gpa: " << endl;
  cin >> anon->gpa;
  cin.ignore();
  stuVec.push_back(anon); //add it to the vector
}

//Prints out all of the currently stored student data.
void Print(vector<Student*> &stuVec) { //pass in the the vector of student pointers (list of pointers to students)
  if (stuVec.empty()) {
    cout << "There are no students" << endl;
  } else {
  //The iterator 'it' is a pointer to Student*, and Student* points to the Student objects 
  for (vector<Student*>::iterator it = stuVec.begin(); it != stuVec.end(); it++) {
    //print out the information for a student.
    cout.setf(ios::showpoint); //show zeros in the decimal places
    cout.precision(3); //to 2 decimal places
    cout << (*it)->firstName << " " << (*it)->lastName << ", " << (*it)->id << ", " << (*it)->gpa << endl;
  }
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
      //it = stuVec.end(); //break out of loop (without a break statement)
      break;
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

//Pass in an array by reference, to change all contents to lowercase
 void setLowerCase(char cstring[]) {
   for (int i = 0; i != '\0'; i++) { //loop until null character (end of cstring)
     cstring[i] = tolower(cstring[i]); //set the char here to lowercase  
   }
 }

