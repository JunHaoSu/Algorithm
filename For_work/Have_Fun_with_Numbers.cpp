/*************************************************************************
	> File Name: Have_Fun_with_Numbers.cpp
	> Author: JunHao SU
	> Mail: sujunhao0504@163.com
	> Created Time: 2018年04月21日 星期六 23时00分58秒
 ************************************************************************/

#include<iostream>
#include<string.h>

using namespace std;

int main(){
    string src;
    int dst[25];
    int cnt1[25]={0},cnt2[25]={0};
    cin>>src;
    int i,j,w,k=0;
    int t=0,flag=1;
    int tmp;
    for(int i=src.size()-1;i>=0;i--){
        tmp=src[i]-'0';
        cnt1[tmp]++;
        j=2*tmp+k;
        w=j%10;
        k=j/10;
        dst[i]=w;
        cnt2[w]++;
    }
    if(k!=0){
        t=src.size();
        dst[t]=k;
        cnt2[k]++;
        flag=0;
    }
    if(flag){
        for(i=0;i<10;i++){
            if(cnt1[i]!=cnt2[i]){
                flag=0;
                break;
            }
        }
    }
    if(flag==0) cout<<"No\n";
    else cout<<"Yes\n";
    if(t==src.size()) cout<<dst[t];
    for(t=0;t<src.size();t++){
        cout<<dst[t];
    }
    return 0;
}
