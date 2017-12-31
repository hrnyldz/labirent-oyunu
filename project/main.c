#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 45

int dizi[N][N];
int sayac=0;

struct matris
{
    int x_koordinat;
    int y_koordinat;
    struct matris *ileri;
};

struct matris *isaretci;
struct matris *ilk;

struct matris* cikarma(struct matris *isaretci);
struct matris* yol_bulma(int x_baslangic,int y_baslangic,int x_bitis,int y_bitis,int matris_boyut);
struct matris* ekleme(struct matris *isaretci,int satir,int sutun);

struct matris* cikarma(struct matris *isaretci){
    if(sayac>1)
    {
        if(sayac>2)
        {
            while(isaretci->ileri->ileri!=NULL)
            {
                isaretci=isaretci->ileri;
            }
        }
        dizi[isaretci->ileri->x_koordinat][isaretci->ileri->y_koordinat]=0;
        isaretci->ileri=NULL;
        free(isaretci->ileri);
        sayac--;
    }
    return isaretci;
}


struct matris* yol_bulma(int x_baslangic,int y_baslangic,int x_bitis,int y_bitis,int matris_boyut)
{
    struct matris *dugum;
    struct matris *geri;
    dugum=malloc(sizeof(struct matris));
    isaretci=dugum;
    isaretci->x_koordinat=x_baslangic;
    isaretci->y_koordinat=y_baslangic;
    ilk=isaretci;
    dizi[x_baslangic][y_baslangic]=2;
    isaretci->ileri=NULL;
    sayac++;
    while(1)
    {
        geri=dugum;
        if(sayac==1)
        {
            geri=NULL;
        }
        else if(sayac==3)
        {
            geri=dugum->ileri;
        }
        else if(sayac >3)
        {
            do
            {
                geri=geri->ileri;
            }
            while(geri->ileri->ileri==NULL);
        }

        if(isaretci->x_koordinat==x_bitis && isaretci->y_koordinat==y_bitis)
        {
            break;
        }
        else if(isaretci->y_koordinat!=0 && dizi[isaretci->x_koordinat][isaretci->y_koordinat-1]==1 )
        {
            if(geri==NULL)
            {
                isaretci=ekleme(isaretci,isaretci->x_koordinat,isaretci->y_koordinat-1);
            }
            else if(isaretci->x_koordinat!=geri->x_koordinat || isaretci->y_koordinat-1!=geri->y_koordinat)
            {
                isaretci=ekleme(isaretci,isaretci->x_koordinat,isaretci->y_koordinat-1);
            }
        }
        else if(isaretci->y_koordinat!=matris_boyut-1 && dizi[isaretci->x_koordinat][isaretci->y_koordinat+1]==1 )
        {
            if(geri==NULL)
            {
                isaretci=ekleme(isaretci,isaretci->x_koordinat,isaretci->y_koordinat+1);
            }
            else if(isaretci->x_koordinat!=geri->x_koordinat || isaretci->y_koordinat+1!=geri->y_koordinat)
            {
                isaretci=ekleme(isaretci,isaretci->x_koordinat,isaretci->y_koordinat+1);
            }
        }
                else if(isaretci->x_koordinat!=0 && dizi[isaretci->x_koordinat-1][isaretci->y_koordinat]==1 )
        {
            if(geri==NULL)
            {
                isaretci=ekleme(isaretci,isaretci->x_koordinat-1,isaretci->y_koordinat);
            }
            else if(isaretci->x_koordinat-1!=geri->x_koordinat || isaretci->y_koordinat!=geri->y_koordinat)
            {
                isaretci=ekleme(isaretci,isaretci->x_koordinat-1,isaretci->y_koordinat);
            }
        }


                else if(isaretci->x_koordinat!=matris_boyut-1 && dizi[isaretci->x_koordinat+1][isaretci->y_koordinat]==1 )
        {
            if(geri==NULL)
            {
                isaretci=ekleme(isaretci,isaretci->x_koordinat+1,isaretci->y_koordinat);
            }
            else if(isaretci->x_koordinat+1!=geri->x_koordinat || isaretci->y_koordinat!=geri->y_koordinat)
            {
                isaretci=ekleme(isaretci,isaretci->x_koordinat+1,isaretci->y_koordinat);
            }
        }
        else if(isaretci->x_koordinat==x_baslangic && isaretci->y_koordinat==y_baslangic)
        {
            return NULL;
        }
        else
        {
            isaretci=cikarma(dugum);
        }
    }
    return dugum;
}
struct matris* ekleme(struct matris *isaretci,int satir,int sutun)
{
    struct matris *gecici;
    gecici=malloc(sizeof(struct matris));
    isaretci->ileri=gecici;
    gecici->x_koordinat=satir;
    gecici->y_koordinat=sutun;
    gecici->ileri=NULL;
    dizi[satir][sutun]=2;
    sayac++;
    return gecici;
}
int main()

{   int n;
    system("COLOR 0A");

     printf("Labirent oyunu icin matris olusturulacaktir...:)\n");

    do{
    printf("nxn lik matrisin n degerini giriniz.(maximum 45)");
    scanf("%d",&n);
    }
    while(n<1||n>45);
    int i,j;
    int rastgele;
    srand(time(NULL));

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            rastgele=rand()%2;
            dizi[i][j]=rastgele;
            printf("%d ",rastgele);
        }
        printf("\n");
    }
    int sifir_dizi[n][n];
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            sifir_dizi[i][j]=0;
        }
    }
    int baslangic_x,baslangic_y,bitis_x,bitis_y;
    do{
    printf("Girisin x koordinatini giriniz : ");
    scanf("%d",&baslangic_x);
    }
    while(baslangic_x<0||baslangic_x>n-1);


    do{
    printf("Girisin y koordinatini giriniz : ");
    scanf("%d",&baslangic_y);
    }
    while(baslangic_y<0||baslangic_y>n-1);

    do{
    printf("Cikisin x koordinatini giriniz : ");
    scanf("%d",&bitis_x);
    }
    while(bitis_x<0||bitis_x>n-1);

    do{
    printf("Cikisin y koordinatini giriniz : ");
    scanf("%d",&bitis_y);
    }
    while(bitis_y<0||bitis_y>n-1);

    if(yol_bulma(baslangic_x,baslangic_y,bitis_x,bitis_y,n)==NULL)
        printf("Labirentte yol yoktur");
    else{
        printf("Labirent Yolu\n");
        while(ilk!=NULL){
            sifir_dizi[ilk->x_koordinat][ilk->y_koordinat]=1;
            ilk=ilk->ileri;
        }
    int i,j;
    for(i=0;i<n;i++){
         for(j=0;j<n;j++){
            printf("%d ",sifir_dizi[i][j]);
        }
        printf("\n");
    }
        }
    return 0;
}
