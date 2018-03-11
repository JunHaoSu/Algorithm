/*************************************************************************
	> File Name: Binary_Tree_ordering.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年03月11日 星期日 15时04分23秒
 ************************************************************************/

#include<iostream>
#include<string.h>
using namespace std;

void preorder(string,string);
void postorder(string,string);

string pre;
string post;

void preorder(string a,string b){
    if(b.length()==1){
        pre += b;
    }else{
        int k=a.find(b.substr(b.length()-1,1));
        pre+=a[k];
        if(k>0)
            preorder(a.substr(0,k),b.substr(0,k));
        if(k<a.length()-1)
            preorder(a.substr(k+1,a.length()-k-1),b.substr(k,b.length()-k-1));
    }
}

void postorder(string a,string b){
    if(b.length()==1){
        post+=b;
    }else{
        int k=a.find(b.substr(0,1));
        if(k>0)
            postorder(a.substr(0,k),b.substr(1,k));
        if(k<a.length()-1)
            postorder(a.substr(k+1,a.length()-k-1),b.substr(k+1,b.length()-k-1));
        post+=a[k];
    }
}


int main(){
    string a="GDAFEMHZ";
    string b="ADEFGHMZ";
    string c="AEFDHZMG";
    cout<<"前序: "<<a<<endl;
    cout<<"中序: "<<b<<endl;
    cout<<"后序: "<<c<<endl;
    preorder(b,c);
    postorder(b,a);
    cout<<"前序结果:"<<pre<<endl;
    cout<<"后序结果:"<<post<<endl;
    return 0;
}
