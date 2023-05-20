#include <iostream>
using namespace std;
class IntNode{

public:
    int info{};
    IntNode* next;
    IntNode * prev;
    IntNode *First,*Last;
    int length;
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



private:
    IntNode *tail;
    IntNode *head;
public:
    void AddHead(int item)
    {
        IntNode *newNODE ;
        newNODE->setNext(item);
        head =newNODE ;
        if(tail ==head== NULL)
        {
            First=Last=newNODE;
            newNODE->next=newNODE->prev=NULL;
        }
        else
        {
            newNODE->next=First;
            newNODE->prev=NULL;
            First->prev=newNODE;
            First=newNODE;
        }
    }
    void AddTail(int item)
    {
        IntNode *newNODE ;
        newNODE->setNext(item);
        if(tail==NULL)
        {
            // there was nothing in the node, so we added it as a head
            First=Last=newNODE;
            newNODE->next=newNODE->prev=NULL;
        }
        else
        {
           newNODE->next=NULL;
           newNODE->prev=Last;
           Last->next=newNODE;
           Last=newNODE;
        }
    }
    void RemoveHead()
    {
       if(tail==head==NULL)
       {
           delete First;
           Last=First=NULL;
       } else{

           IntNode* curr=First;
           First=First->next;
           First->prev=NULL;
           delete curr;
       }
    }
    void RemoveFromTail()
    {
        if(tail==head==NULL)
        {
            delete First;
            Last=First=NULL;
        } else{

            IntNode* curr=Last;
            Last=Last->next;
            Last->prev=NULL;
            delete curr;
        }
    }
    void AddMiddle(int pos, int item) {
        IntNode* newNode = new IntNode();
        newNode->setInfo(item);

        if (pos == 0) {
            AddHead(item);
        } else {

            IntNode *newNode=new IntNode ;
            IntNode *curr =First;
            for(int i=1;i<pos;i++)
            {
                curr=curr->next;
            }
            newNode->next=curr->next;
            newNode->prev=curr;
            curr->next=new IntNode;
            curr->next->prev=newNode;
        }
    }
    void RemoveMiddle(int item)
    {IntNode *curr=First->next;
        if (First->getinfo() == item) {
            RemoveHead();
        }
        else
        {

            while (curr!=NULL)
            {
                if(curr->getinfo()==item)
                {
                    break;
                }
                curr=curr->next;
            }
        }
        if(curr==NULL)
        {
            cout<<"not Found \n";
        }
        else if(curr->next==NULL)
        {
            RemoveFromTail();
        }
        else
        {
            curr->prev->next=curr->next;
            curr->next->prev=curr->prev;
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
