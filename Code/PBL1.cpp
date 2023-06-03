#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <sstream>
#include <windows.h>
using namespace std;
template <typename T> string tostr(const T& t){
	ostringstream os;os<<t;return os.str();
} 
	void gotoxy(int x,int y)
{    
	HANDLE hConsoleOutput;    
	COORD Cursor_an_Pos = {x-1,y-1};   
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);    
	SetConsoleCursorPosition(hConsoleOutput , Cursor_an_Pos);
}
void textcolor(int x)
{
	HANDLE mau;
	mau=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau,x);
}
void XoaManHinh()
{
	HANDLE hOut;
	COORD Position;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	Position.X = 0;
	Position.Y = 0;
	SetConsoleCursorPosition(hOut, Position);
}
class Nhan_vien{
	string Ten_nhan_vien,CCCD,vi_tri,sdt,MSNV;
	int luong,luong_thuong,tong_luong_nv;
		static int luong_dau_bep;
		static int luong_phuc_vu;
		static int luong_quan_li;
		static int so_gio_lam;
		static int so_ngay_lam;
	public:
		int s;
	Nhan_vien(){
	this->MSNV=MSNV;
	this->Ten_nhan_vien="";
	this->CCCD="";
	this->vi_tri="";
	this->sdt="";
	this->luong=0;
}
	Nhan_vien(string MSNV,string Ten_nhan_vien,string CCCD,string vi_tri,string sdt,int luong){
	this->Ten_nhan_vien=Ten_nhan_vien;
	this->CCCD=CCCD;
	this->vi_tri=vi_tri;
	this->sdt=sdt;
	this->luong=luong;
}	
		void setfullName(string Ten_nhan_vien){
	this->Ten_nhan_vien=Ten_nhan_vien;
}
		void setCCCD(string CCCD){
	this->CCCD=CCCD;
}
		void setPos(string vi_tri){
	this->vi_tri=vi_tri;
}
		void setPhone(string sdt){
	this->sdt=sdt;
}
		void setSalary(int luong){
	this->luong=(luong>0)?luong:0;
}

