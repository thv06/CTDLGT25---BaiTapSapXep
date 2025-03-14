#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Hàm sắp xếp mảng theo yêu cầu
void sortArray(vector<int>& arr) {
    vector<int> even, odd;  // Danh sách chứa số chẵn và số lẻ
    vector<int> zeroPositions; // Lưu vị trí số 0

    // Phân loại phần tử
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == 0) {
            zeroPositions.push_back(i); // Ghi nhớ vị trí số 0
        } else if (arr[i] % 2 == 0) {
            even.push_back(arr[i]); // Số chẵn
        } else {
            odd.push_back(arr[i]); // Số lẻ
        }
    }

    // Sắp xếp số chẵn tăng dần và số lẻ giảm dần
    sort(even.begin(), even.end());
    sort(odd.rbegin(), odd.rend());

    // Ghép lại thành mảng ban đầu
    int evenIndex = 0, oddIndex = 0;
    for (int i = 0; i < arr.size(); i++) {
        if (find(zeroPositions.begin(), zeroPositions.end(), i) != zeroPositions.end()) {
            arr[i] = 0; // Giữ nguyên số 0
        } else if (evenIndex < even.size()) {
            arr[i] = even[evenIndex++]; // Lấy số chẵn đã sắp xếp
        } else {
            arr[i] = odd[oddIndex++]; // Lấy số lẻ đã sắp xếp
        }
    }
}

// Hàm main để chạy thử chương trình
int main() {
    vector<int> arr = {3, 0, 2, 8, 5, 0, 1, 4, 7, 0, 6}; // Ví dụ mảng đầu vào

    cout << "Mảng ban đầu: ";
    for (int num : arr) cout << num << " ";
    cout << endl;

    sortArray(arr);

    cout << "Mảng sau khi sắp xếp: ";
    for (int num : arr) cout << num << " ";
    cout << endl;

    return 0;
}
