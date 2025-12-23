#include<iostream>
#include<climits>
using namespace std;
int main(){
    int n ;
    cout<<"Enter the the number of coins :";
    cin>>n;
    int coin[100];
    cout<<"Enter the value of coins :";
    for(int i =0;i<n;i++){
        cin>>coin[i];
    }
    int amount;
    cout<<"Enter the amount";
    cin>>amount;
    int dp[100];
    dp[0]=0;
    for(int i =1;i<=amount;i++){
        dp[i]=INT_MAX;
    }
    for(int i=1;i<=amount;i++){
        for(int j =0;j<n;j++){
            if(coin[j]<=i && dp[i-coin[j] != INT_MAX]){
                dp[i]=min(dp[i] , 1+dp[i-coin[j]]);
            }
        }
    }
    
    if(dp[amount]==INT_MAX)
        cout<<"IMPOSSIBLE";
        else
        cout<<dp[amount];
}