#include <iostream>
#include "Duelist.h"
using namespace std;

void Log()
{
	cout << "First";
}

void Log()
{
	cout << "Second";
}

int main()
{
	MonsterCard A("Gosho", 5, 5);
	MonsterCard B(A);

}