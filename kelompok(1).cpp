#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

//struct
struct node{
    char nim[10], nama[20];
    int mtk, indo, sda, akppl, jumlah, rata;
    
    node *next, *prev;
};
    node *awal = NULL, *akhir = NULL, *bantu, *baru, *hapus;

char tes;
int pil;

//penjabran void yang ada
void pilih();
void datadepan();
void databelakang();
void dataafter();
void hadepan();
void habelakang();
void haal();
void view();
void laporan();


void bersih (){
    system ("cls");
}

bool isEmpty(){
    if(awal == NULL){
        return true; // datanya masih kosong
    }else{
        return false; // datanya udah ada
    }
}

//input depan
void datadepan(){
    baru = new node;
    baru -> next = NULL;
    baru -> prev = NULL;
    cout << "===============================\n";
 	cout << "        Masukan Data \n";
 	cout << "===============================\n";
    cout << "Input Nama : "; cin  >> baru -> nama;
    cout << "Masukkan NIM: "; cin >> baru -> nim;
 	cout << "Nilai Matematika : ";cin >> baru->mtk;
 	cout << "Nilai B.Indonesia : ";cin >> baru->indo;
 	cout << "Nilai SDA : ";cin >>baru->sda;
 	cout << "Nilai AKPPL : ";cin >> baru->akppl;
    baru->jumlah = baru->mtk + baru->indo + baru->sda + baru->akppl;
    baru->rata = baru->jumlah /4;

    if (isEmpty()){
        awal = akhir = baru;

    }else{
        baru -> next = awal; // supaya data berada di posisi awal
        baru -> prev = baru;
        awal = baru; // penjabaran untuk data diinput di awal merupakan data baru
    }
   bersih();
}

//input belakang
void databelakang(){
    baru = new node;
    baru->next = NULL;
    baru->prev = NULL;
    cout << "===============================\n";
 	cout << "        Masukan Data \n";
 	cout << "===============================\n";
    cout << "Input Nama : "; cin  >> baru -> nama;
    cout << "Masukkan NIM: "; cin >> baru -> nim;
 	cout << "Nilai Matematika : ";cin >> baru->mtk;
 	cout << "Nilai B.Indonesia : ";cin >> baru->indo;
 	cout << "Nilai SDA : ";cin >>baru->sda;
 	cout << "Nilai AKPPL : ";cin >> baru->akppl;
    baru->jumlah = baru->mtk + baru->indo + baru->sda + baru->akppl;
    baru->rata = baru->jumlah /4;

    if (isEmpty()){
        awal = akhir = baru;
    }
    else {
        akhir->next = baru; // supaya data berada di posisi akhir
        baru->prev = akhir;
        akhir = baru; // penjabaran untuk data yang diinput diakhir merupakan data baru
    }
    bersih();
}

//input after
void dataafter(){
    node *prev_node;
    prev_node = new node;
    cout << "===============================\n";
 	cout << "        Masukan Data \n";
 	cout << "===============================\n";
    cout << "Input Nama : "; cin  >> baru -> nama;
    cout << "Masukkan NIM: "; cin >> baru -> nim;
 	cout << "Nilai Matematika : ";cin >> baru->mtk;
 	cout << "Nilai B.Indonesia : ";cin >> baru->indo;
 	cout << "Nilai SDA : ";cin >>baru->sda;
 	cout << "Nilai AKPPL : ";cin >> baru->akppl;
    baru->jumlah = baru->mtk + baru->indo + baru->sda + baru->akppl;
    baru->rata = baru->jumlah /4;
    
    if (prev_node = NULL){
        cout <<" NIlai tidak boleh kosong";
        return;
    }
    node baru=(node)malloc(sizeof(struct node));
    baru ->next = prev_node->next;
    prev_node->next = baru;

}

// hapus depan
void hadepan(){
    bersih();
 if(isEmpty()){
  cout<<"kosong";
 }
 else{
  hapus = awal;
  awal=awal->next;
    delete hapus;
 }
 cout << endl << endl;
 view();
}

//hapus belakang
void habelakang(){
    node *hapus;

    if (isEmpty()){
        awal = NULL;
        cout <<"Data kosong";
    }else{
        hapus = awal;
         while(hapus->next->next != NULL){

          if(hapus->next->next !=NULL){//Sebelum Akhir
                hapus = hapus->next;//ini
            }else{
                break;
            }
        }
        hapus->next = NULL;
    }
    view();
}

