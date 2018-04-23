/*************************************************************************
	> File Name: banshuji.cpp
	> Author: sujunhao
	> Mail: sujunhao0504@gmail.com
	> Created Time: 2017年10月04日 星期三 10时59分59秒
 ************************************************************************/

#include<iostream>
#include<cmath>
int id=0;
int a[1000];

using namespace std;

void set(int n,int m,int j){
    for(int i=1;i<=n/2;i++){
        a[id+1]=m*i+a[j];
        id=id+1;
        if(i/2>0){
            set(i,m*10,id);
        }
    }
}

int main(){
    int s;
    cout<<"please input a number:";
    cin>>a[0];
    s=log10(a[0]);
    set(a[0],pow(10,s+1),0);
    cout<<"半数集为：";
    for(int i=0;i<id+1;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return 0;
}
