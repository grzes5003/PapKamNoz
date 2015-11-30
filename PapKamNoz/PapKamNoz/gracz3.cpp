#include "gracz3.h"

		Gracz3::Gracz3() {
		wygr.ja = 0;
		wygr.on = 0;
	}

Gracz3::~Gracz3() {
	//dtor
}

void Gracz3::reset() {

}

float Gracz3::win_ratio() {
	std::vector<int> *wsk = &wygr.wygrana_tab;
	std::vector<int>::iterator it1 = wsk->begin();
	std::vector<int>::iterator it2 = wsk->end();

	int ja = std::count( it1, it2, 1 );
	int on = std::count( it1, it2, 0 );

	return (ja / (on + ja));
}

Ruch Gracz3::podpuszczacz( int numer ) {
	Ruch _return;

	switch( numer ) {
	case 1:
		_return = Kamien;
		break;
	case 2:

		_return = Papier;
		break;
	case 3:

		_return = Nozyce;
		break;
	case 4:
		_return = Kamien;
		break;
	case 5:
		_return = Papier;
		break;
	case 6:
		_return = Nozyce;
		break;
	case 7:
		if( ruchy.at( 0 ) == Papier && ruchy.at( 1 ) == Nozyce && ruchy.at( 2 ) == Kamien ) {
			inteligent = true;
		}
		else {
			inteligent = false;
			return Kamien;
		}
		break;
	case 8:
		if( ruchy.at( 3 ) == Nozyce ) {
			zmienny_inteligent = true;
		}
		else {
			zmienny_inteligent = false;
		}
		break;
	default:
		std::cerr << "error podpuszczacz out of range";
	}
	numer_podpuszczacza++;
	return _return;
}

Ruch Gracz3::statystyka( int ile ) {
	struct staty {
		int ile_Pap;
		int ile_Kam;
		int ile_Noz;
	};
	float znaczna_dysproporcja_plus = 1.3;
	float znaczna_dysproporcja_minus = 0.75;

	staty ja;

	std::vector<Ruch> *wsk = &ruchy;

	std::vector<Ruch>::iterator it1 = wsk->end() - ile;
	std::vector<Ruch>::iterator it2 = wsk->end();

	ja.ile_Pap = std::count( it1, it2, 0 );
	ja.ile_Noz = std::count( it1, it2, 1 );
	ja.ile_Kam = std::count( it1, it2, 2 );

	wsk = &moje_ruchy;

	staty on;

	wsk = &ruchy;

	it1 = wsk->end() - ile;
	it2 = wsk->end();

	on.ile_Pap = std::count( it1, it2, 0 );
	on.ile_Noz = std::count( it1, it2, 1 );
	on.ile_Kam = std::count( it1, it2, 2 );

	//
	if( ja.ile_Kam>0 && ja.ile_Noz >0 && ja.ile_Pap > 0 && on.ile_Kam > 0 && on.ile_Noz >0 && on.ile_Pap > 0 ) {
		if( (ja.ile_Noz / on.ile_Kam) >= znaczna_dysproporcja_minus )
			return Papier;
		else if( (ja.ile_Kam / on.ile_Pap) >= znaczna_dysproporcja_minus )
			return Nozyce;
		else if( (ja.ile_Pap / on.ile_Noz) >= znaczna_dysproporcja_minus )
			return Kamien;


		if( (on.ile_Noz / ja.ile_Kam) >= znaczna_dysproporcja_plus )
			return Kamien;
		else if( (on.ile_Kam / ja.ile_Pap) >= znaczna_dysproporcja_plus )
			return Papier;
		else if( (on.ile_Pap / ja.ile_Noz) >= znaczna_dysproporcja_plus )
			return Nozyce;

		if( (on.ile_Kam / on.ile_Noz) > 1 && (on.ile_Kam / on.ile_Pap) > 1 )
			return Papier;
		else if( (on.ile_Noz / on.ile_Kam) > 1 && (on.ile_Noz / on.ile_Pap) > 1 )
			return Kamien;
		else if( (on.ile_Pap / on.ile_Kam) > 1 && (on.ile_Pap / on.ile_Noz) > 1 )
			return Nozyce;

		if( ja.ile_Kam < ja.ile_Noz && ja.ile_Kam < ja.ile_Pap )
			return Nozyce;
		else if( ja.ile_Noz < ja.ile_Kam && ja.ile_Noz < ja.ile_Pap )
			return Papier;
		else
			return Kamien;
	}
	else {
		//mao danych xd
		if( ja.ile_Kam == 0 )
			return Kamien;
		else if( ja.ile_Noz == 0 )
			return Nozyce;
		else if( ja.ile_Pap == 0 )
			return Papier;
		else {
			if( ja.ile_Kam < ja.ile_Noz && ja.ile_Kam < ja.ile_Pap )
				return Nozyce;
			else if( ja.ile_Noz < ja.ile_Kam && ja.ile_Noz < ja.ile_Pap )
				return Papier;
			else
				return Kamien;
		}

	}

}

