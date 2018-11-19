    /* Les chiffres romains vont de 1 à 3999.
    l'utilisateur peut quitter le programme en tapant 0.
    programme 1 - conversion décimal vers romains
    programme 2 - conversion romain vers décimal */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define TAILLE_MAX_CHAINE 15

//prototype
void initialisation(char *pChaine_car,int *pTableau_entier,int *pLongueur,int *pResultat);
void menu(int *pSaisie_menu);
void saisie_chaine_car(char *pChaine_car);
void traduction(char *pChaine_car,int *pTableau_entier,int *pLongueur);
void verification_soustraction(int *pTableau_entier,const int nLongueur);
void addition(int *pTableau_entier,const int nLongueur,int *pResultat);
void saisie_entier(int *pEntier);
void decomposition_entier(int nEntier,int *pTableau,int *pDecimal);
//void creation_chaine_caractere(int *pTableau,char *pChaine,const int nDecimal);
// la procedure utilisant la chaine de caractere en paramètre ne fonctionne pas -> intégrée au programme principal

// --- PROGRAMME PRINCIPAL ---
int main()
{
    char chaine_car[]="   ";
    int tableau_entier[TAILLE_MAX_CHAINE];
    int nSaisie=3;
    int nLongueur=0;
    int nResultat=0;
    int nEntier=0;
    int nDecimal=0;

    int nCpt=0;

    while (nSaisie!=0)
    {
        menu(&nSaisie);
        if (nSaisie==1)
        {
            initialisation(chaine_car,tableau_entier,&nLongueur,&nResultat);
            chaine_car[1]='\0';
            saisie_entier(&nEntier);
            //printf("nEntier = %d\n",nEntier);
            decomposition_entier(nEntier,tableau_entier,&nDecimal);
            //creation_chaine_caractere(tableau_entier,chaine_car,nDecimal);    -> procédure de création de la chaine ne fonctionnant pas.
            //strcat ne fonctionne pas dans la procédure, creation de la chaine dans le programme principal :(

            switch (tableau_entier[0])
            {
                case 0:
                    chaine_car[0]=' ';
                    break;
                case 1:
                    chaine_car[0]='M';
                    break;
                case 2:
                    chaine_car[0]='M';
                    strcat(chaine_car,"M");
                    break;
                case 3:
                    chaine_car[0]='M';
                    strcat(chaine_car,"MM");
                    break;
            }
            switch (tableau_entier[1])
            {
                case 1:
                    strcat(chaine_car,"C");
                    break;
                case 2:
                    strcat(chaine_car,"CC");
                    break;
                case 3:
                    strcat(chaine_car,"CCC");
                    break;
                case 4:
                    strcat(chaine_car,"CD");
                    break;
                case 5:
                    strcat(chaine_car,"D");
                    break;
                case 6:
                    strcat(chaine_car,"DC");
                    break;
                case 7:
                    strcat(chaine_car,"DCC");
                    break;
                case 8:
                    strcat(chaine_car,"DCCC");
                    break;
                case 9:
                    strcat(chaine_car,"CM");
                    break;
            }
            switch (tableau_entier[2])
            {
                case 1:
                    strcat(chaine_car,"X");
                    break;
                case 2:
                    strcat(chaine_car,"XX");
                    break;
                case 3:
                    strcat(chaine_car,"XXX");
                    break;
                case 4:
                    strcat(chaine_car,"XL");
                    break;
                case 5:
                    strcat(chaine_car,"L");
                    break;
                case 6:
                    strcat(chaine_car,"LX");
                    break;
                case 7:
                    strcat(chaine_car,"LXX");
                    break;
                case 8:
                    strcat(chaine_car,"LXXX");
                    break;
                case 9:
                    strcat(chaine_car,"XC");
                    break;
            }
            switch (tableau_entier[3])
            {
                case 1:
                    strcat(chaine_car,"I");
                    break;
                case 2:
                    strcat(chaine_car,"II");
                    break;
                case 3:
                    strcat(chaine_car,"III");
                    break;
                case 4:
                    strcat(chaine_car,"IV");
                    break;
                case 5:
                    strcat(chaine_car,"V");
                    break;
                case 6:
                    strcat(chaine_car,"VI");
                    break;
                case 7:
                    strcat(chaine_car,"VII");
                    break;
                case 8:
                    strcat(chaine_car,"VIII");
                    break;
                case 9:
                    strcat(chaine_car,"IX");
                    break;
            }
            printf("en chiffre romains : %s\n\n",chaine_car);
        }
        if (nSaisie==2)
        {
            initialisation(chaine_car,tableau_entier,&nLongueur,&nResultat);
            saisie_chaine_car(chaine_car);
            traduction(chaine_car,tableau_entier,&nLongueur);
            verification_soustraction(tableau_entier,nLongueur);
            addition(tableau_entier,nLongueur,&nResultat);
            printf("%s = %d\n\n",&chaine_car,nResultat);
        }
    }
    return 0;
}

