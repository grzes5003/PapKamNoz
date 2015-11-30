//czy inteligent

#define mpa false;
#if mpa 


if( limiter_szesciu >= 1 && limiter_szesciu <= 8 ) {
	_return = podpuszczacz( numer_podpuszczacza );
}


if( limiter_szesciu > 3 ) { //zapisuj ruchy
							//badanie okresu -> brak okresu;
	if( limiter_szesciu > 20 ) {
		if( analizer_up( ruchy, 16 ) == -1 ) { //bez szablonu
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

if( numer_podpuszczacza >= 8 ) {
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
	std::cout << "lol";
}

limiter_szesciu++;
return _return;
#endif