#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Person {
  public: 
    string name;
    string phoneNumber;
    int age;

    Person(string name, string phoneNumber, int age) {
      this->name = name;
      this->phoneNumber = phoneNumber;
      this->age = age;
    }

    virtual void print() {
      cout << "Name: " << name << endl; 
    }
};

class Student: public Person {
  public: 
    int studentId;

    // calls base class constructor 
    Student(int studentId, string name, string phoneNumber, int age): Person(name, phoneNumber, age) {
      this->studentId = studentId;
    }

    void print() {
      Person::print();
      cout << "StudentId: " << studentId << endl;
    }
};

class Professor: public Person {
  public:
    int facultyId;

    // calls base class constructor 
    Professor(int facultyId, string name, string phoneNumber, int age): Person(name, phoneNumber, age) {
      this->facultyId = facultyId;
    }

    void print() {
      Person::print();
      cout << "FacultyId: " << facultyId << endl;
    }
};

int main() {
  Person *person = new Person("Person", "--", 20);
  Student *student = new Student(321, "Student", "--", 19);;
  Professor *professor = new Professor(123, "Professor", "--", 40);

  vector<Person*> people;
  people.push_back(person);
  people.push_back(student);
  people.push_back(professor);

  string data;
  data.stoi();

  for (int i = 0; i < people.size(); i++) {
    people.at(i)->print();
    cout << endl;
  }

  return 0;
}