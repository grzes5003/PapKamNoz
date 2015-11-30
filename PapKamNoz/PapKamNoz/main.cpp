#include "graj.h"

class Gracz1 : public Gracz {
//	std::random_device _rd;
//
//	std::mt19937 _gen;
//
//	std::uniform_int_distribution<> _dis;
//
//public:
//	Gracz1() : _gen( _rd() ), _dis( 0, 2 ) {
//
//	}
//
//	virtual Ruch ruch( Ruch poprzedniRuchPrzeciwnika ) {
//		return Ruch( _dis( _gen ) );
//	}
//	void przedstawSie() {
//		std::cout << "Szymon Palka";
//	}
//	void reset() {
//
//	}
	int dawny = rand() % 3;
	int bardzoDawny = rand() % 3;
	int mojdawny = rand() % 3;
	int lotto = rand() % 3;

public:
	Gracz1() {
		dawny;
		bardzoDawny;
		mojdawny;
		lotto;

	}

	virtual Ruch ruch( Ruch poprzedniRuchPrzeciwnika ) {
		int bardzoDawny = dawny;
		dawny = poprzedniRuchPrzeciwnika;
		if( dawny == lotto ) {
			mojdawny = rand() % 3;
		}
		if( dawny == 0 ) {
			if( bardzoDawny == 0 ) {
				mojdawny = 1;
			}
			else {
				if( mojdawny == 2 )
					mojdawny = 0;
				if( mojdawny == 0 )
					mojdawny = 2;
				if( mojdawny == 1 )
					mojdawny = 2;
			}
		}
		if( dawny == 1 ) {
			if( bardzoDawny == 1 ) {
				mojdawny = 2;
			}
			else {
				if( mojdawny == 2 )
					mojdawny = 0;
				if( mojdawny == 0 )
					mojdawny = 1;
				if( mojdawny == 1 )
					mojdawny = 0;
			}
		}
		if( dawny == 2 ) {
			if( bardzoDawny == 2 ) {
				mojdawny = 0;
			}
			else {
				if( mojdawny == 2 )
					mojdawny = 1;
				if( mojdawny == 0 )
					mojdawny = 1;
				if( mojdawny == 1 )
					mojdawny = 2;
			}
		}
		lotto = rand() % 3;
		return Ruch( mojdawny );

	}
	void przedstawSie() {
		std::cout << "Grzegorz Sarapata";
	}
	void reset() {

	}
};



class Gracz2 : public Gracz {
	int _licznik;
public:
	Gracz2() {
		_licznik = 0;
	}
	virtual Ruch ruch( Ruch poprzedniRuchPrzeciwnika ) {
		// nie chcialem castowac
		/*if( _licznik == 0 ) {
			_licznik++;
			return Ruch::Papier;
		}
		if( _licznik == 1 ) {
			_licznik++;
			return Ruch::Nozyce;
		}
		if( _licznik == 2 ) {
			_licznik = 0;
			return Ruch::Kamien;
		}*/
		return poprzedniRuchPrzeciwnika;
	}
	void reset() {

	}
	virtual void przedstawSie() {
		std::cout << "Tomasz Pedzimaz";
	}
};

int main() {

	Gracz1 gracz1;
	Gracz3 gracz2;
	Gra gra( gracz1, gracz2 );
	gra.graj();
	char s;
	cin >> s;
	return 0;
}


