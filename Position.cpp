//
// Created by oreste on 09/11/22.
//

#include <vector>
#include "Position.h"


/**
 *  Le constructeur par défaut (0,0)
 */
//Position::Position():Position{0,0}{}

/**
 * Constructeur d'affectation pour d_l,et d_c avec tous la meme valeur
 * @param[in] xy la valeur
 * @warning xy doi etre superieur ou egal à zero
 */
Position::Position(unsigned int xy):Position{xy,xy}{}

/**
 * Constructeur d'affectation pour d_l,et d_c
 * @param[in] x la valeur de d_l
 * @param[in] y la valeur de d_c
 * @warning x et y doivent etre superieur ou égal à zero
 */
Position::Position(unsigned int x, unsigned int y):
        d_l{x},
        d_c{y}
{

}
/**
 * @return la valeur de d_l
 */
unsigned int Position::l()const
{
    return d_l;
}
/**
 * @return la valeur de d_c
 */
unsigned int Position::c()const
{
    return d_c;
}

/**
 * Modifieur de d_l
 * @param[in] x La valeur
 */
void Position::l(unsigned int x)
{
    assert(x > 0);
    d_l=x;
}

/**
 * Modifieur de d_c
 * @param[in] y La valeur
 */
void Position::c(unsigned int y)
{
    assert(y >= 0);
    d_c=y;
}

/**
 * Operateur d'affectation
 * @param[in] p la nouvelle position
 * @return le référance du nouvelle position
 */
Position& Position::operator=(const Position& p){
    if (this != &p) {
        d_l=p.d_l;
        d_c=p.d_c;
    }
    return *this;
}

/**
 * Operateur d'égalité
 * @param[in] p la position pour effectuer la comparaison
 * @return vrai si les valeurs des 2 positions sont égaux, ou identiques
 */
bool Position::operator==(const Position& p)const{
    if(this != &p){
        return p.d_l==this->d_l && p.d_c== this->d_c;
    }
    return true;
}

/**
 * Teste la validité du position
 * @param[in] p la position
 * @return vrai si la position p.x et p.y sont supérieur à zero
 */
bool static valide(const Position& p){
    return p.l() >=0 && p.c()>=0;
}

/**
 * La representation textuel d'une position
 * @return (x,y) en texte
 */
std::string Position::toString()const
{
    return "("+std::to_string(d_l)+","+std::to_string(d_c)+")";
}


Position Position::operator+(const Directions& direction)const{
    switch (direction) {
        case NORD:
            return Position(d_l,d_c-1);
            break;
        case SUD:
            return Position(d_l,d_c+1);
            break;
        case EST:
            return Position(d_l+1,d_c);
            break;
        case OUEST:
            return Position(d_l+1,d_c);;
            break;
        case NORD_EST:
            return Position(d_l+1,d_c-1);
            break;
        case NORD_OUEST:
            return Position(d_c-1,d_c-1);
            break;
        case SUD_EST:
            return Position(d_l+1,d_c+1);
            break;
        case SUD_OUEST:
            return Position(d_l-1,d_c+1);
            break;
        default:
            return Position(d_l,d_c);
    }
}

/**
 * calcule la distance entre 2 points
 * @param p point de comparaison
 * @return la distance
 */
double Position::distance(const Position& p)const{
    return sqrt(
            (p.l() - d_l)*(p.l()-d_l)
            +
             (p.c() - d_c)*(p.c()-d_c)
    );
}


/**
 * La position la plus proche pour se rapprocher d'un pas
 * @param p
 * @return
 */
Position Position::plusProche(const Position& p)const{

    vector<Position> v{
            Position(p.d_l+1,p.d_c),
            Position(p.d_l-1,p.d_c),
            Position(p.d_l,p.d_c+1),
            Position(p.d_l,p.d_c-1),
            Position(p.d_l+1,p.d_c+1),
            Position(p.d_l-1,p.d_c-1),
            Position(p.d_l+1,p.d_c-1),
            Position(p.d_l-1,p.d_c+1),
    };

    double dis= RAND_MAX;
    Position* pos;
    for(auto & x : v){
        if(distance(x) < dis){
            dis=distance(p);
            pos=&x;
        }
    }
    return *pos;
}