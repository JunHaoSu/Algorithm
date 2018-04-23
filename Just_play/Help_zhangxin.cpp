/*************************************************************************
	> File Name: Help_zhangxin.cpp
	> Author: JunHao SU
	> Mail: sujunhao0504@163.com
	> Created Time: 2018年03月31日 星期六 10时52分14秒
 ************************************************************************/

#include<iostream>
#include<fstream>
#include<math.h>
#include<iomanip>
using namespace std;
int n;//x,y的个数
double pi=3.1415926;
int i,j,k;//循环变量
double **A;//第一个矩阵
double **ReSult;//结果矩阵

double average(int x_or_y){
    double sum=0.0;
    double ave=0.0;

    for(i=0;i<n;i++){
        sum+=A[i][x_or_y];
    }
    ave=sum/n;
    return ave;
}

void matrix(double **A,double **Re,double B[3][3]){
    for(i=0;i<n;i++){
        for(j=0;j<3;j++){
            Re[i][j]=0;
            for(k=0;k<3;k++){
                Re[i][j]+=A[i][k]*B[k][j];
            }
        }
    }
}

int main(){
    double k,ave_x,ave_y,sita_jiaodu,sita;
    ifstream fin;
    ofstream fout;
    fin.open("Help_zhangxin_input.txt");
    fout.open("Help_zhangxin_output.txt");
    fin>>n;
    A=new double *[n];
    for(i=0;i<n;i++){
        A[i]=new double [3];
        fin>>A[i][0]>>A[i][1];
        A[i][2]=1;
    }//初始化A矩阵
    ave_x=average(0);
    ave_y=average(1);//x和y的平均数算出来了。
    double B[3][3]={{1.0,0.0,0.0},{0.0,1.0,0.0},{-ave_x,-ave_y,1.0}};
    fin>>sita_jiaodu;
    sita=sita_jiaodu*pi/180;
    double C[3][3]={{cos(sita),sin(sita),0.0},{-sin(sita),cos(sita),0.0},{0.0,0.0,1.0}};
    fin>>k;
    double D[3][3]={{k,0.0,0.0},{0.0,k,0.0},{0.0,0.0,1.0}};
    double E[3][3]={{1.0,0.0,0.0},{0.0,1.0,0.0},{ave_x,ave_y,1.0}};
    
    ReSult=new double *[n];
    for(i=0;i<n;i++){
        ReSult[i]=new double [3];
        for(j=0;j<3;j++){
            ReSult[i][j]=0;//初始化结果矩阵
        }
    }
    
    matrix(A,ReSult,B);
    matrix(ReSult,A,C);
    matrix(A,ReSult,D);
    matrix(ReSult,A,E);
    for(i=0;i<n;i++){
        for(j=0;j<3;j++){
            fout<<A[i][j]<<"   ";
        }
        fout<<endl;
    }
    return 0;
}


