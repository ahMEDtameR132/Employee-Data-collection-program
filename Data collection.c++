#include <iostream>
#include <string>
#include <fstream>
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
        cout << "======================" << i + 1 << endl;
        cout << "Enter data for person " << i + 1 << endl;
        cout << "======================\n";
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

    // Display data in a table
    cout << "\nData for 5 people:\n";
    cout << "--------------------------------------\n";
    cout << "Name\tAge\tJob\tBlood Type\n";
    cout << "--------------------------------------\n";
    for (const Person& p : people) {
        cout << p.name << "\t" << p.age << "\t" << p.job << "\t" << p.bloodType << endl;
    }

    // Write data to file
    ofstream outfile("data.txt");
    if (!outfile.is_open()) {
        cerr << "Error: Could not open file for writing!" << endl;
        return 1;
    }

    for (const Person& p : people) {
        outfile << p.name << "," << p.age << "," << p.job << "," << p.bloodType << endl;
    }
    outfile.close();

    // Read data from file
    ifstream infile("data.txt");
    if (!infile.is_open()) {
        cerr << "Error: Could not open file for reading!" << endl;
        return 1;
    }

    cout << "\nData from file:\n";
    while (infile >> person.name >> person.age >> person.job >> person.bloodType) {
        cout << person.name << "\t" << person.age << "\t" << person.job << "\t" << person.bloodType << endl;
    }
    infile.close();

    return 0;
}