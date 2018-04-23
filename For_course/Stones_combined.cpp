/*************************************************************************
	> File Name: Stones_combined.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年03月21日 星期三 19时34分02秒
 ************************************************************************/

#include<iostream>
#include<fstream>
using namespace std;

const int MAX_NUMBER=100;

int Min_Stones(int p[MAX_NUMBER],int n){
    int m[MAX_NUMBER][MAX_NUMBER];
    //初始化合并分数
    //ｍ矩阵的意思是i和j合并的分数
    int min;
    for (int i=1;i<n;i++){
        for (int j=0;j<n;j++){
            m[i][j]==-1;//初始化为-1
        }
        m[i][i]=0;//它自己合并的值为０
    }
    for (int i=1;i<n;i++){
        m[i][i+1]=p[i]+p[i+1];//相邻合并值相加
    }
    for (int r=3;r<=n;r++){//每次循环间距加１，
        for(int i=1;i<=n-r+1;i++){
            int j=i+r-1;//i,j距离为r-1
            int sum=0;//元素sum初始化
            for (int x=i;x<=j;x++){
                sum+=p[x];//需要合并的元素求和
            }
            m[i][j]=m[i+1][j]+sum;//从i到j的得分等于后面的得分加上sum，相当于后面的合并，再并前一个;
            for(int k=i+1;k<j;k++){
                int cache=m[i][k]+m[k+1][j]+sum;//另一种情况就是分别求前一种情况的和，分别相加
                if(cache<m[i][j]) m[i][j]=cache;
            }
            
        }
    }
    min=m[1][n];//返回从１合并到最后的值，这只是一条直线的合并。
    return min;
}

int Max_Stones(int p[MAX_NUMBER],int n){
    int m[MAX_NUMBER][MAX_NUMBER];
    //初始化合并分数
    //ｍ矩阵的意思是i和j合并的分数
    int max;
    for (int i=1;i<n;i++){
        for (int j=0;j<n;j++){
            m[i][j]==-1;//初始化为-1
        }
        m[i][i]=0;//它自己合并的值为０
    }
    for (int i=1;i<n;i++){
        m[i][i+1]=p[i]+p[i+1];//相邻合并值相加
    }
    for (int r=3;r<=n;r++){//每次循环间距加１，
        for(int i=1;i<=n-r+1;i++){
            int j=i+r-1;//i,j距离为r-1
            int sum=0;//元素sum初始化
            for (int x=i;x<=j;x++){
                sum+=p[x];//需要合并的元素求和
            }
            m[i][j]=m[i+1][j]+sum;//从i到j的得分等于后面的得分加上sum，相当于后面的合并，再并前一个;
            for(int k=i+1;k<j;k++){
                int cache=m[i][k]+m[k+1][j]+sum;//另一种情况就是分别求前一种情况的和，分别相加
                if(cache>m[i][j]) m[i][j]=cache;
            }
            
        }
    }
    max=m[1][n];//返回从１合并到最后的值，这只是一条直线的合并。
    return max;
}

int main(){
    int n;
    int stone[MAX_NUMBER];
    ifstream fin;
    ofstream fout;
    fin.open("Stones_combined_input.txt");
    fout.open("Stones_combined_ouput.txt");
    fin>>n;
    for(int i=1;i<=n;i++){
        fin>>stone[i];
    }
    int min=Min_Stones(stone,n);
    int max=Max_Stones(stone,n);

    for(int j=1;j<=n-1;j++){
        int min_cache=0;
        int max_cache=0;
        int cache=stone[1];
        for(int k=2;k<=n;k++){
            stone[k-1]=stone[k];
        }
        stone[n]=cache;
        min_cache=Min_Stones(stone,n);
        max_cache=Max_Stones(stone,n);
        if(min_cache<min) min=min_cache;
        if(max_cache>max) max=max_cache;
    }
    fout<<min<<endl;
    fout<<max<<endl;
    return 0;
}
