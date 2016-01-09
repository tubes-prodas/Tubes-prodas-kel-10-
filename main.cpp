#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <string.h>
//add by taufiq
#include <windows.h>
using namespace std;
HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;

void gotoXY(int x, int y);
	
typedef struct {
	char username[11];
	char password[9];
}input;

typedef struct {
	float matematika;
	float ipa;
	float b_indonesia;
	float b_inggris;
} pelajaran;

typedef struct {
	int no_pendaftaran;
	char nama[51];
	char jenis_kelamin;
	pelajaran nilai;
	int jurusan1;
	int jurusan2;
	int status;
} pendaftaran;
//parameter global
int inentry = 0;

void gotoxy (int x, int y){
	
    CursorPosition.X = x; // lokasi x = kolom
	CursorPosition.Y = y; // lokasi y = baris
	SetConsoleCursorPosition(console,CursorPosition); // set lokasi / posisi dimana di print
}
void standar(pelajaran jurusan[6]){
	jurusan[0].matematika = 75;jurusan[0].b_indonesia = 75; jurusan[0].b_inggris = 75;jurusan[0].ipa = 75; // untuk jurusan tkj
	jurusan[1].matematika = 75;jurusan[1].b_indonesia = 75; jurusan[1].b_inggris = 75;jurusan[1].ipa = 75; // untuk jurusan rpl
	jurusan[2].matematika = 75;jurusan[2].b_indonesia = 75; jurusan[2].b_inggris = 75;jurusan[2].ipa = 75; // untuk jurusan mm
	jurusan[3].matematika = 75;jurusan[3].b_indonesia = 75; jurusan[3].b_inggris = 75;jurusan[3].ipa = 75; // untuk jurusan av
	jurusan[4].matematika = 75;jurusan[4].b_indonesia = 75; jurusan[4].b_inggris = 75;jurusan[4].ipa = 75; // untuk jurusan toi
	jurusan[5].matematika = 75;jurusan[5].b_indonesia = 75; jurusan[5].b_inggris = 75;jurusan[5].ipa = 75; // untuk jurusan titl
}
void rata_rata(pelajaran jurusan[6],float *tkj, float *rpl, float *titl, float *toi, float *av, float *mm){
	*tkj = (jurusan[0].matematika + jurusan[0].b_inggris + jurusan[0].ipa + jurusan[0].b_indonesia);
 	*rpl = (jurusan[1].matematika + jurusan[1].b_inggris + jurusan[1].ipa + jurusan[1].b_indonesia);
 	*mm = (jurusan[2].matematika + jurusan[2].b_inggris + jurusan[2].ipa + jurusan[2].b_indonesia);
 	*av = (jurusan[3].matematika + jurusan[3].b_inggris + jurusan[3].ipa + jurusan[3].b_indonesia);
 	*toi = (jurusan[4].matematika + jurusan[4].b_inggris + jurusan[4].ipa + jurusan[4].b_indonesia);
 	*titl = (jurusan[5].matematika + jurusan[5].b_inggris + jurusan[5].ipa + jurusan[5].b_indonesia);

}

void passing(pelajaran jurusan[6],float tkj, float rpl, float titl, float toi, float av, float mm){
	rata_rata(jurusan,&tkj, &rpl, &titl, &toi, &av, &mm);
 	cout << "---------------------------------------------------------------------\n";
	cout << "Passinggrade Saat Ini :\n";
	cout << "---------------------------------------------------------------------\n";
	cout << "1. Teknik Komputer dan Jaringan\t\t:"<<tkj<<"\n" ;
	cout << "2. Teknik Rekayasa Perangkat Lunak\t:"<<rpl<<"\n" ;
	cout << "3. Teknik Instalasi Tenaga Listrik\t:"<<titl<<"\n" ;
	cout << "4. Teknik Otomasi Industri\t\t:"<<toi<<"\n" ;
	cout << "5. Teknik Audio Video\t\t\t:"<<av<<"\n" ;
	cout << "6. Multi Media\t\t\t\t:"<<mm<<"\n" ;
	cout << "---------------------------------------------------------------------\n";

}
int counter (int n){
	return  n + 1;
}
int menu(pelajaran jurusan[6],float tkj, float rpl, float titl, float toi, float av, float mm){
	int hasil;
	cout << "======== Aplikasi Penerimaan Siswa Baru SMK Negeri 4 Bandung ========\n";
	passing(jurusan,tkj, rpl, titl, toi, av, mm);
	cout << "Menu :\n";
	cout << "---------------------------------------------------------------------\n";
	cout << "1. Login\n" ;
	cout << "2. Search\n" ;
	cout << "3. Persyaratan Nilai\n" ;
	cout << "4. Keluar\n" ;
	cout << "---------------------------------------------------------------------\n";
	cout << "Masukan no menu pilihan anda :" ;
	cin  >> hasil;
	return hasil;

}

