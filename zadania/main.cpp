#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

class Kosc {
private:
    static int licznikInstancji;
    static vector<string> nazwyPlikow;

    int liczbaOczek;
    int identyfikatorGrafiki;
    bool dostepnosc;

public:
    Kosc(int wartosc) {
        if (wartosc >= 1 && wartosc <= 6) {
            liczbaOczek = wartosc;
            identyfikatorGrafiki = wartosc;
        } else {
            liczbaOczek = 0;
            identyfikatorGrafiki = 0;
        }
        dostepnosc = true;
        licznikInstancji++;
    }

    Kosc() {
        int wylosowana = rand() % 6 + 1; // [1; 6]
        liczbaOczek = wylosowana;
        identyfikatorGrafiki = wylosowana;
        dostepnosc = true;
        licznikInstancji++;
    }


    void rzuc() {
        if (!dostepnosc) {
            cout << "Kosc jest zablokowana\n";
            return;
        }
        int wylosowana = rand() % 6 + 1;
        liczbaOczek = wylosowana;
        identyfikatorGrafiki = wylosowana;
    }


    void zablokuj() {
        dostepnosc = false;
    }


    string wartoscTekstowa() const {
        switch (liczbaOczek) {
            case 1: return "jeden";
            case 2: return "dwa";
            case 3: return "trzy";
            case 4: return "cztery";
            case 5: return "piec";
            case 6: return "szesc";
            default: return "brak";
        }
    }

    //getters
    int getLiczbaOczek() const { return liczbaOczek; }
    int getIdentyfikatorGrafiki() const { return identyfikatorGrafiki; }
    bool getDostepnosc() const { return dostepnosc; }

    string getNazwaPliku() const {
        return nazwyPlikow[identyfikatorGrafiki];
    }

    static int getLicznikInstancji() {
        return licznikInstancji;
    }
};

int Kosc::licznikInstancji = 0;
vector<string> Kosc::nazwyPlikow = {
    "kosc0.png",
    "kosc1.png",
    "kosc2.png",
    "kosc3.png",
    "kosc4.png",
    "kosc5.png",
    "kosc6.png"
};

void wyswietlInfo(const Kosc& k) {
    cout << "-----------------------------\n";
    cout << "Liczba utworzonych instancji: " << Kosc::getLicznikInstancji() << '\n';
    cout << "Liczba oczek: " << k.getLiczbaOczek() << '\n';
    cout << "Wartosc tekstowa: " << k.wartoscTekstowa() << '\n';
    cout << "Plik graficzny: " << k.getNazwaPliku() << '\n';
    cout << "-----------------------------\n";
}

int main() {
    srand(time(0));

    Kosc kosc1;
    wyswietlInfo(kosc1);

    int wartoscOdUzytkownika;
    cout << "Podaj liczbe oczek (1-6): ";
    cin >> wartoscOdUzytkownika;

    Kosc kosc2(wartoscOdUzytkownika);
    wyswietlInfo(kosc2);

    return 0;
}
