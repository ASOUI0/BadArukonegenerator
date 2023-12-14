#pragma once
const unsigned char AE = static_cast<unsigned char>(142);
const unsigned char ae = static_cast<unsigned char>(132);
const unsigned char OE = static_cast<unsigned char>(153);
const unsigned char oe = static_cast<unsigned char>(148);
const unsigned char UE = static_cast<unsigned char>(154);
const unsigned char ue = static_cast<unsigned char>(129);
const unsigned char ss = static_cast<unsigned char>(225);
int SortieralgoAstern(int& Netz, std::vector <std::vector <class Teil>>& Arukonefeld, int X, int& X2, int Y, int& Y2, int &j);
bool EndNachbarpruefung(std::vector <std::vector<Teil>>& Arukonefeld, int& Wert, int& X, int& Y, int& Netz/* int& X3, int& Y3*/);
void Fuellvek(std::vector <int>& Pa2, int& Pa) { //Diese Funktion füllt einen Vektor mit einer n-Zahl von Zahlen, sodass sie ausgetauscht werden können.
    for (int i = 1; i < Pa+1; i++) {
        Pa2.push_back(i);
    }
}
void Arukoneausgabe(std::vector <std::vector<class Teil>> &Arukonefeld, int &Netz) {//Dies gibt einfach nur das Spielfeld aus.
    std::cout << std::endl;
	for (int i = 0; i < Netz; i++) {
		for (int j = 0; j < Netz; j++) {
			std::cout << Arukonefeld[i][j].Wert << " ";
		}
		std::cout << std::endl;
	}
}
void Arukoneloeschung(std::vector <std::vector<class Teil>>& Arukonefeld, int& Netz) { //Dies setzt einfach nur das ganze Arukonefeld auf 0.
    for (int i = 0; i < Netz; i++) {
        for (int j = 0; j < Netz; j++) {
            if (Arukonefeld[i][j].EVerbindungsteil == true || (Arukonefeld[i][j].Besucht == true && Arukonefeld[i][j].Paarteil ==false)) {
                Arukonefeld[i][j].EVerbindungsteil = false;
                if (Arukonefeld[i][j].Paarteil == false) {
                    Arukonefeld[i][j].Wert = 0;
                }
                Arukonefeld[i][j].Besucht = false;
            }
        }
       
    }
    std::cout << "Arukone wird neu gestartet." << std::endl;
}
std::vector <std::vector<class Teil>> Arukoneaufbau(int& Netz) { //Funktion für das Etalbieren von einem Arukonefeld
	std::vector<std::vector<class Teil>> Arukonefeld(Netz,std::vector<class Teil>(Netz)); //Hier wird der Vektor von einem Vektor mit der Größe von Netz definiert.
    //Der nächste Teil gibt einfach nur das Netz aus.
    for (int i = 0; i < Netz; i++) {
        for (int j = 0; j < Netz; j++) {
            std::cout << Arukonefeld[i][j].Wert << " "; 
            Arukonefeld[i][j].y = j;
            Arukonefeld[i][j].x = i;
        }
        std::cout << std::endl;
    }
	return Arukonefeld; //Es gibt das Arukonefeld aus.
}
void Vekausgabe(std::vector <int>& A) { //Dies gibt einen normalen Vektor raus. 
    for (int i = 0; i < A.size(); i++) {
        std::cout << A[i] << " ";
    }
    std::cout << std::endl;
}
void Verschieben(std::vector <int> &Paar) { //Dies verschiebt in einem Vektor die Zahlen. Bsp {1,2,3,4,5} -> {5,1,2,3,4}
    Vekausgabe(Paar);
    Paar.insert(Paar.begin(),Paar[Paar.size()-1]);
    Paar.erase(Paar.end()-1);
    Vekausgabe(Paar);
}
std::map <int, ZPH> Arukoneplatzierung(std::vector <std::vector <class Teil>>& Arukonefeld, int &Netz, int &ap) {
    std::map <int, ZPH> BessVek;
    std::random_device trueran;
    std::uniform_int_distribution<int> truer(0, Netz - 1);
    for (int i = 1; i < ap + 1; i++){
        int rv0 = truer(trueran); int rv1 = truer(trueran); int rv2 = truer(trueran); int rv3 = truer(trueran);
        while (Arukonefeld[rv0][rv1].Wert != 0) { //Während die Position beseztzt ist, welche die zufälligen Zahlen genommen haben, sollen die zufälligen Zahlen es nochmal zufällig machen.
            rv0 = truer(trueran); rv1 = truer(trueran);
        }
        Arukonefeld[rv0][rv1].Wert = i; // Der Wert von dem Paarteil wird dem Objekt auf dem Arukonefeld übergeben.
        Arukonefeld[rv0][rv1].Paarteil = true; //Da ein Paarteil an dieser Position vorhanden ist, wird dann jenes Objekt als Paarteil markiert.
        BessVek[i].X = rv0 ; BessVek[i].Y= rv1;
        while (rv0 == rv2 || rv1 == rv3) {
            rv0 = truer(trueran); rv1 = truer(trueran);
        }
        while (Arukonefeld[rv2][rv3].Wert != 0) {
            rv2 = truer(trueran); rv3 = truer(trueran);
        }
        Arukonefeld[rv2][rv3].Wert = i;
        Arukonefeld[rv2][rv3].Paarteil = true;
        BessVek[i].X2 = rv2; BessVek[i].Y2 = rv3;
        
    }
    return BessVek;
}
//Diese Funktion funktioniert ab sofort überhaupt nicht, da Zahlenpaar als ein map umgeschrieben werden muss.