        string getfullName(){
        	return Ten_nhan_vien;
		}
		string getCCCD(){
        	return CCCD;
		}
		string getPos(){
        	return vi_tri;
		}
		string getPhone(){
			return sdt;
		}
		void settongluong(int tong_luong_nv){
			this->tong_luong_nv=tong_luong_nv;
		}
		int gettongluong(){
			return this->tong_luong_nv;
		}
	int getSalary(){
	return this->luong;
}
		void showInfor(){
	cout<<left<<setw(10)<<MSNV<<setw(25)
	<<Ten_nhan_vien<<setw(15)
	<<CCCD<<setw(15)
	<<vi_tri<<setw(20)
	<<sdt<<setw(15)
	<<getSalary()<<endl;	
}
int Tong_luong(Nhan_vien nv[20],int dem){
	tong_luong_nv=0;
	for(int i=0;i<dem;i++){
		tong_luong_nv+=nv[i].luong;
	}
	return tong_luong_nv;
}
void getInfor(){
	cout<<"Nhap MNV (DB,PV,QL): ";getline(cin,MSNV);
	while(MSNV.substr(0,2)!="DB"&&MSNV.substr(0,2)!="PV"&&MSNV.substr(0,2)!="QL"){
	cout<<"Nhap MSNV (DB,PV,QL): ";getline(cin,MSNV);}
	cout<<"Nhap ho va ten: ";getline(cin,Ten_nhan_vien);
	cout<<"Nhap CCCD: ";getline(cin,CCCD);
	cout<<"Nhap sdt: ";getline(cin,sdt);
}
void suathongtin(){
	int chon;
				do{cout<<"\n======SUA THONG TIN NHAN VIEN======\n1.Sua MNV\n2.Sua ten nhan vien.\n3.Sua dia chi nhan vien\n4.Sua so dien thoat nhan vien.\n5.Sua toan bo thong tin nhan vien.\n0.Thoat\nBan chon?";cin>>chon;
				switch(chon){
					case 1:{	cin.ignore();
					system("cls");
						cout<<"Nhap MNV moi(DB,PV,QL): ";getline(cin,MSNV);
						while(MSNV.substr(0,2)!="DB"&&MSNV.substr(0,2)!="PV"&&MSNV.substr(0,2)!="QL"){
	cout<<"Nhap MSNV (DB,PV,QL): ";getline(cin,MSNV);}
						break;
					}
					case 2:{cin.ignore();
					system("cls");
						cout<<"Nhap ten moi: ";getline(cin,Ten_nhan_vien);
						break;
					}
					case 3:{cin.ignore();
					system("cls");
						cout<<"Nhap CCCD moi: ";getline(cin,CCCD);
						break;
					}
					case 4:{cin.ignore();
					system("cls");
						cout<<"Nhap so dien thoai moi: ";getline(cin,sdt);
						break;
					}
					case 5:{cin.ignore();
					system("cls");
				        cout<<"Nhap MNV moi(DB,PV,QL): ";getline(cin,MSNV);
				        while(MSNV.substr(0,2)!="DB"&&MSNV.substr(0,2)!="PV"&&MSNV.substr(0,2)!="QL"){
	cout<<"Nhap MSNV (DB,PV,QL): ";getline(cin,MSNV);}
				        cout<<"Nhap ten moi: ";getline(cin,Ten_nhan_vien);
				        cout<<"Nhap CCCD moi: ";getline(cin,CCCD);
				        cout<<"Nhap so dien thoai moi: ";getline(cin,sdt);
						break;
					}
					
				}
				}while(chon);
}
void xoamangtaivitri(Nhan_vien nv[20],int &n,int vt){
	for(int i=0;i<n-1;i++){
		nv[i].MSNV=nv[i+1].MSNV;
		nv[i].Ten_nhan_vien=nv[i+1].Ten_nhan_vien;
		nv[i].CCCD=nv[i+1].CCCD;
		nv[i].sdt=nv[i+1].sdt;
		nv[i].vi_tri=nv[i+1].vi_tri;
		nv[i].luong=nv[i+1].luong;
	}
	n--;
}
void xoathongtinnv(Nhan_vien nv[20],int &n){
	string gt;cin.ignore();
	cout<<"\nNhap MSNV can xoa: ";getline(cin,gt);
	for(int i=0;i<n;i++){
		if(nv[i].MSNV==gt){
			xoamangtaivitri(nv,n,i+1);
		}
	}
}
int timkiem(Nhan_vien nv[20],int &n,string e){
	int kq;
	cout<<left<<setw(10)<<"MSNV"<<setw(25)
	                    <<"HO VA TEN "<<setw(15)
                     	<<"SO CCCD "<<setw(15)
                    	<<"CHUC VU"<<setw(20)
                    	<<"SO DIEN THOAI"<<setw(15)
	                    <<"LUONG"<<setw(15)<<endl;			
textcolor(14);	for(int i=0;i<n;i++){
		if(nv[i].Ten_nhan_vien==e){
					nv[i].showInfor();
					kq=1;
				}
				}
				textcolor(10);
				return kq;
				}
void timkiemnv(Nhan_vien nv[20],int n){
	string e;cin.ignore();
	cout<<"\nNhap ten nhan vien can tim: ";getline(cin,e);
	int kq=timkiem(nv,n,e);
	if(kq==1){
		cout<<"\n Tim thay nhan vien!";
//		timkiem(nv,n,e);
	}else cout<<"\n Khong tim thay nhan vien!";
}				
void menu(){
	s=0;
	Nhan_vien nv[20];
	int lc,n,chef,manag,ser;
	
	do{ chef=0;manag=0;ser=0;
		int dem=0;
	            ifstream f;
	         	f.open("nhanvien.txt",ios::in);
				while(f.eof()!=true){
				getline(f,nv[dem].MSNV,'#');
	            getline(f,nv[dem].Ten_nhan_vien,'#');
	            getline(f,nv[dem].CCCD,'#');
	            getline(f,nv[dem].vi_tri,'#');
            	getline(f,nv[dem].sdt,'#');
	             f>>nv[dem].luong;f.ignore(1);
	             if(nv[dem].vi_tri=="Dau Bep"){chef++;
				 }
	             
	             if(nv[dem].vi_tri=="Phuc Vu"){ser++;
	             	
				 }
	             
	             if(nv[dem].vi_tri=="Quan Li"){manag++;
				 }
	              dem++;
	            } 
//	            chef--;ser--;manag--;
	            dem--;
	            f.close();
	           s=Tong_luong(nv,dem);
	          system("cls");
		cout<<"\n=====QUAN LI NHAN VIEN=====\n1_Them nhan vien vao quan an.\n2_Cap nhat thong tin tat ca nhan vien.\n3_Hien thi thong tin dau bep.\n4_Hien thi thong tin quan li.\n5_Hien thi thong tin phuc vu.\n6.Sua chua thong tin nhan vien.\n7.Xoa thong tin nhan vien.\n8.Tim kiem nhan vien.\n0_Thoat."<<"\nBan chon ?"<<endl;cin>>lc;
		switch( lc ){
			case 1:{
				system("cls");
				textcolor(14);
				cout<<"So luong nhan vien moi tuyen: ";cin>>n;	cin.ignore();
				if(n>0)for(int i=dem;i<dem+n;i++){
				cout<<"Nhap thong tin nhan vien "<<i+1<<":"<<endl;
	            nv[i].getInfor();
	            if(nv[i].MSNV.substr(0,2)=="DB"){
	            	nv[i].luong=luong_dau_bep*so_gio_lam*so_ngay_lam;
	            	nv[i].vi_tri="Dau Bep";
	            	chef+=1;
	            	string str = tostr(chef);
	            if(str.length()==1){
	            nv[i].MSNV=nv[i].MSNV+"0"+str;
				}
				else nv[i].MSNV=nv[i].MSNV+str;
				}
				if(nv[i].MSNV.substr(0,2)=="PV"){
	            	nv[i].luong=luong_phuc_vu*so_gio_lam*so_ngay_lam;
	            	nv[i].vi_tri="Phuc Vu";
	            	ser+=1;
	            	string str = tostr(ser);
	            if(str.length()==1){
	            nv[i].MSNV=nv[i].MSNV+"0"+str;
				}
				else nv[i].MSNV=nv[i].MSNV+str;
				}
				if(nv[i].MSNV.substr(0,2)=="QL"){
	            	nv[i].luong=luong_quan_li*so_gio_lam*so_ngay_lam;
	            	nv[i].vi_tri="Quan Li";
	            	manag+=1;
	            	string str = tostr(manag);
	            if(str.length()==1){
	            nv[i].MSNV=nv[i].MSNV+"0"+str;
				}
				else nv[i].MSNV=nv[i].MSNV+str;
				}
	            }
				dem+=n; 
				fstream ofs;
					ofs.open("nhanvien.txt",ios::out);
	            for(int i=0;i<dem;i++){
					ofs<<nv[i].MSNV<<"#";
	                ofs<<nv[i].Ten_nhan_vien<<"#";
	                ofs<<nv[i].CCCD<<"#";
	                ofs<<nv[i].vi_tri<<"#";
	                ofs<<nv[i].sdt<<"#";
	                ofs<<nv[i].getSalary()<<"#";	
				}
				 ofs.close();textcolor(10);
				 system("pause");
				break;
				}
			case 2:{
					system("cls");
				cout<<left<<setw(10)<<"MSNV"<<setw(25)
	                    <<"HO VA TEN "<<setw(15)
                     	<<"SO CCCD "<<setw(15)
                    	<<"CHUC VU"<<setw(20)
                    	<<"SO DIEN THOAI"<<setw(15)
	                    <<"LUONG"<<setw(15)<<endl;	
	           textcolor(14);for(int i=0;i<dem;i++){					
					nv[i].showInfor();
				}
				textcolor(10);
				cout<<"Tong Luong Nhan Vien: "<<Tong_luong(nv,dem)<<endl;
				system("pause");
				break;
			}
			case 3:{
				system("cls");
				cout<<left<<setw(10)<<"MSNV"<<setw(25)
	                    <<"HO VA TEN "<<setw(15)
                     	<<"SO CCCD "<<setw(15)
                    	<<"CHUC VU"<<setw(20)
                    	<<"SO DIEN THOAI"<<setw(15)
	                    <<"LUONG"<<setw(15)<<endl;	
			 textcolor(14);	for(int i=0;i<dem;i++){
					if(nv[i].vi_tri=="Dau Bep"){
						nv[i].showInfor();
					}
				}textcolor(10);
				system("pause");
				break;
			}
			case 4:{
				system("cls");
				cout<<left<<setw(10)<<"MSNV"<<setw(25)
	                    <<"HO VA TEN "<<setw(15)
                     	<<"SO CCCD "<<setw(15)
                    	<<"CHUC VU"<<setw(20)
                    	<<"SO DIEN THOAI"<<setw(15)
	                    <<"LUONG"<<setw(15)<<endl;	
			textcolor(14);	for(int i=0;i<dem;i++){
					if(nv[i].vi_tri=="Quan Li"){
						nv[i].showInfor();
					}
				}textcolor(10);
				system("pause");
				break;
			}
			case 5:{
				system("cls");
				cout<<left<<setw(10)<<"MSNV"<<setw(25)
	                    <<"HO VA TEN "<<setw(15)
                     	<<"SO CCCD "<<setw(15)
                    	<<"CHUC VU"<<setw(20)
                    	<<"SO DIEN THOAI"<<setw(15)
	                    <<"LUONG"<<setw(15)<<endl;	
			textcolor(14);	for(int i=0;i<dem;i++){
					if(nv[i].vi_tri=="Phuc Vu"){
						nv[i].showInfor();
					}
				}
				textcolor(10);
				system("pause");
				break;
			}
			case 6:{
				chef=0;manag=0;ser=0;
				system("cls");
				string ms;
				cout<<"Nhap MSNV can sua: ";cin>>ms;
				for(int i=0;i<dem;i++){
					if(nv[i].MSNV==ms){
					nv[i].suathongtin();
					}
					if(nv[i].MSNV.substr(0,2)=="DB"){
	            	nv[i].luong=luong_dau_bep*so_gio_lam*so_ngay_lam;
	            	nv[i].vi_tri="Dau Bep";
	            	chef+=1;
	            	string str = tostr(chef);
	            if(str.length()==1){
	            nv[i].MSNV=nv[i].MSNV.substr(0,2)+"0"+str;
				}
				else nv[i].MSNV=nv[i].MSNV.substr(0,2)+str;
				}
				if(nv[i].MSNV.substr(0,2)=="PV"){
	            	nv[i].luong=luong_phuc_vu*so_gio_lam*so_ngay_lam;
	            	nv[i].vi_tri="Phuc Vu";
	            	ser+=1;
	            	string str = tostr(ser);
	            if(str.length()==1){
	            nv[i].MSNV=nv[i].MSNV.substr(0,2)+"0"+str;
				}
				else nv[i].MSNV=nv[i].MSNV.substr(0,2)+str;
				}
				if(nv[i].MSNV.substr(0,2)=="QL"){
	            	nv[i].luong=luong_quan_li*so_gio_lam*so_ngay_lam;
	            	nv[i].vi_tri="Quan Li";
	            	manag+=1;
	            	string str = tostr(manag);
	            if(str.length()==1){
	            nv[i].MSNV=nv[i].MSNV.substr(0,2)+"0"+str;
				}
				else nv[i].MSNV=nv[i].MSNV+str;
				}
				}
				fstream ofs;
					ofs.open("nhanvien.txt",ios::out);
				for(int i=0;i<dem;i++){
					ofs<<nv[i].MSNV<<"#";
	                ofs<<nv[i].Ten_nhan_vien<<"#";
	                ofs<<nv[i].CCCD<<"#";
	                ofs<<nv[i].vi_tri<<"#";
	                ofs<<nv[i].sdt<<"#";
	                ofs<<nv[i].getSalary()<<"#";	
				}
				 ofs.close();
				 system("pause");
				break;
			}
			case 7:{system("cls");
			xoathongtinnv(nv,dem);
			chef=0;manag=0;ser=0;
			for(int i=0;i<dem;i++){
					if(nv[i].MSNV.substr(0,2)=="DB"){
	            	nv[i].luong=luong_dau_bep*so_gio_lam*so_ngay_lam;
	            	nv[i].vi_tri="Dau Bep";
	            	chef+=1;
	            	string str = tostr(chef);
	            if(str.length()==1){
	            nv[i].MSNV=nv[i].MSNV.substr(0,2)+"0"+str;
				}
				else nv[i].MSNV=nv[i].MSNV.substr(0,2)+str;
				}
				if(nv[i].MSNV.substr(0,2)=="PV"){
	            	nv[i].luong=luong_phuc_vu*so_gio_lam*so_ngay_lam;
	            	nv[i].vi_tri="Phuc Vu";
	            	ser+=1;
	            	string str = tostr(ser);
	            if(str.length()==1){
	            nv[i].MSNV=nv[i].MSNV.substr(0,2)+"0"+str;
				}
				else nv[i].MSNV=nv[i].MSNV.substr(0,2)+str;
				}
				if(nv[i].MSNV.substr(0,2)=="QL"){
	            	nv[i].luong=luong_quan_li*so_gio_lam*so_ngay_lam;
	            	nv[i].vi_tri="Quan Li";
	            	manag+=1;
	            	string str = tostr(manag);
	            if(str.length()==1){
	            nv[i].MSNV=nv[i].MSNV.substr(0,2)+"0"+str;
				}
				else nv[i].MSNV=nv[i].MSNV+str;
				}
				}
				fstream ofs;
					ofs.open("nhanvien.txt",ios::out);
				for(int i=0;i<dem;i++){
					ofs<<nv[i].MSNV<<"#";
	                ofs<<nv[i].Ten_nhan_vien<<"#";
	                ofs<<nv[i].CCCD<<"#";
	                ofs<<nv[i].vi_tri<<"#";
	                ofs<<nv[i].sdt<<"#";
	                ofs<<nv[i].getSalary()<<"#";	
				}
				 ofs.close();
				system("pause");
				break;
			}
			case 8:{
				system("cls");
				timkiemnv(nv,dem);
				system("pause");
				break;
			}	
		}
		
	}while(lc);
//	delete[] nv;
	}
};
int Nhan_vien::luong_quan_li=30000;
int Nhan_vien::luong_phuc_vu=15000;
int Nhan_vien::luong_dau_bep=40000;
int Nhan_vien::so_gio_lam=8;
int Nhan_vien::so_ngay_lam=30;
class Chi_phi_phat_sinh{
	string loai_chi_phi;
	int so_tien;
	int tong_chi_phi,stt;
	public:
		int x;
		int getTongchiphi(){
			return tong_chi_phi;
		}
		Chi_phi_phat_sinh(){
			this->loai_chi_phi="";
			this->so_tien=0;
			this->tong_chi_phi=0;
		}
		Chi_phi_phat_sinh(string loai_chi_phi,float so_tien ){
			this->loai_chi_phi=loai_chi_phi;
			this->so_tien=so_tien;
		}
		void Nhap_loai_chi_phi(){
			cin.ignore();
		getline(cin,loai_chi_phi);
			
		}
		void Nhap_so_tien(){
			cout<<"Nhap so tien chi tra: ";cin>>so_tien;
		}
		float getChi_phi(){
			return so_tien;
		}
//	void checkint(int num){
//    bool valid = false; 
//    do 
//    {
//        cin >> num;
//        if (cin.fail()) 
//        {
//            cin.clear(); 
//            cin.ignore(1000, '\n'); 
//        }
//        else 
//        {
//            
//            valid = true; 
//        }
//    } while (!valid); 
//			
//		}
		
