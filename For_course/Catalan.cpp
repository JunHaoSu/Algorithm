/*************************************************************************
	> File Name: Catalan.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年03月11日 星期日 16时12分18秒
 ************************************************************************/

#include<iostream>
using namespace std;

int c[100];
void catalan(int);

void catalan(int n){
    int i,j;
    c[1]=1;
    for (i=2;i<=n;i++){
        c[i]=c[i-1]*(4*i-2)/(i+1);
    }
}

int main(){
    int n;
    cout<<"输入n:";
    cin>>n;
    catalan(n);
    cout<<c[n]<<endl;
    return 0;
}
