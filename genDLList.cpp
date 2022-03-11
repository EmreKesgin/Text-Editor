#include "genDLList.h"
#include <fstream>
#include <vector>

template<class T>
void DoublyLinkedList<T>::openFile(string filename) {
    ifstream inFile;
    inFile.open(filename, ios::in);
    string line;
    while (getline(inFile, line)) {
        addToDLLTail(line);
    }
    inFile.close();
}

template<class T>
void DoublyLinkedList<T>::saveFile(string output) const {
    int counter = 1;
    int counter2 = 1;
    std::ofstream outFile(output, std::ofstream::out);
    for (DLLNode<T> *tmp = head; tmp != 0; tmp = tmp->next) {
        outFile << counter << ") " << tmp->info << endl;
        if (counter % 10 == 0) {
            outFile << "\n\n--- Page" << counter2 << " ---" << endl;
            counter2++;
        }
        counter++;
    }
}

template<class T>
void DoublyLinkedList<T>::insert(int n, string newLine) {
    DLLNode<T> *iter = head;
    DLLNode<T> *tmp = 0;
    int i = 0;
    if (n == 1) {
        addToDLLHead(newLine);
    } else {
        while (iter != 0) {
            i++;
            tmp = iter;
            iter = iter->next;
            if (i == n - 1) {
                if (iter->info == "") {
                    iter->info = newLine;
                } else {
                    DLLNode<T> *newNode = new DLLNode<T>;
                    newNode->info = newLine;
                    newNode->next = 0;
                    newNode->prev = 0;
                    newNode->prev = tmp;
                    newNode->next = iter;
                    tmp->next = newNode;
                    iter->prev = newNode;
                }
                break;
            }
            if (i != n - 1 && iter == tail) {
                int counter = 0;
                for (counter = n - i; counter != 0; counter--) {
                    DLLNode<T> *newNode = new DLLNode<T>;
                    newNode->info = "";
                    newNode->next = 0;
                    newNode->prev = 0;
                    newNode->prev = tail;
                    tail->next = newNode;
                    tail = newNode;
                }
            }
        }
    }
    printCopy();
}

template<class T>
void DoublyLinkedList<T>::deleteN(int n) {
    int i = 0;
    for (DLLNode<T> *tmp = head; tmp != 0; tmp = tmp->next) {
        i++;
        if (i == n) {
            tmp->prev->next = tmp->next;
            tmp->next->prev = tmp->prev;
            delete tmp;
            break;
        }
    }
    printCopy();
}

template<class T>
void DoublyLinkedList<T>::moveNtoM(int n, int m) {
    int counter = 0;
    int counter2 = 0;
    DLLNode<T> *tmp = head;
    DLLNode<T> *iter = head;

    for (; tmp != 0; tmp = tmp->next) {
        counter++;
        if (counter == n) {
            break;
        }
    }
        for (; iter != 0; iter = iter->next) {
            counter2++;
            if (n > m) {
                if (counter2 == m-1) {
                    break;
                }
            } else {
                if (counter2 == m) {
                    break;
                }
            }
        }
    if (tmp == head) {
        head = tmp -> next;
        tmp->next->prev = 0;
        tmp->prev = iter;
        if(iter == tail){
            tmp->next=0;
            tail = tmp;
        }
        else{
            tmp->next = iter->next;
            iter->next->prev = tmp;
        }
        iter->next = tmp;
        printCopy();
    }
    else {
        if(iter == head)
        {
            if(tmp == tail){
                tmp->prev->next=0;
                tail = tmp->prev;
                head = tmp;
                iter->prev = head;
                tmp->next = iter;
                head->prev = 0;
            }
            else
            {
                tmp->next = tail;
                tmp->prev->next=tmp->next;
                tmp->next->prev = tmp->prev;
                iter->prev = tmp;
                tmp->prev = 0;
                tmp->next = iter;
                head = tmp;

            }
            printCopy();
        }
        else{
            tmp->next->prev = tmp->prev;
            tmp->prev->next = tmp->next;
            tmp->prev = iter;
            if(iter == tail){
                tmp->next = 0;
                tail = tmp;
            }
            else{
                tmp->next = iter->next;
                iter->next->prev = tmp;
            }
            iter->next = tmp;
            printCopy();
        }

    }
}

template<class T>
void DoublyLinkedList<T>::replaceNtext(string newText, int n) {
    int counter = 0;
    for (DLLNode<T> *tmp = head; tmp != 0; tmp = tmp->next) {
        counter++;
        if (counter == n) {
            tmp->info = newText;
            break;
        }
    }
    printCopy();
}

template<class T>
void DoublyLinkedList<T>::printCopy() {
    vec.clear();
    string str;
    int counter = 1;
    for (DLLNode<T> *tmp = DoublyLinkedList<T>::head; tmp != 0; tmp = tmp->next) {
        str += to_string(counter) + ") " + tmp->info;
        vec.push_back(str);
        counter++;
        str.clear();
    }
}

template<class T>
void DoublyLinkedList<T>::print() {
    int tmp = abc;
    int x = abc + 10;
    while (abc != x) {
        if (abc >= vec.size()) {
            abc += 10;
            break;
        }
        cout << vec.at(abc) << endl;
        abc++;
    }
    abc = tmp;
    cout << "\n\n--- " << "page " << abc2 << " ---" << endl;
}

template<class T>
void DoublyLinkedList<T>::next() {
    abc += 10;
    abc2++;
}

template<class T>
void DoublyLinkedList<T>::prev() {
    abc -= 10;
    abc2--;
}


