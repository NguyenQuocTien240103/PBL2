#include "./hocsinh/hocsinh.h"
class BangDiem
{
private:
    int Id;
    HocSinh hs;
    float Toan;

public:
    BangDiem();
    //getter
    int GetId();
    float GetToan();
    //setter
    void SetId(int);
    void SetToan(float);
    void SetHocSinh(HocSinh);
    //
    void DauVao();
    void GhiVaoFile(ofstream &);
    ~BangDiem();
};