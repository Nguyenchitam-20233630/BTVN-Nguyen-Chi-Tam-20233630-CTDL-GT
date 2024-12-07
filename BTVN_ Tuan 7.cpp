#include <iostream>
using namespace std;
struct Dan_so{
    int nam;
    int so_nguoi_sinh_ra;
};
typedef struct Dan_so Dan_so;
Dan_so Nhap(Dan_so x){
    cout <<"Nam : ";
    cin >> x.nam;
    cout <<"So nguoi sinh ra trong nam : ";
    cin >> x.so_nguoi_sinh_ra;
    return x;
}
void NhapDS(Dan_so A[],int n){
    for(int i = 0 ;i <n;i++){
        A[i] = Nhap(A[i]);
    }
}
void Xuat(Dan_so x){
    cout <<"Nam : "<< x.nam;
   cout<<" co so nguoi sinh ra trong nam nay la : "<<x.so_nguoi_sinh_ra<<endl;
}
void XuatDS(Dan_so A[],int n){
    for(int i = 0 ;i <n;i++){
       Xuat(A[i]);  
    }
}
void Kiem_tra(Dan_so A[],int n,int &count){
    count = 0;
    for(int i = 0 ;i <n-1;i++){
        for(int j =i+1 ;j<n;j++){
            if(A[i].so_nguoi_sinh_ra == A[j].so_nguoi_sinh_ra){
                count ++;
            }
        }
    }
    cout<<"So nam co so nguoi sinh ra bang nhau la "<<count<<endl;
}
void Max(Dan_so A[], int n, int &max) {
    max = A[0].so_nguoi_sinh_ra;
    for (int i = 1; i < n; i++) {
        if (A[i].so_nguoi_sinh_ra > max) {
            max = A[i].so_nguoi_sinh_ra;
        }
    }

    for (int i = 0; i < n; i++) {
        if (A[i].so_nguoi_sinh_ra == max) {
            cout <<"Nam co so nguoi sinh ra lon nhat la nam "<< A[i].nam << endl;
        }
    }
}
void Min(Dan_so A[], int n, int &min) {
    min = A[0].so_nguoi_sinh_ra;
    for (int i = 1; i < n; i++) {
        if (A[i].so_nguoi_sinh_ra < min) {
            min = A[i].so_nguoi_sinh_ra;
        }
    }

    for (int i = 0; i < n; i++) {
        if (A[i].so_nguoi_sinh_ra == min) {
            cout <<"Nam co so nguoi sinh ra nho nhat la nam "<< A[i].nam << endl;
        }
    }
}

int main(){
    int n;
    cin>>n;
    int count;
    int max;
    int min;
    Dan_so a[n];
    NhapDS(a,n);
    XuatDS(a,n);
    Kiem_tra(a,n,count);
    Max(a,n,max);
    Min(a,n,min);
    return 0;
}
