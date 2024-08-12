/* Program   : mainListCircular.c */
/* Deskripsi : file DRIVER modul List Circular */
/* NIM/Nama  : 24060120130080/Adiba Justinian */
/* Tanggal   : 16 November 2021 */
/***********************************/

#include <stdio.h>
#include "ListCircular.h"

int main()
{

    //Kamus Global
    List S, T;
    address A, B, C, D, E, F;
    int X;

    //Algoritma
    printf("=======Create List S=======\n");
    CreateList(&S);


    printf("\n-------List Empty-----\n");
    if (ListEmpty(S))
    {
        printf ("List kosong");
    }
    else
    {
        printf ("List tidak kosong");
    }


    A = Alokasi(1);
    printf("\n\n-------Insert First-----\n");
    InsertFirst(&S, A);
    PrintInfo(S);

    B = Alokasi(2);
    printf("\n-------Insert After-----\n");
    InsertAfter(&S, B, A);
    PrintInfo(S);

    C = Alokasi(3);
    printf("\n-------Insert After-----\n");
    InsertAfter(&S, C, B);
    PrintInfo(S);

    D = Alokasi(4);
    printf("\n-------Insert After-----\n");
    InsertAfter(&S, D, C);
    PrintInfo(S);

    E = Alokasi(5);
    printf("\n-------Insert Last-----\n");
    InsertLast(&S, E);
    PrintInfo(S);

    F = Alokasi(6);
    printf("\n-------Insert Last-----\n");
    InsertLast(&S, F);
    PrintInfo(S);


    printf("\n-------List Empty-----\n");
    if (ListEmpty(S))
    {
        printf ("List kosong");
    }
    else
    {
        printf ("List tidak kosong");
    }


    printf("\n\n-------Delete First-----\n");
    DelFirst(&S, &A);
    PrintInfo(S);


    printf("\n-------Delete Last-----\n");
    DelLast(&S, &F);
    PrintInfo(S);


    printf("\n-------Delete After-----\n");
    DelAfter(&S, &D, C);
    PrintInfo(S);


    printf("\n\n=======Create List T=======\n");
    CreateList(&T);


    printf("\n-------InsVFirst-----\n");
    InsVFirst(&T, 240);
    PrintInfo(T);

    printf("\n-------InsVLast-----\n");
    InsVLast(&T, 300);
    PrintInfo(T);

    printf("\n-------InsVAfter-----\n");
    InsVAfter(&T, 601, 240);
    PrintInfo(T);

    printf("\n-------InsVAfter-----\n");
    InsVAfter(&T, 201, 601);
    PrintInfo(T);

    printf("\n-------InsVLast-----\n");
    InsVLast(&T, 80);
    PrintInfo(T);


    printf("\n-------DelVFirst-----\n");
    DelVFirst(&T, &X);
    PrintInfo(T);

    printf("\n-------DelVLast-----\n");
    DelVLast(&T, &X);
    PrintInfo(T);

    printf("\n-------DelVAfter-----\n");
    DelVAfter(&T, &X, 601);
    PrintInfo(T);

    printf("\n-------DelVLast-----\n");
    DelVLast(&T, &X);
    PrintInfo(T);

    printf("\n-------DelVFirst-----\n");
    DelVFirst(&T, &X);
    PrintInfo(T);


    printf("\n\nNb Elmt List S : %d", NbElmt(S));

    printf("\n\nNb Elmt List T : %d\n", NbElmt(T));


    return 0;

}
