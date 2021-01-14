#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;



class Cinema
{
	char* nume;
	char* adresa;
	int recenzii;

public:

	Cinema()
	{
		this->nume = new char[3];
		strcpy(this->nume, "NP");
		this->adresa = new char[25];
		strcpy(this->adresa, "Adr");
		this->recenzii = 0;
	}

	Cinema(const char* name, const char* adress, int reviews)
	{
		if (strlen(name) > 2)
		{
			nume = new char[strlen(name) + 1];
			strcpy(nume, name);
		}
		else
		{
			this->nume = new char[3];
			strcpy(this->nume, "NP");
		}

		if (strlen(adress) > 3)
		{
			this->adresa = new char[strlen(adress) + 1];
			strcpy(adresa, adress);
		}
		else
		{
			this->adresa = new char[3];
			strcpy(adresa, "Ad");
		}


		if (reviews > 0)
		{
			this->recenzii = reviews;
		}
		else
		{
			this->recenzii = 0;
		}
	}

	Cinema(const Cinema& sursa)
	{
		this->nume = new char[strlen(sursa.nume) + 1];
		strcpy(this->nume, sursa.nume);

		this->adresa = new char[strlen(sursa.adresa) + 1];
		strcpy(this->adresa, sursa.adresa);

		this->recenzii = sursa.recenzii;
	}


	Cinema& operator=(const Cinema& sursa)
	{
		if (this->nume)
		{
			delete[] this->nume;
		}

		if (this->adresa)
		{
			delete[] this->adresa;
		}



		this->nume = new char[strlen(sursa.nume) + 1];
		strcpy(this->nume, sursa.nume);

		this->adresa = new char[strlen(sursa.adresa) + 1];
		strcpy(this->adresa, sursa.adresa);

		this->recenzii = sursa.recenzii;

		return *this;
	}

	~Cinema()
	{
		if (this->nume)
		{
			delete[] this->nume;
		}


		if (this->adresa)
		{
			delete[] this->adresa;
		}
	}


	char* getNume()
	{
		return this->nume;
	}

	char* getAdresa()
	{
		return this->adresa;
	}

	int getRecenzii()
	{
		return this->recenzii;
	}

	void setNume(const char* name)
	{
		if (strlen(name) > 2)
		{
			if (nume)
			{
				delete[] nume;
			}
		}
		nume = new char[strlen(name) + 1];
		strcpy(nume, name);
	}

	void setAdresa(const char* adress)
	{
		if (strlen(adress) > 2)
		{
			if (adresa)
			{
				delete[] adresa;
			}
		}
		adresa = new char[strlen(adress) + 1];
		strcpy(adresa, adress);
	}

	void setRecenzii(const int reviews)
	{
		if (reviews >= 0)
		{
			this->recenzii = reviews;
		}
	}

	friend  ostream& operator<< (ostream& o, Cinema c)
	{
		o << "Numele cinematografului: " << c.nume << endl;
		o << "Adresa cinematografului:" << c.adresa << endl;
		o << "Recenzii: " << c.recenzii << endl;
		o << endl;
		return o;
	}

	friend  istream& operator>> (istream& in, Cinema& c)
	{

		cout << "Numele cinematografului: ";
		delete[] c.nume;
		in >> ws;
		char buffer[50];
		in.getline(buffer, 49);
		c.nume = new char[strlen(buffer) + 1];
		strcpy_s(c.nume, strlen(buffer) + 1, buffer);

		cout << "Adresa cinematografului: ";
		delete[] c.adresa;
		in >> ws;
		char buf[100];
		in.getline(buf, 99);
		c.adresa = new char[strlen(buf) + 1];
		strcpy_s(c.adresa, strlen(buf) + 1, buf);

		cout << "Introduceti numarul de recenzii:";
		int aux;
		in >> aux;
		if (aux >= 0) {
			c.recenzii = aux;
		}

		return in;
	}

	Cinema operator+ (int x)
	{
		Cinema  copie(*this);
		copie.recenzii += x;

		return copie;
	}

