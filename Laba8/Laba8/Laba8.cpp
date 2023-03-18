#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <time.h>
#include <locale.h>
#include <queue>
using namespace std;

#define N 5

void newMat(int* mas) {
	srand(time(0));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i == j) {
				mas[N * i + j] = 0;
			}
			if (i < j) {
				mas[N * i + j] = rand() % 2;
				mas[j * N + i] = mas[N * i + j];
			}
		}
	}
}

void printMat(int* mas) {

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printf("%d ", mas[N * i + j]);
		}
		printf("\n");
	}
}

void BFS(int s, int* G, int* num) {

	queue<int> q;
	q.push(s);
	num[s] = 1;
	while (!q.empty()) {
		s = q.front();
		printf("%d ", s);
		q.pop();

		for (int i = 0; i < N; i++) {
			if (G[s * N + i] == 1 && num[i] == 0) {
				q.push(i);
				num[i] = 1;
			}
		}
	}
}

int main() {
	int G[N][N], num[N], s;
	setlocale(LC_ALL, "rus");

	newMat(&G[0][0]);
	printMat(&G[0][0]);

	for (int i = 0; i < N; i++) {
		num[i] = 0;
	}

	printf("Введите номер вершины: ");
	scanf("%d", &s);
	printf("Результат: ");
}