#include <iostream>
#include <vector>
#include "genDLList.h"
#include "genDLList.cpp"

using namespace std;

int main() {
    string fileName = "test1.txt";
    string output = "output.txt";
    DoublyLinkedList<string> myList;

    string command;
    string text;
    string str;
    int n;
    int m;
    int i = 0;
    cout << "/////////////////////////////////////////////////////////////////" << endl;
    cout << "\nWelcome to the text editor. Enter a function to operate.\nEnter x for exit.\n" << endl;
    cout << "/////////////////////////////////////////////////////////////////" << endl;
    while (true) {
        cout << "\nEnter a command:" << endl;
        cin >> command;
        if (command == "open") {
            cout << "Enter your file's name" << endl;
            cin >> str;
            myList.openFile(str);
            myList.printCopy();
            myList.print();
        }
        if (command == "save") {
            cout << "Enter your output file's name" << endl;
            cin >> str;
            myList.saveFile(str);
        }
        if (command == "insert") {
            string str;
            cout << "Enter n and text" << endl;
            cin >> n;
            getchar();
            getline(cin, str);
            myList.insert(n, str);
            myList.print();
        }
        if (command == "delete") {
            cout << "Enter n." << endl;
            cin >> n;
            myList.deleteN(n);
            myList.print();
        }
        if (command == "move") {
            cout << "Enter n and m." << endl;
            cin >> n >> m;
            myList.moveNtoM(n, m);
            myList.print();
        }
        if (command == "replace") {
            string str;
            cout << "Enter n and text." << endl;
            cin >> n;
            getchar();
            getline(cin, str);
            myList.replaceNtext(str, n);
            myList.print();
        }
        if (command == "next") {
            myList.next();
            myList.print();
        }
        if (command == "prev") {
            myList.prev();
            myList.print();
        }
        if (command == "x") {
            exit(1);
        }
    }
}
