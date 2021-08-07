#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string>
#include <cmath> 
#include <limits>
#include <iomanip>

using namespace std;

//struct
struct node{ 
    string nim, nama, nama_tree;
    int mtk, indo, sda, akppl, jumlah, rata;
    int data_tree;
    node *next, *prev;
    node *left, *right;
};
    node *awal = NULL, *akhir = NULL, *bantu, *baru, *hapus;
    node *root, *pohon; //root untuk awal data

char tes;
int pil;

//penjabaran void yang ada
void pilih();
void datadepan();
void databelakang();
void dataafter();
void hadepan();
void habelakang();
void haal();
void view();

//tambahan setelah uts
void inputan();
void insertTree();
void ambilData();
void inOrder();
void kitaOrder();
void choosedel(string search);
void laporan();
void findingAllData();

void bersih (){
    system ("cls"); // windows
    //system("clear"); // linux/mac
}

bool isEmpty(){
    if(awal == NULL){
        return true; // datanya masih kosong
    } else {
       return false; // datanya udah ada
    }
}

void definisi_awal_tree(){
	pohon = NULL;
}

void inputan(node *baru){

    cout << "===============================\n";
 	cout << "        Masukan Data           \n";
 	cout << "===============================\n";
    cout << "Input nama : "; getline(cin, baru-> nama);
    cout << "Masukkan NIM: "; cin >> baru -> nim;
 	cout << "Nilai Matematika : ";cin >> baru ->mtk;
 	cout << "Nilai B.Indonesia : ";cin >> baru ->indo;
 	cout << "Nilai SDA : ";cin >> baru ->sda;
 	cout << "Nilai AKPPL : ";cin >> baru ->akppl;
    
    // hitung rerata data
    baru -> jumlah = baru -> mtk + baru -> indo + baru -> sda + baru -> akppl;
    baru -> rata = baru -> jumlah / 4;
}

void insertTree(node** root, int databaru, string namaInsert){ // bintang 2 biar datanya masuk ke address line di line 95
    node *new_node;
	
    //jika data kosong buat root
    if((*root) == NULL )
    {
        new_node =  new node; // untuk buat data dinamis
        new_node -> data_tree = databaru;
        new_node -> nama_tree = namaInsert;
        new_node -> left = new_node -> right = NULL; // karena data masih 1 berarti kanan = kiri (belum bisa dibedakan)
    
        (*root) = new_node;
        (*root) -> data_tree = databaru;
        (*root) -> nama_tree = namaInsert;
        (*root) -> left = (*root) -> right = NULL;

        // cout<< new_node -> data_tree <<" Data Sudah ditambah"<<endl; // cek data
    }
    // untuk kondisi apakah nilai selanjutnya lebih besar / kecil
    // jika besar di sebelah kanan, jika kecil kiri
    if((databaru < (*root)-> data_tree))
    {
        insertTree(&(*root)-> left, databaru, namaInsert); // address line (&(*root))
        //cout<<databaru<<" Data sudah ditambah di Kiri"<<endl;
    }
    if((databaru > (*root)-> data_tree))
    {
        insertTree(&(*root)-> right, databaru, namaInsert);
    //cout<<databaru<<" Data sudah ditambah di Kanan"<<endl;
    }
}

void ambilData(){
	bantu=awal;
	while(bantu!=NULL){
//		cout << bantu->rata " ";
        int nilai;
        string name;
		nilai = bantu -> rata;
        name = bantu -> nama;
		insertTree(&pohon, nilai, name);
		bantu = bantu -> next;
	}
}

//void preOrder(node *root){
//	if(root != NULL){
//		cout << root->nama << "	=	"<< root->data_tree <<" ";
//		preOrder(root->left); // Untuk mengunjungi anak root KIRI
//		preOrder(root->right); // Untuk mengunjungi anak root KANAN
//	}
//}


