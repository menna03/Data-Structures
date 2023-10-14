#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;
//Menna Osama Elminshawy 20217011
int readall = 0;
struct Book {
    string title;
    string author;
    string category;
    int year{};
};
//linear_search
void linear_search(Book B[100] ,int chosen,const string& title_author){
    bool found= false;
    int comparisons = 0;
    switch(chosen) {
        case 1:
            for (int i = 0; i < readall; i++)
            {
                // compar title
                comparisons++;
                if(B[i].title ==title_author){
                    cout <<  B[i].title<< endl;
                    cout <<  B[i].author<< endl;
                    cout << B[i].category << endl;
                    cout << B[i].year << endl;
                    found= true;
                    cout<<"Book Found\n";
                    cout<<"Comparisons by linear search: "<<comparisons<<"\n";
                    break;
                }
            }
            break;
        case 2:
            for (int i = 0; i < readall; i++)
            {
                // comar author
                comparisons++;
                if(B[i].author ==title_author)
                {
                    cout <<  B[i].title<< endl;
                    cout << B[i].author << endl;
                    cout << B[i].category << endl;
                    cout << B[i].year << endl;
                    found= true;
                    cout<<"Book Found\n";
                    cout<<"Comparisons by linear search: "<<comparisons<<"\n";
                    break;
                }
            }//output 
            break;
        case 0:
            break;
    }
    if(!found&&chosen!=0) {
        cout << "Book *NOT* Found";
    }
     if(chosen==0) {
        cout << "Choice: 0\n";
    }

    cout<<"############################################################################################################\n";
}

void Binary_Search(Book B[100], int chosen, const string& title_author) {
    bool found = false;
    int comparisons = 0;
    int First = 0, last = readall - 1, mid;
    mid = (First + last) / 2;
    if (chosen == 1) {
        // sort function sort object 
        sort(B, B + readall, [](const Book& b1, const Book& b2)
        {
            return b1.title < b2.title;
        });
        while (First <= last && !found) {
            comparisons++;
            if (B[mid].title == title_author) {
                cout << B[mid].title << endl;
                cout << B[mid].author << endl;
                cout << B[mid].category << endl;
                cout << B[mid].year << endl;
                found = true;
            }


            if (B[mid].title > title_author) {
                last = mid - 1;
            } else {
                First = mid + 1;
            }
            mid = (First + last) / 2;
        }
    } else if (chosen == 2) {
        sort(B, B + readall, [](const Book& b1, const Book& b2) {
            return b1.author < b2.author;
        });
        while (First <= last && !found) {
            comparisons++;
            if (B[mid].author == title_author) {
                cout << B[mid].title << endl;
                cout << B[mid].author << endl;
                cout << B[mid].category << endl;
                cout << B[mid].year << endl;

                found = true;
            }


            if (B[mid].author > title_author) {
                last = mid - 1;
            } else {
                First = mid + 1;
            }
            mid = (First + last) / 2;
        }
    }

    if (found) {
        cout << "Book Found\n";
        cout << "Comparisons by Binary_Search:" << comparisons << "\n";
    } else if (chosen == 0) {
        cout << "Choice: 0\n";
    } else {
        cout << "Book *NOT* Found";
        cout << "Comparisons by Binary_Search:" << comparisons << "\n";
    }
    cout<<"############################################################################################################\n";
}
int main()
{
    Book B[100];

    ifstream books("books.txt", ios::in);

    string read;
    if (books.fail()) {
        cout << "not found\n";
    }
    while (!books.eof()) {
        getline(books, B[readall].title);
        getline(books, B[readall].author);
        getline(books, B[readall].category);
        books >> B[readall].year;
        books.ignore();

        ++readall;
    }
    cout << "1 to search by title\n"
            "2 to search by author\n"
            "0 to exit\n";
    int chosen;
    cin >> chosen;
    string title_author;
    while(chosen!=0)
    {
        //chosen=what we want 
        switch (chosen) {
            case 1:
                cout << "Enter title:\n";
                cin.ignore();
                getline(cin,title_author);
                linear_search( B,chosen,title_author);
               Binary_Search(B, chosen, title_author);
                break;
            case 2:
                cout << "Enter author:\n";
                cin.ignore();

                getline(cin,title_author);
                linear_search( B,chosen,title_author);
                Binary_Search(B, chosen, title_author);
                break;
            case 0:
                break;
        }
        cout << "1 to search by title\n"
                "2 to search by author\n"
                "0 to exit\n";
        cin >> chosen;
    }
    linear_search( B,0,title_author);
    return 0;
}