//PROCEDURE INITIALISATION :
void initialisation(char *pChaine_car,int *pTableau_entier,int *pLongueur,int *pResultat)
{
    int nCpt=0;
    *pResultat=0;
    *pLongueur=0;
    *pChaine_car=" ";
    for (nCpt=0;nCpt<TAILLE_MAX_CHAINE;nCpt++)
    {
        pTableau_entier[nCpt]=0;
    }
}

// Procedure MENU permettant de quitter le programme ou de choisir son sens de conversion
void menu(int *pSaisie_menu)
{
    printf("Veuillez entrer 1 pour convertir un nombre decimal en romain.\nVeuillez entrer 2 pour convertir un nombre romain en decimal.\nVeuillez entrer 0 pour quitter le programme.\n");
    scanf("%d",&*pSaisie_menu);
    while ((*pSaisie_menu<0) || (*pSaisie_menu>2))
    {
        printf("Saisie incorrecte, entrer un nouveau chiffre\n");
        scanf("%d",&*pSaisie_menu);
    }
}

// --- PROCEDURES DE TRADUCTION DU ROMAIN VERS LE DECIMAL

//Procedure de SAISIE de la chaine de caractere et de VERIFICATION de ses caracteres
void saisie_chaine_car(char *pChaine_car)
{
    int nCpt=0;
    int nErreur=1;
    int nLongueur=0;

    while (nErreur==1)
    {
        printf("Veuillez entrer votre chaine de caractere\n");
        scanf("%s",&*pChaine_car);
        printf("Vous avez entre la chaine : %s\n",&*pChaine_car);
        nLongueur=strlen(pChaine_car);
        nErreur=0;
        for (nCpt=0;nCpt<nLongueur;nCpt++)
        {
            if ((pChaine_car[nCpt]!='I') && (pChaine_car[nCpt]!='V') && (pChaine_car[nCpt]!='X') && (pChaine_car[nCpt]!='M') && (pChaine_car[nCpt]!='C') && (pChaine_car[nCpt]!='L') && (pChaine_car[nCpt]!='D'))
            {
                printf("Saisie incorrecte\n");
                nCpt=nLongueur;
                nErreur=1;
            }
        }
    }
}


//procedure de traduction des chiffres romains vers des entiers
void traduction(char *pChaine_car,int *pTableau_entier,int *pLongueur)
{
    int nCpt=0;
    while (pChaine_car[nCpt]!='\0')
    {
        switch (pChaine_car[nCpt])
        {
            case 'I':
                pTableau_entier[nCpt]=1;
                break;
            case 'V':
                pTableau_entier[nCpt]=5;
                break;
            case 'X':
                pTableau_entier[nCpt]=10;
                break;
            case 'L':
                pTableau_entier[nCpt]=50;
                break;
            case 'C':
                pTableau_entier[nCpt]=100;
                break;
            case 'D':
                pTableau_entier[nCpt]=500;
                break;
            case 'M':
                pTableau_entier[nCpt]=1000;
                break;
        }
        nCpt++;
        *pLongueur=nCpt;
    }
}


//procedure permettant d'effectuer les soustractions entre caractères romains (ex IX = 9 )
void verification_soustraction(int *pTableau_entier,const int nLongueur)
{
    int nCpt=0;
    for (nCpt=0;nCpt<nLongueur-1;nCpt++) //nLongueur -1 sinon la dernière valeur du tableau est comparée à une donnée du tableau qui ne correspond pas
    {
        if (pTableau_entier[nCpt]<pTableau_entier[nCpt+1])
        {
            pTableau_entier[nCpt]=pTableau_entier[nCpt+1]-pTableau_entier[nCpt];
            pTableau_entier[nCpt+1]=9999; //on réaffecte le nombre à une valeur>1000 pour qu'il ne puisse pas être pris en compte dans 2 soustractions.
        }
    }
}

void addition(int *pTableau_entier,const int nLongueur,int *pResultat)
{
    int nCpt=0;
    for (nCpt=0;nCpt<nLongueur;nCpt++)
    {
        if (pTableau_entier[nCpt]!=9999)
        {
            *pResultat=*pResultat+pTableau_entier[nCpt];
        }
    }
}



