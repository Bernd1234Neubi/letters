#include <iostream>
#include <string>
#include <array>
#include <fstream>
#include <sstream>
#include <map>
#include <random>
#include "ownUtil.hpp"


using namespace std;

//////////////////////////////////////////////////////////////////////////////////////////
//zeichenkette erstellen und durch ziehen einzelner buckstaben ein langes wort erstellen//
//////////////////////////////////////////////////////////////////////////////////////////
Alles Unsinn



int main() {
	string eingabe{};					//ausgangswort
	string eingabe2;				//erstellt eingabe2 plus jedes zweite Zeichen einen seperator | (nur für übersichtlichere Ausgabe benötigt
	unsigned int kopie = 0;
	string wortNeu;					//erratenes wort
	string alleWoerter;				//vergleichsliste? (mit alleWoerter.txt soll wortNeu verglichen werden
	char auswahl[1] = {};					//temporäre ablage für den gewählten buchstaben
	char auswahl1 = 0;
	bool pruefer = true;
	unsigned int anzahl = 0;					//anzahl der Buchstaben im ausgangswort
	string name;
	int schalter;
	//srand(time(0));

	//Vorbereitung des Spiels
	cout << "Buchstaben pfluecken" << endl;
	cout << "~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "Wie heisst du?" << endl;
	cin >> name;
	cout << endl << "Deine Aufgabe wird sein aus dem folgenden Buchstabensalat, ein Wort zu bilden! \n" << endl;
	cout << "Wieviele Buchstaben moechtest du sortieren (max 20)?" << endl;

	benutzereingabe(anzahl);						//ignoriere buchstabeneingaben	
	//anzahl = 20;
	vergleichen(anzahl);
	for (unsigned int i = 0; i < anzahl; i++) {					//abfrage der festgelegten anzahl an Versuchen
		wortbilden(anzahl, kopie);
		eingabe.append(1, wortbilden(anzahl, kopie));					//eingabe wird um ein zeichen 'buchstabe' verlängert
		//eingabe.append(1, kopie);
		if ((i) % 2) {								//eingabe2 wird um ein zeichen 'buchstabe' verlängert und alle 2 Zeichen ein Seperator '|' eingefügt
			eingabe.append(1, '|');
		}
	}

	cout << eingabe << endl;

	//der Buchstabensalat ist bereit
	cout << "\nBastel aus diesen Buchstaben ein moeglichst langes Wort!" << endl << endl << eingabe << endl;

	//
		//Beginn des Rätsels
	//

	unsigned int loeschzeichen = 0;								//welches zeichen soll gelöscht werden
	unsigned char loeschhilfe = 0;								//eingabe char zum umrechnen zu int (zum auslesen falscher eingaben durch buchstaben)
	for (unsigned int i2 = 0; i2 < anzahl; i2) {
		auswahl1 = {};
		int a = eingabe.size();
		anzahl = a;

		cout << "\nDas wievielte Zeichen willst du nehmen? \n druecke '0' um das Wort fertigzustellen!\n";
		benutzereingabe(loeschzeichen);
		//loeschzeichenPruefen(loeschzeichen);

		ueberpruefen(loeschzeichen, anzahl, pruefer);
		SCHALTER(loeschzeichen, schalter);
		zuordnung(schalter, loeschzeichen);
		cout << loeschzeichen << endl;

		if (pruefer == false) {
			break;
		}
		umwandeln(eingabe, eingabe2, auswahl, auswahl1, wortNeu, loeschzeichen, anzahl);

	}
	if (abgleich(wortNeu) == true) {
		cout << "\nBravo, " << name << ". Sie haben ein gueltiges Wort erraten!" << endl;
	}
	else cout << "Tur mir leid! Diese Wort kenne ich nicht. Versuchs doch noch einmal! :)" << endl;


	pause();
	return 0;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////








