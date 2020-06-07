#include <iostream>
#include <sstream>
#include <fstream>
#include "Match.h"
#include <iomanip>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <ctime>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include "selection_sort.h"
#include "insertion_sort.h"
#include <chrono>
#include "merge_sort.h"
#include<algorithm>

#include <random>
using namespace std;

bool mozeliseiz(string kratica, string stadium) {

	transform(kratica.begin(), kratica.end(), kratica.begin(), tolower);
	transform(stadium.begin(), stadium.end(), stadium.begin(), tolower);
	vector<char> kraticaV(kratica.begin(), kratica.end());
	vector<char> stadiumV(stadium.begin(), stadium.end());


	sort(kraticaV.begin(), kraticaV.end());
	sort(stadiumV.begin(), stadiumV.end());

	return (includes(stadiumV.begin(), stadiumV.end(),
		kraticaV.begin(), kraticaV.end()));
}


void loadvectorUmultimapunordered(vector<Match>& utakmice, unordered_multimap<string, Match> &multimapica) {

	for (int i = 0; i < utakmice.size(); i++)
	{
		multimapica.emplace(utakmice[i].get_stadium(), utakmice[i]);

	}

}

class HashFunkcijaZaSet {
public:
	size_t operator()(const Match& t) const {
		return t.get_year();
	}
};
class HashFunkcijaZaSet2 {
public:
	size_t operator()(const Match& t1, const Match& t2) const {
		return t1.get_year()< t2.get_year();
	}
};

bool is_sorted_ascending(vector<Match>& v)
{
	for (unsigned i = 0; i < v.size() - 1; i++)
	{
		if (v[i].get_year() > v[i + 1].get_year())
		{
			return false;
		}
	}
	return true;
}



struct minheapbro {
	bool operator()(const long& a, const long& b) const {
		return a > b;
	}
};

void napunipolje(int* polje,int brojbrojeva) {

	for (int i = 1; i <= brojbrojeva; i++)
	{
		polje[i] = i;
	}


}
int get_rnd(int min, int max) {

	random_device rd;
	mt19937 gen(rd());

	uniform_real_distribution<> distribution(min, max);


	int random = distribution(gen);
	return random;

}

void load(vector<Match>& utakmice, Match* matchevi, const int BROJ_ELEMENATA) {


	for (int i = 0; i < BROJ_ELEMENATA; i++)
	{

		matchevi[i] = utakmice[i];

	}

}

void print(Match& utakmica)
{
	utakmica.ispis();
}



void vectorUmapu(vector<Match> &utakmice, multimap<int, Match> &brojgolovamapa) {
	for (int i = 0; i < utakmice.size(); i++)
	{
		int z = utakmice[i].get_awayteamgoals() + utakmice[i].get_hometeamgoals();
		brojgolovamapa.emplace(z, utakmice[i]);

	}
}


struct find_team {
	find_team(const string& team) : team(team) {}
	bool operator()(const Match& match) {
		return match.get_homeINITIALS() == team || match.get_awayINITIALS()==team;
	}
private:
	string team;
};


struct pogodinama {// i po abecedi
	
	const bool operator()(const Match& _Left, const Match& _Right) const {

		if (_Left.get_year() == _Right.get_year()) {

			if (_Left.get_hometeamname()[0] == _Right.get_hometeamname()[0]) {
				return _Left.get_hometeamname()[1] > _Right.get_hometeamname()[1];

			}


			return _Left.get_hometeamname()[0] > _Right.get_hometeamname()[0];
		}

		return _Left.get_year() > _Right.get_year();
	}
};
void printvrijeme(multimap <__int64, string> vremenaspremnik) {


	for (auto& i : vremenaspremnik)
	{
		cout << i.second << " " << i.first << "ms " << endl;

	}




}

template <class T>
T Convert(string temp) {
	T result;
	stringstream conv(temp);
	if (temp == "") return 0;
	conv >> result;

	return (result);
}

