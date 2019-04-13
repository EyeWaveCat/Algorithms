#include<iostream>


void generateArray(int a[],int size);
void printArray(int a[],int size);
void naivePolynomial(int x,int n);

int main()
{
    using namespace std;
    int n,x;
    
    cout<<"n = ";
    cin>>n;
    cout<<"x = ";
    cin>>x;

    naivePolynomial(x,n);
    
    return 0;
}

void naivePolynomial(int x,int n){
    int a[n];
    int b[n];
    generateArray(a,n);
    printArray(a,n);
    int y=a[0];
    for(int i=1;i<n;i++){
        b[i]=x;
        for(int j = n-i+1 ; j<n ; j++){
            b[i]*=x;  
        }
        y += a[i]*b[i];
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