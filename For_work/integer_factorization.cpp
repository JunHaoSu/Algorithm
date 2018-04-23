/*************************************************************************
	> File Name: integer_factorization.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年03月11日 星期日 16时25分46秒
 ************************************************************************/

#include<iostream>
using namespace std;

int count=0;

void solve(int);

void solve(int n){
    int i;
    if(n==1)
    count ++;
    for (i=2;i<=n;i++){
        if(n%i==0)
        solve(n/i);
    }
}

int main(){
    int n;
    cout<<"输入n:";
    cin>>n;
    solve(n);
    cout<<count<<endl;
    return 0;
}
