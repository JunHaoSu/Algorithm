/*************************************************************************
	> File Name: Gray.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年03月11日 星期日 10时38分58秒
    格雷码构造规则。G(n+1)=0G(n) 1G-1(n)
 ************************************************************************/

#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
using namespace std;


int a[100];

void gray(int);
void out(int);
int dectobin(int);

int main(){
    int n;
    cout<<"输入n:";
    cin>>n;
    gray(n);
    out(n);
    return 0;
}

void gray(int n){
    if(n==1){
        a[1]=0;
        a[2]=1;
        return ;
    }
    gray(n-1);
    for (int k=1<<(n-1),i=k;i>0;i--){
        a[2*k-i+1]=a[i]+k;
    }
}

void out(int n){
    char str[32];
    int m=1<<n;
    int num;
    for (int i=1;i<=m;i++){
        num=dectobin(a[i]);
        sprintf(str,"%d",num);
        int s=strlen(str);
        for(int j=0;j<n-s;j++){
            cout<<"0";
        }
        cout<<str<<" ";
    }
    cout<<endl;
}

int dectobin(int n){
    int result=0,k=1,i,temp;
    temp=n;
    while(temp){
        i=temp%2;
        result = k*i +result;
        k=k*10;
        temp=temp/2;
    }
    return result;
}
