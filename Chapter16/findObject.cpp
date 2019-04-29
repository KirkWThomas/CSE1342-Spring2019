#include <iostream>
#include <algorithm>
#include <list>

using namespace std;

class Student {
  int id;
  char* name;  

public: 
  Student(int id, char* name) {
    this->id = id;
    this->name = name;
  }

  char* getName() {
    return name;
  }

  bool operator==(const Student &student) {
    return this->name == student.name;
  }
};

int main() {
  list<Student> students;

  students.push_back(Student(123, "Erik"));
  
  list<Student>::iterator iter;
  iter = find(students.begin(), students.end(), Student(432, "Erik"));

  if (iter != students.end()) {
    cout << "Student " << iter->getName() << " found" << endl;
  } else {
    cout << "Student not found" << endl;
  }

  return 0;
}