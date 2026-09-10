#include <iostream>
#include <string>
#include <sstream>
#include <chrono>

using namespace std;

string aktualnaData() {
    auto dzis = std::chrono::floor<std::chrono::days>(std::chrono::system_clock::now());
    std::ostringstream oss;
    oss << std::chrono::year_month_day{dzis};
    return oss.str();
}

enum Level {
    NONE,
    LOW,
    MEDIUM,
    HIGH
};

class Notatka {
public:
    string tytul;
    string tresc = "";
    enum Level priorytet;
    string dataDodania = aktualnaData();

    Notatka(string ty, string tr, enum Level p) {
        tytul = ty;
        tresc = tr;
        priorytet = p;
    }

    Notatka(string ty) {
        tytul = ty;
        priorytet = Level::NONE;
    }

    void info(){
        cout << "---------------------" << '\n';
        cout << "TYTUL - " << tytul << '\n';
        cout << "TRESC - " << tresc << '\n';
        cout << "DATA DODANIA - " << dataDodania << '\n';
        cout << ((priorytet == 3) ? "Notatka WAZNA!" : "") << '\n';
        cout << "---------------------" << '\n';
    }
    void setTitle(string newTitle) {
        this->tytul = newTitle;
    }

};

int main(){
    Notatka n1("TYTULTEST3", "TRESCTEST", Level::HIGH);
    Notatka n2("");

    string newTitle = "";
    cout << "Podaj tytul notatki: ";
    cin >> newTitle;
    n2.setTitle(newTitle);

    n1.info();
    n2.info();
    return 0;
}
