#pragma once
void Aufraumen(Teil* &aktuellesTeil, std::vector <std::vector <class Teil>>&Arukonefeld, int &X2, int Y2,int &Netz, int &X,int &Y, int &j, Teil* &AktuellesTeil2){
    int K = KuerzsterWeg(aktuellesTeil->Nachbarn, Arukonefeld[X2][Y2]);
    aktuellesTeil->Besucht = true;
    bool asc = false; bool des = false;
    /*while (aktuellesTeil->Nachbarn[K]->Paarteil == true && (aktuellesTeil->Nachbarn[K]->x != Arukonefeld[X2][Y2].x && aktuellesTeil->Nachbarn[K]->y != Arukonefeld[X2][Y2].y)) {
        //std::cout << "Es ist ein Paarteil" << std::endl;
        Arukoneausgabe(Arukonefeld, Netz);
        int D = aktuellesTeil->Nachbarn.size();
        if (K == 0 && D > 0) {
            K++;
            asc = true;
            des = false;
        }
        else if (K == D && D >= 0) {
            K--;
            des = true;
            asc = false;
        }
        else if (des == true && asc == false) {
            K--;
        }
        else if (asc == true && des == false) {
            K++;
        }
        else if (D >= 0) {
            K++;
        }
    }*/
    aktuellesTeil = aktuellesTeil->Nachbarn[K];
    X = aktuellesTeil->x; Y = aktuellesTeil->y;
    if (aktuellesTeil->DVerbindung == nullptr) {
        aktuellesTeil->DVerbindung = AktuellesTeil2;
    }
    aktuellesTeil->EVerbindungsteil = true;
    aktuellesTeil->Wert = Arukonefeld[X2][Y2].Wert;
    LoeschNachbarn(AktuellesTeil2);
    std::cout << "Arukoneausgabe als die Verbindung best" << ae << "tigt wurde und das Teil den Wert von dem Ende angenommen hat" << std::endl;
    //
    Arukoneausgabe(Arukonefeld, Netz);
    std::cout << "Wir suchen das Paar " << j << std::endl;
}
int Arukonepruefung(std::vector <std::vector <class Teil>>& Arukone, int& Paare, int& Netz, std::map <int, ZPH>& Zahlenpaar) {
    int moeglich = 1;
    int i = 0;
    int x = 0;
    bool kril = false;
    bool ende = false;
    std::vector <int> Paare2; std::vector <int> Pruefvektor;
    std::vector <int> LastTest = { 2,5,1,9,3,7,4,8,6 };
    Fuellvek(Paare2, Paare);
    while (moeglich != 0 && moeglich != 3) {
        std::cout << "While-Loop pruefung" << std::endl;
        Arukoneloeschung(Arukone, Netz);
        //Arukoneausgabe(Arukone, Netz);
        for (int i = 0; i < Paare2.size(); ++i) {
            int X = Zahlenpaar[Paare2[i]].X;//Zahlenpaar[Zahlenpaar.size() - (Zahlenpaar.size() - i)];
            int Y = Zahlenpaar[Paare2[i]].Y;//Zahlenpaar[Zahlenpaar.size() - (Zahlenpaar.size() - i - 1)];
            int X2 = Zahlenpaar.at(Paare2[i]).X2;//Zahlenpaar[Zahlenpaar.size() - (Zahlenpaar.size() - i - 2)];
            int Y2 = Zahlenpaar.at(Paare2[i]).Y2;//Zahlenpaar[Zahlenpaar.size() - (Zahlenpaar.size() - i - 3)];
            if (Arukone[X][Y].Wert == Paare2[i] && Arukone[X2][Y2].Wert == Paare2[i]) {
                //std::cout << "Weg vom " << Paare2[i] << "er Paar wird jetzt gefunden." << std::endl;
                Arukone[X][Y].Paarteil = true; Arukone[X2][Y2].Paarteil = true;
                if (EndNachbarpruefung(Arukone, Paare2[i], X2, Y2, Netz) == false) {
                    return 0;
                }
                else {
                    int Uwe = SortieralgoAstern(Netz, Arukone, X, X2, Y, Y2, Paare2[i]);
                    if (Uwe == 2) {
                        return 0;
                    }
                    if (Uwe == 0 || Uwe == 1) {
                        if (x != Paare2.size() - 1 && kril == false) {
                            Verschieben(Paare2);
                            Arukoneloeschung(Arukone, Netz);
                            x++;
                            i = -1;
                            if (x == Paare2.size()) {
                                kril = true;
                            }
                            Pruefvektor.clear();
                        }
                        else if (kril == true && ende == true) {
                            if (Paare2.size() == 9) {
                                for (int z = 0; z < Paare2.size(); z++) {
                                    Paare2[z] = LastTest[z];
                                    ende = true;
                                }
                            }
                            Pruefvektor.clear();
                        }
                        else {
                            return 0;
                        }
                    }
                    Pruefvektor.push_back(Uwe);
                }
            }
            else if (Arukone[X][Y].Wert != Paare2[i] || Arukone[X2][Y2].Wert != Paare2[i]) {
                std::cout << "Es gibt ein Problem mit der Wertzuweisung" << std::endl;
                std::cin.get();
                break;
            }
        }
        /*if (x != Paare2.size() - 1 && kril == false) {
            Verschieben(Paare2);
            Arukoneloeschung(Arukone, Netz);
            x++;
            i = 0;
            if (x == Paare2.size()) {
                kril = true;
            }
        }
        else if (kril == true && ende == true) {
            if (Paare2.size() == 9) {
                for (int i = 0; i < Paare2.size(); i++) {
                    Paare2[i] = LastTest[i];
                    ende = true;
                }
            }
        }
        else {
            return 0;
        }*/
        Pruefvektor.push_back(3);
        if (std::adjacent_find(Pruefvektor.begin(), Pruefvektor.end(), std::not_equal_to<>()) == Pruefvektor.end())
        {
            std::cout << "All elements are equal each other" << std::endl;
            return 1;
        }
        else {
            Pruefvektor.clear();
        }

    }
    return moeglich;
}
int SortieralgoAstern(int& Netz, std::vector <std::vector <class Teil>>& Arukonefeld, int X, int& X2, int Y, int& Y2, int& j) {
    std::cout << "Es wird jetzt nach M" << oe << "glichkeiten gesucht." << std::endl;
    std::vector<Teil*> u = {};
    Teil* Beginn = &Arukonefeld[X][Y];
    Teil* aktuellesTeil = &Arukonefeld[X][Y]; //Wird aus irgendeinem Grund wiederholt.
    while (aktuellesTeil->x != Arukonefeld[X2][Y2].x || aktuellesTeil->y != Arukonefeld[X2][Y2].y) {
        aktuellesTeil->GlobalesZiel = DistanzuHeuristik(aktuellesTeil, &Arukonefeld[X2][Y2]);
        aktuellesTeil = Nachbardefinierung(Arukonefeld, X, Y, Netz);
        std::cout << "Alle Nachbarn:" << std::endl;
        Nachbarausgabe(aktuellesTeil);
        Nachbarpruefung(aktuellesTeil->Nachbarn, aktuellesTeil->Wert/*,aktuellesTeil->x, aktuellesTeil->y, Beginn->x, Beginn->y*/);
        std::cout << "Nachbarpruefung" << std::endl;
        Nachbarausgabe(aktuellesTeil);
        Arukoneausgabe(Arukonefeld, Netz);
        if (aktuellesTeil->Nachbarn.size() > 0) {
            Verbindungsteilpruefung(aktuellesTeil->Nachbarn);
            std::cout << "Verbindungspruefung" << std::endl;
            Nachbarausgabe(aktuellesTeil);
            if (aktuellesTeil->Nachbarn.size() > 0) {
                Besuchtpruefung(aktuellesTeil->Nachbarn);
                std::cout << "Besuchtpruefung" << std::endl;
                Nachbarausgabe(aktuellesTeil);
                if (aktuellesTeil->Nachbarn.size() > 0) {
                    Teil* AktuellesTeil2 = aktuellesTeil;
                    Aufraumen(aktuellesTeil, Arukonefeld, X2, Y2, Netz, X, Y, j, AktuellesTeil2);
                }
                else {
                    aktuellesTeil->Besucht = true;
                    u.push_back(aktuellesTeil);
                    if (aktuellesTeil->DVerbindung == nullptr) {
                        std::cout << "Es gibt zurück, dass es kein Elternteil gibt. Grund: Besuchtpruefung" << std::endl;
                        return 1;
                    }
                    else {
                        aktuellesTeil->Wert = 0;
                        aktuellesTeil = aktuellesTeil->DVerbindung;
                        X = aktuellesTeil->x; Y = aktuellesTeil->y;
                    }
                    Arukoneausgabe(Arukonefeld, Netz);
                    std::cout << "Wir suchen das Paar " << j-1 << std::endl;
                }
            }
            else { //Kommt von der Verbindungsprüfung
                aktuellesTeil->Besucht = true;
                u.push_back(aktuellesTeil);
                if (aktuellesTeil->DVerbindung == nullptr) {
                    std::cout << "Es gibt zurück, dass es kein Elternteil gibt. Grund: Verbindungspruefung" << std::endl;
                    return 0;
                }
                else {
                    aktuellesTeil->Wert = 0;
                    aktuellesTeil = aktuellesTeil->DVerbindung;
                    X = aktuellesTeil->x; Y = aktuellesTeil->y;
                }
                Arukoneausgabe(Arukonefeld, Netz);
                std::cout << "Wir suchen das Paar " << j << std::endl;                
            }
        }
        else if (aktuellesTeil->Nachbarn.size() == 0) {
            return 2;
        }
        if (0 != u.size())
        {
            for (int i = 0; i < u.size(); i++) {
                u.erase(u.begin() + i);
                i--;
            }
        }
        
    }
    return 3;
}