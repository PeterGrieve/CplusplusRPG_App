

/*
FILE: ItemTester.cpp
PROGRAMMER: <your name>
DATE: <the date the project is submitted>
PROJECT: AG121_Lab04
CREDITS: <A list of web sites, books, and programmers used to create the code.
You do not need to list any text book used in this course or the instructors name. >
LIMITATIONS: <Any limitations your program may have.  For example, Your  program might fail if the user inputs a number instead of a string.>
*/

#include <iostream>
#include <string>
using namespace std;

#include <conio.h>

#include "CGameItem.h"

// TODO: Add choices to the enum
enum INPUT_CHOICES {
	SPELL,
	POTION,
	SWORD,
	BOW

	// TODO: Add to enum
};

const int MAX_ITEMS = 5;

/*
* Function: help
* Usage: help()
* -----------------------------------
* Prints the help menu to the console.
*/
void help();

/*
* Function: getItemToAdd
* Usage: CGameItem * w = getItemToAdd();
* -----------------------------------
* If successful, this function returns a valid pointer
* to an object derived from type CGameItem.  If the  function
* fails, the function returns NULL.
*/
CGameItem * getItemToAdd();

/*
* Function: getNumber
* Usage: bool result = getNumber(number);
* -----------------------------------
* This function gets a number input by the user.  If the user
* inputs a number, the function returns true and sets number
* the the value input by the user.  If the function returns false,
* the value of number is not changed.
*
*/
bool getNumber(int & number);

/*
* Function: add
* Usage: add(weapons, w, MAX, count)
* -----------------------------------
* This function adds a valid pointer to an array of CWeapon
* pointers.  If successful, the function returns true and the
* value of count is the number of weapons in the pointer array.
* If the function fails, it returns false and the value of count
* is unchanged.
*/
bool add(CGameItem ** items, CGameItem * itemToAdd, int max, int & count);

/*
* Function: remove
* Usage: remove(items, count, index)
* -----------------------------------
* If successful, this function deletes the item at index and
* sets count to the new count of items in the array.  Otherwise,
* the function returns false and count is unchanged.
*/
bool remove(CGameItem ** items, int & count, int index);

/*
* Function: showItems
* Usage: showItems(items, count)
* -----------------------------------
* Prints a list of item descriptions to the console.
*/
void showItems(CGameItem ** items, int count);

int main()
{

	CGameItem * items[MAX_ITEMS]; // array of pointers 
	CGameItem * itemToAdd = NULL;

	int count = 0; // no weapons yet 
	int input;

	// no weapons yet
	for (int i = 0; i < MAX_ITEMS; i++)
	{
		items[i] = 0; // all NULL pointers
	}

	help();

	while (1)
	{
		cout << ">";
		input = _getche();
		cout << endl;

		switch (input)
		{
		case 'a': // ADD
		case 'A':

			itemToAdd = getItemToAdd();

			if (itemToAdd != NULL)
			{
				add(items, itemToAdd, MAX_ITEMS, count);
			}

			break;

		case 'l': // LIST
		case 'L':

			showItems(items, count);
			break;

		case 'Q': // QUIT
		case 'q':
			return 0; // end program

		case 'r': // REMOVE
		case 'R':

			cout << "Enter index to remove: ";

			if (getNumber(input) == false)
			{
				cout << "Invalid input" << endl;
				break; // get out of switch statement
			}

			remove(items, count, input);

			break;

		case 'u': // USE
		case 'U':

			cout << "Enter index of item to use: ";
			if (getNumber(input) == false)
			{
				cout << "Invalid input" << endl;
				break; // get out of switch statement
			}

			if (input >= 0 && input < count)
			{
				items[input]->use();
			}
			else
			{
				cout << "index out of range or no items yet" << endl;
			}

			break;

		default:
			help();

		}// end switch
	}

	system("pause");

	return 0;
}

void help()
{
	cout << endl;
	cout << "Menu: " << endl;
	cout << "  a = add" << endl;
	cout << "  h = help" << endl;
	cout << "  l = list items" << endl;
	cout << "  q = quit" << endl;
	cout << "  r = remove" << endl;
	cout << "  u = use" << endl;
}

CGameItem * getItemToAdd()
{
	CGameItem * addMe = NULL;

	cout << endl;
	cout << "available weapons: " << endl;

	// use enum to output numbers
	cout << SPELL << ". Spell" << endl;
	cout << POTION << ". Potion" << endl;
	cout << SWORD << ". Sword" << endl;
	cout << BOW << ". Bow" << endl;

	// TODO: Add more enums to available items

	int choice = 0;

	cout << "Enter a choice: ";
	if (!getNumber(choice)) // could loop here until input is valid 
	{
		cout << "invalid input." << endl;
		return addMe; // return NULL
	}

	// TODO: 
	// use a switch statement to find the user choice -- use the enum in the switch statement
	// create object based on user input

	switch (choice)
	{
	default: 
		break;
	case SPELL:
		addMe = new CSpell();
		break;
	case POTION:
		addMe = new CPotion();
		break;
	case SWORD:
		addMe = new CSword();
		break;
	case BOW:
		addMe = new CBow();
		break;
	}

	return addMe;
}

bool getNumber(int & number)
{
	// no code to add here 

	string input;

	getline(cin, input);

	// check that input is numeric
	for (unsigned int i = 0; i < input.length(); i++)
	{
		if (input[i] < '0' || input[i] > '9')
		{
			return false;
		}
	}

	number = atoi(input.c_str());

	return true;
}

bool add(CGameItem ** items, CGameItem * itemToAdd, int max, int & count)
{
	// TODO: 
	// if count >= max return false; 
	// assign object to array at count
	// increment count

	if (count >= max)
	{
		return false;
	}

	items[count] = itemToAdd;

	count++;

	return true;
}

void showItems(CGameItem ** items, int count)
{
	for (int i = 0; i < count; i++)
	{
		items[i]->description();

		cout << items[i]->description() << endl;
	}
}

bool remove(CGameItem ** items, int & count, int index)
{
	if (count <= 0)
	{
		return false;
	}


	for (int i = index; i < count; i++)
	{
		items[i] = items[i + 1];
	}

	items[count - 1] = 0;
	count--;
	return true;
}
