#include "VerifSeuil.h"
#include <ctime>
#include <iostream>

using namespace std;

float VerifSeuil::Get_TempInt()
{
	return this->SeuilTempInt;
}

float VerifSeuil::Get_TempExt()
{
	return this->SeuilTempExt;
}

int VerifSeuil::Get_Hygro()
{
	return this->SeuilHygro;
}

int VerifSeuil::Get_HumiSol()
{
	return this->SeuilHumiSol;
}

int VerifSeuil::Get_PlageHoraire()
{
	int horaire[2];
	
	horaire[0] = this->Plageheure; //indice 0 pour heure
	horaire[1] = this->Plageminute; //indice 1 pour minute


	return horaire[0];

}

bool VerifSeuil::AllumeVasistas()
{
	if (this->Hygro >= 85 && this->TempExt >= 10 || this->TempExt >= this->TempInt && this->TempInt <= 10 || this->TempInt >= 25)
	{
		cout << "ouverture du vasistas..." << endl;
		return true;
	}

		return false;
}

bool VerifSeuil::AllumeBrumi()
{
	if (this->TempInt >= 25 || this->Hygro <= 50 && this->TempInt >= 5)
	{
		cout << "lancement de la brumisation..." << endl;
		return true;
	}

		return false;
}

bool VerifSeuil::AllumeChauffage()
{
	if (this->TempInt <= 1)
	{
		cout << "lancement du chauffage..." << endl;
		return true;
	}
		
		return false;
}

bool VerifSeuil::AllumeArrosage()
{
	
	struct tm newtime;
	time_t dateheureactuelle = time(NULL);
	localtime_s(&newtime, &dateheureactuelle); //on recupere l'heure et la date actuelle
	int heure = newtime.tm_hour;
	int minute = newtime.tm_min;

	if (this->HumiSol < this->SeuilHumiSol && heure >= this->Plageheure  || heure <= this->Plageheure)
	{
		if (heure == this->Plageheure && minute < this->Plageminute)
		{
			return false;
		}

		if (heure == this->Plageheure && minute > this->Plageminute)
		{
			return false;
		}
		cout << "lancement de l'arrosage..." << endl;
		
		return true;
	}
		return false;
}

void VerifSeuil::SetHumiSol(int SeuilHumiSol)
{
	this->SeuilHumiSol = SeuilHumiSol;
}

void VerifSeuil::SetHygro(int SeuilHygro)
{
	this->SeuilHygro = SeuilHygro;
}

void VerifSeuil::SetPlage(int heure, int minute)
{
	this->Plageheure = heure;
	this->Plageminute = minute;
	
}

void VerifSeuil::SetTempExt(float SeuilTempExt)
{
	this->SeuilTempExt = SeuilTempExt;
}

void VerifSeuil::SetTempInt(float SeuilTempInt)
{
	this->SeuilTempInt = SeuilTempInt;
}