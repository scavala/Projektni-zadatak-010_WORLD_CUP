#include <iostream>
#include "insertion_sort.h"
using namespace std;

int insertion_sort(Match data[], int n) {
	int brojac = 0;
	for (int i = 0; i < n; i++) { 
		for (int j = i; j > 0; j--) {
			if (data[j - 1].get_homeINITIALS() > data[j].get_homeINITIALS()) {
				swap(data[j], data[j - 1]);
				brojac++;
			}
		}
	}

	return brojac;
}