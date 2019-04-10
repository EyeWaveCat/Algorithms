#include<iostream>
#include<cstdlib>
#include<ctime>
#include<climits>

static int count =0;
void generateArray(int a[],int size);
void printArray(int a[],int size);
void mergeSort(int a[],int begin,int end);
void merge(int a[],int begin,int mid,int end);


int main(void)
{
    
    int array[10];
    int length = sizeof(array) / sizeof(array[0]);
    generateArray(array,length);
    printArray(array,length);
    mergeSort(array,0,length-1);
    printArray(array,length);

    
    std::cout<<"count = "<<count<<std::endl;
    return 0;
}

void mergeSort(int a[],int begin,int end)
{
    if(begin<end){
        int mid = (begin + end) / 2;
        mergeSort(a,begin,mid);
        mergeSort(a,mid+1,end);
        merge(a,begin,mid,end);
    }
}

void merge(int a[],int begin,int mid,int end)
{
   
    int l1 = mid - begin + 1;
    int l2 = end - mid;
    int temp1[l1+1];
    int temp2[l2+1];
    for(int i =0;i<l1;i++){
        temp1[i] = a[begin+i];
    }
    temp1[l1] = INT_MAX;
    for(int i =0;i<l2;i++){
        temp2[i] = a[mid+1+i];
    }
    temp2[l2] = INT_MAX;

    int k =0,j=0;
    for(int i = begin;i<end+1;i++){
        if(temp1[k]<=temp2[j]){
            a[i] = temp1[k];
            k++;
        }else{
            a[i] = temp2[j];
            j++;
            if(!(temp2[j]==INT_MAX))
                count++;
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

