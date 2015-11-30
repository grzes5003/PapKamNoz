#include "gracz.h"
#include<iostream>

std::ostream& operator<<( std::ostream& s, Ruch w ) {
	return s << ((w == Kamien) ? "Kamien" : (w == Papier) ? "Papier" : "Nozyce");
}