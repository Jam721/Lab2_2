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
    if(count==0){count=4;}
    int N = count+1;
    int n = N;
    Abonent* abonents = new Abonent[N];

    bool p = true;
    while(p){
        switch(Menu()){
            case 1:
                cout << "\n===================ДОБАВЛЕНИЕ АБОНЕНТА=======================\n";
                abonents = Add(abonents);
                n = 0;
                for (int i = 0; abonents[i].GetNumber() != 0; i++) {
                    n++;
                }
                break;
            case 2:
                cout << "\n===================УДАЛЕНИЕ АБОНЕНТА=======================\n";
                abonents = Delete(abonents);
                break;
            case 3:
                cout << "\n===================ПОИСК АБОНЕНТА=======================\n";
                FindPlanet(abonents, n);
                break;
            case 4:
                cout << "\n==============================КОРРЕКТИРОВКА ДАННЫХ===============================\n";
                CorrectionOfInformation(abonents);
                break;
            case 5:
                cout << "\n====================================ВЫВОД ТАБЛИЦЫ=================================\n";
                PrintDbase(abonents);
                cout << "==================================================================================\n";
                break;
            case 6:
                cout << "\n====================================ВВОД В ТАБЛИЦУ=================================";
                WriteDBase(abonents);
                cout << "\n==================================================================================\n";
                break;
            case 7:
                cout << "\n====================================СОРТИРОВКА ТАБЛИЦЫ=================================\n";
                SortPlanets(abonents);
                cout << "==================================================================================\n";
                break;
            case 8:
                cout << "\n====================================СЧИТЫВАНИЕ С ФАЙЛА=================================\n";
                ReadFile(abonents);
                cout << "\n==================================================================================\n";
                break;
            case 9:
                cout << "\n===================ВЫХОД=======================\n";
                p = false;
                cout<<"ПОКА"<<endl;
                break;
        }
    }
    delete[] abonents;
    return 0;
}

