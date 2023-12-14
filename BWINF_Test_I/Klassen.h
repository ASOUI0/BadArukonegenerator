#pragma once
class Teil
{
public:
	bool Paarteil = false;
	int Wert = 0;
	bool EVerbindungsteil = false;
	float GlobalesZiel = INFINITY;
	//float LokalesZiel = INFINITY; Wird wahrscheinlich nicht benutzt, weil ich mich dem nicht traue.
	int x = NULL;
	int y = NULL;
	bool Besucht = false;
	std::vector <Teil*> Nachbarn;
	Teil* DVerbindung = nullptr; //Hier ist dein Verbindungsteil.
	//Teil(int Wert = 0, bool Paarteil = false, bool Verbindungsteil = false){}
};
class ZPH {//Zahlenpaarhalter
public:
	int X;
	int Y;
	int X2;
	int Y2;
};
