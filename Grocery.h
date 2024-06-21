#ifndef GROCERY_H
#define GROCERY_H

#include <string>
#include <map>

using namespace std;

class Grocery {
public:
//constructor that takes in an input file
    Grocery(const string& inputFile);
    //method to search for item that takes in an input string
    void searchForItem(const string& item);
    void displayItemList();
    void displayHistogram();
    void interactiveMenu();
private:
    //private map 
    map<string, int> itemFrequency;
    //method that will use infstream with an input string "" file  to load/read items
    void loadItemsFromFile(const string& filename);
    //method that will use the ofstream and an file name argument to write into new file
    void saveBackUpFile(const string& filename);

};

#endif
