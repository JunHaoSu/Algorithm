/*************************************************************************
	> File Name: array_right_shift.cpp
	> Author: JunHao SU
	> Mail: sujunhao0504@163.com
	> Created Time: 2018年04月21日 星期六 22时32分32秒
 ************************************************************************/

#include<iostream>
using namespace std;

int n[100];

void move(int *a,int head,int tail){
    int i;
    for(i=head;i<=(head+tail)/2;i++){
        int tmp=a[i];
        a[i]=a[head+tail-i];
        a[head+tail-i]=tmp;
    }
}

int main(){
    int number,times,i;
    cin>>number>>times;
    if(times>=number){
        times=times%number;
    }
    for(i=0;i<number;i++){
        cin>>n[i];
    }
    move(n,0,number-times-1);
    move(n,number-times,number-1);
    move(n,0,number-1);
    for(i=0;i<number;i++){
        cout<<n[i];
        if(i<number-1){
            cout<<" ";
        }
    }
    cout<<endl;
}
