#ifndef DATETIME_LIBRARY_H
#define DATETIME_LIBRARY_H

#include <string>

class DateTime {
private:

    //proprieta
    int giorno;
    int mese;
    int anno;

public:

    //Property
    int getDay();
    int getMonth();
    int getYear();

    void setDay(int d);
    void setMonth(int m);
    void setYear(int y);

    //Costruttori
    DateTime();

    DateTime(int d, int m, int y);

    //Metodi
    std::string ToString();

    //Metodi statici
    static DateTime Now();

};

#endif //DATETIME_LIBRARY_H