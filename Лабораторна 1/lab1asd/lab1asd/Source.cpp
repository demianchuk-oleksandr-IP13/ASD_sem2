#include <iostream>
using namespace std;

int* generatearr(int size) {
	srand(time(NULL));
	int* arr = new int[size];
	for (int i = 0; i < size; i++) {
		arr[i] = rand() % size;
	}
	return arr;
}

int* perfectarr(int size) {
	int* arr = new int[size];
	for (int i = 0; i < size; i++) {
		arr[i] = i;
	}
	return arr;
}

int* worstarr(int size) {
	int* arr = new int[size];
	for (int i = 0; i < size; i++) {
		arr[i] = size - i;
	}
	return arr;
}

void bubble(int* arr, int size, int &comp, int &swap) {
	for (int i = 0; i < size - 1; i++) {
		bool swapped = false;
		for (int j = 0; j < size - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				swapped = true;
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				swap++;
			}
			comp++;
		}
		if (swapped == false) break;
	}
}

void comb(int* arr, int size, int& comp, int& swap) {
	int step = size - 1;
	double factor = 1.3;
	while (step >= 1) {
		for (int i = 0; i + step < size; i++) {
			if(arr[i] > arr[i+step]) {
				int temp = arr[i];
				arr[i] = arr[i + step];
				arr[i + step] = temp;
				swap++;
			}
			comp++;
		}
		step /= factor;
	}
}

void printarr(int* arr, int size) {
	if (size > 100) {
		for (int i = 0; i < 50; i++) {
			cout << arr[i] << " ";
		}
		cout << "... ";
		for (int i = size - 51; i < size; i++) {
			cout << arr[i] << " ";
		}
		cout << endl;
	}
	else
	{
		for (int i = 0; i < size; i++) {
			cout << arr[i] << " ";
		}
		cout << endl;
	}
}

int main() {
	int size = 0;
	while (size <= 0) {
		cout << "enter size: ";
		cin >> size;
	}
	char method;
	cout << "choose sorting method (bubble - b, comb - c): ";
	cin >> method;
	if (method == 'b') {
		int comp = 0;
		int swap = 0;
		int* perfect = perfectarr(size);
		cout << "PERFECT ARRAY IS: \n";
		printarr(perfect, size);
		bubble(perfect, size, comp, swap);
		cout << "SORTED ARRAY IS: \n";
		printarr(perfect, size);
		cout << "comparisons: " << comp << endl;
		cout << "swaps: " << swap << endl << endl;
		delete[] perfect;

		comp = 0;
		swap = 0;
		int* random = generatearr(size);
		cout << "RANDOM ARRAY IS: \n";
		printarr(random, size);
		bubble(random, size, comp, swap);
		cout << "SORTED ARRAY IS: \n";
		printarr(random, size);
		cout << "comparisons: " << comp << endl;
		cout << "swaps: " << swap << endl << endl;
		delete[] random;

		comp = 0;
		swap = 0;
		int* worst = worstarr(size);
		cout << "WORST ARRAY IS: \n";
		printarr(worst, size);
		bubble(worst, size, comp, swap);
		cout << "SORTED ARRAY IS: \n";
		printarr(worst, size);
		cout << "comparisons: " << comp << endl;
		cout << "swaps: " << swap << endl << endl;
		delete[] worst;
	}
	if (method == 'c') {
		int comp = 0;
		int swap = 0;
		int* perfect = perfectarr(size);
		cout << "PERFECT ARRAY IS: \n";
		printarr(perfect, size);
		comb(perfect, size, comp, swap);
		cout << "SORTED ARRAY IS: \n";
		printarr(perfect, size);
		cout << "comparisons: " << comp << endl;
		cout << "swaps: " << swap << endl << endl;
		delete[] perfect;

		comp = 0;
		swap = 0;
		int* random = generatearr(size);
		cout << "RANDOM ARRAY IS: \n";
		printarr(random, size);
		comb(random, size, comp, swap);
		cout << "SORTED ARRAY IS: \n";
		printarr(random, size);
		cout << "comparisons: " << comp << endl;
		cout << "swaps: " << swap << endl << endl;
		delete[] random;

		comp = 0;
		swap = 0;
		int* worst = worstarr(size);
		cout << "WORST ARRAY IS: \n";
		printarr(worst, size);
		comb(worst, size, comp, swap);
		cout << "SORTED ARRAY IS: \n";
		printarr(worst, size);
		cout << "comparisons: " << comp << endl;
		cout << "swaps: " << swap << endl << endl;
		delete[] worst;
	}
}