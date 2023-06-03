#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class hoadon {
protected:
    string mahoadon;
    string ngaythangnam;
public:
    hoadon() {
        this->mahoadon = "";
    }  
    void sethoadon(string mahoadon,string ngaythangnam)
    {
        this->mahoadon=mahoadon;
        this->ngaythangnam=ngaythangnam;

    }
	void virtual Xuat_hoa_don()
    {} ;
    int virtual tinhtongtientoanbo()=0;

};

class hoadondichvu : public hoadon {
    int soluongdichvu;
    int chiphiphatsinhthem;
    int* madichvu;
    string menu[3] = { "To chuc Su Kien", "To chuc Sinh Nhat " ,"To chuc Tiec Cuoi "};
    int gia[3] = { 5000, 6000, 10000 };
public:
    void sethoadon(string mahoadon,string ngaythangnam,int chiphiphatsinhthem, int soluongdichvu, int* madichvu)
     {  hoadon::sethoadon(mahoadon,ngaythangnam);
        this->soluongdichvu = soluongdichvu;
        this->chiphiphatsinhthem=chiphiphatsinhthem;
        this->madichvu = new int[soluongdichvu];

        for (int i = 0; i < soluongdichvu; i++) {
            this->madichvu[i] = madichvu[i];
        }
    }

    ~hoadondichvu() {
        delete[] madichvu;
    }

    int tinhtongtientoanbo() {
        int s = 0;
        for (int i = 0; i < soluongdichvu; i++) {
            s += gia[madichvu[i] - 1];
        }
        s+=chiphiphatsinhthem;
        return s;
    }

    void Xuat_hoa_don() {
        cout << "MA HOA DON: " << mahoadon << endl;
        cout << "Thoi gian: "    << ngaythangnam<<endl;
        for (int i = 0; i < soluongdichvu; i++) {
            cout << i + 1 << ". " << menu[madichvu[i] - 1] << " (" << gia[madichvu[i] - 1] << "000 VND)" << endl;
            cout << "Tong tien: " << gia[madichvu[i] - 1] << "000 VND" << endl;
            
        }   
            cout << "Chi phi phat sinh them : " << chiphiphatsinhthem << "0000 VND" <<endl;
            cout << "Tong tien toan bo: " << tinhtongtientoanbo() << "000 VND" << endl;
            cout << "-------------------------------------------------"<<endl;
    }
};

class hoadonmonan : public hoadon {
    int soluongmonan;
    int* mamonan;
    int* soluong;
    string menu[10] = { "Muc Hap", "Bun Bo", "Xoi Ga", "Pho Bo", "Goi Ca", "Ga Nuong","Thich Xien Nuong","Lau Bo","Nuoc Loc","Nuoc Ngot" };
    int gia[10] = { 60, 30, 24, 30, 45,200, 25,200,7,15};
public:
    void sethoadon(string mahoadon,string ngaythangnam,  int soluongmonan, int* mamonan, int* soluong) 
     {  hoadon::sethoadon(mahoadon,ngaythangnam);
        this->soluongmonan = soluongmonan;
        this->mamonan = new int[soluongmonan];
        this->soluong = new int[soluongmonan];

        for (int i = 0; i < soluongmonan; i++) {
            this->mamonan[i] = mamonan[i];
            this->soluong[i] = soluong[i];
        }
    }
    hoadonmonan(){
        this->mamonan=0;
        this->soluong=0;

    };

    ~hoadonmonan() {
        delete[] mamonan;
        delete[] soluong;
    }

    int tinhtongtientoanbo() {
        int s = 0;
        for (int i = 0; i < soluongmonan; i++) {
            s += gia[mamonan[i] - 1] * soluong[i];
        }
        return s;
    }

    void Xuat_hoa_don() {
        cout << "MA HOA DON: " << mahoadon << endl;
        cout << "Thoi gian : " << ngaythangnam <<endl;
        for (int i = 0; i < soluongmonan; i++) {
            cout << i + 1 << ". " << menu[mamonan[i] - 1] << " (" << gia[mamonan[i] - 1] << "000 VND)" << endl;
            cout << "So luong: " << soluong[i] << endl;
            cout << "Tong tien: " << gia[mamonan[i] - 1] * soluong[i] << "000 VND" << endl;
        }
        cout << "Tong tien toan bo: " << tinhtongtientoanbo() << "000 VND" << endl;
        cout << "-------------------------------------------------"<<endl;
    }
};

class KhachHang {
    string hoten;
    string masokhachhang;
    
