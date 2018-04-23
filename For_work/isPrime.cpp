/*************************************************************************
	> File Name: test.cpp
	> Author: JunHao SU
	> Mail: sujunhao0504@163.com
	> Created Time: 2018年04月21日 星期六 22时12分18秒
 ************************************************************************/

#include<iostream>
#include<cmath>
using namespace std;

bool isPrime(int number){
    if(number==1||number==0){
        return false;
    }
    if(number==2||number==3){
        return true;
    }
    if(number%6!=1&&number%6!=5){
        return false;
    }
    int tmp=sqrt(number);
    for(int i=5;i<=tmp;i+=6){
        if(number%i==0||number%(i+2)==0){
            return false;
        }
    }
    return true;
}

int main(){
    int n;
    int cnt=0;
    cin>>n;

    for(int i=3;i<=n;i++){
        if(isPrime(i)&&isPrime(i-2)){
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}
