#include<iostream>
#include<cstdlib>
#include<ctime>

struct MaximumSubarray
{
    int begin;
    int end;
    int sum;
};


void generateArray(int a[],int size);
void printArray(int a[],int size);
MaximumSubarray findMaximumSubarray(int a[],int size);


int main(void)
{
    using namespace std;
    int array[10];
    int length = sizeof(array) / sizeof(array[0]);
    generateArray(array,length);
    printArray(array,length);
    MaximumSubarray sa = findMaximumSubarray(array,length);
    cout<<"("<<sa.begin<<","<<sa.end<<")"<<":"<<sa.sum<<endl;
    return 0;
}

MaximumSubarray findMaximumSubarray(int a[],int size)
{
    MaximumSubarray sa;
    int sum = INT_MIN;
    for(int i =0;i<size-1;i++){
        for(int j =i+1;j<size;j++){
            if(sum<(a[i]-a[j])){
                sum = a[i]-a[j];
                sa.begin = i;
                sa.end = j;
                sa.sum = sum;
            }
        }
    }

    return sa;

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