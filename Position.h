//
// Created by oreste on 09/11/22.
//

#ifndef CHASSE_PAR_FAUVES_POSITION_H
#define CHASSE_PAR_FAUVES_POSITION_H

#include <cassert>
#include<string>
#include"constants.cpp"
#include <cmath>

class Position {
private:
    unsigned int d_l;
    unsigned int d_c;

public:
    Position(unsigned int l,unsigned int c);
    explicit Position(unsigned int xy);
    //Position();

    unsigned int l()const;
    unsigned int c()const;
    void l(unsigned int );
    void c(unsigned int );

    Position& operator=(const Position& );
    bool operator==(const Position& )const;
    bool static valide(){return true;}
    std::string toString()const;

    double distance(const Position&)const;
    Position plusProche(const Position& p)const;

    Position operator+(const Directions& direction)const;




};


#endif //CHASSE_PAR_FAUVES_POSITION_H
