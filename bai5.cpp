#include <iostream>
using namespace std;

const int MAX_N = 100;
int n, f[MAX_N + 1];  // mảng f để lưu số cách phân tích các số từ 0 đến n

int main() {
    cout << "Vui long nhap n (n < 100): ";
    cin >> n;
    
    if (n < 0 || n >= 100) {
        cout << "Vui long nhap so nguyen n trong khoang (0, 100)." << endl;
        return 1;
    }

    // Khởi tạo giá trị cơ bản
    f[0] = 1;  // Chỉ có 1 cách phân tích số 0 (không có số nào)

    // Tính toán số cách phân tích từng số từ 1 đến n
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            f[j] += f[j - i];
        }
    }

    // In kết quả số cách phân tích n thành các tổng không phân biệt thứ tự
    cout << "So cach phan tich " << n << " thanh tong cac so nguyen duong la: " << f[n] << endl;

    return 0;
}
