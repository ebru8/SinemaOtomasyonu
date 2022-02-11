#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sifre()
{
    printf("lutfen sifreyi giriniz:\n");
    char sifre[20]="ebrugenc";
    FILE *fp1;
    fp1=fopen("sifre.txt","r+");
    int a;
    char girilensifre[20];
    scanf("%s",girilensifre);
    a= strcmp(sifre,girilensifre);
    if(a==0)
        printf("sifreyi dogru girdiniz.\n");
    else
       {
         printf("sifreyi yanlis girdiniz.\n");
         exit(0);
       }
    fclose(fp1);
}
typedef enum
{
    ogrencibilet=1,
    tam
}ucretler;
typedef struct
{
    char Red  [5][50];
    char Blue [5][50];
    char Green[5][50];
}salonlar;
int main()
{
    printf("merhaba, sinema otomasyon sistemine hos geldiniz.\n");
    sifre();
    salonlar salon;
    ucretler ucret;
    int hasilat;
    int koltuksayaci=0;
    FILE *fp5;
    fp5=fopen("hasilat.txt","r");

            fscanf(fp5,"%d",&hasilat);

    fclose(fp5);

    int menuSecimi;
    printf("Rezervasyon yapmak icin 1e, hasilati ogrenmek icin 2ye, izlenme sayisini ogrenmek icin 3e basiniz.\n");
    scanf("%d",&menuSecimi);
    char salonsecimi;
    int matine;
    salonlar *psalon;
    psalon = &salon;
    int i,j,k;
    int koltuknum=0;
    int odemesekli;
    int tutar=0;

    FILE *fp2;
    fp2=fopen("koltukred.txt","r");
    for(j=0;j<5;j++)
    {
        for(k=0;k<50;k++)
        {
            psalon->Red[j][k] = getc(fp2) ;
        }

    }
    fclose(fp2);

    FILE *fp3;
    fp3=fopen("koltukgreen.txt","r");
    for(j=0;j<5;j++)
    {
        for(k=0;k<50;k++)
        {
            psalon->Green[j][k] = getc(fp3) ;
        }

    }
    fclose(fp3);

    FILE *fp4;
    fp4=fopen("koltukblue.txt","r");
    for(j=0;j<5;j++)
    {
        for(k=0;k<50;k++)
        {
            psalon->Blue[j][k] = getc(fp4) ;
        }

    }
    fclose(fp4);

    switch(menuSecimi)
    {
        case 1:
            printf("\nHangi salona rezarvasyon yapmak istersiniz?\nRed icin r,Green icin g,Blue icin b\n");
            scanf(" %c",&salonsecimi);
            switch(salonsecimi)
            {
                case 'r':

                    printf("\n\nKac numarali matinede rezarvasyon yapmak istersiniz?\n1/2/3/4/5\n");
                    scanf("%d",&matine);
                    for(i=matine-1;i<matine;i++)
                    {
                        for(j=0;j<50;j++)
                        {
                            if(psalon->Red[i][j] == '0')
                            {
                                psalon->Red[i][j] = 1;
                                koltuknum = j;
                                break;
                            }
                            else
                                continue;

                        }
                    }

                    printf("\nOgrenci icin 1'e Tam icin 2'ye basin\n");
                    scanf(" %d",&odemesekli);
                    if(odemesekli == ogrencibilet )
                    {
                        tutar = 20;
                        hasilat+=tutar;
                    }
                    else if(odemesekli == tam)
                    {
                        tutar = 30;
                        hasilat+=tutar;
                    }
                    printf("\nRezarvasyon Bilgileri:\n");
                    printf("\n%d numarali koltuga rezervasyon yapilmistir.",koltuknum+1);
                    printf("\nbilet fiyati %d liradir.\n",tutar);

                    fp2=fopen("koltukred.txt","w+");
                    for(j=0;j<5;j++)
                    {
                        for(k=0;k<50;k++)
                        {
                            if(psalon->Red[j][k] == '0')
                            fputc('0',fp2);
                        else
                            fputc('1',fp2);
                        }

                    }
                    fclose(fp2);

                    fp5=fopen("hasilat.txt","w+");

                    fprintf(fp5,"%d",hasilat);

                    fclose(fp5);



                break;
                break;
                case 'g':
                    printf("\nKac numarali matinede rezarvasyon yapmak istersiniz?\n1/2/3/4/5\n");
                    scanf("%d",&matine);
                    for(i=matine-1;i<matine;i++)
                    {
                        for(j=0;j<50;j++)
                        {
                            if(psalon->Green[i][j] == '0')
                            {
                                psalon->Green[i][j] = 1;
                                koltuknum = j;
                                break;
                            }
                            else
                                continue;

                        }
                    }

                    printf("Ogrenci icin 1'e Tam icin 2'ye basin\n");
                    scanf(" %d",&odemesekli);
                    if(odemesekli == ogrencibilet )
                    {
                        tutar = 20;
                        hasilat+=tutar;
                    }
                    else if(odemesekli == tam)
                    {
                        tutar = 30;
                        hasilat+=tutar;
                    }
                    printf("\nRezarvasyon Bilgileri:\n");
                    printf("\n%d numarali koltuga rezervasyon yapilmistir.\n",koltuknum+1);
                    printf("bilet fiyati %d liradir.\n",tutar);

                    fp3=fopen("koltukgreen.txt","w+");
                    for(j=0;j<5;j++)
                    {
                        for(k=0;k<50;k++)
                        {
                            if(psalon->Green[j][k] == '0')
                            fputc('0',fp2);
                        else
                            fputc('1',fp2);
                        }

                    }
                    fclose(fp3);
                    fp5=fopen("hasilat.txt","w+");

                    fprintf(fp5,"%d",hasilat);

                    fclose(fp5);


                    break;
                    break;

                case 'b':
                    printf("\nKac numarali matinede rezarvasyon yapmak istersiniz?\n1/2/3/4/5\n");
                    scanf("%d",&matine);
                    for(i=matine-1;i<matine;i++)
                    {
                        for(j=0;j<50;j++)
                        {
                            if(psalon->Blue[i][j] == '0')
                            {
                                psalon->Blue[i][j] = 1;
                                koltuknum = j;
                                break;
                            }
                            else
                                continue;

                        }
                    }

                    printf("\nOgrenci icin 1'e Tam icin 2'ye basin\n");
                    scanf(" %d",&odemesekli);
                    if(odemesekli == ogrencibilet )
                    {
                        tutar = 20;
                        hasilat+=tutar;
                    }
                    else if(odemesekli == tam)
                    {
                        tutar = 30;
                        hasilat+=tutar;
                    }
                    printf("\nRezarvasyon Bilgileri:\n");
                    printf("\n%d numarali koltuga rezervasyon yapilmistir.\n",koltuknum+1);
                    printf("\nbilet fiyati %d liradir.\n",tutar);

                    fp4=fopen("koltukblue.txt","w+");
                    for(j=0;j<5;j++)
                    {
                        for(k=0;k<50;k++)
                        {
                            if(psalon->Blue[j][k] == '0')
                            fputc('0',fp4);
                        else
                            fputc('1',fp4);
                        }

                    }
                    fclose(fp4);
                    fp5=fopen("hasilat.txt","w+");

                    fprintf(fp5,"%d",hasilat);

                    fclose(fp5);

                    break;
                    break;

            }
            break;

        case 2:
            fp5=fopen("hasilat.txt","r");

            fscanf(fp5,"%d",&hasilat);

            fclose(fp5);
            printf("\nToplam hasilat : %d TL.\n",hasilat);

            break;

        case 3:
            printf("\nRed icin izlenme sayisi asagidadir.\n");
            for(i=0;i<5;i++)
            {
                for(j=0;j<50;j++)
                {
                    if(psalon->Red[i][j] == '1')
                    {
                        koltuksayaci++;

                    }
                }
                printf("\n%d. Matinede %d izlenme vardir.\n",i+1,koltuksayaci);
                koltuksayaci=0;
            }

            printf("\nGreen icin izlenme sayisi asagidadir.\n");
            for(i=0;i<5;i++)
            {
                for(j=0;j<50;j++)
                {
                    if(psalon->Green[i][j] == '1')
                    {
                        koltuksayaci++;

                    }
                }
                printf("\n%d. Matinede %d izlenme vardir.\n",i+1,koltuksayaci);
                koltuksayaci=0;
            }


            printf("\nBlue icin izlenme sayisi asagidadir.\n");
            for(i=0;i<5;i++)
            {
                for(j=0;j<50;j++)
                {
                    if(psalon->Blue[i][j] == '1')
                    {
                        koltuksayaci++;

                    }
                }
                printf("\n%d. Matinede %d izlenme vardir.\n",i+1,koltuksayaci);
                koltuksayaci=0;
            }

            break;

        default:
            break;

    }

    return 0;
}
