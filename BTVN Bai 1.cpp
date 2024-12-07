#include <iostream>
using namespace std;
void Sap_xep(int A[],int n){
    for(int i
     =1;i<n;i++){
        int x = A[i];
        int j = i -1;
        while(j >=0 && A[j] > x){
            A[j+1]=A[j];
            j=j-1;}
            A[j+1]=x;
        }
    }
void Nhap_mang(int A[],int n){
    for(int i =0 ;i<n;i++){
        cin>>A[i];
    }
}
void In_mang(int A[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << A[i] << " ";
    cout << endl;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    Nhap_mang(arr,n);
    Sap_xep(arr, n);
    In_mang(arr, n);
    return 0;
}
