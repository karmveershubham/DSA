#include <iostream>
#include<conio.h>
using namespace std;

int fib(int num) {
    if((num==1)||(num==0)) {
        return(num);
    }else {
        return(fib(num-1)+fib(num-2));
    }
}
int main() {
    int num , i=0;
    cout << "Enter the number of terms of series : ";
    cin >> num;
    cout << "Fibonnaci Series : ";
    while(i < num) {
        cout << " " << fib(i);
        i++;
    }
    getch();
return 0;
}
