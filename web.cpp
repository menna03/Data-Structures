#include <iostream>
#include <string>
#include <fstream>
using namespace std;

// define a template class NODE
template<class T>
class NODE{
public :
    T info;
    NODE* next;
    NODE(){
        next=NULL;
    }
};

// define a template class Stack
template<class T>
class Stack {
public:
    NODE<T> * Head;
    Stack(){
        Head=NULL;
    }
    bool IsEmpty(){
        if(Head==NULL){
            return true;
        }
        else{
            return false;
        }
    }
    void push(T item){
        NODE<T>* newNode= new NODE<T>;
        newNode->info=item;
        if(IsEmpty()){
            newNode->next=NULL;
            Head=newNode;
        }
        else{
            newNode->next=Head;
            Head=newNode;
        }
    }
    T pop(){
        T Data;
        NODE<T>* current=Head;
        Data=Head->info;
        Head=Head->next;
        delete current;
        return Data;
    }
    void display(){
        NODE<T> *tmp=Head;
        while(tmp!=NULL){
            cout<<tmp->info<<" ";
            tmp=tmp->next;
        }
        cout<<endl;
    }
    T top(){
        return Head->info;
    }

};

// main function
int main() {
    // create two stacks of string type
    Stack<string> Stack1, Stack2;

    // open a file for input
    ifstream file("URLs.txt");

    // check if file opened successfully
    if (!file.is_open()) {
        cout << "COULDN'T OPEN!!\n";
    }

    // read the number of URLs from the file
    int num;
    file >> num;

    // read URLs from the file and push them onto Stack1
    string Url;
    for (int i = 0; i < num; i++) {
        file >> Url;
        Stack1.push(Url);
    }

    // read 10 choices from the file and store them in an array
    string choices[10];
    for (int j = 0; j < 10; j++) {
        file >> choices[j];
    }

    // set the initial current page to the top of Stack1
    string currentPage = Stack1.top();

    // display the initial current page
    cout << "\nThe current page is: " << currentPage << endl;

    // push the initial current page onto Stack2
    Stack2.push(currentPage);

    // remove the initial current page from Stack1
    Stack1.pop();

    // loop through the 10 choices
    for (int i = 0; i < 10; i++) {
        // if the choice is "Backward"
        if (choices[i] == "Backward") {
            cout << "-------------------------------------------------------------------------" << endl;

            // push the current page onto Stack2
            Stack2.push(currentPage);

            // set the current page to the top of Stack1
            currentPage = Stack1.top();

            // remove the current page from Stack1
            Stack1.pop();

            // display the new current page and the previous and next pages
            cout << "\n choice " << i + 1 << " [Backward]\n";
            cout << "The current page is: \n";
            cout << currentPage;
            cout << "\nThe next one is:\n";
            cout << Stack2.top();
            cout << "\nThe previous one is:\n ";
            cout << Stack1.top() << endl;
        }
            // if the choice is "Forward"
        else if (choices[i] == "Forward") {
            cout << "-------------------------------------------------------------------------" << endl;

            // push the current page onto Stack1
            Stack1.push(currentPage);

            // set the current page to the top of Stack2
            currentPage = Stack2.top();

            // remove the current page from Stack2
            Stack2.pop();

            // display the new current page and the previous and next pages
            cout << "\n choice " << i + 1 << " [Forward]\n";
            cout << "The current page is: \n";
            cout << currentPage;
            cout << "\nThe next one is:\n";
            cout << Stack2.top();
            cout << "\nThe previous one is:\n ";
            cout << Stack1.top() << endl;
        }
    }

    return 0;
}