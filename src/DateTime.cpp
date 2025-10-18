#include "../include/DateTime.h"
#include <ctime>
#include <iostream>
#include <string>

DateTime DateTime::Now() {

    DateTime dt;

    time_t t = time(nullptr);
    tm* now = localtime(&t);

    dt.setDay(now->tm_mday);
    dt.setMonth(now->tm_mon + 1);
    dt.setYear(now->tm_year + 1900);

    return dt;
}

DateTime::DateTime() {

    giorno = 1;
    mese = 1;
    anno = 1970;
}

DateTime::DateTime(int d, int m, int y) {

    giorno = d;
    mese = m;
    anno = y;
}

int DateTime::getDay() {
    return giorno;
}

int DateTime::getMonth() {
    return mese;
}

int DateTime::getYear() {
    return anno;
}

void DateTime::setDay(int d) {
    try {
        int maxGiorni = GiorniInMese();
        if (d <= 0 || d > maxGiorni) {
            throw std::string("Errore: giorno non valido per il mese selezionato!");
        }
        giorno = d;
    } catch (const std::string& errore) {
        std::cout << errore << std::endl;
    }
}

void DateTime::setMonth(int m) {
    try {
        if (m <= 0 || m > 12) {
            throw std::string("Errore: mesi impostati su dati non validi!");
        }

        mese = m;
    }
    catch (const std::string& errore) {
        std::cout << errore << std::endl;
    }
}

void DateTime::setYear(int y) {
    try {
        if (y <= 0 || y > 3000) {
            throw std::string("Errore: anni impostati su dati non validi!");
        }

        anno = y;
    }
    catch (const std::string& errore) {
        std::cout << errore << std::endl;
    }
}

std::string DateTime::ToString()
{
    std::string g;
    std::string m;
    std::string a;

    if (giorno < 10)
    {
        g = "0" + std::to_string(giorno);
    }
    else
    {
        g = std::to_string(giorno);
    }

    if (mese < 10)
    {
        m = "0" + std::to_string(mese);
    }
    else
    {
        m = std::to_string(mese);
    }

    if (anno < 10)
    {
        a = "000" + std::to_string(anno);
    }
    else if (anno < 100)
    {
        a = "00" + std::to_string(anno);
    }
    else if (anno < 1000)
    {
        a = "0" + std::to_string(anno);
    }
    else
    {
        a = std::to_string(anno);
    }

    return g + "/" + m + "/" + a;
}

bool DateTime::isLeapYear()
{
    if (anno % 4 == 0 && (anno % 100 != 0 || anno % 400 == 0)) {
        return true;
    }
    else {
        return false;
    }
}

int DateTime::GiorniInMese()
{
    switch (mese) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            return 31;
        case 4: case 6: case 9: case 11:
            return 30;
        case 2:
            return isLeapYear() ? 29 : 28;
        default:
            return 0; // mese non valido
    }
}
