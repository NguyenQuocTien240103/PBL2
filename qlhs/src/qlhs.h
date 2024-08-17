#include <iostream>
#include "node.h"
using namespace std;
class QuanLiHocSinh
{
private:
    Node *Head;

public:
    QuanLiHocSinh();
    void ThemHocSinh(HocSinh);
    ~QuanLiHocSinh();
};