void search(pendaftaran siswa[200],int insiswa){
	int  index;
	system("cls");
	cout << "---------------------------------------------------------------------\n";
	cout << "Search System :\n";
	cout << "---------------------------------------------------------------------\n";
	cout << "Masukan No Pendaftaran\t:" ;
	cin  >> index;
	for(int a = 0; a <= insiswa ; a++){
		if(siswa[a].no_pendaftaran == index){
		cout << "---------------------------------------------------------------------\n";
		cout << "No. Pendaftaran 	: "<<siswa[a].no_pendaftaran<<"\n";
		cout << "Nama Lengkap 		: "<<siswa[a].nama<<"\n";
		cout << "Jenis Kelamin		: "<<siswa[a].jenis_kelamin<<"\n";
		if(siswa[a].status > 0){
			cout << "status			: Diterima Di Jurusan "<<siswa[a].status<<"\n";
		}else{
			cout << "status			: Tidak Diterima \n";	
		}
		cout << "---------------------------------------------------------------------\n";
		cout << "Nilai Matematika	: "<<siswa[a].nilai.matematika<<"\n";
		cout << "Nilai Bahasa Indo	: "<<siswa[a].nilai.b_inggris<<"\n";
		cout << "Nilai Bahasa Ingg	: "<<siswa[a].nilai.b_indonesia<<"\n";
		cout << "Nilai IPA		: "<<siswa[a].nilai.ipa<<"\n";
		cout << "---------------------------------------------------------------------\n";
		break;	
	 	}
	}
	cout << "|-----------Daftar Jurusan----------|\n";
	cout << "|1.| Teknik Komputer dan Jaringan   |\n";
	cout << "|2.| Teknik Rekayasa Perangkat Lunak|\n";
	cout << "|3.| Teknik Instalasi Tenaga Listrik|\n";
	cout << "|4.| Teknik Otomasi Industri        |\n";
	cout << "|5.| Teknik Audio Video             |\n";	
	cout << "|6.| Multi Media                    |\n";
	cout << "-------------------------------------------------------------------------\n";
	system("pause");

}
void persyaratan(pelajaran jurusan[6],float tkj, float rpl, float titl, float toi, float av, float mm){
  	system("cls");
  	rata_rata(jurusan,&tkj, &rpl, &titl, &toi, &av, &mm);
 	cout << "--------------------------------------------------------------------------------\n";
	cout << "|NO| JURUSAN                        | MTK | B. ING | IPA | B. INDO | PASSING GRADE |\n";
	cout << "--------------------------------------------------------------------------------\n";
	cout << "|1.| Teknik Komputer dan Jaringan   |  "<<jurusan[0].matematika <<" |   "<<jurusan[0].b_inggris<<"   |  "<<jurusan[0].ipa<<" |    "<<jurusan[0].b_indonesia<<"   |  "<<tkj<<"       |\n";
	cout << "|2.| Teknik Rekayasa Perangkat Lunak|  "<<jurusan[1].matematika <<" |   "<<jurusan[1].b_inggris<<"   |  "<<jurusan[1].ipa<<" |    "<<jurusan[1].b_indonesia<<"   |  "<<rpl<<"       |\n";
	cout << "|3.| Multi Media                    |  "<<jurusan[2].matematika <<" |   "<<jurusan[2].b_inggris<<"   |  "<<jurusan[2].ipa<<" |    "<<jurusan[2].b_indonesia<<"   |  "<<mm<<"       |\n";
	cout << "|4.| Teknik Audio Video             |  "<<jurusan[3].matematika <<" |   "<<jurusan[3].b_inggris<<"   |  "<<jurusan[3].ipa<<" |    "<<jurusan[3].b_indonesia<<"   |  "<<av<<"       |\n";
	cout << "|5.| Teknik Otomasi Industri        |  "<<jurusan[4].matematika <<" |   "<<jurusan[4].b_inggris<<"   |  "<<jurusan[4].ipa<<" |    "<<jurusan[4].b_indonesia<<"   |  "<<toi<<"       |\n";
	cout << "|6.| Teknik Instalasi Tenaga Listrik|  "<<jurusan[5].matematika <<" |   "<<jurusan[5].b_inggris<<"   |  "<<jurusan[5].ipa<<" |    "<<jurusan[5].b_indonesia<<"   |  "<<titl<<"       |\n";
	cout << "--------------------------------------------------------------------------------\n";

}
void inputentry(input entry[200]){
	cout << "Masukan Username :";
	cin  >> entry[inentry].username;
	cout << "Masukan Password :";
	cin  >> entry[inentry].password;
	inentry++;

}
void ubahnilai(pelajaran jurusan[6]){
 int c;
 	
 	cout << "-------------------------------------------------------------------------\n";
 	cout << "|-----------Daftar Jurusan----------|\n";
	cout << "|1.| Teknik Komputer dan Jaringan   |\n";
	cout << "|2.| Teknik Rekayasa Perangkat Lunak|\n";
	cout << "|3.| Teknik Instalasi Tenaga Listrik|\n";
	cout << "|4.| Teknik Otomasi Industri        |\n";
	cout << "|5.| Teknik Audio Video             |\n";
	cout << "|6.| Multi Media                    |\n";
	cout << "-------------------------------------------------------------------------\n";
	cout << "Masukan Pilihan Jurusan	: ";
	cin  >> c;

	cout << "Masukan Nilai Matematika	: ";
	cin  >> jurusan[c].matematika;
	cout << "Masukan Nilai Bahasa Indo	: ";
	cin  >> jurusan[c].b_indonesia ;
	cout << "Masukan Nilai Bahasa Ingg	: ";
	cin  >> jurusan[c].b_inggris;
	cout << "Masukan Nilai IPA			: ";
	cin  >> jurusan[c].ipa;

}
void upgrade(pelajaran jurusan[6],int stat,pendaftaran siswa[200],int insiswa){
	int parx = 1,l = 0;
	int c = stat;
	c--; 	
 	float ratamat = jurusan[c].matematika, rataing = jurusan[c].b_inggris, rataind = jurusan[c].b_indonesia,rataipa = jurusan[c].ipa;
 	do{
		if(siswa[l].status == stat){
			ratamat += siswa[l].nilai.matematika;
			rataipa += siswa[l].nilai.ipa;
			rataing += siswa[l].nilai.b_inggris;
			rataind += siswa[l].nilai.b_indonesia;
			parx++;
			cout << ratamat <<"|"<< rataipa <<"|"<< rataing <<"|"<< rataind <<"|"<< parx <<"\n";
		}
		l++;
	}while(l <= insiswa);
	
	if(parx == 0){
		parx = 1;
	}
	ratamat /= parx;
	rataipa /= parx;
	rataing /= parx;
	rataind /= parx;

	jurusan[c].matematika = ratamat;
	jurusan[c].ipa = rataipa;
	jurusan[c].b_inggris = rataing;
	jurusan[c].b_indonesia = rataind;

}
int seleksi(pelajaran jurusan[6],int jur,pendaftaran siswa[200],float tkj, float rpl, float titl, float toi, float av, float mm, int insiswa){
	rata_rata(jurusan,&tkj, &rpl, &titl, &toi, &av, &mm);
 	float rata = (siswa[insiswa].nilai.matematika + siswa[insiswa].nilai.ipa + siswa[insiswa].nilai.b_inggris + siswa[insiswa].nilai.b_indonesia);
 	jur--;
	if(jur == 0){
		if(rata >= tkj){
			if((jurusan[0].matematika<=siswa[insiswa].nilai.matematika)&&(jurusan[0].ipa<=siswa[insiswa].nilai.ipa)&&(jurusan[0].b_inggris<=siswa[insiswa].nilai.b_inggris)&&(jurusan[0].b_indonesia<=siswa[insiswa].nilai.b_indonesia)){
				return 1;
			}else{
				return -1;
			}
		}else{
			return -1;
		}
	}else if(jur == 1){
		if(rata >= rpl){
			if((jurusan[1].matematika<=siswa[insiswa].nilai.matematika)&&(jurusan[1].ipa<=siswa[insiswa].nilai.ipa)&&(jurusan[1].b_inggris<=siswa[insiswa].nilai.b_inggris)&&(jurusan[1].b_indonesia<=siswa[insiswa].nilai.b_indonesia)){
				return 2;
			}else{
				return -1;
			}
		}else{
			return -1;
		}
	}else if(jur == 2){
		if(rata >= mm){
			if((jurusan[2].matematika<=siswa[insiswa].nilai.matematika)&&(jurusan[2].ipa<=siswa[insiswa].nilai.ipa)&&(jurusan[2].b_inggris<=siswa[insiswa].nilai.b_inggris)&&(jurusan[2].b_indonesia<=siswa[insiswa].nilai.b_indonesia)){
				return 3;
			}else{
				return -1;
			}
		}else{
			return -1;
		}
	}else if(jur == 3){
		if(rata >= av){
			if((jurusan[3].matematika<=siswa[insiswa].nilai.matematika)&&(jurusan[3].ipa<=siswa[insiswa].nilai.ipa)&&(jurusan[3].b_inggris<=siswa[insiswa].nilai.b_inggris)&&(jurusan[3].b_indonesia<=siswa[insiswa].nilai.b_indonesia)){
				return 4;
			}else{
				return -1;
			}
		}else{
			return -1;
		}
	}else if(jur == 4){
		if(rata >= toi){
			if((jurusan[4].matematika<=siswa[insiswa].nilai.matematika)&&(jurusan[4].ipa<=siswa[insiswa].nilai.ipa)&&(jurusan[4].b_inggris<=siswa[insiswa].nilai.b_inggris)&&(jurusan[4].b_indonesia<=siswa[insiswa].nilai.b_indonesia)){
				return 5;
			}else{
				return -1;
			}
		}else{
			return -1;
		}
	}else if(jur == 5){
		if(rata >= toi){
			if((jurusan[5].matematika<=siswa[insiswa].nilai.matematika)&&(jurusan[5].ipa<=siswa[insiswa].nilai.ipa)&&(jurusan[5].b_inggris<=siswa[insiswa].nilai.b_inggris)&&(jurusan[5].b_indonesia<=siswa[insiswa].nilai.b_indonesia)){
				return 6;
			}else{
				return -1;
			}
		}else{
			return -1;
		}
	}else{
		return -1;
	}

}
int sorting(int stat, pendaftaran siswa[200],int insiswa){
	int temp[20];
 	int param = 0 ;
 	int pl = stat;
 	
 	for(int a = 0; a <= insiswa ; a++){
 		if(siswa[a].status == stat){
 			temp[param] = a;
 			param++;
		 }
	}
	
	for(int b = 0; b <= param ; b++ ){
		if((siswa[temp[b]].nilai.matematika <= siswa[insiswa].nilai.matematika)&&(siswa[temp[b]].nilai.ipa <= siswa[insiswa].nilai.ipa)&&(siswa[temp[b]].nilai.b_inggris <= siswa[insiswa].nilai.b_inggris)&&(siswa[temp[b]].nilai.b_indonesia <= siswa[insiswa].nilai.b_indonesia)){
			siswa[temp[b]].status = -1;
			stat = pl; 
			break; 	
		}else{
			stat = -1;
		}
	}
	
	return stat;	
}

