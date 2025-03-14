#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Hàm tính tổng của một dòng trong ma trận
int rowSum(const vector<int>& row) {
    int sum = 0;
    for (int num : row) {
        sum += num;
    }
    return sum;
}

// Hàm tìm dòng có tổng lớn nhất
int findMaxSumRow(const vector<vector<int>>& matrix, int m, int n) {
    int maxSum = -1, maxRowIndex = -1;
    for (int i = 0; i < m; i++) {
        int sum = rowSum(matrix[i]);
        if (sum > maxSum) {
            maxSum = sum;
            maxRowIndex = i;
        }
    }
    return maxRowIndex;
}

// Hàm sắp xếp các dòng theo tổng giảm dần
void sortRowsBySum(vector<vector<int>>& matrix, int m, int n) {
    sort(matrix.begin(), matrix.end(), [](const vector<int>& row1, const vector<int>& row2) {
        return rowSum(row1) > rowSum(row2); // Sắp xếp giảm dần theo tổng dòng
    });
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

// Hàm in ma trận
void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int num : row) {
            cout << num << " ";
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

    // a. Tìm dòng có tổng lớn nhất
    int maxRowIndex = findMaxSumRow(matrix, m, n);
    cout << "Dong co tong lon nhat la dong: " << maxRowIndex << endl;

    // b. Sắp xếp các dòng theo tổng giảm dần
    sortRowsBySum(matrix, m, n);
    cout << "\nMa tran sau khi sap xep theo tong giam dan:\n";
    printMatrix(matrix);

    return 0;
}
