//#include "qlhs.cpp"
#include "lop/node_lop.cpp"
#include <fstream> // Thư viện để làm việc với file
using namespace std;
int main()
{
    //Sử dụng new cho cấp phát động: Nếu bạn muốn tạo đối tượng trên heap (bộ nhớ động),
    //bạn phải sử dụng new, và bạn cũng phải quản lý bộ nhớ đó bằng cách tự tay giải phóng nó với delete.
    //example : QuanLiHocSinh *ql = new QuanLiHocSinh();

    // Khi bạn khởi tạo đối tượng trên stack, bạn không cần sử dụng new, và đối tượng sẽ tự động được giải phóng khi ra khỏi phạm vi (scope).
    //QuanLiHocSinh ql;
    Node_Lop *head = nullptr;
    string fileName = "../data/data_lop/data.txt";
    ifstream fileInput(fileName);
    // Kiểm tra xem file có trống hay không

    // Vào đọc file và cập nhật lại địa chỉ của head
    head->DocFile(fileInput, head);
    // Tạo object lop
    Lop lop;
    for (int i = 0; i < 1; i++)
    {
        lop.DauVao();
        head->ThemLop(lop, head);
    }
    head->SaveAllLop(head, fileName);
    return 0;
}