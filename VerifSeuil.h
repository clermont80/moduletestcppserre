#pragma once
class VerifSeuil
{
	private:
		
		
		float TempInt;
		float TempExt;
		int Hygro;
		int HumiSol = 49;
		float SeuilTempInt;
		float SeuilTempExt;
		int SeuilHygro;
		int SeuilHumiSol;
		int Plageheure;
		int Plageminute;
		int Plageseconde;

	public:
	
		float Get_TempInt();
		float Get_TempExt();
		int Get_Hygro();
		int Get_HumiSol();
		int Get_PlageHoraire();
		void SetHygro(int SeuilHygro);
		void SetTempInt(float SeuilTempInt);
		void SetTempExt(float SeuilTempExt);
		void SetHumiSol(int SeuilHumiSol);
		void SetPlage(int heure,int minute,int seconde);
		bool AllumeVasistas();
		bool AllumeBrumi();
		bool AllumeChauffage();
		bool AllumeArrosage();

};

