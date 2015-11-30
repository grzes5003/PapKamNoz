#ifndef GRACZ_H
#define GRACZ_H
#include<iostream>
#include<array>
#include<cmath>
#include <random>

enum Ruch { Papier, Nozyce, Kamien };
enum Wynik { Remis, Wygral_Pierwszy, Wygral_Drugi };

class Gracz {
public:
	virtual void przedstawSie() = 0;
	virtual Ruch ruch( Ruch poprzedniRuchPrzeciwnika ) = 0;
	virtual void reset() = 0;
};

#endif // GRACZ_H