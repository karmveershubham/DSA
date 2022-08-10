#include<iostream>
#include<conio.h>
using namespace std;

int LinearSearch(int arr[], int n, int val){
    for(int i=0;i<n;i++){
        if(arr[i]==val){
            return i;
        }
    }
    return -1;
}

int main(){
    
    int n;
    cout<<"Enter the Size of array:  ";
    cin>>n;

    int arr[n];
    cout<<"Enter the elements of Array"<<endl;
    for (int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    int val;
    cout<<"Enter the value you want to search\t";
    cin>>val;

    
    int res=LinearSearch(arr,n, val);

    if(res==-1){
        cout<<"Element not found."<<endl;
    } else{
        cout<<"The searched value is at index:\t"<<res<<endl;
    }
    return 0;

}