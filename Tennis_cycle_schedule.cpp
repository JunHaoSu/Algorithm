/*************************************************************************
	> File Name: Tennis_cycle_schedule.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年03月11日 星期日 13时19分05秒
    网球循环赛，一个分治法填表的过程
 ************************************************************************/

#include<iostream>
using namespace std;

void copy(int);
void copyodd(int);
void tournamont(int);
void makecopy(int);

int a[100][100];
int b[100];

int main(){
    int n;
    cout<<"输入队员人数:";
    cin>>n;
    tournamont(n);
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            cout<<a[i][j]<<' ';
        }
        cout<<endl;
    }
    return 0;
}

void copy(int n){
   int m=n/2;
   for (int i=1;i<=m;i++){
       for(int j=1;j<=m;j++){
           a[i][j+m]=a[i][j]+m;
           a[i+m][j]=a[i][j+m];
           a[i+m][j+m]=a[i][j];
       }
   }
}

void tournamont(int n){
    if(n==1){
        a[1][1]=1;
        return;
    } 
    if(n&1){
        tournamont(n+1);
        return;
    }
    tournamont(n/2);
    makecopy(n);
}

void makecopy(int n){
    if(n/2>1 && ((n/2)&1)) copyodd(n);
    else copy(n);
}

void copyodd(int n){
    int m=n/2;
    for(int i=1;i<=m;i++){
        b[i]=m+i;
        b[m+i]=b[i];
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=m+1;j++){
            if(a[i][j]>m){
                a[i][j]=b[i];
                a[m+i][j]=(b[i]+m)%n;
            }
            else{
                a[m+i][j]=a[i][j]+m;
            }
        }
        for(int j=2;j<=m;j++){
            a[i][m+j]=b[i+j-1];
            a[b[i+j-1]][m+j]=i;
        }
    }
}

