#include <fstream>
using namespace std;
class Lop
{
private:
    string MaLop;
    string TenLop;

public:
    Lop();

    // Getter
    string GetMaLop();
    string GetTenLop();

    // Setter
    void SetMaLop(string);
    void SetTenLop(string);

    // Nhập thông tin lớp
    void DauVao();

    // Xuất thông tin lớp ra file
    void GhiVaoFile(ofstream &);

    // Đọc file
    // void DocFile(ifstream &);
    // Hàm hủy
    ~Lop();
};