#include<iostream>
#include"hocsinh.cpp"
#include"monhoc.cpp"
#include"node.cpp"
#include"quanli.cpp"
#include<vector>
#include<fstream>
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
	QuanLi quanli;
	vector<HocSinh> list_hoc_sinh;
	vector<MonHoc> list_mon_hoc;
	int n;
	do{
		gioi_thieu();
		cout<<"------------------------------------------------CAC LUA CHON DE QUAN LI-------------------------------------------------\n\n";
		cout<<"\t\t\t\t\t0.lay tu thong tin va diem hoc sinh tu file"<<endl;
		cout<<"\t\t\t\t\t1.nhap thong tin hoc sinh"<<endl;
		cout<<"\t\t\t\t\t2.nhap diem cua hoc sinh"<<endl;
		cout<<"\t\t\t\t\t3.hien thi thong tin cua hoc sinh"<<endl;
		cout<<"\t\t\t\t\t4.hien thi diem cua hoc sinh"<<endl;
		cout<<"\t\t\t\t\t5.hien thi thong tin va diem cua hoc sinh"<<endl;
		cout<<"\t\t\t\t\t6.them hoc sinh vao dau danh sach lop hoc"<<endl;
		cout<<"\t\t\t\t\t7.them hoc sinh vao cuoi danh sach lop hoc"<<endl;
		cout<<"\t\t\t\t\t8.them hoc sinh vao vi tri bat ki trong danh sach lop hoc"<<endl;
		cout<<"\t\t\t\t\t9.xoa hoc sinh o dau danh sach lop hoc"<<endl;
		cout<<"\t\t\t\t\t10.xoa hoc sinh o cuoi danh sach lop hoc"<<endl;
		cout<<"\t\t\t\t\t11.xoa hoc sinh o vi tri bat ki "<<endl;
		cout<<"\t\t\t\t\t12.sua diem cho hoc sinh"<<endl;
		cout<<"\t\t\t\t\t13.tim kiem hoc sinh"<<endl;
		cout<<"\t\t\t\t\t14.sap xep diem"<<endl;
		cout<<"\t\t\t\t\t15.hien thi thong tin va diem cua hoc sinh toan lop"<<endl;
		cout<<"\t\t\t\t\nhap TH:"; cin>>n;
		if(n==0){
			ifstream filein1,filein2,filein3;
			filein1.open("thongtinhocsinh.txt");
			filein2.open("diemmonhoc.txt");
			filein3.open("so_luong.txt");
			int soluong;
			filein3>>soluong;
			HocSinh student;
			MonHoc subject;
			for(int i=0;i<soluong;i++){
				student.docFile_hocsinh(filein1);
				list_hoc_sinh.push_back(student);
				subject.docFile_MonHoc(filein2);
				list_mon_hoc.push_back(subject);
			}
		}
		else if(n==1){
			HocSinh student;
			student.nhapthongtin();
			list_hoc_sinh.push_back(student);
			system("cls");
		}
		else if(n==2){
			MonHoc subject;
			subject.nhapdiem();
			list_mon_hoc.push_back(subject);
			system("cls");
		}
		else if(n==3){
			int x;
			cout<<"nhap id cua hoc sinh ma ban muon hien thi : "; cin>>x;
			system("cls");
			for(HocSinh a: list_hoc_sinh){
				if(a.get_id()==x){
					a.xuat_thong_tin();
				}
			}
		}
		else if(n==4){
			int x;
			cout<<"nhap id cua hoc sinh ma ban muon hien thi : ";cin>>x;
			system("cls");
			for(MonHoc a: list_mon_hoc){
				if(a.get_id()==x){
					a.xuatdiem();
				}
			}
		}
		else if(n==5){
			int x;
			cout<<"nhap id cua hoc sinh ma ban muon hien thi : "; cin>>x;
			system("cls");
			HocSinh student;
			for(HocSinh a: list_hoc_sinh){
				if(a.get_id()==x){
					student=a;
					break;
				}
			}
			MonHoc subject;
			for(MonHoc a: list_mon_hoc){
				if(a.get_id()==x){
					subject=a;
					break;
				}
			}
			student.xuat_thong_tin();
			subject.xuatdiem();
		}
		else if(n==6){
			int x;
			cout<<"nhap id cua hoc sinh ma ban muon them vao dau : "; cin>>x;
			HocSinh student;
			for(HocSinh a: list_hoc_sinh){
				if(a.get_id()==x){
					student=a;
					break;
				}
			}
			MonHoc subject;
			for(MonHoc a: list_mon_hoc){
				if(a.get_id()==x){
					subject=a;
					break;
				}
			}
			quanli.them_hoc_sinh_vao_dau(student,subject);
			system("cls");
		}
		else if(n==7){
				int x;
			cout<<"nhap id cua hoc sinh ma ban muon them vao cuoi : "; cin>>x;
			HocSinh student;
			for(HocSinh a: list_hoc_sinh){
				if(a.get_id()==x){
					student=a;
					break;
				}
			}
			MonHoc subject;
			for(MonHoc a: list_mon_hoc){
				if(a.get_id()==x){
					subject=a;
					break;
				}
			}
			quanli.them_hoc_sinh_vao_cuoi(student,subject);
			system("cls");
		}
		else if(n==8){
			int x,pos;
			cout<<"nhap id cua hoc sinh ma ban muon them vao vi tri bat ki : "; cin>>x;
			HocSinh student;
			for(HocSinh a: list_hoc_sinh){
				if(a.get_id()==x){
					student=a;
					break;
				}
			}
			MonHoc subject;
			for(MonHoc a: list_mon_hoc){
				if(a.get_id()==x){
					subject=a;
					break;
				}
			}
			cout<<"nhap vi tri ma ban muon them vao:";cin>>pos;
			quanli.them_hoc_sinh_vao_vi_tri_bat_ki(student,subject,pos);
			system("cls");
		}
		else if(n==9){
			quanli.xoa_hoc_sinh_o_vi_tri_dau_tien();
			system("cls");
		}
		else if(n==10){		
			quanli.xoa_hoc_sinh_o_vi_tri_cuoi_cung();
			system("cls");
		}
		else if(n==11){
			int x;
			cout<<"nhap id cua hoc sinh ma ban muon xoa:";cin>>x;
			quanli.xoa_hoc_sinh_o_vi_tri_bat_ki(x);
			system("cls");
		}
		else if(n==12){
			int x;
			cout<<"nhap id cua hoc sinh can sua diem:"; cin>>x;
			quanli.sua_diem_cho_hoc_sinh(x);
			system("cls");
		}
		else if(n==13){
			system("cls");
			int ID;
			cout<<"tim kiem hoc sinh ban cach tim id "<<endl;
			cout<<"nhap id cua hoc sinh ma` ban muon tim` kiem:";
			cin>>ID;
			cout<<"thong tin hoc sinh ma` ban tim kiem la:"<<endl;
			quanli.tim_kiem_hoc_sinh(ID);
		}
		else if(n==14){
			quanli.sap_xep_diem();
			system("cls");
		}
		else if(n==15){
			system("cls");
			quanli.HienThiDanhSach();
		}
		else{
			system("cls");
			cout<<"TH ban vua nhap nam ngoai cac lua chon tren!!!"<<endl;
		}

	}while(n==0||n==1||n==2||n==3 ||n==4 ||n==5 || n==6 || n==7 ||n==8||n==9||n==10||n==11|n==12||n==13||n==14||n==15);
	
}
