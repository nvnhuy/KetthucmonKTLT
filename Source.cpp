#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#include <fstream>
#include <CoreWindow.h>
#define maxsize 100
using namespace std;
struct Khach
{
	char MaKhach[10];
	char HoTen[30];
	
};
struct SanBong
{
	char MaSan[10];
	int LoaiSan, GiaThue;
	char TinhTrang [10];
	char GiaChoThue[30];
};
struct SanPham
{
	char MaSP[10];
	char TenSP[20];
	char DonViTinh[10];
	int GiaBan;
	
};
struct CTHoaDon
{
	SanPham sp;
	int SoLuongBan,ThanhTien;
};
struct HoaDon
{
	int SoHoaDon;
	int TongTien;
	char GioBatDau [10];
	char GioKetThuc [10];
	char NgayChoThue[15];
	CTHoaDon cthd;
	SanBong sb;
	Khach k;
};
//void set_color(int code) {
//	HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
//	SetConsoleTextAttribute(color, code);
//}
void AnyPress()
{
	printf_s("\n\t\t[&]Nhan bat ki phim gi.....\n");
	_getch();
	system("cls");
}
void Xuat1Khach(Khach k,SanBong sb,HoaDon b)
{
	printf("\n%s\t%s\t%s\t%4d\t\t%d\t\t%s\t%s\t\t%s",k.MaKhach,k.HoTen,sb.MaSan,sb.LoaiSan,sb.GiaThue,b.NgayChoThue,b.GioBatDau,b.GioKetThuc);
}
void DSKhach(Khach k[],int &n,SanBong sb[],HoaDon b[])
{
	ifstream file;
	file.open("khach.txt");
	if(file.eof())
	{
		printf("\nKhong Tim Thay File");
	}
	else
	{
		file >> n;
		for(int i = 0;i < n;i++)
		{
			file >> k[i].MaKhach;
			file >> k[i].HoTen;
			file >> sb[i].MaSan;
			file >> sb[i].LoaiSan;
			file >> sb[i].GiaThue;
			file >> b[i].NgayChoThue;
			file >> b[i].GioBatDau;
			file >> b[i].GioKetThuc;
			
		}
	}
	file.close();

}
void XuatDSKhach(Khach k[],int n,SanBong sb[],HoaDon b[])
{
	printf("\nThong Tin Khach Hang");
	printf("\n%s%10s\t%5s\t%s\t\t%s\t\t%s\t%s\t%s","MaKhach","HoTen","MaSan","LoaiSan","GiaThue","NgayThue","GioBatDau","GioKetThuc");
	for(int i = 0;i < n;i++)
	{
		Xuat1Khach(k[i],sb[i],b[i]);
	}
}
void Xuat1SanPham(SanPham sp)
{
	printf("\n%s\t%s\t%s\t%d",sp.MaSP,sp.TenSP,sp.DonViTinh,sp.GiaBan);
}
void MenuSanPham(SanPham sp[],int &n)
{
	ifstream file2;
	file2.open("sanpham.txt");
	file2 >> n;
		for(int i = 0;i < n; i++)
		{
			file2 >> sp[i].MaSP;
			file2 >> sp[i].TenSP;
			file2 >> sp[i].DonViTinh;
			file2 >> sp[i].GiaBan;
		}
	file2.close();
}
void XuatMenuSanPham(SanPham sp[],int n)
{
	printf("\nThong Tin San Pham");
	printf("\n%s\t%s\t%s\t%s","MaSp","TenSp","DonVi","GiaBan");
	for(int i = 0;i < n;i++)
	{
		Xuat1SanPham(sp[i]);
	}
}
void Xuat1CTHoaDon(Khach k,CTHoaDon cthd)
{
	printf("\n%s\t%s\t%s\t%4d\t%d",k.MaKhach,k.HoTen,cthd.sp.MaSP,cthd.SoLuongBan,cthd.ThanhTien);
}
void ChiTietHoaDon(Khach k[],CTHoaDon cthd[],int &n)
{
	ifstream file;
	file.open("cthoadon.txt");
	if(file.eof())
	{
		printf("Khong Tim Thay file");
	}
	else
	{
		file >> n;
		for(int i = 0;i < n;i++)
		{
			file >> k[i].MaKhach;
			file >> k[i].HoTen;
			file >> cthd[i].sp.MaSP;
			file >> cthd[i].SoLuongBan;
			file >> cthd[i].ThanhTien;
		}
	}
	file.close();
}
void XuatDSCTHoaDon(Khach k[],CTHoaDon cthd[],int n)
{
	printf("\nThong Tin Chi Tiet Hoa Don");
	printf("\n%s\t%10s\t%s\t%s\t%s","MaKhach","HoTen","MaSp","SoLuong","ThanhTien");
	for(int i = 0;i < n;i++)
	{
		Xuat1CTHoaDon(k[i],cthd[i]);
	}
}
void Xuat1HoaDon(HoaDon b)
{
	
	printf("\n%s\t%s\t%s\t%d\t%d",b.k.MaKhach,b.k.HoTen,b.NgayChoThue,b.sb.GiaThue,b.cthd.ThanhTien);
	
	
}
void HoaDonKhach(HoaDon b[],int &n)
{
	ifstream filein;
	filein.open("hoadon.txt");
	if(filein.eof())
	{
		printf("\nLoi Khong Tim Thay File");
	}
	else
	{
		filein >> n;
		for(int i =0; i < n; i++)
		{
			
			filein >> b[i].k.MaKhach;
			filein >> b[i].k.HoTen;
			filein >> b[i].NgayChoThue;
			filein >> b[i].sb.GiaThue;
			filein >> b[i].cthd.ThanhTien;
		}
	}
}
void XuatDSHoaDon(HoaDon b[],int n)
{
	printf("\n Thong Tin Hoa Don Trong Ngay");
	printf("\n%s\t%s\t\t%s\t%s\t%s\t%s","MaKhach","HoTen","NgayThanhToan","GiaThue","TienSp","Tong");
	for(int i = 0;i < n; i++)
	{
		b[i].TongTien = b[i].sb.GiaThue + b[i].cthd.ThanhTien;
		Xuat1HoaDon(b[i]);
		printf("\t%d",b[i].TongTien);
		
	}
}
void LuuThongTinKhach(Khach k[],SanBong sb[],CTHoaDon cthd[],HoaDon b[],int n)
{
	ofstream fileout;
	fileout.open("thongtinkhach.txt", ios_base::out);
	for(int i = 0;i < n;i++)
	{
		fileout << "MaKhach: " << k[i].MaKhach << endl;
		fileout << "HoTen: " << k[i].HoTen  << endl;
		fileout << "MaSan: " << sb[i].MaSan  << endl;
		fileout << "LoaiSan: " << sb[i].LoaiSan  << endl;
		fileout << "GiaChoThue: " << sb[i].GiaThue  << endl;
		fileout << "NgayChoThue: " << b[i].NgayChoThue  << endl;
		fileout << "GioBatDau: " << b[i].GioBatDau  << endl;
		fileout << "GioKetThuc: " << b[i].GioKetThuc << "\n" << endl;
	}
	fileout.close();
}
void Xuat1SanBong(SanBong a)
{
	printf("\n-MaSan:%s\n-TinhTrang:%s\n-GiaChoThue:%s\n",a.MaSan,a.TinhTrang,a.GiaChoThue);
}
void XuatDSSanBong(SanBong &a)
{
	ifstream file3;
	file3.open("sanco.txt");
	printf("\nThong Tin San Bong, Tinh Trang Va Gia Thue San");
	string line;
	while(!file3.eof())
	{
			file3 >> a.MaSan;
			file3 >> a.TinhTrang;
			file3 >> a.GiaChoThue;
			Xuat1SanBong(a);
	}

}
void LuuSanBongMoi(SanBong &a)
{
	int n;
	printf("\nNhap Thong Tin San Moi !!!");
	do
	{
		printf("\nNhap So San Bong Moi: ");
		scanf_s("%d",&n);
		_flushall();
		if(n < 1)
		{
			printf("Vui Long Nhap Lai !!!");
		}
	}while(n < 1);
	for(int i = 0; i < n;i++)
	{
		printf("\nNhap Ma San: ");
		gets_s(a.MaSan);
		printf("Nhap Loai San: ");
		scanf_s("%d",&a.LoaiSan);
		_flushall();
		printf("Nhap Tinh Trang: ");
		gets_s(a.TinhTrang);
		printf("Nhap Gia Cho Thue: ");
		gets_s(a.GiaChoThue);
	}
	/*ofstream fileout;
	fileout.open("sanbong.txt",ios::app);
	for(int i = 0;i < n;i++)
	{
		fileout << "\nMaSan:" <<a.MaSan<< endl;
		fileout << "LoaiSan:" << a.LoaiSan << endl;
		fileout << "TinhTrang:" <<a.TinhTrang<< endl;
		fileout << "GiaChoThue:" <<a.GiaChoThue<< endl;
	}*/
	ofstream file2;
	file2.open("sanco.txt",ios::app);
	for(int i = 0;i < n; i++)
	{
		file2 << a.MaSan << "\t ";
		file2 << a.TinhTrang << "  ";
		file2 << a.GiaChoThue << endl;
	}
	file2.close();
	/*fileout.close();*/
}
void LuuThongTinKhachMoi(HoaDon &c,int n)
{
	printf("\n**Vui Long Nhap Thong Tin Khach Dat San** ");
	do
	{
		printf("\nNhap So Khach Moi: ");
		scanf_s("%d",&n);
		_flushall();
		if(n < 1)
		{
			printf("Vui Long Nhap Lai !!!");
		}
	}while(n < 1);
	for(int i = 0; i < n;i++)
	{
		printf("Nhap Ma Khach Thue: ");
		gets_s(c.k.MaKhach);
		printf("Nhap Ho Ten Khach: ");
		gets_s(c.k.HoTen);
		printf("Nhap Ma San: ");
		gets_s(c.sb.MaSan);
		printf("Nhap Loai San: ");
		scanf_s("%d",&c.sb.LoaiSan);
		_flushall();
		printf("Ngay Dat San: ");
		gets_s(c.NgayChoThue);
		printf("Gio Bat Dau: ");
		gets_s(c.GioBatDau);
		printf("Gio Ket Thuc: ");
		gets_s(c.GioKetThuc);
		printf("Gia Cho Thue: ");
		scanf_s("%d",&c.sb.GiaThue);
		_flushall();
		printf("Ma San Pham: ");
		gets_s(c.cthd.sp.MaSP);
		printf("So Luong: ");
		scanf_s("%d",&c.cthd.SoLuongBan);
		printf("Thanh Tien: ");
		scanf_s("%d",&c.cthd.ThanhTien);
		_flushall();
		c.TongTien = c.cthd.ThanhTien + c.sb.GiaThue;
		printf("Tong Tien: %d",c.TongTien);
	}
	ofstream fileout;
	fileout.open("thongtinkhachmoi.txt",ios::out);
	for(int i = 0;i < n;i++)
	{
		fileout << "MaKhach:" << c.k.MaKhach << endl;
		fileout << "HoTen:" << c.k.HoTen << endl;
		fileout << "MaSan:" << c.sb.MaSan << endl;
		fileout << "LoaiSan:" << c.sb.LoaiSan << endl;
		fileout << "NgayDatSan:" << c.NgayChoThue << endl;
		fileout << "GioBatDau:" << c.GioBatDau<< endl;
		fileout << "GioKetThuc:" << c.GioKetThuc << endl;
		fileout << "GiaChoThue:" << c.sb.GiaThue << endl;
		fileout << "MaSp:" << c.cthd.sp.MaSP << endl;
		fileout << "SoLuong:" << c.cthd.SoLuongBan << endl;
		fileout << "Tong:" << c.TongTien << endl;
	}
	fileout.close();
}
void HoanVi(HoaDon &b,HoaDon &b2)
{
	HoaDon t = b;
	b = b2;
	b2 = t;

}
void SapXepHoaDon_TongTien_GiamDan(HoaDon b[],int n)
{
	for(int i = 0;i < n;i++)
	{
		for(int j = i+1;j < n;j++)
		{
			b[i].TongTien = b[i].sb.GiaThue + b[i].cthd.ThanhTien;
			if(b[i].TongTien < b[j].TongTien)
				HoanVi(b[i],b[j]);
		}
	}
}
void SapXepHoaDon_MaKhach_TangDan(HoaDon b[],int n)
{
	for(int i = 0;i < n;i++)
	{
		for(int j = i + 1;j < n;j++)
		{
			if(strcmp(b[i].k.MaKhach,b[j].k.MaKhach) > 0)
			{
				HoanVi(b[i],b[j]);
			}
		}
	}
}
void menu()
{
	//SetConsoleOutputCP(65000);
	///*SetConsoleOutputCP(65001);*/
	//set_color(0 << 10 | 0 << 4 | 7);
	//system("CLS");
	//set_color(3 << 10 | 1 << 4 | 11);
	//printf("\t\t\t\t\t******************************\n");
	//printf("\t\t\t\t\t**Chuong trinh thue san bong**\n");
	//printf("\t\t\t\t\t******************************\n");
	//set_color(1 << 10 | 0 << 4 | 10);

	printf("\n1.Thong Tin Khach Thue San");
	printf("\n2.Thong Tin San Pham");
	printf("\n3.Thong Tin CT Hoa Don");
	printf("\n4.Thong Tin Hoa Don");
	printf("\n5.Luu Thong Tin Khach");
	printf("\n6.Thong Tin San Bong,Tinh Trang Va Gia Thue");
	printf("\n7.Luu Thong Tin San Bong Moi");
	printf("\n8.Luu Thong Tin Khach Moi");
	printf("\n9.Hoa Don Tang Dan Theo Ma Khach");
	printf("\n10.Hoa Don Giam Dan Theo Tong Tien");
	printf("\n0.Thoat Chuong Trinh");
}
int main()
{
	
	SanBong a;
	HoaDon c;
	Khach k[maxsize];
	SanBong sb[maxsize];
	HoaDon b[maxsize];
	SanPham sp[maxsize];
	CTHoaDon cthd[maxsize];
	int chon,n;
	menu();
	do
	{
		printf("\n\nChon Chuong Trinh Can Thuc Hien: ");
		scanf_s("%d",&chon);
		printf("*******************************************");
		switch(chon)
		{
		case 1:
			{
				DSKhach(k,n,sb,b);
				XuatDSKhach(k,n,sb,b);
				break;
			}
		case 2:
			{
				MenuSanPham(sp,n);
				XuatMenuSanPham(sp,n);
				break;
			}
		case 3:
			{
				ChiTietHoaDon(k,cthd,n);
				XuatDSCTHoaDon(k,cthd,n);
				break;
			}
		case 4:
			{
				HoaDonKhach(b,n);
				XuatDSHoaDon(b,n);
				break;
			}
		case 5:
			{
				LuuThongTinKhach(k,sb,cthd,b,n);
				printf("\nDa Luu Thong Tin Khach!!!");
				break;
			}
		case 6:
			{
				XuatDSSanBong(a);
				break;
			}
		case 7:
			{
				LuuSanBongMoi(a);
				printf("\nDa Luu Thong Tin San Bong Moi !!!");
				break;
			}
		case 8:
			{
				LuuThongTinKhachMoi(c,n);
				printf("\nDa Luu Thong Tin Khach Moi!!!");
				break;
			}
		case 9:
			{
				HoaDonKhach(b, n);
				XuatDSHoaDon(b, n);
				SapXepHoaDon_MaKhach_TangDan(b, n);
				printf("\nHoa don tang dan theo Ma Khach Hang");
				XuatDSHoaDon(b, n);
				AnyPress();
				break;
			}
		case 10:
			{
				HoaDonKhach(b, n);
				XuatDSHoaDon(b, n);
				SapXepHoaDon_TongTien_GiamDan(b, n);
				printf("\nHoa don giam dan theo Tong Tien");
				XuatDSHoaDon(b, n);
				AnyPress();
				break;
			}
		case 0: exit(1);
		}
	}while(1);

	system ("pause");
	return 0;
}