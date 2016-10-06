/******************************************************************

********************************************************************/

#include "homes.h"
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <list>

using namespace std;

void menu();

int main()
{
	list<Homes*> myhomes;
	list<Homes*>::iterator it;
	Homes *ptr;
	string username, filename;
	ifstream ins;
	ofstream outs;
	int choice = 0;
	string tag;
	
	
	cout << "Welcome to Animal Homes Construction Inc.\n";
	cout << "Enter your username to start using the software: ";
	getline(cin, username);
	filename = username + ".txt";
	
	ins.open(filename.c_str());
	
	if (!ins.fail())
	{
		ins >> tag;
		
		while(!ins.eof())
		{
			if(tag == "Panda")
			{
				ptr = new Panda();
				ptr -> input(ins);
				myhomes.push_back(ptr);
			}
			else if(tag == "Eagle")
			{
				ptr = new Eagle();
				ptr -> input(ins);
				myhomes.push_back(ptr);
			}
			else if(tag == "Groundhog")
			{
				ptr = new Groundhog();
				ptr -> input(ins);
				myhomes.push_back(ptr);
			}
			else if (tag == "Dog")
			{
				ptr = new Dog();
				ptr -> input(ins);
				myhomes.push_back(ptr);
			}
			else if(tag == "Fish")
			{
				ptr = new Fish();
				ptr -> input(ins);
				myhomes.push_back(ptr);
			}
			
			ins >> tag;
		}
	}
	
	ins.close();
	
	while(choice != 7)
	{
		menu();
		cout<<"Enter your choice: ";
		cin>>choice;
		
		switch(choice)
		{
			case 1:
				ptr = new Panda();
				ptr -> input();
				myhomes.push_back(ptr);
				break;
			case 2:
				ptr = new Eagle();
				ptr -> input();
				myhomes.push_back(ptr);
				break;
			case 3:
				ptr = new Groundhog();
				ptr -> input();
				myhomes.push_back(ptr);
				break;
			case 4:
				ptr = new Dog();
				ptr -> input();
				myhomes.push_back(ptr);
				break;
			case 5:
				ptr = new Fish();
				ptr -> input();
				myhomes.push_back(ptr);
			case 6:
				it = myhomes.begin();
				while(it != myhomes.end())
				{
					(*it) -> output();
					cout << endl << endl;
					++it;
				}
				break;
			case 7:
				outs.open(filename.c_str());
				it = myhomes.begin();
				while(it != myhomes.end())
				{
					(*it) -> output(outs);
					++it;
				}
				outs.close();
				break;
			default:
				cout << "Invalid choice. Choose again.";
				break;		
		}
	}
	return EXIT_SUCCESS;
}

void menu()
{
	cout << "\nPick an animal to make a home for:\n";
    cout<<"Enter 1 to build a house for a Bear.\n";
    cout<<"Enter 2 to build a house for a Eagle.\n";
    cout<<"Enter 3 to build a house for a Groundhog. \n";
	cout<<"Enter 4 to build a house for a Dog. \n";
	cout<<"Enter 5 to build a house for a Fish. \n";
    cout<<"Enter 6 to see total houses.\n";
	cout<<"Enter 7 to quit.\n";
}
