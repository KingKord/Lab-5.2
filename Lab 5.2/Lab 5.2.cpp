// вариант 3,18
// Горбатых Александр
#include <iostream>
#include <ctime>
using namespace std;

void init(int** Mas, int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			Mas[i][j] = rand() % 10 -5;
			cout << Mas[i][j] << "\t";
		}
		cout << endl;
	}
}
// та самая функция
int** hren(int** Mas, int n, int m) {
	int** Mas_rez = new int*[n * m];
	int** pmas = Mas;
	int** prez = Mas_rez;
	int k = 0;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			if ((i >= j and 10 - i > j or i <= j and 9 - i <= j) and Mas[i][j] < 0) { // условие на заштрихованную зону и на знак числа
				prez = pmas;
				prez++;
			}
			pmas++;


		}
	}

	return Mas_rez;
	delete[] Mas_rez;
}


int main() {
	srand(time(0));

	//
	cout << "Enter the size of dinamic array ";
	int n, m;
	cin >> n >> m;
	int** Mas = new int* [n];
	for (int i = 0; i < m; i++) Mas[i] = new int[m];
	init(Mas, n, m);

	// сам массив и вызов функции
	int** sobaka = new int*[m * n];
	sobaka = hren(Mas, n, m);
	// далее идёт удаление

	delete[] sobaka;


	for (int i = 0; i < n; i++)
		delete[] Mas[i];
	delete[] Mas;
	return 0;
}