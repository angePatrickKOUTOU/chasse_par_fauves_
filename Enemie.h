//
// Created by oreste on 12/11/22.
//

#ifndef CHASSE_PAR_FAUVES_ENEMIE_H
#define CHASSE_PAR_FAUVES_ENEMIE_H


#include "Participant.h"

class Enemie : public Participant{
    int puissanceAttaque;

public:
    Enemie(unsigned int vie, int puissanceAttaque);

    //detruire un element dans le meme case
    void attacquer(Participant& p){
        if(p.getVie()>getVie()){

        }else{

        }
    }

    //changer la position pour s'approcher de la cible principale
    virtual void bouger(const Position&)=0;
    virtual unsigned int getType()const =0;

};


#endif //CHASSE_PAR_FAUVES_ENEMIE_H
