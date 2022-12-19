//
// Created by oreste on 09/11/22.
//


#include <cassert>
#include "Plateau.h"
#include "Vide.h"
#include "Joueur.h"
#include "Lion.h"

Plateau::Plateau(unsigned int lc,OccupantPtr *occupants):
    Plateau(lc,lc,occupants){}
Plateau::Plateau( OccupantPtr* occupants):
    Plateau(TAILLE_MIN,TAILLE_MIN,occupants)
{}
Plateau::Plateau(unsigned int nl, unsigned int nc,OccupantPtr *occupants):
    d_nl{nl},d_nc{nc},
    position_joueur{RAND_MAX,RAND_MAX},
    d_tab{new OccupantPtr *[d_nl]},
    grille{new OccupantPtr [d_nl*d_nc]},
    joueur{nullptr}
{

    for(unsigned int x=0;x<d_nc*d_nl;x++){
        grille[x]=occupants[x];
    }

    for(int i = 0; i < d_nl; i++) {
        d_tab[i] = grille+i*d_nc;
    }

    for(int x = 0; x < d_nl*d_nc; x++) {
        if (occupants[x]->getType()==JOUEUR) {
            ///TODO to be replaced lmater with setJoueir function
            joueur=(Joueur*)occupants[x];
            position_joueur=Position(x/d_nc,x%d_nc);
        }
        grille[x] = occupants[x];
    }

    //Au cas ou il n' y a pas de joueurs, on le met à la position zero
    if(joueur==nullptr){
        joueur=(Joueur*)occupants[0];
        position_joueur=Position(0,0);
    }
}
void Plateau::setJoueur(int l,int c){
    grille[(l*d_nc)+l]=joueur;
    position_joueur=Position(l,c);
}
Plateau::Plateau(const Plateau &t) :
    d_nl(t.d_nl),
    d_nc(t.d_nc),
    position_joueur(t.position_joueur),
    d_tab(new OccupantPtr * [d_nl]),
    grille(new OccupantPtr[d_nl*d_nc])
{
    for(unsigned int l = 0; l < d_nl; l++) {
        d_tab[l] = grille+l*d_nc;
    }
    for(unsigned int i = 0; i < d_nl*d_nc; i++){
        grille[i]=t.grille[i];
    }
}


Plateau::~Plateau() { delete[] d_tab; delete[] grille; }











// Pour dupliquer un autre tableau
Plateau& Plateau::operator=(const Plateau& t) {

    if (this != &t) {
        if (t.d_nl == d_nl && t.d_nc == d_nc) {
            for(int i = 0; i < d_nl*d_nc; i++){
                grille[i] = t.grille[i];
            }
        } else if (t.d_nl*t.d_nc == d_nl*d_nc) {
            d_nl = t.d_nl; d_nc = t.d_nc;
            for(int i = 0; i < d_nl*d_nc; i++){
                grille[i] = t.grille[i];
            }
            delete[] d_tab; d_tab = new OccupantPtr*[d_nl];
            for(int l = 0; l < d_nl; l++){
                d_tab[l] = grille+l*d_nc;
            }

        } else {
            delete[] grille; // Libération de la mémoire
            delete[] d_tab;
            d_nc = t.d_nc; // Les dimensions sont
            d_nl = t.d_nl; // les mêmes
            grille = new OccupantPtr[d_nl*d_nc]; // Nouvelles allocations
            d_tab = new OccupantPtr*[d_nl];
            for(int i = 0; i < d_nl; i++) {
                d_tab[i] = grille+i*d_nc; // Les départs de lignes
            }// Enfin, la recopie du tableau contigu
            for(int i = 0; i < d_nl*d_nc; i++)
                grille[i] = t.grille[i];
        }
    }
    return *this;
}
// Pour connaître ses dimensions
unsigned int Plateau::get_nl() const{
    return d_nl;
}
unsigned int Plateau::get_nc() const{
    return d_nc;
}
// Pour afficher son contenu
ostream& operator<<(ostream& os,const Plateau& t);


OccupantPtr* Plateau::operator[](unsigned int l) {
    return d_tab[l];
}
const OccupantPtr* Plateau::operator[](unsigned int l) const {
    return d_tab[l];
}
OccupantPtr& Plateau::operator()(unsigned int l, unsigned int c) {
    return grille[l*d_nc+c];
}
OccupantPtr Plateau::operator()(unsigned int l, unsigned int c) const {
    return grille[l*d_nc+c];
}


char Plateau::getChar(unsigned int val) {

    switch (val) {
        case 0:
            //VIDE
            return '.';
        case 1:
            //LION
            return 'L';
        case 2:
            //piège
            return 'C';
        case 3:
            //JAGUAR
            return 'G';
        case 4:
            //PIEGE
            return 'P';
        case 5:
            //OBSTACLE
            return 'J';
        case 6:
            //JOUEUR
            return 'O';
        default:
            return 'V';
    }
}
ostream& operator<<(ostream& os, const Plateau& t) {
    int k = 0;
    for(int i = 0; i < t.d_nl; i++) {
        for(int j = 0; j < t.d_nc; j++)
            // L’accès se fait par un simple indice
            os << Plateau::getChar(t.grille[k++]->getType() )<< "\t";
        os << std::endl;
    }
    return os;
}
void Plateau::afficher()const{
    int k = 0;
    for(int l = 0; l < d_nl; l++) {
        for(int c = 0; c < d_nc; c++)
                std::cout << getChar(grille[k++]->getType()) << "\t";

        std::cout << std::endl;
    }
}
void Plateau::MAJ(){
    //grilleOc[position_joueur.c()*position_joueur.l()+position_joueur.c()]=JOUEUR;
}

