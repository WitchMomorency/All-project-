#include <iostream>
#include "Parent.h"
using namespace std;

int main(){

    listMahasiswa LM;
    ListInternship LI;
    adrMahasiswa m;
    adrInternship i, adrIntership_favorit;
    adrRelasi pointerRelasi;
    infotypeMahasiswa x;
    infotypeInternship y;

    /* Bagian Tambahan*/
    string namaperusahaan;

    string input_delete, in;
    int favorit, input_internship, iterasi;

    createListMahasiswa(LM);
    createListInternship(LI);

    int pilihan = -1;

    while (pilihan != 0) {
        cout << "Menu Program: \n";
        cout << "1. Input Parent (Perusahaan dan Posisi Internship) \n";
        cout << "2. Input Child (Mahasiswa) \n";
        cout << "3. Cari Internship \n";
        cout << "4. Hubungkan Relasi \n";
        cout << "5. Tampilkan Mahasiswa dari Internship Tertentu \n";
        cout << "6. Hapus Parent \n";
        cout << "7. Hapus Relasi Mahasiswa \n";
        cout << "8. Tampilkan Semua Internship \n";
        cout << "9. Tampilkan Semua Child \n";
        cout << "10. Tampilkan Semua Relasi \n";
        cout << "11. Tampilkan Jumlah Mahasiswa pada Internship \n";
        cout << "12. Tampilkan Internship Paling Favorit \n";
        cout << "0. Keluar \n";
        cout << "Masukkan pilihan Anda: ";
        cin >> pilihan;

        switch(pilihan) {
            case 1:
                    cout << "Nama Perusahaan : " ;
                    cin >> y.nama_perusahaan;
                    cout << "Posisi atau Jabatan : ";
                    cin >> y.nama_posisi;
                    insertLastInternship(LI, alokasi_Internship(y));
                    cout << endl;
                break;
            case 2:
                cout << "Nama Mahasiswa : ";
                cin >> x.nama_mahasiswa;
                cout << "NIM Mahasiswa : ";
                cin >> x.NIM_mahasiswa;
                insertLastMahasiswa(LM, alokasi_Mahasiswa(x));
                cout << endl;
                break;
            case 3:
                cout << "Nama Perusahaan : ";
                cin >> namaperusahaan;
                i = findInternship(LI, namaperusahaan);
                cout <<"Nama Perusahaan: " << i->info.nama_perusahaan << endl << "Posisi: " << i->info.nama_posisi << endl;
                break;
            case 4:
                connectRelasi(LI, LM);
                break;
            case 5:
                cout << endl;
                showMahasiswaJoinInternship(LI, LM);
                cout << endl;
                break;
            case 6:
                cout << endl;
                cout << "Nama Perusahaan Yang Ingin Dihapus : ";
                cin >> namaperusahaan;
                i = findInternship(LI,namaperusahaan);
                deleteInternship(LI, i, LM);
                cout << endl;
                break;
            case 7:
                removeRelasiMahasiswa(LI, LM);
                break;
            case 8:
                i = LI.First;
              while(i != NULL){
                  cout << endl;
                  cout << "Nama Perusahaan: " << i->info.nama_perusahaan << endl << "Posisi: " << i->info.nama_posisi << endl << "Total Mahasiswa Bergabung: " << i->info.sum_mahasiswaJoined << endl;;
                  i = i ->next;
                }
              cout << endl;
                break;
            case 9:
                m = LM.First;
                while(m->next != NULL){
                    cout << endl;
                    cout << "Nama Mahasiswa: " << m->info.nama_mahasiswa << endl << "NIM Mahasiswa: " << m->info.NIM_mahasiswa << endl << "Total Internship Yang Diikuti: " << m->info.sum_joinIntern << endl;
                    m = m->next;
                }
                    cout << endl;
                    cout << "Nama Mahasiswa: " << m->info.nama_mahasiswa << endl << "NIM Mahasiswa: " << m->info.NIM_mahasiswa << endl << "Total Internship Yang Diikuti: " << m->info.sum_joinIntern << endl;
                    cout << endl;
                break;
            case 10:
                showAllRelasi(LI, LM);
                break;
            case 11:
                cout << "Masukan Nama Perusahaan: ";
                cin >> namaperusahaan;
                i = findInternship(LI, namaperusahaan);
                cout << "Mahasiswa Yang Mengikuti Internship Di Perusahaan " << i->info.nama_perusahaan << " Berjumlah " <<i->info.sum_mahasiswaJoined <<" Orang" << endl;
                break;
            case 12:
                i = LI.First;
                favorit = 0;
                while(i != NULL){
                    if(i->info.sum_mahasiswaJoined > favorit){
                        favorit = i->info.sum_mahasiswaJoined;
                        adrIntership_favorit = i;
                    }
                    i = i->next;
                }
                cout <<"Intership Ter-Favorit Adalah: " << adrIntership_favorit->info.nama_perusahaan <<" Dengan " << adrIntership_favorit->info.sum_mahasiswaJoined << " Mahasiswa" << endl;
                break;
            case 0:
                cout << "Terima kasih telah menggunakan program ini. \n";
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi. \n";
        }
    }

    return 0;
}


