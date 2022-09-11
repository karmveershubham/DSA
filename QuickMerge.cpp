#include<iostream>
#include<conio.h>
using namespace std;

void printArray(int arr[], int size){
    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void swap(int arr[], int i,int j){
    int temp=arr[i];
    arr[i]= arr[j];
    arr[j]=temp;
}

int partition(int arr[], int s, int e){
    int pivot=arr[e];
    int i=s-1;
    for(int j=s;j<e;j++){
        if(arr[j]<pivot){
            i++;
            swap(arr,i,j);
        }
    }
    swap(arr,i+1,e);
    return i+1;
}

void quickSort(int arr[],int s,int e){   // s start e end
    if(s<e){
        int pi=partition(arr,s,e);
        quickSort(arr,s,pi-1);
        quickSort(arr, pi+1 ,e);
    }
}

void merge(int arr[], int s, int mid, int e){
    int n1=mid-s+1;
    int n2=e-mid;

    int a[n1]; 
    int b[n2]; //temp arrays

    for(int i=0;i<n1;i++){
        a[i]=arr[s+i];
    }
    for(int i=0;i<n2;i++){
        b[i]=arr[mid+1+i];
    }
    int i=0,j=0; //pointer to travrerse array
    int k=s;

    while(i<n1 && j<n2){
        if(a[i]<b[j]){
            arr[k]=a[i];
            k++; i++;
        }
        else{
            arr[k]=b[j];
            k++; j++;
        }
    }
    while(i<n1){
        arr[k]=a[i];
        k++;i++;
    }

    while(j<n2){
        arr[k]=b[j];
        k++; j++;
    }
}

void mergeSort(int arr[], int s, int e){
    if(s<e){
        int mid=(s+e)/2;
        mergeSort(arr,s,mid);
        mergeSort(arr, mid+1, e);

        merge(arr,s,mid,e);
    }
}
int main(){
    int n;
    cout<<"Enter the size of array.: ";
    cin>>n;

    int arr[n];
    cout<<"Enter the elements of array: ";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int start=0;
    int end=n-1;
    cout<<"SORT\n1.Quick\n2.Merge\n";
    int ch;
    cout<<"Enter Choice: ";
    cin>>ch;
    if(ch==1){
    	quickSort(arr, start, end);
    }else if(ch==2){
    	mergeSort(arr, start, end);
    }else{
    	cout<<"Inavlaid choice."<<endl;
    }
    
    cout<<"The sorted array is.: ";
    printArray(arr, n);

    getch();
    return 0;
}
