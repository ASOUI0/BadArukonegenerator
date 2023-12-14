// BWINF_Test_I.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
#include <iostream> //Ist für cin und cout
#include <vector> //Ist für dynamische Felder, um die Eingabe des Nutzers umzusetzen in einem Feld
#include <random> //Ist für die Platzierung der Paarteile
#include <array>
#include <map> //Ist für eine Zuweisung von Werten in einem Feld, welches zwei oder mehr essenzielle Daten speichert.
#include "Klassen.h" //Ist die header-Datei für alle Klassen, die ich benutzen werden.
#include "Funktionen.h" //Ist für Funktionen da, die hauptsächlich nicht viel mit dem Suchalgorithmus zu tun haben.
#include "Suchalgorithmus.h" //Hier drin ist der Suchalgorithmus.

int main()
{ 
    int Netz; int Paare;
    std::cout << "Guten Tag im komplett zuf" << ae <<"lligen Arukone" << std::endl; //Text
    std::cout << "Geben sie bitte die Gr" << oe << ss <<"e des Netzes ein." << std::endl;
    std::cin >> Netz; // Erhält die Zahl von dem Nutzer.
    std::cin.ignore(); //Ignoriert alles andere.
    std::cout << "Geben sie bitte die Anzahl der Paare an." << std::endl;
    std::cin >> Paare; //Erhält die Zahl von dem Nutzer.
    std::cin.ignore(); //Ignoriert alles andere.
    
    if (Netz / 2 > Paare) { //Arbeitsanweisung wird nicht getroffen.
        std::cout << "Da stimmt etwas nicht" << ue << "berein"<<std::endl;
    }
    else if (Paare*2 > Netz*Netz) { //Arukone nicht möglich.
        std::cout << "Dies geht nicht, da du mehr Paarteil hast, als das Netz es eralaubt." << std::endl;
    }
    else {
        int TArukone = 0; //Ein Bool wird definiert.
        std::vector<std::vector<class Teil>> Arukone;
        std::vector<std::vector<class Teil>> Arukone3; //Ein Vektor von einem Vektor, welcher Objekte halten kann.
        while (TArukone == 0) { //Solange der Bool hier falsch ist, wird jene Funktion immer ausgeführt. Der Bool determiniert, ob das Arukone tatsächlich möglich ist oder nicht.
            Arukone = Arukoneaufbau(Netz); //Baut das Netz auf.
            std::map <int,ZPH> Zahlen = Arukoneplatzierung(Arukone, Netz, Paare); //Plaziert die Zahlen und erinnert sich jene Stellen.
            Arukoneausgabe(Arukone, Netz); //Gibt einfach nur das Arukonefeld zurück.

            Arukone3 = Arukone; //Erstellt eine Kopie von dem originalem Code.
            TArukone = Arukonepruefung(Arukone, Paare, Netz, Zahlen); //Jetzt wird überprüft, ob tatsächlich das Arukone schaffbar ist.
            for (int i = 0; i < 30; i++) {
                std::cout << "/////////////////////////////" << std::endl;
            }
            std::cout << "Das Arukone ist " << TArukone << "[Code:0 == falsch; Code:1 == richtig]" << std::endl;
        }
        std::cout << "Arukone wurde beendet" << std::endl;
        Arukoneausgabe(Arukone, Netz);
        Arukoneausgabe(Arukone3, Netz);
    }
    std::cin.get();
    return 0;
}

// Programm ausführen: STRG+F5 oder Menüeintrag "Debuggen" > "Starten ohne Debuggen starten"
// Programm debuggen: F5 oder "Debuggen" > Menü "Debuggen starten"

// Tipps für den Einstieg: 
//   1. Verwenden Sie das Projektmappen-Explorer-Fenster zum Hinzufügen/Verwalten von Dateien.
//   2. Verwenden Sie das Team Explorer-Fenster zum Herstellen einer Verbindung mit der Quellcodeverwaltung.
//   3. Verwenden Sie das Ausgabefenster, um die Buildausgabe und andere Nachrichten anzuzeigen.
//   4. Verwenden Sie das Fenster "Fehlerliste", um Fehler anzuzeigen.
//   5. Wechseln Sie zu "Projekt" > "Neues Element hinzufügen", um neue Codedateien zu erstellen, bzw. zu "Projekt" > "Vorhandenes Element hinzufügen", um dem Projekt vorhandene Codedateien hinzuzufügen.
//   6. Um dieses Projekt später erneut zu öffnen, wechseln Sie zu "Datei" > "Öffnen" > "Projekt", und wählen Sie die SLN-Datei aus.
