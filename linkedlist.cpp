#include <iostream>
using namespace std;
class IntNode{
public:
    int info{};
    IntNode* next;


    IntNode()
    {
        next=0;
    }
IntNode * getNode()
{
    return next;
}
void setNext(int n,IntNode*in=0)
{
        next=in;
        info=n;
}
IntNode* getnext()
{
     return next;
}

int getinfo()
{
    return info;
}
void setInfo(int n)
{
        info=n;
}


};
class InSLL{
private:
    IntNode *head,*tail;
public:

    InSLL()
    {
        head =tail = NULL;
    }
    void AddHead(int item)
    {
        IntNode *newNODE=new IntNode ;
        newNODE->info=item;
        newNODE->setNext(item);
        head =newNODE ;
        if(tail ==nullptr)
        {
            tail=head;
        }
    }
    void AddTail(int item)
    {
     IntNode *NewNODE =new IntNode;
     if(head==nullptr)
     {
        // there was nothing in the node, so we added it as a head
         AddHead(item);
     }
     else
     {
         tail->setNext(item,NewNODE);
         tail=NewNODE;
         //or if we don't wnt te use tail
         IntNode *curr=head;
         while(curr->next!= nullptr)
         {
            curr=curr->next;
         }
         NewNODE->info=item;
         NewNODE->next= nullptr;
         curr->next=NewNODE;
     }
    }
    void RemoveHead()
    {
        IntNode *ptr=head;;
        if(head==tail)
        {
            head=tail = NULL;
        }
        else
        {
            head->setNext(head->getinfo(),head->getnext());
            delete ptr;
        }
    }
    void RemoveFromTail()
    {
        IntNode *ptr=head;;
        if(head==tail)
        {
            head=tail = NULL;
        }
        else
        {
            while(ptr->getnext()!=tail)
            {
                ptr=ptr->getnext();
            }
            delete tail;
            tail = ptr;
            tail->setNext(0);
        }
    }
    void AddMiddle(int pos, int item) {
        IntNode* newNode = new IntNode();
        newNode->setInfo(item);

        if (pos == 0) {
            AddHead(item);
        }
        else {
            IntNode* curr = head;
            for (int i = 0; i < pos - 1 && curr != nullptr; i++)
            {
                curr = curr->getnext();

            }
            if (curr != nullptr)
            {
               newNode->next=curr->next;
               curr->next=newNode;
            }
        }
    }
    void RemoveMiddle(int pos,int item)
    {
        if (pos == 0) {
            RemoveHead();
        }
        else
        {
            IntNode* newNode = head;
            IntNode* curr = head->next;
            for (int i = 0; i < pos ; i++)
            {
                newNode=curr;
                curr = curr->getnext();
            }
            newNode->next=curr->next;
            curr=curr->getnext();
            delete curr;

        }
    }
    void Search(int item)
    {
        bool found = false;
        IntNode* ptr = head;
        while (!found && ptr != NULL)
        {
            ptr = ptr->getnext();
            if(ptr->getinfo()==item )
            {
                found= true;
                cout<<"found at position "<<ptr->getNode()<<ptr->getinfo()<<endl;
            }

        }

    }


};
int main() {

    return 0;
}
