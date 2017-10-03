/*************************************************************************
	> File Name: factorial.cpp
	> Author: sujunhao
	> Mail: sujunhao0504@gmail.com
	> Created Time: 2017年10月03日 星期二 22时14分50秒
 ************************************************************************/

#include<iostream>
using namespace std;

int factorial(int a){
    if (a==0){
        return 1;
    }
    else{
        return a*factorial(a-1);
    }
}

int main(){
    int n,result;
    cout<<"please input a number:";
    cin>>n;
    result=factorial(n);
    cout<<"the factorial of the number is:"<<result;
    return 0;
}
