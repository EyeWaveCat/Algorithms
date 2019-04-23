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
void getChangeArray(int ca[],int a[],int size);
void printArray(int a[],int size);
MaximumSubarray forceMaximumSubarray(int a[],int size);

MaximumSubarray findMaximumSubarray(int a[],int begin,int end);
MaximumSubarray findMidMaximumSubarray(int a[],int begin,int mid,int end);

int main(void)
{
    using namespace std;
    int array[10];
    int length = sizeof(array) / sizeof(array[0]);
    int carray[length-1];
    generateArray(array,length);
    getChangeArray(carray,array,length);
    printArray(array,length);
    printArray(carray,length-1);
    MaximumSubarray sa = findMaximumSubarray(carray,0,length-2);
    cout<<"finally ("<<sa.begin<<","<<sa.end<<")"<<":"<<sa.sum<<endl;
    forceMaximumSubarray(array,length);
    cout<<"finally ("<<sa.begin<<","<<sa.end<<")"<<":"<<sa.sum<<endl;
    return 0;
}

 MaximumSubarray findMidMaximumSubarray(int a[],int begin,int mid,int end)
 {
    using namespace std;
    MaximumSubarray sa;
    int leftSum = INT_MIN;
    int sum = 0;
    for(int i =mid ;i>=begin;i--){
        sum+= a[i];
        if(sum> leftSum){
            sa.begin = i;
            leftSum = sum;
        }
    }
    sum= 0;
    int rightSum =INT_MIN;
    for(int i =mid+1 ;i<=end;i++){
        sum+= a[i];
        if(sum> rightSum){
            sa.end = i;
            rightSum = sum;
        }
    }
    sa.sum = leftSum + rightSum;
    return sa;
 }

MaximumSubarray forceMaximumSubarray(int a[],int size)
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

MaximumSubarray findMaximumSubarray(int a[],int begin,int end)
{
    using namespace std;
    MaximumSubarray sa;
    if(begin == end){
            sa.begin = begin;
            sa.end = end;
            sa.sum = a[begin];
            return sa;
    }
    int mid = (begin+end)/2;
    MaximumSubarray la = findMaximumSubarray(a,begin,mid);
    MaximumSubarray ra = findMaximumSubarray(a,mid+1,end);
    MaximumSubarray ma = findMidMaximumSubarray(a,begin,mid,end);
    if(la.sum > ra.sum && la.sum > ma.sum){
        return la;
    }else if(ra.sum > la.sum && ra.sum > ma.sum){
        return ra;
    }else{
        return ma;
    }
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
    for(int i=1;i<size;i++){
        ca[i] = a[i] - a[i-1];
    }
}

void printArray(int a[],int size)
{
    for(int i=0;i<size;i++){
       std::cout<<a[i]<<" ";
    }
    std::cout<<std::endl;
}