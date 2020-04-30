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

	//Operator's
	CComputer& operator= (const CComputer& other)
	{
		cout << endl << "Operator =" << endl;
		this->cpumodel = other.cpumodel;
		this->videomodel = other.videomodel;
		this->operation_per_seconds = other.operation_per_seconds;
		this->hardsize = other.hardsize;
		this->ramsize = other.ramsize;
		this->optime = other.optime;
		this->numprogram = other.numprogram;

		return *this;
	}

	CComputer& operator *(const int value)
	{
		cout << endl << "Operator *" << endl;
		this->hardsize = this->hardsize*value;
		return *this;
	}

	CComputer& operator ++ ()
	{
		cout << endl << "Operator ++" << endl;
		this->ramsize ++;
		this->operation_per_seconds++;
		return *this;
	}

	bool operator ==(const CComputer& other)
	{
		cout << endl << "Operator ==" << (this->cpumodel == other.cpumodel && this->videomodel == other.videomodel && this->operation_per_seconds == other.operation_per_seconds && this->hardsize == other.hardsize && this->ramsize == other.ramsize && this->optime == other.optime && this->numprogram == other.numprogram) << endl;
		return this->cpumodel == other.cpumodel && this->videomodel == other.videomodel && this->operation_per_seconds == other.operation_per_seconds && this->hardsize == other.hardsize && this->ramsize == other.ramsize && this->optime == other.optime && this->numprogram == other.numprogram;
	}

	bool operator ||(const CComputer& other)
	{
		cout << endl << "Operator < :: " << (this->optime == other.optime || this->numprogram == other.numprogram) << endl;
		return this->optime == other.optime || this->numprogram == other.numprogram;
	}



	//Constrictor's | Destructor's
	CComputer(string Ccpumodel, string Cvideomodel, double Coperation_per_seconds, int Chardsize, int Cramsize, int Coptime, int Cnumprogram)   //Конструктор
	{
		cpumodel = Ccpumodel;
		videomodel = Cvideomodel;
		operation_per_seconds = Coperation_per_seconds;
		hardsize = Chardsize;
		ramsize = Cramsize;
		optime = Coptime;
		numprogram = Cnumprogram;
	}

	CComputer(const CComputer& other)
	{
		this->cpumodel = other.cpumodel;
		this->videomodel = other.videomodel;
		this->operation_per_seconds = other.operation_per_seconds;
		this->hardsize = other.hardsize;
		this->ramsize = other.ramsize;
		this->optime = other.optime;
		this->numprogram = other.numprogram;
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
		cout << endl << "Operation per seconds" << operation_per_seconds;
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

	string scpuname = "i7-8400K", svname = "GTX 1060 Ti";
	CComputer secondpc(scpuname, svname, 3000, 2000, 12, 2, 104);

	cout << "Was:" << endl << "Hadrsize: " << firstpc.Get_hardsize() << endl;
	cout << endl << "****************";
	firstpc * 5;
	cout << endl << "****************" << endl;
	cout << endl << "Has become:" << endl << "Hadrsize: " << firstpc.Get_hardsize() << endl;
	cout << "================================================================"<< endl;
	
	cout << endl;
	cout << endl << "Was:" << endl << "Ramsize: " << firstpc.Get_ramsize() << endl << "OPS: " << firstpc.Get_operation_per_seconds() << endl;
	cout << endl << "****************";
	++firstpc;
	cout << endl << "****************" << endl;
	cout << endl << "Has become:" << endl << "Ramsize: " << firstpc.Get_ramsize() << endl << "OPS: " << firstpc.Get_operation_per_seconds() << endl;
	cout << "================================================================" << endl;

	cout << endl;
	cout << endl << "Was:" << endl << endl << "Optime: " << firstpc.Get_optime() << endl << "Num programm:" << firstpc.Get_numprogram() << endl;
	cout << "Operator || :" << (secondpc || firstpc) << endl << endl<< endl;
	cout << "================================================================" << endl << endl;


	cout << "====****====****====****====****====****====****====****====****====";
	cout << endl;
	cout << endl << "Was before operator = :" << endl;
	cout << endl << "****************";
	secondpc == firstpc;
	cout << endl << "****************" << endl;
	cout << "================================================================" << endl;

	cout << endl;
	cout << "Was:" << endl;
	firstpc.Showdata();
	cout << endl;
	cout << endl << "****************";
	firstpc = secondpc;
	cout << endl << "****************" << endl;
	cout << endl;
	cout << "Has become:" << endl;
	firstpc.Showdata();
	cout << endl;
	cout << "================================================================" << endl;

	cout << endl;
	cout << endl << "has become after operator = :" << endl;
	cout << endl << "****************";
	secondpc == firstpc;
	cout << endl << "****************" << endl;
	cout << "====****====****====****====****====****====****====****====****====" << endl;

	return 0;
}