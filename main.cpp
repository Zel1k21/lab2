#include "planet/planet.h"
#include "product/product.h"

using namespace planets;

int main() {
	setlocale(LC_ALL, "RUSSIAN");
	const char* fileName = "dataBase.txt";
	const char* productsDataBase = "productsDataBase.txt";
	Planet* planets = new Planet[0];
	product::Product* products = new product::Product[0];
	int planetsAmount = 0, productsAmount = 0, mode = 0;
	std::cout << "� ��� �� ������ ��������:" << std::endl << "1 - �������" << std::endl << "2 - ��������" << std::endl;
	std::cin >> mode;
	if (mode == 1) {
		while (true) {
			switch (menu()) {
			case 1:
				planets = readDataBase(fileName, planetsAmount);
				break;
			case 2:
				writeDataBase(fileName, planets, planetsAmount);
				break;
			case 3:
				planets = sortPlanets(planets, planetsAmount - 1);
				break;
			case 4:
				planets = addPlanet(planets, planetsAmount);
				break;
			case 5:
				planets = deletePlanet(planets, planetsAmount);
				break;
			case 6:
			{
				int p = choosePlanet(planets, planetsAmount);
				planets[p].editPlanet();
				break;
			}
			case 7:
				printDataBase(planets, planetsAmount);
				break;
			case 8:
				return 0;
			default:
				std::cout << "������������ ����" << std::endl << "���������� ��� ���:" << std::endl;
			}
		}
		delete[] planets;
	}
	else {
		while (true) {
			switch (product::productMenu()) {
			case 1:
				products = product::readDataBase(productsDataBase, productsAmount);
				break;
			case 2:
				product::writeDataBase(productsDataBase, products, productsAmount);
				break;
			case 3:
				products = product::sortProducts(products, productsAmount - 1);
				break;
			case 4:
				products = product::addProduct(products, productsAmount);
				break;
			case 5:
				products = product::deleteProduct(products, productsAmount);
				break;
			case 6:
			{
				int p = product::chooseProduct(products, productsAmount);
				products[p].editProduct();
				break;
			}
			case 7:
				product::printDataBase(products, productsAmount);
				break;
			case 8:
				return 0;
			default:
				std::cout << "������������ ����" << std::endl << "���������� ��� ���:" << std::endl;
			}
		}
		delete[] products;
	}
	
	return 0;
}