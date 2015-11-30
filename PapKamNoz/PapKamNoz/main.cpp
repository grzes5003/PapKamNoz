#include "graj.h"

class Gracz1 : public Gracz {
	std::random_device _rd;

	std::mt19937 _gen;

	std::uniform_int_distribution<> _dis;

public:
	Gracz1() : _gen( _rd() ), _dis( 0, 2 ) {

	}

	virtual Ruch ruch( Ruch poprzedniRuchPrzeciwnika ) {
		return Ruch( _dis( _gen ) );
	}
	void przedstawSie() {
		std::cout << "Szymon Palka";
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
		if( _licznik == 0 ) {
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
		}
	}
	void reset() {

	}
	virtual void przedstawSie() {
		std::cout << "Tomasz Pedzimaz";
	}
};

int main() {

	Gracz2 gracz1;
	Gracz3 gracz2;
	Gra gra( gracz1, gracz2 );
	gra.graj();
	char s;
	cin >> s;
	return 0;
}


