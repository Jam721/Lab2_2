#include "a.h"

using namespace std;

int main() {
    system("chcp 65001");

    const int N = 10;
    Planet planets[N];
    planets[0].SetAll("Earth", 12000, true, 1);
    planets[1].SetAll("Jupiter", 51000, false, 12);
    planets[2].SetAll("Mars", 10000, false, 4);

    bool p = true;
    while(p){
        switch(Menu()){
            case 1:
                cout << "\n===================ДОБАВЛЕНИЕ ПЛАНЕТЫ=======================\n";
                Add(planets);
                break;
            case 2:
                cout << "\n===================УДАЛЕНИЕ ПЛАНЕТЫ=======================\n";
                Delete(planets, N);
                break;
            case 3:
                cout << "\n===================ПОИСК ПЛАНЕТ=======================\n";
                FindPlanet(planets, N);
                break;
            case 4:
                cout << "\n==============================КОРРЕКТИРОВКА ДАННЫХ===============================\n";
                CorrectionOfInformation(planets);
                break;
            case 5:
                cout << "\n====================================ВЫВОД ТАБЛИЦЫ=================================\n";
                PrintDbase(planets);
                cout << "\n==================================================================================\n";
                break;
            case 6:
                cout << "\n====================================ВВОД В ТАБЛИЦУ=================================\n";
                WriteDBase(planets);
                cout << "\n==================================================================================\n";
                break;
            case 7:
                cout << "\n===================ВЫХОД=======================\n";
                p = false;
                cout<<"ПОКА"<<endl;
                break;

        }
    }
    return 0;
}

int Menu(){
    cout << "\n======================= ГЛАВНОЕ МЕНЮ ========================\n";
    cout << "1 - Добавление планеты\t\t 4 - Корректировка сведений\n";
    cout << "2 - Удаление планеты\t\t 5 - Вывод базы на экран\n";
    cout << "3 - Поиск планеты\t\t 6 - Вывод базы в файл\n";
    cout << "\t\t\t\t 7 - ВЫХОД\n";
    cout << "Для выбора операции выберите цифру от 1 до 7: ";

    int choose;
    cin >> choose;
    while (!(choose>0 && choose<8)){
        cout << "ВЫ ВЫБРАЛИ НЕСУЩЕСТВУЮЩИЙ ПУНКТ!\n";
        cout << "Для выбора операции выберите цифру от 1 до 7:";
        cin >> choose;
    }

    cin.clear();
    cin.ignore(10, '\n');
    return choose;
}

void PrintDbase(Planet* planets){
    for (int i = 0; planets[i].GetDiam()!=0; i++){
        cout << i+1 << ") " << planets[i];
    }
}

int MenuFind(){
    cout<<"\n--------------------- ПОИСК --------------------------\n";
    cout<<"1 - Поиск по имени планеты\t 2 - Поиск по диаметру\n";
    cout<<"3 - Поиск по жизни на планете\t 4 - Поиск по спутникам\n";
    cout<<"\t\t\t\t 5 - Конец поиска\n";
    cout<<"Для выбора операции введите число от 1 до 5: ";

    int choose;
    cin >> choose;
    while (!(choose>0 && choose<6)){
        cout << "ВЫ ВЫБРАЛИ НЕСУЩЕСТВУЮЩИЙ ПУНКТ!\n";
        cout << "Для выбора операции выберите цифру от 1 до 5: ";
        cin >> choose;
    }

    cin.clear();
    cin.ignore(10, '\n');

    return choose;
}

void FindPlanet(Planet* planets, int n){
    char name[size];
    int diam;
    bool live;
    unsigned short satellites;

    while(true){
        switch (MenuFind()) {
            case 1:
                cout << "Введите имя планеты: ";
                cin >> name;
                Find(planets, n, name);
                break;
            case 2:
                cout << "Введите диаметр планеты: ";
                cin >> diam;
                diam = (int)diam;
                Find(planets, n, diam);
                break;
            case 3:
                cout << "Введите есть ли жизнь на планете(1 - если да 0 - если нет): ";
                cin >> live;
                live = (bool)live;
                Find(planets, n, live);
                break;
            case 4:
                cout << "Введите количество спутников на планете: ";
                cin >> satellites;
                satellites = (unsigned short)satellites;
                Find(planets, n, satellites);
                break;
            case 5:
                return;
                break;
            default:
                cout<<"Неверный ввод";
        }
    }
}

