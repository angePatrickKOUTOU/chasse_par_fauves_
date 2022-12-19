//
// Created by oreste on 09/11/22.
//

#include <iostream>
using namespace std;
enum Occupants{
    VIDE=0,
    LION,
    CHIEN,
    JAGUAR,
    PIEGE,
    JOUEUR,
    OBSTACLE,
};

enum Directions{
    NORD,
    EST,
    OUEST,
    SUD,
    NORD_OUEST,
    NORD_EST,
    SUD_OUEST,
    SUD_EST
};
const unsigned int TAILLE_MIN=6;