void Plateau::bouger(const Directions& direction){
    switch (direction) {
        case (SUD):
            moveDown();
            break;
        case(EST):
            moveRight();
            break;
        case(OUEST):
            moveLeft();
            break;
        case (NORD):
            moveUp();
            break;
        case(NORD_EST):
            moveUpRight();
            break;
        case(NORD_OUEST):
            moveUpLeft();
            break;
        case (SUD_EST):
            moveDownRight();
            break;
        case(SUD_OUEST):
            moveDownLeft();
            break;
        default:
            break;
    }
}

///DONE
void Plateau::moveUp(){
    if(position_joueur.l()>0 &&
    grille[(position_joueur.l()-1)*d_nc+position_joueur.c()]->getType()==VIDE){
        swap(grille[(position_joueur.l()-1)*d_nc+position_joueur.c()],grille[(position_joueur.l())*d_nc+position_joueur.c()]);
        position_joueur=Position(position_joueur.l()-1,position_joueur.c());
    }else{
        cout<<"DESINATION IMPOSSIBLE"<<endl;
    }
}


///DONE
void Plateau::moveDown(){
    if(position_joueur.l()<d_nl-1 &&
            grille[(position_joueur.l()+1)*d_nc+position_joueur.c()]->getType()==VIDE
    ){
        swap(grille[(position_joueur.l())*d_nc+position_joueur.c()],grille[(position_joueur.l()+1)*d_nc+position_joueur.c()]);
        position_joueur=Position(position_joueur.l()+1,position_joueur.c());
    }else{
        cout<<"DESINATION IMPOSSIBLE"<<endl;
    }
}
///DONE
void Plateau::moveLeft(){
    if(position_joueur.c()>0 &&
    grille[position_joueur.l()*d_nc+position_joueur.c()-1]->getType()==VIDE){
        swap(grille[position_joueur.l()*d_nc+position_joueur.c()],grille[position_joueur.l()*d_nc+position_joueur.c()-1]);
        position_joueur=Position(position_joueur.l(),position_joueur.c()-1);
    }else{
        cout<<"DESINATION IMPOSSIBLE"<<endl;
    }
}

///DONE
void Plateau::moveRight(){
    if(position_joueur.c()<d_nc-1 &&
            grille[position_joueur.l()*d_nc+position_joueur.c()+1]->getType()==VIDE
    ){
        swap(grille[position_joueur.l()*d_nc+position_joueur.c()],grille[position_joueur.l()*d_nc+position_joueur.c()+1]);
        position_joueur=Position(position_joueur.l(),position_joueur.c()+1);
    }else{
        cout<<"DESINATION IMPOSSIBLE"<<endl;
    }
}
void Plateau::moveUpRight(){
    if(position_joueur.l()>0  && position_joueur.c()<d_nc-1 &&
            grille[(position_joueur.l()-1)*d_nc+(position_joueur.c()+1)]->getType()==VIDE
    ){
        swap(grille[position_joueur.l()*d_nc+position_joueur.c()],grille[(position_joueur.l()-1)*d_nc+(position_joueur.c()+1)]);
        position_joueur=Position(position_joueur.l()-1,position_joueur.c()+1);
    }else{
        cout<<"DESINATION IMPOSSIBLE"<<endl;
    }
}
void Plateau::moveUpLeft(){
    if(position_joueur.l()>0  && position_joueur.c()>0 &&
            grille[(position_joueur.l()-1)*d_nc+(position_joueur.c()-1)]->getType()==VIDE
    ){
        swap(grille[position_joueur.l()*d_nc+position_joueur.c()],grille[(position_joueur.l()-1)*d_nc+(position_joueur.c()-1)]);
        position_joueur=Position(position_joueur.l()-1,position_joueur.c()-1);
    }else{
        cout<<"DESINATION IMPOSSIBLE"<<endl;
    }
}
void Plateau::moveDownRight(){
    if(position_joueur.l()<d_nl-1  && position_joueur.c()<d_nc-1
    && grille[(position_joueur.l()+1)*d_nc+(position_joueur.c()+1)]->getType()==VIDE
    ){
        swap(grille[position_joueur.l()*d_nc+position_joueur.c()],grille[(position_joueur.l()+1)*d_nc+(position_joueur.c()+1)]);
        position_joueur=Position(position_joueur.l()+1,position_joueur.c()+1);
    }else{
        cout<<"DESINATION IMPOSSIBLE"<<endl;
    }
}
void Plateau::moveDownLeft(){
    if(position_joueur.l()<d_nl-1  &&  position_joueur.c()>0 &&
            grille[(position_joueur.l()+1)*d_nc+(position_joueur.c()-1)]->getType()==VIDE
    ){
        swap(grille[position_joueur.l()*d_nc+position_joueur.c()],grille[(position_joueur.l()+1)*d_nc+(position_joueur.c()-1)]);
        position_joueur=Position(position_joueur.l()+1,position_joueur.c()-1);
    }else{
        cout<<"DESINATION IMPOSSIBLE"<<endl;
    }
}


void Plateau::fight(Participant& p1,Participant& p2){

}

