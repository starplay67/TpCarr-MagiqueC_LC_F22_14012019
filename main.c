#include <stdio.h>
#include <stdlib.h>
#define LIMITE 7

typedef struct tPos
{
    int nX;
    int nY;
}tPos;

//prototypes
void init(int carreMagique[LIMITE][LIMITE]);
void avancer(tPos *maPos,int carreMagique[LIMITE][LIMITE],int nCpt);
void placer(tPos *maPos, int carreMagique[LIMITE][LIMITE],int nCpt);
void corriger(tPos *maPos, int carreMagique[LIMITE][LIMITE]);
int vide(tPos *maPos,int carreMagique[LIMITE][LIMITE]);
void aff(int carreMagique[LIMITE][LIMITE]);
void avDroite(tPos *maPos);
void avGauche(tPos *maPos);

int main()
{
    tPos maPos={2,3};
    int nCpt=2;
    int carreMagique[LIMITE][LIMITE];
    init(carreMagique);
    do
    {
        avancer(&maPos,carreMagique,nCpt);
        nCpt+=1;
        aff(carreMagique);
    }while(nCpt<26);
    return 0;
}

void init(int carreMagique[LIMITE][LIMITE]) //Initialisation du carré magique
{
    int nCpt1=0;
    int nCpt2=0;
    for (nCpt1=0;nCpt1<LIMITE;nCpt1++)
    {
        for (nCpt2=0;nCpt2<LIMITE;nCpt2++)
        {
            carreMagique[nCpt1][nCpt2]=0;
        }
    }
    carreMagique[2][3]=1;
}

void avancer(tPos *maPos,int carreMagique[LIMITE][LIMITE],int nCpt) //Fonction permettant de se déplacer, j'avance forcément à droite et déplace à gauche si la case est prise.
{
    maPos->nX-=1;
    avDroite(maPos);
    corriger(maPos,carreMagique);
    if(vide(maPos,carreMagique)==1)
    {
        maPos->nX-=1;
        avGauche(maPos);
    }
    corriger(maPos,carreMagique);
    placer(maPos,carreMagique,nCpt);
}

void placer(tPos *maPos, int carreMagique[LIMITE][LIMITE],int nCpt) //Fonction permettant d'ajouter à mon carré magique la valeur correspondante.
{
    carreMagique[maPos->nX][maPos->nY]=nCpt;
}

void corriger(tPos *maPos, int Sphere[LIMITE][LIMITE]) //Fonction permettant de rester dans le cadre.
{
    if(maPos->nX<1)
    {
        maPos->nX+=5;
    }
    if(maPos->nY<1)
    {
        maPos->nY+=5;
    }
    if(maPos->nX>5)
    {
        maPos->nX-=5;
    }
    if(maPos->nY>5)
    {
        maPos->nY-=5;
    }
}

int vide(tPos *maPos,int carreMagique[LIMITE][LIMITE]) //Fonction qui sert à savoir si la case sélectionnée est vide ou non.
{
    int nVerif=0;
    if(carreMagique[maPos->nX][maPos->nY]!=0)
    {
        nVerif=1;
    }
    return nVerif;
}

void aff(int carreMagique[LIMITE][LIMITE]) //Fonction d'affichage.
{
    int nCpt1=0;
    int nCpt2=0;
    for(nCpt1=1;nCpt1<LIMITE-1;nCpt1++)
    {
        for(nCpt2=1;nCpt2<LIMITE-1;nCpt2++)
        {
            printf("[%d]",carreMagique[nCpt1][nCpt2]);
        }
        printf("\n");
    }
    printf("\n");
}

void avDroite(tPos *maPos) //Fonction permettant un déplacement sur la droite. Elle est toujours utilisée.
{
    maPos->nY+=1;
}

void avGauche(tPos *maPos) //Fonction permettant une rectification sur la gauche si la case sur laquelle on a avancé est prise.
{
    maPos->nY-=1;
    /*if (maPos->nY<=0)
    {
        if(maPos->nY==0)
        {
            maPos->nY=5;
        }
        else if (maPos->nY==-1)
        {
            maPos->nY=4;
        }
    }*/
}

