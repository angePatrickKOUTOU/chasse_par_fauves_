#include <iostream>
#include <unordered_map>
#include "Plateau.h"
#include "Position.h"
#include "Jeu.h"
#include "Lion.h"
#include "Jaguar.h"
#include "Obstacle.h"
#include "Vide.h"
#include "Piege.h"
#include <time.h>
using namespace std;





Occupant** getRandomOccupants(unsigned int nl,unsigned int nc){
    OccupantPtr *grille=new OccupantPtr [nl*nc];
    srand (time(NULL));
    bool jPresent=false;
    int pos=rand()%nl*nc;
    for(int x=0;x<nl*nc;x++){
        //random number between 1 and 5
        if(x==pos && !jPresent){
            grille[x]=new Joueur();
            jPresent=true;
        }else{
            int rd = rand() % 15 + 1;
            if(rd==1 ){
                grille[x]=new Lion();
            }else if(rd==2){
                grille[x]=new Obstacle();
            }else if(rd==3){
                grille[x]=new Piege();
            }else{
                grille[x]=new Vide();
            }
        }
    }
    return grille;
}




int main() {
   Joueur joueur=Joueur();

    Plateau plateau= Plateau(5,getRandomOccupants(5,5));
    Jeu *jeu=new Jeu(plateau);
    jeu->lancer();

   return 0;
}