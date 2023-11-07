#include<iostream>
#include"thongtinhocsinh.cpp"
#include"diemmonhoc.cpp"
#include"node.cpp"
#include"qlhs.cpp"
using namespace std;
void gioi_thieu(){
	cout<<"\t\t\t....................................................................\n";
	cout<<"\t\t\t.                                                                  .\n";
	cout<<"\t\t\t.               PBL2: QUAN LI DIEM HOC SINH THPT                   .\n";
	cout<<"\t\t\t.                                                                  .\n";
	cout<<"\t\t\t....................................................................\n";
	cout<<"\t\t\t.                                                                  .\n";
	cout<<"\t\t\t.               NGUYEN QUOC TIEN    MSSV:102220043                 .\n";
	cout<<"\t\t\t.               PHAM QUOC VU        MSSV:102220050                 .\n";
	cout<<"\t\t\t.               GVHD: TS. TRUONG NGOC CHAU                         .\n";
	cout<<"\t\t\t....................................................................\n";
	cout<<endl;

}
int main(){
	QuanLi a;
	HocSinh student;
	MonHoc subject;
	int n;
	do{
		gioi_thieu();
		cout<<"------------------------------------------------CAC LUA CHON DE QUAN LI-------------------------------------------------\n\n";
		cout<<"\t\t\t\t\t0.them file vao danh sach"<<endl;
		cout<<"\t\t\t\t\t1.them hoc sinh vao dau danh sach"<<endl;
		cout<<"\t\t\t\t\t2.them hoc sinh vao cuoi danh sach"<<endl;
		cout<<"\t\t\t\t\t3.them hoc sinh vao vi tri bat ki"<<endl;
		cout<<"\t\t\t\t\t4.xoa hoc sinh o dau danh sach"<<endl;
		cout<<"\t\t\t\t\t5.xoa hoc sinh o cuoi danh sach"<<endl;
		cout<<"\t\t\t\t\t6.xoa hoc sinh o vi tri bat ki"<<endl;
		cout<<"\t\t\t\t\t7.sua diem cho hoc sinh"<<endl;
		cout<<"\t\t\t\t\t8.tim kiem hoc sinh"<<endl;
		cout<<"\t\t\t\t\t9.hien thi danh sach hoc sinh"<<endl;
		cout<<"\t\t\t\t\t10.sap xep diem"<<endl;
		cout<<"\t\t\t\t\tNhap TH:";cin>>n;
		if(n==0){
			int so_luong;
			ifstream filein1,filein2,filein3;
			filein1.open("thongtinhocsinh.txt");
			filein2.open("diemmonhoc.txt");
			filein3.open("so_luong.txt");
			filein3>>so_luong;
			for(int i=0;i<so_luong;i++){
			student.docFile_hocsinh(filein1);
			subject.docFile_MonHoc(filein2);
			a.them_hoc_sinh_vao_cuoi(student,subject);
			}
			system("cls");
		}
		else if(n==1){
			student.nhapthongtin();
			subject.nhapdiem();
			a.them_hoc_sinh_vao_dau(student,subject);
			system("cls");
		}
		else if(n==2){
			student.nhapthongtin();
			subject.nhapdiem();
			a.them_hoc_sinh_vao_cuoi(student,subject);
			system("cls");
		}
		else if(n==3){
			int pos;
			cout<<"nhap vi tri can them hoc sinh:"; cin>>pos;
			cout<<"nhap thong tin va` diem cua hoc sinh do:"<<endl;
			student.nhapthongtin();
			subject.nhapdiem();
			a.them_hoc_sinh_vao_vi_tri_bat_ki(student,subject,pos);
			system("cls");
		}
		else if(n==4){
			a.xoa_hoc_sinh_o_vi_tri_dau_tien();
			system("cls");
		}
		else if(n==5){
			a.xoa_hoc_sinh_o_vi_tri_cuoi_cung();
			system("cls");
		}
		else if(n==6){
			int pos;
			cout<<"nhap vi tri can xoa:"; cin>>pos;
			a.xoa_hoc_sinh_o_vi_tri_bat_ki(pos);
			system("cls");
		}
		else if(n==7){
			int pos;
			cout<<"nhap vi tri can sua diem cho hoc sinh:";cin>>pos;
			a.sua_diem_cho_hoc_sinh(pos);
			system("cls");

		}
		else if(n==8){
			system("cls");
			string name;
			cout<<"tim kiem hoc sinh bang cach loc ten"<<endl;
			cout<<"nhap ten hoc sinh ma` ban muon tim` kiem:";
			cin.ignore();
			getline(cin,name);
			cout<<"thong tin hoc sinh ma` ban tim kiem la:"<<endl;
			a.tim_kiem_hoc_sinh(name);
		}
		else if(n==9){
			system("cls");
			a.HienThiDanhSach();
		}
		else if(n==10){
			a.sap_xep_diem();
			system("cls");

		}
		else{
			system("cls");
			cout<<"TH ban vua nhap nam ngoai cac lua chon tren!!!"<<endl;
		}
	}while(n==0||n==1||n==2||n==3||n==4||n==5||n==6||n==7||n==8||n==9 || n==10);
}
