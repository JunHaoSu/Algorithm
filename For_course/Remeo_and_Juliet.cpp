/*************************************************************************
	> File Name: Remeo_and_Juliet.cpp
	> Author: JunHao SU
	> Mail: sujunhao0504@163.com
	> Created Time: 2018年03月28日 星期三 15时42分26秒
 ************************************************************************/

#include<iostream>
#include<fstream>

using namespace std;

const int MAX_NUMBER=10000;
int dirs=0;//转弯次数
int mins=MAX_NUMBER;//最少转弯次数
int cnt=0;//不同的最少转弯次数
int n,m,k;
int i,j;//循环变量
int **board;//封闭房间矩阵
int **best;//最好的走法矩阵

struct Point{
    int x,y;
};
Point remeo;
Point julie;

int dx[8]={1,0,-1,0,1,1,-1,-1};
int dy[8]={0,1,0,-1,1,-1,-1,1};//八个方向

bool Isokay(int x,int y){//判断走的是否合法
    if(x>0&&y>0&&x<=m&&y<=n&&board[x][y]==0){
        return true;
    }else{
        return false;
    }
}

void save(){
    for(i=1;i<=m;i++){
        for(j=1;j<=n;j++){
            best[i][j]=board[i][j];
        }
    }
}

void backtrack(int x,int y,int dep,int di){//dep走的步数
    if(dep==n*m-k&&x==julie.x&&y==julie.y&&dirs<=mins){
        if(dirs<mins){
            mins=dirs;
            cnt=1;
            save();
        }else{
            cnt++;
        }
        return;
    }
    if(dep==n*m-k&&x==julie.x&&y==julie.y&&dirs>mins){
        return;
    }
    for(int i=0;i<8;i++){
        int next_x=x+dx[i];
        int next_y=y+dy[i];
        if(Isokay(next_x,next_y)){
            board[next_x][next_y]=dep+1;//记录走的路径
            if(dep>1&&di!=i){
                dirs++;
            }
            backtrack(next_x,next_y,dep+1,i);
            board[next_x][next_y]=0;
            if(dep>1&&di!=i){
                dirs--;
            }
        }
    } 
}



int main(){
    ifstream fin;
    ofstream fout;
    fin.open("Remeo_and_Juliet_input.txt");
    fout.open("Remeo_and_Juliet_output.txt");
    fin>>m>>n>>k;
    board =new int *[m+1];
    best=new int *[m+1];
    for (i=1;i<=m;i++){
        board[i]=new int [n+1];
        best[i]=new int [n+1];
    }
    for(i=1;i<=m;i++){
        for(j=1;j<=n;j++){
            board[i][j]=0;
        }
    }
    int x,y;
    for (i=1;i<=k;i++){
        fin>>x>>y;
        board[x][y]=-1;//-1表示这一格是不通的
    }
    fin>>remeo.x>>remeo.y;
    fin>>julie.x>>julie.y;

    board[remeo.x][remeo.y]=1;
    backtrack(remeo.x,remeo.y,1,0);
    cout<<mins<<endl;
    cout<<cnt<<endl;
    for(i=1;i<=m;i++){
        for(j=1;j<=n;j++){
            cout<<best[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
