#include<iostream>

static int baseNum[10] = {0,1,2,3,4,5,6,7,8,9};

void getFourNum(int possibleFactor1[1680])
{
    int factor1 ;
    for(int i=1;i<10;i++){
        if(baseNum[i]==1){
            factor1 =i;
        }
    }
    int j=0;
    for(int i=1;i<10;i++){
        if(baseNum[i]==1){
            continue;
        }
        for(int k=1;k<10;k++){
            if(baseNum[k]==1){
            continue;
            }
            for(int l=1;l<10;l++){
                if(baseNum[l]==1){
                    continue;
                }
                for(int h=1;h<10;h++){
                    if(baseNum[h]==1){
                    continue;
                    }
                    possibleFactor1[++j] = i*1000+k*100+l*10+h;
                }
            }
        }
    }

}

void getAnotherFourNum(int possibleFactor2[24])
{

}

int main()
{
    int factor1,factor2,result;
    int possibleFactor1[1680];
    int possibleFactor2[24];
    for(int i=1;i<10;i++){
        baseNum[i] = 1;
        getFourNum(possibleFactor1);
        getFourNum(possibleFactor2);
        for(int j =0;j<1680;j++){
            for(int k=0;k<24;k++){
                factor1 = possibleFactor1[j];
                factor2 = possibleFactor2[k];
                if( (factor1*i)==factor2){
                    result = factor2;
                    std::cout<<factor1<<"*"<<i<<"="<<result<<std::endl;
                }else if((factor2*i)==factor1){
                    result = factor1;
                    std::cout<<factor2<<"*"<<i<<"="<<result<<std::endl;   
                }
            }
        }
    }
}