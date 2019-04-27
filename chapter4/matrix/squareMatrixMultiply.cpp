#include<iostream>
#include<ctime>
#include<vector>
 using namespace std;

struct ArrayLimit
{
    int starti;
    int startj;
    int endi;
    int endj;
    int size;
};

//helper function
void generateArray( vector<vector<int> >& v , int size );    
void generateResultArray( vector< vector<int> >& v , int size );
void printArray( vector<vector<int> >& v , int size );   
void partArray(ArrayLimit& aLimit , ArrayLimit& a11 , ArrayLimit& a12 ,ArrayLimit& a21 ,ArrayLimit& a22 );


//general multiply add and sub
void squareMatrixMultiply(vector<vector<int> >& c, vector<vector<int> >& a, vector<vector<int> >& b,ArrayLimit& limit);
void squareMatrixAdd( vector<vector<int> >& c , vector<vector<int> >& a, 
                     vector<vector<int> >& b,ArrayLimit& aLimit,ArrayLimit& bLimit,ArrayLimit& cLimit);
void squareMatrixSub(vector<vector<int> >& c , vector<vector<int> >& a,
                     vector<vector<int> >& b,ArrayLimit& aLimit,ArrayLimit& bLimit,ArrayLimit& cLimit);

//recursive multiply and strassen multiply
vector<vector<int> > squareMatrixMultiplyRecursive(vector<vector<int> >& c, vector<vector<int> >& a,
                                        vector<vector<int> >& b,ArrayLimit& aLimit,ArrayLimit& bLimit,ArrayLimit& cLimit);

vector<vector<int> > strassenMatrixMultiplyRecursive(vector<vector<int> >& c, vector<vector<int> >& a,
                                        vector<vector<int> >& b,ArrayLimit& aLimit,ArrayLimit& bLimit,ArrayLimit& cLimit);



int main()
{
    srand(time(NULL));
    int size;
    cout<<"Input a number as square array size"<<endl;
    cin>> size;
    vector< vector<int> > a;
    vector< vector<int> > b;
    vector< vector<int> > c;
    generateArray(a,size);
    generateArray(b,size);
    generateResultArray(c,size);
    ArrayLimit limit ={0,0,size,size,size};
    printArray(a,size);
    printArray(b,size);
    strassenMatrixMultiplyRecursive(c,a,b,limit,limit,limit);
    printArray(c,size);

    squareMatrixMultiply(c,a,b,limit);
    printArray(c,size);

    squareMatrixMultiplyRecursive(c,a,b,limit,limit,limit);
    printArray(c,size);
    return 0;
}


void generateResultArray( vector< vector<int> >& v , int size )
{
    //generate an array contains only 0 as result array
    vector<int > temp;
    
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            temp.push_back(0);
        }
        v.push_back(temp);
        temp.clear();
    }

}

