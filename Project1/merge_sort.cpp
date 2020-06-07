#include <iostream>
#include "merge_sort.h"
#include <fstream>
using namespace std;
int brojac = 0;

void pisanjeUdatoteku(int n) {

	ofstream dat2;
	dat2.open("brojaczamergesort.txt", std::ios_base::app);
	for (int i = 0; i < n; i++)
	{
		dat2 << "#";
	}
	dat2 << endl;
	dat2.close();

}



void merge(Match* poljea, int na, Match* poljeb, int nb) {
	
	Match* poljec = new Match[na + nb];

	int ia = 0, ib = 0;
	for (int ic = 0; ic < na + nb; ic++) {
		if (ia == na) { // Ispraznili smo polje a.
			poljec[ic] = poljeb[ib++];
			continue;
		}
		if (ib == nb) { // Ispraznili smo polje b.
			poljec[ic] = poljea[ia++];
			continue;
		}

		if (poljea[ia].get_year() < poljeb[ib].get_year()) {
			poljec[ic] = poljea[ia++];
		}
		else {
			poljec[ic] = poljeb[ib++];
		}
	}

	for (int i = 0; i < na + nb; i++) {
		poljea[i] = poljec[i];
	}

	delete[] poljec;
}

void merge_sort(Match data[], int from, int to) {
	if (from == to) { // Uvjet zaustavljanja.
		return;
	}

	int mid = (from + to) / 2;
	brojac++; pisanjeUdatoteku(brojac); merge_sort(data, from, mid); brojac--; pisanjeUdatoteku(brojac);
	brojac++; pisanjeUdatoteku(brojac);	merge_sort(data, mid + 1, to); brojac--; pisanjeUdatoteku(brojac);

	brojac++; pisanjeUdatoteku(brojac); merge(data + from, mid - from + 1, data + mid + 1, to - mid); brojac--; pisanjeUdatoteku(brojac);
}

void merge_sort(Match data[], int n) {
	brojac++; pisanjeUdatoteku(brojac); merge_sort(data, 0, n - 1); brojac--; pisanjeUdatoteku(brojac);
}
