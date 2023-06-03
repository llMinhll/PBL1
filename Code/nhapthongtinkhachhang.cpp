#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void menumonan()
{
    cout << " ----MA Mon AN----" <<endl;
    cout << "1.Muc Hap"
    <<"\n2.Bun Bo"
    <<"\n3.Xoi Ga"
    <<"\n4.Pho Bo"
    <<"\n5.Goi Ca"
    <<"\n6.Ga Nuong"
    <<"\n7.Thich Xien Nuong"
    <<"\n8.Lau Bo"
    <<"\n9.Nuoc Loc"
    <<"\n10.Nuoc Ngot" <<endl;

}
void menudichvu()
{
    cout <<"----Ma Dich Vu----" <<endl;
    cout <<"1.To chuc Su Kien " <<endl;
    cout <<"2.To chuc Sinh Nhat " << endl;
    cout <<"3.To chuc Tiec Cuoi " << endl;
}
class thongtin
{
    string hoten, makhachhang, mahoadon,ngaythangnam;
    int loaihoadon;
    int chiphiphatsinhthem;
    int* madichvu;
    int* mamonan;
    int* soluong;
    int soluongdichvu;
    int soluongmonan;
    static int stt;

public:
    ~thongtin()
    {
        delete[] mamonan;
        delete[] soluong;
        delete[] madichvu;
    }

    thongtin()
    {
        this->hoten = "0";
        this->makhachhang = "0";
        this->mahoadon = "0";
        this->ngaythangnam="0";
        this->loaihoadon =0;
        this->chiphiphatsinhthem=0;
        this->soluongdichvu=0;
        this->soluongmonan = 0;
        this->madichvu = new int[1];
        this->mamonan = new int[1];
        this->soluong = new int[1];
        this->mamonan[0] = 0;
        this->madichvu[0] = 0;
        this->soluong[0] = 0;
    }
    void setthongtinhdmonan(string hoten, string masokhachhang, string mahoadon, string ngaythangnam,int soluongmonan, int* mamonan, int* soluong)
    {
        this->hoten = hoten;
        this->makhachhang = masokhachhang;
        this->mahoadon = mahoadon;
        this->ngaythangnam=ngaythangnam;
        this->soluongmonan = soluongmonan;
        this->mamonan = new int[soluongmonan];
        this->soluong = new int[soluongmonan];

        for (int i = 0; i < soluongmonan; i++)
        {
            this->mamonan[i] = mamonan[i];
            this->soluong[i] = soluong[i];
        }
        loaihoadon=1;
        stt += 1;
    }
    void setthongtinhddichvu(string hoten, string masokhachhang, string mahoadon, string ngaythangnam, int chiphiphatsinhthem,int soluongdichvu, int* madichvu)
    {
        this->hoten = hoten;
        this->makhachhang = masokhachhang;
        this->mahoadon = mahoadon;
        this->ngaythangnam=ngaythangnam;
        this->chiphiphatsinhthem=chiphiphatsinhthem;
        this->soluongdichvu = soluongdichvu;
        this->mamonan = new int[soluongdichvu];

        for (int i = 0; i < soluongdichvu; i++)
        {
            this->madichvu[i] = madichvu[i];
        }
      loaihoadon=2;
        stt += 1;
    }
    void sethoten()
    {  cout << "Nhap Lai Ho Ten : " ;
    cin.ignore();
       getline(cin,hoten);
         
    }   
    void setmakhachhang()
    {
        cout << "Nhap Lai Ma Khach Hang : ";
        cin >> makhachhang;

    }
    void setmahoadon()
    {
        cout << "Nhap Lai Ma Hoa Don : ";
        cin >> mahoadon;
    }
    void setthoigian()
    {
        cout <<" Nhap Lai Thoi Gian : ";
        cin.ignore();
        getline(cin,ngaythangnam);
    }
    void setchiphiphatsinh()
    {
        cout << "Nhap Lai Chi Phi Phat sinh : ";
        cin >> chiphiphatsinhthem;
    }
    void setthongtinmonan()
    {    menumonan();
          cout << "Nhap so luong mon an ";
          cin >> soluongmonan;
          for (int i=0;i <soluongmonan;i++)
          {do{
               cout << "Nhap Ma Mon An Thu " << i + 1 << ": ";
               cin >> mamonan[i];
            if (mamonan[i] > 10 || mamonan[i]<1)
              {
                cout << "---Nhap Sai,Moi Nhap lai---" <<endl ;
              }
       } 
       while (mamonan[i] > 10 || mamonan[i]<1);

               cout << "Nhap So Luong: ";
                cin >> soluong[i];

     }
    }
   void setthongtindichvu()
   {      menudichvu();
          cout << "Nhap so luong dich vu";
          cin >> soluongdichvu;
          for (int i=0;i <soluongmonan;i++)
          { do{
               cout << "Nhap Ma Dich Vu Thu " << i + 1 << ": ";
               cin >> madichvu[i];
               if (mamonan[i] > 3 || mamonan[i]<1)
            {
                cout << "---Nhap Sai,Moi Nhap lai---"<<endl ;
            }
          } 
       while (mamonan[i] > 3 || mamonan[i]<1);

          }
    }   
    int getloaihoadon()
    {
      return loaihoadon;
    }
    int getchiphiphatsinh()
    {
      return chiphiphatsinhthem;
    }
    string gethoten()
    {
        return hoten;
    }
    string getmakhachhang()
    {
        return makhachhang;
    }
    string getmahoadon()
    {
        return mahoadon;
    }
    string getthoigian()
    {
        return ngaythangnam;
    }
    int getsoluongmonan()
    {
        return soluongmonan;
    }   
    int getsoluongdichvu()
    {
        return soluongdichvu;
    }
   int* getmadichvu()
    {
        return madichvu;
    }
    int* getmamonan()
    {
        return mamonan;
    }
    int* getsoluong()
    {
        return soluong;
    }
    static int getstt()
    {
        return stt;
    }
    static void setstt()
    {
        stt=stt-1;
    }
    
};

