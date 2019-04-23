#include<iostream>
#include<cstdlib>
#include<ctime>
#include<chrono>

struct MaximumSubarray
{
    int begin;
    int end;
    int sum;
};


void generateArray(int a[],int size);
void getChangeArray(int ca[],int a[],int size);
void printArray(int a[],int size);
MaximumSubarray forceMaximumSubarray(int a[],int size);
MaximumSubarray linearMaximumSubarray(int a[],int size);

int main()
{
    using namespace std;
    int n;
    cout<<"Input a number as array length:";
    cin >> n;
    int array[n];
    int length = sizeof(array) / sizeof(array[0]);
    int carray[length-1];
    generateArray(array,length);
    getChangeArray(carray,array,length);

    MaximumSubarray fsa; 
    auto forceStart = std::chrono::system_clock::now();
    fsa = forceMaximumSubarray(carray,length-1);
    auto forceEnd = std::chrono::system_clock::now();
    cout<<"finally ("<<fsa.begin<<","<<fsa.end<<")"<<":"<<fsa.sum<<endl;


    MaximumSubarray lsa; 
    auto linearStart = std::chrono::system_clock::now();
    lsa = linearMaximumSubarray(carray,length-1);
    auto linearEnd = std::chrono::system_clock::now();
    cout<<"finally ("<<lsa.begin<<","<<lsa.end<<")"<<":"<<lsa.sum<<endl;



    

    std::chrono::duration<double> linearTimeUse = linearEnd - linearStart;
    std::chrono::duration<double> forceTimeUse = forceEnd - forceStart;
    cout<<"recusiveTimeUse: "<<linearTimeUse.count()<<", forceTimeUse: "<<linearTimeUse.count()<<endl;
}

MaximumSubarray linearMaximumSubarray( int a[],int size){
    MaximumSubarray sa;
    sa.sum = INT_MIN;
    int sum =0;
    int tempBegin = 0;
    for(int i=0;i<size;i++){
        sum += a[i];
        if(sum > sa.sum){
            sa.begin = tempBegin;
            sa.end = i;
            sa.sum = sum;
        }
        if(sum<0){
            sum =0;
            tempBegin =i+1;
        }
        
    }
  return sa;
}

MaximumSubarray forceMaximumSubarray(int a[],int size)
{
    MaximumSubarray sa;
    sa.sum =INT_MIN;
    for(int i=0;i<size;i++)
    { 
        int temp=0;
        for(int j=i;j<size;j++)
        {
             temp += a[j];
           if(temp> sa.sum){
               sa.begin =i;
               sa.end = j;
               sa.sum = temp;
               
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

void getChangeArray(int ca[],int a[],int size)
{
    using namespace std;
    for(int i=1;i<size;i++){
        ca[i-1] = a[i] - a[i-1];
    }
    cout<<endl;
}
