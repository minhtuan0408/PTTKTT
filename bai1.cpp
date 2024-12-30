#include <iostream>
using namespace std;

//soTien: Tổng số tiền cần đổi.
//loaiXu[]: Mảng chứa các giá trị xu khả dụng.
//n: Số lượng các loại xu.

void doiTien(int soTien, int loaiXu[], int n ){
    for(int i = 0; i < n; i++){
       int solgXu = soTien / loaiXu[i];
       if(solgXu > 0){
        cout<<"So luong xu "<<loaiXu[i]<<": "<<solgXu<<endl;
        soTien %= loaiXu[i];
        cout<<"so tien con lai "<<soTien<<endl;
       }
    }
}

int main()
{
    int soTien;
    cout<<"nhap so tien can doi: ";
    cin>>soTien;
    int n;
    cout<<"nhap so loai xu: ";
    cin>>n;
    int loaiXu[n];
    cout<<"Nhap gia tri cac loai xu: "<<endl;
    for(int i  = 0; i < n;i++){
        cin>>loaiXu[i];
    }

    
    doiTien(soTien, loaiXu, n);
    return 0;
}
