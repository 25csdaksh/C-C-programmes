#include <iostream>
using namespace std;

int main() {
    cout << "--------------WELCOME TO HDFC BANK---------------" << endl;

    int age, count = 0;
    char gender, choice;

    do {
        cout << "\nWanna continue further (y/n): ";
        cin >> choice;

        if (choice == 'y' || choice == 'Y') {
            cout << "Kindly enter your age: ";
            cin >> age;

            if (age < 0) {
                cout << "\nInvalid Age, Kindly enter valid age." << endl;
                continue; // restart loop
            }

            cout << "\nEnter customer gender:" << endl;
            cout << "Enter 'm' for male gender:" << endl;
            cout << "Enter 'f' for female gender:" << endl;
            cin >> gender;

            if (age < 18 && gender == 'm') {
                cout << "\nSorry Sir, You are underage for opening an account" << endl;
                cout << "You are eligible once you complete 18 years" << endl;
                cout << "\t***THANK YOU***" << endl;
            } else if (age < 18 && gender == 'f') {
                cout << "\nSorry Ma'am, You are underage for opening an account" << endl;
                cout << "You are eligible once you complete 18 years" << endl;
                cout << "\t***THANK YOU***" << endl;
            } else if (age >= 18 && gender == 'm' && age < 60) {
                cout << "\nWelcome Sir to our Bank for registration for regular saving account" << endl;
                cout << "Kindly fill the bank slip for the further procedure" << endl;
                cout << "\t***THANK YOU***" << endl;
                count++;
            } else if (age >= 18 && gender == 'f' && age < 60) {
                cout << "\nWelcome Ma'am to our Bank for registration for regular saving account" << endl;
                cout << "Kindly fill the bank slip for the further procedure" << endl;
                cout << "\t***THANK YOU***" << endl;
                count++;
            } else {
                cout << "\nWelcome To Our Bank for registration for senior citizen account" << endl;
                cout << "\t***THANK YOU***" << endl;
                count++;
            }
        }

    } while (choice == 'y' || choice == 'Y');

    cout << "\nTotal number of customers registered today are: " << count << endl;

    return 0;
}
