#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string printlcs(string x , string y , int &length){
    int m=x.length();
    int n=y.length();
    
    int dp[100][100];
    for(int i =0;i<m;i++){
        for(int j =0;j<n;j++){
            dp[i][j]=0;
        }
    }
    
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(x[i-1]==y[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }
            else{
                dp[i][j]=max(dp[i-1][j] , dp[i][j-1]);
            }
        }
    }
    length=dp[m][n];
    int i=m , j=n;
    string lcs="";
    while(i>0 && j>0){
        if(x[i-1] == y[j-1]){
            lcs=x[i-1]+lcs;
            i--;
            j--;
        }else{
            if(dp[i-1][j] > dp[i][j-1])
            i--;
            else
            j--;
        }
        
    }
    return lcs;
}
int main(){
    string str1 , str2;
    cout<<"Enter first string :";
    cin>>str1;
    cout<<"Enter second strinf :";
    cin>>str2;
    
    int lcslength;
    
    string lcs=printlcs(str1 , str2 ,lcslength);
    cout<<"LCS charater"<<lcs;
    cout<<"Length :"<<lcslength;
    
}
