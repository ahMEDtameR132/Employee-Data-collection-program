#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Person {
    string name;
    int age;
    string job;
    string bloodType;
};

int main() {
    vector<Person> people;
    Person person;

    for (int i = 0; i < 5; ++i) {
        cout << "Enter data for person " << i + 1 << endl;
        cout << "Name: ";
        cin >> person.name;
        cout << "Age: ";
        cin >> person.age;
        cout << "Job: ";
        cin >> person.job;
        cout << "Blood type: ";
        cin >> person.bloodType;

        people.push_back(person);
    }

    // عرض البيانات في جدول
    cout << "\nData for 5 people:\n";
    cout << "--------------------\n";
    cout << "Name\tAge\tJob\tBlood Type\n";
    cout << "--------------------\n";
    for (const Person& p : people) {
        cout << p.name << "\t" << p.age << "\t" << p.job << "\t" << p.bloodType << endl;
    }

    return 0;
}