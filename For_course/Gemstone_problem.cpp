/*************************************************************************
	> File Name: Gemstone_problem.cpp
	> Author: JunHao SU
	> Mail: sujunhao0504@163.com
	> Created Time: 2018年03月25日 星期日 15时22分35秒
 ************************************************************************/

#include<iostream>
#include<fstream>
#include<algorithm>
using namespace std;

const int MAX_N=9;
int i,j,k;
int n;
int **color;//宝石颜色
int **shape;//宝石形状
bool **use;//i颜色j形状的宝石是否被使用过
long int num=0;//方案数


bool isOK(int r,int c,int k,bool isShap){//k颜色值，r行，c列，isShap是否被用过
    if(isShap){
        for(i=1;i<r;i++){
            if(shape[i][c]==k) return false;//形状重复
        }
    }else{
        if(use[shape[r][c]][k]) return false;//这个颜色和形状的宝石已经被使用过
        for(i=1;i<r;i++){
            if(color[i][c]==k) return false;//颜色重复
        }
    }
    return true;
}


void backtrack(int r,int c){
    for(int i=c;i<=n;i++){
        if(isOK(r,c,shape[r][i],true)){//当前位置的宝石形状是否被使用过                  
            swap(shape[r][c],shape[r][i]);
            for(int j=c;j<=n;j++){
                if(isOK(r,c,color[r][j],false)){
                    swap(color[r][c],color[r][j]);
                    use[shape[r][c]][color[r][c]]=true;
                    if(c==n){
                        if(r==n){
                            num++;
                        }else{
                            backtrack(r+1,1);
                        }
                    }else{
                        backtrack(r,c+1);
                    }
                }
                swap(color[r][c],color[r][j]);
                use[shape[r][c]][color[r][c]]=false;
            }
        }
        swap(shape[r][c],shape[r][i]);
    }
}

void init(){
    color= new int *[n+1];
    shape= new int *[n+1];
    use=new bool *[n+1];
    for(i=1;i<=n;i++){
        color[i]=new int[n];
        shape[i]=new int[n];
        use[i]=new bool[n];
        for(j=1;j<=n;j++){
            color[i][j]=j;
            shape[i][j]=j;
            use[i][j]=false;
        }
    }
}

int main(){
    ifstream fin;
    ofstream fout;
    fin.open("Gemstone_problem_input.txt");
    fout.open("Gemstone_problem_output.txt");
    fin>>n;
    init();
    backtrack(1,1);
    fout<<"num="<<num<<endl;
    return 0;
}