//hapus all
void haal(){
    node *bantu,*hapus;
    bantu = awal;
    while (bantu!= NULL){
        hapus = bantu;
        bantu = bantu -> next;
        delete hapus;
    }
    awal = NULL;
    view();
    }

//tampilkan data
void view(){
bersih();   
		bantu=awal;
		while(bantu!=NULL){
            cout << "NAMA : " << bantu->nama << endl;
			cout << "NIM : " << bantu->nim << endl;
			cout << "Nilai Matematika : " << bantu->mtk << endl;
			cout << "Nilai B.Indonesia : " << bantu->indo << endl;
			cout << "Nilai SDA : " << bantu->sda << endl;
			cout << "Nilai AKPPL : " << bantu->akppl << endl;
			cout << "Nilai RATA-RATA : " << bantu->rata << endl;

			bantu=bantu->next;
			cout << "===============================" << endl;
			}
		
	getch();
}

//laporan txt
void laporan(){
    bersih();
    char text;
    ofstream filesaya;
    filesaya.open("raport.txt", ios::app);
    cout << "Memasukkan data ke dalam file..." << endl;
    bantu=awal;
		while(bantu!=NULL){
            filesaya << "===============================\n";
	        filesaya << "       REKAPAN RAPORT            " << endl;
	        filesaya << "===============================\n";
            filesaya << "NAMA : " << bantu->nama << endl;
			filesaya << "NIM : " << bantu->nim << endl;
			filesaya << "Nilai Matematika : " << bantu->mtk << endl;
			filesaya << "Nilai B.Indonesia : " << bantu->indo << endl;
			filesaya << "Nilai SDA : " << bantu->sda << endl;
			filesaya << "Nilai AKPPL : " << bantu->akppl << endl;
            filesaya << "Nilai rata-rata : " <<baru->rata<<" "<<endl;
            bantu=bantu->next;
			}
    filesaya << endl;
	filesaya << "=================================\n";

    cout<<"Operasi Membaca File txt"<<endl;
    cout<<"------------------------"<<endl;
    ifstream file;                              //tidak boleh sama dengan ofstream
    file.open("raport.txt");
    if(!file.fail())
    {
        // file ada
        cout<<"Isi dari file ialah : "<<endl;
        // perintah eof / end of file
        while (!file.eof())
        {
            file.get(text); //mengambil data dan disimpan pada variabel text
            cout<<text;  //menampilkan
        }
        file.close();
    }
    else
    {
        cout<<" File tidak ditemukan"<<endl;
    }
	filesaya.close();
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
    cout << "| 4. Laporan                   |" << endl;
	cout << "| 5. Selesai                   |" << endl;
	cout << "____________\n" << endl;
	cout << "Pilihan anda : ";
	cin>>pil;
	pilih();
	} while (pil!=6);
return 0;
}

void pilih(){
    switch(pil){
            case 1:
            bersih();
                cout << "===============================\n";
                cout << "|      PILIH MENU INPUTAN     |" << endl;
                cout << "===============================\n";
                cout <<" | a. Input Depan                |"<< endl;
                cout <<" | b. Insert Last                |"<< endl;
                cout <<" | c. Insert After               |"<< endl;
                cout <<" ___________\n"<< endl;
                cout << "Pilihan anda : ";
                cin>>tes;
                
                switch(tes){
                    case 'a' : 
                        bersih();
                        datadepan();
                        system("PAUSE");
                        break;
                    case 'b' :
                        bersih();
                        databelakang();
                        system("PAUSE");
                        break;
                    case 'c':
                        bersih();
                        dataafter();
                        system("PAUSE");
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
                cout <<" | c. Delete All               |"<< endl;
                cout <<" ___________\n"<< endl;
                cout << "Pilihan anda : ";
                cin>>tes;
                
                switch(tes){
                    case 'a' : 
                        bersih();
                        hadepan();
                        system("PAUSE");
                        break;
                    case 'b' :
                        bersih();
                        habelakang();
                        system("PAUSE");
                        break;
                    case 'c' :
                        bersih();
                        haal();
                        system("PAUSE");
                        break;
                }
				system("PAUSE");         
                break;
            case 3:
            if (isEmpty()){
                    cout << "Data masih kosong !\n";
            }
            else {
                 view();
            }
            break;
            case 4:
            bersih();
            laporan();
            system("PAUSE");
            break;
    }
}
