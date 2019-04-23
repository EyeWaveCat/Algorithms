#include<iostream>
#include<ctime>
#include<vector>
 using namespace std;


void generateArray( vector<vector<int> >& v , int size );    
void printArray( vector<vector<int> >& v , int size );   
vector<vector<int> > squareMatrixMultiply( vector<vector<int> >& a, vector<vector<int> >& b);


int main()
{
    srand(time(NULL));
    int size;
    cout<<"Input a number as square array size"<<endl;
    cin>> size;
    vector< vector<int> > a;
    vector< vector<int> > b;
    generateArray(a,size);
    generateArray(b,size);
    printArray(a,size);
    printArray(b,size);
    vector< vector<int> > c = squareMatrixMultiply(a,b);
    printArray(c,size);

    return 0;
}



void generateArray( vector< vector<int> >& v , int size )
{
    vector<int > temp;
    
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            temp.push_back(rand()%100);
        }
        v.push_back(temp);
        temp.clear();
    }

}

void printArray( vector<vector<int> >& v , int size )
{
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}


vector<vector<int> > squareMatrixMultiply( vector<vector<int> >& a, vector<vector<int> >& b)
{
    vector<vector<int> > c;
    int size = a.size();
    generateArray(c,size);
    for(int i=0;i< size;i++){
        for(int j=0;j<size;j++){
            c[i][j] = 0;
            for(int k=0;k<size;k++){
                c[i][j] = c[i][j] + a[i][k] * b[k][j];
            }
        }
    }
    return c;
}