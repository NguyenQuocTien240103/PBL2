#include <iostream>
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
    void ShowAllHocSinh();
    void ThemHocSinh(HocSinh);
    void SuaHocSinh(HocSinh);
    void XoaHocSinh(HocSinh);
    void TimKiemHocSinh(int);
    int GetId();
    string GetMaLop();
    string GetTenHocSinh();
    string GetNgaySinh();
    void SetId(int);
    void SetMaLop(string);
    void SetTenHocSinh(string);
    void SetNgaySinh(string);
    ~HocSinh();
};