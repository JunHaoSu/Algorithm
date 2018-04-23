/*************************************************************************
	> File Name: DFS.cpp
	> Author: JunHao SU
	> Mail: sujunhao0504@163.com
	> Created Time: 2018年04月08日 星期日 19时20分25秒
    数据字典说明：
    vertex[] 节点集合
    visited[] 节点是否被访问过的记录 0 表示未被访问过
    arc[][] 记录两节点之间是否有边 1 表示有边
    vertexNum 节点的数量
    arcNum 边的数量

 ************************************************************************/

#include<iostream>
#include<fstream>
#include<queue>
using namespace std;

const int MaxSize=10;

int i,j,k;//循环变量
queue<char> DFS_result;
queue<char> BFS_result;
queue<int>  BFS_queue;
template <class T>
class MGraph{
    public:
        MGraph(T list_of_node[],int node,int edge,int re[MaxSize][MaxSize]);
        ~MGraph() {}
        void DFST(int begin_node);
        void BFST(int begin_node);
        void cleara();
    private:
        T vertex[MaxSize];
        bool visited[MaxSize];
        int arc[MaxSize][MaxSize];
        int vertexNum,arcNum;
};
template <class T>
void MGraph<T>::cleara(){
    for(i=0;i<MaxSize;i++){
        visited[i]=false;
    }
}

template <class T>
MGraph<T>::MGraph(T a[],int n,int e,int re[MaxSize][MaxSize]){
    vertexNum=n;
    arcNum=e;
    for(i=0;i<vertexNum;i++){
        vertex[i]=a[i];//传入节点数组
    }
    for(i=0;i<vertexNum;i++){
        for(j=0;j<vertexNum;j++){
            arc[i][j]=re[i][j];//传入边信息
        }
    }
}

template <class T>
void MGraph<T>::DFST(int v){
    DFS_result.push(vertex[v]);
    visited[v]=true;//初始节点记为访问过
    for(int i=0;i<vertexNum;i++){
        if(arc[v][i]==1&&visited[i]==false){
            DFST(i);
        }
    }
    
}

template <class T>
void MGraph<T>::BFST(int v){
    BFS_queue.push(v);
    BFS_result.push(vertex[v]);
    while(!BFS_queue.empty()){
        v=BFS_queue.front();
        BFS_queue.pop();
        for(j=0;j<vertexNum;j++){
            if(arc[v][j]==1&&visited[j]==false){
                BFS_result.push(vertex[j]);
                visited[j]=1;
                BFS_queue.push(j);
            }
        }
    }
}

int main(){
    ifstream fin;
    ofstream fout;
    fin.open("DFS_input.txt");
    fout.open("DFS_output.txt");
    int n,e;
    int re[MaxSize][MaxSize]={0};
    char d[MaxSize];
    fin>>n>>e;
    for(i=0;i<n;i++){
        fin>>d[i];
    }
    for(k=0;k<e;k++){
        fin>>i>>j;
        re[i-1][j-1]=1;
    }
    MGraph<char> a(d,n,e,re);
    a.cleara();
    a.DFST(0);
    a.cleara();
    a.BFST(0);
    for(i=0;i<n;i++){
        char x=DFS_result.front();
        fout<<x<<" ";
        DFS_result.pop();
    }
    fout<<endl;
    for(i=0;i<n;i++){
        char x=BFS_result.front();
        fout<<x<<" ";
        BFS_result.pop();
    }
    fout<<endl;
}
