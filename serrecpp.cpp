// serrecpp.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include "VerifSeuil.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;


int main(int argc, char *argv[])
{
	int *horaire;
	VerifSeuil* Verif;
	Verif = new VerifSeuil;
	Verif->SetHumiSol(40);
	Verif->SetHygro(60);
	Verif->SetPlage(15,31);
	Verif->SetTempExt(28);
	Verif->SetTempInt(26);
	horaire = Verif->Get_PlageHoraire;

	for (int i = 0; i < 2; i++)
	{
		cout << horaire[i] << endl;
	}

	bool res = Verif->AllumeArrosage();

	if (res == true)
	{
		cout << "ok" << endl;
	}
	else
	{
		cout << "pas ok" << endl;
	}

	system("PAUSE");
	return 0;
	
}

