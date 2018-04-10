/*************************************************************************
	> File Name: OS_Bankers_Algorithm.cpp
	> Author: JunHao SU
	> Mail: sujunhao0504@163.com
	> Created Time: 2018年04月09日 星期一 16时29分30秒
 ************************************************************************/

#include<iostream>
#include<fstream>

using namespace std;

const int MAX_porcess=10;
const int MAx_source=10;

int **max_re;//每个进程需要的最大资源数
int **allocation;//每个进程已经得到的资源的数量
int **need;//每个进程依然需要的资源量
int *available;//每个资源最大数
int source_number,process_number;

int com(int m[],int n[]);

void test(){
    for(int i=0;i<process_number;i++){
        for(int j=0;j<source_number;j++){
            cout<<max_re[i][j]<<" ";
        }
        cout<<"  ";
        for(int j=0;j<source_number;j++){
            cout<<allocation[i][j]<<" ";
        }
        cout<<" ";
        for(int j=0;j<source_number;j++){
            cout<<need[i][j]<<" ";
        }
        cout<<endl;
    }
    for(int i=0;i<source_number;i++){
        cout<<available[i]<<" ";
    }
    cout<<endl<<endl;;
}



void init(){
    ifstream fin;
    fin.open("OS_Bankers_Algorithm_input.txt");
    int p,r;
    fin>>p>>r;

    source_number=r;
    process_number=p;

    allocation = new int *[p];
    for(int i=0;i<p;i++){
        allocation[i]=new int [r];
        for(int j=0;j<r;j++){
            fin>>allocation[i][j];
        }
    }
    
    max_re = new int *[p];
    for(int i=0;i<p;i++){
        max_re[i]=new int [r];
        for(int j=0;j<r;j++){
            fin>>max_re[i][j];
        }
    }
    
    available = new int [r];
    for(int i=0;i<r;i++){
        fin>>available[i];
    }

    need = new int *[p];
    for(int i=0;i<p;i++){
        need[i] = new int [r];
        for(int j=0;j<r;j++){
            need[i][j]=max_re[i][j]-allocation[i][j];
        }
    }
}

int test_first(){
    int i,j,k,l,flag=0,flag1=0;
    bool finish[process_number];
    int available_save[source_number];

    for(int i=0;i<source_number;i++){
        available_save[i]=available[i];
    }
    
    for(i=0;i<process_number;i++){
        finish[i]=false;//finish为false代表这个进程未被分配资源
    }
    for(k=0;k<process_number;k++){
        for(i=0;i<process_number;i++){
            if(finish[i]==true){
                continue;//如果进程为true代表使用过资源
            }else{
                if(com(available,need[i])){//比较need和available，如果够，就分配给他
                    finish[i]=true;
                    cout<<i+1<<"     ";
                    for(l=0;l<source_number;l++){
                        available[l]=available[l]+allocation[i][l];//使用后总资源增加
                        cout<<available[l]<<" ";
                    }                
                    cout<<endl;
                    break;//分配过一个后即跳出当前循环，已经找到了，所以不用再找
                }
            }
        }
    }

    
    for(int i=0;i<source_number;i++){
        available[i]=available_save[i];
    }

    cout<<endl;
    for(l=0;l<process_number;l++){
        if(finish[l]==false){
            flag1=1;//flag1为1代表循环结束后有进程未被分配，是不安全状态
        }
    }
    if(flag1==0) return 1;
    else return 0;
}

void test_After_request(int request[],int n){
    int i,j;
    n=n-1;
    if(com(available,request)&&com(need[n],request)){
        for(j=0;j<source_number;j++){
            allocation[n][j]=allocation[n][j]+request[j];
            need[n][j]=need[n][j]-request[j];
            available[j]=available[j]-request[j];
        }
        test();
        if(test_first()){
            cout<<"允许"<<n+1<<"号进程申请资源！"<<endl;
        }else{
            cout<<"不允许"<<n+1<<"号进程申请资源！"<<endl;
            for(j=0;j<source_number;j++){
                allocation[n][j]=allocation[n][j]-request[j];
                need[n][j]=need[n][j]+request[j];
                available[j]=available[j]+request[j];
            }
        }
    }else{
        cout<<"申请资源出错！"<<endl;
    }
    
}

//比较函数，first数组大于second代表need小于available,
//资源可以提供给该进程
int com(int first[],int second[]){
    int i,flag=0;
    for(i=0;i<source_number;i++){
        if(first[i]<second[i]){
            flag=1;
            break;
        }
    }
    if(flag==1) 
        return 0;
    else 
        return 1;
}

int main(){
    int n;
    init();
    test();
    int request[source_number];
    if(test_first()){
        cout<<"初始状态安全!"<<endl;
    }else{
        cout<<"初始状态不安全！"<<endl;
    }
    cout<<"输入请求的进程号！";
    cin>>n;
    cout<<"输入请求的进程号资源!:";
    for(int i=0;i<source_number;i++){
        cin>>request[i];
    }
    test_After_request(request,n);

    return 0;
}
