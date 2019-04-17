#include<iostream>

int findMaximumProduct(int n);

int main(){
    using namespace std;
    int n;
    cout<<"Enter a positive number you like:";
    cin>>n;
    int product;
    cout<<findMaximumProduct(10);
    cin.get();
    cin.get();
    return 0;
}



int findMaximumProduct(int n){
    if(n>3){
        if((n%2) == 0){
            return findMaximumProduct(n/2)*findMaximumProduct(n/2);
        }else{
            return findMaximumProduct(n/2)*findMaximumProduct(n/2 + 1);
        }
    }else{
            return n;
    }
}