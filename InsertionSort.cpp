#include<iostream>
#include<conio.h>

using namespace std;
void printArray(int arr[], int size){
    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void insertionSort(int arr[], int size) {
    for(int i=1; i<size; i++)
    {
        int current = arr[i];
        int pre=i-1;
        while(arr[pre]>current && pre>=0)
        {
            arr[pre+1]=arr[pre];
            pre--;
        }
        arr[pre+1]=current;
    }
}  


int main(){
    int n;
    cout<<"Eneter the size of array.: ";
    cin>>n;

    int arr[n];
    cout<<"Enter the elements of array: ";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    insertionSort(arr, n);
    cout<<"The sorted array is.: ";
    printArray(arr, n);

    getch();
    return 0;
}