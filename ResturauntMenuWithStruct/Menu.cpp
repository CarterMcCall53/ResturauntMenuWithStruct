/* Menu.cpp
*  Carter McCall
*  26 January 2023
*  Purpose:
*		Hold the main functions for the program
*  Modified 27 January 2023:
*		Added printMenu, printBasket, and purchaseItems Functions
*/

#include "Menu.h"

void Menu::readMenu(string file) {
	string line, temp;
	ifstream input;
	int recNum = 0;
	char delim;
	input.open(file);
	if (input) {
		while (!input.eof()) {
			getline(input, line);
			delim = line.find(DELIM);
			records[recNum].item = line.substr(0, delim);
			line = line.substr(delim + 1, line.size());
			records[recNum].stringCost = line.substr(0, delim);
			records[recNum].itemCost = stod(records[recNum].stringCost);
			/*cout << records[recNum].item << endl;
			cout << records[recNum].itemCost << endl;*/
			recNum++;
		}
	}
	recordsSize = recNum;
	for (int i = 0; i < recordsSize; i++)
	{
		temp = records[i].item;
		for (int i = 0; i < temp.length(); i++)
		{
			temp[i] = tolower(temp[i]);
		}
		records[i].item = temp;
	}
}

void Menu::printMenu() {
	for (int i = 1; i < recordsSize; i++) {
		cout << records[i].item << ": $" << records[i].itemCost << endl;
	}
}

void Menu::purchaseItems() {
	string itemInput, input;
	char repChar;
	int quantity;
	do {
		cout << "What would you like to purchase? ";
		getline(cin, itemInput);
		for (int i = 0; i < itemInput.length(); i++)
		{
			itemInput[i] = tolower(itemInput[i]);
		}
		for (int i = 1; i < recordsSize; i++)
		{
			if (itemInput == records[i].item) { 
				cout << "How many would you like? ";
				cin >> quantity;
				for (int j = 0; j < quantity; j++) itemsList.push_back(itemInput);
				for (int j = 0; j < quantity; j++) costList.push_back(records[i].itemCost);
				for (int j = 0; j < quantity; j++) subTotal += records[i].itemCost;
				break;
			}
		}
		Menu::printBasket();
		do {
			cin.ignore();
			cout << "Would you like to buy another item? (Y|N): ";
			getline(cin, input);
			repChar = tolower(input[0]);
		} while (repChar != 'y' && repChar != 'n');
	} while (repChar == 'y');
	Menu::printBasket();
}

void Menu::printBasket() {
	tax = TAXPERCENT * subTotal;
	tax = ceil(tax * 100) / 100;
	totalCost = tax + subTotal;
	totalCost = ceil(totalCost * 100) / 100;
	cout << "\n\nYour Basket\n\n" << endl;
	for (int i = 0; i < itemsList.size(); i++) {
		cout << itemsList[i] << ": $" << costList[i] << endl;
	}
	cout << "\n\n--------------------\n\n" << endl;
	cout << "Subtotal: $" << subTotal << endl;
	cout << "Tax: $" << tax << endl;
	cout << "Total: $" << totalCost << endl;
}