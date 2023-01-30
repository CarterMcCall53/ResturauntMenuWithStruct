#pragma once
/* Menu.h
*  Carter McCall
*  27 Jan. 2023
*  Purpose:
*		hold the Menu class which holds the variables and struct for the rest of the program
*/

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <vector>
using namespace std;

class Menu {
private:
	struct MenuRecord
	{
		string item, stringCost;
		double itemCost;
	};
	char DELIM = ',';
	int recordsSize;
	double totalCost, tax, subTotal;
	const double TAXPERCENT = 0.0525;

	vector<double> costList;
	vector<string> itemsList;
	MenuRecord records[25];
public:
	void readMenu(string);
	void printMenu();
	void purchaseItems();
	void printBasket();
};