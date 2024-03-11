#include "planet.h"

namespace planets {

    planets::Planet::Planet()
    {
        name = nullptr;
        diametr = 0;
        satelites = 0;
        life = false;
    }

    planets::Planet::Planet(char* newName, int newDiametr, bool newLife, int newSatelites)
    {
        strncpy(name, newName, strlen(newName));
        diametr = newDiametr;
        life = newLife;
        satelites = newSatelites;
    }

    bool operator > (Planet& p1, Planet& p2) {
        if (p1.getDiametr() > p2.getDiametr())
            return true;
        else
            return false;
    }

    std::istream& operator>>(std::istream& in, Planet& p1)
    {
        char* newName = new char[64];
        std::cin.getline(newName, '\n');
        p1.name = newName;
        in >> p1.diametr;
        in >> p1.life;
        in >> p1.satelites;
        return in;
    }

    char* getName(char* line) {
        char* name = new char[64];
        for (int i = 0; i < 64; i++) {
            if (line[i] == ' ' || line[i] == '\n') {
                strncpy(name, line, i);
                return name;
            }
        }
        return nullptr;
    }

    std::ifstream& operator>>(std::ifstream& in, Planet& p1)
    {
        char* newName = new char[64];
        in >> newName;
        p1.name = newName;
        in >> p1.diametr;
        in >> p1.life;
        in >> p1.satelites;
        return in;
        
    }

    std::ofstream& operator<<(std::ofstream& out, Planet& p1)
    {
        out << p1.name << ' ' << p1.diametr << ' ' << p1.life << ' ' << p1.satelites << std::endl;
        return out;
    }

    void Planet::printPlanet() 
    {
        std::cout << this->name << std::setw(10) << this->diametr << ' ' << this->life << ' ' << this->satelites << std::endl;
    }


    Planet* addPlanet(Planet* oldArray, int& n)
    {
        n += 1;
        Planet* newArray = new Planet[n];
        for (int i = 0; i < n - 1; i++)
            copyPlanet(newArray[i], oldArray[i]);
        std::cin >> newArray[n - 1];
        newArray[n - 1].printPlanet();
        return newArray;
    }

    void copyPlanet(Planet& p1, Planet& p2)
    {
        p1.setName(p2.getName());
        p1.setDiametr(p2.getDiametr());
        p1.setLife(p2.getLife());
        p1.setSatelites(p2.getSatelites());
    }

    void exchangePlanets(Planet& p1, Planet& p2)
    {
        char* tempName = new char[64];
        strncpy(tempName, p2.getName(), 64);
        int tempDiametr = p1.getDiametr(), tempSatelites = p1.getSatelites();
        bool tempLife = p1.getLife();
        copyPlanet(p1, p2);

        p2.setName(tempName);
        p2.setDiametr(tempDiametr);
        p2.setLife(tempLife);
        p2.setSatelites(tempSatelites);
    }

    Planet* deletePlanet(Planet* oldArray, int& n)
    {
        int userInput, j = 0;
        Planet* newArray = new Planet[n - 1];
        userInput = choosePlanet(oldArray, n);
        for (int i = 0; i < n; i++) {
            if (n < userInput)
                copyPlanet(newArray[i], oldArray[i]);
            else if (i > userInput)
                copyPlanet(newArray[i - 1], oldArray[i]);
        }
        n -= 1;
        return newArray;
    }

    void planets::Planet::editPlanet() {
        int userInput;
        while (true) {
            std::cout << "1. �������� �������� ������� \t 4. �������� ���-�� ����������" << std::endl;
            std::cout << "2. �������� ������� ������� \t 5. �����" << std::endl;
            std::cout << "3. �������� ������� �����" << std::endl;
            std::cin >> userInput;
            switch (userInput) {
            case 1:
            {
                char* newName = new char[64];
                std::cin >> newName;
                this->setName(newName);
                break;
            }
            case 2: {
                int newDiametr;
                std::cin >> newDiametr;
                this->setDiametr(newDiametr);
                break;
            }
            case 3:
                bool newLife;
                std::cin >> newLife;
                this->setLife(newLife);
                break;
            case 4:
                int newSatelites;
                std::cin >> newSatelites;
                this->setSatelites(newSatelites);
                break;
            case 5:
                return;
            default:
                std::cout << "������������ ����" << std::endl << "���������� ��� ���:" << std::endl;
            }
        }
    }

    char* planets::Planet::getName()
    {
        return name;
    }

    int planets::Planet::getDiametr()
    {
        return diametr;
    }

    bool planets::Planet::getLife()
    {
        return life;
    }

    int planets::Planet::getSatelites()
    {
        return satelites;
    }

    void planets::Planet::setName(char* newName)
    {
        delete[] this->name;
        const size_t bufSz = strlen(newName) + 1;
        this->name = new char[bufSz];
        strncpy(this->name, newName, bufSz);
    }

    void planets::Planet::setDiametr(int newDiametr)
    {
        this->diametr = newDiametr;
    }

    void planets::Planet::setLife(bool newLife)
    {
        this->life = newLife;
    }

    void planets::Planet::setSatelites(int newSatelites)
    {
        this->satelites = newSatelites;
    }

    planets::Planet::~Planet() { delete[] name; }

    int menu() {
        std::cout << " ============== ������� ���� ========================\n";
        std::cout << "1 - ������� ���� ������\t\t\t 5 - ������� �������" << std::endl;
        std::cout << "2 - ��������� ���� ������ \t\t 6 - �������� �������" << std::endl;
        std::cout << "3 - ����������� ���� ������ \t\t 7 - ����� ���� �� �����" << std::endl;
        std::cout << "4 - �������� ������� \t\t\t 8 - �����" << std::endl;
        std::cout << "��� ������ �������� ������� ����� �� 1 �� 8" << std::endl;
        int userInput;
        std::cin >> userInput;
        std::cin.clear();
        std::cin.ignore(10, '\n');
        system("cls");
        return userInput;
    }

    Planet* readDataBase(const char* fileName, int& n)
    {
        std::ifstream fin(fileName, std::ios::in);
        if (!fin) {
            std::cout << "He� ����� " << fileName << std::endl;
            return nullptr;
        }
        fin >> n;
        Planet* newArray = new Planet[n];
        for (int i = 0; i < n; i++)
            fin >> newArray[i];
        fin.close();
        return newArray;
    }

    void printDataBase(Planet* array, int n) {
        std::cout << n << " ������: " << std::endl;
        for (int i = 0; i < n; i++) {
            std::cout << i+1 << ". ";
            array[i].printPlanet();
        }

    }

    int writeDataBase(const char* fileName, Planet* array, int n)
    {
        std::ofstream fout(fileName, std::ios::out);
        if (!fout) {
            std::cout << "He� ����� " << fileName << std::endl;
            return 1;
        }
        fout << n << std::endl;
        for (int i = 0; i < n; ++i)
            fout << array[i];
        fout.close();
        return 0;
    }

    Planet* sortPlanets(Planet* array, int n)
    {
        for (int i = 0; i < n - 1; i++)
            for (int j = i + 1; j < n; j++)
                if (array[i] > array[j])
                    exchangePlanets(array[j], array[i]);
                    
        return array;
    }

    int choosePlanet(Planet* array, int n) {
        int userInput;
        std::cout << "�������� �������:" << std::endl;
        for (int i = 0; i < n; i++)
            std::cout << i + 1 << ". " << array[i].getName() << std::endl;
        std::cin >> userInput;
        return userInput - 1;
    }

}