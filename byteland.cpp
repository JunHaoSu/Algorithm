/*************************************************************************
	> File Name: byteland.cpp
	> Author: sujunhao
	> Mail: sujunhao0504@gmail.com
	> Created Time: 2017年11月16日 星期四 20时56分03秒
 ************************************************************************/

#include<iostream>
#include<fstream>

using namespace std;

int **relation;//标记每人之间的关系
int people_number,enemy_relationship;//人数和敌对关系
bool *people_list;//当前的列表
bool *result;//结果列表

int i,j,k;
int sum,max_people=0;//最大的人数，和当前的人数


bool judge(int x){
    for(int i=0;i<people_number;i++){
        if(people_list[i]&&relation[x][i]){
            return false;
        }
    }
    return true;
}

void byteland(int x){
    for(int i=0;i<people_number;i++){
        if(!people_list[i]){
            if(judge(i)){//判断加入的人中是否有该居民的仇敌
                people_list[i]=1;//加入当前居民
                sum++;
            }
            if(x==people_number){
                if(sum>max_people){
                    max_people=sum;
                }
                for(int i=0;i<people_number;i++){
                    result[i]=people_list[i];
                }
            }else{
                byteland(x+1);
                people_list[i]=0;
                sum--;
            }
        }
    }
}



int main(){
    ifstream fin;
    ofstream fout;
    fin.open("byteland_input.txt");
    fout.open("byteland_output.txt");
    fin>>people_number>>enemy_relationship;
    int x,y;//x和y分别表示两人的位置

    //关系初始化一个二维数组，全部赋为0;
    relation = new int *[people_number];
    for(int i=0;i<people_number;i++){
        relation[i]=new int [people_number];
        for(int j=0;j<people_number;j++){
            relation[i][j]=0;
        }
    }
    for(int i=0;i<enemy_relationship;i++){
        fin>>x>>y;
        relation[x-1][y-1]=relation[y-1][x-1]=1;//输入仇敌关系,初始化二维矩阵的工作完成
        }
    
    result=new bool [people_number];
    people_list = new bool [people_number];//初始化当前加入的人的矩阵
    for(int i=0;i<people_number;i++){
        people_list[i]=0;
        result[i]=0;
    }
    

    byteland(0);//先加入第一个人

    //for(int i=0;i<people_number;i++){
        //for(int j=0;j<people_number;j++){
            //cout<<relation[i][j]<<" ";
        //}
        //cout<<endl;
    //}
    //cout<<endl;

    fout<<max_people<<endl;

    for(int i=0;i<people_number;i++){
        fout<<result[i]<<" ";
    }
    fout<<endl;

    return 0;
}