void generateArray( vector< vector<int> >& v , int size )
{
    //generate an array contains random values  
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


void squareMatrixMultiply(vector<vector<int> >& c, vector<vector<int> >& a, vector<vector<int> >& b, ArrayLimit& limit)
{
    //force multiply 
    for(int i=limit.starti;i< limit.endi;i++){
        for(int j=limit.startj;j<limit.endj;j++){
            c[i][j] = 0;
            for(int k=limit.starti;k<limit.endi;k++){
                c[i][j] = c[i][j] + a[i][k] * b[k][j];
            }
        }
    }
}

vector<vector<int> > squareMatrixMultiplyRecursive(vector<vector<int> >& c, vector<vector<int> >& a, vector<vector<int> >& b, ArrayLimit& aLimit,ArrayLimit& bLimit,ArrayLimit& cLimit)
{
    //recursive multiply for 2n array
    if(aLimit.size == 1){
        c[cLimit.starti][cLimit.startj] = a[aLimit.starti][aLimit.startj] * b[bLimit.starti][bLimit.startj];
    }else{
        ArrayLimit a11 , a12 , a21 , a22 , b11 , b12 , b21 , b22,c11 ,c12 ,c21 , c22;
        partArray(aLimit, a11, a12 , a21 , a22);
        partArray(bLimit, b11 , b12 , b21 , b22);
        partArray(cLimit,c11 ,c12 ,c21 , c22);
        int size = c.size();
        vector<vector<int> > temp;
        generateResultArray(temp,size);
        vector<vector<int> > lArray = squareMatrixMultiplyRecursive(temp,a,b,a11,b11,c11);
        vector<vector<int> > rArray = squareMatrixMultiplyRecursive(temp,a,b,a12,b21,c12);
        squareMatrixAdd(c,lArray,rArray,c11,c12,c11);
        lArray = squareMatrixMultiplyRecursive(temp,a,b,a11,b12,c11);
        rArray = squareMatrixMultiplyRecursive(temp,a,b,a12,b22,c12);
        squareMatrixAdd(c,lArray,rArray,c11,c12,c12);
        lArray = squareMatrixMultiplyRecursive(temp,a,b,a21,b11,c11);
        rArray = squareMatrixMultiplyRecursive(temp,a,b,a22,b21,c12);
        squareMatrixAdd(c,lArray,rArray,c11,c12,c21);
        lArray = squareMatrixMultiplyRecursive(temp,a,b,a21,b12,c11);
        rArray = squareMatrixMultiplyRecursive(temp,a,b,a22,b22,c12);
        squareMatrixAdd(c,lArray,rArray,c11,c12,c22);
          
        
    }
    return c;
}

vector<vector<int> > strassenMatrixMultiplyRecursive(vector<vector<int> >& c, vector<vector<int> >& a,
                                        vector<vector<int> >& b,ArrayLimit& aLimit,ArrayLimit& bLimit,ArrayLimit& cLimit)
{
    if(aLimit.size == 1){
        c[cLimit.starti][cLimit.startj] = a[aLimit.starti][aLimit.startj] * b[bLimit.starti][bLimit.startj];
    }else{
        ArrayLimit a11 , a12 , a21 , a22 , b11 , b12 , b21 , b22,c11 ,c12 ,c21 , c22;
        partArray(aLimit, a11, a12 , a21 , a22);
        partArray(bLimit, b11 , b12 , b21 , b22);
        partArray(cLimit,c11 ,c12 ,c21 , c22);
        
        int helpArraySize = a11.size;
        ArrayLimit helpLimit = {0,0,helpArraySize,helpArraySize,helpArraySize};
        vector<vector<int> > s1,s2,s3,s4,s5,s6,s7,s8,s9,s10,p1,p2,p3,p4,p5,p6,p7;
        generateResultArray(s1,helpArraySize);
        generateResultArray(s2,helpArraySize);
        generateResultArray(s3,helpArraySize);
        generateResultArray(s4,helpArraySize);
        generateResultArray(s5,helpArraySize);
        generateResultArray(s6,helpArraySize);
        generateResultArray(s7,helpArraySize);
        generateResultArray(s8,helpArraySize);
        generateResultArray(s9,helpArraySize);
        generateResultArray(s10,helpArraySize);

        generateResultArray(p1,helpArraySize);
        generateResultArray(p2,helpArraySize);
        generateResultArray(p3,helpArraySize);
        generateResultArray(p4,helpArraySize);
        generateResultArray(p5,helpArraySize);
        generateResultArray(p6,helpArraySize);
        generateResultArray(p7,helpArraySize);

        squareMatrixSub(s1,b,b,b12,b22,helpLimit);
        squareMatrixAdd(s2,a,a,a11,a12,helpLimit);
        squareMatrixAdd(s3,a,a,a21,a22,helpLimit);
        squareMatrixSub(s4,b,b,b21,b11,helpLimit);
        squareMatrixAdd(s5,a,a,a11,a22,helpLimit);
        squareMatrixAdd(s6,b,b,b11,b22,helpLimit);
        squareMatrixSub(s7,a,a,a12,a22,helpLimit);
        squareMatrixAdd(s8,b,b,b21,b22,helpLimit);
        squareMatrixSub(s9,a,a,a11,a21,helpLimit);
        squareMatrixAdd(s10,b,b,b11,b12,helpLimit);

        p1 = strassenMatrixMultiplyRecursive(p1,a,s1,a11,helpLimit,helpLimit);
        p2 = strassenMatrixMultiplyRecursive(p2,s2,b,helpLimit,b22,helpLimit);
        p3 = strassenMatrixMultiplyRecursive(p3,s3,b,helpLimit,b11,helpLimit);
        p4 = strassenMatrixMultiplyRecursive(p4,a,s4,a22,helpLimit,helpLimit);
        p5 = strassenMatrixMultiplyRecursive(p5,s5,s6,helpLimit,helpLimit,helpLimit);
        p6 = strassenMatrixMultiplyRecursive(p6,s7,s8,helpLimit,helpLimit,helpLimit);
        p7 = strassenMatrixMultiplyRecursive(p7,s9,s10,helpLimit,helpLimit,helpLimit);

        
        squareMatrixAdd(c,p5,p4,helpLimit,helpLimit,c11);
        squareMatrixSub(c,c,p2,c11,helpLimit,c11);
        squareMatrixAdd(c,c,p6,c11,helpLimit,c11);

        squareMatrixAdd(c,p1,p2,helpLimit,helpLimit,c12);

        squareMatrixAdd(c,p3,p4,helpLimit,helpLimit,c21);

        squareMatrixAdd(c,p5,p1,helpLimit,helpLimit,c22);
        squareMatrixSub(c,c,p3,c22,helpLimit,c22);
        squareMatrixSub(c,c,p7,c22,helpLimit,c22);
    }
    return c;
}


void partArray(ArrayLimit& aLimit , ArrayLimit& a11 , ArrayLimit& a12 ,ArrayLimit& a21 ,ArrayLimit& a22 )
{
    //partition array for 4 part 
        int midi = (aLimit.starti +aLimit.endi) / 2;
        int midj = (aLimit.startj +aLimit.endj) / 2;
        int aSubSize = midi - aLimit.starti;
        a11 = {aLimit.starti , aLimit.startj , midi , midj , aSubSize };
        a12 = {aLimit.starti,midj,midi,aLimit.endj,aSubSize };
        a21 = {midi , aLimit.startj , aLimit.endi , midj , aSubSize};
        a22 = {midi,midj,aLimit.endi,aLimit.endj ,aSubSize };
}

void squareMatrixAdd( vector<vector<int> >& c , vector<vector<int> >& a, vector<vector<int> >& b,ArrayLimit& aLimit,ArrayLimit& bLimit,ArrayLimit& cLimit)
{
    for(int ai=aLimit.starti,bi = bLimit.starti,ci = cLimit.starti,cj = cLimit.startj;(ai<aLimit.endi) && (bi<bLimit.endi);ai++,bi++,ci++){
        for(int aj=aLimit.startj,bj = bLimit.startj,cj = cLimit.startj;(aj<aLimit.endj) && (bj<bLimit.endj);aj++,bj++,cj++){
            c[ci][cj] = a[ai][aj] + b[bi][bj];
        }
    }

}

void squareMatrixSub( vector<vector<int> >& c , vector<vector<int> >& a, vector<vector<int> >& b,ArrayLimit& aLimit,ArrayLimit& bLimit,ArrayLimit& cLimit)
{
     for(int ai=aLimit.starti,bi = bLimit.starti,ci = cLimit.starti,cj = cLimit.startj;(ai<aLimit.endi) && (bi<bLimit.endi);ai++,bi++,ci++){
        for(int aj=aLimit.startj,bj = bLimit.startj,cj = cLimit.startj;(aj<aLimit.endj) && (bj<bLimit.endj);aj++,bj++,cj++){
            c[ci][cj] = a[ai][aj] - b[bi][bj];
        }
    }

}