// Terkecil -> Terbesar
void inOrder(node *root){
	if(root != NULL){
		inOrder(root->left); // Untuk mengunjungi anak root KIRI
		cout << "| Nama : " << setiosflags(ios::left)<<""<<setw(10)<< root->nama_tree << "| Nilai : " << setiosflags(ios::left) << "" << setw(10) << root->data_tree << endl;
		inOrder(root->right); // Untuk mengunjungi anak root KANAN
	}
}


// ngurutin data dari yang terbesar ke terkecil
void kitaOrder(node *root){
    if(root != NULL){
		kitaOrder(root->right); // Untuk mengunjungi anak root KANAN
		cout << "| Nama : " << setiosflags(ios::left)<<""<<setw(10)<< root->nama_tree << "| Nilai : " << setiosflags(ios::left)<<""<<setw(10) << root->data_tree << endl;
		kitaOrder(root->left); // Untuk mengunjungi anak root KIRI
	}
}

//void postOrder(node *root){
//	if(root != NULL){
//		preOrder(root->left); // Untuk mengunjungi anak root KIRI
//		preOrder(root->right); // Untuk mengunjungi anak root KANAN
//		cout << root->nama << "	=	"<< root->data_tree <<" ";
//	}
//}


//input depan
void datadepan(){

    baru = new node;
    baru -> next = NULL;
    baru -> prev = NULL;

    inputan(baru);
    if (isEmpty()){
        awal = akhir = baru;
    } else {
        baru -> next = awal; // supaya data berada di posisi awal
        awal -> prev = baru;
        baru -> prev = NULL;
        awal = baru; // penjabaran untuk data diinput di awal merupakan data baru
    }
   bersih();
}

//input belakang
void databelakang(){
    
    baru = new node;
    baru->next = NULL;
    baru->prev = NULL;
  
    inputan(baru);

    if (isEmpty()){
        awal = akhir = baru;
    }
    else {
        baru -> prev = akhir;
        akhir -> next = baru; // supaya data berada di posisi akhir
        akhir = baru; // penjabaran untuk data yang diinput diakhir merupakan data baru
    }
    bersih();
}

//input after
void dataafter(string search){
    if(isEmpty()){
        cout << "Data masih kosong" << endl;
    } else {
        node *baru;
        baru = new node;
        baru -> next = NULL;
        baru -> prev = NULL;

        node *nodeData;
        nodeData = new node;
        nodeData = awal;
        while(nodeData != NULL){
        //loopingCheckpoint++;
            cout << "Mencari data..." << endl;
            if ( (search == nodeData -> nama) || (search == nodeData -> nim) ){
                cout << "===============================" << endl;
                cout << "         Data ditemukan        " << endl;
                cout << "===============================" << endl;
                cout << "NAMA : " << nodeData->nama << endl;
                cout << "NIM : " << nodeData->nim << endl;
                cout << "Nilai Matematika : " << nodeData->mtk << endl;
                cout << "Nilai B.Indonesia : " << nodeData->indo << endl;
                cout << "Nilai SDA : " << nodeData->sda << endl;
                cout << "Nilai AKPPL : " << nodeData->akppl << endl;
                cout << "Nilai RATA-RATA : " << nodeData->rata << endl;
                break;
            } else {
                nodeData = nodeData -> next;
            }
        }
        if(nodeData -> next == NULL){
            databelakang();
        } else {
            inputan(baru);
            nodeData -> next -> prev = baru;
            baru -> next = nodeData -> next;
            baru -> prev = nodeData;
            nodeData -> next = baru;
        }
    }
    // panggilInsertTree();
    bersih();
}

// hapus depan
void hadepan(){
    bersih();
    if(isEmpty()){
        cout<<"kosong" << endl;
    } else {
        hapus = awal;
        awal=awal->next;
        awal -> prev = NULL;
        delete hapus;
    }
    cout << endl << endl;
}

