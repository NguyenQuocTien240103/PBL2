#include "node_bangdiem.cpp"
class QuanLiBangDiem
{
private:
    Node_BangDiem *Head;

public:
    QuanLiBangDiem();
    void SaveBangDiem(const string &);
    int DemSoLuong();
    void ThemBangDiemVaoDau(BangDiem);
    void ThemBangDiemVaoCuoi(BangDiem);
    void ThemVaoViTriBatKi(BangDiem, int);
    void SuaDiem(int);
    void XoaBangDiemVaoDau(QuanLiHocSinh &);
    void XoaBangDiemVaoCuoi(QuanLiHocSinh &);
    void XoaVaoViTriBatKi(int, QuanLiHocSinh &);
    void TimKiemBangDiemHocSinh(int);
    void SapXepDiem();
    void HienThiDanhSachBangDiem();
    //  Đọc file ( đọc dữ liệu từ database lưu vào cấu trúc dữ liệu linked-list)
    void DocFile(ifstream &);
    ~QuanLiBangDiem();
};