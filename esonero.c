#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

int main (){  // dichiarazioni array e variabili
char str1[128];
char Key2[128];
int len1; // variabile lunghezza str1
time_t t;


printf("Scrivere la stringa qui: \n");
fgets(str1,128,stdin);
printf("\n");
printf("Stringa Ricevuta :\n");
puts(str1);
len1= strlen(str1)-1; // lunghezza caratteri

printf("lunghezza della stringa : %d\n", len1);



    int choose;
    //int ch;
    printf("\n");
    printf("\n");

    printf("Come vuoi procedere :\n \n");
    printf("***********************************************\n");
    printf("1) Scrivi un altra stringa uguale o superiore \n che non superi 128 caratteri.\n");
    printf("2) Criptare la stringa.\n");
    printf("***********************************************\n");
    printf("\nInserisci risposta: ");
    scanf("%d",&choose); // screvere risposta tra 1 e 2
    printf("\n");
      if(choose==1){

        char Key1[128]; // dichiarazione array chiave per fare l'operazione di xor
        int len2;
        while(getchar() !='\n');
        do{
        printf("Scrvi un altra stringa maggiore o uguale \n alla precedente : \n");
        fgets(Key1,128,stdin);
        printf("Stampa stringa :\n");
        puts(Key1);

        len2=strlen(Key1)-1;
        printf("lunghezza stringa 2 : %d\n",len2 );
      } while (len2<=len1);
        char xor[128];
        memset(xor,0,sizeof(xor)); // funzione per svuotare la chiave in caso di occupazione in memoria da precedente avvio del programma
        printf("Chiave unendo le 2 stringhe :\n \n");
        for(int i=0;i<len2;i++){
          xor[i]^=(char)(str1[i]^Key1[i]); // operazione di XOR
          printf("%x",xor[i]);

        }

        printf("\n");
        printf("\n");

        char Plain[128]; // dichiarazione array per ristampare la stringa principale

        for(int i=0;i<128;i++){
          Plain[i]=(char)(Key1[i]^xor[i]); // operazione inversa di XOR
        }
        printf("Plain text....\n");
          puts(Plain);

      }
          else if(choose==2){
            srand((unsigned) time(&t)); //funzione random
            for(int i=0;i<=len1;i++){

            Key2[i]=(char)rand() %(128-32+1)+32; // prendere solo i caratteri da 32 a 128
        }
        printf("Chiave di criptazione : ");
        puts(Key2); // stampa chiave randomica
        printf("\n");
        char xor1[128];
          printf("XOR operation : \n");
           for(int i=0;i<strlen(Key2)-1;i++){
              xor1[i]=(char)(str1[i]^Key2[i]);
              printf("%c",xor1[i]);
            }
            printf("\n");
            printf("\n");

          //  puts(xor1); // stampa chiave cifrata

            char Plain[128];
            printf("Plain Text.....\n");
              for(int i=0;i<len1;i++){
                Plain[i]=(char)(Key2[i]^xor1[i]);
                printf("%c",Plain[i] );
              }
               // stampa Plain text


printf("\n");
  }
else if(choose!=1||2){ // controllo di scelta
  perror("Scegliere o 1 o 2 come scelta non oltre! \n");
    return 0;
}


}
