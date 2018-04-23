/*************************************************************************
	> File Name: MaxSum.cpp
	> Author: sujunhao
	> Mail: sujunhao0504@gmail.com
	> Created Time: 2017年11月15日 星期三 18时30分42秒
 ************************************************************************/
/*最大子段和问题可以使用动态规划完成，从第一个元素开始循环，一直向后加，第一次循环
 * 会将整个数组加完，之后从第二个元素开始加，加到比第一次的大就停止，将此时的和赋给
 *最大子段和，一直向后推，从每个元素开始加到的数一旦大于前一次的最大字段和，就替换
 * 将这个数组循环一遍以后，最后那个最大的数一定就是最大子段和。
*/
#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;

int MaxSum(int n,int a[3]){//最大子段和
    int sum=0;
    for(int i=0;i<n;i++){
        int thissum=0;
        for(int j=i;j<n;j++){
            thissum+=a[j];
            if(thissum>sum){
                sum=thissum;
            }
        }
    }
    return sum;
}

int MaxSum2(int m,int n,int b[3][3]){//最大矩阵和
    int sum=0;
    int c[3];
    memset(c,0,sizeof(c));
    int i,k,j;
    for(i=0;i<m;i++){
       memset(c,0,sizeof(c));
        for(k=i;k<m;k++){
            for(j=0;j<n;j++)
                c[j]+=b[k][j];
            int max=MaxSum(n,c);
            if(max>sum)sum=max;
        }
    }
    return sum;
}

int MaxSum3(int m,int n,int x,int a[3][3][3]){//最大长方体
    int sum=0;
    int b[3][3];
    int i,j,k,l;
    memset(b,0,sizeof(b));
    for(i=0;i<m;i++){
        memset(b,0,sizeof(b));
        for(j=i;j<m;j++){
            for(k=0;k<n;k++)
                for(l=0;l<x;l++)
                    b[k][l]+=a[j][k][l];
                int max=MaxSum2(n,x,b);
                if(max>sum)
                    sum=max;
        }
    }
    return sum;
}

int main(){
    ifstream fin;
    ofstream fout;
    int m,n,p;
    fin.open("MaxSum_input.txt");
    fout.open("MaxSum_output.txt");
    fin>>m>>n>>p;
    int i,j,k;
    int a[3][3][3];
    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
            for(k=0;k<p;k++){
                fin>>a[i][j][k];
                }
    int result=MaxSum3(m,n,p,a);
    fout<<result;
    fin.close();
    fout.close();
    return 0;
}

