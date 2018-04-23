/*************************************************************************
	> File Name: Dijkstra.cpp
	> Author: JunHao SU
	> Mail: sujunhao0504@163.com
	> Created Time: 2018年03月24日 星期六 15时29分42秒
 ************************************************************************/

#include<iostream>
#include<fstream>
#include<stdlib.h>
using namespace std;

const int MAX_DISTANCE=999999;

int i,j;//循环变量
int **point;
int *dist;
int *prev;

void Dijkstra(int n, int v, int *dist,int *prev,int **a){
    if(v<1||v>n) return;
    bool s[n+1];//判断该点是否在Ｓ中
    for(i=1;i<=n;i++){
        dist[i]=a[v][i];
        s[i]=false;//初始化为false
        if(dist[i]==MAX_DISTANCE){//如果v到i不可达
            prev[i]=0;//i的前驱是0
        }else{
            prev[i]=v;//如果i和v可达，将v作为i的前驱
        }
    }
    dist[v]=0;
    s[v]=true;//初始化v加入S集
    for(i=1;i<n;i++){//最多循环n-1次
        int temp=MAX_DISTANCE;//找到最小的距离temp，将他赋成u
        int u=v;
        for(j=1;j<=n;j++){
            if((!s[j])&&dist[j]<temp){
                u=j;
                temp=dist[j];
            }
        }
        s[u]=true;//将u加入Ｓ集
        for(j=1;j<=n;j++){
            if((!s[j])&&(a[u][j]<MAX_DISTANCE)){//如果j点没有在Ｓ集，且ｕ,j点之间有距离
                int newdist=dist[u]+a[u][j];//将新距离算出来
                if(newdist<dist[j]){//如果新距离比原来的小      
                    dist[j]=newdist;//新距离替换
                    prev[j]=u;//j的前驱是u
                }
            }             
        }
    }

}


int main(){
    ifstream fin;
    ofstream fout;
    fin.open("Dijkstra_input.txt");
    fout.open("Dijkstra_output.txt");
    int n,l;//n点数,l边数
    int len;//边长度
    int x,y,v;//x,y点，源点v
    fin>>n>>l>>v;
    dist=new int[n+1];//存储当前点对对每个顶点的最短长度
    prev=new int[n+1];//存储源点到顶点i的前一个顶点
    point=new int *[n+1];

    for(i=1;i<=n;i++){//点间关系初始化
        point[i]=new int[n+1];
        dist[i]=MAX_DISTANCE;
        prev[i]=v;
        for(j=1;j<=n;j++){
            point[i][j]=MAX_DISTANCE;
        }
    }
    for (i=1;i<=l;i++){
        fin>>x>>y>>len;
        point[x][y]=len;//输入点间关系
    }

    Dijkstra(n,v,dist,prev,point);

    fout<<"dist数组为：";
    for(i=1;i<=n;i++){
        fout<<dist[i]<<" ";
    }
    fout<<endl;
    fout<<"prev数组为：";
    for(i=1;i<=n;i++){
        fout<<prev[i]<<" ";
    }
    fout<<endl;
    return 0;
}
