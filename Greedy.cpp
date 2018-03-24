/*************************************************************************
	> File Name: Greedy.cpp
	> Author: JunHao SU
	> Mail: sujunhao0504@163.com
	> Created Time: 2018年03月24日 星期六 21时23分52秒
 ************************************************************************/

#include<iostream>
#include<vector>
#include<fstream>
#include<algorithm>

using namespace std;

int i,j;

double greedy(vector<int> p){
    int n=p.size();
    vector<int> x(n,0);
    sort(p.begin(),p.end());
    int k=(n-1)/2;
    x[k]=p[n-1];
    for(i=k+1;i<n;i++){
        x[i]=p[n-2*(i-k)];//n-2,n-4,n-6分别向一侧散发
    }
    for(i=k-1;i>=0;i--){
        x[i]=p[n-2*(k-i)-1];//n-3,n-5,n-7分别向另一侧散发
    }
    double m=0,t=0;
    for(i=0;i<n;i++){
        m+=p[i];
        for(j=i+1;j<n;j++){
            t+=x[i]*x[j]*(j-i);
        }
    }
    return t/m/m;
}

int main(){
    ifstream fin;
    ofstream fout;
    fin.open("Greedy_input.txt");
    fout.open("Greedy_output.txt");
    int n,a;
    double t;
    vector<int>p;
    fin>>n;
    for(i=1;i<=n;i++){
        fin>>a;
        p.push_back(a);
    }
    t=greedy(p);
    fout<<t;
    return 0;
}
