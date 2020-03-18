/*************************************************************************
 * Ini adalah contoh coding                                              *
 * Untuk Memahami tentang:                                               *
 * - Penggunaan Flag                                                     *
 * - I/O Program                                                         *
 * - If - Else Statement                                                 *
 * - Do - While Repetition                                               *
 * - While Repetition                                                    *
 * - Switch Case                                                         *
 * - Function (w/ Actual Parameter dan Formal Parameter)                 *
 * - Recursive                                                           *
 * - File Processing                                                     *
 * - Struct                                                              *
 * - Sorting                                                             *
 * - Searching                                                           *
 * Update utk Semester 2                                                 *
 * - Linked List                                                         *
 * - Trees (Not Implemented Yet...)                                      *
 *                                                                       *
 * Coding ini telah dibreakdown                                          *
 * Penjelasan proses setiap baris kode                                   *
 * Agar anda mudah memahami jalan program                                *
 *                                                                       *
 * Jika dirasa berguna, dapat kalian share                               *
 * Dengan syarat dan ketentuan berlaku, jika ada pertanyaan              *
 * Bisa hubungi saya... bagi yang tahu :v                                *
 * Terima kasih                                                          *
 * Regards,                                                              *
 *                                                                       *
 * Rafli Jaskandi                                                        *
 *                                                                       *
 * Program Mahasiswa Source Code                                         *
 * Copyright (C) 2019  Rafli Jaskandi                                    *
 *                                                                       *
 * This program is free software: you can redistribute it and/or modify  *
 * it under the terms of the GNU General Public License as published by  *
 * the Free Software Foundation, either version 3 of the License, or     *
 * (at your option) any later version.                                   *
 *                                                                       *
 * This program is distributed in the hope that it will be useful,       *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 * GNU General Public License for more details.                          *
 *                                                                       *
 * You should have received a copy of the GNU General Public License     *
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.*
 *                                                                       *
 *************************************************************************/

/*****************
 * Library
 *****************/

#include <stdio.h> //printf, scanf, FILE, fopen, fclose, fcloseall, fflush(stdin)
#include <stdlib.h> //system("cls")
#include <string.h> //strcpy(), strcmp()
#include <unistd.h> //sleep(unsigned time);
#include <conio.h> //getch()
/*****************
 * Variabel Global
 *****************/

//Indeks Jumlah Data pada file
int data_index = 0; //Untuk menentukan berapa banyak jumlah data / index dalam file
int node_index = 0; //Untuk menentukan berapa banyak jumlah data / index dalam file (Linked List)
/*****************
 * Data Structure
 *****************/

//Detail Mahasiswa
struct detail_mahasiswa
{
    char nama[30]; //Untuk menyimpan nama Mahasiswa
    char nim[12]; //Untuk menyimpan NIM Mahasiswa
};
//Variable global untuk Detail Mahasiswa
struct detail_mahasiswa mahasiswa[20]; //Mahasiswa[20] disini bertindak sebagai variabel global dari struct detail_mahasiswa
/********************
 * Sama dengan
 * char nama[20][30];
 * char nim[20][12];
 ********************/
//Pointer untuk Detail Mahasiswa
//struct detail_mahasiswa *mhs[20]; //mhs adalah pointer dari struct mahasiswa
//Untuk pointer struct tidak dapat digunakan karena saya tidak tahu persis cara kerjanya, Terims...

//Detail Mahasiswa (Linked List)
struct node_mahasiswa
{
    int key; //Untuk menandai list keberapa
    char node_nama[30]; //Untuk menyimpan nama Mahasiswa
    char node_nim[12]; //Untuk menyimpan nama Mahasiswa
    struct node_mahasiswa *next; //Pointer untuk menunjuk list selanjutnya
};
//Pointer untuk menunjuk kepala atau data paling depan dari list
struct node_mahasiswa *head = NULL;

/*****************
 * Prototype Fungsi / Fungsi
 *****************/

//Fungsi

//Membersihkan Layar Console
void clrscr()
{
    system("cls"); //Fungsi dari library stdlib.h untuk membersihkan layar console
}
//Mencetak Garis
void cetak_garis(int n) //Formal parameter int n(Merujuk pada angka yang akan dimasukan pada Actual Parameter)
{
    //Variabel Lokal
    int i; //Untuk batas awal pengulangan For
    //Metode
    for(i = 0; i < n; i++) //Pengulangan dari 0 sampai ke-n
    {
        printf("="); //Mencetak =
    }
}
//Membaca Data
void baca_data()
{
    FILE *pf; //Pointer File Lokal
    /***********************************
     * Jika file data.txt tidak ada
     * Maka akan dibuat sebuah data.txt
     * Dengan isi yang kosong
     ***********************************/
    if((pf = fopen("data.txt", "r")) == NULL) //Jika data.txt tidak ada / NULL, maka
    {
        pf = fopen("data.txt", "w"); //Membuat file data.txt dengan isi yang kosong
        fcloseall; //Menutup semua pointer file yang digunakan untuk file processing
    }
    else //Selain itu... (Jika data.txt ada)
    {
        pf = fopen("data.txt", "r"); //Membuka file dengan mode read
        while(fscanf(pf, "%[^#]# %s\n", mahasiswa[data_index].nama, mahasiswa[data_index].nim) != EOF) //Ketika membaca file sebelum End Of File
        {
            data_index++; //Data Index ditambah 1 setiap pengulangan
        }
        fclose(pf); //Menutup pointer file pf
    }
}

//Prototype Fungsi

