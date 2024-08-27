#include<iostream>
using namespace std;

class HocSinh{
	private:
	string ten,ngaysinh,lop;
	public:
		HocSinh();
		HocSinh(string,string,string);
		string get_ten();
		string get_ngaysinh();
		string get_lop();
		void nhapthongtin();
		void set_lop(string);
		void set_ngaysinh(string);
		void set_ten(string);
		void xuat_thong_tin();
		~HocSinh();
		void docFile_hocsinh(ifstream&);
};
