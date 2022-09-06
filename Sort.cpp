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

void bubbleSort(int arr[], int size)
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

void selectionSort(int arr[],int n)  
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

int main()
{
    char ch='y';
	while(ch=='y'){
    int n;
    cout<<"Enter the size of array.: ";
    cin>>n;

    int arr[n];
    cout<<"Enter the elements of array.: ";
    for (int i=0; i<n; i++){
        cin>>arr[i];
    }
    
    int opt;
    cout<<"Sorting Methods\n";
    cout<<"\n1.Bubble sort\n2.SelectionSort\n3.InsertionSort.\n";
    cout<<"\nSelect Method: ";
    cin>>opt;
    switch(opt){
        case 1:{
            bubbleSort(arr, n);
            cout<<"The sorted array is:\t";
            printArray(arr, n);
            break;
        }
        case 2:{
            selectionSort(arr, n);
            cout<<"The sorted array is:\t";
            printArray(arr, n);
            break;
        }
        case 3:{
            insertionSort(arr, n);
            cout<<"The sorted array is:\t";
            printArray(arr, n);
            break;
        }
        default: {
            cout<<"Invalid choice";
        }
    }
    
    cout<<"\nContinue?\t";
    cin>>ch;
    cout<<endl;
	}
	cout<<"Thanks!";
    getch();
    return 0;
}