	void showthongtin(){
		cout<<left<<setw(10)<<stt<<setw(30)<<loai_chi_phi<<setw(30)<<so_tien<<endl;
	}
	int tong_chi_ps(Chi_phi_phat_sinh phat_sinh[20],int n){
		tong_chi_phi=0;
		for(int i=0;i<n;i++){
		tong_chi_phi+=phat_sinh[i].so_tien;
		}
		return tong_chi_phi;	
	}
	void menu_ps(){
		x=0;
		int lc,n,count;
		Chi_phi_phat_sinh phat_sinh[20];
		do{stt=0;count=0;n=0;
		count=0;
			ifstream ifs;
			ifs.open("chiphips.txt",ios::in);
			while(ifs.eof()!=true){
				ifs>>phat_sinh[count].stt;ifs.ignore();
				getline(ifs,phat_sinh[count].loai_chi_phi,'#');
				ifs>>phat_sinh[count].so_tien;ifs.ignore(1);
				count++;
			}
			count--;
			ifs.close();
			x=tong_chi_ps(phat_sinh,count);
			cout<<"\n======QUAN LI CHI PHI PHAT SINH======\n1.Them chi phi phat sinh.\n2.Hien thi lich su chi phi phat sinh.\n0.Thoat."<<endl;cout<<"Ban chon?";cin>>lc;
		switch(lc){
			case 1:{
				system("cls");textcolor(14);
				cout<<"Nhap so luong chi phi phat sinh : ";cin>>n;
	         for(int i=count;i<count+n;i++){
		    	cout<<"Nhap loai chi phi phat sinh "<<i+1<<":";
		    	phat_sinh[i].stt=i+1;
		        phat_sinh[i].Nhap_loai_chi_phi();
		        phat_sinh[i].Nhap_so_tien();
	} 
	count+=n;
				fstream of;
				of.open("chiphips.txt",ios::out);
				for(int i=0;i<count;i++){
					of<<phat_sinh[i].stt<<"#";
					of<<phat_sinh[i].loai_chi_phi<<"#";
	                of<<phat_sinh[i].so_tien<<"#";	
				}
				
				 of.close();
				 textcolor(10);
				break;
			}
			case 2:{system("cls");
			textcolor(14);
				cout<<left<<setw(10)<<"STT"<<setw(30)<<"Cac loai chi phi"<<setw(30)<<"So tien chi tra"<<endl;
				for(int i=0;i<count;i++){
					phat_sinh[i].showthongtin();
				}
				cout<<"Tong chi phi phat sinh:"<<tong_chi_ps(phat_sinh,count);x=tong_chi_ps(phat_sinh,count);
				textcolor(10);
				break;
			}		
		}
	}while(lc);			
}};
class Chi_phi{
     int tienhuhai;
	int tiendien,tiennuoc,tien_nl;
	int thue;
	int tat_ca_cp;
	static unsigned int tienvon;
	public:
	Chi_phi(){
		this->tienhuhai=0;
		this->tiendien=0;
		this->tiennuoc=0;
		this->thue=0;
	}
	Chi_phi( int tienhuhai,int tiendien,int tiennuoc,int thue,int tien_nl){
		this->tienhuhai=tienhuhai;
		this->tiendien=tiendien;
		this->tiennuoc=tiennuoc;
		this->thue=thue;
		this->tien_nl=tien_nl;
	}
	void nhap_cp(){
		float pthh;
	cout<<"Nhap phan tram hu hai csvc: ";cin>>pthh;
		tienhuhai=tienvon*(pthh/100);
		cout<<"\nNhap tien dien thang: ";cin>>tiendien;
			cout<<"\nNhap tien nuoc thang: ";cin>>tiennuoc;
				cout<<"\nNhap tien nguyen lieu thang: ";cin>>tien_nl;
	}
	int tongtienthang(){
		int tong;
		tong=tiendien+tiennuoc+tienhuhai;
		return tong;
	}
	int tinh_chi_phi(Nhan_vien nv,Chi_phi_phat_sinh phat_sinh){
		tat_ca_cp=nv.s+phat_sinh.x+tongtienthang();
		return tat_ca_cp;
	}
};
void Dieu_khien(Nhan_vien nv,Chi_phi_phat_sinh ps,Chi_phi cp){
	int chonlua;int doanhthu;doanhthu=0;
	do{system("cls");
	   gotoxy(47,1);cout<<"=====OPTION=====";
	   gotoxy(45,2);cout<<"1.QUAN LI NHAN VIEN.";
	   gotoxy(45,3);cout<<"2.QUAN LI KHACH HANG.";
	   gotoxy(45,4);cout<<"3.QUAN LI CHI PHI PHAT SINH.";
	   gotoxy(45,5);cout<<"4.BAO CAO CHI PHI.";
	   gotoxy(45,6);cout<<"5.BAO CAO DOANH THU.";
	   gotoxy(45,7);cout<<"6.BAO CAO LOI NHUAN.";
	   gotoxy(45,8);cout<<"0.THOAT! Ban Chon: ";cin>>chonlua;
	switch(chonlua){
		case 1:{system("cls");
		nv.menu();
			break;
		}
		case 2:{system("cls"); int l;
		 do{cout<<"\n=====QUAN LI KHACH HANG=====\n1.Nhap thong tin khach hang.\n2.Xuat thong tin hoa don.\n0.Thoat.\nBan chon:";cin>>l;
		 	switch(l){
		 		case 1:{
		 			system("nhapthongtinkhachhang.exe");
					break;
				 }
				 case 2:{
				 	system("xuatthongtinkhachhang.exe");
					break;
				 }
		 		
			 }
		 }while(l);
			
			
			break;
		}
		case 3:{
			system("cls");
			ps.menu_ps();
			system("pause");
			break;
		}
		case 4:{
			nv.menu();
			ps.menu_ps();
			system("cls");
			cp.nhap_cp();
			cout<<"\nTien chi tieu hang thang: "<<cp.tongtienthang();
			cout<<"\nLuong nhan vien: "<<nv.s;
	        cout<<"\nChi phi phat sinh : "<<ps.x;
	        cout<<"\nTong chi phi: "<<cp.tinh_chi_phi(nv,ps)<<endl;
			system("pause");	
			break;
		}
		case 5:{
			system("cls");ifstream f;
			f.open("doanhthu.txt",ios::in);
			f>>doanhthu;
			cout<<"Tong doanh thu: "<<doanhthu<<endl;
			system("pause");
			break;
		}
		case 6:{
			system("cls");
			ifstream f;
			f.open("doanhthu.txt",ios::in);
			f>>doanhthu;
			f.close();
			cout<<"\nTong chi phi: "<<cp.tinh_chi_phi(nv,ps);	
			cout<<"\nTong doanh thu: "<<doanhthu;
			cout<<"\nLoi nhuan "<<endl<<doanhthu-cp.tinh_chi_phi(nv,ps)<<endl;
			system("pause");
			break;
		}			
}}while(chonlua);
}
class Admin{
	string account,password;
	public:
	Nhan_vien nv;
	Chi_phi_phat_sinh ps;
	Chi_phi cp;
		void Dohoa(){textcolor(14);
	gotoxy(10,5);	cout<<" _______________     ____          ____      ____         ____      ____         ____       ____          ____ ";
	gotoxy(10,6);   cout<<"|SSSSSSSSSSSSSSS|   |UUUU|        |UUUU|    |NNNNN|      |NNNN|    |NNNNN|      |NNNN|     |YYYY|        |YYYY|";
	gotoxy(10,7);   cout<<"|SSSSS__________|   |UUUU|        |UUUU|    |NNNN|N|     |NNNN|    |NNNN|N|     |NNNN|     |YYYY|        |YYYY|";
	gotoxy(10,8);   cout<<"|SSSS|              |UUUU|        |UUUU|    |NNNN||N|    |NNNN|    |NNNN||N|    |NNNN|     |YYYY|        |YYYY|";
	gotoxy(10,9);	cout<<"|SSSS|__________    |UUUU|        |UUUU|    |NNNN| |N|   |NNNN|    |NNNN| |N|   |NNNN|      |YYYY|      |YYYY| ";
   gotoxy(10,10);	cout<<"|__________SSSSS|   |UUUU|        |UUUU|    |NNNN|  |N|  |NNNN|    |NNNN|  |N|  |NNNN|       |YYYY|    |YYYY|  ";
   gotoxy(10,11);	cout<<"           |SSSS|   |UUUU|        |UUUU|    |NNNN|   |N| |NNNN|    |NNNN|   |N| |NNNN|         |YYYY|_|YYYY|   ";
   gotoxy(10,12);   cout<<" __________|SSSS|   |UUUU|________|UUUU|    |NNNN|    |N||NNNN|    |NNNN|    |N||NNNN|           |YYYYYYY|     ";
   gotoxy(10,13);   cout<<"|SSSSSSSSSSSSSSS|   |UUUUUUUUUUUUUUUUUU|    |NNNN|     |N|NNNN|    |NNNN|     |N|NNNN|             |YYYY|      "; 
   gotoxy(10,14);   cout<<"|_______________|   |__________________|    |____|      |N____|    |____|      |N____|             |____|      ";
   gotoxy(25,16);  cout<<" _________________________________________________________________";
   gotoxy(25,17);  cout<<"|                                                                 |";
   gotoxy(25,18);  cout<<"|                                                                 |";
   gotoxy(25,19);  cout<<"|                                                                 |";
   gotoxy(25,20);  cout<<"|                                                                 |";
   gotoxy(25,21);  cout<<"|                                                                 |";
   gotoxy(25,22);  cout<<"|_________________________________________________________________|";
  gotoxy(25,23);   cout<<"|_________________________________________________________________|";
   }
		void Login(){textcolor(10);
			gotoxy(42,19);
			cout<<"Account: ";
			gotoxy(42,20);
			cout<<"Password: ";
			textcolor(15);
			gotoxy(51,19);getline(cin,this->account);
			gotoxy(51,20);getline(cin,this->password);
			while(((account!="admin1")||(password!="chuquan123"))&&((account!="nhanvien")||(password!="nv1"))){
				XoaManHinh();
				Dohoa();
			gotoxy(42,21);textcolor(12);cout<<"!Your password is false.Try again please!"<<endl;
			textcolor(10);
			gotoxy(42,19);
			cout<<"Account: ";
			gotoxy(42,20);
			cout<<"Password: ";
			textcolor(15);
			gotoxy(51,19);getline(cin,this->account);
			gotoxy(51,20);getline(cin,this->password);	
			}
			XoaManHinh();
			Dohoa();
			if(account=="admin1"){
			textcolor(10);gotoxy(40,20);cout<<"Ban da dang nhap voi tu cach la chu quan!";
			gotoxy(40,25);system("pause");
			system("cls");
			Dieu_khien(nv,ps,cp);
			}
			if(account=="nhanvien"){
			textcolor(10);gotoxy(40,20);cout<<"Ban da dang nhap voi tu cach la nhan vien!";
			gotoxy(40,25);system("pause");
			system("cls");
			int l;
		 do{cout<<"\n=====QUAN LI KHACH HANG=====\n1.Nhap thong tin khach hang.\n2.Xuat thong tin hoa don.\n0.Thoat.\nBan chon:";cin>>l;
		 	switch(l){
		 		case 1:{
		 			system("nhapthongtinkhachhang.exe");
					break;
				 }
				 case 2:{
				 	system("xuatthongtinkhachhang.exe");
					break;
				 }
		 		
			 }
		 }while(l);
		}
		}
};
unsigned int Chi_phi::tienvon=2000000000;
int main(){
		Admin a;
	a.Dohoa();
	a.Login();
		system("cls");
	a.Dohoa();
	gotoxy(40,20);textcolor(10);cout<<"Ket thuc ngay lam!Quan an Sunny xin cam on!"<<endl<<endl<<endl;
	return 0;
}
