// tutorial 9.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <sstream>
#include <vector>
#include <iomanip>
#include "conio.h"

using namespace std;

class bankacc {
public:
    string name;
    double balance;
    bankacc(const string x, double y) {
        name = x;
        balance = y;
    }

    void deposit(double x) {
        balance = balance + x;
    }

    void withdraw(double x) {

        if ((balance - x) >= 0) {
            balance = balance - x;
        }
        else {
            cout << "invalid withdrawal; returning to menu\n\n";

            cout << "Returning to Menu: " << endl;
            for (int i = 1; i <= 5; i++){
                cout << i << ", " << endl;
                system("sleep 1");
            }
        }
    }

    void remove() {
        name = "";
        balance = 0;
}
};

void menu() {
    cout << "Select option\n\nN - New account\nW - Withdrawal \nD - Deposit\nB - Balance \nQ - Quit \nX - Delete Account\n\n";
}


int main()
{

    vector<bankacc> accounts;
    bankacc(" ", 0);
    int index(-1);
    string accname;
    double money;
    char sel;


    for (;;) {
        system("clear");
        menu();

        cin >> sel;

        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        //NEW ACCOUNT
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        if (toupper(sel) == 'N') {

            system("clear");
            cout << "Enter name for Account: ";
            cin >> accname;
            cout << "Enter balance of Account: ";
            cin >> money;

            accounts.push_back(bankacc(accname, money));    //creates account with name as entered

            for (unsigned int i = 0; i <= accounts.size(); i++) {
                if (accounts[i].name == accname) {
                    index = i;
                    break;
                }
                else {
                    index = -1;
                }
            }

            system("clear");
            cout << "Account Created: \n";
            cout << endl << "Account: " << accounts[index].name << endl;
            cout << "Balance: " << fixed << setprecision(2) << accounts[index].balance << endl << endl;


        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        //DEPOSIT
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        } else if (toupper(sel) == 'D') {
            system("clear");


            cout << "Enter account name to deposit: ";
            cin >> accname;

            cout << "Enter ammount to deposit: ";
            cin >> money;

            for (unsigned int i = 0; i < accounts.size(); i++) {
                if (accounts[i].name == accname) {
                    index = i;
                    break;
                }
                else {
                    index = -1;
                }
            }

            system("clear");
            if (index != -1) {
                accounts[index].deposit(money);

                cout << "Money Deposited:\n ";
                cout << endl << "Account: " << accounts[index].name << endl;
                cout << "Balance: " << fixed << setprecision(2) << accounts[index].balance << endl << endl;
            }
            else {
                cout << "Account does not exist; returning to menu\n\n";
            }
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        //WITHDRAW
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        } else if (toupper(sel) == 'W') {

            system("clear");


            cout << "Enter account name to withdraw: ";
            cin >> accname;

            cout << "Enter ammount to withdraw: ";
            cin >> money;

            for (unsigned int i = 0; i < accounts.size(); i++) {
                if (accounts[i].name == accname) {
                    index = i;
                    break;
                }
                else {
                    index = -1;
                }
            }

            system("clear");
            if (index != -1) {
                accounts[index].withdraw(money);

                cout << "Money Withdrawn: \n";
                cout << endl << "Account: " << accounts[index].name << endl;
                cout << "Balance: " << fixed << setprecision(2) << accounts[index].balance << endl << endl;
            }
            else {
                cout << "Account does not exist; returning to menu\n\n";
            }

        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        //BALANCE
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        } else if (toupper(sel) == 'B') {

            system("clear");


            cout << "Enter account name to check balance: ";
            cin >> accname;

            for (unsigned int i = 0; i < accounts.size(); i++) {
                if (accounts[i].name == accname) {
                    index = i;
                    break;
                }
                else {
                    index = -1;
                }
            }

            system("clear");
            if (index != -1) {
                cout << "Account Balance:\n ";
                cout << endl << "Account: " << accounts[index].name << endl;
                cout << "Balance: " << fixed << setprecision(2) << accounts[index].balance << endl << endl;
            }
            else {
                cout << "Account does not exist; returning to menu\n\n";
            }

        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        //QUIT
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        } else if (toupper(sel) == 'Q') {
            break;

        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        //DELETE ACCOUNT
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        } else if (toupper(sel) == 'X') {

            system("clear");


            cout << "Enter name of account to delete: ";
            cin >> accname;

            for (unsigned int i = 0; i < accounts.size(); i++) {
                if (accounts[i].name == accname) {
                    index = i;
                    break;
                }
                else {
                    index = -1;
                }
            }

            system("clear");
            if (index != -1) {

                cout << accounts[index].name << " was removed.\nA";
                accounts[index].remove();
            }
            else {
                cout << "Account does not exist; returning to menu\n\n";
            }
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        //INVALID INPUT
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        } else {
            system("clear");
            cout << "Invalid input\n\n";
        }

        cout << "Returning to Menu: " << endl;
        for (int i = 1; i <= 5; i++){
            cout << i << ", " << endl;
            system("sleep 1");
        }
    }

}
