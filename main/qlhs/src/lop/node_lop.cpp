#include "node_lop.h"
Node_Lop::Node_Lop(Lop lop)
{
    this->lop = lop;
    this->next = nullptr;
}

Node_Lop::~Node_Lop()
{
}