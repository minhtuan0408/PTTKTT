#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Hàm tìm dãy con có tổng lớn nhất cắt qua giữa mảng
int maxCrossingSum(const vector<int>& arr, int left, int mid, int right) {
    // Tìm tổng lớn nhất của dãy con bên trái cắt qua giữa
    int leftSum = INT_MIN;
    int sum = 0;
    for (int i = mid; i >= left; --i) {
        sum += arr[i];
        if (sum > leftSum) {
            leftSum = sum;
        }
    }

    // Tìm tổng lớn nhất của dãy con bên phải cắt qua giữa
    int rightSum = INT_MIN;
    sum = 0;
    for (int i = mid + 1; i <= right; ++i) {
        sum += arr[i];
        if (sum > rightSum) {
            rightSum = sum;
        }
    }

    // Trả về tổng lớn nhất của dãy con cắt qua giữa
    return leftSum + rightSum;
}

// Hàm đệ quy tìm dãy con có tổng lớn nhất trong mảng con
int maxSubArraySum(const vector<int>& arr, int left, int right) {
    // Trường hợp cơ bản: chỉ có một phần tử
    if (left == right) {
        return arr[left];
    }

    // Tính chỉ số giữa
    int mid = (left + right) / 2;

    // Tìm dãy con có tổng lớn nhất trong phần bên trái, bên phải và cắt qua giữa
    int leftSum = maxSubArraySum(arr, left, mid);
    int rightSum = maxSubArraySum(arr, mid + 1, right);
    int crossSum = maxCrossingSum(arr, left, mid, right);

    // Trả về tổng lớn nhất trong ba trường hợp
    return max(leftSum, max(rightSum, crossSum));
}

// Hàm chính để tìm dãy con có tổng lớn nhất trong mảng
int findMaxSubArray(const vector<int>& arr) {
    return maxSubArraySum(arr, 0, arr.size() - 1);
}

int main() {
    vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << "Tong lon nhat day con la: " << findMaxSubArray(arr) << endl;
    return 0;
}
