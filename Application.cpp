//Application.cpp
#include "RegList.h"
#include <iostream>
#include <cstdlib>
#include <stdio.h>
using namespace std;

int main()
{
	const int max = 5;
	int choice = 0;
	RegList registered = new RegList(max);
	RegList waitlisted = new RegList(max);
	printf("Type:\n");
	printf("1: Register a student \n");
	printf("2: Unregister a student\n");
	printf("3: Show number of registered students\n");
	printf("4: Show number of waitlisted students\n");
	printf("5: Display list of registered students\n");
	printf("6: Display list of waitlisted students\n");
	cin >> choice;
	int id = 0;
	switch(choice)
	{
		case 1:
			
			printf("Type Student's ID\n");
			cin >> id;
			if(registered.isFull())
			{
				if(waitlisted.isFull())
				{
					printf("Waitlist is also full.\n");
					printf("you neither register nor Waitlist\n");
				}
				else
				{
					waitlisted.addStudent(id);
					printf("---waitlisted---\n");
				}
			}
			else
			{
				registered.addStudent(id);
				printf("---registered---\n");
			}
			printf("\n");
			break;
		case 2:
			printf("Type Student ID\n");
			cin >> id;
			registered.removeStudent(id);
			if (!waitlisted.isEmpty)
			{
				int wait1 = waitlisted.removeFromFront();
				registered.addStudent(wait1);
			}
			break;
		case 3: 
			printf("number of registered students:\n");
			printf("%d \n", registered.listSize());
			break;
		case 4:
			printf("number of waitlisted students\n");
			printf("%d \n", waitlisted.listSize());
			break;
		case 5:
			printf("Display list of registered students\n");
			cout << registered;
			break;
		case 6: 
			printf("Display list of waitlisted students\n");
			cout << waitlisted;
			break;



			


	}




	return 0;
}