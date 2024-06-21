#include "Grocery.h"

int main() {
    //initialize object using the file name as an argument
    Grocery grocery("InventoryList.txt");
    //use the new object to call its child method "interactive menu" to start everything
    grocery.interactiveMenu();
    return 0;
}
