#include "node_lop.cpp"
class QuanLiLop
{
private:
    Node_Lop *Head;

public:
    QuanLiLop();
    Node_Lop *getHead();
    void SaveAllLop(const string &);
    void ThemLop(Lop);
    void HienThiDanhSachLop();
    //  Đọc file ( đọc dữ liệu từ database lưu vào cấu trúc dữ liệu linked-list)
    void DocFile(ifstream &);
    ~QuanLiLop();
};