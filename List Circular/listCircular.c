/* Program   : listCircular.c */
/* Deskripsi : file BODY modul List Circular */
/* NIM/Nama  : 24060120130080/Adiba Justinian */
/* Tanggal   : 16 November 2021 */
/***********************************/

#ifndef listCircular_C
#define listCircular_C
#include "listCircular.h"
#include <stdio.h>
#include <stdlib.h>

/* ----- Test List Kosong ----- */
boolean ListEmpty (List L)
/* Mengirim true jika list kosong */
{
    //Kamus Lokal


    //Algoritma
    if(First(L) == Nil)
    {
        return true;
    }
    else
    {
        return false;
    }

}

/* ----- Pembuatan List Kosong ----- */
void CreateList (List *L)
/* I.S.		: sembarang
   F.S.		: Terbentuk list kosong */
{
    //Kamus Lokal


    //Algoritma
    First(*L) = Nil;

}

/* ----- Manajemen Memori ----- */
address Alokasi (infotype X)
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak Nil,
   dan misalnya menghasilkan P, maka
   Info(P) = X, Next(P) = Nil
   Jika alokasi gagal, mengirimkan Nil */
{
    //Kamus Lokal
    address P;

    //Algooritma
    P = (address) malloc(sizeof(ElmtList));
    if(P != Nil )
    {
        info(P) = X;
        next(P) = Nil;
        return P;
    }
    else
    {
        return Nil;
    }

}

void Dealokasi (address *P)
/* I.S.		: P terdefinisi
   F.S.		: P dikembalikan ke sistem
   Melakukan dealokasi/pengembalian address P */

/* ----- Primitif Berdasarkan Alamat ------ */
{
    //Kamus Lokal


    //Algoritma
    free(*P);

}

/* Penambahan Elemen Berdasarkan Alamat */
void InsertFirst (List *L, address P)
/* I.S. 	: Sembarang, P sudah dialokasi
   F.S.		: Menambahkan elemen ber-address P sebagai elemen pertama */
{
    //Kamus Lokal
    address A;

    //Algoritma
    if(ListEmpty(*L))
    {
        First(*L) = P;
        next(P) = First(*L);
    }
    else
    {
        A = First(*L);
        while(next(A) != First(*L))
        {
            A = next(A);
        }
        next(P) = First(*L);
        First(*L) = P;
        next(A) = First(*L);
    }

}

void InsertAfter (List *L, address P, address Prec)
/* I.S.		: Prec pastilah elemen list dan bukan elemen terakhir,
			  P sudah dialokasi
   F.S. 	: Insert P sebagai elemen sesudah elemen beralamat Prec */
{
    //Kamus Lokal


    //Algoritma
    if(ListEmpty(*L))
    {
        InsertFirst(&(*L), P);
    }
    else
    {
        next(P) = next(Prec);
        next(Prec) = P;
    }

}

void InsertLast (List *L, address P)
/* I.S.		: Sembarang, P sudah dialokasi
   F.S.		: P ditambahkan sebagai elemen terakhir yang baru */
{
    //Kamus Lokal
    address Last;

    //Algoritma
    if(ListEmpty(*L))
    {
        InsertFirst(&(*L), P);
    }
    else
    {
        Last = First(*L);
        while(next(Last) != First(*L))
        {
            Last = next(Last);
        }
        next(Last) = P;
        next(P) = First(*L);
    }

}

/* Penghapusan Sebuah Elemen */
void DelFirst (List *L, address *P)
/* I.S.     : List tidak kosong
   F.S.     : P adalah alamat elemen pertama list sebelum penghapusan
              Elemen list berkurang satu (mungkin menjadi kosong)
              First element yang baru adalah suksesor elemen pertama yang
              lama */
{
    //Kamus Lokal
    address Last;

    //Algoritma
    (*P) = First(*L);
    if(next(*P) != First(*L))
    {
        Last = First(*L);
        while(next(Last) != First(*L))
        {
            Last = next(Last);
        }
        First(*L) = next(*P);
        next(Last) = First(*L);
    }
    else
    {
        First(*L) = Nil;
    }

}

void DelLast (List *L, address *P)
/* I.S.     : List tidak kosong
   F.S.     : P adalah alamat elemen terakhir list sebelum penghapusan
              Elemen list berkurang satu (mungkin menjadi kosong)
              Last element baru adalah predesesor elemen pertama yang
              lama, jika ada */
{
    //Kamus Lokal
    address Last;
    address Prec;

    //Algoritma
    Last = First(*L);
    Prec = Nil;
    while(next(Last) != First(*L))
    {
        Prec = Last;
        Last = next(Last);
    }
    (*P) = Last;
    if(Prec == Nil)
    {
        First(*L) = Nil;
    }
    else
    {
        next(Prec) = First(*L);
    }

}

void DelAfter (List *L, address * Pdel, address Prec)
/* I.S.     : List tidak kosong. Prec adalah anggota list L.
   F.S.     : Menghapus Next(Prec) :
              Pdel adalah alamat elemen list yang dihapus */
{
    //Kamus Lokal


    //Algoritma
    (*Pdel) = next(Prec);
    next(Prec) = next(next(Prec));
    next(*Pdel) = Nil;

}


