#include<iostream>
#include<fstream>
using namespace std;

int **arraymass(char *fname,int *m ,int *n){
	int buff;
	ifstream fin(fname);
	fin >> buff;
	*n = buff;
	fin >> buff;
	*m = buff;
	int **arr = new int *[*n];
	for (int i = 0; i < *n; i++) {
		arr[i] = new int[*m];
		for (int j = 0; j < *m; j++) {
			fin >> buff;
			arr[i][j] = buff;
		}
	}
	return arr;
}

double sumpol(int *arr[],int n ,int m) {
	int sum = 0;
    int num = 0;
	double sred = 0.0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] > 0) {
				sum += arr[i][j];
				num ++;
		 }
		}
	}
	sred = sum / num;
	return sred;
}

void otvet(int *arr[], int n, int m) {
	int l = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] < 0) {
				l++;
			}
		}
		cout << "в " << i + 1 << "-ой строке отрицательных элементов " << l << endl;
		l = 0;
	}
}
int main(int argc, char *argv[]) {
	int n1 = 0;
	int n2 = 0;
	int m1 = 0;
	int m2 = 0;
	double sum1, sum2;
	setlocale(LC_ALL, "rus");

	int **arr1 = arraymass(argv[1],&m1,&n1);
	int **arr2 = arraymass(argv[2], &m2, &n2);
	/*for (int i = 0; i < n1; i++) {
		for (int j = 0; j < m1; j++) {
			cout << arr1[i][j];
		}
		cout << '\n';
	}
	for (int i = 0; i < n2; i++) {
		for (int j = 0; j < m2; j++) {
			cout << arr2[i][j];
		}
		cout << '\n';
	}*/
	sum1 = sumpol(arr1, n1, m1);
	sum2 = sumpol(arr2, n2, m2);
	if (sum1 == sum2) {
		cout << "среднее арифмитическое положительных эл-тов матриц одинаковое";
	}
	else {
		if (sum1 > sum2) {
			cout << "в первой матрицы больше среднее арифмитическое положительных"<<endl;
			otvet(arr1, n1, m1);
		}
		else {
			cout << "во второй матрицы больше среднее арифмитическое положительных" << endl;
			otvet(arr1, n1, m1);
		}
	}
	system("pause");
	return 0;
}
