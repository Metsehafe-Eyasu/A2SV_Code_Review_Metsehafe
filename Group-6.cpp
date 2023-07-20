#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

struct Departments
{
    char deptID[20];
    char deptName[30];
    char deptHead[20];
    char collegeName[30];
};

void addDept(Departments *dept, int index, int total);
void Display(Departments dept[], int total);
void Search(Departments dept[], int total, char value[]);

int main()
{
    cout << "\t*************Simple College Management System*************\n";
    cout << "\n\n";
    cout << "\t\t\tWelcome to our program!\n\n";
    system("pause");
    Departments deptList[50];
    int a = 0;
    int total = 0;
    int option;
start:
    cout << "\nWhat would you like to do:\n";
    cout << "\t[1] Add Department\n";
    cout << "\t[2] Display all Departments\n";
    cout << "\t[3] Search\n";
    cout << "\t[4] Exit\n";
    cin >> option;
    switch (option)
    {
    case 1:
        cout << "How many Department would you like to add? ";
        cin >> a;
        addDept(deptList, a, total);
        total += a;
        break;
    case 2:
        if (total == 0)
            cout << "No Department saved\n";
        else
        {
            Display(deptList, total);
            system("pause");
        }
        system("pause");
        system("clear");
        break;
    case 3:
        if (total == 0)
            cout << "No Department saved\n";
        else
        {
            char searchVal[20];
            cout << "Search value: ";
            cin >> searchVal;
            Search(deptList, total, searchVal);
            cout << endl;
        }
        system("pause");
        system("clear");
        break;
    case 4:
        cout << "Thank you";
        exit(0);
    default:
        cout << "invalid value!";
        break;
    }
    goto start;

    return 0;
}

void addDept(Departments *dept, int index, int total)
{
    cin.ignore();
    for (int i = total; i < index + total; i++)
    {
        cout << "\nEnter department " << total + i + 1 << " ID: ";
        gets((dept + i)->deptID);
        cout << "\nEnter department " << total + i + 1 << " name: ";
        gets((dept + i)->deptName);
        cout << "\nEnter department " << total + i + 1 << " Head: ";
        gets((dept + i)->deptHead);
        cout << "\nEnter college " << total + i + 1 << " name: ";
        gets((dept + i)->collegeName);
    }
}

void Display(Departments dept[], int total)
{
    if (total == 0)
        cout << "No students saved\n";
    else
    {
        cout << "Department ID\tDepartment Name\t Department Head\tCollege Name\n";
        for (int i = 0; i < total; i++)
        {
            cout << (dept + i)->deptID << "\t\t" << (dept + i)->deptName << "\t" << (dept + i)->deptHead << "\t\t" << (dept + i)->collegeName;
            cout << endl;
        }
        cout << endl;
    }
}
void Search(Departments dept[], int total, char value[])
{
    Departments searchResults[total] = {};
    int sr = 0;
    for (int i = 0; i < total; i++)
    {
        if (strncasecmp(value, dept[i].deptID, strlen(value)) == 0)
        {
            searchResults[sr] = dept[i];
            sr++;
        }
        else
            continue;
    }
    Display(searchResults, sr);
}