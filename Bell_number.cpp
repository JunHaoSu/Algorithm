/*************************************************************************
	> File Name: Bell_number.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年03月11日 星期日 15时33分11秒
 ************************************************************************/

#include<iostream>
using namespace std;

int Stirling(int,int);

int Stirling(int m,int n){
    if(m==1)
        return 1;
    if(m==n)
        return 1;
    else
        return Stirling(m-1,n-1)+Stirling(m,n-1)*m;
}

int main(){
    int n,i;
    int sum=0;
    cout<<"输入n:";
    cin>>n;
    for(i=1;i<=n;i++){
        sum+=Stirling(i,n);
    }
    cout<<sum<<endl;
    return 0;
}
