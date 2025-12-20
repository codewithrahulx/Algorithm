#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int mineditdistance(string x ,string y){
    int m=x.length();
    int n=y.length();
    
    int dp[100][100];
    for(int i=0;i<=m;i++){
        dp[i][0]=i;
    }
     for(int j=0;j<=n;j++){
        dp[0][j]=j;
            
    }
    for(int i=1;i<=m;i++){
        for(int j =1;j<=n;j++){
            if(x[i-1]==y[j-1]){
                dp[i][j]=dp[i-1][j-1];
            }else{
                dp[i][j]=1+min({
                    dp[i-1][j],
                    dp[i][j-1],
                    dp[i-1][j-1]
                });
            }
        }
    }
    return dp[m][n];
}
int main(){
    string str1 ,str2;
    cout<<"Enter first string :";
    cin>>str1;
    cout<<"Enter second string :";
    cin>>str2;
    
    int result=mineditdistance(str1, str2);
    cout<<"Minimum edit distance :"<<result;
}