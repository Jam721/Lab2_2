#include <iostream>
#include <fstream>
#include <iomanip>

class Planet{
    char* _name;
    int _diam;
    bool _live;
    unsigned short _satellites;

public:
    Planet(){
        _name = nullptr;
        _diam = 0;
        _live = false;
        _satellites = 0;
    }
    Planet(char* name, int diam, bool live, unsigned short satellites){
        _name = new char[strlen(name)+1];
        strcpy_s(_name, strlen(name)+1 ,name);
        _diam = diam;
        _live = live;
        _satellites = satellites;
    }
    Planet(const Planet& planet){
        _name = new char[strlen(planet._name)+1];
        strcpy_s(_name, strlen(planet._name)+1 ,planet._name);
        _diam = planet._diam;
        _live = planet._live;
        _satellites = planet._satellites;
    }

    Planet& operator =(const Planet& planet){
        if(_name){
            delete[] _name;
        }
        _name = new char[strlen(planet._name)+1];
        strcpy_s(_name, strlen(planet._name)+1 ,planet._name);
        _diam = planet._diam;
        _live = planet._live;
        _satellites = planet._satellites;
        return *this;
    }

    void SetName(char* name){
        if(_name){
            delete[] _name;
        }
        _name = new char[strlen(name)+1];
        strcpy_s(_name, strlen(name)+1 ,name);
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
    ~Planet(){
        if(_name)
            delete[] _name;
    }
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


Planet* Add(Planet* planets);

Planet* Delete(Planet* planets);

void CorrectionOfInformation(Planet* planets);

void WriteDBase(Planet* planets);
void ReadFile(Planet* planets);

void SortPlanets(Planet* planets);