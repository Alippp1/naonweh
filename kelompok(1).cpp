#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <fstream>
#include <string>


using namespace std;

struct nilai
{
	string nis, nama;
	int mtk, bindo, sda, akppl;
	int jmlsiswa;
	nilai *next;
} *baru, *awal=NULL, *akhir=NULL, *hapus, *bantu; // deklarasi linkedlist

char tes;
int pil;

void pilih();
void databaru();
void after();
void last();
void haafter();
void halast();
void view();
bool kosong();
void bersih();

//untuk input data baru 

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
	} while (pil!=6);
return 0;
}


void bersih(){
	system("cls");
}

void databaru(){ // mungkin add last ya
	int inputanInteger;
	string inputanString;
 	baru=(nilai*)malloc(sizeof(struct nilai));
 	nilai *current;
 	baru = new nilai;
 	baru -> next = NULL;
 	cout << "===============================\n";
 	cout << "        Masukan Data \n";
 	cout << "===============================\n";
 	// cout << "Input NIS : "; cin >> baru->nis;
 	cout << "Input Nama : ";
 	cin >> inputanString;getline(cin, inputanString);// baru->nama;
 	baru -> nama = inputanString;
 	cout << "Masukkan NIS : "; cin >> baru -> nis;
 	cout << "Nilai Matematika : ";cin >> baru->mtk;
 	cout << "Nilai B.Indonesia : ";cin >> baru->bindo;
 	cout << "Nilai SDA : ";cin >>baru->sda;
 	cout << "Nilai AKPPL : ";cin >> baru->akppl;

	if(kosong()){
		awal = baru;
		baru -> next = NULL;
	} else {
		baru -> next = awal;
		awal = baru;
	}
}

//insert after
void after(){
	databaru();
	if(awal==NULL){
		awal=baru;
		akhir=baru;
		akhir->next=NULL;
	} else {
		baru->next=awal;
		awal=baru;
	}
	cout << endl << endl;
}

// liat data
void view(){
	if(awal==NULL){
		cout << "Kosong";
	} else {
		bantu=awal;
		while(bantu!=NULL){
			cout << "NIM : " << bantu->nis << endl;
			cout << "NAMA : " << bantu->nama << endl;
			cout << "Nilai Matematika : " << bantu->mtk << endl;
			cout << "Nilai B.Indonesia : " << bantu->bindo << endl;
			cout << "Nilai SDA : " << bantu->sda << endl;
			cout << "Nilai AKPPL : " << bantu->akppl << endl;
			 
			bantu=bantu->next;
			cout << "===============================" << endl;
			}
		}
	getch();

}

void pilih(){
    switch(pil){
            case 1:
            bersih();
                cout << "===============================\n";
                cout << "|      PILIH MENU INPUTAN     |" << endl;
                cout << "===============================\n";
                cout <<" | a. Data baru                |"<< endl;
                cout <<" | b. Insert After             |"<< endl;
                cout <<" | c. Insert Last              |"<< endl;
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

bool kosong(){
	if(awal == NULL){
		return true;
	} else {
		return false;
	}
}
