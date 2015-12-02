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
	int _licznik;
	int _reset;
public:
	Gracz1() {
		_licznik = 0;
		_reset = 0;
	}
	virtual Ruch ruch( Ruch poprzedniRuchPrzeciwnika ) {
		// nie chcialem castowac

		if( _reset == 0 ) {
			if( _licznik == 0 ) {
				_licznik = 2;
				_reset++;
				return Ruch::Papier;
			}
			if( _licznik == 1 ) {
				_licznik = 0;
				_reset++;
				return Ruch::Nozyce;
			}
			if( _licznik == 2 );
			_licznik = 1;
			_reset++;
			return Ruch::Kamien;
		}
		if( _reset == 1 ) {
			if( _licznik == 0 || _licznik == 1 ) {
				_licznik = 2;
				_reset++;
				return Ruch::Papier;
			}
			if( _licznik == 2 );
			_licznik = 1;
			_reset++;
			return Ruch::Kamien;
		}
		if( _reset == 2 || _reset == 3 ) {
			_reset++;
			return Ruch::Papier;
		}
		if( _reset == 4 ) {
			_reset = 0;
			return Ruch::Kamien;
		}
	}
	void reset() {

	}
	virtual void przedstawSie() {
		std::cout << "Bartosz Pietrzyk";
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


