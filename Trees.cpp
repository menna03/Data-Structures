#include <iostream>
#include <queue>
using namespace std;
class Node
{

public:
    int data;
    Node *left,*right;
    Node(int item)
    {
        data=item;
        left=right=nullptr;
    }
};
class Tree
{
    Node *root;
    Tree()
    {
        root=nullptr;
    }
    Node * Insert(Node * Pnode,int item)
    {
        if(Pnode== nullptr)
        {
            Node* neww=new Node(item);
            Pnode=neww;
        }
        else if(item<Pnode->data)
        {
            Pnode->left= Insert(Pnode->left,item);
        }
        else
        {
            Pnode->right= Insert(Pnode->right,item);
        }
        return Pnode;

    }

};

Node* search(Node *r,int Key)
{
    if(r==NULL)
    {
        return NULL;
    }
    else if(r->data==Key)
    {
        return r;
    }
    else if(Key<r->data)
    {
        return search(r->left,Key);
    }
    else
    {
        return search(r->right,Key);
    }
}

Node * MIN(Node*r)
{
    if(r==NULL)
    {
        return NULL;
    }
    else if(r->left==NULL)
    {
        return r;
    } else
    {
        return MIN(r->left);
    }
}

Node * MAX(Node*r)
{
    if(r==nullptr)
    {
        return NULL;
    }
    else if(r->right==nullptr)
    {
        return r;
    } else
    {
        return MAX(r->right);
    }
}

Node* DELETE(Node*r,int Key)
{
    if(r==NULL)
    {
        return NULL;
    }
    if(Key<r->data)
    {
        r->left= DELETE(r->left,Key);
    }
    else if(Key>r->data)
    {
        r->right= DELETE(r->right,Key);
    }
    else
    {
        if(r->left==NULL&&r->right==NULL)
        {
            r=NULL;
        }
        else if(r->left!=NULL&&r->right==NULL)
        {
            r->data=r->left->data;
            delete r->left;
            r->left=NULL;

        }
        else if(r->left!=NULL&&r->right==NULL)
        {
            r->data=r->right->data;
            delete r->right;
            r->right=NULL;
        }
        else
        {
            Node *MAx=MAX(r->left);
            r->data=MAx->data;
            DELETE(r->left,MAx->data);
        }
    }
    return r;
}

void PREorder(Node*p)
{
//root left right
if(p!=NULL)
{
    cout<<p->data <<" ";
    PREorder(p->left);
    PREorder(p->right);
    //Yes only this :)
}
}

void INorder(Node *p)
{
    if(p!=NULL)
    {
        INorder(p->left);
        cout<<p->left<<" ";
        INorder(p->right);
    }
}

void POSTorder(Node *p)
{
    if(p!=NULL)
    {
        PREorder(p->left);
        POSTorder(p->right);
        cout<<p->data<<" ";
    }
}


void Heapify(int arr[],int n,int i)
{
    int L=2*i+1;
    int r=2*i+2;
    int max=i;
    if(L<n&&arr[L]>arr[max])
    {
        max=L;
    }
    if(r<n&&arr[r]>arr[max])
    {
        max=r;
    }
    if(max!=i)
    {
        swap(arr[i],arr[max]);
        Heapify(arr,n,max);

    }
    //nlog(n)
}
void buildHeap(int arr[],int n)
{//O(n)
for(int i=n/2-1;i>0;i--){
Heapify(arr,n,i);
}

}

void HeapSort(int arr[],int n)
{
    buildHeap(arr,n);
    for(int i=n-1;i>0;i--)
    {
        swap(arr[0],arr[i]);
        Heapify(arr,i,0);
    }
    //nlog(n)
}

void BFT(Node *root)
{
    if(root==nullptr)
    {
        return;
    }
    queue<Node*>Q;
    Q.push(root);
    while (!Q.empty())
    {
        Node*curr=Q.front();
        cout<<curr->data<<" ";
        if(curr->left!=nullptr)
        {
            Q.push(curr->left);
        }
        if(curr->right!=nullptr)
        {
            Q.push(curr->right);
            Q.pop();
        }
    }

}


int main() {

    return 0;
}
