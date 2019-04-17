#include<iostream>

int main(){
    using namespace std;

    int n;
    cout<<"Input a number:";
    cin>>n;


    int hole[n] ;
    for(int i=0;i<n;i++){
        hole[i]=0;
    }

    int findTimes = 100 * n;
    int currentHole;
    for(int i=0;i<findTimes;i++){
        currentHole = ((i+1)*(i+2)/2-1)%n;
        hole[currentHole] = 1;
    }

    for(int i=0;i<n;i++){
        if(hole[i] == 0){
            cout<< i+1<<" ";
        }
    }
    cout<<"end"<<endl;
    cin.get();
    cin.get();
    return 0;

}