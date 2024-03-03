#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>


#define size 1000

class Planet{
    char _name[size];
    int _diam;
    bool _live;
    unsigned short _satellites;

public:
    Planet(){
        _name[0] = '\0';
        _diam = 0;
        _live = false;
        _satellites = 0;
    }
    Planet(char* name, int diam, bool live, unsigned short satellites){
        strcpy(_name, name);
        _diam = diam;
        _live = live;
        _satellites = satellites;
    }

    void SetName(char* name){
        strcpy(_name, name);
    }
    void SetDiam(int diam){
        _diam = diam;
    }
    void SetLive(bool live){
        _live = live;
    }
    void SetSatellites(unsigned short satellites){
        _satellites = satellites;
    }
    void SetAll(char* name, int diam, bool live, unsigned short satellites){
        SetName(name);
        SetDiam(diam);
        SetLive(live);
        SetSatellites(satellites);
    }

    char* GetName(){
        return _name;
    }
    int GetDiam(){
        return _diam;
    }
    bool GetLive(){
        return _live;
    }
    unsigned short GetSatellites(){
        return _satellites;
    }

    friend std::ostream &operator<<(std::ostream &out, const Planet obj);

};
std::ostream &operator<<(std::ostream &out, const Planet obj) {
    out << "Имя планеты: " << obj._name << "\tДиаметр: " << obj._diam << "\t\tЖизнь: ";
    obj._live?out<<"есть \t ":out<<"нет \t ";
    out << "Спутники: " << obj._satellites << std::endl;
    return out;
}

int Menu();

void PrintDbase(Planet* planets);

void Find(Planet* planets, int n, char* name);
void Find(Planet* planets, int n, int diam);
void Find(Planet* planets, int n, bool live);
void Find(Planet* planets, int n, unsigned short satellites);
int MenuFind();
void FindPlanet(Planet* planets, int n);


void Add(Planet* planets);

void Delete(Planet* planets, int N);

void CorrectionOfInformation(Planet* planets);

void WriteDBase(Planet* planets);