void Gracz3::przedstawSie() {
	std::cout << "GrzegorZ Kulinski" << std::endl;
}

bool Gracz3::czy_wygralem( std::vector<Ruch> ja, std::vector<Ruch> on, int kiedy ) { //kiedy: od 0 licze
	if( (kiedy >= ja.size()) || (kiedy >= on.size()) ) {
		std::cerr << "blad: iterator out of range" << std::endl;
	}
	if( ja.size() != on.size() ) {
		std::cerr << "tablice roznej wielkosci" << std::endl;
	}

	if( ja.at( kiedy ) == kontrator( on.at( kiedy ) ) )
		return true;
	else
		return false;
}

Ruch Gracz3::kontrator( Ruch input ) {
	if( input == Kamien ) {
		return Papier;
	}
	else if( input == Papier ) {
		return Nozyce;
	}
	else if( input == Nozyce ) {
		return Kamien;
	}
	else {
		throw "WTF";
	}
}
/*
Ruch Gracz3::ruch(Ruch stary_ruch){
Ruch do_returna = stary_ruch;
ruchy.push_back( stary_ruch );
switch( ruchy.size() ) {
case 1:
do_returna = Papier;
metoda = nope;
break;
case 2:
do_returna = Papier;
metoda = nope;
break;
case 3:
if( ruchy.at( 1 ) == ruchy.at( 2 ) ) {
do_returna = kontrator( ruchy.at( 1 ) );
metoda = stala;
}
else if( ruchy.at( 1 ) != ruchy.at( 2 ) ) {
////technika czego nie bylo
if( ruchy.at( 1 ) == (Kamien || Papier) & ruchy.at( 2 ) == (Kamien || Papier) )
do_returna = Kamien;
else if( ruchy.at( 1 ) == (Kamien || Nozyce) & ruchy.at( 2 ) == (Kamien || Nozyce) )
do_returna = Nozyce;
else if( ruchy.at( 1 ) == (Papier || Nozyce) & ruchy.at( 2 ) == (Papier || Nozyce) )
do_returna = Papier;
////END czego nie bylo
metoda = co_2;
}
break;
case 4: //mam 3 odp przeciwnika
if( ruchy.at( 1 ) == ruchy.at( 2 ) && ruchy.at( 1 ) == ruchy.at( 3 ) ) {
std::cout << "lolz" << std::endl;
do_returna = kontrator( ruchy.at( 1 ) );
metoda = stala;
}
else if( ruchy.at( 1 ) != ruchy.at( 2 ) != ruchy.at( 3 ) ) {
do_returna = kontrator( ruchy.at( 1 ) );
metoda = co_3;
}
break;
case 5:

if( (ruchy.at( 1 ) != ruchy.at( 4 )) && (ruchy.at( 1 ) == ruchy.at( 3 )) && (ruchy.at( 2 ) == ruchy.at( 4 )) ) {
do_returna = kontrator( ruchy.at( 1 ) );
metoda = co_2;
}
else if( ruchy.at( 1 ) == ruchy.at( 2 ) && ruchy.at( 1 ) == ruchy.at( 3 ) && ruchy.at( 1 ) == ruchy.at( 4 ) ) {
do_returna = kontrator( ruchy.at( 1 ) );
metoda = stala;
}
else if( metoda == co_3 && (ruchy.at( 1 ) == ruchy.at( 4 )) ) {
metoda = co_3;
}
else{
do_returna = Papier;
metoda = rand;
}
//( (ruchy.at( 0 ) != ruchy.at( 3 )) && (ruchy.at( 0 ) != ruchy.at( 2 )) && (ruchy.at( 0 ) != ruchy.at( 1 )) )
default:
if( metoda == stala ) {
do_returna = kontrator( ruchy.at( 1 ) );
}
else if(metoda == co_2) {
if( ruchy.at( ruchy.size() - 1 ) == ruchy.at( 1 ) ) {
do_returna = kontrator( ruchy.at( 2 ) );
}
else {
do_returna = kontrator( ruchy.at( 1 ) );
}
}
else if( metoda == co_3 ) {
if( ruchy.at( ruchy.size() - 1 ) == ruchy.at( 1 ) ) {
do_returna = kontrator( ruchy.at( 2 ) );
}
else if( ruchy.at( ruchy.size() - 1 ) == ruchy.at( 2 ) ) {
do_returna = kontrator( ruchy.at( 3 ) );
}
else if( ruchy.at( ruchy.size() - 1 ) == ruchy.at( 3 ) ) {
do_returna = kontrator( ruchy.at( 1 ) );
}
else {
throw "WTF zla co_3";
}
}
else if( metoda == rand ) {
//Ruch chwila = Ruch( _dis( _gen ) );
//do_returna = kontrator( chwila );
do_returna = Papier;
//if( ruchy.at( ruchy.size() - 1 ) == Papier ) {
//	do_returna = Kamien;
//}
}

break;
}
if( metoda == stala ) std::cout << "     ***stala***" << std::endl;
else if( metoda == co_2 ) std::cout << "     co_2" << std::endl;
else if( metoda == co_3 ) std::cout << "     co_3" << std::endl;
else if( metoda == rand ) std::cout << "     rand" << std::endl;
else if( metoda == nope ) std::cout << "     ***brak***" << std::endl;

return do_returna;
}
*/

