#include <iostream>
#include <cstring>
using namespace std;

void insertion_sort(int arr[],int n)
{
/*
arranging hands of cards
first one is constant we change the rest
The list is divided into two parts: sorted and unsorted.
• In each pass, the first element of the unsorted part is
picked up, transferred to the sorted sublist, and inserted
at the appropriate place.
• A list of n elements will take at most n-1 passes to sort
the data.
 */

int comparisons=0;
for(int i=1;i<n;i++)
{
    int still=arr[i];
    int j=i-1;
    while(j>=0&&arr[j]>still)
    { comparisons++;
        arr[j+1]=arr[j];
        j--;
    }

    arr[j+1]=still;
/*
 * Best case is O(n)
 * worst case is O(n^2)
 * Average case os O(n^2)
 * comparisons n(n-1)/2
 */

}
    cout<<"Insertion sort \n";
cout<<"Insertion sort comparisons are "<<comparisons<<endl;
for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}

void selection_sort(int arr[],int n)
{
    /*
    Sorts an array by making several passes through the
    array, selecting the next smallest item in the array each
    time and placing it where it belongs in the array
     *
    It attempts to localize exchanges by putting the item
    directly in its final place.
     */
    int min,comparisons=0;
    for(int i=0;i<n-1;i++)
    {
        min=i;
        for(int j=i+1;j<n;j++)
        {
            comparisons++;
            if(arr[j]<arr[min])
            {
                min=j;
                swap(arr[i],arr[min]);
            }
        }

    }
    cout<<"Selection sort\n";
    //comparisons=N*(N-1)/2
    cout<<" Selection sort comparisons are "<<comparisons<<endl;

    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    /*
 * Best case is O(n^2)
 * worst case is O(n^2)
 * Average case os O(n^2)
    * comparisons n(n-1)/2
 */
}
//insertion has fewer comparisons than selection

void bubble_sort(int arr[],int n)
{
/*
Compares adjacent array elements and exchanges their
values if they are out of order
Smaller values bubble up to the top of the array and
larger values sink to the bottom
 */
int comparisons=0;
for(int i=0;i<n-1;i++)
{
    for( int j=0;j<n-i-1;j++)
    {
        comparisons++;
        if(arr[j]>arr[j+1])
        {
             swap(arr[j],arr[j+1]);
        }
    }
}
cout<<"Bubble sort\n";
    //comparisons=N*(N-1)/2
    cout<<"Bubble sort comparisons are "<<comparisons<<endl;

    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    /*
    Best case is O(1)
     worst case is O(n^2)
    Average case os O(n^2)
     comparisons n(n-1)/2
*/
}

void Shell_sort(int arr[],int n)
{
    /*
Start with sub arrays created by looking at data that is far apart and
then reduce the gap size
Donald Shell suggested that the initial separation
between indices be n/2 and halve this value at each
pass until it is 1.
Initial sorts are much smaller, the later sorts are on
arrays that are partially sorted, the final sort is on an
array that is almost entirely sorted.
     */

 int comparisons=0;
    for(int step=n/2;step>0;step/=2){
        for(int i=step;i<n;i++){
            int j=i;
            int key=arr[j];
            comparisons++;
            while(key<arr[j-step]&&j>=step)
            {


                arr[j]=arr[j-step];
                j-=step;

            }
            arr[j]=key;
        }
    }
    cout<<"Shell sort\n";
    cout<<"Shell sort comparisons are " << comparisons <<endl;
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    /*
   * Best case is  O(n log n)
   * worst case is O(n^3/2)
   * Average case os O(n^(5/4))
      * comparisons n(n-1)/2
   */
}

void Merge(int arr[],int left ,int Middle,int right )
{

int i,j,k;
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int n1=Middle -left +1;
int n2=right -Middle ;
int *L=new int[n1],*R=new int[n2];
for(i=0;i<n1;i++)
{
    L[i]=arr[left +i];
}
    for (j = 0; j < n2; j++) {
        R[j] = arr[Middle + j + 1];
    }
i=j=0;
k=left ;
while(i<n1 && j<n2)
{
    if(L[i]<=R[j])
    {
        arr[k]=L[i];
        i++;
    }
    else
    {
        arr[k]=R[j];
        j++;
    }
    k++;
}
while(i<n1)
{
    arr[k]=L[i];
    i++;
    k++;
}
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

}

void Merge_sort(int arr[], int left,int right)
{
    /*
       Access the first item from both sequences

       Compare the current items from the two sequences, copy the
       smaller current item to the output sequence, and access the
       next item from the input sequence whose item was copied

       Copy any remaining items from the first sequence to
       the output sequence

       Copy any remaining items from the second sequence
       to the output sequence
       */

    if(left <right )
    {
        int Middle = left + (right - left) / 2;
        Merge_sort(arr,left,Middle);
        Merge_sort(arr,Middle+1,right);

        Merge(arr,left,Middle,right);

    }
/*Best case: O(n log n)
Worst case: O(n log n)
Average case: O(n log n)
*/
}

int partition(int arr[], int left,int right)
{
    int pivot = arr[right]; // pivot
    int i = (left - 1); // Index of smaller element

    for (int j = left; j <= right - 1; j++)
    {
        // If current element is smaller than or equal to pivot
        if (arr[j] <= pivot)
        {
            i++; // increment index of smaller element
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[right]);
    return (i + 1);
}

void quickSort(int arr[], int left,int right)
{
    if (left < right)
    {
        int pi = partition(arr, left, right);
        quickSort(arr, left, pi - 1);
        quickSort(arr, pi + 1, right);
    }
}
int main() {
int arr[]={9,8,7,6,5,4,3,2,1,0};
    insertion_sort( arr,10);
    cout<< endl;
    selection_sort(arr,10);
    cout<< endl;
    bubble_sort(arr,10);
    cout<< endl;
    Shell_sort(arr,10);
    cout<< endl;
    Merge_sort(arr,0,9);

    cout<<"Merge sort\n";
    for(int i=0;i<(10);i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    quickSort(arr,0,9);
    cout<<"Quick sort\n";
    for(int i=0;i<(10);i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}
