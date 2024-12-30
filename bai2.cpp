#include <iostream>
#include <string>
using namespace std;

struct MatHang {
    string ten;   // Tên của mặt hàng (thay đổi từ char thành string để lưu chuỗi tên)
    int trongLuong; // Trọng lượng của mặt hàng
    int giaTri;     // Giá trị của mặt hàng
};

// Hàm so sánh tỷ lệ giá trị/trọng lượng giữa hai mặt hàng
bool soSanhMatHang(const MatHang &a, const MatHang &b) {
    return ((double)a.giaTri / a.trongLuong) > ((double)b.giaTri / b.trongLuong);
}

// Hàm sắp xếp danh sách mặt hàng theo tỷ lệ giá trị/trọng lượng giảm dần (Sử dụng thuật toán sắp xếp nổi bọt)
void sapXepNoiBot(MatHang matHangs[], int soLuongMatHang) {
    for (int i = 0; i < soLuongMatHang - 1; ++i) {
        for (int j = 0; j < soLuongMatHang - i - 1; ++j) {
            // So sánh nếu mặt hàng j có tỷ lệ giá trị/trọng lượng nhỏ hơn mặt hàng j+1
            if (!soSanhMatHang(matHangs[j], matHangs[j + 1])) {
                swap(matHangs[j], matHangs[j + 1]); // Đổi chỗ nếu cần
            }
        }
    }
}

// Hàm giải quyết bài toán chọn mặt hàng sao cho tổng giá trị tối đa mà không vượt quá sức chứa
void caiTuiDangPhanSo(MatHang matHangs[], int soLuongMatHang, int sucChua) {
    sapXepNoiBot(matHangs, soLuongMatHang); // Sắp xếp các mặt hàng theo tỷ lệ giá trị/trọng lượng
    double tongGiaTri = 0.0;  // Tổng giá trị của các mặt hàng trong túi
    int trongLuongHienTai = 0;  // Trọng lượng hiện tại của túi

    cout << "Danh sach mat hang duoc chon:" << endl;
    for (int i = 0; i < soLuongMatHang; ++i) {
        if (trongLuongHienTai + matHangs[i].trongLuong <= sucChua) {
            // Nếu có đủ chỗ trong túi, chọn toàn bộ mặt hàng
            trongLuongHienTai += matHangs[i].trongLuong;
            tongGiaTri += matHangs[i].giaTri;
            cout << "Chon toan bo mat hang " << matHangs[i].ten << " (Trong luong: "
                 << matHangs[i].trongLuong << ", Gia tri: " << matHangs[i].giaTri << ")" << endl;
        }
    }
    cout << "Tong gia tri cua tui la: " << tongGiaTri << endl;  // In tổng giá trị của các mặt hàng được chọn
}

int main() {
    int soLuongMatHang = 3;  // Số lượng mặt hàng
    MatHang matHangs[] = {
        {"Mat hang 1", 10, 60},  // Mặt hàng 1 (Tên, Trọng lượng, Giá trị)
        {"Mat hang 2", 20, 100},
        {"Mat hang 3", 30, 120},
        {"Mat hang 4", 40, 240}, 
        {"Mat hang 5", 50, 200} 
    };
    int sucChua = 31;
    caiTuiDangPhanSo(matHangs, soLuongMatHang, sucChua);  // Tính toán và in ra kết quả
    return 0;
}