/*Teil* aktivesTeil = &Arukonefeld[X][Y];
std::list<Teil*> NochZuTesten;
NochZuTesten.push_back(&Arukonefeld[X][Y]);
while (!NochZuTesten.empty() && aktivesTeil != &Arukonefeld[X2][Y2]) {
    NochZuTesten.sort(Funktia);
    while (!NochZuTesten.empty() && NochZuTesten.front()->Besucht) {
        NochZuTesten.pop_front();
        if (NochZuTesten.empty()) {
            break;
        }

    }
    aktivesTeil = NochZuTesten.front();
    aktivesTeil->Besucht = true;
    for (auto)
}*/
float DistanzuHeuristik(Teil* a, Teil* b) { //Vektorenrechnung. Einfach nur Vektorenrechnung.
    return sqrt((a->x - b->x) * (a->x - b->x) + (a->y - b->y) * (a->y - b->y));
}
void LoeschNachbarn(Teil*& AktuellesTeil) { //Dies löscht alle Nachbarn in einem Nachbarnvektor.
    for (int i = 0; i < AktuellesTeil->Nachbarn.size(); i++) {
        AktuellesTeil->Nachbarn.erase(AktuellesTeil->Nachbarn.begin() + i);
        i--;
    }
}
void Nachbarpruefung(std::vector <Teil*>& ZPTfN, int& Wert /*,int& x, int& y, int& X3, int& Y3*/) { //Der Nachbarnvektor wird überprüft.
    for (int i = 0; i < ZPTfN.size(); i++) {
        //bool proof = (ZPTfN[i]->Paarteil == true && ZPTfN[i]->Wert != Wert);
        if ((ZPTfN[i]->Paarteil == true && ZPTfN[i]->Wert != Wert)
            /*(ZPTfN[i]->x == x && ZPTfN[i]->y == y)*/) {
            std::cout << "Im Nachbarnvektor wird der " << i << "te Teil gel" << oe << "scht." << std::endl;
            ZPTfN.erase(ZPTfN.begin() + i);
            i--;
            std::cout << "//////////////////////////" << std::endl;
        }
    }
}
Teil* Nachbardefinierung(std::vector<std::vector<Teil>>& Arukonefeld, int& X, int& Y, int& Netz) {
    Teil* aktuellesTeil = &Arukonefeld[X][Y];
    if (X - 1 == -1 || X + 1 == Netz || Y - 1 == -1 || Y + 1 == Netz) {
        if (X - 1 == -1 && Y - 1 == -1) {
            aktuellesTeil->Nachbarn.push_back(&Arukonefeld[X + 1][Y]);
            aktuellesTeil->Nachbarn.push_back(&Arukonefeld[X][Y + 1]);
        }
        else if (X - 1 == -1 && Y + 1 == Netz) {
            aktuellesTeil->Nachbarn.push_back(&Arukonefeld[X + 1][Y]);
            aktuellesTeil->Nachbarn.push_back(&Arukonefeld[X][Y - 1]);
        }
        else if (X + 1 == Netz && Y - 1 == -1) {
            aktuellesTeil->Nachbarn.push_back(&Arukonefeld[X - 1][Y]);
            aktuellesTeil->Nachbarn.push_back(&Arukonefeld[X][Y + 1]);
        }
        else if (X + 1 == Netz && Y + 1 == Netz) {
            aktuellesTeil->Nachbarn.push_back(&Arukonefeld[X - 1][Y]);
            aktuellesTeil->Nachbarn.push_back(&Arukonefeld[X][Y - 1]);
        }
        else if (X - 1 == -1) {
            aktuellesTeil->Nachbarn.push_back(&Arukonefeld[X + 1][Y]);
            aktuellesTeil->Nachbarn.push_back(&Arukonefeld[X][Y - 1]);
            aktuellesTeil->Nachbarn.push_back(&Arukonefeld[X][Y + 1]);
        }
        else if (Y - 1 == -1) {
            aktuellesTeil->Nachbarn.push_back(&Arukonefeld[X - 1][Y]);
            aktuellesTeil->Nachbarn.push_back(&Arukonefeld[X + 1][Y]);
            aktuellesTeil->Nachbarn.push_back(&Arukonefeld[X][Y + 1]);
        }
        else if (Y + 1 == Netz) {
            aktuellesTeil->Nachbarn.push_back(&Arukonefeld[X - 1][Y]);
            aktuellesTeil->Nachbarn.push_back(&Arukonefeld[X + 1][Y]);
            aktuellesTeil->Nachbarn.push_back(&Arukonefeld[X][Y - 1]);
        }
        else if (X + 1 == Netz) {
            aktuellesTeil->Nachbarn.push_back(&Arukonefeld[X - 1][Y]);
            aktuellesTeil->Nachbarn.push_back(&Arukonefeld[X][Y - 1]);
            aktuellesTeil->Nachbarn.push_back(&Arukonefeld[X][Y + 1]);
            //std::cout << "X ber" << ue << "hrt das Netz" << std::endl;
        }
    }
    else {
        aktuellesTeil->Nachbarn.push_back(&Arukonefeld[X - 1][Y]);
        aktuellesTeil->Nachbarn.push_back(&Arukonefeld[X + 1][Y]);
        aktuellesTeil->Nachbarn.push_back(&Arukonefeld[X][Y - 1]);
        aktuellesTeil->Nachbarn.push_back(&Arukonefeld[X][Y + 1]);
    }
    return aktuellesTeil;
}
bool EndNachbarpruefung(std::vector <std::vector<Teil>>& Arukonefeld, int& Wert, int& X, int& Y, int& Netz/* int& X3, int& Y3*/) {
    Teil* aktuellesTeil = &Arukonefeld[X][Y];
    if (X - 1 == -1 || X + 1 == Netz || Y - 1 == -1 || Y + 1 == Netz) {
        if (X - 1 == -1 && Y - 1 == -1) {
            aktuellesTeil->Nachbarn.push_back(&Arukonefeld[X + 1][Y]);
            aktuellesTeil->Nachbarn.push_back(&Arukonefeld[X][Y + 1]);
        }
        else if (X - 1 == -1 && Y + 1 == Netz) {
            aktuellesTeil->Nachbarn.push_back(&Arukonefeld[X + 1][Y]);
            aktuellesTeil->Nachbarn.push_back(&Arukonefeld[X][Y - 1]);
        }
        else if (X + 1 == Netz && Y - 1 == -1) {
            aktuellesTeil->Nachbarn.push_back(&Arukonefeld[X - 1][Y]);
            aktuellesTeil->Nachbarn.push_back(&Arukonefeld[X][Y + 1]);
        }
        else if (X + 1 == Netz && Y + 1 == Netz) {
            aktuellesTeil->Nachbarn.push_back(&Arukonefeld[X - 1][Y]);
            aktuellesTeil->Nachbarn.push_back(&Arukonefeld[X][Y - 1]);
        }
        else if (X - 1 == -1) {
            aktuellesTeil->Nachbarn.push_back(&Arukonefeld[X + 1][Y]);
            aktuellesTeil->Nachbarn.push_back(&Arukonefeld[X][Y - 1]);
            aktuellesTeil->Nachbarn.push_back(&Arukonefeld[X][Y + 1]);
        }
        else if (Y - 1 == -1) {
            aktuellesTeil->Nachbarn.push_back(&Arukonefeld[X - 1][Y]);
            aktuellesTeil->Nachbarn.push_back(&Arukonefeld[X + 1][Y]);
            aktuellesTeil->Nachbarn.push_back(&Arukonefeld[X][Y + 1]);
        }
        else if (Y + 1 == Netz) {
            aktuellesTeil->Nachbarn.push_back(&Arukonefeld[X - 1][Y]);
            aktuellesTeil->Nachbarn.push_back(&Arukonefeld[X + 1][Y]);
            aktuellesTeil->Nachbarn.push_back(&Arukonefeld[X][Y - 1]);
        }
        else if (X + 1 == Netz) {
            aktuellesTeil->Nachbarn.push_back(&Arukonefeld[X - 1][Y]);
            aktuellesTeil->Nachbarn.push_back(&Arukonefeld[X][Y - 1]);
            aktuellesTeil->Nachbarn.push_back(&Arukonefeld[X][Y + 1]);
            //std::cout << "X ber" << ue << "hrt das Netz" << std::endl;
        }
    }
    else {
        aktuellesTeil->Nachbarn.push_back(&Arukonefeld[X - 1][Y]);
        aktuellesTeil->Nachbarn.push_back(&Arukonefeld[X + 1][Y]);
        aktuellesTeil->Nachbarn.push_back(&Arukonefeld[X][Y - 1]);
        aktuellesTeil->Nachbarn.push_back(&Arukonefeld[X][Y + 1]);
    }
    for (int i = 0; i < Arukonefeld[X][Y].Nachbarn.size(); i++) {
        //bool proof = (ZPTfN[i]->Paarteil == true && ZPTfN[i]->Wert != Wert);
        if ((Arukonefeld[X][Y].Nachbarn[i]->Paarteil == true && Arukonefeld[X][Y].Nachbarn[i]->Wert != Wert)
            /*(ZPTfN[i]->x == x && ZPTfN[i]->y == y)*/) {
            std::cout << "Im Nachbarnvektor wird der " << i << "te Teil gel" << oe << "scht." << std::endl;
            Arukonefeld[X][Y].Nachbarn.erase(Arukonefeld[X][Y].Nachbarn.begin() + i);
            i--;
            std::cout << "//////////////////////////" << std::endl;
        }
    }
    if (Arukonefeld[X][Y].Nachbarn.size() == 0) {
        return false;
    }
    return true;
}
void Verbindungsteilpruefung(std::vector<Teil*>& ZPTfVt) {
    for (int i = 0; i < ZPTfVt.size(); i++) {
        if (ZPTfVt[i]->EVerbindungsteil == true) {
            ZPTfVt.erase(ZPTfVt.begin() + i);
            i--;
        }
    }
}
void Besuchtpruefung(std::vector<Teil*>& ZPfB) {
    for (int i = 0; i < ZPfB.size(); i++) {
        if (ZPfB[i]->Besucht == true) {
            ZPfB.erase(ZPfB.begin() + i);
            i--;
        }
    }
}
void Nachbarausgabe(Teil*& aktuellesTeil) {
    for (int i = 0; i < aktuellesTeil->Nachbarn.size(); i++) {
        //std::cout << Arukonefeld[aktuellesTeil->x][aktuellesTeil->y].Nachbarn[i].x << std::endl;
        //std::cout << Arukonefeld[aktuellesTeil->x][aktuellesTeil->y].Nachbarn[i].y << std::endl;
        std::cout << aktuellesTeil->Nachbarn[i]->x << " ";
        std::cout << aktuellesTeil->Nachbarn[i]->y << std::endl;
    }
    std::cout << "/////////////////////////" << std::endl;
}
int KuerzsterWeg(std::vector <Teil*>& T, Teil& Arukoneende) {
    std::map <float, int> fMap;
    std::vector <float> Jik;
    for (int i = 0; i < T.size(); i++) {
        fMap[DistanzuHeuristik(T[i], &Arukoneende)] = i;
        Jik.push_back(DistanzuHeuristik(T[i], &Arukoneende));
    }
    std::sort(Jik.begin(), Jik.end());
    float x = Jik[0];
    int y = fMap[x];
    return y;
    /*for (int i = 0; i < T.size(); i++) {
        T[i]->GlobalesZiel = DistanzuHeuristik(T[i], &Arukoneende);

    }*/
}