#include "../hocsinh/quanli_hocsinh.cpp"
class BangDiem
{
private:
    HocSinh hs;
    float Toan, Li, Hoa, DTB;
    string HocLuc;

public:
    BangDiem();
    //getter
    HocSinh GetHocSinh();
    float GetToan();
    float GetLi();
    float GetHoa();
    float GetDTB();
    string GetHocLuc();
    //setter
    void SetToan(float);
    void SetLi(float);
    void SetHoa(float);
    void SetDTB(float, float, float);
    void SetHocLuc(float);
    void SetHocSinh(HocSinh);
    //
    void DauVao();
    //
    void DauRa();
    void GhiVaoFile(ofstream &);
    ~BangDiem();
};