#include<iostream>
#include<cmath>

int findMaximumProduct(int n);
int main(){
    using namespace std;
    int n;
    cout<<"Enter a positive number you like:";
    cin>>n;
    int product;
    cout<<findMaximumProduct(n);
    cin.get();
    cin.get();
    return 0;
}



int findMaximumProduct(int n){
    if(n>3){
        if(n%3 == 0){
            return  pow(3,n/3);
        }else if((n%2) == 0){
            return findMaximumProduct(n/2)*findMaximumProduct(n/2);
        }else{
            return findMaximumProduct(n/2)*findMaximumProduct(n/2 + 1);
        }
    }else{
            return n;
    }
}