//hapus belakang
void habelakang(){
    if (isEmpty()){
        cout <<"Data masih kosong" << endl;
    } else {
        while(awal -> next -> next != NULL) {// batasan untuk nilai null pada next dalam next dari hapus buat nentuin data terakhir
            awal = awal->next; // ini 
        }
        delete awal -> next;
        awal -> next = NULL;
    }
}

//hapus all
void haal(){
    awal = NULL; // dijadiin null == ngosongin semua data yang ada dalem node awal
}

//Choose delete
void choosedel(string search){

    if(isEmpty()){
        cout << "Data masih kosong" << endl;
    } else {
        node *nodeData;
        nodeData = new node;
        nodeData = awal;
        while(nodeData != NULL){
        //loopingCheckpoint++;
            cout << "Mencari data..." << endl;

            if ( (search == nodeData -> nama) || (search == nodeData -> nim) ){
                {   
                    cout << "===============================" << endl;
                    cout << "         Data ditemukan        " << endl;
                    cout << "===============================" << endl;
                    cout << "NAMA : " << nodeData->nama << endl;
                    cout << "NIM : " << nodeData->nim << endl;
                    cout << "Nilai Matematika : " << nodeData->mtk << endl;
                    cout << "Nilai B.Indonesia : " << nodeData->indo << endl;
                    cout << "Nilai SDA : " << nodeData->sda << endl;
                    cout << "Nilai AKPPL : " << nodeData->akppl << endl;
                    cout << "Nilai RATA-RATA : " << nodeData->rata << endl;
                    // data sudah ditemukan

                    // buat mengantisipasi ngehapus data yang NULL, kalo engga bakalan segmentation fault
                    if(nodeData -> prev == NULL && nodeData -> next ==  NULL){
                        nodeData = NULL;
                        awal = NULL;
                        break;
                    } else if(nodeData -> prev != NULL && nodeData -> next ==  NULL){
                        nodeData -> prev -> next = NULL;
                        break;
                    } else if(nodeData -> prev == NULL && nodeData -> next !=  NULL){
                        nodeData = nodeData -> next;
                        awal = awal -> next;
                        nodeData -> prev = NULL;
                        break;
                    } else {
                        nodeData -> prev -> next = nodeData -> next;
                        nodeData -> next -> prev = nodeData -> prev;
                        break;
                    }
                }
            } else {
                nodeData = nodeData -> next;
            }
        }
    }
}

//tampilkan data
void view(){
		bantu=awal;
        bool loop = true;
        char pilih;
		while(loop != false){
            bersih(); 
            cout << "NAMA : " << bantu->nama << endl;
			cout << "NIM : " << bantu->nim << endl;
			cout << "Nilai Matematika : " << bantu->mtk << endl;
			cout << "Nilai B.Indonesia : " << bantu->indo << endl;
			cout << "Nilai SDA : " << bantu->sda << endl;
			cout << "Nilai AKPPL : " << bantu->akppl << endl;
			cout << "Nilai RATA-RATA : " << bantu->rata << endl;
            ulangi:
            cout << "<n = next> <p = previous> <d = done view>\nPilihan : "; cin >> pilih;
            if(pilih == 'n'){
            { if(bantu -> next == NULL){
                    cout << "Data selanjutnya masih kosong" << endl;
                } else {
                    bantu = bantu -> next;
                }   }
            } else if (pilih == 'p'){
            {   if(bantu -> prev == NULL){
                    cout << "Data sebelumnya masih kosong" << endl;
                } else {
                    bantu = bantu -> prev;
                }   }
            } else if (pilih == 'd'){
                loop = false;
            } else {
                cout << "Pilihan salah, silahkan coba kembali." << endl;
                goto ulangi;
            }
		}
		
	getchar();
}


