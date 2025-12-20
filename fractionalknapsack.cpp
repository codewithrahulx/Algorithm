#include<iostream>
using namespace std;
int main(){
    int n ;
    cin>>n;

    int value[100], weight[100];
    double ratio[100];

    for(int i=0;i<n;i++){
        cin>>value[i]>>weight[i];
        ratio[i]=(double)value[i]/weight[i];
    }
    cout<<"Enter knapsack capacity: ";
    int w;
    cin>>w;
    
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(ratio[i] < ratio[j]){
                swap(ratio[i] , ratio[j]);
                swap(value[i] , value[j]);
                swap(weight[i] , weight[j]);
        }
    }
}

    double totalprofit=0;
    

    for(int i =0; i<n; i++){
        if(w == 0 ){
            break;

        }
        if(weight[i] <=w){
            w-=weight[i];
            totalprofit+=value[i];
        }
        else{
            totalprofit+=value[i] * (double)w/weight[i];
            w=0;
        }


    }
    cout<<"total profit is :"<<totalprofit;
    return 0;




}
