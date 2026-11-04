// ConsoleApplication8.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
using namespace std; 
void showPopulation(int day, int suspectible, int infected, int recovered); 
void simulateDay(int& day, int& susceptible, int& infected, int& recovered, double& infectionRate, double& recoveryRate); 
bool checkPopulation(int susceptible, int infected, int recovered); 
int susceptible = 80;
int infected = 10;
int recovered = 10;
int day = 0;
double infectionRate = 0.20;
double recoveryRate = 0.10;
int main() {
	int susceptible = 80;
	int infected = 10;
	int recovered = 10;
	int day = 0;
	double infectionRate = 0.20;
	double recoveryRate = 0.10;
	char option;
	while (true) {
		if (checkPopulation(susceptible, infected, recovered) == false) {
			cout << "Error! Population count does not match" << endl;
		}
		showPopulation(day, susceptible, infected, recovered);
		cout << " === Epidemic symulator === " << endl;
		cout << "1. Simulate next day" << endl;
		cout << "2. Change model parametrs" << endl;
		cout << "3. Exit" << endl;
		cout << "Your choice: " << endl;
		cin >> option;
		switch (option) {
		case '1':
			simulateDay(day, susceptible, infected, recovered, infectionRate, recoveryRate);
			break;
		case '2': {
			double tempInfectionRate;
			do {
				cout << "Enter infection rate (0-1): " << endl;
				cin >> tempInfectionRate;
				if (tempInfectionRate < 0 || tempInfectionRate >1) {
					cout << "Error: Value mus be between 0 and 1. Keeping previous value" << endl;
				}
			} while (tempInfectionRate < 0 || tempInfectionRate > 1);
			infectionRate = tempInfectionRate;
			double tempRecoveryRate;
			do {
				cout << "Enter recovery rate (0-1): " << endl;
				cin >> tempRecoveryRate;
				if (tempRecoveryRate < 0 || tempRecoveryRate >1) {
					cout << "Error: Value must be between 0 and 1. Keeping previous value" << endl;
				}
			} while (tempRecoveryRate < 0 || tempRecoveryRate >1);
			recoveryRate = tempRecoveryRate;
			break;
		}
		case '3':

			cout << "Program finished " << endl;
			return 0;
		default:
			cout << "Incorrect choice " << endl;

		}
	} return 0; 
}

void showPopulation(int day, int susceptible, int infected, int recovered) {
	cout << "Day: " << day << endl; 
	cout << "Suspectible: " << susceptible << endl; 
	cout << "Infected: " << infected << endl; 
	cout << "Recovered: " << recovered << endl; 
	cout << "Total: " << susceptible + infected + recovered << endl; 

}

void simulateDay(int &day,int &susceptible, int &infected, int &recovered, double &infectionRate, double &recoveryRate) {
	int initialInfected = infected;
	int newInfections = (int)(infected * infectionRate);
	int newRecoveries = (int)(initialInfected * recoveryRate);
	if (newInfections > susceptible) {
		newInfections = susceptible;
	} if (newRecoveries > initialInfected) {
		newRecoveries = initialInfected;
	}
	susceptible = susceptible - newInfections;
	infected = infected + newInfections - newRecoveries;
	recovered = recovered + newRecoveries;
	day = day + 1;
} 


bool checkPopulation(int susceptible, int infected, int recovered) {
	if (susceptible >= 0 && infected >= 0 && recovered >= 0 && (susceptible + infected + recovered == 100)) {
		return true;
	}
	else {
		return false;
	}
} 





