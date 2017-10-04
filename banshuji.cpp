/*************************************************************************
	> File Name: banshuji.cpp
	> Author: sujunhao
	> Mail: sujunhao0504@gmail.com
	> Created Time: 2017年10月04日 星期三 10时59分59秒
 ************************************************************************/

#include<iostream>
using namespace std;

int set(int n){
    int cnt =1;
    if(n>=2){
        for(int i=1;i<=n/2;i++){
            cnt=cnt+set(i);
        }
    }
    return cnt;
}

int main(){
    int s;
    cout<<"please input a number:";
    cin>>s;
    cout<<set(s)<<endl;
}
