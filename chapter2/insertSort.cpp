#include<iostream>
#include<cstdlib>
#include<ctime>


void generateArray(int a[],int size);
void printArray(int a[],int size);
void insertSort(int a[],int size);


int main(void)
{
    int array[100];
    int length = sizeof(array) / sizeof(array[0]);
    generateArray(array,length);
    printArray(array,length);
    insertSort(array,length);
    printArray(array,length);
    return 0;
}

void insertSort(int a[],int size)
{
    for(int j=1;j<size;j++){
        int in = a[j];
        int i = j - 1;
        while(a[i]>in && i>=0){
            a[i+1]= a[i];
            --i;
        }
        a[i+1] = in;
    }
}

void generateArray(int a[],int size)
{
    srand(time(NULL));
    for(int i=0;i<size;i++){
        a[i] = rand()%100;
    }
}

void printArray(int a[],int size)
{
    for(int i=0;i<size;i++){
       std::cout<<a[i]<<" ";
    }
    std::cout<<std::endl;
}