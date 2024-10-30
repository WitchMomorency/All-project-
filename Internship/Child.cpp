#include "Child.h"

void createListMahasiswa(listMahasiswa &LM){
    LM.First = NULL;
    LM.Last = NULL;
}
adrMahasiswa alokasi_Mahasiswa(infotypeMahasiswa x){
    adrMahasiswa m;
    m = new elmMahasiswa;
    m->info = x;
    m->info.sum_joinIntern = 0;
    m->next = NULL;
    m->prev = NULL;

    return m;
}
adrMahasiswa findMahasiswa(listMahasiswa LM, string NIM){
    adrMahasiswa m = LM.First;

    while(m != NULL && m->info.NIM_mahasiswa != NIM){
        m = m->next;
    }
    if(m != NULL && m->info.NIM_mahasiswa == NIM){
        return m;
    }else{
        cout << "Data Mahasiswa Tidak Ada" << endl;
        return NULL;
    }
}
void insertLastMahasiswa(listMahasiswa &LM, adrMahasiswa m){
    if(LM.First == NULL && LM.Last == NULL){
        LM.First = m;
        LM.Last = m;
    }else{
        m->prev = LM.Last;
        LM.Last->next = m;
        LM.Last = m;
    }
}
void showListMahasiswa(listMahasiswa LM){
    adrMahasiswa m = LM.First;

    while(m != NULL){
        cout << "Nama Mahasiswa:" << m->info.nama_mahasiswa << " NIM:" << m->info.NIM_mahasiswa << " <-> ";
        m = m->next;
    }
    cout << endl;
}
