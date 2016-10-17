#include "DLinkedList.h"
#include <iostream>
#include <cstdlib>
using namespace std;

int main() 
{
	//creating our Doubly linked list
	mike_DLinkedList::DLinkedList l1;
	//initializing variables 
	int input = 0,destination = 0;
	string testInput = "";
	char ch = '';

	cout << "Welcome to Doubly Linked List Tester!\n\n";

	do
	{
		//menu
		cout << "\nWhat would you like to do ?\n";
		cout << "A. Add A Node.\n";
		cout << "B. Add A Node At A Specific Location.\n";
		cout << "C. Search For A Value.\n";
		cout << "D. Delete A Node.\n";
		cout << "E. Print the List.\n";
		cout << "F. Clear the List.\n";
		cout << "G. List Size.\n";
		cout << "Q. Quit.\n";

		//reads as a string to make sure user does not break the program.
		//if user enter something larger than one character, we give it a 
		//default value of a '?' which will get caught in the default statement
		//inside our switch.
		cin >> testInput;

		if(testInput.length() > 1)
			ch = '?';
		else
			ch = testInput[0];

		//Make our character an upper case for simplicity.
		ch = toupper(ch);

		//switch takes care of the user input from the above menu.

		switch(ch)
		{
			case 'A':
						cout << "Enter the value you would like to add.\n";
						cin >> input;
						l1.head_insert(input);
						cout << "if valid, the value " << input << " has been added.\n";
				break;
			case 'B':
						cout << "Enter the value you would like to add.\n";
						cin >> input;
						cout << "\nBelow is the list, enter the value in which you "
							 << "would like to insert your new value at.\n(I will add it "
							 << "right after the given value.)\n";
						cout << l1 << endl;
						cin >> destination;
						l1.list_insert(l1.list_search(destination),input);
						cout << "If valid, the value " << input << " has been added.\n";
				break;
			case 'C':
						cout << "Enter the value you are looking for.\n";
						cin >> input;
						cout << "Value located in address " << l1.list_search(input) << endl;
						cout << "(If location was \"0x0\", value was not found, NULL)\n";
				break;
			case 'D':
						cout << "Enter the value you are deleting.\n";
						cin >> input;
						cout << l1 << endl;
						l1.list_remove(l1.list_search(input));
						cout << "If valid, the value " << input << " has been deleted.\n";
				break;
			case 'E':
						cout << "The list: \n";
						cout << l1 << endl;
				break;
			case 'F':
						l1.clear_list();
						cout << "The list has been cleared.\n";
				break;
			case 'G': 
						cout << "Size of the list " << l1.list_length() << endl;
			case 'Q': 
				break;
			// if user enters an unvalid character, we simply notify him and allow him a chance
			// to either input valid input or quit.
			default: cout << "Wrong input, please try again.\n";
				break;
		}
		// end of our do while loop which closes our program.
	}while(ch != 'Q');

	cout << "Thank you & Goodbye.\n";

	return EXIT_SUCCESS;
}