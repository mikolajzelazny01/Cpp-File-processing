#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Person {

    private:
        string name;
        string surname;
    public:
        Person(string name, string surname): name(name), surname(surname) {}
        string toString() {
            return name + " " + surname;
        }

        string getName() {
            return name;
        }
        string getSurname() {
            return surname;
        }

        friend ostream& operator<<(ostream& os,Person& person ){
            os << person.name << " " << person.surname;
            return os;
        }

        friend istream& operator>>(istream& is,Person& person){
            is >> person.name >> person.surname;
            return is;
        }

};

class Student: public Person {
    private:
        unsigned int id;
        string faculty;
    public:
        Student(string name, string surname, unsigned int id, string faculty): Person(name, surname), id(id), faculty(faculty) {}
        
        friend ostream& operator<<(ostream& os, Student& student) {
            os << student.toString() << " " << student.id << " " << student.faculty << endl;
            return os; 
        }

      friend istream& operator>>(istream& is, Student& student) {
            string name = student.getName();
            string surname = student.getSurname();
            is >> name >> surname >> student.id >> student.faculty;
            student = Student(name, surname, student.id, student.faculty);
            return is;
        }
 
};

int main()
{

    Person p1("Jan", "Kowalski");
    Person p2("Adam", "nowak");

    ofstream plikWyj("person.txt");
    if (plikWyj) {
        plikWyj << p1;
        plikWyj.close();
        cout << "Data saved to he file" << endl;
    } else { cout << "Data could not be saved" << endl;}

    ifstream plikWej("person.txt");

    if (plikWej) {
        plikWej >> p2;
        plikWej.close();
        cout << "Data read from the file" << endl;
    } else {cout << "Data could not be written" << endl;}

    cout << p2 << endl << endl;

    Student s1("Adam", "Gajda" , 123457, "Mechatronics");
    Student s2("Jan", "Kowalski", 333456, "Chemistry");

    ofstream plikWyj2("student.txt");
    if (plikWyj2) {
        plikWyj2 << s1;
        plikWyj2.close();
        cout << "Data saved to the file" << endl;
    } else { cout << "Data could not be saved" << endl;}

    ifstream plikWej2("student.txt");
    if (plikWej2) {
        plikWej2 >> s2;
        plikWej2.close();
        cout << "Data wread from the file" << endl;
    } else { cout << "Data could not be written" << endl;}

    cout << s2 << endl;

  return 0;
}
