#include "Parent.h"

void createListInternship(ListInternship &LI){
    LI.First = NULL;
}
adrInternship alokasi_Internship(infotypeInternship x){
    adrInternship I;
    I = new elmInternship;
    I->info = x;
    I->info.sum_mahasiswaJoined = 0;
    I->next = NULL;
    I->FirstRelasi = NULL;

    return I;
}
adrInternship findInternship(ListInternship LI, string perusahaan){
    adrInternship I = LI.First;

    while(I != NULL && I->info.nama_perusahaan != perusahaan){
        I = I->next;
    }
    if(I != NULL && I->info.nama_perusahaan == perusahaan){
        return I;
    }else{
        cout << "Data Perusahaan Tidak Ada" << endl;
        return NULL;
    }
}
void insertLastInternship(ListInternship &LI, adrInternship i){
    adrInternship last;

    if(LI.First != NULL){
        last = LI.First;
        while(last->next != NULL){
            last = last->next;
        }
        last->next = i;
    }else{
        LI.First = i;
    }
}
void connectRelasi(ListInternship &LI, listMahasiswa &LM){
    adrInternship I;
    adrMahasiswa M;
    adrRelasi R;
    string perusahaan, nim;

    cout << "Inputkan Nama Perusahaan: ";
    cin >> perusahaan;
    cout << "Inputkan NIM Mahasiswa: ";
    cin >> nim;
    cout << endl;

    I = findInternship(LI, perusahaan);
    M = findMahasiswa(LM, nim);

    if(I == NULL || M == NULL){
        return;
    }else if (M->info.sum_joinIntern >= 3) {
        cout << "Mahasiswa sudah mengikuti 3 internship" << endl;
        return;
    }


    if (M->info.sum_joinIntern >= 3) {
        cout << "Mahasiswa sudah mengikuti 3 internship" << endl;
        return;
    }

    R = new elmRelasi;
    R->info = M;

    if(I->FirstRelasi == NULL){
        I->FirstRelasi = R;
        R->next = I->FirstRelasi;
        I->info.sum_mahasiswaJoined++;
        M->info.sum_joinIntern++;

    }else{
        adrRelasi last_R = I->FirstRelasi;
        while(last_R->next != I->FirstRelasi){
            last_R = last_R->next;
        }
        R->next = I->FirstRelasi;
        I->FirstRelasi = R;
        last_R->next = I->FirstRelasi;
        I->info.sum_mahasiswaJoined++;
        M->info.sum_joinIntern++;
    }
}
void deleteInternship(ListInternship &LI, adrInternship P, listMahasiswa &LM){
    adrInternship before_p, last;
    adrRelasi r;

    before_p = LI.First;
    last = LI.First;

    while(last->next != NULL){
            last = last->next;
        }

    if(P == LI.First){ //delete first
        LI.First = P->next;
        if(P->FirstRelasi != NULL){
            r = P->FirstRelasi;
            while(r->next != P->FirstRelasi){
                r->info->info.sum_joinIntern--;
                r = r->next;
            }
            r->info->info.sum_joinIntern--;
        }

        P = NULL;

    }else if(P == last){ // delete last
        while(before_p->next != P){
            before_p = before_p->next;
        }
        if(P->FirstRelasi != NULL){
            r = P->FirstRelasi;
            while(r->next != P->FirstRelasi){
                r->info->info.sum_joinIntern--;
                r = r->next;
            }
            r->info->info.sum_joinIntern--;
        }
        before_p->next = NULL;
        P = NULL;

    }else{ //delete middle
        while(before_p->next != P){
            before_p = before_p->next;
        }
        if(P->FirstRelasi != NULL){
            r = P->FirstRelasi;
            while(r->next != P->FirstRelasi){
                r->info->info.sum_joinIntern--;
                r = r->next;
            }
            r->info->info.sum_joinIntern--;
        }
        before_p->next = P->next;
        P = NULL;
    }
}
void removeRelasiMahasiswa(ListInternship &LI, listMahasiswa &LM){
    adrInternship I;
    adrMahasiswa M;
    adrRelasi r, last, before_r;
    string perusahaan, nim;

    cout << "Nama Perusahaan: ";
    cin >> perusahaan;
    cout << "NIM Mahasiswa: ";
    cin >> nim;

    I = findInternship(LI, perusahaan);

    M = findMahasiswa(LM, nim);

    if(I != NULL){

        last = I->FirstRelasi;
        while(last->next != I->FirstRelasi){
            last = last->next;
        }

        r = I->FirstRelasi;
        while(r->next != I->FirstRelasi && r->info->info.NIM_mahasiswa != nim){ //mencari relasi mahasiswa -> internship
            r = r->next;
        }
        if(r == I->FirstRelasi && r->info->info.NIM_mahasiswa == nim){ //jika di relasi pertama
            if(r->next == I->FirstRelasi){
                r->info = NULL;
                r->next = NULL;
                I->FirstRelasi = NULL;
                M->info.sum_joinIntern--;
                I->info.sum_mahasiswaJoined--;
            }else{
                I->FirstRelasi = r->next;
                r->info = NULL;
                last->next = I->FirstRelasi;
                M->info.sum_joinIntern--;
                I->info.sum_mahasiswaJoined--;
            }
        }else if(r == last && r->info->info.NIM_mahasiswa == nim){ //jika di relasi terakhir (AMAN)
            before_r = I->FirstRelasi;

            while(before_r->next != r){
                before_r = before_r->next;
            }
            r->info = NULL;
            r->next = NULL;
            before_r->next = I->FirstRelasi;
            M->info.sum_joinIntern--;
            I->info.sum_mahasiswaJoined--;

        }else if(r != I->FirstRelasi && r != last && r->info->info.NIM_mahasiswa == nim){ //Jika data ditengah (AMAN)
            before_r = I->FirstRelasi;

            while(before_r->next != r){
                before_r = before_r->next;
            }
            r->info = NULL;
            before_r->next = r->next;
            r->next = NULL;
            M->info.sum_joinIntern--;
            I->info.sum_mahasiswaJoined--;
        }else{
            cout << "Mahasiswa Tersebut Tidak Mengikuti Internship Dari Perusahaan " << perusahaan << endl; //(AMAN)
        }
    }else{
        cout << "Perusahaan Tidak Ditemukan" << endl;
    }
    cout << endl;
}
void showMahasiswaJoinInternship(ListInternship LI, listMahasiswa LM){
    adrInternship PP = LI.First;
    adrRelasi r;
    adrMahasiswa PC;
    string input_mahasiswa;

    cout << "Input NIM Mahasiswa: ";
    cin >> input_mahasiswa;
    PC = findMahasiswa(LM, input_mahasiswa);

    if(PP != NULL){
        while(PP != NULL){
            if(PP->FirstRelasi != NULL){
                r = PP->FirstRelasi;
                while(r->next != PP->FirstRelasi){
                    if(r->info->info.NIM_mahasiswa == input_mahasiswa){
                        cout << "Mahasiswa " << PC->info.nama_mahasiswa << " Mengikuti Internship:" << endl;
                        cout << "- " << PP->info.nama_perusahaan << endl;
                    }
                    r = r->next;
                }
                if(r->info->info.NIM_mahasiswa == input_mahasiswa){
                        cout << "Mahasiswa " << PC->info.nama_mahasiswa << " Mengikuti Internship:" << endl;
                        cout << "- " << PP->info.nama_perusahaan << endl;
                }
            }
            PP = PP->next;
        }
    }
}
void showListInternship(ListInternship LI){
    adrInternship i = LI.First;

    while(i != NULL){
        cout << "Nama Perusahaan:" << i->info.nama_perusahaan << " Nama Posisisi:" << i->info.nama_posisi << " -> ";
        i = i->next;
    }
    cout << endl;
}
void showAllRelasi(ListInternship LI, listMahasiswa LM){
    adrInternship PP;
    adrRelasi PR;
    PP = LI.First;

    if(PP != NULL){
        while(PP != NULL){
            cout << "Internship: " << PP->info.nama_perusahaan << endl;
            cout << "Mahasiswa Yang Mengikuti Internship: " << endl;
            if(PP->FirstRelasi != NULL){
                PR = PP->FirstRelasi;
                while(PR->next != PP->FirstRelasi){
                    cout << "- " << PR->info->info.nama_mahasiswa << endl;
                    PR = PR->next;
                }
                cout << "- " << PR->info->info.nama_mahasiswa << endl;
                cout << endl;
            }else{
                cout << "Tidak Ada Data Mahasiswa" << endl;
                cout << endl;
            }
            PP = PP->next;
        }

    }else{
        cout << "Tidak Ada Data Internship" << endl;
    }
}
