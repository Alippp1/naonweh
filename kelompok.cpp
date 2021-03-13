#include<iostream>
#include<conio.h>
#include<stdio.h>

using namespace std;

struct nilai
{
   char nis [8], nama[60];
   int mtk, bindo, sda, akppl;
   int jmlsiswa;
struct nilai *next;
}*baru, *awal=NULL, *akhir=NULL, *hapus,*bantu; // deklarasi linkedlist

char tes;
int pil;
void pilih();
void databaru();
void after();
void last();
void haafter();
void halast();
void view();


void bersih(){
 system("cls");
}


//untuk input data baru 
void databaru(){
    baru=(nilai*)malloc(sizeof(struct nilai));
 cout << "===============================\n";
 cout << "        Masukan Data \n";
 cout << "===============================\n";
 cout << "Input NIS : ";cin >> baru->nis;
 cout << "Input Nama : ";cin >>baru->nama;
 cout << "Nilai Matematika : ";cin >> baru->mtk;
 cout << "Nilai B.Indonesia : ";cin >> baru->bindo;
 cout << "Nilai SDA : ";cin >>baru->sda;
 cout << "Nilai AKPPL : ";cin >> baru->akppl;

 baru->next=NULL;
}

//insert after
void after(){
 databaru();
 if(awal==NULL){
  awal=baru;
  akhir=baru;
  akhir->next=NULL;
 }
 else{
  baru->next=awal;
  awal=baru;
 }
 cout << endl << endl;
}


void view(){
 if(awal==NULL){
  cout << "Kosong";
 }
 else{
  bantu=awal;
  while(bantu!=NULL){
    cout << "NIM : " << bantu->nis << endl;
    cout << "NAMA : " << bantu->nama << endl;
    cout << "Nilai Matematika : " << bantu->mtk << endl;
    cout << "Nilai B.Indonesia : " << bantu->bindo << endl;
    cout << "Nilai SDA : " << bantu->sda << endl;
    cout << "Nilai AKPPL : " << bantu->akppl << endl;
 
   bantu=bantu->next;
  }
 }
 getch();
}


int main(){
 do{
  bersih();
    cout << "===============================\n";
    cout << "          PILIH MENU           " << endl;
    cout << "===============================\n";
    cout << "| 1. Tambah Data               |" << endl;
    cout << "| 2. Hapus                     |" << endl;
    cout << "| 3. Tampil                    |"<< endl;
    cout << "| 4. Selesai                   |" << endl;
    cout << "________________________________\n" << endl;
    cout << "Pilihan anda : ";
  cin>>pil;
  pilih();
 }while (pil!=6);
 return 0;
}


void pilih(){
    switch(pil){
            case 1:
            bersih();
                cout << "===============================\n";
                cout << "      PILIH MENU INPUTAN         " << endl;
                cout << "===============================\n";
                cout <<" | a. Data baru                 |"<< endl;
                cout <<" | b. Insert After              |"<< endl;
                cout <<" | c. Insert Last               |"<< endl;
                cout <<" _______________________________\n"<< endl;
                cout << "Pilihan anda : ";
                cin>>tes;
                
                switch(tes){
                    case 'a' : 
                        bersih();
                        databaru();
                        system("PAUSE");
                        break;
                    case 'b' :
                        bersih();
                        after();
                        system("PAUSE");
                        break;
                    case 'c':
                        cout<<"masukin";
                        break;
                }
				system("PAUSE");         
                break;
            case 2:
            bersih();
                cout << "===============================\n";
                cout << "          PILIH HAPUS          " << endl;
                cout << "===============================\n";
                cout <<" | a. Delete First              |"<< endl;
                cout <<" | b. Delete Last               |"<< endl;
                cout <<" _______________________________\n"<< endl;
                cout << "Pilihan anda : ";
                cin>>tes;
                
                switch(tes){
                    case 'a' : 
                        bersih();
                        //haafter();
                        system("PAUSE");
                        break;
                    case 'b' :
                        bersih();
                        //halast();
                        system("PAUSE");
                        break;
                }
				system("PAUSE");         
                break;
            case 3:
            view();
            break;
    }
}
