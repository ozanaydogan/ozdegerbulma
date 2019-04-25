// Cihangir Ilyas Bastan 160202019- Ridvan Kaplan  160202013


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<math.h>
ozdegerbul()
{

    int n,i,j,det=0;
    printf("(OZDEGER)Kare Matrisinizin Boyutunu Giriniz : ");
    scanf("%d",&n);
    int matris[n][n];
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            printf("%d.Satirin %d.Sutununu Giriniz : ",i+1,j+1);
            scanf("%d",&matris[i][j]);
        }
    }

    if(n==1)
    {
        FILE *dosya;
        dosya=fopen("ozdeger.txt","w");
        for(i=0; i<n; i++)
        {
            for(j=0; j<n; j++)
            {
                fprintf(dosya,"Girilen Matris\n");
                fprintf(dosya,"%d\n\n",matris[i][j]);
                fprintf(dosya,"Matrisin Ozdegeri\n");
                fprintf(dosya,"%d ",matris[i][j]);
            }
            fputs("\n",dosya);
        }
        fclose(dosya);
    }

    int lamda1,lamda2,delta,a=1,b,c;

    if(n==2)
    {
        b=-matris[0][0]-matris[1][1];
        c=matris[0][0]*matris[1][1]-matris[0][1]*matris[1][0];
        delta=b*b-(4*a*c);;
        lamda1=(-b+sqrt(delta))/2*a;
        lamda2=(-b-sqrt(delta))/2*a;
        FILE *dosya;
        dosya=fopen("ozdeger.txt","w");
        fprintf(dosya,"Girilen Matris\n");
        for(i=0; i<n; i++)
        {
            for(j=0; j<n; j++)
            {
                fprintf(dosya,"%d ",matris[i][j]);
            }
            fputs("\n",dosya);
        }

        fprintf(dosya,"Matrisin Ozdegerleri\n");
        fprintf(dosya,"%d  %d \n",lamda1,lamda2);
        fclose(dosya);
    }
    else if(n==2)
    {

    }

}
schur();
ozvektorbul();

   nilpotent(){

printf("\nNilpotent Calisiyor .");
FILE *f;
f=fopen("nilpotent.txt","w+");
fclose(f);
f=fopen("nilpotent.txt","r+");

    int i,j,n;
    int matris1[50][50],matris2[50][50],sonuc[50][50],toplam=0, say,sayac,k,x,y;
    printf("(NILPOTENT) Kare Matrisinizin Boyutunu Giriniz : ");
    scanf("%d",&n);

    srand(time(NULL));

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            matris1[i][j]=(rand()%30)-15;
            sonuc[i][j]=matris1[i][j];
            fprintf(f, "%7d" ,sonuc[i][j]);
        }
        fprintf(f,"\n");
    }
    fprintf(f,"CARPIM SONUCLARI\n");

    for(say=0;say<100;say++){
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                for(k=0;k<n;k++){
                    toplam+=matris1[i][k]*sonuc[k][j];
                }
                matris2[i][j]=toplam;
                toplam=0;
            }
        }

        for(x=0;x<n;x++){
            for(y=0;y<n;y++){
                sonuc[x][y]=matris2[x][y];
                fprintf(f,"%7d ",sonuc[x][y]);
                if(matris2[x][y]!=0)sayac=1;

				else sayac=0;
            }
            fprintf(f,"\n");
        }
        fprintf(f,"\n");
    }
    if(sayac==0){
        printf("Nilpotent.");
        fprintf(f,"nilpotent.");
    }else{

        printf("Nilpotent degil.");
        fprintf(f,"Nilpotent degil.");
    }
    printf("\n Sonuclar yazildi.");





}

cark()
{

    int uretilecek_sayi,sayac=1,random,islem;
    printf("Kac Tane Sayi Uretilmesini Istiyorsunuz\n");
    scanf("%d",&uretilecek_sayi);
    srand(time(NULL));
    while(sayac<=uretilecek_sayi)
    {
        random=0+rand()%242;
        printf("%d.Sayi %d\n",sayac,random);
        sayac++;
    }
printf("%d\n",random);
    islem=random%4;
    printf("%d",islem);
    if(islem==0)
    {
        nilpotent();
    }
    if(islem==1)
    {
        ozdegerbul();
    }
    if(islem==2)
    {
        //   schur();
        printf("\n schur");
        getch();
    }
    if(islem==3)
    {
        //   ozvektorbul();
        printf("\n ozvektor") ;
        getch();
    }

}
int main()
{
    cark();
    return 0;

}


