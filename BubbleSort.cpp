#include<iostream>
#include<conio.h>
using namespace std;

void swap(int *a, int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
void printArray(int arr[],int size) 
{
    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }

}
// void Bubblesort(int arr[], int size)
// {
//     int iteration=1;
//     while(iteration<size)
//     {
//         for(int i=0; i<size-iteration; i++){
//         {
//             if(arr[i]>arr[i+1])
//             {
//                 swap(&arr[i], &arr[i+1]);
//             }
//         }
//         iteration++;
//     }
// }
void Bubblesort(int arr[], int size)
{
    for(int i=1;i<size; i++)
    {
        for(int j=0;j<size-i; j++)
        {
            if(arr[j]>arr[j+1])
            {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

int main()
{
    int n;
    cout<<"Enter the size of array.: ";
    cin>>n;

    int arr[n];
    cout<<"Enter the elements of array.: ";
    for (int i=0; i<n; i++){
        cin>>arr[i];
    }

    Bubblesort(arr, n);

    cout<<"The sorted array is:\t";
    printArray(arr, n);

    getch();
    return 0;
}