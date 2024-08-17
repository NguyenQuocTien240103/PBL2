#include <iostream>
#include <hocsinh.h>
#include <lop.h>
#include <bangdiem.h>
using namespace std;
class Node
{
public:
    HocSinh hs;
    BangDiem mh;
    Node *next;

public:
    Node();
    Node(HocSinh, BangDiem);
    ~Node();
};