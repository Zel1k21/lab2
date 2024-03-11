#include <iostream>
#include <iomanip>
#include <fstream>
#include <locale>
#include <cstring>

namespace planets {

	class Planet {
	private:
		char* name;
		int diametr;
		bool life;
		int satelites;
	public:
		Planet();
		Planet(char*, int, bool, int);

		void editPlanet();

		char* getName();
		int getDiametr();
		bool getLife();
		int getSatelites();

		void setName(char*);
		void setDiametr(int);
		void setLife(bool);
		void setSatelites(int);


		friend std::istream& operator >> (std::istream&, Planet&);
		friend std::ifstream& operator >> (std::ifstream&, Planet&);
		friend std::ofstream& operator << (std::ofstream&, Planet&);
		void printPlanet();

		~Planet();

	};

	int menu();
	int choosePlanet(Planet*, int);
	Planet* readDataBase(const char*, int&);
	void printDataBase(Planet*, int);
	int writeDataBase(const char*, Planet*, int);
	void copyPlanet(Planet&, Planet&);
	void exchangePlanets(Planet&, Planet&);

	bool operator > (Planet&, Planet&);
	
	Planet* addPlanet(Planet*, int&);
	Planet* deletePlanet(Planet*, int&);
	Planet* sortPlanets(Planet*, int);

}

