#ifndef GRA_H
#define GRA_H
#include "gracz.h"
#include "gracz3.h"

using namespace std;

class Gra {
	std::array<int, 3> _ktoWygralPojedynek;
	std::array<int, 3> _ktoWygralGre;
	Gracz & _gracz1;
	Gracz & _gracz2;

	std::array<std::array<Wynik, 3>, 3> _macierzWynikow;

public:
	Gra( Gracz & gracz1, Gracz & gracz2 );
	void graj();
	void zeruj();
	Wynik ktoWygral( Ruch ruchGracza1, Ruch ruchGracza2 )const {


		return _macierzWynikow[ruchGracza1][ruchGracza2];
	}
	Wynik pokazWynikiPojedynku()const {
		for( int i = 0; i < _ktoWygralPojedynek.size(); ++i ) {
			std::cout << _ktoWygralPojedynek[i] << " ";
		}

		if( _ktoWygralPojedynek[Wygral_Pierwszy] == _ktoWygralPojedynek[Wygral_Drugi] ) {
			std::cout << "Remis!\n";
			return Wynik::Remis;
		}
		else {
			if( _ktoWygralPojedynek[Wygral_Pierwszy] > _ktoWygralPojedynek[Wygral_Drugi] ) {
				std::cout << "Pojedynek wygral gracz: "; _gracz1.przedstawSie(); std::cout << std::endl;
				std::cout << "Zdobyl " << _ktoWygralPojedynek[Wygral_Pierwszy] - _ktoWygralPojedynek[Wygral_Drugi] << " punktow\n";
				return Wynik::Wygral_Pierwszy;
			}
			else {
				std::cout << "Pojedynek wygral gracz: "; _gracz2.przedstawSie(); std::cout << std::endl;
				std::cout << "Zdobyl " << _ktoWygralPojedynek[Wygral_Drugi] - _ktoWygralPojedynek[Wygral_Pierwszy] << " punktow\n";
				return Wynik::Wygral_Drugi;
			}
		}
	}
	void pokazWynikiGry()const {
		std::cout << std::endl << std::endl << std::endl;
		for( int i = 0; i < _ktoWygralGre.size(); ++i ) {
			std::cout << _ktoWygralGre[i] << " ";
		}

		if( _ktoWygralGre[Wygral_Pierwszy] == _ktoWygralGre[Wygral_Drugi] ) {
			std::cout << "Remis!\n";
		}
		else {
			if( _ktoWygralGre[Wygral_Pierwszy] > _ktoWygralGre[Wygral_Drugi] ) {
				std::cout << "Gre wygral gracz: "; _gracz1.przedstawSie(); std::cout << std::endl;
				std::cout << "Zdobyl " << _ktoWygralGre[Wygral_Pierwszy] - _ktoWygralGre[Wygral_Drugi] << " punktow\n";
			}
			else {
				std::cout << "Gre wygral gracz: "; _gracz2.przedstawSie(); std::cout << std::endl;
				std::cout << "Zdobyl " << _ktoWygralGre[Wygral_Drugi] - _ktoWygralGre[Wygral_Pierwszy] << " punktow\n";
			}
		}
	}
};


#endif // GRAJ_H