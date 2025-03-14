#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Hàm kiểm tra số nguyên tố
bool isPrime(int num) {
    if (num < 2) return false;
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) return false;
    }
    return true;
}

// Hàm tìm số nguyên tố lớn nhất trong ma trận
int findMaxPrime(const vector<vector<int>>& matrix, int m, int n) {
    int maxPrime = -1; // Nếu không có số nguyên tố nào thì trả về -1
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (isPrime(matrix[i][j]) && matrix[i][j] > maxPrime) {
                maxPrime = matrix[i][j];
            }
        }
    }
    return maxPrime;
}

// Hàm tìm các dòng chứa ít nhất một số nguyên tố
vector<int> findRowsWithPrimes(const vector<vector<int>>& matrix, int m, int n) {
    vector<int> rows;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (isPrime(matrix[i][j])) {
                rows.push_back(i);
                break;
            }
        }
    }
    return rows;
}

// Hàm tìm các dòng chỉ chứa toàn số nguyên tố
vector<int> findRowsWithOnlyPrimes(const vector<vector<int>>& matrix, int m, int n) {
    vector<int> rows;
    for (int i = 0; i < m; i++) {
        bool allPrime = true;
        for (int j = 0; j < n; j++) {
            if (!isPrime(matrix[i][j])) {
                allPrime = false;
                break;
            }
        }
        if (allPrime) rows.push_back(i);
    }
    return rows;
}

// Hàm nhập ma trận
void inputMatrix(vector<vector<int>>& matrix, int m, int n) {
    cout << "Nhap cac phan tu cua ma tran:\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }
}

// Hàm hiển thị danh sách các dòng
void displayRows(const vector<int>& rows) {
    if (rows.empty()) {
        cout << "Khong co dong nao thoa man.\n";
    } else {
        cout << "Cac dong: ";
        for (int row : rows) {
            cout << row << " ";
        }
        cout << endl;
    }
}

int main() {
    int m, n;
    cout << "Nhap so dong (m) va so cot (n): ";
    cin >> m >> n;

    vector<vector<int>> matrix(m, vector<int>(n));

    inputMatrix(matrix, m, n);

    // a. Tìm số nguyên tố lớn nhất trong ma trận
    int maxPrime = findMaxPrime(matrix, m, n);
    if (maxPrime == -1)
        cout << "Ma tran khong co so nguyen to.\n";
    else
        cout << "So nguyen to lon nhat trong ma tran: " << maxPrime << endl;

    // b. Tìm các dòng chứa ít nhất một số nguyên tố
    cout << "\nNhung dong chua it nhat mot so nguyen to:\n";
    displayRows(findRowsWithPrimes(matrix, m, n));

    // c. Tìm các dòng chỉ chứa toàn số nguyên tố
    cout << "\nNhung dong chi chua cac so nguyen to:\n";
    displayRows(findRowsWithOnlyPrimes(matrix, m, n));

    return 0;
}
