/*************************************************************************
	> File Name: Quick_sort.cpp
	> Author: sujunhao
	> Mail: sujunhao0504@gmail.com
	> Created Time: 2017年11月11日 星期六 21时26分55秒
 ************************************************************************/

#include<iostream>
#include<vector>

using namespace std;

void quick_sort(vector<int> &x,int _left,int _right){
    if(_left<_right){
        int left=_left;
        int right=_right;
        int key=x[_left];
        while(left<right){
            while(right>left&&key<=x[right]){
                right--;
            }
            x[left]=x[right];
            while(right>left&&key>=x[left]){
                left++;
            }
            x[right]=x[left];
        }
        x[left]=key;
        quick_sort(x,_left,left-1);
        quick_sort(x,right+1,_right);
    }
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
    quick_sort(a,0,a.size()-1);
    cout<<"快速排序结果：";
    for(int i=0;i<a.size();i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return 0;
}
