#include<iostream>
#include<conio.h>
using namespace std;
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
    int arr[]={7,6,5,4,3};
    mergeSort(arr,0,4);
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
	getch();
    return 0;
}
