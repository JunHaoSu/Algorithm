/*************************************************************************
	> File Name: car_fuel_drive.cpp
	> Author: sujunhao
	> Mail: sujunhao0504@gmail.com
	> Created Time: 2017年11月13日 星期一 14时12分30秒
 ************************************************************************/

#include<iostream>
#include<fstream>

#define  INF 10086
using namespace std;

int N;//网格大小
int A;//加油费用
int C;//增设油库费用
int B;//每条节点应付费用
int K;//加满能走多少条边

struct port{
    int k_re;//当前节点车油箱剩余量
    int result;//当前节点的路费总额
};

int a[100][100];//油库节点，地图
port f[100][100];//路线节点，
int s[4][3]={{-1,0,0},{0,-1,0},{1,0,B},{0,1,B}};//上下左右四个选择的路费

int car(){
    int i,j,k;
    for(i=1;i<=N;i++){
        for(j=1;j<=N;j++){
            f[i][j].result=INF;
            f[i][j].k_re=K;
        }
    }

    f[1][1].result=0;//左上角的点
    f[1][1].k_re=K;

    int cnt=1;
    int chang_x,chang_y;

    while(cnt){
        cnt=0;
        for(i=1;i<=N;i++){
            for(j=1;j<=N;j++){
                if(i==1&&j==1){
                    continue;//出发点不做
                }
                int minmoney=INF;//初始化最小路费
                int minfuel;//最小的油耗
                int money,fuel;//当前费用和油量

                for(k=0;k<4;k++){//四种选择
                    chang_x=i+s[k][0];//移动X
                    chang_y=j+s[k][1];//移动Y
                    if(chang_x<1||chang_x>N||chang_y<1||chang_y>N){//如果出界就跳出
                        continue;
                    }
                    money=f[chang_x][chang_y].result+s[k][2];//当前节点的路费
                    fuel=f[chang_x][chang_y].k_re-1;//剩余油量减1;
                    if(a[i][j]==1){//如果是油库
                        money+=A;//加油钱
                        fuel=K;//油满
                    }
                    if(a[i][j]==0 && fuel==0 && (i!=N||j!=N)){//如果不是油库，且没油了而且没有到终点
                        money+=A+C;//油钱加上增设油库的钱
                        fuel=K;//油满
                    }
                    if(money<minmoney){//如果钱没有超标,即可以走
                        minmoney=money;
                        minfuel=fuel;
                    }
                }
                if(f[i][j].result>minmoney){//如果有更好的选择
                    cnt++;//步数加一
                    f[i][j].result=minmoney;//该点的最小钱
                    f[i][j].k_re=minfuel;//该点剩余的油
                }

            }
        }
    }
    return f[N][N].result;
}

int main(){
    ifstream fin("car_fuel_drive_input.txt");
    ofstream fout("car_fuel_drive_output.txt");
    cout<<"输入方格规模：";
    fin>>N;cout<<N<<endl;
    cout<<"输入加满后行驶的网格边数：";
    fin>>K;cout<<K<<endl;
    cout<<"输入加满油的费用：";
    fin>>A;cout<<A<<endl;
    cout<<"输入坐标减少的路费：";
    fin>>B;cout<<B<<endl;
    s[2][2]=B;//给B赋值
    s[3][2]=B;
    cout<<"输入增设油库的费用：";
    fin>>C;cout<<C<<endl;
    cout<<"输入的网格为："<<endl;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            fin>>a[i][j];
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    fin.close();
    int out=car();
    cout<<"最小费用为："<<out<<endl;
    fout<<out<<endl;
    fout.close();
    return 0;
}
