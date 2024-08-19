#include "./hocsinh/hocsinh.h"
class BangDiem
{
private:
    int Id;
    HocSinh hs;
    float Toan;

public:
    BangDiem();
    int GetId();
    float GetToan();
    void SetId(int);
    void SetToan(float);
    void DauVao();
    ~BangDiem();
};