#include<iostream>
#include<cstring>
using namespace std;
int main (){
    char x[100] , y[100];
    cout<<"Enter first string :";
    cin>>x;
    cout<<"Enter second string :";
    cin>>y;
    int m=strlen(x);
    int n=strlen(y);
    
   int dp[101][101];
    
    for(int i=0 ; i<=m;i++){
        for(int j=0;j<=n;j++){
            if( i ==0 || j==0){
                dp[i][j]=0;
            }
        }
    }
    
    for(int i= 1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(x[i-1]==y[j-1]){
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else{
                dp[i][j]=max(dp[i-1][j] , dp[i][j-1]);
            }
        }
    }
    cout<<"The minimum length :"<<dp[m][n];
}