/* ----- Primitif Berdasarkan Nilai ----- */
/* Penambahan Elemen */
void InsVFirst (List *L, infotype X)
/* I.S.		: L mungkin kosong
   F.S. 	: X ditambahkan sebagai elemen pertama L
   Proses 	: Melakukan alokasi sebuah elemen dan menambahkan elemen
   			  pertama dengan nilai X jika alokasi berhasil.
   			  Jika alokasi gagal, maka I.S.= F.S. */
{
    //Kamus Lokal
    address P;

    //Algoritma
    P = Alokasi(X);
    if(P != Nil)
    {
        InsertFirst(&(*L), P);
    }

}

void InsVLast (List *L, infotype X)
/* I.S. 	: L mungkin kosong
   F.S.		: X ditambahkan sebagai elemen terakhir L
   Proses 	: Melakukan alokasi sebuah elemen dan menambahkan elemen list
   			  di akhir yaitu
   			  jika alokasi berhasil, elemen terakhir yang baru bernilai X
   			  Jika alokasi gagal, maka I.S.= F.S. */
{
    //Kamus Lokal
    address P;

    //Algoritma
    P = Alokasi(X);
    if(P != Nil)
    {
        InsertLast(&(*L), P);
    }

}

void InsVAfter (List *L, infotype X, infotype Xprec)
/* I.S. 	: L mungkin kosong
   F.S.		: X ditambahkan sebagai elemen setelah Prec
   Proses 	: Melakukan alokasi sebuah elemen dan menambahkan elemen list
   			  setelah Prec yaitu
   			  jika alokasi berhasil, elemen setelah Prec yang baru bernilai X
   			  Jika alokasi gagal, maka I.S.= F.S. */
{
    //Kamus Lokal
    address P;
    address Prec;

    //Algoritma
    P = Alokasi(X);
    Prec = First(*L);
    if(info(Prec) == Xprec)
    {
        InsertAfter(&(*L), P, Prec);
    }
    else
    {
        while(info(Prec) != Xprec && next(Prec) != Nil)
        {
            Prec = next(Prec);
            if(info(Prec) == Xprec)
            {
                InsertAfter(&(*L), P, Prec);
            }
        }
    }

}

void AdrLast(List *L, address *Prec, address *Last)
/*mencari alamat elemen terakhir dan sebelumnya*/
{
    //Kamus Lokal


    //Algoritma
    if(!ListEmpty(*L))
    {
        (*Last) = First(*L);
        (*Prec) = Nil;
        while(next(*Last) != First(*L))
        {
            (*Prec) = (*Last);
            (*Last) = next(*Last);
        }
    }
    else
    {
        (*Prec) = Nil;
        (*Last) = Nil;
    }

}

/* Penghapusan ELemen */
void DelVFirst (List *L, infotype *X)
/* I.S.		: List L tidak kosong
   F.S.		: Elemen pertama list dihapus den nilai info disimpan pada X
   			 dan alamat elemen pertama di-dealokasi */
{
    //Kamus Lokal
    address P;

    //Algoritma
    DelFirst(&(*L), &P);
    (*X) = info(P);
    next(P) = Nil;
    Dealokasi(&P);

}


void DelVLast (List *L, infotype *X)
/* I.S.		: List L tidak kosong
   F.S.		: Elemen terakhir list dihapus : nilai info disimpan pada X
   			  dan alamat elemen terakhir di-dealokasi */
{
    //Kamus Lokal
    address P;
    address Prec;

    //Algoritma
    AdrLast(&(*L), &Prec, &P);
    (*X) = info(P);
    if(Prec == Nil)
    {
        First(*L) = Nil;
    }
    else
    {
        next(Prec) = First(*L);
    }
    Dealokasi(&P);

}

void DelVAfter (List *L, infotype *X, infotype Xprec)
/* I.S.		: List L tidak kosong
   F.S.		: Elemen list setelah Prec dihapus : nilai info disimpan pada X
   			  dan alamat elemen setelah Prec di-dealokasi */
{
    //Kamus Lokal
    address P;
    address Prec;

    //Algoritma
    P = First(*L);
    while(info(P) != Xprec && next(P) != First(*L))
    {
        P = next(P);
    }
    if(info(P) == Xprec)
    {
        (*X) = info(P);
        DelAfter(&(*L), &Prec, P);
        Dealokasi(&Prec);
    }

}

/* ----- Proses Semua Elemen List ----- */
void PrintInfo (List L)
/* I.S.     : List mungkin kosong
   F.S.     : Jika list tidak kosong, semua info yg disimpan pada elemen
              list diprint
              Jika list kosong, hanya menuliskan "list kosong" */
{
    //Kamus Lokal
    address P;

    //Algoritma
    P = First(L);
    if(!ListEmpty(L))
    {
        while(next(P) != First(L))
        {
            printf("%d ", info(P));
            P = next(P);
        }
        printf("%d ", info(P));
        printf("\n");
    }
    else
    {
        printf("List Kosong");
    }

}

int NbElmt (List L)
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */
{
    //Kamus Lokal
    address P;
    int i;

    //Algoritma
    if(ListEmpty(L))
    {
        i = 0;
    }
    else
    {
        i = 1;
        P = First(L);
        while(next(P) != First(L))
        {
            i++;
            P = next(P);
        }
    }
    return i;

}



#endif