void inputsiswa(pelajaran jurusan[6],float tkj, pendaftaran siswa[200],float rpl, float titl, float toi, float av, float mm, int *insiswa){
bool exist; //inisialisasi variable local
		cout<<*insiswa;
		getche();
	
	do{	
		exist = false; //inisiasi variable
		system("cls");
		cout << "---------------------------------------------------------------------\n";
		cout << "Masukan No Pendaftaran \t\t\t: ";
		cin  >> siswa[*insiswa].no_pendaftaran;
		
		
		//add by faisal
		//validasi no_pelajaran 
		if(*insiswa != 0){
			int i = 0;
			while(i != (*insiswa) && exist != true){
				if(siswa[i].no_pendaftaran == siswa[*insiswa].no_pendaftaran){
					exist = true;
				}
				i++;
			}
			if (exist){
				cout<<"Nomer pendaftaran sudah ada"<<endl;
				getche();
			}else{
				exist = false;
			}
		}
		cout<<*insiswa;
	}while(exist != false);
	
		cout << "Masukan Nama Calon Siswa \t\t: ";
		fflush(stdin);
		cin.get(siswa[*insiswa].nama, 50);
		cout << "Masukan Jenis Kelamin Calon Siswa (L/P) : ";
		cin  >> siswa[*insiswa].jenis_kelamin;
		cout << "---------------------------------------------------------------------\n";
		cout << "|-----------Daftar Jurusan----------|\n";
		cout << "|1.| Teknik Komputer dan Jaringan   |\n";
		cout << "|2.| Teknik Rekayasa Perangkat Lunak|\n";
		cout << "|3.| Multi Media                    |\n";
		cout << "|4.| Teknik Audio Video             |\n";
		cout << "|5.| Teknik Otomasi Industri        |\n";
		cout << "|6.| Teknik Instalasi Tenaga Listrik|\n";
		cout << "---------------------------------------------------------------------\n";
		cout << "Masukan Pilihan Pertama : ";
		cin  >> siswa[*insiswa].jurusan1;
		cout << "Masukan Pilihan Kedua \t: ";
		cin  >> siswa[*insiswa].jurusan2;
		cout << "---------------------------------------------------------------------\n";
		cout << "Masukan Nilai Bahasa Indonesia \t: ";
		cin  >> siswa[*insiswa].nilai.b_indonesia;
		cout << "Masukan Nilai Bahasa Inggris \t: ";
		cin  >> siswa[*insiswa].nilai.b_inggris;
		cout << "Masukan Nilai IPA \t\t: ";
		cin  >> siswa[*insiswa].nilai.ipa;
		cout << "Masukan Nilai Matematika \t: ";
		cin  >> siswa[*insiswa].nilai.matematika;
		
		*insiswa= counter(*insiswa);
		
		//awal proses seleksi
		int hasil = seleksi(jurusan,siswa[*insiswa].jurusan1,siswa, tkj, rpl, titl, toi, av, mm, *insiswa);
		if(hasil >0){
		siswa[*insiswa].status = hasil;
		}else{
			hasil = seleksi(jurusan,siswa[*insiswa].jurusan2, siswa,tkj, rpl, titl, toi, av, mm, *insiswa);
			siswa[*insiswa].status = hasil;
		}
		 hasil = sorting(siswa[*insiswa].status,siswa, *insiswa);
		 siswa[*insiswa].status = hasil;
		 
		 upgrade(jurusan,siswa[*insiswa].status,siswa, *insiswa);
						
		//akhir
		cout << "---------------------------------------------------------------------\n";
		cout << "----------------------------Data Tersimpan---------------------------\n";
		cout << "---------------------------------------------------------------------\n";
	system("pause");
	
	system("cls");

}
void datapendaftar(pendaftaran siswa[200],int insiswa){
	cout << "--------------------------------------------------------------------------------"<<endl;
	cout << "---------------------Data Siswa Terdaftar---------------------------------------"<<endl;
	cout << "--------------------------------------------------------------------------------"<<endl;
	cout << "| NP  | Nama             | L/P | PIL 1 | PIL 2 | MAT | B.INGG | B.INDO | IPA |"<<endl;
	cout << "--------------------------------------------------------------------------------"<<endl;
	for(int a = 0; a <= insiswa ; a++){
		//rumus gotoxy
		// batas x = 80
		//batas y = 25
	
		gotoxy(0,a+8);
	cout<< "|     |                  |     |       |       |     |        |        |     |";
		gotoxy(2,8+a);
		cout<<siswa[a].no_pendaftaran;
		
		gotoxy(8,8+a);
		cout<<siswa[a].nama;
		
		gotoxy(26,8+a);
		cout<<siswa[a].jenis_kelamin;
		
		gotoxy(32,8+a);
		cout<<siswa[a].jurusan1;
		
		gotoxy(40,8+a);
		cout<<siswa[a].jurusan2;
		gotoxy(49,8+a);
		cout<<siswa[a].nilai.matematika;
		
		gotoxy(56,8+a);
		cout<<siswa[a].nilai.b_inggris;
		
		gotoxy(64,8+a);
		cout<<siswa[a].nilai.b_indonesia;
		
		gotoxy(73,8+a);
		cout<<siswa[a].nilai.ipa;
		cout<<endl;
		
		
		
 		//cout << "| "<<" | "<<siswa[a].nama<<" | "<<siswa[a].jenis_kelamin<<" | "<<siswa[a].jurusan1<<" | "<<siswa[a].jurusan2<<" | "<<siswa[a].nilai.matematika<<" | "<<siswa[a].nilai.b_inggris<<" | "<<siswa[a].nilai.b_indonesia<<" | "<<siswa[a].nilai.ipa<<" |\n";
		//cout << "-----------------------------------------------------------------------------------------------------\n";	
		
	}
	/*cout << "-----------------------------------------------------------------------------------------------------\n";
	cout << "------------------------------------------Keterangan-------------------------------------------------\n";
	cout << "-----------------------------------------------------------------------------------------------------\n";
	cout << "--------------------------------|-----------Daftar Jurusan----------|--------------------------------\n";
	cout << "--------------------------------|1.| Teknik Komputer dan Jaringan   |--------------------------------\n";
	cout << "--------------------------------|2.| Teknik Rekayasa Perangkat Lunak|--------------------------------\n";
	cout << "--------------------------------|3.| Teknik Instalasi Tenaga Listrik|--------------------------------\n";
	cout << "--------------------------------|4.| Teknik Otomasi Industri        |--------------------------------\n";
	cout << "--------------------------------|5.| Teknik Audio Video             |--------------------------------\n";
	cout << "--------------------------------|6.| Multi Media                    |--------------------------------\n";
	cout << "-----------------------------------------------------------------------------------------------------\n"; 
	*/
	system("pause");

}

