// serrecpp.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include "VerifSeuil.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;


int main(int argc, char *argv[])
{
	int* horairerecup;
	VerifSeuil* Verif;
	Verif = new VerifSeuil;
	Verif->SetHumiSol(40);
	Verif->SetHygro(60);
	Verif->SetPlage(15,31);
	Verif->SetTempExt(28);
	Verif->SetTempInt(26);
	horairerecup = Verif->Get_PlageHoraire();
	

	cout << "la plage horaire est de " <<horairerecup[0] << " heure et " <<horairerecup[1]<<" minutes"<<endl;
	
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