int thongtin::stt = -1;

void nhap_thong_tin_tu_file(ifstream& ifs, thongtin& tt)
{
    string hoten, makhachhang, mahoadon,ngaythangnam;
    int soluongmonan,loaihoadon,soluongdichvu,chiphiphatsinhthem;
    getline(ifs, hoten, ';');
    getline(ifs, makhachhang, ';');
    getline(ifs, mahoadon, ';');
    getline(ifs,ngaythangnam,';');
    ifs >> loaihoadon;
    ifs.ignore();
    if (loaihoadon==1)
    { ifs >> soluongmonan;
      ifs.ignore();

       int* mamonan = new int[soluongmonan];
       int* soluong = new int[soluongmonan];

    for (int i = 0; i < soluongmonan; i++)
    {
        ifs >> mamonan[i];
        ifs.ignore();
        ifs >> soluong[i];
        ifs.ignore();
    }

    tt.setthongtinhdmonan(hoten, makhachhang, mahoadon,ngaythangnam,soluongmonan, mamonan, soluong);

      delete[] mamonan;
      delete[] soluong;
    }
    else if (loaihoadon==2)
    {    ifs >> chiphiphatsinhthem;
         ifs.ignore();
         ifs >> soluongdichvu;
         ifs.ignore();

    int* madichvu = new int[soluongdichvu];
    for (int i = 0; i < soluongdichvu; i++)
    {
        ifs >> madichvu[i];
        ifs.ignore();
    }

    tt.setthongtinhddichvu(hoten, makhachhang, mahoadon,ngaythangnam,chiphiphatsinhthem,soluongdichvu, madichvu);



    }
      ifs.ignore();
}
void nhap_them_thong_tin(thongtin& tt)
{
    string hoten, makhachhang, mahoadon,ngaythangnam;
    int soluongmonan,loaihoadon,chiphiphatsinh;
   
   
    cout << "Nhap Thong Tin Khach Hang Thu " << thongtin::getstt() +1 << endl;
    cout << "Nhap Ho Ten Khach Hang: ";
    getline( cin,hoten);

    cout << "Nhap Ma Khach Hang: ";
    cin >> makhachhang;

    cout << "Nhap Ma Hoa Don: ";
    cin >> mahoadon; 
    cout << "Nhap thoi gian : ";
    cin.ignore();
    getline(cin,ngaythangnam);
    //cout << ngaythangnam;
   
    cout << "Nhap Loai Hoa don (1 hoac 2): ";
    cin >> loaihoadon;
    if (loaihoadon !=1 && loaihoadon !=2) 
    {
        cout <<"Nhap sai nen loai hoa don se la loai 1" <<endl;
        loaihoadon=1;
    }    
  if (loaihoadon==1)
  { menumonan();
    cout << "Nhap So Luong Mon An: ";
    cin >> soluongmonan;

    int* mamonan = new int[soluongmonan];
    int* soluong = new int[soluongmonan];

    for (int j = 0; j < soluongmonan; j++)
    {
        
       do { cout << "Nhap Ma Mon An Thu " << j + 1 << ": ";
            cin >> mamonan[j];
            if (mamonan[j] > 10 || mamonan[j]<1)
            {
                cout << "----Nhap Sai,Moi Nhap lai ----" <<endl;
            }
       } 
       while (mamonan[j] > 10 || mamonan[j]<1);
        cout << "Nhap So Luong: ";
        cin >> soluong[j];
    }
    tt.setthongtinhdmonan(hoten, makhachhang, mahoadon,ngaythangnam, soluongmonan, mamonan, soluong);
    //cout << tt.getthoigian();

  
  }
  else
  if (loaihoadon==2)
  { cout << "Nhap Chi Phi Phat Sinh :";
    cin >> chiphiphatsinh;
    menudichvu();
    cout << "Nhap So Luong Dich Vu  : ";
    cin >> soluongmonan;

    int* madichvu = new int[soluongmonan];
    int* soluong = new int[soluongmonan];

    for (int j = 0; j < soluongmonan; j++)
    {do{
        cout << "Nhap Ma Dich Vu Thu  " << j + 1 << ": ";
        cin >> madichvu[j];
              if (madichvu[j] > 3 || madichvu[j]<1)
            {
                cout << "------Nhap Sai,Moi Nhap lai----" <<endl ;
            }
       } 
       while (madichvu[j] > 3 || madichvu[j]<1);
    }
 
   tt.setthongtinhddichvu(hoten, makhachhang, mahoadon,ngaythangnam, chiphiphatsinh, soluongmonan, madichvu);
  // cout << tt.getthoigian();
   // cout << "khong loi";
  
  

    delete[] madichvu;
    delete[] soluong;

  }
     cin.ignore();
  
    
}