Ruch Gracz3::jaki_ruch_okresu( std::vector<Ruch> vec, int ile_ostatnich, int okres ) {
	std::vector<Ruch> frag;
	std::vector<Ruch>::iterator it;
	//std::cout << potyczki.size() << " " << ile_ostatnich << std::endl;
	it = vec.end() - ile_ostatnich;
	frag.assign( it, vec.end() );

	int ile_razy = floor( frag.size() / okres );

	return frag.at( frag.size() - (okres*ile_razy) + 1 );
}

int Gracz3::analizer( std::vector<Ruch> potyczki, int ile ) {
	//-2 blad:out of range; -1: nie ma wzoru; 0++: taki ma okres  
	//std::cout << potyczki.size() << " " << ile << std::endl;
	//std::cout << ile;
	int modulo = ile % potyczki.size();
	bool ile_dziala;

	if( potyczki.size() == 1 ) return -1;

	if( ile == 0 ) { return -1; }

	for( unsigned int i = 0; i < floor( potyczki.size() / ile ); i++ ) {
		for( unsigned int x = 0; x < ile; x++ ) {
			if( x < modulo ) {
				if( potyczki.at( potyczki.size() - modulo + x ) == potyczki.at( ile*i + x ) )
					ile_dziala = true;
				else
					ile_dziala = false;
			}
			else {
				if( potyczki.at( potyczki.size() - x - 1 ) == potyczki.at( ile * i + x ) )
					ile_dziala = true;
				else
					ile_dziala = false;
			}
			if( !ile_dziala ) x = ile;
		}
		if( !ile_dziala ) i = floor( potyczki.size() / ile );
	}

	if( ile_dziala && ile == potyczki.size() ) {
		ile_dziala = false;
	}

	if( ile_dziala ) {
		return (potyczki.size() - ile);
	}
	else {

		return analizer( potyczki, ile - 1 );

	}
}
//floor zaokraglanie w dol
int Gracz3::analizer_up( std::vector<Ruch> potyczki, int ile_ostatnich ) {
	std::vector<Ruch> frag;
	std::vector<Ruch>::iterator it;
	//std::cout << potyczki.size() << " " << ile_ostatnich << std::endl;
	it = potyczki.end() - ile_ostatnich;
	frag.assign( it, potyczki.end() );

	/*for( int i = 0; i < frag.size(); i++ ) {
	std::cout << frag.at( i ) << "  ";
	}
	std::cout << std::endl;*/

	return analizer( frag, frag.size() );
}


