#include<iostream>


void generateArray(int a[],int size);
void printArray(int a[],int size);
void HornerPolynomial(int x,int n);

int main()
{
    using namespace std;
    int n,x;
    
    cout<<"n = ";
    cin>>n;
    cout<<"x = ";
    cin>>x;

    HornerPolynomial(x,n);
    
    return 0;
}

void HornerPolynomial(int x,int n){
    int a[n];
    int b[n];
    generateArray(a,n);
    printArray(a,n);
    int y=0;
    for(int i = n-1;i>=0;i--){
        y = a[i] + x*y;
    }

    std::cout<<"y = "<<y<<std::endl;
}

void generateArray(int a[],int size)
{
    for(int i=0;i<size;i++){
        a[i] = i;
    }
}

void printArray(int a[],int size)
{
    for(int i=0;i<size;i++){
       std::cout<<a[i]<<" ";
    }
    std::cout<<std::endl;
}