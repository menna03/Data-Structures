//Menna Osama Elminshawy 20217011
// Radwa Belal AbdAllah 20217005
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Printer
{
public:
    string PC_NUM;
    string Time;
    int HR;
    int MIN;
    int TimeTaken;
    string executed;

    int get_MIN()
    {
        // converting from string to int
        MIN = stoi(Time.substr(3, 2));
        return MIN;
    }

    int get_HR()
    {
        // converting from string to int

        HR = stoi(Time.substr(0, Time.find(':')));
        return HR;
    }


};

class linkedQueue {
private:
    struct Node
    {
        Printer item;
        Node* next;
    };
    Node* front, * rear;
    int size;

public:
    linkedQueue()
    {
        front = rear = NULL;
        size = 0;
    }

    bool IsEmpty() const
    {
        return size == 0;
    }

    void Enqueue(Printer el)
    {
        Node* newptr = new Node;
        newptr->item.PC_NUM = el.PC_NUM;
        newptr->item.Time = el.Time;
        newptr->item.TimeTaken = el.TimeTaken;
        newptr->next = NULL;
        if (IsEmpty())
        {
            front = rear = newptr;
        }
        else
        {
            rear->next = newptr;
            rear = newptr;
        }
        size++;
    }

    Printer Dequeue()
    {
        if (IsEmpty())
        {
            cout << "Queue is empty." << endl;
            return Printer();
        }
        Node* temp = front;
        Printer item = temp->item;
        front = front->next;
        if (front == NULL)
        {
            rear = NULL;
        }
        delete temp;
        size--;
        return item;
    }

    Printer getFront()
    {
        if (IsEmpty())
        {
            cout << "Queue is empty." << endl;
            return Printer();
        }
        return front->item;
    }


    int getSize() const
    {
        return size;
    }
    int waiting_time(int  PCnum)
    {
        Node* temp = front;
        int size = getSize();
        int* M = new int [size];
        int* TT = new int [size];
        int* H = new int [size];
        int WT = 0;
        for (int i = 0; i < this->getSize(); i++)
        {
            //putting vales in arrays
            M[i] = temp->item.get_MIN();
            TT[i] = temp->item.TimeTaken;
            H[i]=temp->item.get_HR();
            temp = temp->next;
        }
        if (PCnum == 0 ||H[PCnum] != H[PCnum-1])
        {
            return WT;
        }
        else
        {
            WT = ((M[PCnum-1] + TT[PCnum-1]) - M[PCnum ]);

        }
        return WT;
    }

    linkedQueue sortByTime() const
    {
       //making the size
        int size = getSize();
        Printer* printers = new Printer[size];

        // Copy the printers from the queue to the array
        Node* temp = front;
        for (int i = 0; i < size; i++) {
            printers[i] = temp->item;
            temp = temp->next;
        }

        // Sort the printers by time
        for (int i = 0; i < size - 1; i++) {
            int min = i;
            for (int j = i + 1; j < size; j++) {
                // if (HR) of the printer at index j is less than HR of the printer at index min
                if (printers[j].get_HR() < printers[min].get_HR() ||
                    (printers[j].get_HR() == printers[min].get_HR()&&
                    printers[j].get_MIN() < printers[min].get_MIN())||
                    (printers[min].get_HR() == printers[j].get_HR() &&
                    printers[min].get_MIN() == printers[j].get_MIN() &&
                    printers[min].TimeTaken > printers[j].TimeTaken)) //
                {
                    min = j;
                }
            }
            if (min != i) {
                swap(printers[i], printers[min]);
            }
        }

        // Create a new queue and add the sorted printers to it
        linkedQueue sortedQueue;
        for (int i = 0; i < size; i++) {
            sortedQueue.Enqueue(printers[i]);
        }

        // Free the memory allocated for the array
        delete[] printers;

        return sortedQueue;
    }

    int Occupied()
    {
        Node* temp = front;
        int sum = 0;
        for (int i = 0; i < getSize(); i++)
        {
            sum = sum + temp->item.TimeTaken;
            temp = temp->next;
        }
        return sum;
    }
};


float Average_waiting(linkedQueue Q)
{
    float sum = 0;
    for (int i = 0; i < Q.getSize(); i++)
    {
        sum += Q.waiting_time(i);
    }
    return (sum / Q.getSize());
}


int main()
{
    ifstream file;
    file.open("Printer.txt");
    if (!file.is_open())
    {
        cout << "ERROR: Could not open file." << endl;
        return 1;
    }

    linkedQueue Q;
    int tPCS;

    file >> tPCS;
    file.ignore(); // ignore the newline character
    Printer P;
    for (int i = 0; i < tPCS; i++) {

        file >> P.PC_NUM >> P.Time >> P.TimeTaken;
        Q.Enqueue(P);
    }


    cout << "Jobs Executed: " << Q.getSize() << endl;

    Q = Q.sortByTime();
    linkedQueue p = Q;
    for (int i = 0; i < Q.getSize(); i++)
    {
        cout << "PC" << p.getFront().PC_NUM << " " << p.getFront().Time << " " << p.getFront().TimeTaken
             << " executed at " << p.getFront().get_HR() << ':' <<(p.getFront().get_MIN()+Q.waiting_time(i))
             << " " << " waiting time " << Q.waiting_time(i) << endl;
        p.Dequeue();
    }
    cout << "The printer was occupied for " << Q.Occupied() << " minutes." << endl;
    cout << "Average waiting time for all jobs is " << Average_waiting(Q) << " minutes." << endl;

    return 0;
}
