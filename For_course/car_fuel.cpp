/*************************************************************************
	> File Name: car_fuel.cpp
	> Author: sujunhao
	> Mail: sujunhao0504@gmail.com
	> Created Time: 2017年11月11日 星期六 19时29分10秒
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

int fuel(vector<int>x,int n){
    int sum=0,count=0;
    for(int i=0;i<x.size();i++){
        if(x[i]>n){
            cout<<"No Solition"<<endl;
            return -1;
        }
    }
    for(int i=0;i<x.size();i++){
        count+=x[i];
        if(count>n){
            sum++;
            count=x[i];
        }
    }
    return sum;
}

int main(){
    int j,k,n,result;
    vector<int>x;
    cout<<"输入满油可行驶nkm："<<endl;
    cin>>n;
    cout<<"输入加油站个数K:"<<endl;
    cin>>j;
    cout<<"输入加油站之间的距离:"<<endl;
    for(int i=0;i<j+1;i++){
        cin>>k;
        x.push_back(k);
    }
    result=fuel(x,n);
    if(result >=0)
    cout<<"最少加油次数："<<result<<endl;
    return 0;
}
