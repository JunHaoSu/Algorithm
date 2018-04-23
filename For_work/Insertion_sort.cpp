/*************************************************************************
	> File Name: Insertion_sort.cpp
	> Author: sujunhao
	> Mail: sujunhao0504@gmail.com
	> Created Time: 2017年11月09日 星期四 21时23分16秒
 ************************************************************************/

#include<iostream>
#include<vector>

using namespace std;

void Insertion_sort(vector<int> x){
    for(int i=1;i<x.size();i++){
        int key=x[i];
        int j=i-1;
        while(j>=0&&key<x[j]){
            x[j+1]=x[j];
            j--;
        }
        x[j+1]=key;
    }
    cout<<"插入排序结果:";
    for(int i=0;i<x.size();i++){
        cout<<x[i]<<" ";
    }
    cout<<endl;
}

int main(){
    vector<int> a;
    int number;
    cout<<"Input an Array:"<<endl;
    while(cin>>number){
        a.push_back(number);
    }
    cin.clear();
    cin.ignore();
    Insertion_sort(a);
    return 0;
}