// --- PROCEDURES PERMETTANT DE TRADUIRE DU DECIMAL AU ROMAIN ---

//procedure de saisie et de vérification de l'entier.
void saisie_entier(int *pEntier)
{
     printf("Veuillez entrer un entier compris entre 1 et 3999:\n");
     scanf("%d",&*pEntier);
     while ((*pEntier<1)||(*pEntier>3999))
     {
         printf("Saisie incorrecte, veuillez entrer un entier compris entre 1 et 3999\n");
         scanf("%d",&*pEntier);
     }
}



//procedure de décomposition d'un entier vers un tableau d'entier
void decomposition_entier(int nEntier,int *pTableau,int *pDecimal)
{
    int nDecimal=0; //on utilisera et modifiera nDecimal alors que *pDecimal sera renvoyé afin d'être utilisé dans la prochaine procédure
    int nY=0;
    div_t nX;

    if (nEntier>=1000) //vérification du nombre de décimales
    {
        nDecimal=4;
        *pDecimal=4;
    }
    else if (nEntier>=100)
    {
        nDecimal=3;
        *pDecimal=3;
    }
    else if (nEntier>=10)
    {
        nDecimal=2;
        *pDecimal=2;
    }
    else
    {
        nDecimal=1;
        *pDecimal=1;
    }

    while (nDecimal>0)
    {
        if (nDecimal==4)
        {
            nX=div(nEntier,1000);
            nY=nEntier-(nX.quot*1000);
            pTableau[0]=nX.quot;
            nEntier=nY;
            nDecimal--;
        }
        else if (nDecimal==3)
        {
            nX=div(nEntier,100);
            nY=nEntier-(nX.quot*100);
            pTableau[1]=nX.quot;
            nEntier=nY;
            nDecimal--;
        }
        else if (nDecimal==2)
        {
            nX=div(nEntier,10);
            nY=nEntier-(nX.quot*10);
            pTableau[2]=nX.quot;
            nEntier=nY;
            nDecimal--;
        }
        else
        {
            pTableau[3]=nEntier;
            nEntier=0;
            nDecimal--;
        }
    }
}

//Procedure de creation de la chaine de caractere. Ne fonctionne pas en faisant passer la chaine en paramètre. Je n'ai pas réussi à trouver de solution.
/*void creation_chaine_caractere(int *pTableau,char *pChaine,const int nDecimal)
 {
    switch (pTableau[0])
    {
        case 0:
            pChaine=' ';
            break;
        case 1:
            pChaine='M';
            break;
        case 2:
            pChaine="MM";
            break;
        case 3:
            pChaine="MMM";
            break;
    }
    printf("en chiffre romains : %s\n",pChaine);
    switch (pTableau[1])
    {
        case 1:
            strcat(pChaine,"C");
            break;
        case 2:
            strcat(pChaine,"CC");
            break;
        case 3:
            strcat(pChaine,"CCC");
            break;
        case 4:
            strcat(pChaine,"CD");
            break;
        case 5:
            strcat(pChaine,"D");
            break;
        case 6:
            strcat(pChaine,"DC");
            break;
        case 7:
            strcat(pChaine,"DCC");
            break;
        case 8:
            strcat(pChaine,"DCCC");
            break;
        case 9:
            strcat(pChaine,"CM");
            break;
    }
    switch (pTableau[2])
    {
        case 1:
            strcat(pChaine,"X");
            break;
        case 2:
            strcat(pChaine,"XX");
            break;
        case 3:
            strcat(pChaine,"XXX");
            break;
        case 4:
            strcat(pChaine,"XL");
            break;
        case 5:
            strcat(pChaine,"L");
            break;
        case 6:
            strcat(pChaine,"LX");
            break;
        case 7:
            strcat(pChaine,"LXX");
            break;
        case 8:
            strcat(pChaine,"LXXX");
            break;
        case 9:
            strcat(pChaine,"XC");
            break;
    }
    switch (pTableau[3])
    {
        case 1:
            strcat(pChaine,"I");
            break;
        case 2:
            strcat(pChaine,"II");
            break;
        case 3:
            strcat(pChaine,"III");
            break;
        case 4:
            strcat(pChaine,"IV");
            break;
        case 5:
            strcat(pChaine,"V");
            break;
        case 6:
            strcat(pChaine,"VI");
            break;
        case 7:
            strcat(pChaine,"VII");
            break;
        case 8:
            strcat(pChaine,"VIII");
            break;
        case 9:
            strcat(pChaine,"IX");
            break;
    }
}*/
