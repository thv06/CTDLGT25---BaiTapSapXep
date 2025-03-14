#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Định nghĩa cấu trúc dữ liệu cho phòng thi
struct ExamRoom {
    int roomNumber;  // Số phòng
    char building;   // Nhà (A-Z)
    int capacity;    // Khả năng chứa

    // Hàm khởi tạo
    ExamRoom(int num, char b, int cap) : roomNumber(num), building(b), capacity(cap) {}
};

// Hàm so sánh để sắp xếp theo khả năng chứa giảm dần
bool compareByCapacity(const ExamRoom& a, const ExamRoom& b) {
    return a.capacity > b.capacity;
}

// Hàm so sánh theo nhà (tăng dần), nếu cùng nhà thì sắp xếp theo số phòng (tăng dần)
bool compareByBuildingAndRoom(const ExamRoom& a, const ExamRoom& b) {
    if (a.building == b.building)
        return a.roomNumber < b.roomNumber;
    return a.building < b.building;
}

// Hàm so sánh theo nhà (tăng dần), nếu cùng nhà thì sắp xếp theo khả năng chứa (giảm dần)
bool compareByBuildingAndCapacity(const ExamRoom& a, const ExamRoom& b) {
    if (a.building == b.building)
        return a.capacity > b.capacity;
    return a.building < b.building;
}

// Hàm nhập danh sách phòng thi
void inputExamRooms(vector<ExamRoom>& rooms, int n) {
    for (int i = 0; i < n; i++) {
        int roomNumber, capacity;
        char building;
        cout << "Nhap so phong, nha (A-Z) va kha nang chua: ";
        cin >> roomNumber >> building >> capacity;
        rooms.push_back(ExamRoom(roomNumber, building, capacity));
    }
}

// Hàm hiển thị danh sách phòng thi
void displayExamRooms(const vector<ExamRoom>& rooms) {
    for (const auto& room : rooms) {
        cout << "Phong " << room.roomNumber << " - Nha " << room.building 
             << " - Kha nang chua: " << room.capacity << endl;
    }
}

int main() {
    int n;
    cout << "Nhap so luong phong thi: ";
    cin >> n;

    vector<ExamRoom> rooms;
    inputExamRooms(rooms, n);

    // Sắp xếp theo khả năng chứa giảm dần
    sort(rooms.begin(), rooms.end(), compareByCapacity);
    cout << "\nDanh sach phong theo kha nang chua giam dan:\n";
    displayExamRooms(rooms);

    // Sắp xếp theo nhà (tăng dần), cùng nhà thì theo số phòng (tăng dần)
    sort(rooms.begin(), rooms.end(), compareByBuildingAndRoom);
    cout << "\nDanh sach phong theo nha (A-Z), cung nha theo so phong tang dan:\n";
    displayExamRooms(rooms);

    // Sắp xếp theo nhà (tăng dần), cùng nhà thì theo khả năng chứa (giảm dần)
    sort(rooms.begin(), rooms.end(), compareByBuildingAndCapacity);
    cout << "\nDanh sach phong theo nha (A-Z), cung nha theo kha nang chua giam dan:\n";
    displayExamRooms(rooms);

    return 0;
}
