//
// Created by oreste on 11/11/22.
//

#ifndef CHASSE_PAR_FAUVES_PARTICIPANT_H
#define CHASSE_PAR_FAUVES_PARTICIPANT_H


#include "Position.h"
#include "Occupant.h"

class Participant:public Occupant {
    unsigned int vie;
public:

    explicit Participant(unsigned int vie);



    unsigned int getVie() const;

    void setVie(unsigned int vie);

    //la methode bouger doit etre virtuel, car chaque participant doit buger a sa maniere
    virtual void bouger(const Position&)=0;
    unsigned int getType()const override =0;


};


#endif //CHASSE_PAR_FAUVES_PARTICIPANT_H
