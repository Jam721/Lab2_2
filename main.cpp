#include "a.h"

using namespace std;

int main() {
    system("chcp 65001");

    ifstream fin("dbase.txt", ios::in);
    if (!fin) {
        cout << "Heт файла dbase.txt" << endl;
    }
    int count = 0;
    fin>>count;
    fin.close();

    int N = count+1;
    int n = N;
    Planet* planets = new Planet[N];

    bool p = true;
    while(p){
        switch(Menu()){
            case 1:
                cout << "\n===================ДОБАВЛЕНИЕ ПЛАНЕТЫ=======================\n";
                planets = Add(planets);
                n = 0;
                for (int i = 0; planets[i].GetDiam()!=0; i++) {
                    n++;
                }
                break;
            case 2:
                cout << "\n===================УДАЛЕНИЕ ПЛАНЕТЫ=======================\n";
                planets = Delete(planets);
                break;
            case 3:
                cout << "\n===================ПОИСК ПЛАНЕТ=======================\n";
                FindPlanet(planets, n);
                break;
            case 4:
                cout << "\n==============================КОРРЕКТИРОВКА ДАННЫХ===============================\n";
                CorrectionOfInformation(planets);
                break;
            case 5:
                cout << "\n====================================ВЫВОД ТАБЛИЦЫ=================================\n";
                PrintDbase(planets);
                cout << "==================================================================================\n";
                break;
            case 6:
                cout << "\n====================================ВВОД В ТАБЛИЦУ=================================";
                WriteDBase(planets);
                cout << "\n==================================================================================\n";
                break;
            case 7:
                cout << "\n====================================СОРТИРОВКА ТАБЛИЦЫ=================================\n";
                SortPlanets(planets);
                cout << "==================================================================================\n";
                break;
            case 8:
                cout << "\n====================================СЧИТЫВАНИЕ С ФАЙЛА=================================\n";
                ReadFile(planets);
                cout << "\n==================================================================================\n";
                break;
            case 9:
                cout << "\n===================ВЫХОД=======================\n";
                p = false;
                cout<<"ПОКА"<<endl;
                break;
        }
    }
    delete[] planets;
    return 0;
}

int Menu(){
    cout << "\n======================= ГЛАВНОЕ МЕНЮ ========================\n";
    cout << "1 - Добавление планеты\t\t 4 - Корректировка сведений\n";
    cout << "2 - Удаление планеты\t\t 5 - Вывод базы на экран\n";
    cout << "3 - Поиск планеты\t\t 6 - Вывод базы в файл\n";
    cout << "7 - Сортировка таблицы\t\t 8 - Ввод из файла\n";
    cout << "\t\t\t\t 9 - ВЫХОД\n";
    cout << "Для выбора операции выберите цифру от 1 до 9: ";

    int choose;
    cin >> choose;
    while (!(choose>0 && choose<10)){
        cout << "ВЫ ВЫБРАЛИ НЕСУЩЕСТВУЮЩИЙ ПУНКТ!\n";
        cout << "Для выбора операции выберите цифру от 1 до 9:";
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
    char name[40];
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
    int _n = 0;
    for (int i = 0; planets[i].GetDiam()!=0; i++) {
        _n++;
    }
    for (int i = 0; i< _n; i++){
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

Planet* Add(Planet* planets){
    cout<<"Ввежите название планеты(на английском): ";
    char name[40];
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
    while(true){
        if(planets[n].GetDiam()!=0)
            n++;
        else
            break;
    }

    Planet* planet = new Planet[n+2];
    for(int i = 0; i<n; i++){
        planet[i] = planets[i];
    }
    delete[] planets;
    planet[n].SetAll(name, diam, live, satellites);
    cout<<"Успешно добавили планету!";
    return planet;
}

Planet* Delete(Planet* planets){
    PrintDbase(planets);
    cout<<"Введите номер планеты, которой хотите удалить: ";

    int n = 0;
    for (int i = 0; planets[i].GetDiam()!=0; i++) {
        n++;
    }

    Planet* planet = new Planet[n];
    int deleteNumber;
    cin>>deleteNumber;
    int c = 0;
    if(deleteNumber<=n && deleteNumber>0){
        for(int i = 0; i<n; i++){
            if(i!=deleteNumber-1){
                planet[c] = planets[i];
                c++;
            }
        }

        delete[] planets;
        return planet;

        cout<<"Успешно удалили";
    } else{
        cout << "Неподходящий номер!";
    }
    return planets;
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

        char name[40];
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
        fout<<n<<'\n';
        for (int i = 0; i < n; ++i) {
            fout<<planets[i].GetName()<<' '<<planets[i].GetDiam()<<' '<<planets[i].GetLive()<<' '<<planets[i].GetSatellites()<<'\n';
        }
        cout<<"\nУспешно введено в базу данных!";
    }
    else{
        cout<<"\nНе найден файл";
    }
    fout.close();
}

void SortPlanets(Planet* planets){
    int n = 0;
    for (int i = 0; planets[i].GetDiam()!=0; i++) {
        n++;
    }
    Planet pl;
    for(int i = 0; i < n-1; i++){
        for (int j = 0; j<n-i-1; j++){
            if(planets[j].GetDiam()>planets[j+1].GetDiam()){
                pl = planets[j];
                planets[j] = planets[j+1];
                planets[j+1] = pl;
            }
        }
    }
    PrintDbase(planets);
}


void ReadFile(Planet* planets){

    ifstream fin("dbase.txt", ios::in);
    if (!fin) {
        cout << "Heт файла dbase.txt" << endl;
    }
    int n = 0;
    fin>>n;
    char t[20];
    if(planets[0].GetDiam()==0){
        for (int i = 0; i < n; i++) {
            fin >> t;
            cout<<t <<' ';
            planets[i].SetName(t);
            fin >> t;
            cout << t<<' ';
            planets[i].SetDiam(stod(t));
            fin >> t;
            cout<<t<<' ';
            planets[i].SetLive(stoi(t));
            fin >> t;
            cout<<t<<'\n';
            planets[i].SetSatellites(stoi(t));
        }
        cout<<"Успешно считалось!";
    }
    else{
        cout<<"Файл уже считался!";
    }

    fin.close();
}