//carii data
void findingAllData(node *nodeData, string kataKunci){
    if(isEmpty()){
        cout << "Data masih kosong" << endl;
    } else {
            while(nodeData != NULL){
            cout << "Mencari data..." << endl;
            if ( (kataKunci == nodeData -> nama) || (kataKunci == nodeData -> nim) ){
                cout << "Data ditemukan!" << endl;
                cout << "===============================" << endl;
                cout << "NAMA : " << nodeData -> nama << endl;
                cout << "NIM : " << nodeData -> nim << endl;
                cout << "Nilai Matematika : " << nodeData -> mtk << endl;
                cout << "Nilai B.Indonesia : " << nodeData -> indo << endl;
                cout << "Nilai SDA : " << nodeData -> sda << endl;
                cout << "Nilai AKPPL : " << nodeData -> akppl << endl;
                cout << "Nilai RATA-RATA : " << nodeData -> rata << endl;
                nodeData = nodeData -> next; // buat nyari kalo masih ada data yang sama di depan
            } else {
                nodeData = nodeData -> next;
            }
        }
    }
    
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

//Function cek akun
int CekAkun(string username, string pass, string level){
	//Pengecekan username dan pass RT-RW
	if((username == "tata" && pass == "satu" && level == "tatau") || (username == "walikelas" && pass == "walikelas" && level == "walik")) 
		return 1; //Mengembalikan Nilai 0 
	else
		return 99; //Mengembalikan nilai 99 jika username dan pass salah
}

//Function Login
int Login(){
    bersih();
    ulang :
    int temp;
	string username, Pass, level; //Variabel lokal untuk menyimpan inputan username dan password

	cout << "LOGIN\n";
	cout << "Username : "; cin >> username;
	cout << "Password : "; cin >> Pass;
    cout << "Level : "; cin >> level;
	temp = CekAkun(username, Pass, level); //Menggunakan function CekAkun untuk melihat nilai return sebagai kondisi

	//Cek untuk kondisi salah password/username
	if(temp == 99){
		cout << "Akun atau Password salah!\n";
		system("PAUSE");
        goto ulang;
		return temp; //Mengembalikan nilai temp sebagai kondisi
	}else{
		return temp; //Mengembalikan nilai temp sebagai kondisi
	}
}

void updateData(string search){
    
    if(isEmpty()){
        cout << "Data masih kosong" << endl;
    } else {
        node *nodeData;
        nodeData = new node;
        nodeData = awal;
        while(nodeData != NULL){
        //loopingCheckpoint++;
            cout << "Mencari data..." << endl;
            if ( (search == nodeData -> nama) || (search == nodeData -> nim) ){
                cout << "+-----------------------------+" << endl;
                cout << "|        Data ditemukan       |" << endl;
                cout << "+-----------------------------+" << endl;
                cout << " NAMA : " << nodeData->nama << endl;
                cout << " NIM : " << nodeData->nim << endl;
                cout << " Nilai Matematika : " << nodeData->mtk << endl;
                cout << " Nilai B.Indonesia : " << nodeData->indo << endl;
                cout << " Nilai SDA : " << nodeData->sda << endl;
                cout << " Nilai AKPPL : " << nodeData->akppl << endl;
                cout << " Nilai RATA-RATA : " << nodeData->rata << endl;
                break;
            } else {
                nodeData = nodeData -> next;
            }
        }
        inputan(nodeData);
    }
}

int main(){ 
    int temp;
    temp = Login();
    if(temp == 1){

    
	do{
	// bersih();
	cout << "+-----------------------------+\n";
	cout << "|          PILIH MENU         |" << endl;
	cout << "+-----------------------------+\n";
	cout << "| 1. Tambah Data              |" << endl;
	cout << "| 2. Hapus                    |" << endl;
	cout << "| 3. Tampil                   |"<< endl;
    cout << "| 4. Laporan                  |" << endl;
    cout << "| 5. Cari Data                |" << endl;
	cout << "| 6. Update                   |" << endl;
    cout << "| 7. Urutan Rata-rata         |" << endl;
    cout << "| 0. Selesai                  |" << endl;
	cout << "+-----------------------------+\n" << endl;
	cout << "Pilihan anda : ";
    cin>>pil;
    pilih();
    } 
    while (pil != 0);
    return 0;
    }
}

void pilih(){
    int banyakData;
    string kataKunci;
    switch(pil){
            case 1:
            bersih();
                cout << "Masukkan banyak data : "; cin >> banyakData;
                for(int i = 1; i <= banyakData; i++){
                cout << "+-----------------------------+\n";
                cout << "|      PILIH MENU INPUTAN     |" << endl;
                cout << "+-----------------------------+\n";
                cout << "| a. Input Depan              |"<< endl;
                cout << "| b. Insert After             |"<< endl;
                cout << "| c. Insert Last              |"<< endl;
                cout << "+-----------------------------+\n"<< endl;
                cout << "Pilihan anda : ";
                cin>>tes;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                switch(tes){
                    case 'a' : 
                        bersih();
                        datadepan();
                        system("PAUSE");
                        break;

                    case 'b':
                        bersih();
                        cout << "Masukkan kata kunci : "; cin >> kataKunci;
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        dataafter(kataKunci);
                        system("PAUSE");
                        break;

                    case 'c' :
                        bersih();
                        databelakang();
                        system("PAUSE");
                        break;
                    }
                }
				system("PAUSE");         
                break;
            
            case 2:
            bersih();
                cout << "+-------------------------------+\n";
                cout << "|          PILIH HAPUS          |" << endl;
                cout << "+-------------------------------+\n";
                cout << "| a. Delete First               |"<< endl;
                cout << "| b. Choose Delete              |"<< endl;
                cout << "| c. Delete Last                |"<< endl;
                cout << "| d. Delete All                 |"<< endl;
                cout << "+-------------------------------+\n"<< endl;
                cout << "Pilihan anda : ";
                cin>>tes;
                switch(tes){
                    case 'a' : 
                        bersih();
                        hadepan();
                        system("PAUSE");
                        break;
                   
                    case 'c' :
                        bersih();
                        habelakang();
                        system("PAUSE");
                        break;
                    
                    case 'd' :
                        bersih();
                        haal();
                        system("PAUSE");
                        break;
                   
                   case 'b' :
                        bersih();
                        cout << "Masukkan kata kunci : "; cin >> kataKunci;
                        choosedel(kataKunci);
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
	            system("PAUSE"); 
	            break;

            case 4:
	            bersih();
	            laporan();
	            system("PAUSE");
	            break;

            case 5: // find all data
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
	            cout << "Masukkan kata kunci : "; getline(cin, kataKunci);
	            findingAllData(awal, kataKunci);
	            system("PAUSE");
	            break;

            case 6: // update data
	            cout << "Masukkan kata kunci :"; cin >> kataKunci;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                updateData(kataKunci);
                system("PAUSE");	
	            break;

			case 7: //Urut Rank
                ulang :
				bersih();
				ambilData();
                cout << "+-------------------------------+\n";
                cout << "|          PILIH URUTAN         |" << endl;
                cout << "+-------------------------------+\n";
                cout << "| a. Dari yang terbesar         |"<< endl;
                cout << "| b. Dari yang terkecil         |"<< endl;
                cout << "+-------------------------------+\n"<< endl;
                cout << "Pilihan anda : ";
                cin>>tes;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                if(tes == 'a'){
                    kitaOrder(pohon); cout << "\n";
                } else if (tes == 'b'){
				    inOrder(pohon); cout << "\n";
                } else {
                    cout << "Inputan salah, coba kembali..." << endl;
                    system("pause");
                    goto ulang;
                }
//				preOrder(pohon); cout << "\n";
//				postOrder(pohon); cout << "\n";
				system("PAUSE");
				break;
            case 0 :
                cout << "Keluar aplikasi..." << endl;
                break;
            default:
                cout << "Menu tidak ada...\nsilahkan coba kembali" << endl;
    }
    
}
