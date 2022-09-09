#include<iostream>
#include<conio.h>
using namespace std;

bool isSorted(int arr[], int n){
	for(int i=0; i<n; i++){
		if(arr[i]>arr[i+1]){
			return false;
			break;
		}	
	}
	return true;	
}

int binarySearch(int arr[], int n, int key)  //for sorted array
{  
    int s=0;
    int e=n;

    while(s<=e){
        int mid=(s+e)/2 ;

        if(arr[mid]==key){
            return mid;
        }
        else if(arr[mid]>key){
            e=mid-1;

        }else{
            s=mid+1;
        }
    }
    return -1;
}

int main()
{
    int n;
    cout<<"\nEnter the length of the array: ";
    cin>>n;
    
    int arr[n];
    cout<<"Enter the elements of the array.: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    if(!(isSorted(arr,n))){
        cout<<"Array not sorted.\n";
    }else{
        char ch='y';
        while(ch=='y'){
            int val;
            cout<<"Enter the value to be searched.: ";
            cin>>val;

            int res = binarySearch(arr,n,val);
            if(res==-1){
                cout<<"Element not found."<<endl;
            }else{
                cout<<"Element found at index.: "<<res<<endl;
            }
            cout<<"\nContinue?\t";
            cin>>ch;
        }
	}
    cout<<"Thanks"<<endl;

    getch();
    return 0;
}
