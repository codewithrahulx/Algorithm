#include<iostream>
using namespace std;
int main(){
    int n , w;
    cout<<"Number of items :";
    cin>>n;
    cout<<"MAXIMUM capacity :";
    cin>>w;
    int value[100] , weight[100];
    cout<<"Number of value and weight :";
    for(int i =0;i<n;i++){
        cin>>value[i]>>weight[i];
    }
    int dp[101][101];
    for(int i =0;i<=n;i++){
        for(int j=0;j<=w;j++){
            dp[i][j]=0;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j =1;j<=w;j++){
            if(weight[i-1] <=j){
                dp[i][j]=max(dp[i-1][j] , value[i-1]+dp[i-1][j-weight[i-1]]);
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    cout<<"Maximum value in knapsack :"<<dp[n][w];
}