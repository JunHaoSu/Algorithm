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
using namespace std;


int a[6]={-2,11,-4,13,-5,-2};

int MaxSum(int n,int *a){
    int sum=0;
    for(int i=1;i<=n;i++){
        int thissum=0;
        for(int j=i;j<=n;j++){
            thissum+=a[j];
            if(thissum>sum){
                sum=thissum;
            }
        }
    }
    return sum;
}

int main(){
    int re=MaxSum(6,a);
    cout<<re;
}