//Menu Utama
void menu();
//Mencetak Data
void cetak_data();
//Menambah Data
void tambah_data();
//Edit Data
void edit_data();
//Hapus Data
void hapus_data();
//Menyimpan Data
void simpan_data();
//Sorting
void sorting();
//Searching
void searching();
//Searching berdasarkan Nama
int Nama_search(char *cari); //Formal parameter char pointer cari(Merujuk pada variabel char char_cari)
//Searching berdasarkan NIM
int NIM_search(long long int *cari); //Formal Parameter long long int pointer cari(Merujuk pada variabel long long int NIM)

/*****************
 * Program
 *****************/

//Program Utama
int main(int argv, const char *argc[])
{
    /*******************************************************************
     * Tidak usah pedulikan parameter pada int main()
     * Hanya sedikit formalitas yang tidak terlalu penting
     * Langsung saja lihat kode dari fungsi menu()
     * 
     * Jika penasaran, silahkan searching google
     * printf("%s", *argc); akan mencetak tulisan lokasi exe dijalankan
     ******************************************************************/
    menu(); //Memanggil fungsi Menu
    return 0;
}
//Menu Utama
void menu()
{
    //Variabel Lokal
    int ans; //Untuk pemilihan Switch Case pada menu
    static int flag = 0; //Untuk penanda pembacaan file agar tidak berulang kali, static disini agar variabel tidak berubah jika fungsi dipanggil kembali
    //Proses Pembacaan Data
    if(flag == 0) //Jika data belum dibaca, maka
    {
        baca_data(); //Memanggil baca_data untuk membaca file
    }
    flag = 1; //Penanda jika data sudah dibaca
    //Tampilan
    cetak_garis(30); //Mencetak sebuah garis
    puts(""); //Memberi enter setelah cetak garis diatas
    printf("  Project Program Mahasiswa");
    puts(""); //Memberi enter setelah cetak garis diatas
    cetak_garis(30); //Mencetak sebuah garis
    printf("\n\n"); //Memberi enter sebanyak 2x setelah cetak garis diatas
    printf("Menu\n");
    printf("1. Lihat Data\n");
    printf("2. Tambah Data\n");
    printf("3. Edit Data\n");
    printf("4. Hapus Data\n");
    printf("5. Urutkan Data\n");
    printf("6. Mencari Data\n");
    printf("7. Simpan Data\n");
    printf("8. Lihat Node\n");
    printf("9. Tambah Node\n");
    printf("10. Edit Node\n");
    printf("11. Hapus Node\n");
    printf("12. Urutkan Node\n");
    printf("13. Mencari Node\n");
    printf("14. Simpan Node\n");
    printf("15. Keluar\n");
    //Pengulangan kode dibawah ketika baris membaca syarat while
    do
    {
        printf("Jawaban anda: ");
        scanf("%d", &ans); //Input ke variabel ans
        fflush(stdin); //Untuk jaga jaga jika nanti terdapat error saat input disuatu tempat
        switch(ans) //Pengecekan isi variabel ans
        {
            case 1:
                //Jika ans == 1, maka
                clrscr(); //Membersihkan Layar Console
                cetak_data(); //Memanggil fungsi cetak_data
            case 2:
                //Jika ans == 2, maka
                if(data_index < 20) //Jika index data masih dibawah 20, maka
                {
                    clrscr(); //Membersihkan Layar Console
                    tambah_data(); //Memanggil fungsi tambah_data
                }
                else //Selain itu...
                {
                    printf("Mohon maaf, database telah penuh...!\n");
                    printf("Hapus beberapa data terlebih dahulu sebelum lanjut...");
                    sleep(2); //Jeda selama 1 detik
                    clrscr(); //Membersihkan layar console
                    menu(); //Memanggil fungsi menu (Ini Rekursif)
                }
                
            case 3:
                //Jika ans == 3, maka
                clrscr(); //Membersihkan Layar Console
                edit_data(); //Memanggil fungsi edit_data
            case 4:
                //Jika ans == 4, maka
                clrscr(); //Membersihkan Layar Console
                hapus_data(); //Memanggil fungsi hapus_data
            case 5:
                //Jika ans == 5, maka
                if(data_index > 0) //Jika index data lebih dari 0, maka
                {
                    clrscr(); //Membersihkan layar console
                    sorting(); //Memanggil fungsi sorting
                }
                else //Selain itu...
                {
                    printf("Tidak bisa mengurutkan data...!\n");
                    printf("Tidak ada data tersedia...");
                    sleep(1); //Jeda selama 1 detik
                    clrscr(); //Membersihkan layar console
                    menu(); //Memanggil fungsi menu (Ini Rekursif)
                }
            case 6:
                //Jika ans == 6, maka
                if(data_index > 0) //Jika index data lebih dari 0, maka
                {
                    clrscr(); //Membersihkan layar console
                    searching(); //Memanggil fungsi searching
                }
                else //Selain itu...
                {
                    printf("Tidak bisa mencari data...!\n");
                    printf("Tidak ada data tersedia...");
                    sleep(1); //Jeda selama 1 detik
                    clrscr(); //Membersihkan layar console
                    menu(); //Memanggil fungsi menu (Ini Rekursif)
                }
            case 7:
                //Jika ans == 7, maka
                clrscr(); //Membersihkan Layar Console
                simpan_data(); //Memanggil fungsi simpan_data
            case 15:
                //Jika ans == 15, maka
                exit(0); //Program selesai / berhenti dengan status 0 (Tidak ada error atau masalah)
                /*********************************************************
                 * Bisa juga menggunakan return(0);
                 * Jika switch case ini masih didalam int main()
                 * Penggunaan return 0; dapat mengakhiri program
                 * Tetapi lebih dianjurkan untuk menggunakan fungsi exit()
                 *********************************************************/
            default:
                //Jika ans != 1, 2, 3, 4, 5, 6, 7, 8, maka
                continue; //Pembacaan kode berlanjut ke while(1)
        }
        /**********************************************
         * Jika pembacaan kode bertemu while(1)
         * Maka kode akan kembali membaca dari awal Do
         * Karena while(1) adalah pengulangan Infinity
         **********************************************/
    } while (1); //Pengulangan tak hingga(Infinite)
}
//Cetak Data
void cetak_data()
{
    //Variabel Lokal
    int i; //Untuk batas awal For
    int no = 0; //Untuk mencetak urutan nomor data
    cetak_garis(50); //Mencetak sebuah garis
    puts(""); //Memberi enter setelah cetak garis
    printf("\t\tList Mahasiswa\n");
    cetak_garis(50); //Mencetak sebuah garis
    puts(""); //Memberi enter setelah cetak garis
    printf("%-2s| %-30s| %-10s\n", "No","            Nama", "    NIM"); //No|      Nama      |       NIM
    cetak_garis(50); //Mencetak sebuah garis
    puts(""); //Memberi enter setelah cetak garis
    for(i = 0; i < data_index; i++) //Dari i ke 0 sampai kurang dari data_index
    {
        printf("%-2d| %-30s| %-10s\n", ++no, mahasiswa[i].nama, mahasiswa[i].nim); //Mencetak Data
    }
    if(data_index > 0) //Jika indeks data > 0, maka
    {
        cetak_garis(50); //Mencetak sebuah garis
    }
    printf("\n"); //Memberi enter setelah cetak garis
    printf("Jumlah data: %d/20", data_index); //Mencetak berapa banyak data yang tersedia dan batas data yang dapat ditampung
    getch(); //Memberi jeda sampai user menekan sembarang tombol
    clrscr(); //Membersihkan layar console
    menu(); //Memanggil fungsi menu
}
//Menambah Data
void tambah_data()
{
    char ans; //Untuk menyimpan jawaban sebuah pilihan
    //Input Data
    do
    {
        printf("Masukkan nama Mahasiswa: ");
        scanf("%[^\n]", mahasiswa[data_index].nama); //Input ke nama dalam mahasiswa, array ke data_index
        fflush(stdin); //Untuk jaga jaga jika nanti terdapat error saat input disuatu tempat
    } while (strlen(mahasiswa[data_index].nama) < 1 || strlen(mahasiswa[data_index].nama) > 30); //Pengulangan input jika input yang dimasukkan == 0  atau > 30
    do
    {
        printf("Masukkan NIM Mahasiswa: ");
        scanf("%s", mahasiswa[data_index].nim); //Input ke nim dalam mahasiswa, array ke data_index
        fflush(stdin); //Untuk jaga jaga jika nanti terdapat error saat input disuatu tempat
    } while (strlen(mahasiswa[data_index].nim) < 10 || strlen(mahasiswa[data_index].nim) > 10); //Pengulangan input jika input yang dimasukkan < 10 atau > 10
    //Cek data
    printf("%-30s| %-10s\n", mahasiswa[data_index].nama, mahasiswa[data_index].nim); //Mencetak hasil input
    do
    {
        printf("Apakah data sudah benar, c untuk cancel? [y/n/c]\n");
        ans = getch(); //Input ans tanpa terlihat dalam console
        fflush(stdin); //Untuk jaga jaga jika nanti terdapat error saat input disuatu tempat
        //Cek variabel ans
        if(ans == 'y') //Jika ans == y, maka
        {
            data_index++; //Memastikan jika kita mau input kembali, kita tidak menumpuk inputan lama dengan inputan baru
            printf("Data telah terekam!");
            sleep(1); //Jeda selama 1 detik
            clrscr(); //Membersihkan layar console
            menu(); //Memanggil Fungsi menu
        }
        else if(ans == 'n') //Jika ans == n, maka
        {
            clrscr(); //Membersihkan layar console
            tambah_data(); //Memanggil fungsi tambah_data untuk input ulang
        }
        else if(ans == 'c') //Jika ans == c, maka
        {
            clrscr(); //Membersihkan layar console
            menu(); //Memanggil fungsi menu
        }
        else //Jika selain kedua syarat diatas, maka
        {
            continue; //Lanjut pengulangan dari awal Do
        }
    } while (1); //Infinite Loop
}
//Edit Data
void edit_data()
{
    //Variabel Lokal
    int i; //Untuk batas awal For
    int no = 0; //Untuk mencetak urutan nomor data
    int idx; //Untuk menentukan index data yang mau diedit
    char ans; //Untuk menyimpan jawaban sebuah pilihan
    //Menampilkan data
    cetak_garis(50); //Mencetak sebuah garis
    puts(""); //Memberi enter setelah cetak garis
    printf("\t\tList Mahasiswa\n");
    cetak_garis(50); //Mencetak sebuah garis
    puts(""); //Memberi enter setelah cetak garis
    printf("%-2s| %-30s| %-10s\n", "No","            Nama", "    NIM"); //No|      Nama      |       NIM
    cetak_garis(50); //Mencetak sebuah garis
    puts(""); //Memberi enter setelah cetak garis
    for(i = 0; i < data_index; i++) //Dari i ke 0 sampai kurang dari data_index
    {
        printf("%-2d| %-30s| %-10s\n", ++no, mahasiswa[i].nama, mahasiswa[i].nim); //Mencetak Data
    }
    if(data_index > 0) //Jika indeks data > 0, maka
    {
        cetak_garis(50); //Mencetak sebuah garis
    }
    printf("\n\n"); //Memberi enter sebanyak 2 kali setelah cetak garis
    printf("Data ke berapa yang mau diedit? [99 untuk batal] ");
    scanf("%d", &idx); //Input ke variabel idx
    fflush(stdin); //Untuk jaga jaga jika nanti terdapat error saat input disuatu tempat
    puts(""); //Memberi enter setelah cetak garis
    if(idx == 99)
    {
        clrscr(); //Membersihkan layar console
        menu(); //Memanggil fungsi menu
    }
    else
    {
        /*******************************************************************************************************************
         * Dalam bagian ini, setiap input langsung masuk array ke data_index.
         * Jadi kalau tidak jadi mengedit data, maka sebenarnya data sudah terganti oleh inputan yang dimasukan sebelumnya.
         * Nah, solusi dari itu adalah ketika kita menginput data, kita sudah punya cadangan data tersebut,
         * Semisal kita tidak jadi mengedit data, kita dapat mengembalikan data yang sempat kita ubah
         *******************************************************************************************************************/
        printf("%-2d| %-30s| %-10s\n", idx, mahasiswa[idx - 1].nama, mahasiswa[idx - 1].nim); //Mencetak data yang mau diedit
        //Penyimpanan Sementara jika tidak jadi edit data
        char temp_nama[30]; //Penyimpanan nama sementara
        char temp_nim[12]; //Penyimpanan NIM sementara
        strcpy(temp_nama, mahasiswa[idx - 1].nama); //Menyalin variabel mahasiswa[idx - 1].nama ke temp_nama
        strcpy(temp_nim, mahasiswa[idx - 1].nim); //Menyalin variabel mahasiswa[idx - 1].nim ke temp_nim
        //Input Data
        do
        {
            printf("Masukkan nama Mahasiswa: ");
            scanf("%[^\n]", mahasiswa[idx - 1].nama); //Input ke nama dalam pointer mhs array ke data_index
            fflush(stdin); //Untuk jaga jaga jika nanti terdapat error saat input disuatu tempat
        } while (strlen(mahasiswa[idx - 1].nama) < 1 || strlen(mahasiswa[idx - 1].nama) > 30); //Pengulangan input jika input yang dimasukkan == 0  atau > 30
        do
        {
            printf("Masukkan NIM Mahasiswa: ");
            scanf("%s", mahasiswa[idx - 1].nim); //Input ke nim dalam pointer mhs array ke data_index
            fflush(stdin); //Untuk jaga jaga jika nanti terdapat error saat input disuatu tempat
        } while (strlen(mahasiswa[idx - 1].nim) < 10 || strlen(mahasiswa[idx - 1].nim) > 10); //Pengulangan input jika input yang dimasukkan < 10 atau > 10
        //Cek data
        printf("%-30s| %-10s\n", mahasiswa[idx - 1].nama, mahasiswa[idx - 1].nim); //Mencetak hasil yang dicari
        do
        {
            printf("Apakah data yang diedit sudah benar, c untuk cancel? [y/n/c]\n");
            ans = getch(); //Input ans tanpa terlihat dalam console
            fflush(stdin); //Untuk jaga jaga jika nanti terdapat error saat input disuatu tempat
            //Cek variabel ans
            if(ans == 'y') //Jika ans == y, maka
            {
                printf("Data telah teredit!");
                sleep(1); //Jeda selama 1 detik
                clrscr(); //Membersihkan layar console
                menu(); //Memanggil Fungsi menu
            }
            else if(ans == 'n') //Jika ans == n, maka
            {
                strcpy(mahasiswa[idx - 1].nama, temp_nama); //Mengembalikan data sebelumnya
                strcpy(mahasiswa[idx - 1].nim, temp_nim); //Mengembalikan data sebelumnya
                clrscr(); //Membersihkan layar console
                edit_data(); //Memanggil fungsi edit_data untuk input ulang
            }
            else if(ans == 'c') //Jika ans == c, maka
            {
                strcpy(mahasiswa[idx - 1].nama, temp_nama);
                strcpy(mahasiswa[idx - 1].nim, temp_nim);
                clrscr(); //Membersihkan layar console
                menu(); //Memanggil fungsi menu
            }
            else //Jika selain kedua syarat diatas, maka
            {
                continue; //Lanjut pengulangan dari awal Do
            }
        } while (1); //Infinite Loop  
    }
    
}
//Hapus Data
void hapus_data()
{
    //Variabel Lokal
    int i; //Untuk batas awal For
    int no = 0; //Untuk mencetak urutan data
    int idx; //Untuk menentukan index data yang mau dihapus
    char ans; //Untuk menyimpan jawaban sebuah pilihan
    //Menampilkan data
    cetak_garis(50); //Mencetak sebuah garis
    puts(""); //Memberi enter setelah cetak garis
    printf("\t\tList Mahasiswa\n");
    cetak_garis(50); //Mencetak sebuah garis
    puts(""); //Memberi enter setelah cetak garis
    printf("%-2s| %-30s| %-10s\n", "No","            Nama", "    NIM"); //No|      Nama      |       NIM
    cetak_garis(50); //Mencetak sebuah garis
    puts(""); //Memberi enter setelah cetak garis
    for(i = 0; i < data_index; i++) //Dari i ke 0 sampai kurang dari data_index
    {
        printf("%-2d| %-30s| %-10s\n", ++no, mahasiswa[i].nama, mahasiswa[i].nim);
    }
    if(data_index > 0) //Jika indeks data > 0, maka
    {
        cetak_garis(50); //Mencetak sebuah garis
    }
    printf("\n\n"); //Memberi enter sebanyak 2 kali setelah cetak garis
    printf("Data ke berapa yang mau dihapus? [99 untuk batal] ");
    scanf("%d", &idx); //Input ke variabel idx
    fflush(stdin); //Untuk jaga jaga jika nanti terdapat error saat input disuatu tempat
    puts(""); //Memberi enter setelah cetak garis
    if(idx == 99)
    {
        clrscr(); //Membersihkan layar console
        menu(); //Memanggil fungsi menu
    }
    else
    {
        printf("%-30s| %-10s\n", mahasiswa[idx - 1].nama, mahasiswa[idx - 1].nim); //Mencetak hasil yang dicari
        puts(""); //Memberi enter setelah cetak garis
        do
        {
            printf("Apakah anda yakin? c untuk cancel [y/n/c]\n");
            ans = getch(); //Input ans tanpa terlihat dalam console
            fflush(stdin); //Untuk jaga jaga jika nanti terdapat error saat input disuatu tempat
            if(ans == 'y') //Jika ans == y, maka
            {
                //Proses penghapusan data dan menaikan data dibawahnya
                strcpy(mahasiswa[idx - 1].nama, ""); //Menganti variable nama mahasiswa ke idx - 1 dengan string kosong / menghapus
                strcpy(mahasiswa[idx - 1].nim, ""); //Menganti variable nim mahasiswa ke idx - 1 dengan string kosong / menghapus
                for (i = idx; i < data_index; i++) //Nilai i adalah idx, lalu pengulangan dari i sampai kurang dari data_index
                {
                    strcpy(mahasiswa[i - 1].nama, mahasiswa[i].nama); //Mengganti data diatasnya dengan bawahnya
                    strcpy(mahasiswa[i - 1].nim, mahasiswa[i].nim); //Mengganti data diatasnya dengan bawahnya
                }
                data_index--; //Mengurangi jumlah index data
                printf("Data berhasil dihapus!");
                sleep(1); //Jeda selama 1 detik
                clrscr(); //Membersihkan layar console
                menu(); //Memanggil Fungsi menu
            }
            else if(ans == 'n') //Jika ans == n, maka
            {
                clrscr(); //Membersihkan layar console
                hapus_data(); //Memanggil fungsi hapus_data untuk input ulang
            }
            else if(ans == 'c') //Jika ans == c, maka
            {
                clrscr(); //Membersihkan layar console
                menu(); //Memanggil fungsi menu
            }
            else //Jika selain kedua syarat diatas, maka
            {
                continue; //Lanjut pengulangan dari awal Do
            }
        } while (1); //Infinite Loop
    }
}
/* Reference for Bubble Sort, from ppt Algorithm and Programming Session 20

void Bubble(int *DataArr, int n)
{
		int i, j;
		for(i=1; i<n; i++)
			for(j=n-1; j>=i; j--)
				if(DataArr[j-1] > DataArr[j]) 
	             Swap(&DataArr[j-1],&DataArr[j]);
}

*/
//Sorting
void sorting()
{
    //Variabel Lokal
    int i, j; //Untuk batas awal For
    int no = 0; //Untuk mencetak urutan nomor data
    int ans; //Untuk menyimpan jawaban sebuah pilihan
    long long int NIM[20]; //Untuk sorting NIM
    long long int temp; //Untuk menyimpan nilai yang akan ditukar
    char char_temp[30]; //Untuk menyimpan string yang akan ditukar
    cetak_garis(50); //Mencetak sebuah garis
    puts(""); //Memberi enter setelah cetak garis
    printf("\t\tList Mahasiswa\n");
    cetak_garis(50); //Mencetak sebuah garis
    puts(""); //Memberi enter setelah cetak garis
    printf("%-2s| %-30s| %-10s\n", "No","            Nama", "    NIM"); //No|      Nama      |       NIM
    cetak_garis(50); //Mencetak sebuah garis
    puts(""); //Memberi enter setelah cetak garis
    for(i = 0; i < data_index; i++) //Dari i ke 0 sampai kurang dari data_index
    {
        printf("%-2d| %-30s| %-10s\n", ++no, mahasiswa[i].nama, mahasiswa[i].nim); //Mencetak data
    }
    cetak_garis(50); //Mencetak sebuah garis
    printf("\n\n"); //Memberi enter sebanyak 2x
    printf("1. Ascending NIM   2. Descending NIM   3. Ascending Nama   4. Descensing Nama   5. Kembali\n");
    do
    {
        printf("Jawaban Anda: ");
        scanf("%d", &ans); //Input ke variabel ans
        fflush(stdin); //Untuk jaga jaga jika nanti terdapat error saat input disuatu tempat
        //Switch Case
        switch(ans)
        {
            case 1:
                //Jika ans == 1, maka
                //Ascending NIM
                for(i = 0; i < data_index; i++) //Dari i = 0 sampai kurang dari data_index
                {
                    sscanf(mahasiswa[i].nim, "%lld", &NIM[i]); //Convert NIM dari string ke long long int agar dapat disorting
                }
                //Sorting Ascending (Lihat rumus di baris 509)
                for(i = 1; i < data_index; i++) //Dari i = 1 sampai kurang dari data_index
                {
                    for(j = data_index - 1; j >= i; j--) //Dari j = data_index - 1 sampai lebih dari sama dengan i
                    {
                        if(NIM[j - 1] > NIM[j]) //Jika NIM array ke j - 1 lebih besar dari NIM ke j, maka
                        {
                            //Menukar NIM
                            temp = NIM[j - 1];
                            NIM[j - 1] = NIM[j];
                            NIM[j] = temp;
                            //Menukar Nama
                            strcpy(char_temp, mahasiswa[j - 1].nama);
                            strcpy(mahasiswa[j - 1].nama, mahasiswa[j].nama);
                            strcpy(mahasiswa[j].nama, char_temp);
                        }
                    }
                }
                for(i = 0; i < data_index; i++) //Dari i = 0 sampai kurang dari data_index
                {
                    sprintf(mahasiswa[i].nim, "%lld", NIM[i]); //Convert kembali NIM dari long long int ke string
                }
                clrscr(); //Membersihkan layar console
                sorting(); //Memanggil fungsi sorting
            case 2:
                //Jika ans == 2, maka
                //Descending NIM
                for(i = 0; i < data_index; i++) //Dari i = 0 sampai kurang dari data_index
                {
                    sscanf(mahasiswa[i].nim, "%lld", &NIM[i]); //Convert NIM dari string ke long long int agar dapat disorting
                }
                //Sorting Descending (Lihat rumus di baris 509, untuk descending tinggal ganti > dengan < di NIM[j - 1] ... NIM[j])
                for(i = 1; i < data_index; i++) //Dari i = 1 sampai kurang dari data_index
                {
                    for(j = data_index - 1; j >= i; j--) //Dari j = data_index - 1 sampai lebih dari sama dengan i
                    {
                        if(NIM[j - 1] < NIM[j]) //Jika NIM array ke j - 1 lebih kecil dari NIM ke j, maka
                        {
                            //Menukar NIM
                            temp = NIM[j - 1];
                            NIM[j - 1] = NIM[j];
                            NIM[j] = temp;
                            //Menukar Nama
                            strcpy(char_temp, mahasiswa[j - 1].nama);
                            strcpy(mahasiswa[j - 1].nama, mahasiswa[j].nama);
                            strcpy(mahasiswa[j].nama, char_temp);
                        }
                    }
                }
                for(i = 0; i < data_index; i++) //Dari i = 0 sampai kurang dari data_index
                {
                    sprintf(mahasiswa[i].nim, "%lld", NIM[i]); //Convert kembali NIM dari long long int ke string
                }
                clrscr(); //Membersihkan layar console
                sorting(); //Memanggil fungsi sorting
            case 3:
                //Jika ans == 3, maka
                //Ascending Nama
                for(i = 0; i < data_index; i++) //Dari i = 0 sampai kurang dari data_index
                {
                    sscanf(mahasiswa[i].nim, "%lld", &NIM[i]); //Convert NIM dari string ke long long int agar dapat disorting
                }
                //Sorting Ascending (Lihat rumus di https://www.tutorialspoint.com/c_standard_library/c_function_strcmp.htm dan mengambil refrensi dari baris 509)
                for(i = 1; i < data_index; i++) //Dari i = 1 sampai kurang dari data_index
                {
                    for(j = data_index - 1; j >= i; j--) //Dari j = data_index - 1 sampai lebih dari sama dengan i
                    {
                        if(strcmp(mahasiswa[j - 1].nama, mahasiswa[j].nama) < 0) //Jika Nama Mahasiswa array ke j - 1 jumlah angka ascii lebih kecil dari Nama Mahasiswa array ke j, maka
                        {
                            //Menukar NIM
                            temp = NIM[j - 1];
                            NIM[j - 1] = NIM[j];
                            NIM[j] = temp;
                            //Menukar Nama
                            strcpy(char_temp, mahasiswa[j - 1].nama);
                            strcpy(mahasiswa[j - 1].nama, mahasiswa[j].nama);
                            strcpy(mahasiswa[j].nama, char_temp);
                        }
                    }
                }
                for(i = 0; i < data_index; i++) //Dari i = 0 sampai kurang dari data_index
                {
                    sprintf(mahasiswa[i].nim, "%lld", NIM[i]); //Convert kembali NIM dari long long int ke string
                }
                clrscr(); //Membersihkan layar console
                sorting(); //Memanggil fungsi sorting
            case 4:
                //Jika ans == 4, maka
                //Descending Nama
                for(i = 0; i < data_index; i++) //Dari i = 0 sampai kurang dari data_index
                {
                    sscanf(mahasiswa[i].nim, "%lld", &NIM[i]); //Convert NIM dari string ke long long int agar dapat disorting
                }
                //Sorting Descending (Lihat rumus di https://www.tutorialspoint.com/c_standard_library/c_function_strcmp.htm dan mengambil refrensi dari baris 509)
                for(i = 1; i < data_index; i++) //Dari i = 1 sampai kurang dari data_index
                {
                    for(j = data_index - 1; j >= i; j--) //Dari j = data_index - 1 sampai lebih dari sama dengan i
                    {
                        if(strcmp(mahasiswa[j - 1].nama, mahasiswa[j].nama) > 0) //Jika Nama Mahasiswa array ke j - 1 jumlah angka ascii lebih besar dari Nama Mahasiswa array ke j, maka
                        {
                            //Menukar NIM
                            temp = NIM[j - 1];
                            NIM[j - 1] = NIM[j];
                            NIM[j] = temp;
                            //Menukar Nama
                            strcpy(char_temp, mahasiswa[j - 1].nama);
                            strcpy(mahasiswa[j - 1].nama, mahasiswa[j].nama);
                            strcpy(mahasiswa[j].nama, char_temp);
                        }
                    }
                }
                for(i = 0; i < data_index; i++) //Dari i = 0 sampai kurang dari data_index
                {
                    sprintf(mahasiswa[i].nim, "%lld", NIM[i]); //Convert kembali NIM dari long long int ke string
                }
                clrscr(); //Membersihkan layar console
                sorting(); //Memanggil fungsi sorting
            case 5:
                //Jika ans == 5, maka
                clrscr(); //Membersihkan layar console
                menu(); //Memanggil fungsi menu
            default:
                //Jika ans selain 1, 2, 3, 4, 5, maka
                continue; //Lanjut pengulangan dari awal Do
        }
    } while (1);
}
/* Reference for Linear Searching, from ppt Algorithm and Programming Session 22-23

int linearSearch(const int array[], int key, int size) {
	int n;	// counter
	// loop through array
	for (n=0; n<size; ++n){	
		if (array[n] == key){
			return n;	// return location of key
		}	
	}
	return -1;	// key not found
}

*/
//Searching
void searching()
{
    //Variabel Lokal
    int ans; //Untuk menyimpan jawaban sebuah pilihan
    long long int cari; //Untuk menyimpan NIM yang ingin dicari
    char char_cari[30]; //Untuk menyimpan Nama yang ingin dicari
    int hasil; //Untuk menyimpan hasli pencarian data, untuk menentukan ada di array ke berapa data yang dicari
    //Tampilan
    printf("1. Cari berdasarkan Nama\n");
    printf("2. Cari berdasarkan NIM\n");
    printf("3. Kembali\n\n");
    do
    {
        printf("Jawaban Anda: ");
        scanf("%d", &ans); //Input ke variabel ans
        fflush(stdin); //Untuk jaga jaga jika nanti terdapat error saat input disuatu tempat
        puts(""); //Memberi enter
        //Switch Case
        switch(ans)
        {
            case 1:
                //Jika ans == 1, maka
                //Cari berdasarkan Nama
                do
                {
                    printf("Masukkan Nama: ");
                    scanf("%[^\n]", char_cari); //Input Nama yang mau dicari
                    fflush(stdin); //Untuk jaga jaga jika nanti terdapat error saat input disuatu tempat
                } while (strlen(char_cari) < 0 || strlen(char_cari) >= 30);
                hasil = Nama_search(char_cari); //Variable char_cari bertindak sebagai Actual Parameter dan value dari variabel itu akan dioper ke fungsi Nama_search, lalu angka hasil pencarian akan dimasukkan ke variabel hasil
                if(hasil != -1) //Jika hasil ditemukan atau selain -1
                {
                    printf("Data ditemukan!\n");
                    sleep(1); //Jeda selama 1 detik
                    printf("%-2s| %-30s| %-10s\n", "No","            Nama", "    NIM"); //No|      Nama      |       NIM
                    printf("%-2d| %-30s| %-10s", hasil + 1, mahasiswa[hasil].nama, mahasiswa[hasil].nim); //Cetak data yang dicari
                    puts(""); //Memberi enter setelah teks diatas
                    do
                    {
                        printf("Apakah anda mau cari lagi? [y/n]");
                        ans = getch(); //Input ke variabel ans tanpa terlihat di console
                        puts(""); //Memberi enter setelah teks
                        if(ans == 'y') //Jika ans == y, maka
                        {
                            clrscr(); //Membersihkan layar console
                            searching(); //Memanggil fungsi searching
                        }
                        else if(ans == 'n') //Jika ans == n, maka
                        {
                            clrscr(); //Membersihkan layar console
                            menu(); //Memanggil fungsi main
                        }
                        else //Selain itu...
                        {
                            continue; //Lanjut pembacaan kode ke While(1); lalu pembacaan akan berulang dari Do
                        }
                    } while (1); //Infinite Loop
                }
                else //Jika hasil == -1
                {
                    printf("Data tidak ditemukan!\n");
                    sleep(1); //Jeda selama 1 detik
                    do
                    {
                        printf("Apakah anda mau cari lagi? [y/n]");
                        ans = getch(); //Input ke variabel ans
                        puts(""); //Memberi enter setelah teks
                        if(ans == 'y') //Jika ans == y, maka
                        {
                            clrscr(); //Membersihkan layar console
                            searching(); //Memanggil fungsi searching
                        }
                        else if(ans == 'n') //Jika ans == n, maka
                        {
                            clrscr(); //Membersihkan layar console
                            menu(); //Memanggil fungsi menu
                        }
                        else //Selain itu...
                        {
                            continue; //Lanjut pembacaan kode ke While(1); lalu pembacaan akan berulang dari Do
                        }
                    } while (1); //Infinite Loop
                }
                continue;
            case 2:
                //Jika ans == 2, maka
                //Cari berdasarkan NIM
                do
                {
                    printf("Masukkan NIM: ");
                    scanf("%lld", &cari); //Input NIM yang mau dicari
                    fflush(stdin); //Untuk jaga jaga jika nanti terdapat error saat input disuatu tempat
                } while (cari < 1000000000 || cari > 9999999999);
                hasil = NIM_search(&cari); //Variabel cari disini bertindak sebagai Actual Parameter dan value dari variabel tersebut akan dioper ke fungsi NIM_search, lalu angka hasil pencarian akan dimasukkan ke variabel hasil
                if(hasil != -1) //Jika hasil ditemukan atau selain -1
                {
                    printf("Data ditemukan!\n");
                    sleep(1); //Jeda selama 1 detik
                    printf("%-2s| %-30s| %-10s\n", "No","            Nama", "    NIM"); //No|      Nama      |       NIM
                    printf("%-2d| %-30s| %-10s", hasil + 1, mahasiswa[hasil].nama, mahasiswa[hasil].nim); //Cetak data yang dicari
                    puts(""); //Memberi enter setelah teks diatas
                    do
                    {
                        printf("Apakah anda mau cari lagi? [y/n]");
                        ans = getch(); //Input ke variabel ans tanpa terlihat di console
                        puts(""); //Memberi enter setelah teks
                        if(ans == 'y') //Jika ans == y, maka
                        {
                            clrscr(); //Membersihkan layar console
                            searching(); //Memanggil fungsi searching
                        }
                        else if(ans == 'n') //Jika ans == n, maka
                        {
                            clrscr(); //Membersihkan layar console
                            menu(); //Memanggil fungsi menu
                        }
                        else //Selain itu...
                        {
                            continue; //Lanjut pembacaan kode ke While(1); lalu pembacaan akan berulang dari Do
                        }
                    } while (1); //Infinite Loop
                }
                else //Jika hasil == -1
                {
                    printf("Data tidak ditemukan!\n");
                    sleep(1); //Jeda selama 1 detik
                    do
                    {
                        printf("Apakah anda mau cari lagi? [y/n]");
                        ans = getch(); //Input ke variabel ans
                        puts(""); //Memberi enter setelah teks
                        if(ans == 'y') //Jika ans == y, maka
                        {
                            clrscr(); //Membersihkan layar console
                            searching(); //Memanggil fungsi searching
                        }
                        else if(ans == 'n') //Jika ans == n, maka
                        {
                            clrscr(); //Membersihkan layar console
                            menu(); //Memanggil fungsi menu
                        }
                        else //Selain itu...
                        {
                            continue; //Lanjut pembacaan kode ke While(1); lalu pembacaan akan berulang dari Do
                        }
                    } while (1); //Infinite Loop
                }
            case 3:
                //Jika ans == 3, maka
                clrscr(); //Membersihkan layar console
                menu(); //Memanggil fungsi main
            default:
                //Jika ans selain 1, 2, 3, maka
                continue; //Lanjut pengulangan dari awal Do
        }
    } while (1); //Infinite Loop
}
//Search berdasarkan Nama
int Nama_search(char *cari) //Formal Parameter disini adalah char *cari(Maksud dari *cari adalah pointer cari ini merujuk kepada sebuah variabel yang dioper kedalam fungsi ini, yaitu sebuah string char_cari)
{
    //Variabel Lokal
    int i; //Untuk batas awal for
    int n; //Untuk penghitung array keberapa data yang ditemukan sama
    //Linear Searching (Lihat rumus di baris 688, dengan sedikit modifikasi)
    for(n = 0; n < data_index; n++) //Dari n = 0 sampai kurang dari data_index
    {
        if(strcmp(mahasiswa[n].nama, cari) == 0) //Jika NIM array ke n sama dengan cari, maka
        {
            return n; //Kembalikan angka n ke dimana fungsi dipangil
        }
    }
    return -1; //Kembalikan angka -1 ke dimana fungsi dipanggil, hal ini akan dilakukan jika data tidak ada yang sama atau tidak ditemukan
}
//Search berdasarkan NIM
int NIM_search(long long int *cari) //Formal Parameter disini adalah long long int *cari(Maksud dari *cari disini adlah pointer cari ini merujuk kepada sebuah variabel yang dioper kedalam fungsi ini, yaitu alamat dari cari)
{
    //Variabel Lokal
    int i; //Untuk batas awal For
    int n; //Untuk penghitung array keberapa data yang ditemukan sama
    long long int NIM[20]; //Untuk searching NIM
    for(i = 0; i < data_index; i++) //Dari i = 0 sampai kurang dari data_index
    {
        sscanf(mahasiswa[i].nim, "%lld", &NIM[i]); //Convert String NIM ke Long Long Int NIM
    }
    //Linear Searching (Lihat rumus di baris 688)
    for(n = 0; n < data_index; n++) //Dari n = 0 sampai kurang dari data_index
    {
        if(NIM[n] == *cari) //Jika NIM array ke n sama dengan cari, maka
        {
            return n; //Kembalikan angka n ke dimana fungsi dipangil
        }
    }
    return -1; //Kembalikan angka -1 ke dimana fungsi dipanggil, hal ini akan dilakukan jika data tidak ada yang sama atau tidak ditemukan
}
//Simpan Data
void simpan_data()
{
    FILE *pf; //Pointer File Lokal
    //Variabel Lokal
    int i; //Untuk batas awal For
    pf = fopen("data.txt", "w"); //Membuka file dengan mode write
    for(i = 0; i < data_index; i++) //Pengulangan dari 0 sampai < data_index
    {
        fprintf(pf, "%s# %s\n", mahasiswa[i].nama, mahasiswa[i].nim); //Menulis struct mahasiswa kedalam file
    }
    fclose(pf); //Menutup pointer file pf
    printf("Data berhasil disimpan!");
    getch(); //Memberi jeda sampai user menekan sembarang tombol
    clrscr(); //Membersihkan layar console
    menu(); //Memanggil fungsi menu
}
/****************************************************
 * EOP (End OF Program)
 * 
 * Side note
 * 
 * Jika anda merasa ingin menjadi collaborator
 * Silahkan hubungi pembuat code...
 * 
 * Sekian, Terima kasih
 * 
 * Created at 14/01/2020
 * Update:
 * 1st Revision at 15/01/2020
 * 2nd Revision at 16/01/2020
 * 1st Release at 18/03/2020 (v.0.1-Alpha)
 * 1st Release 1st Revision (v.0.1.1-Alpha)
 ****************************************************/