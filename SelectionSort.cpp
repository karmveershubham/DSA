#include<iostream>
#include<conio.h>
using namespace std;

void swap(int *a,int *b){ 
    int temp = *a;
    *a = *b;
    *b=temp;
}
void printArray(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
// void selectionSort(int arr[],int n)  // repetitive swapping in this section 
// {
//     for(int i=0;i<n-1;i++){
//         for(int j=i+1;j<n;j++){
//             if(arr[j]<arr[i]){
//                 swap(&arr[j],&arr[i]);
//             }
//         }
//     }
// }

void selectionSort(int arr[],int n) //perfect condition for swapping 
{
    for (int i=0; i<n-1;i++){
        int min=i;
        for(int j=i+1; j<n; j++){
            if(arr[j]<arr[min]){
                min=j; 
            }
        }
        if(min!=i){
            swap(&arr[i], &arr[min]);
        }
    }
    
}

int main()
{
    int n;

    cout<<"Enter the size of array"<<endl;
    cin>>n;

    int arr[n];

    cout <<"Enter the elements of array "<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    selectionSort(arr,n);

    cout<<"The sorted array is:\t";
    printArray(arr,n);
    
    getch();
    return 0;
}
