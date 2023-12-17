#include <iostream>
#include <fstream>
#include <map>
using namespace std;

class ItemFinder {
public:
    // this method opens up the file and reads through it, so it can be used in the map.
    void LoadData(const string &FileName) {
        ifstream file(FileName);
        string item;
        while (file >> item) {
            itemFrequency[item]++;
        }
    }

    // goes through a while loop until it reaches the end of the map, printing all the grouped instances in the process.
    void PrintFreq() {
        map<string, int>::iterator it = itemFrequency.begin();

        while (it != itemFrequency.end()) {
            cout << it -> first <<  " " << it -> second << endl;
            it++;
        }
    }

    //same thing as PrintFreq but the second value is converted into a string consisting of *.
    void PrintHistogram() {
        map<string, int>::iterator it = itemFrequency.begin();

        while (it != itemFrequency.end()) {
            cout << it -> first <<  " " << string (it->second, '*') << endl;
            it++;
        }
    }

    // uses LoadData to list how many times a specific item has shown in the map.
    void SearchItem(const string &ItemName) {
        cout << ItemName << " Appears " << itemFrequency[ItemName] << " Times." << endl;
    }
private:
    // groups the items in text file into a data structure.
    map<string, int> itemFrequency;
};



// GUI for user
void menu(ItemFinder& itemFinder){
    bool MenuRun = true;
    int Choice;
    string ItemSearch;

    while (MenuRun) {
        cout << "Main Menu" << endl;
        cout << "\n[1] Item Search.";
        cout << "\n[2] Item Frequency.";
        cout << "\n[3] Item Histogram.";
        cout << "\n[4] Exit Menu." << endl;
        cout<<"Select Menu option 1-4"<<endl;
        cin >> Choice;
        switch (Choice) {

            case 1:
                cout << "Please enter an item" << endl;
                cin >> ItemSearch;
                itemFinder.SearchItem(ItemSearch);
                break;
            case 2:
                itemFinder.PrintFreq();
                break;
            case 3:
                itemFinder.PrintHistogram();
                break;
            case 4:
                MenuRun = false;
                break;
        }
    }
}
// loads the class, data, and menu.
int main() {
    ItemFinder itemFinder;
    itemFinder.LoadData("CS210_Project_Three_Input_File.txt");
    menu(itemFinder);
    return 0;
}