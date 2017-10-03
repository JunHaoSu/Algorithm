/*************************************************************************
	> File Name: hanoi.cpp
	> Author: sujunhao
	> Mail: sujunhao0504@gmail.com
	> Created Time: 2017年10月03日 星期二 21时50分26秒
 ************************************************************************/

#include<iostream>
using namespace std;

void hanoi(int n,char a,char b,char c){
    if(n>0){
        hanoi(n-1,a,c,b);
        cout<<a<<"-->"<<c<<endl;
        hanoi(n-1,b,a,c);
    }

}

int main(){
    int n;
    char a='A',b='B',c='C';
    cout<<"Please input the number of disks:";
    cin>>n;
    hanoi(n,a,b,c);
    return 0;
}