int main()
{
	ofstream dat22("brojaczamergesort.txt");//brisem datoteku zbog appenda
	dat22.close();

	ifstream datoteka("SPA_PROJ_010_WORLD_CUP_data_1.csv");


	if (!datoteka)
	{
		cout << "Pogreska kod otvaranja datoteke." << endl;
		return 1;
	}

	vector<Match> utakmice;
	string line;
	getline(datoteka, line);

	while (getline(datoteka, line))
	{
		if (line == ",,,,,,,,,,,,,,,,,,,")break;
		Match m;
		stringstream ss(line);

		string temp;

		getline(ss, temp, ';');
		m.set_year(Convert<int>(temp));

		getline(ss, temp, ';');


		stringstream date(temp);
		tm tm = {};
		date >> get_time(&tm, "%d %b %Y - %R ");
		m.set_date(tm);

		getline(ss, temp, ';');
		m.set_stage(temp);

		getline(ss, temp, ';');
		m.set_stadium(temp);

		getline(ss, temp, ';');

		m.set_city(temp);

		getline(ss, temp, ';');
		m.set_hometeamname(temp);

		getline(ss, temp, ';');
		m.set_hometeamgoals(Convert<int>(temp));

		getline(ss, temp, ';');
		m.set_awayteamgoals(Convert<int>(temp));

		getline(ss, temp, ';');
		m.set_awayteamname(temp);

		getline(ss, temp, ';');

		getline(ss, temp, ';');
		m.set_attendance(Convert<int>(temp));
		getline(ss, temp, ';'); getline(ss, temp, ';'); getline(ss, temp, ';'); getline(ss, temp, ';'); getline(ss, temp, ';'); getline(ss, temp, ';'); getline(ss, temp, ';');
		getline(ss, temp, ';');
		m.set_homeINITIALS(temp);
		getline(ss, temp, ';');
		m.set_awayINITIALS(temp);


		utakmice.push_back(m);
	}
	datoteka.close();
	
	while(true){
		cout << endl;
	cout << "IZBORNIK- za izlazak iz programa unesite negativan broj." << endl;

	cout << "1 Pretraga po reprezentaciji" << endl;
	cout << "2 Prikaz po godini" << endl;
	cout << "3 Kopiranje u novu listu" << endl;
	cout << "4 Prikaz po godini i domacinu" << endl;
	cout << "5 Selection vs Insertion" << endl;
	cout << "6 Pogodi trajanje" << endl;
	cout << "7 Lets Bogo!" << endl;
	cout << "8 The Merge Dance" << endl;
	cout << "9 Pretraga po troslovnoj oznaci" << endl;
	cout << "10 Vizualiziraj" << endl;
	cout << "11 Izrada string iz stringa" << endl;

	cout << "Vas izbor: ";

	

	multiset<Match, HashFunkcijaZaSet2> utakmiceUsetu(utakmice.begin(), utakmice.end());
	auto result = utakmiceUsetu.begin();
	auto adresica = utakmice.begin();
	int a;
	string b;
	cin >> a;
	if (a < 0)break;
	cin.ignore();

	multimap <__int64, string> vremenaspremnika;
	multimap <__int64, string> vremenaspremnikazacase9;
	chrono::time_point<chrono::high_resolution_clock> begin;
	chrono::time_point<chrono::high_resolution_clock> end;
	list<Match> utakmiceulisti(utakmice.begin(), utakmice.end());
	auto adresaliste = utakmiceulisti.begin();
	__int64 vrijeme;




	system("cls");


	priority_queue<Match, vector<Match>, pogodinama> pq(utakmice.begin(), utakmice.end());
	priority_queue<Match, vector<Match>, pogodinama> pq2(utakmice.begin(), utakmice.end());
	list<Match> novalista;
	multimap<int, Match> brojgolovamapa;

	int provjera;

	pair<map<int, Match>::iterator, map<int, Match>::iterator> found;




	vector<Match> v1(utakmice.begin(), utakmice.end());
	vector<Match> v2(utakmice.begin(), utakmice.end());
	vector<Match> vektorzarandomelemente(utakmice.begin(), utakmice.end());

	Match* matchevi = new Match[utakmice.size()];

	int broj_zamjena_u_sortu;
	int slucajnibroj, korisnikovbroj;
	int* poljebrojeva;
	Match* utakmiecZaMerge;
	vector<Match> noviVektor;



	int m;

	unordered_multiset<Match, HashFunkcijaZaSet, pogodinama> unorderedSET(utakmice.begin(), utakmice.end());
	auto resultSETUNORDER = unorderedSET.begin();

	unordered_multimap<string, Match> multimapica;
	unsigned n;


	unordered_map<string, string> mapazaimena;

	switch (a)
	{



	case 1:
		cout << "Unesite troslovnu oznaku reprezentaciju za reprezentaciju za koju zelite vidjeti sve utakmice: ";

		cin >> b;
		begin = chrono::high_resolution_clock::now();

		while (true) {



			result = find_if(result, utakmiceUsetu.end(),
				find_team(b));
			if (result == utakmiceUsetu.end())break;
			(*result).ispis();
			result++;

		}

		end = chrono::high_resolution_clock::now();
		chrono::duration_cast<chrono::milliseconds>(end - begin).count();
		vremenaspremnika.emplace(chrono::duration_cast<chrono::milliseconds>(end - begin).count(), "Multiset");

		//VEKTOR
		begin = chrono::high_resolution_clock::now();




		while (true) {



			adresica =find_if(adresica, utakmice.end(),
				find_team(b));
			if (adresica == utakmice.end())break;
			(*adresica).ispis();
			adresica++;

		}




		end = chrono::high_resolution_clock::now();
	
		vremenaspremnika.emplace(chrono::duration_cast<chrono::milliseconds>(end - begin).count(), "Vektor");

		//lista
		begin = chrono::high_resolution_clock::now();




		while (true) {

			adresaliste =find_if(adresaliste, utakmiceulisti.end(),
				find_team(b));
			if (adresaliste == utakmiceulisti.end())break;
			(*adresaliste).ispis();
			adresaliste++;

		}




		end = chrono::high_resolution_clock::now();

		vremenaspremnika.emplace(chrono::duration_cast<chrono::milliseconds>(end - begin).count(), "Lista");
		printvrijeme(vremenaspremnika);


		break;
	case 2:
		while (!pq.empty())
		{
			pq.top().ispis();
			pq.pop();
		}

		break;
	case 3:

		while (true) {
			cout << "Za prestanak unosa unesite negativan broj." << endl;
			cout << "Unesite broj golova: ";
			cin >> provjera;
			if (provjera < 0)break;
			vectorUmapu(utakmice, brojgolovamapa);
			found = brojgolovamapa.equal_range(provjera);

			if (found.first != found.second)
			{
				//pronasao
				for (auto it = found.first; it != found.second; ++it)
				{
					novalista.emplace_back(it->second);
				}

			}






		}
		cout << "Ispis svih utakmica: " << endl;

		for_each(novalista.begin(), novalista.end(), print);
		break;


	case 4:
		while (!pq2.empty())
		{
			pq2.top().ispis();
			pq2.pop();
		}


		break;
	case 5:
		begin = chrono::high_resolution_clock::now();

		load(v1, matchevi, utakmice.size());
		broj_zamjena_u_sortu = selection_sort(matchevi, v1.size());

		end = chrono::high_resolution_clock::now();
		for (int i = 0; i < v1.size(); i++)
		{

			v1[i] = matchevi[i];

		}


		cout << "Selection sortu je trebalo " << chrono::duration_cast<chrono::milliseconds>(end - begin).count() << " ms uz " << broj_zamjena_u_sortu << " zamjena." << endl;


		begin = chrono::high_resolution_clock::now();

		load(v2, matchevi, utakmice.size());
		broj_zamjena_u_sortu = insertion_sort(matchevi, v2.size());
		end = chrono::high_resolution_clock::now();

		for (int i = 0; i < v2.size(); i++)
		{

			v2[i] = matchevi[i];

		}
		delete[] matchevi;

		cout << "Insertion sortu je trebalo " << chrono::duration_cast<chrono::milliseconds>(end - begin).count() << "ms uz " << broj_zamjena_u_sortu << " zamjena." << endl;




		break;

	case 6:

		srand(time(nullptr));
		slucajnibroj = get_rnd(1, 100000000);
		cout << "Unesite kolko milisekundi mislite mislite da ce trajati razbacivanje, sortiranje i binarno pretrazivanje polja u potrazi za brojem 7: ";
		cin >> korisnikovbroj;

		poljebrojeva = new  int[slucajnibroj];

		napunipolje(poljebrojeva, slucajnibroj);
		begin = chrono::high_resolution_clock::now();

		random_shuffle(poljebrojeva, poljebrojeva + slucajnibroj);
		make_heap(poljebrojeva, poljebrojeva + slucajnibroj, minheapbro());

		binary_search(poljebrojeva, poljebrojeva + slucajnibroj, 7);



		end = chrono::high_resolution_clock::now();
		cout << "Razlika izmedu vase predikcije i konkretnog trajanja iznosi " << abs(chrono::duration_cast<chrono::milliseconds>(end - begin).count() - korisnikovbroj) << " ms" << endl;

		delete[] poljebrojeva;


		break;

	case 7:



		for (int i = 0; i < 5; i++)
		{
			m = get_rnd(0, utakmice.size() - 1);

			noviVektor.push_back(utakmice[m]);


		}

		while (!is_sorted_ascending(noviVektor))
		{
			next_permutation(noviVektor.begin(), noviVektor.end(), pogodinama());
			cout << "NOVA PERMUTACIJA" << endl;
			for (int i = 0; i < noviVektor.size(); i++)
			{
				noviVektor[i].ispis();

			}
		}


		break;
	case 8:


		srand(time(nullptr));
		cout << "Unesite broj koji predstavlja broj elemenata: ";
		cin >> m;
		random_shuffle(vektorzarandomelemente.begin(), vektorzarandomelemente.end());
		vektorzarandomelemente.erase(vektorzarandomelemente.begin() + m, vektorzarandomelemente.end());



		for (int i = 0; i < vektorzarandomelemente.size(); i++)
		{
			vektorzarandomelemente[i].ispis();

		}

		utakmiecZaMerge = new  Match[vektorzarandomelemente.size()];


		load(vektorzarandomelemente, utakmiecZaMerge, m);



		merge_sort(utakmiecZaMerge, m);
		cout << "Sortirani vektor: " << endl;


		for (int i = 0; i < m; i++)
		{

			vektorzarandomelemente[i] = utakmiecZaMerge[i];
			vektorzarandomelemente[i].ispis();
		}
		



		delete[] utakmiecZaMerge;

		break;
	case 9:


		cout << "Unesite troslovnu oznaku reprezentacije: ";
		cin >> b;
		begin = chrono::high_resolution_clock::now();
		while (true) {



			resultSETUNORDER = find_if(resultSETUNORDER, unorderedSET.end(),
				find_team(b));
			if (resultSETUNORDER == unorderedSET.end())break;
			(*resultSETUNORDER).ispis();
			resultSETUNORDER++;

		}

		end = chrono::high_resolution_clock::now();
		vremenaspremnikazacase9.emplace(chrono::duration_cast<chrono::milliseconds>(end - begin).count(), "Unordered Multiset");

		begin = chrono::high_resolution_clock::now();




		while (true) {



			adresica =find_if(adresica, utakmice.end(),
				find_team(b));
			if (adresica == utakmice.end())break;
			(*adresica).ispis();
			adresica++;

		}




		end = chrono::high_resolution_clock::now();
	
		vremenaspremnikazacase9.emplace(chrono::duration_cast<chrono::milliseconds>(end - begin).count(), "Vektor");

		//lista
		begin = chrono::high_resolution_clock::now();




		while (true) {

			adresaliste =find_if(adresaliste, utakmiceulisti.end(),
				find_team(b));
			if (adresaliste == utakmiceulisti.end())break;
			(*adresaliste).ispis();
			adresaliste++;

		}




		end = chrono::high_resolution_clock::now();

		vremenaspremnikazacase9.emplace(chrono::duration_cast<chrono::milliseconds>(end - begin).count(), "Lista");





		printvrijeme(vremenaspremnikazacase9);


		break;
	case 10:

		loadvectorUmultimapunordered(utakmice, multimapica);

		n = multimapica.bucket_count();

	
		for (unsigned i = 0; i < n; i++) {
			cout << "Bucket " << i << ": ";
			if (!multimapica.bucket_size(i)) { cout << "[EMPTY]" << endl; continue; }
			for (auto it = multimapica.begin(i); it != multimapica.end(i); it++)
			{
				cout << it->first << " ( " << it->second.get_homeINITIALS() << " vs " << it->second.get_awayINITIALS() << ")";
				if (it != --multimapica.end(i)) cout << "--";
			}

			cout << endl;
		}


		break;


	case 11:
		for (int i = 0; i < utakmice.size(); i++)
		{
			cout << i + 1 << "- ";
			utakmice[i].ispis();

		}
		cout << "Odaberite utakmicu unosom rednog broja(1-852): ";
		cin >> n;
		cout << endl;
		cout << "Odabrali ste utakmicu: " << endl;
		utakmice[n - 1].ispis();
		cout << "Stadium: " << utakmice[n - 1].get_stadium() << endl;
		cout << "Kratica gostujuce ekipe: " << utakmice[n - 1].get_awayINITIALS() << endl;
		mapazaimena.emplace(utakmice[n - 1].get_awayINITIALS(), utakmice[n - 1].get_stadium());


		for (auto& i : mapazaimena)
		{
			if (mozeliseiz(i.first, i.second)) cout << "Iz imena stadium MOZE se dobiti kratica gostujuce momcadi." << endl;
			else cout << "Iz imena stadium NE MOZE se dobiti kratica gostujuce momcadi." << endl;
		}





		break;

	default:
		cout << "Krivi odabir." << endl;
		break;
	}
}

	

	

    return 0;
}
