/**
*
* Solution to homework assignment 1
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2021/2022
*
* @author Georgi Terziev
* @task 3
* @compiler VC
*
*/

#include <iostream>

using namespace std;

int main()
{
    short rows;
    short salary;

    cin >> rows;

    if (rows < 1 || rows > 10)
    {
        cout << -1;
        return 0;
    }

    cin >> salary;

    if (salary < 700 || salary > 1500)
    {
        cout << -1;
        return 0;
    }

    for (short i = 0; i < rows; i++)
    {
        char site;
        cin >> site;
        
        switch (site)
        {
            case 'F': salary -= 150; break;
            case 'f': salary -= 150; break;
            case 'I': salary -= 100; break;
            case 'i': salary -= 100; break;
            case 'R': salary -= 50; break;
            case 'r': salary -= 50; break;
            case 'd': break;
            case 'D': break;
            default: cout << -1; return 0; break;
        }

        if (salary <= 0)
        {
            cout << "You have lost your salary.";
            return 0;
        }
    }

    cout << salary;

    return 0;
}