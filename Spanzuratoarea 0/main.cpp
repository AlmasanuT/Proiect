#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <ctime>

using namespace std;

ifstream fin ("d.in");

#define var_random  //aici am trei variante, "var_random" e cea in care programul imi alege pseudorandom un cuvant din cele 350 000, "var_select" in care
                    //bag de la tastatura cuvantul, si "staged" pentru prezentare - voiam un cuvant pe care sa fiu sigur ca il ghicesc.

#define program     //define program ruleaza programul in sine, daca scriu in loc de program "showcase" imi tot genereaza numere pseudorandom - tot pentru
                    //prezentare era si asta - voiam sa arat cum sunt generate cele trei numere si cel care rezulta din ele

char sir1[41];      //variabile declarate super neintuitiv
char sir0[41];
char gresit[6];
char corect[20];
int v[40];
char a[1];
int ok, c, i, I, g=-1;

int assholevariable = 0;    //daca imputez de prea multe ori la rand o litera deja ghicita din program, ma scoate din el

int show;

/*
am doua functii cast100() si cast35() in loc sa am una singura pentru ca in functia originala,
cand apelam cast(100) de doua ori la rand, imi returna acelasi numar, insa apeland cast100() de doua ori, nu.

int cast(int nr)
{
    int num = (rand() % nr)+ 1;
      return num;
}

*/

int cast100() {
      int num = (rand() % 100)+ 1; //iau un numar random intre 1 si 100 incl
      return num;
}

int cast35() {
      int num = (rand() % 35)+ 1; //iau un numar random intre 1 si 35 incl
      return num;
}
/*
cu asta voi verifica, la fiecare litera nou introdusa, daca am terminat "de ghicit" cuvantul.
am un fel de array de frecventa (nu-i prea accurate numit, ca are doar 0 si 1) cu ajutorul caruia verific daca s-au ghicit toate literele:

v: 0 1 2 3 4 5 6 8 9 10 ...

   1 0 0 0 1 0 0 1
   A N I M A T I E

asa il voi implementa initial. cu fiecare inputare, se va parcurge tot cuvantul si se vor marca aparitiile literei cu 1. pe urma afisez litera de pe locul
respectiv daca in array e 1, sau "_" daca in array e 0. rinse and repeat (pana cand raman fara incercari - 6 din default: 1 cap, 1 corp, 2 maini, 2 picoare)
sau pana cand ghicesc cuvantul - adica atunci cand in tot arrayul, de la 0 pana la strlen(sir1) e numai 1

*/

bool verVECT(char s[40],int w[40])
{
       for(i=0;i<strlen(s);i++)
              if(v[i]==0)
                     return false;
       return true;
}


void hang (int c)       //subpr care imi deseneaza corpul la fiecare pas
{
       switch (c)
       {
       case 6:

       cout   <<endl<<endl
              <<" "<<char(176)<<char(194)<<char(196)<<char(196)<<char(196)<<char(191)<<endl
              <<" "<<char(176)<<"/   |   "<<endl
              <<" "<<char(177)<<"    " <<char(1)<<"   "<<endl
              <<" "<<char(177)<<"   /|\\ "<<endl
              <<" "<<char(178)<<"    |   "<<endl
              <<" "<<char(178)<<"   / \\ "<<endl
              <<"_"<<char(178)<<"_ ";
              break;

       case 5:

       cout   <<endl<<endl
              <<" "<<char(176)<<char(194)<<char(196)<<char(196)<<char(196)<<char(191)<<endl
              <<" "<<char(176)<<"/   |   "<<endl
              <<" "<<char(177)<<"    " <<char(1)<<"   "<<endl
              <<" "<<char(177)<<"   /|\\ "<<endl
              <<" "<<char(178)<<"    |   "<<endl
              <<" "<<char(178)<<"   / \ "<<endl
              <<"_"<<char(178)<<"_ ";
              break;
       case 4:


       cout   <<endl<<endl
              <<" "<<char(176)<<char(194)<<char(196)<<char(196)<<char(196)<<char(191)<<endl
              <<" "<<char(176)<<"/   |   "<<endl
              <<" "<<char(177)<<"    " <<char(1)<<"   "<<endl
              <<" "<<char(177)<<"   /|\\ "<<endl
              <<" "<<char(178)<<"    |   "<<endl
              <<" "<<char(178)<<"        "<<endl
              <<"_"<<char(178)<<"_ ";
              break;

       case 3:

       cout   <<endl<<endl
              <<" "<<char(176)<<char(194)<<char(196)<<char(196)<<char(196)<<char(191)<<endl
              <<" "<<char(176)<<"/   |   "<<endl
              <<" "<<char(177)<<"    " <<char(1)<<"   "<<endl
              <<" "<<char(177)<<"   /|   "<<endl
              <<" "<<char(178)<<"    |   "<<endl
              <<" "<<char(178)<<"        "<<endl
              <<"_"<<char(178)<<"_ ";
              break;
       case 2:

       cout   <<endl<<endl
              <<" "<<char(176)<<char(194)<<char(196)<<char(196)<<char(196)<<char(191)<<endl
              <<" "<<char(176)<<"/   |   "<<endl
              <<" "<<char(177)<<"    " <<char(1)<<"   "<<endl
              <<" "<<char(177)<<"    |   "<<endl
              <<" "<<char(178)<<"    |   "<<endl
              <<" "<<char(178)<<"        "<<endl
              <<"_"<<char(178)<<"_ ";
              break;
       case 1:

       cout   <<endl<<endl
              <<" "<<char(176)<<char(194)<<char(196)<<char(196)<<char(196)<<char(191)<<endl
              <<" "<<char(176)<<"/   |   "<<endl
              <<" "<<char(177)<<"    " <<char(1)<<"   "<<endl
              <<" "<<char(177)<<"        "<<endl
              <<" "<<char(178)<<"        "<<endl
              <<" "<<char(178)<<"        "<<endl
              <<"_"<<char(178)<<"_ ";
              break;
       case 0:

       cout   <<endl<<endl
              <<" "<<char(176)<<char(194)<<char(196)<<char(196)<<char(196)<<char(191)<<endl
              <<" "<<char(176)<<"/   |   "<<endl
              <<" "<<char(177)<<"       "<<endl
              <<" "<<char(177)<<"       "<<endl
              <<" "<<char(178)<<"       "<<endl
              <<" "<<char(178)<<"      "<<endl
              <<"_"<<char(178)<<"_ ";
       }
}

