#include<iostream>
// #include "node.h"
using namespace std;
class QuanLi{
	private:
		Node *Head;
	public:
		QuanLi();
		int dem_so_luong_hoc_sinh();
		void them_hoc_sinh_vao_dau(HocSinh,MonHoc);
		void them_hoc_sinh_vao_cuoi(HocSinh,MonHoc);
		void them_hoc_sinh_vao_vi_tri_bat_ki(HocSinh,MonHoc,int);
		void xoa_hoc_sinh_o_vi_tri_dau_tien();
		void xoa_hoc_sinh_o_vi_tri_cuoi_cung();
		void xoa_hoc_sinh_o_vi_tri_bat_ki(int);
		void sua_diem_cho_hoc_sinh(int);
		void tim_kiem_hoc_sinh(int);
		void HienThiDanhSach();
		void sap_xep_diem();
		~QuanLi();
};
