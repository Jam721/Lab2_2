#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <string>


class Abonent{
    char* _name;
    long _number;
    bool _active;
    unsigned short _cost;

public:
    Abonent(){
        _name = nullptr;
        _number = 0;
        _active = false;
        _cost = 0;
    }
    Abonent(char* name, long number, bool active, unsigned short cost){
        _name = new char[strlen(name)+1];
        strcpy_s(_name, strlen(name)+1 ,name);
        _number = number;
        _active = active;
        _cost = cost;
    }
    Abonent(const Abonent& abonent){
        _name = new char[strlen(abonent._name)+1];
        strcpy_s(_name, strlen(abonent._name)+1 ,abonent._name);
        _number = abonent._number;
        _active = abonent._active;
        _cost = abonent._cost;
    }

    Abonent& operator =(const Abonent& abonent){
        if(_name){
            delete[] _name;
        }
        _name = new char[strlen(abonent._name)+1];
        strcpy_s(_name, strlen(abonent._name)+1 ,abonent._name);
        _number = abonent._number;
        _active = abonent._active;
        _cost = abonent._cost;
        return *this;
    }

    void SetName(char* name){
        if(_name!=nullptr){
            delete[] _name;
        }
        _name = new char[strlen(name)+1];
        strcpy_s(_name, strlen(name)+1 ,name);
    }
    void SetNumber(int number){
        _number = number;
    }
    void SetActive(bool active){
        _active = active;
    }
    void SetCost(unsigned short cost){
        _cost = cost;
    }
    void SetAll(char* name, long number, bool active, unsigned short cost){
        SetName(name);
        SetNumber(number);
        SetActive(active);
        SetCost(cost);
    }

    char* GetName(){
        return _name;
    }
    long GetNumber(){
        return _number;
    }
    bool GetActive(){
        return _active;
    }
    unsigned short GetCost(){
        return _cost;
    }

    friend std::ostream &operator<<(std::ostream &out, const Abonent obj);
    friend std::istream &operator>>(std::istream &in, Abonent& obj);
    ~Abonent(){
        if(_name)
            delete[] _name;
    }
};
std::ostream &operator<<(std::ostream &out, const Abonent obj) {
    out << "Имя человека: " << obj._name << "\tНомер: " << obj._number << "\t\tАктивность: ";
    obj._active ? out << "активен \t " : out << "не активен \t ";
    out << "Цена: " << obj._cost << std::endl;
    return out;
}
std::istream &operator>>(std::istream &in, Abonent& obj){
    std::cout<<"Ввежите имя человека(на английском): ";
    char name[40];
    in>>name;

    std::cout<<"Введите номер человека: ";
    long number;
    in>>number;

    std::cout<<"Введите активен ли номер(1 если да 0 если нет): ";
    bool active;
    in>>active;

    std::cout<<"Введите цену(от 0): ";
    unsigned short cost;
    in>>cost;

    obj.SetAll(name, number, active, cost);
    return in;
}

int Menu();

void PrintDbase(Abonent* abonents);

void Find(Abonent* abonents, int n, char* name);
void Find(Abonent* abonents, int n, int diam);
void Find(Abonent* abonents, int n, bool live);
void Find(Abonent* abonents, int n, unsigned short satellites);
int MenuFind();
void FindPlanet(Abonent* abonents, int n);


Abonent* Add(Abonent* abonents);

Abonent* Delete(Abonent* abonents);

void CorrectionOfInformation(Abonent* abonents);

void WriteDBase(Abonent* abonents);
void ReadFile(Abonent* abonents);

void SortPlanets(Abonent* abonents);