int OK;
int main()
{
    LOOP:
    #ifdef showcase
    srand(time(NULL));
    int A=cast100();
    int b=cast100();
    int C=cast35();

    cout<<"Numar pseudorandom intre 1 si 100: "<<A<<endl
        <<"Numar pseudorandom intre 1 si 100: "<<b<<endl
        <<"Numar pseudorandom intre 1 si 35: "<<C<<endl;

    int NUMAR = (A-1)*3500 + (b-1)*35 + C-1;

    cout<<endl<<"Numarul intre 1 si 350 000 care reiese din cele trei: "<<NUMAR<<endl;
    cin>>show;
    if(show)
        goto LOOP;
    #endif // showcase

    srand(time(NULL));
    #ifdef program
    cout<<endl<<endl<<"Numerele generate pseudorandom: "<<endl;
    int A=cast100();
    int b=cast100();
    int C=cast35();
    cout<<A<<" "<<b<<" "<<C;
    int NUMAR = (A-1)*3500 + (b-1)*35 + C-1;
    cout<<endl<<NUMAR;
    for(i=1;i<=NUMAR;i++){
       fin.get(sir1, 41);
       fin.get();
    }

    #ifdef var_select
    cout<<endl<<"Introduceti cuvatul: ";

    cin>>sir1;

    #endif

    #ifdef staged
    strcpy(sir1, "supercalifragilisticexpialidocius");
    #endif


    for(i=0;i<strlen(sir1);i++) //le fac pe toate uppercase for consistency's sake, la fel o sa fac la un moment dat si inputurile, ca sa am mai putin de verificat

        sir1[i]=sir1[i]-32;

       v[0]=1;
       v[strlen(sir1)-1]=1;
        corect[++g]=v[0];
        if(v[0]!=v[strlen(sir1)-1])
            corect[++g]=v[strlen(sir1)-1];

       for(i=1;i<strlen(sir1)-1;i++)
              if((sir1[i]==sir1[0])||(sir1[i]==sir1[strlen(sir1)-1]))
                     v[i]=1;

       while(!verVECT(sir1, v) && c<6)
       {
              if(c>0)                                               //afisez string-ul cu LITERE GRESITE
              {
                  cout<<"Litere gresite pana acum:"<<endl<<endl<<">>>> ";
                    for(I=0;I<strlen(gresit);I++)
                        cout<<gresit[I]<<" ";
                  cout<<" <<<<"<<endl;
              }


              hang(c);
              cout<<endl<<endl;
              cout<<"Incercari ramase = "<<6-c<<endl<<endl;
              for(i=0;i<strlen(sir1);i++)                           //afisez literele din cuvant in functie de v[i]
                     if(v[i]==1)
                            cout<<sir1[i]<<" ";
                     else
                            cout<<"_ ";
              cout<<endl<<endl<<"INTRODUCETI LITERA ";

              assholevariable=0;


              repeat2:

              cin>>a;                                               //citesc o LITERA

              if(a[0]>=97 && a[0]<=122)                             //fac a.i. sa nu conteze daca litera introdusa e cu litera mare sau nu
                    a[0]=a[0]-32;
              else if(a[0]<65 || a[0]>90)
              {
                    assholevariable++;                              //fac astfel incat sa iasa din program daca este inputata de prea multe ori o litera deja gasita/ gresita
                    if(assholevariable==3)
                        cout<<"Atentie! Daca mai introduceti o litera la panarama inca o data, veti pierde jocul! Introduceti o litera: ";
                    else if(assholevariable==4)
                        goto lost;
                    else
                        cout<<"Asta nu e litera! Introdu una noua: ";
                    goto repeat2;
              }
              if(a[0]==sir1[0]||a[0]==sir1[strlen(sir1)-1])
              {
                    assholevariable++;
                    if(assholevariable==3)
                        cout<<"Atentie! Daca mai introduceti o litera la panarama inca o data, veti pierde jocul! Introduceti o litera: ";
                    else if(assholevariable==4)
                        goto lost;
                    else
                        cout<<"Litera este deja marcata! Introduceti una noua: ";
                    goto repeat2;
              }





              for(I=0;I<strlen(gresit);I++)
                    if(gresit[I]==a[0])
                    {
                        assholevariable++;
                        if(assholevariable==3)
                            cout<<"Atentie! Daca mai introduceti o litera la panarama inca o data, veti pierde jocul! Introduceti o litera: ";
                        else if(assholevariable==4)
                            goto lost;
                        else
                            cout<<"Litera a fost inputata deja! E gresita! Introduceti una noua: ";
                        goto repeat2;
                    }

              for(I=0;I<strlen(corect);I++)
                    if(corect[I]==a[0])
                    {
                        assholevariable++;
                        if(assholevariable==3)
                            cout<<"Atentie! Daca mai introduceti o litera la panarama inca o data, veti pierde jocul! Introduceti o litera: ";
                        else if(assholevariable==4)
                            goto lost;
                        else
                            cout<<"Litera este corecta, dar a fost deja inputata! Introduceti una noua: ";
                        goto repeat2;
                    }

              ok=0;
              for(i=0;i<strlen(sir1);i++)                           //compar fiecare litera cu LITERA

              {
                     if(sir1[i]==a[0])
                     {
                            v[i]=1;                                 //unde coincid, acolo fac v[i] sa ia val 1
                            ok=1;                                   //asta inseamna ca am ghicit macar o data
                            corect[++g]=a[0];
                     }
              }

              if(ok==0)
              {
                     gresit[c]=a[0];
                     c++;
                     cout<<endl<<"WRONG!!!"<<endl;                  //daca nu coincid deloc, cresc un contor c
              }
              else
                     cout<<endl<<"Corect!"<<endl;                   //altfel, inseamna ca am ghicit si ca litera apare in macar un loc
       cout<<endl;
       }



       //secventa de final - ori am ghicit si e 1 peste tot, ori am ramas fara incercari
       lost:
       if(assholevariable==4)
       cout<<endl<<endl<<"FELICITARI! TOCMAI ATI FOST DESCALIFICAT. VA RUGAM INTRODUCETI UN BANUT PENTRU A CONTINUA"<<endl<<endl
    <<"         ..-'''''-..          "<<endl
    <<"       .'    ___    '.        "<<endl
    <<"      /    .'\\  `\\    \\    "<<endl
    <<"     ;    /, (    |    ;      "<<endl
    <<"    ;    /_   '._ /     ;     "<<endl
    <<"    |     |-  '._`)     |     "<<endl
    <<"    ;     '-;-'  \\      ;    "<<endl
    <<"     ;      / TEO \\    ;     "<<endl
    <<"      \\    '.__..-'   /      "<<endl
    <<"       '._ 2 0 1 7 _.'        "<<endl
    <<"          ''-----''           "<<endl

    <<endl<<endl<<"APASATI ENTER PENTRU A INTRODUCE BANUTUL"<<endl<<endl;

        else if(c>=6)
        {
            cout<<"           YOU LOSE"<<endl;
            hang(6);
            cout<<endl<<endl<<" !!!!LOSER!!!!"<<endl;
        }
       else
              cout<<"           YOU WIN"<<endl<<endl<<sir1<<endl<<endl<<endl
    <<"         ..-'''''-..          "<<endl
    <<"       .'    ___    '.        "<<endl
    <<"      /    .'\\  `\\    \\    "<<endl
    <<"     ;    /, (    |    ;      "<<endl
    <<"    ;    /_   '._ /     ;     "<<endl
    <<"    |     |-  '._`)     |     "<<endl
    <<"    ;     '-;-'  \\      ;    "<<endl
    <<"     ;      / TEO \\    ;     "<<endl
    <<"      \\    '.__..-'   /      "<<endl
    <<"       '._ 2 0 1 6 _.'        "<<endl
    <<"          ''-----''           "<<endl

    <<endl<<endl<<"APASATI ENTER PENTRU A INTRODUCE O NOUA FISA"<<endl<<endl;
        #endif


       return 0;
}


