#ifndef PARENT_H_INCLUDED
#define PARENT_H_INCLUDED
#include <iostream>
#include "Child.h"

using namespace std;

struct internship{
    string nama_perusahaan, nama_posisi;
    int sum_mahasiswaJoined;
};

typedef struct internship infotypeInternship;
typedef struct elmInternship *adrInternship;
typedef struct elmRelasi *adrRelasi;

struct elmInternship{
    adrInternship next;
    infotypeInternship info;
    adrRelasi FirstRelasi;
};

struct elmRelasi{
    adrRelasi next;
    adrMahasiswa info;
};

struct ListInternship{
    adrInternship First;
};

void createListInternship(ListInternship &LI);
adrInternship alokasi_Internship(infotypeInternship x); // Point a
adrInternship findInternship(ListInternship LI, string perusahaan); //Point c
void insertLastInternship(ListInternship &LI, adrInternship i);
void connectRelasi(ListInternship &LI, listMahasiswa &LM); //Point d
void deleteInternship(ListInternship &LI, adrInternship P, listMahasiswa &LM); //Point f
void removeRelasiMahasiswa(ListInternship &LI, listMahasiswa &LM);
void showMahasiswaJoinInternship(ListInternship LI, listMahasiswa LM);
void showListInternship(ListInternship LI);
void showAllRelasi(ListInternship LI, listMahasiswa LM); //Point h


#endif // PARENT_H_INCLUDED
