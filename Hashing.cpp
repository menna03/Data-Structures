#include <iostream>
#include <fstream>
#include <list>
#include <string>
using namespace std;

class Book {
public:
    string ISBN;
    string Title;
    string Author;

    void setAll(string& T, string& A, string& ID) {
        Title = T;
        Author = A;
        ISBN = ID;
    }
};


class Hashing {
public:
    int size;
    list<Book>* Hbook;

    int stringToInteger(const string& str) {
        return stoi(str.substr(str.length() - 3)) % 100;
    }

    void insert(const Book& b) {
        int index = hashFun(b.ISBN);
        Hbook[index].push_back(b);
    }

    Hashing(int b = 0) {
        size = b;
        Hbook = new list<Book>[size];
    }

    int hashFun(const string& ISBN) {
        return stringToInteger(ISBN) % size;
    }

    void search(const string& ISBN) {
        int index = hashFun(ISBN);
        int comparisons = 0;
        bool found = false;

        for (list<Book>::iterator it = Hbook[index].begin(); it != Hbook[index].end(); ++it) {
            comparisons++;

            if (it->ISBN == ISBN) {
                cout << "Title: " << it->Title << endl;
                cout << "Author: " << it->Author << endl;
                cout << "Comparisons: " << comparisons << endl;
                found = true;
                break;
            }
        }

        if (!found) {
            cout << "Book Not found" << endl;
            cout << "Comparisons: " << comparisons <<endl;
        }
    }
};


int main() {
    ifstream file1("in.txt");
    ifstream file2("search.txt");
    if (file2.fail()) {
        cout << "\n ERROR \n";
    }
    if (file1.is_open()) {
        cout << "clear ^-^\n";
    }
    if (!file1.is_open()) {
        cout << "COULDN'T OPEN\n";
    }
    Hashing *hash = new Hashing(100);
    Book bOOK;
    int c=0;
    while (getline(file1, bOOK.ISBN)) {
        getline(file1, bOOK.Title);
        getline(file1, bOOK.Author);
        hash->insert(bOOK);
        if (file1.fail()) {
            cout << "Error reading file!" << endl;
            break;
        }
        c++;
    }


    file1.close();
    string search;
int i=0;
    while (file2>>search) {
        cout << i+1<<"\t"<<search<< ":" << endl;
        hash->search(search);
        i++;
    }

    file1.close();
    file2.close();
cout<<"End of our program thank you ^_^";
    return 0;
}
