#include<iostream>
#include<cstdlib>
#include<ctime>
#include<climits>


void generateArray(int a[],int size);
void printArray(int a[],int size);
void selectSort(int a[],int size);
int  findIn(int a[],int size);


int main(void)
{
    int array[100];
    int length = sizeof(array) / sizeof(array[0]);
    generateArray(array,length);
    printArray(array,length);
    selectSort(array,length);
    printArray(array,length);
    return 0;
}

void selectSort(int a[],int size)
{
    for(int i = 0; i < size; i++){
        int index = findIn(a + i,size -i);
        int temp = a[i];
        a[i] = a[index + i];
        a[index+i] = temp;
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

int  findIn(int a[],int size)
{
    int min = INT_MAX;
    int index;
    for (int i =0;i<size;i++) {
        if(a[i]<min){
            min = a[i];
            index = i;
        }
    }
    return index;
}
