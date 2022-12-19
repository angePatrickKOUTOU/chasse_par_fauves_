cmake_minimum_required(VERSION 3.23)
project(chasse_par_fauves)

set(CMAKE_CXX_STANDARD 14)

add_executable(chasse_par_fauves main.cpp Position.cpp Position.h Plateau.cpp Plateau.h constants.cpp Jeu.cpp Jeu.h Joueur.cpp Joueur.h Participant.cpp Participant.h Occupant.cpp Occupant.h Jaguar.cpp Jaguar.h Piege.cpp Piege.h Obstacle.cpp Obstacle.h Enemie.cpp Enemie.h Lion.cpp Lion.h Vide.cpp Vide.h)