void Find(Planet* planets, int n, char* name){ //По фамилии
    int k = 0;

    for (int i = 0; i< n; i++){
        if(!strcmp(planets[i].GetName(), name)){
            cout<<planets[i];
            k++;
        }
    }
    if (k==0){
        cout << "Не найдено такой планеты по введенному значению!\n";
    }
    cout<<endl;
}
void Find(Planet* planets, int n, bool live){ //По жизни
    int k = 0;
    for (int i = 0; i< n; i++){
        if(live==planets[i].GetLive()){
            cout << planets[i];
            k++;
        }
    }
    if (k==0){
        cout << "Не найдено такой планеты по введенному значению!\n";
    }
    cout<<endl;
}
void Find(Planet* planets, int n, unsigned short satellites){ //По спутникам
    int k = 0;
    for (int i = 0; i< n; i++){
        if(satellites==planets[i].GetSatellites()){
            cout << planets[i];
            k++;
        }
    }
    if (k==0){
        cout << "Не найдено такой планеты по введенному значению!\n";
    }
    cout<<endl;
}
void Find(Planet* planets, int n, int diam){ //По диаметру
    int k = 0;
    for (int i = 0; i< n; i++){
        if(planets[i].GetDiam()==diam){
            cout << planets[i];
            k++;
        }
    }
    if (k==0){
        cout << "Не найдено такой планеты по введенному значению!\n";
    }
    cout<<endl;
}

void Add(Planet* planets){
    cout<<"Ввежите название планеты(на английском): ";
    char name[size];
    cin>>name;

    cout<<"Введите Диаметр планеты(от 1): ";
    int diam;
    cin>>diam;

    cout<<"Введите есть ли жизнь на планете(1 если да 0 если нет): ";
    bool live;
    cin>>live;

    cout<<"Введите количество спутников(от 0): ";
    unsigned short satellites;
    cin>>satellites;

    int n = 0;
    for (int i = 0; planets[i].GetDiam()!=0; i++) {
      n++;
    }
    planets[n].SetAll(name, diam, live, satellites);
}

void Delete(Planet* planets, int N){
    PrintDbase(planets);
    cout<<"Введите номер планеты, которой хотите удалить: ";

    int n = 0;
    for (int i = 0; planets[i].GetDiam()!=0; i++) {
        n++;
    }

    Planet planet[N];
    int deleteNumber;
    cin>>deleteNumber;
    int c = 0;
    if(deleteNumber<n && deleteNumber>0){
        for(int i = 0; i<N; i++){
            if(i!=deleteNumber-1){
                planet[c] = planets[i];
                c++;
            }
        }
        for (int i = 0; i < N; i++) {
            planets[i] = planet[i];
        }
        cout<<"Успешно удалили";
    } else{
        cout << "Неподходящий номер!";
    }

}

void CorrectionOfInformation(Planet* planets){
    PrintDbase(planets);
    cout << "Выберите в какой планете хотите корректировать сведенья: ";

    int n = 0;
    for (int i = 0; planets[i].GetDiam()!=0; i++) {
        n++;
    }

    int choose;
    cin >> choose;

    if(choose>0 && choose<n+1){
        int why;
        cout<<planets[choose-1];
        cout<<"Выберите какое сведение будете корректировать(1-имя, 2-диаметр, 3-жизнь, 4-спутники): ";
        cin >> why;

        char name[size];
        int diam;
        bool live;
        unsigned short satellites;
        if(why>0 && why<5){
            switch (why) {
                case 1:
                    cout<<"Введите новое имя: ";
                    cin >> name;
                    planets[choose-1].SetName(name);
                    cout<<"Вы успешно поменяли имя на " << name;
                    break;
                case 2:
                    cout<<"Введите новый диаметр(от 1): ";
                    cin >> diam;
                    planets[choose-1].SetDiam(diam);
                    cout<<"Вы успешно поменяли диаметр на " << diam;
                    break;
                case 3:
                    cout<<"Введите новую информацию существования жизни(1-еть 0-нет): ";
                    cin >> live;
                    planets[choose-1].SetLive(live);
                    cout<<"Вы успешно поменяли жизнь на " ;
                    live==1?cout<<"'существует'":cout<<"'не существует'";
                    break;
                case 4:
                    cout<<"Введите новое кол-во спутников(от 0): ";
                    cin >> satellites;
                    planets[choose-1].SetSatellites(satellites);
                    cout<<"Вы успешно поменяли количество спутников на " << satellites;
                    break;
                default:
                    break;
            }
        } else{
            cout << "Неподходящий номер!";
        }
    } else{
        cout << "Неподходящий номер!";
    }
}

void WriteDBase(Planet* planets){
    int n = 0;
    for (int i = 0; planets[i].GetDiam()!=0; i++) {
        n++;
    }

    ofstream fout;
    fout.open("dbase.txt");
    fout.clear();
    if(fout.is_open()){
        for (int i = 0; i < n; ++i) {
            fout<<planets[i];
        }
        cout<<"Успешно!";
    }
    else{
        cout<<"Не найден файл";
    }
    fout.close();
}