int Menu(){
    cout << "\n======================= ГЛАВНОЕ МЕНЮ ========================\n";
    cout << "1 - Добавление абонента\t\t 4 - Корректировка сведений\n";
    cout << "2 - Удаление абонента\t\t 5 - Вывод базы на экран\n";
    cout << "3 - Поиск абонента\t\t 6 - Вывод базы в файл\n";
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

void PrintDbase(Abonent* abonent){
    for (int i = 0; abonent[i].GetNumber() != 0; i++){
        cout << i+1 << ") " << abonent[i];
    }
}

int MenuFind(){
    cout<<"\n--------------------- ПОИСК --------------------------\n";
    cout<<"1 - Поиск по имени абоента\t 2 - Поиск по номеру\n";
    cout<<"3 - Поиск по активности\t 4 - Поиск по цене\n";
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

void FindPlanet(Abonent* abonent, int n){
    char name[40];
    int number;
    bool active;
    unsigned short cost;

    while(true){
        switch (MenuFind()) {
            case 1:
                cout << "Введите имя абонента: ";
                cin >> name;
                Find(abonent, n, name);
                break;
            case 2:
                cout << "Введите номер абонента: ";
                cin >> number;
                number = (int)number;
                Find(abonent, n, number);
                break;
            case 3:
                cout << "Введите активен ли номер: ";
                cin >> active;
                active = (bool)active;
                Find(abonent, n, active);
                break;
            case 4:
                cout << "Введите цену: ";
                cin >> cost;
                cost = (unsigned short)cost;
                Find(abonent, n, cost);
                break;
            case 5:
                return;
                break;
            default:
                cout<<"Неверный ввод";
        }
    }
}

void Find(Abonent* abonents, int n, char* name){
    int k = 0;
    int _n = 0;
    for (int i = 0; abonents[i].GetNumber() != 0; i++) {
        _n++;
    }
    for (int i = 0; i< _n; i++){
        if(!strcmp(abonents[i].GetName(), name)){
            cout<<abonents[i];
            k++;
        }
    }
    if (k==0){
        cout << "Не найдено такго абонента по введенному значению!\n";
    }
    cout<<endl;
}
void Find(Abonent* abonents, int n, bool active){
    int k = 0;
    for (int i = 0; i< n; i++){
        if(active==abonents[i].GetActive()){
            cout << abonents[i];
            k++;
        }
    }
    if (k==0){
        cout << "Не найдено такого абонента по введенному значению!\n";
    }
    cout<<endl;
}
void Find(Abonent* abonents, int n, unsigned short cost){ //По спутникам
    int k = 0;
    for (int i = 0; i< n; i++){
        if(cost==abonents[i].GetCost()){
            cout << abonents[i];
            k++;
        }
    }
    if (k==0){
        cout << "Не найдено такго абонента по введенному значению!\n";
    }
    cout<<endl;
}
void Find(Abonent* abonents, int n, int number){
    int k = 0;
    for (int i = 0; i< n; i++){
        if(abonents[i].GetNumber() == number){
            cout << abonents[i];
            k++;
        }
    }
    if (k==0){
        cout << "Не найдено такго абонента по введенному значению!\n";
    }
    cout<<endl;
}

Abonent* Add(Abonent* abonents){
    Abonent ab;
    cin>>ab;

    int n = 0;
    for (int i = 0; abonents[i].GetNumber() != 0; i++) {
        n++;
    }

    Abonent* abonent = new Abonent[n + 2];
    for(int i = 0; i<n; i++){
        abonent[i] = abonents[i];
    }
    delete[] abonents;
    cout<<ab;
    abonent[n] = ab;
    cout<<"Успешно добавили планету!";
    return abonent;
}

Abonent* Delete(Abonent* abonents){
    PrintDbase(abonents);
    cout<<"Введите номер абонента, которого хотите удалить: ";

    int n = 0;
    for (int i = 0; abonents[i].GetNumber() != 0; i++) {
        n++;
    }

    Abonent* abonent = new Abonent[n];
    int deleteNumber;
    cin>>deleteNumber;
    int c = 0;
    if(deleteNumber<=n && deleteNumber>0){
        for(int i = 0; i<n; i++){
            if(i!=deleteNumber-1){
                abonent[c] = abonents[i];
                c++;
            }
        }

        delete[] abonents;
        return abonent;
    }
    cout << "Неподходящий номер!";
    return abonents;
}

void CorrectionOfInformation(Abonent* abonents){
    PrintDbase(abonents);
    cout << "Выберите, у какого абонента хотите корректировать сведенья: ";

    int n = 0;
    for (int i = 0; abonents[i].GetNumber() != 0; i++) {
        n++;
    }

    int choose;
    cin >> choose;

    if(choose>0 && choose<n+1){
        int why;
        cout << abonents[choose - 1];
        cout<<"Выберите какое сведение будете корректировать(1-имя, 2-номер, 3-активность, 4-цена): ";
        cin >> why;

        char name[40];
        long number;
        bool active;
        unsigned short cost;
        if(why>0 && why<5){
            switch (why) {
                case 1:
                    cout<<"Введите новое имя: ";
                    cin >> name;
                    abonents[choose - 1].SetName(name);
                    cout<<"Вы успешно поменяли имя на " << name;
                    break;
                case 2:
                    cout<<"Введите новый номер(пример 8005553535): ";
                    cin >> number;
                    abonents[choose - 1].SetNumber(number);
                    cout<<"Вы успешно поменяли номер на " << number;
                    break;
                case 3:
                    cout<<"Введите новую информацию об активности (1-еть 0-нет): ";
                    cin >> active;
                    abonents[choose - 1].SetActive(active);
                    cout<<"Вы успешно поменяли активность на " ;
                    active==1?cout<<"'активно'":cout<<"'не активно'";
                    break;
                case 4:
                    cout<<"Введите новую цену(от 0): ";
                    cin >> cost;
                    abonents[choose - 1].SetCost(cost);
                    cout<<"Вы успешно поменяли цену на " << cost;
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

void WriteDBase(Abonent* abonents){
    int n = 0;
    for (int i = 0; abonents[i].GetNumber() != 0; i++) {
        n++;
    }

    ofstream fout;
    fout.open("dbase.txt");
    fout.clear();
    if(fout.is_open()){
        fout<<n<<'\n';
        for (int i = 0; i < n; ++i) {
            fout << abonents[i].GetName() << ' ' << abonents[i].GetNumber() << ' ' << abonents[i].GetActive() << ' ' << abonents[i].GetCost() << '\n';
        }
        cout<<"\nУспешно введено в базу данных!";
    }
    else{
        cout<<"\nНе найден файл";
    }
    fout.close();
}

void SortPlanets(Abonent* abonents){
    int n = 0;
    for (int i = 0; abonents[i].GetNumber() != 0; i++) {
        n++;
    }
    Abonent pl;
    for(int i = 0; i < n-1; i++){
        for (int j = 0; j<n-i-1; j++){
            if(abonents[j].GetCost() > abonents[j + 1].GetCost()){
                pl = abonents[j];
                abonents[j] = abonents[j+1];
                abonents[j+1] = pl;
            }
        }
    }
    PrintDbase(abonents);
}


void ReadFile(Abonent* abonents){

    ifstream fin("dbase.txt", ios::in);
    if (!fin) {
        cout << "Heт файла dbase.txt" << endl;
    }
    int n = 0;
    fin>>n;
    char t[20];
    if(abonents[0].GetNumber() == 0){
        for (int i = 0; i < n; i++) {
            fin >> t;
            cout<<t <<' ';
            abonents[i].SetName(t);
            fin >> t;
            cout << t<<' ';
            abonents[i].SetNumber(stod(t));
            fin >> t;
            cout<<t<<' ';
            abonents[i].SetActive(stoi(t));
            fin >> t;
            cout<<t<<'\n';
            abonents[i].SetCost(stoi(t));
        }
        cout<<"Успешно считалось!";
    }
    else{
        cout<<"Файл уже считался!";
    }

    fin.close();
}