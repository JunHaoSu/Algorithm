/*************************************************************************
	> File Name: byteland.cpp
	> Author: sujunhao
	> Mail: sujunhao0504@gmail.com
	> Created Time: 2017年11月16日 星期四 20时56分03秒
 ************************************************************************/

#include<iostream>
#include<fstream>
#include<cstring>

using namespace std;

void byteland(){

}

int main(){
    ifstream fin;
    ofstream fout;
    fin.open("byteland_input.txt");
    fout.open("byteland_output.txt");
    int people_number,enemy_relationship;
    fin>>people_number>>enemy_relationship;
    int a[enemy_relationship][2];
    for(int i=0;i<enemy_relationship;i++){
        for(int j=0;j<2;j++){
            fin>>a[i][j];
        }
    }
    byteland();


}
