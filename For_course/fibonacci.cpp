/*************************************************************************
	> File Name: fibonacci.cpp
	> Author: sujunhao
	> Mail: sujunhao0504@gmail.com
	> Created Time: 2017年10月03日 星期二 22时26分00秒
 ************************************************************************/

#include<iostream>
using namespace std;

int fibonacci(int n){
    if (n>1){
        return fibonacci(n-1)+fibonacci(n-2);
    }
    else{
        return 1;
    }
}

int main(){
    int n,result;
    cout<<"please input a number:";
    cin>>n;
    cout<<"fibonacci is:";
    for (int i=0;i<n;i++){
        result=fibonacci(i);
        cout<<result<<",";
    }
    return 0;
}
