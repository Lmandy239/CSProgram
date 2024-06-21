#include "Grocery.h"
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

// Constructor
Grocery::Grocery(const string& inputFile) {
    //calling method to load file passing the string as an argument. (this can be seen in main)
    loadItemsFromFile(inputFile);
    //calls the method to save into the backup file
    saveBackUpFile("frequency.dat");
}

//method that loads files
void Grocery::loadItemsFromFile(const string& filename) {
    //opening the info stream with the file (will be passed when initializing object)
    ifstream inFile(filename);
    //string to store items 
    string item;
    //loop to read every item
    while (inFile >> item) {
        //Increases the frequency for the item
        itemFrequency[item]++;
    }
    inFile.close(); 
}

// method to output into new file
void Grocery::saveBackUpFile(const string& filename) {
    //ofstream to open output file 
    ofstream outFile(filename); 
    // For loop that iterates the item frequencies map and write each item and its frequency to the file
    for (map<string, int>::const_iterator it = itemFrequency.begin(); it != itemFrequency.end(); ++it) {
        outFile << it->first << " " << it->second << endl;
    }
    outFile.close(); 
}

// method to search for items
void Grocery::searchForItem(const string& item) {
    //declaring map it and using method find("") to find the typed item
    map<string, int>::const_iterator it = itemFrequency.find(item);
    //if item is found, display the frequencey. Else error message. 
    if (it != itemFrequency.end()) {
        cout << "Item: " << it->first << " Frequency: " << it->second << endl;
    } else { 
        cout << "Item not found." << endl;
    }
}

// Function to display the list of items and their frequencies
void Grocery::displayItemList() {
    // For loop to iterate the list and display items with frequencies. 
    for (map<string, int>::const_iterator it = itemFrequency.begin(); it != itemFrequency.end(); ++it) {
        cout << it->first << " " << it->second << endl;
    }
}

// Display histogram to the console
void Grocery::displayHistogram() {
    // For loop to iterate and display histograms
    for (map<string, int>::const_iterator it = itemFrequency.begin(); it != itemFrequency.end(); ++it) {
        cout << setw(10) << left << it->first << " " << string(it->second, '*') << endl;
    }
}

//Interactive menu for the user
void Grocery::interactiveMenu() {
    int choice;
    string input;
    // Loop to keep showing the menu until the user chooses to quit
    do {
        cout << "Please choose from the following:\n"
             << " 1. Search for item \n"
             << " 2. Display item list \n"
             << " 3. Display item list (histogram) \n"
             << " 4. Quit" << endl;
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Type item below: \n" << endl;
                cin >> input;
                searchForItem(input);
                break;
            case 2:
                displayItemList();
                break;
            case 3:
                displayHistogram();
                break;
            case 4:
                cout << "GoodBye!" << endl;
                break;
            default:
                cout << "Try again" << endl;
                break;
        }
        //loop condition
    } while (choice != 4); 
}
