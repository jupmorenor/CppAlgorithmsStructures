/**
 * Juan Pablo Moreno Rico 20111020059
 * Ciencias de la computacion 1 grupo 82 2014-2
 */

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <windows.h>
using namespace std;

ofstream resultados;
LARGE_INTEGER frecuencia;
LARGE_INTEGER inicio;
LARGE_INTEGER finale;
LARGE_INTEGER delta;

void print(int a[], int N) {
	for(int i=0; i<N; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}

bool isSafe(int queen_number, int row_position, int *position) {
	// Check each queen before this one
	for (int i = 0; i < queen_number; i++) {
		// Get another queen's row_position
		int other_row_pos = position[i];

		// Now check if they're in the same row or diagonals
		if (other_row_pos == row_position || // Same row
				other_row_pos == row_position - (queen_number - i) || // Same diagonal
				other_row_pos == row_position + (queen_number - i)) // Same diagonal
			return false;
	}
	return true;
}

void solve(int k, int N, int *position)
{
	if (k == N) // We placed N-1 queens (0 included), problem solved!
	{
		// Solution found!
	}
	else
	{
		for (int i = 0; i < N; i++) // Generate ALL combinations
		{
			// Before putting a queen (the k-th queen) into a row, test it for safeness
			if (isSafe(k, i, position))
			{
				position[k] = i;
				// Place another queen
				solve(k + 1, N, position);
			}
		}
	}
}

int main() {
	int *position;
	float tiempo;
	resultados.open("resultados.txt");
	QueryPerformanceFrequency(&frecuencia);
	for (int N = 1; N <= 30; N++) {
		position = new int[N];
		QueryPerformanceCounter(&inicio);
		solve(0, N, position);
		QueryPerformanceCounter(&finale);
		print(position, N);
		delta.QuadPart = finale.QuadPart - inicio.QuadPart;
		tiempo = ((float)delta.QuadPart)/frecuencia.QuadPart;

		resultados << tiempo*1000 << "\n";
	}
	resultados.close();
	cout << "terminado" << endl;
	return 0;
}
