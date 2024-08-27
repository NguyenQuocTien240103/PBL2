#include "hocsinh.cpp"

class Node_HocSinh
{
public:
    HocSinh hs;
    Node_HocSinh *next;

public:
    Node_HocSinh();
    Node_HocSinh(HocSinh);
    ~Node_HocSinh();
};