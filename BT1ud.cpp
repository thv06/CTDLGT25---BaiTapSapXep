#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

// Hàm tìm vị trí của k phần tử có giá trị lớn nhất
vector<int> findLargestElementsPositions(vector<int>& arr, int k) {
    vector<int> indices(arr.size());
    for (int i = 0; i < arr.size(); i++) {
        indices[i] = i;
    }

    sort(indices.begin(), indices.end(), [&](int i, int j) {
        return arr[i] > arr[j]; // Sắp xếp giảm dần theo giá trị
    });

    indices.resize(k); // Giữ lại k phần tử lớn nhất
    return indices;
}

// Hàm tính tổng các chữ số của một số nguyên
int digitSum(int num) {
    int sum = 0;
    num = abs(num); // Đảm bảo xử lý số âm đúng
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

// Hàm sắp xếp theo tổng các chữ số
void sortByDigitSum(vector<int>& arr) {
    sort(arr.begin(), arr.end(), [](int a, int b) {
        return digitSum(a) < digitSum(b);
    });
}

// Hàm kiểm tra số nguyên tố
bool isPrime(int num) {
    if (num < 2) return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

// Hàm xóa tất cả số nguyên tố trong dãy
void removePrimes(vector<int>& arr) {
    arr.erase(remove_if(arr.begin(), arr.end(), isPrime), arr.end());
}

// Hàm in mảng
void printArray(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr = {23, 5, 17, 40, 12, 8, 31, 15, 7, 9};
    int k = 3;

    // a) Tìm vị trí k phần tử lớn nhất
    vector<int> largestPositions = findLargestElementsPositions(arr, k);
    cout << "Vi tri " << k << " phan tu lon nhat: ";
    for (int pos : largestPositions) {
        cout << pos << " ";
    }
    cout << endl;

    // b) Sắp xếp theo tổng các chữ số
    sortByDigitSum(arr);
    cout << "Day sau khi sap xep theo tong chu so: ";
    printArray(arr);

    // c) Xóa số nguyên tố
    removePrimes(arr);
    cout << "Day sau khi xoa so nguyen to: ";
    printArray(arr);

    return 0;
}
