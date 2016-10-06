#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <list>
#include "homes.h"

using namespace std;

Homes::Homes()
{
	
}

Panda::Panda()
{
	bamboo = 1;
	area = 1;
	trees = 1;
}

void Panda::input(istream& ins)
{
	ins >> bamboo;
	ins >> area;
	ins >> trees;
}

void Panda::output(std::ostream& outs)const
{
	if(&outs != &cout){
	outs << "Panda\n";
	outs << bamboo << endl;
	outs << area << endl;
	outs << trees << endl << endl;}
}

void Panda::output()
{
	cout << "Panda\n\n";
	cout << "Radius of bamboo available = " << bamboo << endl;
	cout << "Roaming area = " << area << endl;
	cout << "Number of trees = " << trees << endl << endl;
}

void Panda::input()
{
	cout << "Please enter the value for radius of bamboo available: ";
	cin >> bamboo;
	cout << "Please enter the value for roaming area: ";
	cin >> area;
	cout << "Please enter the value for number of trees: ";
	cin >> trees;
}

Eagle::Eagle()
{
	food = 1;
	thickness = 1;
	height = 1;
}

void Eagle::input(istream& ins)
{
	ins >> food;
	ins >> thickness;
	ins >> height;
}

void Eagle::output(std::ostream& outs)const
{
	if(&outs != &cout){
	outs << "Eagle\n";
	outs << food << endl;
	outs << thickness << endl;
	outs << height << endl << endl;}
}

void Eagle::output()
{
	cout << "Eagle:\n\n";
	cout << "Type of food =  " << food << endl;
	cout << "Thickness of nest = " << thickness << endl;
	cout << "Height of nest = " << height << endl << endl;
}

void Eagle::input()
{
	cout << "Please enter the type of food: ";
	cin >> food;
	cout << "Please enter the value for thickness of nest: ";
	cin >> thickness;
	cout << "Please enter the value for height of nest: ";
	cin >> height;
}

Dog::Dog()
{
	diameter = 1;
	height = 1;
	windows = 1;
	length = 1;
	color = "blue";
}

void Dog::input(istream& ins)
{
	ins >> diameter;
	ins >> height;
	ins >> windows;
	ins >> length;
	ins >> color;
}

void Dog::output(std::ostream& outs)const
{
	if(&outs != &cout){
	outs << "Dog\n";
	outs << diameter << endl;
	outs << height << endl;
	outs << windows << endl;
	outs << length << endl;
	outs << color << endl << endl;}
}

void Dog::output()
{
	cout << "Dog\n\n";
	cout << "Diameter of the dog house = " << diameter << endl;
	cout << "height of the dog house = " << height << endl;
	cout << "Amount of windows = " << windows << endl;
	cout << "Length of the dog house = " << length << endl;
	cout << "Color of the dog house = " << color << endl << endl;
}

void Dog::input()
{
	cout << "Please enter the value for the diameter of enterance to the dog house: ";
	cin >> diameter;
	cout << "Please enter the value for the height of the dog house: ";
	cin >> height;
	cout << "Please enter the amount of windows: ";
	cin >> windows;
	cout << "Please enter the value for the length of the dog house: ";
	cin >> length;
	cout << "Please enter the color for the dog house: ";
	cin >> color;
	
}

Groundhog::Groundhog()
{
	radius = 1;
	depth = 1;
	
}

void Groundhog::input(istream& ins)
{
	ins >> radius;
	ins >> depth;
}

void Groundhog::output(std::ostream& outs)const
{
	if(&outs != &cout){
	outs << "Groundhog\n";
	outs << radius << endl;
	outs << depth << endl << endl;}
}

void Groundhog::output()
{
	cout << "Groundhog\n\n";
	cout << "Hole radius = " << radius << endl;
	cout << "Hole depth = " << depth << endl << endl;
}

void Groundhog::input()
{
	cout << "Please enter the value for hole radius: ";
	cin >> radius;
	cout << "Please enter the value for hole depth: ";
	cin >> depth;
}

Fish::Fish()
{
	gallons = 1;
	toys = 1;
	toyType = "";
}

void Fish::input(istream& ins)
{
	ins >> gallons;
	ins >> toys;
	ins >> toyType;
}

void Fish::output(std::ostream& outs)const
{
	if(&outs != &cout){
	outs << "Fish\n";
	outs << gallons << endl;
	outs << toys << endl;
	outs << toyType << endl << endl;}
}

void Fish::output()
{
	cout << "Fish\n\n";
	cout << "Gallons of water in fish tank = " << gallons << endl;
	cout << "Amount of toys in fish tank = " << toys << endl;
	cout << "Types of toys in fish tank = " << toyType << endl << endl;
}

void Fish::input()
{
	cout << "Please enter the value for gallons of water in fish tank: ";
	cin >> gallons;
	cout << "Please enter the amount of toys in fish tank: ";
	cin >> toys;
	cout << "Please enter the type of toys in fish tank: ";
	cin >> toyType;
}
