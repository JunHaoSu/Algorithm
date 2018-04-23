/*************************************************************************
	> File Name: Number_Triangle.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年03月21日 星期三 21时11分41秒
 ************************************************************************/

#include<iostream>
#include<fstream>
using namespace std;

const int MAX_MUNBER=100;

int triangle(int a[MAX_MUNBER][MAX_MUNBER],int n){
    int max[MAX_MUNBER][MAX_MUNBER];
    for(int i=1;i<=n;i++){
        max[n][i]=a[n][i];
    }
    for (int i=n-1;i>=1;i--){
        for(int j=1;j<=i;j++){
            int the_first=max[i+1][j];
            int the_second=max[i+1][j+1];
            if(the_first>=the_second) max[i][j]=a[i][j]+the_first;
            else max[i][j]=a[i][j]+the_second;
        }
    }
    return max[1][1];
}

int main(){
    ifstream fin;
    ofstream fout;
    fin.open("Number_Triangle_input.txt");
    fout.open("Number_Triangle_output.txt");
    int n,result;
    int a[MAX_MUNBER][MAX_MUNBER];
    fin>>n;
    for(int i=1;i<=n;i++){
        for (int j=1;j<=i;j++){
            fin>>a[i][j];
        }
    }
    result=triangle(a,n);
    fout<<result<<endl;
    return 0;
}