void nhap_thong_tin_vao_file(ofstream& of, thongtin& tt)
{
    of << tt.gethoten() << ";";
    of << tt.getmakhachhang() << ';';
    of << tt.getmahoadon() << ';';
    of << tt.getthoigian() << ';';
    of << tt.getloaihoadon() << ';';
    if (tt.getloaihoadon()==1)
    {
    of << tt.getsoluongmonan() << ';';

    for (int i = 0; i < tt.getsoluongmonan(); i++)
    {
        of << tt.getmamonan()[i] << '-';
        of << tt.getsoluong()[i] << ';';
    }

    of << "\n";
    }
    else
      if (tt.getloaihoadon()==2)
        {  of << tt.getchiphiphatsinh() << ';';
           of << tt.getsoluongdichvu() << ';';

    for (int i = 0; i < tt.getsoluongdichvu(); i++)
    {
        of << tt.getmadichvu()[i] <<';';
    }
    of << "\n";
        }
}
void chinh_sua_thong_tin(thongtin *tt)
{ string mahoadon;
   int k=0;
  cout << "Nhap ma hoa don can chinh sua : ";
  cin >> mahoadon;
  cin.ignore();
  for (int i=0;i<thongtin::getstt();i++)
    {  int a;
        if (tt[i].getmahoadon()==mahoadon)
          {  k=1;
            if (tt[i].getloaihoadon()==1)
             { do{ 
                cout <<"1.Nhap Lai Ho Ten" <<endl;
                cout <<"2.Nhap Lai Ma Khach Hang" <<endl;
                cout <<"3.Nhap Lai Thoi Gian" <<endl;
                cout <<"4.Nhap Lai Thong tin" <<endl;
                cout <<"0.Quay Lai "<<endl;
                cin >> a;
                 switch (a)
                 {
                 case 1:
                    system("cls");
                    tt[i].sethoten();
                    break;
                 case 2: 
                   system("cls");
                    tt[i].setmakhachhang();
                    break;
                 case 3:
                   system("cls");
                    tt[i].setthoigian();
                    break;
                 case 4:
                    system("cls");
                    tt[i].setthongtinmonan();
                    break;
                
                 }
             }while(a);
             }
        if (tt[i].getloaihoadon()==2)
              { do{
                cout <<"1.Nhap Lai Ho Ten" <<endl;
                cout <<"2.Nhap Lai Ma Khach Hang" <<endl;
                cout <<"3.Nhap Lai Ma Hoa Don" <<endl;
                cout <<"4.Nhap Lai Thoi Gian" <<endl;
                cout <<"5.Nhap Lai Thong tin" <<endl;
                cout <<"0.Thoat";
                cin >> a;
                switch (a)
                 {
                 case 1:
                   system("cls");
                    tt[i].sethoten();
                    break;
                 case 2: 
                   system("cls");
                    tt[i].setmakhachhang();
                    break;
                 case 3:
                    system("cls");
                    tt[i].setmahoadon();
                    break;   
                 case 4:
                    system("cls");
                    tt[i].setthoigian();
                    break;
                 case 5:
                   system("cls");
                    tt[i].setthongtindichvu();
                    break;
                 }
  
               }while(a);
         if (k==0) cout <<"----Khong co thong tin hoa don---" << endl;
    
    }

    };
}
}

