#include<iostream>
using namespace std;
int main(){
    int n ;
    cout<<"Enter the size of array :";
    cin>>n;
    int arr[100];
    cout<<"Enter the element :";
    for(int i =0;i<n;i++){
        cin>>arr[i];
    }
    for(int i =0;i<n;i++){
        int key=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
    cout<<"The sorted array is :";
    for(int i =0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}