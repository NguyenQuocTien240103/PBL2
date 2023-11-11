#include<iostream>
using namespace std;

class MonHoc{
	private:
		double toan,li,hoa,van,anh,tin;
		double diemtrungbinh;
		string hocluc;
        int id;
	public:
		MonHoc();
		MonHoc(double,double,double,double,double,double,int);
		void nhapdiem();
		double get_toan();
		double get_li();
		double get_hoa();
		double get_van();
		double get_anh();
		double get_tin();
		double get_diem_trung_binh();
		string get_hoc_luc();
        int get_id();
		void set_toan(double);
		void set_li(double);
		void set_hoa(double);
		void set_van(double);
		void set_anh(double);
		void set_tin(double);
		void set_diem_trung_binh(double);
		void set_hoc_luc(string);
        void set_id(int);
		void xuatdiem();
		~MonHoc();
		void docFile_MonHoc(ifstream&);
};