void Xuatdanhsach(thongtin *tt)
{ 
   for (int i=0;i<thongtin::getstt();i++)
   {cout << "Thong Tin Khach Hang Thu " << i+1 <<endl;
    cout << "Ho Va Ten: " << tt[i].gethoten()<<endl;
    cout << "Ma Khach Hang: "<< tt[i].getmakhachhang()<<endl;
    cout << "Ma Hoa Don: " << tt[i].getmahoadon()<<endl;
    cout << "Thoi Gian: " << tt[i].getthoigian()<<endl;
    cout << "Loai hoa don : ";
    if (tt[i].getloaihoadon()==1)
    {  cout <<"Hoa don Mon AN" << endl;
       cout << "So Luong Mon An " << tt[i].getsoluongmonan()<<endl;
       for (int j=0;j<tt[i].getsoluongmonan();j++)
       {
          cout << "Ma Mon an thu " << j +1 << " : " << tt[i].getmamonan()[j]<<endl;
          cout << "So luong " << tt[i].getsoluong()[j]<<endl;
       }
         cout<<"----------------------------------------"   <<endl;
            
    }
    if (tt[i].getloaihoadon()==2)
    {  cout <<"Hoa don Dich Vu" << endl;
       cout << "So Luong Dich Vu " << tt[i].getsoluongdichvu()<<endl;
       for (int j=0;j<tt[i].getsoluongdichvu();j++)
       {
          cout << "Ma Dich Vu " << j +1 << " : " << tt[i].getmadichvu()[j]<<endl;
       }
         cout<<"----------------------------------------"   <<endl;
    }

   }




}
void xoathongtin(thongtin *tt)
{  int k=0;
    string mahoadon;
   cout << "Nhap Ma Hoa Don Can Xoa : "<<endl;
   cin >> mahoadon;
   for (int i=0;i<thongtin::getstt();i++)
   { if (tt[i].getmahoadon() == mahoadon)
         {   k=1;
             for (i ; i < thongtin::getstt(); i++)
             { tt[i]=tt[i+1];
             }
             thongtin::setstt();
             cout << "--Da XOA Thong TIn--" << endl;
         }
   }
              if (k==0) cout <<"Khong co thong tin"<<endl;

}
int main()
{
    thongtin* tt;
    int i = 0;
    int a;
    char k;
    tt = new thongtin[100];
    ifstream ifs;
    ofstream of;

    ifs.open("khachhang.txt");
    of.open("khachhang2.txt" );

    while (!ifs.eof())
    {
        nhap_thong_tin_tu_file(ifs, tt[i]);
        i++;
    }
   // cout << tt[1].getmahoadon();
    //cout << thongtin::getstt();

 ifs.close();
   do
   { //system("cls");
    cout << "1.Nhap Them Thong Tin Khach Hang " << endl;
    cout << "2.Chinh Sua Thong Tin Khach Hang " << endl ;
    cout << "3.Xoa Thong Tin Khach Hang  " <<endl;
    cout << "4.Xem Danh Sach Khach Hang " << endl;
    cout << "0.Thoat va Luu thong tin" <<endl;
    cin >>a;
    cin.ignore();
    switch (a)
    {
    case 1:   
    system("cls");
    do {
        nhap_them_thong_tin(tt[thongtin::getstt()  ]);
        cout << "Ban Co Muon Nhap Tiep Khong? (Y/N): ";
        cin >> k;
        cin.ignore();
         system("cls");
    } while (k != 'N' && k != 'n');
   
    break;

    //cout << "ho ten la" << tt[0].gethoten();
    case 2 :
     system("cls");
    chinh_sua_thong_tin(tt);
    break;
    case 4 :
     system("cls");
    Xuatdanhsach(tt);
    break;
    case 3 :
    system("cls");
    xoathongtin(tt);
     
    }
    }while (a);
    

    

    for (int j = 0; j < thongtin::getstt(); j++)
    {
        nhap_thong_tin_vao_file(of, tt[j]);
      
    }

    of.close();
    remove("khachhang.txt");
    rename("khachhang2.txt", "khachhang.txt");

    delete[] tt;

    system("pause");
    return 0;
}
