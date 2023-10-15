#include <iostream>
#include<fstream>
#include<string>
#include<algorithm>

using namespace std;
struct Book {
    string Title ;
    string  Author ;
    string Category;
    int Year{};
    // overloading on cout operator of book
    friend ostream& operator <<(ostream &os,const Book&book ){
        os<<"Title: "<<book.Title<<endl;
        os<<"Author: "<<book.Author<<endl;
        os<<"Category: "<<book.Category<<endl;
        os<<"Year: "<<book.Year<<endl;
        return os;
    }

};
struct Node {
    Book book ;
    Node* prev{};
    Node* next{};
};
class DoublyList{
public:
    Node *first;
    Node* last;
    Book info;
    int counter=0;

    DoublyList(){
        first= nullptr, last= nullptr;
    }
    // add at the end
    void AddTail(Book &book) {
        Node *newNode = new Node;
        newNode->book = book;
        if (counter == 0) {
            first = last = newNode;
            newNode->next = newNode->prev = nullptr;
            // there are no vales it will be the first value
        } else {
            //putting vales in list
            newNode->next = nullptr;
            newNode->prev = last;
            last->next = newNode;
            last = newNode;
        }
        counter++;//<-counting vales (adding)
    }
    //add from the beginning
    void AddHeadBook(Book &book) {
        Node *newNode = new Node;
        newNode->book = book;
        newNode->next = nullptr;
        newNode->prev = nullptr;
        if (first == nullptr)
        {
            // there are no vales it will be the first value
            first = newNode;
            last = newNode;
        } else {
            newNode->next = first;
            first->prev = newNode;
            first = newNode;
            //putting vales in list
        }
        counter++;//<-counting vales
    }
    //displaying the data in reverse
    void  DisplayInReverse() const {
        cout << "BOOKS IN REVERSE ORDER: \n";
        Node *ptr = last;
        int count=0;
        for (int i = 0; i < counter;i++ ) {
            while (ptr != nullptr) {
                cout <<"Book no# "<<++count<<": "<<ptr->book<<endl;
                ptr = ptr->prev;
            }
        }  cout << endl ;
    }
    //displaying the data in order
    void DisplayInOrder() const {
        cout << "Books in order : \n";
        Node *ptr = first;
        int count=0;
        for (int i = 0; i < counter;i++ ) {
            while (ptr != nullptr) {
                cout << "Book no# " << ++count << ": " << ptr[i].book << endl;
                ptr = ptr[i].next;
            }
        }cout<<endl;
    }
    //this function is to attach a list to an existing one
    void attach(const DoublyList& L2)
    {
        for(Node *curr = L2.first; curr != nullptr; curr = curr->next)
        {
            AddTail(curr->book);
        }
    }
    //this one is to sort the list depending on the books' titles
    void sortOFList()  {
        Node* node1=first, *node2;
        Node *TMP=new Node;
        while(node1!= nullptr) {
            node2 = node1->next;
            while (node2 != nullptr) {
                if (node1->book.Title > node2->book.Title)
                {//swiping
                    TMP->book = node1->book;
                    node1->book = node2->book;
                    node2->book = TMP->book;
                }
                node2 = node2->next;
            }
            node1 = node1->next;
            counter++;
        }
    }
    // the subscript operator to check if there's any indexes put of range
    Book& operator[](const int index) const {
        if(index < 0 || index >= counter) {
            cout << "SUBSCRIPT ERROR" << endl;//<- the value is larger than the array
        }
        Node *curr = first;
        for(int i = 0; i < index ;i++) {
            curr = curr->next;
        }
        return curr->book;
    }

};
int counter=0;
//get the size of the lists
int get_size(){
    return counter;
}

int main() {
    DoublyList L1,L2;
    ifstream book1("books1.txt");
    Book Bo;

    if(book1.fail()){
        cout<<"COULDN'T OPEN Book1!!!!\n";
    }
    while(!book1.eof()){//putting inputs in the First linked list
        getline(book1,Bo.Title);
        if(book1.eof()){break;}
        getline(book1,Bo.Author);
        getline(book1,Bo.Category);
        book1>>Bo.Year;
        book1.ignore();
        L1.AddTail(Bo);
        counter++;
    }
    book1.close();
    cout<<"FIRST, the display of the first list in order:"<<endl;
    cout<<"Before sorting:"<<endl;
    L1.DisplayInOrder();
    cout<<"the size of the first list= "<<counter<<endl;
    cout<<"######################################################################################################################"<<endl;
    L1.sortOFList();
    cout<<"After sorting:"<<endl;
    L1.DisplayInOrder();

    ifstream book2("books2.txt");
    if(book2.fail()){
        cout<<"COULDN'T OPEN Book2!!!!\n";
    }
    while(!book2.eof()){
        //putting inputs in the second linked list
        getline(book2,Bo.Title);
        if(book2.eof()){break;}
        getline(book2,Bo.Author);
        getline(book2,Bo.Category);
        book2>>Bo.Year;
        book2.ignore();
        L2.AddHeadBook(Bo);
        counter++;
    }
    book2.close();
    cout<<"#######################################################################################################################"<<endl;
    cout<<"SECOND, the display of the second list in order:"<<endl;
    L2.DisplayInOrder();
    cout<<"the second list in reverse: "<<endl;
    L2.DisplayInReverse();
    cout<<"########################################################################################################################"<<endl;
    L1.attach(L2);
    cout<<"THE new list after attaching the second list to the first one:"<<endl;
    for(int i=0;i<counter;i++)
    {
        cout<<"Book no# "<<i+1<<": "<<L1[i]<<endl;
    }
    cout<<"The size of the two lists= "<<get_size()<<endl;
    cout<<"****************\n";
    return 0;
}
