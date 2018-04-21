#include<iostream>

using namespace std;

int main(){
    int n;
    char x;
    cin>>n>>x;
    int i=0,sum=0;
    while(sum<=n){
        i++;
        sum=2*i*i-1;
    }
    int high=i-1;
    int residue=n-(2*high*high-1);
    
    for(int i=high;i>0;i--){
        if(i<high){
            for(int k=0;k<high-i;k++){
                cout<<" ";
            }
        }
        for(int j=1;j<=2*i-1;j++){
            cout<<x;
        }
        cout<<endl;
    }
    for(int i=2;i<=high;i++){
        if(i<high){
            for(int k=0;k<high-i;k++){
                cout<<" ";
            }
        }
        for(int j=1;j<=2*i-1;j++){
            cout<<x;
        }
        cout<<endl;
    }
    cout<<residue;
    return 0;
}
