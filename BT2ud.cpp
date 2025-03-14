#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Định nghĩa cấu trúc dữ liệu cho số hạng của đa thức
struct Term {
    double coefficient; // Hệ số
    int exponent;       // Bậc

    // Hàm tạo để khởi tạo giá trị
    Term(double c, int e) : coefficient(c), exponent(e) {}
};

// Hàm so sánh để sắp xếp theo bậc tăng dần
bool compareByExponent(const Term& a, const Term& b) {
    return a.exponent < b.exponent;
}

// Hàm nhập dữ liệu
void inputPolynomial(vector<Term>& polynomial, int n) {
    for (int i = 0; i < n; i++) {
        double coefficient;
        int exponent;
        cout << "Nhap he so va bac cua so hang thu " << i + 1 << ": ";
        cin >> coefficient >> exponent;
        polynomial.push_back(Term(coefficient, exponent));
    }
}

// Hàm hiển thị đa thức
void displayPolynomial(const vector<Term>& polynomial) {
    for (const auto& term : polynomial) {
        cout << term.coefficient << "x^" << term.exponent << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Nhap so luong so hang cua da thuc: ";
    cin >> n;

    vector<Term> polynomial;
    inputPolynomial(polynomial, n);

    // Sắp xếp theo bậc tăng dần
    sort(polynomial.begin(), polynomial.end(), compareByExponent);

    // Xuất kết quả sau khi sắp xếp
    cout << "Da thuc sau khi sap xep theo bac tang dan: ";
    displayPolynomial(polynomial);

    return 0;
}
