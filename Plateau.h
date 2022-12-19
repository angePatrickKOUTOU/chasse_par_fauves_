//
// Created by oreste on 09/11/22.
//

#ifndef CHASSE_PAR_FAUVES_PLATEAU_H
#define CHASSE_PAR_FAUVES_PLATEAU_H

#include <vector>
#include <iostream>
#include <ostream>
#include "Position.h"
#include "Participant.h"
#include "Joueur.h"

using std::vector;
using std::ostream;
typedef Occupant* OccupantPtr;
class Plateau {

private:
    unsigned int d_nl,d_nc;

    // Le tableau contigu
    OccupantPtr *grille;
    //OccupantPtr *grilleOc;

    // Le tableau de pointeurs sur les « lignes »
    //unsigned int **d_tab;
    OccupantPtr**d_tab;
    //std::vector<Occupant*> occupants;
    Position position_joueur;
    void MAJ();
    Joueur * joueur;
    OccupantPtr& operator()(unsigned int l, unsigned int c);

public:

    Plateau(unsigned int nl,unsigned int nc,OccupantPtr *);
    explicit Plateau(OccupantPtr*occupants);
    Plateau(unsigned int,OccupantPtr*occupants);
    Plateau(const Plateau& t);
    ~Plateau();

// Pour modifier ses éléments avec l’opérateur []
    OccupantPtr* operator[](unsigned int l);
// Pour accéder à ses éléments avec l’opérateur []
    const OccupantPtr* operator[](unsigned int l) const;
// Une autre façon de modifier et lire ses éléments.

    OccupantPtr operator()(unsigned int l, unsigned int c) const;

// Pour dupliquer un autre tableau
    Plateau& operator=(const Plateau& t) ;
// Pour connaître ses dimensions
    unsigned int get_nl() const; unsigned int get_nc() const;
// Pour afficher son contenu
    friend ostream& operator<<(ostream& os,const Plateau& t);
    void afficher()const;

    static char getChar( unsigned int);

    void bouger(const Directions& direction);
    static void fight(Participant& p1,Participant& p2);

    //movements
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();
    void moveUpRight();
    void moveUpLeft();
    void moveDownRight();
    void moveDownLeft();

    void setJoueur(int l,int c);

};


#endif //CHASSE_PAR_FAUVES_PLATEAU_H
