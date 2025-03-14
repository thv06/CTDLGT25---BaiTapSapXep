#include <iostream>
#include <vector>

using namespace std;

// Hàm sắp xếp chẵn trước, lẻ sau với độ phức tạp O(n)
void separateEvenOdd(vector<int>& arr) {
    int left = 0, right = arr.size() - 1;

    while (left < right) {
        // Nếu phần tử đầu là số chẵn, tiếp tục duyệt sang phải
        if (arr[left] % 2 == 0) {
            left++;
        } 
        // Nếu phần tử cuối là số lẻ, tiếp tục duyệt sang trái
        else if (arr[right] % 2 == 1) {
            right--;
        } 
        // Nếu arr[left] là số lẻ và arr[right] là số chẵn -> hoán đổi vị trí
        else {
            swap(arr[left], arr[right]);
            left++;
            right--;
        }
    }
}

// Hàm main để chạy thử chương trình
int main() {
    vector<int> arr = {3, 8, 5, 2, 7, 4, 6, 9, 10}; // Ví dụ mảng đầu vào

    cout << "Mảng ban đầu: ";
    for (int num : arr) cout << num << " ";
    cout << endl;

    separateEvenOdd(arr);

    cout << "Mảng sau khi sắp xếp (chẵn trước, lẻ sau): ";
    for (int num : arr) cout << num << " ";
    cout << endl;

    return 0;
}