void dataditerima(pendaftaran siswa[200],int insiswa){
	for(int x = 0; x <= 5; x++){
	cout << "--------------------------------------------------------------------------------"<<endl;
	cout << "---------------------Data Siswa Terdaftar---------------------------------------"<<endl;
	cout << "--------------------------------------------------------------------------------"<<endl;
	cout << "| NP  | Nama             | L/P | PIL 1 | PIL 2 | MAT | B.INGG | B.INDO | IPA |"<<endl;
	cout << "--------------------------------------------------------------------------------"<<endl;
		for(int a = 0; a <= insiswa ; a++){
			if(siswa[a].status == x){
					gotoxy(0,a+8);
					cout<< "|     |                  |     |       |       |     |        |        |   |";
					gotoxy(2,8+a);
					cout<<siswa[a].no_pendaftaran;
					
					gotoxy(8,8+a);
					cout<<siswa[a].nama;
					
					gotoxy(26,8+a);
					cout<<siswa[a].jenis_kelamin;
					
					gotoxy(32,8+a);
					cout<<siswa[a].jurusan1;
					
					gotoxy(40,8+a);
					cout<<siswa[a].jurusan1;
					gotoxy(49,8+a);
					cout<<siswa[a].nilai.matematika;
					
					gotoxy(56,8+a);
					cout<<siswa[a].nilai.b_inggris;
					
					gotoxy(64,8+a);
					cout<<siswa[a].nilai.b_indonesia;
					
					gotoxy(73,8+a);
					cout<<siswa[a].nilai.ipa;
					cout<<endl;
							
		 		//cout << "| "<<siswa[a].no_pendaftaran<<" | "<<siswa[a].nama<<" | "<<siswa[a].jenis_kelamin<<" | "<<siswa[a].jurusan1<<" | "<<siswa[a].jurusan2<<" | "<<siswa[a].nilai.matematika<<" | "<<siswa[a].nilai.b_inggris<<" | "<<siswa[a].nilai.b_indonesia<<" | "<<siswa[a].nilai.ipa<<" |\n";
				//cout << "-----------------------------------------------------------------------------------------------------\n";	
			}
		}
	/*	
		cout << "--------------------------------------------------------------------------------"<<endl;
		cout << "-------------------------------Keterangan---------------------------------------"<<endl;
		cout << "--------------------------------------------------------------------------------"<<endl;
		cout << "---------------|-----------Daftar Jurusan----------|----------------------------"<<endl;
		cout << "---------------|1.| Teknik Komputer dan Jaringan   |----------------------------"<<endl;
		cout << "---------------|2.| Teknik Rekayasa Perangkat Lunak|----------------------------"<<endl;
		cout << "---------------|3.| Teknik Instalasi Tenaga Listrik|----------------------------"<<endl;
		cout << "---------------|4.| Teknik Otomasi Industri        |----------------------------"<<endl;
		cout << "---------------|5.| Teknik Audio Video             |----------------------------"<<endl;
		cout << "---------------|6.| Multi Media                    |-----------------------------"<<endl;
		cout << "---------------------------------------------------------------------------------"<<endl; 
	 */
	 }
	system("pause");

}
void dataditolak(pendaftaran siswa[200],int insiswa){
	 	cout << "--------------------------------------------------------------------------------"<<endl;
		cout << "---------------------Data Siswa Terdaftar---------------------------------------"<<endl;
		cout << "--------------------------------------------------------------------------------"<<endl;
		cout << "| NP  | Nama             | L/P | PIL 1 | PIL 2 | MAT | B.INGG | B.INDO | IPA |"<<endl;
		cout << "--------------------------------------------------------------------------------"<<endl;
	for(int a = 0; a <= insiswa ; a++){
			if(siswa[a].status == -1){
		 		
				 	gotoxy(0,a+8);
					cout<< "|     |                  |     |       |       |     |        |        |   |";
					gotoxy(2,8+a);
					cout<<siswa[a].no_pendaftaran;
					
					gotoxy(8,8+a);
					cout<<siswa[a].nama;
					
					gotoxy(26,8+a);
					cout<<siswa[a].jenis_kelamin;
					
					gotoxy(32,8+a);
					cout<<siswa[a].jurusan1;
					
					gotoxy(40,8+a);
					cout<<siswa[a].jurusan1;
					gotoxy(49,8+a);
					cout<<siswa[a].nilai.matematika;
					
					gotoxy(56,8+a);
					cout<<siswa[a].nilai.b_inggris;
					
					gotoxy(64,8+a);
					cout<<siswa[a].nilai.b_indonesia;
					
					gotoxy(73,8+a);
					cout<<siswa[a].nilai.ipa;
					cout<<endl;
				
               }
	system("pause");
          } 
    }

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void login(input entry[20],pendaftaran siswa[200],pelajaran jurusan[6],float tkj, float rpl, float titl, float toi, float av, float mm, int *insiswa){
	char username[10],password[8];
	system("cls");
	cout << "---------------------------------------------------------------------\n";
	cout << "Login System :\n";
	cout << "---------------------------------------------------------------------\n";
	cout << "Masukan username\t: " ;
	cin  >> username;
	cout << "Masukan password\t: " ;
	cin  >> password;
	
	if((strcmp(username,"admin") == 0)&&(strcmp(password,"admin") == 0)){
		int m = 0;
		while(m == 0){
			cout << "======== Aplikasi Penerimaan Siswa Baru SMK Negeri 4 Bandung ========\n";
		    cout << "---------------------------------------------------------------------\n";
		    cout << "Selamat Datang Administrator!\n";
			cout << "---------------------------------------------------------------------\n";
			passing(jurusan,tkj, rpl, titl, toi, av, mm);
			cout << "Menu :\n";
			cout << "---------------------------------------------------------------------\n";
			cout << "1. Tambah User Tim Entry \n" ;
			cout << "2. Ubah Standar Nilai\n" ;
			cout << "3. Data Pendaftar\n" ;
			cout << "4. Data Diterima\n" ;
			cout << "5. Data Ditolak\n" ;
			cout << "6. Logout\n" ;
			cout << "---------------------------------------------------------------------\n";
			cout << "Masukan no menu pilihan anda :" ;
			int adminmenu;
			cin  >> adminmenu;
				switch(adminmenu){
					case 1 :
						inputentry(entry);
						break;
					case 2 :
						system("cls");
						ubahnilai(jurusan);
						break;
					case 3 :
						system("cls");
						datapendaftar(siswa,*insiswa);
						break;
					case 4 :
						system("cls");
						dataditerima(siswa,*insiswa);
						break;
					case 5 :
						system("cls");
						dataditolak(siswa,*insiswa);
						break;
					case 6 :
						m++;
						break;
					default :
						break;
				}
		}
		system("pause");
	}else{
		int stat =0;
		for(int a = 0; a < 20 ;a++){
			if((strcmp(username,entry[a].username) == 0)&&(strcmp(password,entry[a].password) == 0)){
				system("cls");
				int m  = 0;
				stat++;
				while(m == 0){
					cout << "======== Aplikasi Penerimaan Siswa Baru SMK Negeri 4 Bandung ========\n";
				    cout << "---------------------------------------------------------------------\n";
				    cout << "Selamat Datang " << entry[a].username << "\n";
					cout << "---------------------------------------------------------------------\n";
					cout << "Menu :\n";
					cout << "---------------------------------------------------------------------\n";
					cout << "1. Tambah Data Pendaftar\n" ;
					cout << "2. Logout\n" ;
					cout << "---------------------------------------------------------------------\n";
					cout << "Masukan menu pilihan :" ;
					int entrymenu;
					cin  >> entrymenu;
						switch(entrymenu){
							case 1 :
								inputsiswa(jurusan,tkj,siswa, rpl, titl, toi, av, mm, insiswa);
								break;
							case 2 :
								m++;
								break;
							default :
								break;
						}
				}
				system("pause");
				break;
			}
		}
		if(stat == 0){
			cout << "Username / Password Salah\n";
			system("pause");
		}
	}
	
 }




