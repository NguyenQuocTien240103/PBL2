#include <iostream>
#include <fstream>
using namespace std;
class HocSinh
{
private:
    int Id;       // primary key
    string MaLop; // foregin key
    string TenHocSinh;
    string NgaySinh;

public:
    HocSinh();
    // getter
    int GetId();
    string GetMaLop();
    string GetTenHocSinh();
    string GetNgaySinh();
    // setter
    void SetId(int);
    void SetMaLop(string);
    void SetTenHocSinh(string);
    void SetNgaySinh(string);
    // Nhập
    void DauVao();
    // Xuất thông tin lớp ra file
    void GhiVaoFile(ofstream &);
    ~HocSinh();
};