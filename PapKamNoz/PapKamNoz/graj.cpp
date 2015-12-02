#include "graj.h"

Gra::Gra( Gracz & gracz1, Gracz & gracz2 ) : _gracz1( gracz1 ), _gracz2( gracz2 ) {
	_macierzWynikow = { { { { Remis, Wygral_Drugi, Wygral_Pierwszy } },{ { Wygral_Pierwszy, Remis, Wygral_Drugi } },{ { Wygral_Drugi, Wygral_Pierwszy, Remis } } } };

	_ktoWygralGre[0] = _ktoWygralGre[1] = _ktoWygralGre[2] = 0;

	zeruj();
}

void Gra::graj() {

	Ruch staryRuch1 = Papier;
	Ruch staryRuch2 = Papier;
	for( int pojedynek = 0; pojedynek < 10; pojedynek++ ) {
		for( int i = 0; i < 1000; i++ ) {
			Ruch ruch1 = _gracz1.ruch( staryRuch2 );
			Ruch ruch2 = _gracz2.ruch( staryRuch1 );
			//

			/*if( ruch1 == Papier ) std::cout << "    ten typ papier" << std::endl;
			else if( ruch1 == Kamien ) std::cout << "    ten typ  kamien" << std::endl;
			else if( ruch1 == Nozyce ) std::cout << "    ten typ  nozyce" << std::endl;
			if( ruch2 == Papier ) std::cout << "    ja papier" << std::endl;
			else if( ruch2 == Kamien ) std::cout << "    ja  kamien" << std::endl;
			else if( ruch2 == Nozyce ) std::cout << "    ja  nozyce" << std::endl;*/

			//
			_ktoWygralPojedynek[ktoWygral( ruch1, ruch2 )]++;
			staryRuch1 = ruch1;
			staryRuch2 = ruch2;
		}
		_ktoWygralGre[pokazWynikiPojedynku()] += abs( _ktoWygralPojedynek[Wygral_Drugi] - _ktoWygralPojedynek[Wygral_Pierwszy] );
		zeruj();
	}
	pokazWynikiGry();
}

void Gra::zeruj() {
	_ktoWygralPojedynek[0] = _ktoWygralPojedynek[1] = _ktoWygralPojedynek[2] = 0;
	//_gracz1.reset();
	//_gracz2.reset();
}
