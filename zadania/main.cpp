#include <iostream>
#include <string>
using namespace std;

class Pytanie {
protected:
    string trescPytania;
    string nazwaPliku;
    bool poprawnoscOdpowiedzi;

public:
    Pytanie(string tresc, string plik) {
        trescPytania = tresc;
        nazwaPliku = plik;
        poprawnoscOdpowiedzi = false;
    }

    virtual bool sprawdzOdpowiedz(char odpowiedz) = 0;

    //getters
    string getTrescPytania() const { return trescPytania; }
    string getNazwaPliku() const { return nazwaPliku; }
    bool getPoprawnoscOdpowiedzi() const { return poprawnoscOdpowiedzi; }

};

class PytanieZamkniete : public Pytanie {
private:
    string odpowiedzA;
    string odpowiedzB;
    string odpowiedzC;
    char poprawnaOdpowiedz;

public:
    PytanieZamkniete(string tresc, string plik,
                      string odpA, string odpB, string odpC,
                      char poprawna)
        : Pytanie(tresc, plik)
    {
        odpowiedzA = odpA;
        odpowiedzB = odpB;
        odpowiedzC = odpC;
        poprawnaOdpowiedz = poprawna;
    }


    bool sprawdzOdpowiedz(char odpowiedz) override {
        if (odpowiedz == poprawnaOdpowiedz) {
            poprawnoscOdpowiedzi = true;
        } else {
            poprawnoscOdpowiedzi = false;
        }
        return poprawnoscOdpowiedzi;
    }

    void wyswietlPytanie() const {
        cout << trescPytania << '\n';
        cout << "A) " << odpowiedzA << '\n';
        cout << "B) " << odpowiedzB << '\n';
        cout << "C) " << odpowiedzC << '\n';
    }
};

int main() {

    PytanieZamkniete pytanie1(
        "Jaka jest stolica Polski?",
        "pytanie1.png",
        "Krakow",
        "Warszawa",
        "Gdansk",
        'B'
    );

    pytanie1.wyswietlPytanie();

    char odpowiedzUzytkownika;
    cout << "Twoja odpowiedz (A/B/C): ";
    cin >> odpowiedzUzytkownika;

    bool wynik = pytanie1.sprawdzOdpowiedz(odpowiedzUzytkownika);

    if (wynik) {
        cout << "Poprawna odpowiedz!\n";
    } else {
        cout << "Niepoprawna odpowiedz.\n";
    }

    cout << "Pole poprawnoscOdpowiedzi: "
         << (pytanie1.getPoprawnoscOdpowiedzi() ? "true" : "false") << '\n';

    return 0;
}
