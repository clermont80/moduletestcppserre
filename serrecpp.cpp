// serrecpp.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include "VerifSeuil.h"
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
	VerifSeuil* Verif;
	Verif = new VerifSeuil;

	bool res = Verif->AllumeArrosage();

	if (res == true)
	{
		cout << "ok" << endl;
	}
	else
	{
		cout << "pas ok" << endl;
	}

	return 0;
}