	Cinema& operator++() 
	{
		this->recenzii += 100;

		return *this;
	}

	Cinema  operator++ (int)
	{
		Cinema cin(*this);  
		this->recenzii += 100;

		return cin;
	}

	explicit operator int()
	{
		return this->recenzii;
	}

	bool operator ! ()
	{
		if (this->recenzii > 0)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
	
	bool operator > (Cinema kino) 
	{
		if (this->recenzii > kino.recenzii) 
		{
			return true;
		}
		else 
		{
			return false;
		}
	}

	bool operator ==(Cinema kino)
	{
		if (this->recenzii == kino.recenzii)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};


class Sala
{
	int nr_sali_totale;
	int* id_sala;
	int nr_locuri;
	int* id_loc;

public:

	Sala()
	{
		this->nr_sali_totale = 0;
		this->id_sala = nullptr;
		this->nr_locuri = 0;
		this->id_loc = nullptr;
	}

	Sala(int nrRooms, int* idRoom, int nrSeats, int* seatId)
	{
		if (nrRooms > 0)
		{
			this->nr_sali_totale = nrRooms;
			this->id_sala = new int[nrRooms];
			for (int i = 0; i < nrRooms; i++)
			{
				if (idRoom[i] >= 0)
				{
					this->id_sala[i] = idRoom[i];
				}
				else
				{
					this->id_sala[i] = 0;
				}
			}
		}
		else
		{
			this->nr_sali_totale = 0;
			this->id_sala = NULL;
		}


		if (nrSeats > 0)
		{
			this->nr_locuri = nrSeats;
			this->id_loc = new int[nrSeats];
			for (int i = 0; i < nrSeats; i++)
			{
				if (seatId[i] >= 0)
				{
					this->id_loc[i] = seatId[i];
				}
				else
				{
					this->id_loc[i] = 0;
				}
			}
		}
		else
		{
			this->nr_locuri = 0;
			this->id_loc = NULL;
		}
	}

	Sala(const Sala& sursa)
	{
		this->nr_sali_totale = sursa.nr_sali_totale;
		this->id_sala = new int[nr_sali_totale];
		for (int i = 0; i < sursa.nr_sali_totale; i++)
		{

			this->id_sala[i] = sursa.id_sala[i];

		}

		this->nr_locuri = sursa.nr_locuri;
		this->id_loc = new int[nr_locuri];
		for (int i = 0; i < sursa.nr_locuri; i++)
		{

			this->id_loc[i] = sursa.id_loc[i];

		}


	}

	Sala& operator=(const Sala& sursa)
	{

		if (this->id_sala)
		{
			delete[] this->id_sala;
		}

		if (this->id_loc)
		{
			delete[] this->id_loc;
		}


		this->nr_locuri = sursa.nr_locuri;
		this->id_loc = new int[sursa.nr_locuri];
		for (int i = 0; i < sursa.nr_locuri; i++) 
		{
			this->id_loc[i] = sursa.id_loc[i];
		}

		return *this;
	}

	~Sala()
	{
		if (this->id_sala)
		{
			delete[] this->id_sala;
		}

		if (this->id_loc)
		{
			delete[] this->id_loc;
		}
	}

	int getNr_sali_totale()
	{
		return this->nr_sali_totale;
	}

	int* getId_sala()
	{
		return this->id_sala;
	}

	int getNr_locuri()
	{
		return this->nr_locuri;
	}

	int* getId_loc()
	{
		return this->id_loc;
	}

	void setId_sala(int nrRooms, int* idRooms)
	{
		if (nrRooms > 0 && idRooms != nullptr)
		{
			if (this->id_sala)
			{
				delete[]this->id_sala;
			}

			this->nr_sali_totale = nrRooms;
			this->id_sala = new int[nrRooms];
			for (int i = 0; i < nrRooms; i++)
			{
				this->id_sala[i] = idRooms[i];
			}

		}
	}

	void setId_loc(int nrSeats, int* seatId)
	{
		if (nrSeats > 0 && seatId != nullptr)
		{
			if (this->id_loc)
			{
				delete[]this->id_loc;
			}

			this->nr_locuri = nrSeats;
			this->id_loc = new int[nrSeats];
			for (int i = 0; i < nrSeats; i++)
			{
				this->id_loc[i] = seatId[i];
			}

		}

	}


	friend  ostream& operator<< (ostream& o, Sala s)
	{
		o << "Salile cinamatografului in nr de " << s.nr_sali_totale << " sunt: ";
		for (int i = 0; i < s.nr_sali_totale; i++)
		{
			o << s.id_sala[i] << "  ";
		}
		o << endl;

		o << "Numerele scaunelor intr-o sala de " << s.nr_locuri << " locuri sunt: ";
		for (int i = 0; i < s.nr_locuri; i++)
		{
			o << s.id_loc[i] << "  ";
		}

		o << endl;

		return o;
	}


	friend  istream& operator>> (istream& in, Sala& s)
	{
		cout << "Introduceti numarul de sali totale";
		int nrSaliAux;
		in >> nrSaliAux;
		if (nrSaliAux > 0)
		{
			if (s.id_sala)
			{
				delete[] s.id_sala;
			}
			s.nr_sali_totale = nrSaliAux;
			s.id_sala = new int[nrSaliAux];
			for (int i = 0; i < nrSaliAux; i++)
			{
				cout << "Introduceti id-ul salii " << i + 1 << ": ";
				in >> s.id_sala[i];
			}
		}

		cout << "Introduceti numarul de locuri:";
		int nrLocAux;
		in >> nrLocAux;
		if (nrLocAux > 0)
		{
			if (s.id_loc)
			{
				delete[] s.id_loc;
			}
			s.nr_locuri = nrLocAux;
			s.id_loc = new int[nrLocAux];
			for (int i = 0; i < nrLocAux; i++)
			{
				cout << "Introduceti id-ul locului " << i + 1 << ": ";
				in >> s.id_loc[i];
			}
		}

		return in;
	}

	int& operator []  (int i)
	{
		if (i >= 0 && i < nr_sali_totale)
		{
			return id_sala[i];
		}
		else
		{
			throw new exception("Index gresit"); 	
		}
	}

	Sala operator+ (int x)
	{
		Sala  copie(*this);
		copie.nr_locuri += x;

		return copie;

	}

	Sala& operator++() {

		this->nr_sali_totale += 2;

		return *this;
	}

	Sala  operator++ (int)
	{
		Sala room(*this);  
		this->nr_sali_totale += 2;

		return room;

	}

	explicit operator int()
	{
		return this->nr_locuri;
	}

	bool operator ! ()
	{
		if (this->nr_locuri > 0)
		{
			return false;
		}
		else
		{
			return true;
		}
	}

	bool operator > (Sala room) 
	{
		if (this->nr_locuri > room.nr_locuri)
		{
			return true;
		}
		else 
		{
			return false;
		}
	}

	bool operator ==(Sala room)
	{
		if (this->nr_locuri == room.nr_locuri)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};


class Film
{
	char* nume;
	int Zile;
	int* rulareZi;

public:

	Film()
	{
		this->nume = new char[3];
		strcpy(this->nume, "NP");
		this->Zile = 0;
		this->rulareZi = nullptr;
	}

	Film(const char* name, int days, int* Dayruns)
	{
		if (strlen(name) > 3)
		{
			nume = new char[strlen(name) + 1];
			strcpy(nume, name);
		}
		else
		{
			this->nume = new char[3];
			strcpy(this->nume, "NP");
		}


		if (days > 0)
		{
			this->Zile = days;
			this->rulareZi = new int[days];
			for (int i = 0; i < days; i++)
			{
				if (Dayruns[i] >= 0)
				{
					this->rulareZi[i] = Dayruns[i];
				}
				else
				{
					this->rulareZi[i] = 0;
				}
			}
		}

		else
		{
			this->Zile = 0;
			this->rulareZi = nullptr;
		}
	}

	Film(const Film& sursa)
	{
		this->nume = new char[strlen(sursa.nume) + 1];
		strcpy(this->nume, sursa.nume);

		this->Zile = sursa.Zile;
		this->rulareZi = new int[Zile];
		for (int i = 0; i < sursa.Zile; i++)
		{
			this->rulareZi[i] = sursa.rulareZi[i];
		}

	}

	Film& operator=(const Film& sursa)
	{
		if (this->nume)
		{
			delete[] this->nume;
		}

		if (this->rulareZi)
		{
			delete[] this->rulareZi;
		}

		this->nume = new char[strlen(sursa.nume) + 1];
		strcpy(this->nume, sursa.nume);

		this->Zile = sursa.Zile;
		this->rulareZi = new int[sursa.Zile];
		for (int i = 0; i < sursa.Zile; i++)
		{
			this->rulareZi[i] = sursa.rulareZi[i];
		}

		return *this;
	}

	~Film()
	{
		if (this->nume) {
			delete[] this->nume;
		}

		if (this->rulareZi)
		{
			delete[] this->rulareZi;
		}
	}


	char* getNume()
	{
		return this->nume;
	}

	int getZile()
	{
		return this->Zile;
	}

	int* getRulareZi()
	{
		return this->rulareZi;
	}

	void setRulareZi(int days, int* dayruns)
	{
		if (days > 0 && dayruns != nullptr)
		{
			if (this->rulareZi)
			{
				delete[]this->rulareZi;
			}

			this->Zile = days;
			this->rulareZi = new int[days];
			for (int i = 0; i < days; i++)
			{
				this->rulareZi[i] = dayruns[i];
			}

		}
	}

	void setNume(const char* name) 
	{
		if (strlen(name) > 3) 
		{
			if (this->nume)
			{
				delete[] this->nume;
			}

			this->nume = new char[strlen(name) + 1];
			strcpy(this->nume, name);
		}


	}

	friend  ostream& operator<< (ostream& o, Film f)
	{
		o << "Nume " << f.nume << endl;
		o << "Filmul ruleaza in  " << f.Zile << " Zile: ";
		for (int i = 0; i < f.Zile; i++)
		{
			o << f.rulareZi[i] << "  ";
		}

		o << endl;

		return o;
	}

	friend  istream& operator>> (istream& in, Film& f)
	{
		cout << "Introduceti numele: ";
		char buffer[500];
		in >> buffer;
		f.setNume(buffer);

		cout << "Introduceti numarul de zile in care ruleaza filmul:";
		int ZileAux;
		in >> ZileAux;
		if (ZileAux > 0)
		{
			if (f.rulareZi)
			{
				delete[] f.rulareZi;
			}
			f.Zile = ZileAux;
			f.rulareZi = new int[ZileAux];
			for (int i = 0; i < ZileAux; i++)
			{
				cout << "Introduceti de cate ori ruleaza filmul in ziua " << i + 1 << ": ";
				in >> f.rulareZi[i];
			}
		}

		return in;
	}

	int& operator []  (int i)
	{
		if (i >= 0 && i < Zile)
		{
			return rulareZi[i];
		}
		else
		{
			throw new exception("Index gresit");
		}
	}

	Film operator+ (int x)
	{
		Film copie(*this);
		if (x >= 0 && x < 20)
		{
			copie.Zile += x;
		}
		return copie;

	}


	Film& operator++() 
	{
		this->Zile += 5;
		return *this;
	}


	Film  operator++ (int) 
	{
		Film movie(*this);  
		this->Zile += 5;
		return movie;
	}

	explicit operator int()
	{
		return this->Zile;
	}

	bool operator ! ()
	{
		if (this->Zile > 0)
		{
			return false;
		}
		else
		{
			return true;
		}
	}


	bool operator > (Film movie)
	{
		if (this->Zile > movie.Zile)
		{
			return true;
		}
		else
		{
			return false;
		}
	}


	bool operator ==(Film movie)
	{
		if (this->Zile == movie.Zile)
		{
			return true;
		}
		else
		{
			return false;
		}
	}



};


class Bilet
{
	char* serie_bilet;
	float pret;

	static int nrBilete;// static ce contorizeaza numarul de bilete vandute
	const int id; // constanta generata pe baza campului static de mai sus


public:


	Bilet() : id(nrBilete++)
	{
		this->serie_bilet = new char[3];
		strcpy(this->serie_bilet, "AA");

		this->pret = 0;
	}

	Bilet(char* series, float price) : id(nrBilete++)
	{
		if (strlen(series) > 3)
		{
			serie_bilet = new char[strlen(series) + 1];
			strcpy(serie_bilet, series);
		}
		else
		{
			this->serie_bilet = new char[3];
			strcpy(this->serie_bilet, "AA");
		}

		if (price > 0) 
		{
			this->pret = price;
		}
		else
		{
			this->pret = 0;
		}

	}

	Bilet(const Bilet& sursa) :id(sursa.id)
	{
		nrBilete++;

		this->serie_bilet = new char[strlen(sursa.serie_bilet) + 1];
		strcpy(this->serie_bilet, sursa.serie_bilet);
		this->pret = sursa.pret;
	}

	Bilet& operator=(const Bilet& sursa)
	{
		if (this->serie_bilet)
		{
			delete[] this->serie_bilet;
		}

		this->serie_bilet = new char[strlen(sursa.serie_bilet) + 1];
		strcpy(this->serie_bilet, sursa.serie_bilet);

		this->pret = sursa.pret;

		return *this;
	}

	~Bilet()
	{
		if (this->serie_bilet)
		{
			delete[] this->serie_bilet;
		}
	}

	char* getSerie_Bilet()
	{
		return this->serie_bilet;
	}

	int getPret()
	{
		return this->pret;
	}

	void setSerie_bilet(const char* series)
	{
		if (strlen(series) > 3)
		{
			if (this->serie_bilet)
			{
				delete[] this->serie_bilet;
			}

			this->serie_bilet = new char[strlen(series) + 1];
			strcpy(this->serie_bilet, series);
		}
	}

	void setPret(int new_price)
	{
		if (new_price >= 20 && new_price <= 150)
		{
			this->pret = new_price;
		}
	}

	friend  ostream& operator<< (ostream& o, Bilet b)
	{
		o << "Seria biletului: " << b.serie_bilet << endl;
		o << "Pretul biletului este:  " << b.pret << " Zile: ";

		o << endl;

		return o;
	}


	friend  istream& operator>> (istream& in, Bilet& b)
	{
		cout << "Introduceti seria billetului: ";
		char buffer[500];
		in >> buffer;
		b.setSerie_bilet(buffer);

		cout << "Introduceti pretul biletului:";
		int PretAux;
		in >> PretAux;
		if (PretAux > 20 && PretAux < 150)
		{
			b.pret = PretAux;
		}

		return in;
	}

	char& operator []  (int i)
	{
		if (i >= 0 && i < strlen(serie_bilet))
		{
			return serie_bilet[i];
		}
		else
		{
			throw new exception("Index gresit");
		}
	}

	Bilet operator+ (float x)
	{
		Bilet copie(*this);
		if (x >= 0 && x <= 150)
		{
			copie.pret += x;
		}
		return copie;

	}

	Bilet& operator++() 
	{
		this->pret += 1.00;
		return *this;
	}

	Bilet  operator++ (int)
	{
		Bilet ticket(*this);  
		this->pret += 1.00;

		return ticket;
	}

	explicit operator int()
	{
		return this->pret;
	}

	bool operator ! ()
	{
		if (this->pret > 0)
		{
			return false;
		}
		else
		{
			return true;
		}
	}


	bool operator > (Bilet ticket)
	{
		if (this->pret > ticket.pret)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool operator ==(Bilet ticket)
	{
		if (this->pret == ticket.pret)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};
	
int Bilet::nrBilete = 0;

class Personal
{
	char* nume;
	int nr_legitimatie;

public:

	Personal()
	{
		this->nume = new char[3];
		strcpy(this->nume, "NA");
		this->nr_legitimatie = 0;
	}


	Personal(const char* name, int nr_id)
	{
		if (strlen(name) > 3)
		{
			nume = new char[strlen(name) + 1];
			strcpy(nume, name);
		}
		else
		{
			this->nume = new char[3];
			strcpy(this->nume, "AA");
		}

		if (nr_id > 10000)
		{
			this->nr_legitimatie = nr_id;
		}
		else 
		{
			this->nr_legitimatie = 10000;
		}

	}

	Personal(const Personal& sursa)
	{
		this->nume = new char[strlen(sursa.nume) + 1];
		strcpy(this->nume, sursa.nume);

		this->nr_legitimatie = sursa.nr_legitimatie;
	}

	Personal& operator=(const Personal& sursa)
	{
		if (this->nume)
		{
			delete[] this->nume;
		}

		this->nume = new char[strlen(sursa.nume) + 1];
		strcpy(this->nume, sursa.nume);

		this->nr_legitimatie = sursa.nr_legitimatie;

		return *this;
	}

	

	~Personal()
	{
		if (this->nume)
		{
			delete[] this->nume;
		}
	}

	char* getNume()
	{
		return this->nume;
	}

	int getNrLegitimatie()
	{
		return this->nr_legitimatie;
	}

	void setNume(const char* name)
	{
		if (strlen(name) > 2)
		{
			if (nume)
			{
				delete[] nume;
			}
		}
		nume = new char[strlen(name) + 1];
		strcpy(nume, name);
	}


	void setNrLegitimatie(int nr_id)
	{
		if (nr_id >= 10000 && nr_id <= 15000)
		{
			this->nr_legitimatie = nr_id;
		}
	}

	friend  ostream& operator<< (ostream& o, Personal p)
	{
		o << "Numele angajatului: " << p.nume << endl;
		o << "Numarul legitimatiei:  " << p.nr_legitimatie << endl;

		return o;
	}

	friend  istream& operator>> (istream& in, Personal& p)
	{
		cout << "Introduceti numele: ";
		char buffer[500];
		in >> buffer;
		p.setNume(buffer);

		cout << "Introduceti numarul legitimatiei:";
		int IdAux;
		in >> IdAux;
		if (IdAux >= 10000 && IdAux <= 15000)
		{
			p.nr_legitimatie = IdAux;
		}

		return in;
	}

	char& operator []  (int i)
	{
		if (i >= 0 && i < sizeof(nume))
		{
			return nume[i] = char(toupper(nume[i]));
		}
		else
		{
			throw new exception("Index gresit");
		}
	}

	Personal operator+ (int x)
	{
		Personal copie(*this);
		if (x >= 0 && x <= 10)
		{
			if (nr_legitimatie < 14990)
			{
				copie.nr_legitimatie += x;
			}
		}
		return copie;

	}


	Personal& operator--()
	{
		this->nr_legitimatie-= 10;
		return *this;
	}

	Personal operator-- (int)
	{
		Personal pers(*this);
		this->nr_legitimatie-= 10;

		return pers;
	}

	explicit operator int()
	{
		return this->nr_legitimatie;
	}

	bool operator ! ()
	{
		if (this->nr_legitimatie > 0)
		{
			return false;
		}
		else
		{
			return true;
		}
	}

	bool operator < (Personal pers)
	{
		if (this->nr_legitimatie < pers.nr_legitimatie)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool operator ==(Personal pers)
	{
		if (this->nr_legitimatie == pers.nr_legitimatie)
		{
			return true;
		}
		else
		{
			return false;
		}
	}



};





void main()
{
	

}