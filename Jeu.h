//
// Created by oreste on 11/11/22.
//

#ifndef CHASSE_PAR_FAUVES_JEU_H
#define CHASSE_PAR_FAUVES_JEU_H


#include "Joueur.h"
#include "Plateau.h"
//#include "constants.cpp"


class Jeu {
private:
Plateau plateau;
vector<Occupant*>occupants;
public:
    Jeu(const Plateau &plateau);

    void bouger(Participant& p,Directions& direction);
    void afficher()const;
    void MAJ();
    void lancer();
    void afficherDirections()const;
    void afficherOccupants()const;



    void saisir();
    void performOperations();
    void performCheck();



};


#endif //CHASSE_PAR_FAUVES_JEU_H
