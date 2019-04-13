#include<iostream>
#include<cstdlib>
#include<ctime>


void generateArray(int a[],int size);
void printArray(int a[],int size);
void bubbleSort(int a[],int size);


int main(void)
{
    int array[100];
    int length = sizeof(array) / sizeof(array[0]);
    generateArray(array,length);
    printArray(array,length);
    bubbleSort(array,length);
    printArray(array,length);
    return 0;
}

void bubbleSort(int a[],int size)
{
    int j,i;
    for(j=size-1;j>0;j--){
        for(i = 0;i<j;i++){
            if(a[i]>a[i+1]){
                int temp = a[i+1] ;
                a[i+1] = a[i];
                a[i]=temp; 
            }
        }
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