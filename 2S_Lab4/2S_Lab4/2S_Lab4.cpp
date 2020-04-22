#include <iostream>
#include <string>
using namespace std;

class CComputer
{
private:
	string cpumodel, videomodel;
	double operation_per_seconds;//"operation per second"
	int hardsize, ramsize, optime, numprogram;

public:

	CComputer(string Vcpumodel, string Vvideomodel, double Voperation_per_seconds, int Vhardsize, int Vramsize, int Voptime, int Vnumprogram)   //Конструктор
	{
		cpumodel = Vcpumodel;
		videomodel = Vvideomodel;
		operation_per_seconds = Voperation_per_seconds;
		hardsize = Vhardsize;
		ramsize = Vramsize;
		optime = Voptime;
		numprogram = Vnumprogram;
	}

	//Setters
	void Set_cpumodel(string Scpumodel)
	{
		cpumodel = Scpumodel;
	}

	void Set_videomodel(string Svideomodel)
	{
		videomodel = Svideomodel;
	}

	void Set_operation_per_seconds(double Soperation_per_seconds)
	{
		operation_per_seconds = Soperation_per_seconds;
	}

	void Set_hardsize(int Shardsize)
	{
		hardsize = Shardsize;
	}

	void Set_ramsize(int Sramsize)
	{
		ramsize = Sramsize;
	}

	void Set_optime(int Soptime)
	{
		optime = Soptime;
	}

	
	//Getters
	string Get_cpumodel()
	{
		return cpumodel;
	}

	string Get_videomodel()
	{
		return videomodel;
	}

	double Get_operation_per_seconds()
	{
		return operation_per_seconds;
	}

	int Get_hardsize()
	{
		return hardsize;
	}

	int Get_ramsize()
	{
		return ramsize;
	}

	int Get_optime()
	{
		return optime;
	}

	int Get_numprogram()
	{
		return numprogram;
	}

	//Install and uninstall programm
	void install()
	{
		cout << endl << "Enter the name of the application which you want to install:";
		//cin>>

		numprogram++;
		cout << endl << "The program is installed." << endl << "Number installed program::" << numprogram << endl;		
	}

	void uninstall()
	{
		cout << endl << "Enter the name of the application which you want to uninstall:";
		//cin>>

		numprogram--;
		cout << endl << "The program is uninstalled." << endl << "Number installed program::" << numprogram << endl;
	}

	void timeneed()
	{
		int numop;
		cout << endl << "Enter the number of operations the program must perform::";
		cin >> numop;

		cout << endl << "Time for execution(in seconds):" << numop / operation_per_seconds << endl;
	}

	void Showdata()
	{
		cout << endl << "Cpu model:" << cpumodel;
		cout << endl << "Video model:" << videomodel;
		cout << endl << "Operation per seconds" <<operation_per_seconds;
		cout << endl << "Hard size" << hardsize;
		cout << endl << "Ram size" << ramsize;
		cout << endl << "Time of operation" << optime;
		cout << endl << "Number of program" << numprogram;
	}
};

int main()
{
	string fcpuname = "i7-8400", fvname = "GTX 1660";
	CComputer firstpc(fcpuname, fvname, 4000, 3000, 16, 1, 164);
	firstpc.Get_optime();
	firstpc.Set_operation_per_seconds(6000);
	firstpc.Showdata();
	firstpc.timeneed();
	firstpc.install();
	firstpc.Showdata();

	string scpuname = "i7-8400K", svname = "GTX 1060 Ti";
	CComputer secondpc(scpuname, svname, 3000, 2000, 12, 2, 104);
	secondpc.Get_cpumodel();
	secondpc.Get_numprogram();
	secondpc.Get_ramsize();
	secondpc.Showdata();
	secondpc.Set_hardsize(8000);
	secondpc.install();
	secondpc.Showdata();
	return 0;
}