int main(int argc, char** argv) {
	pendaftaran siswa[200];
    int inentry = 0;
    pelajaran jurusan[6];

	input entry[20];
	
	float tkj,rpl,mm,toi,av,titl;
 	int insiswa = 0;
	int pilihan; 	
 	//insiswa = insiswa + 1;
 	standar(jurusan);
 	do{	
		pilihan = menu(jurusan,tkj, rpl, titl, toi, av, mm);
		switch (pilihan){
			case 1:
					login(entry,siswa,jurusan, tkj, rpl, titl, toi, av, mm, &insiswa);
				break;
			case 2:
					search(siswa,insiswa);
				break;
			case 3:
					persyaratan(jurusan,tkj, rpl, titl, toi, av, mm);
					system("pause");
				break;
			case 4:
					system("cls");
					cout << "======== Aplikasi Penerimaan Siswa Baru SMK Negeri 4 Bandung ========\n";
					cout << "---------------------------------------------------------------------\n";
					cout << "----------Terima Kasih Telah Menggunakan Aplikasi kami---------------\n";
					cout << "---------------------------------------------------------------------\n";
					
					system("pause");
				break;
			default:
					system("cls");
					cout << "================ Maaf pilihan anda tidak terdefinisi ================\n";
					cout << "---------------------------------------------------------------------\n";
					cout << "----------------------- Silahkan Coba Lagi !!! ----------------------\n";
					cout << "---------------------------------------------------------------------\n";
					system("pause");
				break;
			}
		system("cls");	
	}while(pilihan != 4);	

	return 0;
}