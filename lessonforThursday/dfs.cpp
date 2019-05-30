#include<iostream>

static int baseNum[10] = {0};

void getFourNum(int possibleFactor1[1680])
{
    
    int j=0;
    for(int i=1;i<10;i++){
        if(baseNum[i]==1){
            continue;
        }
        baseNum[i]= 1;
        for(int k=1;k<10;k++){
            if(baseNum[k]==1){
            continue;
            }
            baseNum[k]=1;
            for(int l=1;l<10;l++){
                if(baseNum[l]==1){
                    continue;
                }
                baseNum[l]=1;
                for(int h=1;h<10;h++){
                    if(baseNum[h]==1){
                    continue;
                    }
                    possibleFactor1[j++] = i*1000+k*100+l*10+h;
                }
                baseNum[l]=0;
            }
            baseNum[k]=0;
        }
        baseNum[i]=0;
    }
}

void getAnotherFourNum(int possibleFactor2[24], int factor)
{
    
    int factor1 ;
    for(int i=1;i<10;i++){
        if(baseNum[i]==1){
            factor1 =i;
        }
    }

    while(factor/10 > 0){
        baseNum[factor%10]=1;
        factor = factor/10;
    }
    baseNum[factor%10]=1;
    int j=0;
    for(int i=1;i<10;i++){
        if(baseNum[i]==1){
            continue;
        }
        baseNum[i]= 1;
        for(int k=1;k<10;k++){
            if(baseNum[k]==1){
            continue;
            }
            baseNum[k]=1;
            for(int l=1;l<10;l++){
                if(baseNum[l]==1){
                    continue;
                }
                baseNum[l]=1;
                for(int h=1;h<10;h++){
                    if(baseNum[h]==1){
                    continue;
                    }
                    possibleFactor2[j++] = i*1000+k*100+l*10+h;
                }
                baseNum[l]=0;
            }
            baseNum[k]=0;
        }
        baseNum[i]=0;
    }
    for(int i=1;i<10;i++){
        if(i!=factor1){
            baseNum[i]=0;
        }
    }
}

int main()
{
    int factor1,factor2,result;
    int possibleFactor1[1680];
    int possibleFactor2[24];
    for(int i=2;i<10;i++){
        baseNum[i] = 1;
        getFourNum(possibleFactor1);
        for(int j =0;j<1680;j++){
            factor1 = possibleFactor1[j];
            getAnotherFourNum(possibleFactor2,factor1);
            for(int k=0;k<24;k++){
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
