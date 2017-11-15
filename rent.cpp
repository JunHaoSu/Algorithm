/*************************************************************************
	> File Name: rent.cpp
	> Author: sujunhao
	> Mail: sujunhao0504@gmail.com
	> Created Time: 2017年11月14日 星期二 19时15分51秒
 ************************************************************************/
#include<iostream>  
#include<fstream>
#include<vector>

using namespace std;  
const int MAX = 200;
vector<vector<int> >list;//用于存放租金
vector<int>line;

int R(int n){
    int i, j, k;//定义三个索引
    for (k=2;k<n;k++){
        for (i=0;i<n-k;i++){
            int mark=i+k;
            for(j=i+1;j<mark;j++){
                if(list[i][j]+list[j][mark]<list[i][mark]){
                list[i][mark]=list[i][j]+list[j][mark];
            }  
        }  
    }
    return list[0][n-1];
    }  
}
int main(){  
    ifstream fin;
    ofstream fout;
    fin.open("rent_input.txt");  
    fout.open("rent_output.txt");  
    int n;//站点数 
    int rent;//租金
    fin>>n;
    for (int i=0;i<n-1;i++){ //i 行，j 列 
        list.push_back(line);
        for(int j=0;j<=i;j++){
            list[i].push_back(0);
        }
        for (int j=i+1;j<n;j++){
            fin>>rent;
            list[i].push_back(rent);
        }
    }
    fout<<R(n)<<endl;
    return 0;  
    }  
