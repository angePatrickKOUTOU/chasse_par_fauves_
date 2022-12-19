//
// Created by oreste on 11/11/22.
//

#include "Jeu.h"

Jeu::Jeu( const Plateau &plateau):
plateau{plateau}{}
void Jeu::bouger(Participant& p,Directions& direction){
    switch (direction) {
        case (SUD):
            // p.setPosition(plateau.jouable(p.getPosition());
            break;
        case(EST):
            break;
        case(OUEST):
            break;
        case (NORD):
            break;
        case(NORD_EST):
            break;
        case(NORD_OUEST):
            break;
        case (SUD_EST):
            break;
        case(SUD_OUEST):
            break;
        default:
            break;
    }
}

void Jeu::lancer(){
    bool end=false;
    while(!end){
        //std::cout.flush();
        afficher();
        saisir();
        MAJ();
        performOperations();
        performCheck();
    }
    if(true){}

}

void Jeu::afficher()const{
    cout<<"plateau has "<<plateau.get_nc()<<" cols and "<<plateau.get_nl()<<" lignes"<<endl;
    plateau.afficher();
}
void Jeu::saisir(){
    Directions d;
    afficherDirections();
    std::cout<<"\tDirection $ ";
    unsigned int x;
    std::cin>>x;
    d=(Directions)x;
    cout<<"Direction is "<<d<<endl;
    plateau.bouger(d);
}

void Jeu::MAJ(){}
void Jeu::performOperations(){}
void Jeu::performCheck(){}

/*
Jeu::Jeu(const Joueur &joueur, const Plateau &plateau) : joueur(joueur), plateau(plateau) {}
void Jeu::afficher()const{
    for(int x=0;x<plateau.getGrille().size();x++){
        for(int y=0;y<plateau.getLargeur();y++){
            std::cout<<plateau.getGrille()[x][y].getType()<<"\t";
        }std::cout<<std::endl;
    }
}
*/


void Jeu::afficherOccupants()const{
    cout<<endl<<endl;
    cout<<"  --------- OCCUPANTS ---------";
    cout<<"VIDE :"<< VIDE<<endl;
    cout<<"LION :"<< LION<<endl;
    cout<<"CHIEN :"<< CHIEN<<endl;
    cout<<"JAGUAR :"<< JAGUAR<<endl;
    cout<<"PIEGE :"<< PIEGE<<endl;
    cout<<"JOUEUR :"<< JOUEUR<<endl;
    cout<<"OBSTACLE :"<< OBSTACLE<<endl;

    cout<<endl;
    cout<<"  --------- OCCUPANTS ---------";
    cout<<endl<<endl;

}

void Jeu::afficherDirections()const{

    cout<<"  --------- DIRECTIONS POSSIBLE ---------"<<endl;
    cout<<"NORD :"<< NORD<<endl;
    cout<<"EST :"<< EST<<endl;
    cout<<"OUEST :"<< OUEST<<endl;
    cout<<"SUD :"<< SUD<<endl;
    cout<<"NORD_OUEST :"<< NORD_OUEST<<endl;
    cout<<"NORD_EST :"<< NORD_EST<<endl;
    cout<<"SUD_OUEST :"<< SUD_OUEST<<endl;
    cout<<"SUD_EST :"<< SUD_EST<<endl;

    cout<<"  --------- END DIRECTIONS ---------"<<endl;

}
