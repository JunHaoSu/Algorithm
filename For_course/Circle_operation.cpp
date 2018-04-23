/*************************************************************************
	> File Name: Circle_operation.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年03月22日 星期四 21时22分14秒
 ************************************************************************/

#include<iostream>
#include<cmath>
#include<algorithm>
#include<fstream>

using namespace std;

const int INT_MAX=10000;

int S1;//N的值
int S2;//K的值
int BIG;//最大取值
int **num;
int i,j,k;

void count(int one[],int i){
    int t;
    int max=0;
    int min=10;
    int sum=0;
    while(i){
        t=i%10;
        if(t>max)
            max=t;
        if(t<min)
            min=t;
        sum += t;
        i /=10;//i等于i除以10
    }
    one[1]=min;
    one[2]=max;
    one[3]=sum;
}

void init(){
    int m=ceil(log(S1+1)/log(10));
    BIG=81*m+9;
    if(BIG<171) BIG=171;
    num = new int*[BIG+1];
    for(i=0;i<=BIG;i++){
        num[i]=new int[4];
    }
    for(i=1;i<=BIG;i++){
        num[i][0]=INT_MAX;//圈乘最小次数
        num[i][1]=INT_MAX;//i的最小数字
        num[i][2]=0;//i的最大数字
        num[i][3]=0;//数i的数字和
    }
    for (i=1;i<=BIG;i++){
        count(num[i],i);
    }
    num[0][0]=0;
    count(num[0],S1);
}

int compute(){
    if(S1==S2){
        return 0;
    }
    if(S2 > BIG){
        return -1;
    }

    bool flag = true;
    while(flag){
        flag=false;
        for(i=0;i<=BIG;i++){
            if(num[i][0]<INT_MAX){//确保i算过
                for(j=0;j<=BIG;j++){
                    if(num[j][0]<INT_MAX){//确保j算过
                        int cache=num[i][3]*num[j][2]+num[j][1];//算k
                        if(num[cache][0]>num[i][0]+num[j][0]+1){//如果算到k的原值比现在大，用现在的替换
                            num[cache][0]=num[i][0]+num[j][0]+1;
                            flag=true;//继续循环
                        }
                    }
                }
            }
        }
    }
    if(num[S2][0]<INT_MAX){
        return num[S2][0];
    }else{
        return -1;
    }
}

int main(){
    ifstream fin;
    ofstream fout;
    fin.open("Circle_operation_input.txt");
    fout.open("Circle_operation_output.txt");
    fin>>S1;
    fin>>S2;
    init();
    fout<<compute();
    return 0;
}
