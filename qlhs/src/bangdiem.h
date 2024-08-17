#include <iostream>
using namespace std;
class BangDiem
{
private:
    int Id;
    int IdHocSinh;
    float Toan;
    //Li, Hoa, DTB;
    //string HocLuc;
    //string HanhKiem;

public:
    BangDiem();
    void ShowBangDiem();
    void ThemBangDiem(BangDiem);
    int GetId();
    int GetIdHocSinh();
    float GetToan();
    void SetId();
    void SetIdHocSinh();
    void SetToan();
    ~BangDiem();
};