    static int stt;
public:
 hoadon *hd;
    KhachHang() {
        hoten = "";
        masokhachhang = "";
    }

    KhachHang(string hoten, string masokhachhang) {
        this->hoten = hoten;
        this->masokhachhang = masokhachhang;
       
        stt++;
    }
    string gethoten() { return hoten; }
    string getmasokhachhang() { return masokhachhang; }
    static int getSTT() { return stt; }
};

int KhachHang::stt = -1;
void doc_file_hoa_don_dich_vu(ifstream& ifs, hoadondichvu& hd,string masohoadon,string ngaythangnam)
{  
   
    int chiphiphatsinhthem;
    int soluongdichvu;
    int* madichvu;
    ifs >> chiphiphatsinhthem;
    ifs.ignore();

    ifs >> soluongdichvu;
    ifs.ignore();

    madichvu = new int[soluongdichvu];

    for (int i = 0; i < soluongdichvu; i++) {
        ifs >> madichvu[i];
        ifs.ignore();
    }
 

    hd.sethoadon(masohoadon, ngaythangnam,chiphiphatsinhthem, soluongdichvu, madichvu);
    delete[] madichvu;



}

void doc_file_hoa_don_mon_an(ifstream& ifs, hoadonmonan& hd, string masohoadon,  string ngaythangnam) {
   
    int soluongmonan;
    int* mamonan;
    int* soluong;
    ifs >> soluongmonan;
    ifs.ignore();

    mamonan = new int[soluongmonan];
    soluong = new int[soluongmonan];

    for (int i = 0; i < soluongmonan; i++) {
        ifs >> mamonan[i];
        ifs.ignore();
        ifs >> soluong[i];
        ifs.ignore();
    }

    hd.sethoadon(masohoadon, ngaythangnam,soluongmonan, mamonan, soluong);
    delete[] mamonan;
    delete[] soluong;

}

void doc_file_khach_hang(ifstream& ifs, KhachHang& kh) {
    string hoten;
    string masokhachhang;

    getline(ifs, hoten, ';');
    getline(ifs, masokhachhang, ';');

    kh = KhachHang(hoten, masokhachhang);
}

int main() {
   
    int loaihoadon;
    hoadondichvu hd1[100];
    hoadonmonan hd[100];
    KhachHang khachHang[100];
    ifstream ifs;
    ofstream of1;
    ofstream of;
    int a;
    int k = 0;
    int i = 0;
    of1.open("doanhthu.txt");
    ifs.open("khachhang.txt");

    while (!ifs.eof()) 
       { doc_file_khach_hang(ifs, khachHang[i]);
          string masohoadon;
          string ngaythangnam;
        getline(ifs, masohoadon, ';');
        getline(ifs, ngaythangnam,';');
        ifs >> loaihoadon;
        ifs.ignore();
        if (loaihoadon==1)
         { 
           doc_file_hoa_don_mon_an(ifs,hd[i],masohoadon,ngaythangnam);
           khachHang[i].hd=&hd[i];
          } 
        else
         { hoadondichvu hd;
           doc_file_hoa_don_dich_vu(ifs,hd1[i],masohoadon,ngaythangnam);
           khachHang[i].hd=&hd1[i];
          } 
         i++;
      }
       //khachHang[0].hd->Xuat_hoa_don();
       system("cls");
 do
 {
    
      cout << "1.Xem Thong Tin Hoa Don Khach Hang"<<endl;
      cout << "0.Thoat va Cap Nhat Doanh THu"<<endl;
      cin >> a;
      switch (a)
   {case 1:
    string maSoKhachHang;
    cout << "Nhap Ma Khach Hang: ";
    cin >> maSoKhachHang;
    system("cls");
    for (int j = 0; j < KhachHang::getSTT(); j++) 
    {
        if (khachHang[j].getmasokhachhang() == maSoKhachHang) 
           { cout << "Ho Ten: " << khachHang[j].gethoten() << endl;
            cout << "Ma KHach Hang: " << khachHang[j].getmasokhachhang() << endl;
            khachHang[j].hd->Xuat_hoa_don();
            k = 1; 
        }
    }
  
    if (k == 0) 
        cout << "Khong Co thong tin khach hang" << endl;
 break;
    }
}while(a);
     int s=0;
      for (int v = 0; v < KhachHang::getSTT(); v++)
     {
       s+=khachHang[v].hd->tinhtongtientoanbo();
      } //tinhdoanhthu
    cout << "------Doanh Thu da duoc Cap Nhat------" ;
   of1 << s<<"000";
   of1.close();   
    ifs.close();
    system("pause");

    return 0;
}

