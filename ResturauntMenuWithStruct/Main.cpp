/* Main.cpp
*  Carter McCall
*  26 January 2023
*  Purpose:
*		Make a resturaunt menu
*/

#include "Menu.h"

int main() {
	Menu mp;
	mp.readMenu("Menu.txt");
	mp.printMenu();
	mp.purchaseItems();
}