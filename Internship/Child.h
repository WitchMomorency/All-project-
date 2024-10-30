#ifndef CHILD_H_INCLUDED
#define CHILD_H_INCLUDED
#include <iostream>
using namespace std;

struct mahasiswa{
    string NIM_mahasiswa, nama_mahasiswa;
    int sum_joinIntern;
};

typedef struct mahasiswa infotypeMahasiswa;
typedef struct elmMahasiswa *adrMahasiswa;

struct elmMahasiswa{
    adrMahasiswa next;
    adrMahasiswa prev;
    infotypeMahasiswa info;
};

struct listMahasiswa{
    adrMahasiswa First;
    adrMahasiswa Last;
};

void createListMahasiswa(listMahasiswa &LM);
adrMahasiswa alokasi_Mahasiswa(infotypeMahasiswa x); // Point b
adrMahasiswa findMahasiswa(listMahasiswa LM, string NIM);
void insertLastMahasiswa(listMahasiswa &LM, adrMahasiswa m);
void showListMahasiswa(listMahasiswa LM);


#endif // CHILD_H_INCLUDED
