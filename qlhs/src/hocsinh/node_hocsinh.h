#include "hocsinh.cpp"

class Node_HocSinh
{
public:
    HocSinh hs;
    Node_HocSinh *next;

public:
    Node_HocSinh();
    Node_HocSinh(HocSinh);
    void SaveAllHocSinh(Node_HocSinh *&, const string &);
    void ThemHocSinh(HocSinh, Node_HocSinh *&);
    void DocFile(ifstream &, Node_HocSinh *&);
    ~Node_HocSinh();
};