#include "node_hocsinh.cpp"
class QuanLiHocSinh
{
private:
    Node_HocSinh *Head;

public:
    QuanLiHocSinh();
    Node_HocSinh *getHead();
    void SaveAllHocSinh(const string &);
    void ThemHocSinh(HocSinh);
    void XoaVaoViTriBatKi(int);
    void HienThiDanhSachHocSinh();
    // Đọc file
    void DocFile(ifstream &);
    ~QuanLiHocSinh();
};