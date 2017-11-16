/*************************************************************************
	> File Name: rent.cpp
	> Author: sujunhao
	> Mail: sujunhao0504@gmail.com
	> Created Time: 2017年11月14日 星期二 19时15分51秒
 ************************************************************************/
/* 该算法的思想是,如果单步租用小于连续租用的钱，就用单步租用的钱替换掉连续租用的钱。即本例的1站->2站->3站的租金替换掉1站->3站的租金。依次循环，最后右上角的那个值就是最小的租金。
 */
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
                if(list[i][j]+list[j][mark]<list[i][mark]){//核心代码
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
    for (int i=0;i<n-1;i++){ //二维向量，不满的值用0填满。
        list.push_back(line);
        for(int j=0;j<=i;j++){
            list[i].push_back(0);
        }
        for (int j=i+1;j<n;j++){
            fin>>rent;
            list[i].push_back(rent);
        }
    }
    fin.close();
    fout<<R(n)<<endl;
    return 0;  
    }  