Ruch Gracz3::ruch( Ruch stary_ruch ) {
	Ruch _return;

	//czy inteligent

	if( limiter_szesciu >= 1 && limiter_szesciu <= 9 ) {
		_return = podpuszczacz( numer_podpuszczacza );
	}


	if( limiter_szesciu >= 4 ) { //zapisuj ruchy


								 //badanie okresu -> brak okresu;
		if( limiter_szesciu > 20 ) {
			if( analizer_up( ruchy, 16 ) == -1 ) {
				if( limiter_szesciu <= 50 )
					_return = statystyka( limiter_szesciu - 10 );
				else
					_return = statystyka( 40 );
			}
			else if( analizer_up( ruchy, 16 ) >0 ) {
				_return = kontrator( jaki_ruch_okresu( ruchy, 16, analizer_up( ruchy, 16 ) ) );
			}
		}
		else if( limiter_szesciu > 8 ) {
			if( analizer_up( ruchy, ruchy.size() ) == -1 ) {
				_return = statystyka( ruchy.size() );
			}
			else if( analizer_up( ruchy, ruchy.size() ) >0 ) {
				_return = kontrator( jaki_ruch_okresu( ruchy, ruchy.size(), analizer_up( ruchy, ruchy.size() ) ) );
			}
		}
		//jesli wygrywa za duzo
		if( limiter_szesciu > 50 ) {
			if( win_ratio() < 0.75 && limiter_szesciu > 50 && kiedy_badanie > int( 10000 / limiter_szesciu ) ) { //pewnie do zmiany, z liczba zagran 
				podpuszczacz( numer_podpuszczacza );
			}
		}
	}

	kiedy_badanie++;

	if( numer_podpuszczacza >= 9 ) {
		kiedy_badanie = 0;
		numer_podpuszczacza = 1;
	}

	if( limiter_szesciu >= 4 ) { //update tablic z ruchami
		ruchy.push_back( stary_ruch );
		moje_ruchy.push_back( _return );

		if( limiter_szesciu >= 5 ) {


			if( czy_wygralem( moje_ruchy, ruchy, ruchy.size() - 1 ) ) {
				wygr.ja++;
				wygr.wygrana_tab.push_back( 1 );
			}
			else {
				wygr.on++;
				wygr.wygrana_tab.push_back( 0 );
			}
		}
	}
	if( limiter_szesciu == 99 ) {
		//std::cout << "lol";
	}

	limiter_szesciu++;
	return _return;
}

Ruch Gracz3::symulator( Ruch poprzedni_moj ) {
	moje_ruchy.push_back( poprzedni_moj );

	return Kamien;
}


/*if( inteligent && limiter_szesciu >8 ) {
if( zmienny_inteligent ) {

}
else {

}

}
else if( !inteligent && limiter_szesciu > 8 ) {

switch( analizer(ruchy, ruchy.size()) ) {
case -1:
std::cout << "randomer" << std::endl;
_return = Kamien;
case 1:
_return = kontrator( ruchy.at( ruchy.size() - 1 ) );
default:
_return = kontrator( ruchy.at( ruchy.size() % analizer( ruchy, ruchy.size() ) ) );
}
}*/