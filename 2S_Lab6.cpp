#include <iostream>
#include <string>
using namespace std;

class Boiler
{
public:

	//Constructor's | Destructor's
	Boiler()
	{
		cout << "Constructor of Boiler" << endl;
		this->waranty = rand()/12;

		BoilTime = new int;
		*BoilTime = rand()/10;
	}

	Boiler(const Boiler &other)
	{
		cout << "Constructor of Boiler (copy)" << endl;
		this->BoilTime = new int;
		
		this->BoilTime = other.BoilTime;

		this->waranty= other.waranty;
		this->power= other.power;
	}
	
	virtual ~Boiler()
	{
		cout << "Detructor of Boiler" << endl;
		delete BoilTime;
		BoilTime = nullptr;
	}

	//Method's
	virtual void TurnOn() = 0;
	virtual void TurnOff() = 0;


	//Geter's  ||  Setter's
	int GetWaranty()
	{
		return this->waranty;
	}

	double GetPower()
	{
		return this->power;
	}

	int* GetBoilTime()
	{		
		return this->BoilTime;
	}


	void SetWaranty(int waranty)
	{
		this->waranty=waranty;
	}

	void SetPower(double power)
	{
		this->power=power;
	}

	void SetBoilTime(int value)
	{
		this->BoilTime=&value;
	}


protected:

	bool State;
	int waranty;
	double power=1.6;	
	int* BoilTime;
};

class Teapot : public Boiler
{
private:
	string model;
	int capacity;
	int* Cable_Lenth;

public:
	//Constructor's | Destructor's

	Teapot (string model,int capacity, int cablelenth)
	{
		cout << "Constructor of Teapot" << endl;
		this->model = model;
		this->capacity = capacity;

		Cable_Lenth = new int;
		*Cable_Lenth = cablelenth;
	}

	Teapot(const Teapot& other)
	{
		cout << "Constructor of Teapot (copy)" << endl;
		this->model = other.model;
		this->capacity = other.capacity;

		this->Cable_Lenth = other.Cable_Lenth;
	}

	~Teapot() override
	{
		cout << "Detructor of Teapot" << endl;
		delete this->Cable_Lenth;
		this->Cable_Lenth = nullptr;
	}

	//Operator
	void operator=(const Teapot& other)
	{
		this->model = model;
		this->capacity = capacity;
	}

	//Method's

	void TurnOn()override
	{
		cout <<endl<< "TurnOn Teapot" << endl;
		this->State = true;
	}
	void TurnOff()override
	{
		cout <<endl<< "TurnOff Teapot" << endl;
		this->State = false;
	}

	void StartBoiling(int water_capacity)
	{
		if (!this->State)
		{
			cout << "Error: turn on Teapot!!!" << endl;
			return;
		}
		if (water_capacity > this->capacity)
		{
			cout << "Error: water capacity more than Teapot's capacity"<<endl << endl;
			return;
		}
		cout << "Start boiling with "<<water_capacity<<" litr of water." << endl << "Process..." << endl << "Finish boiling" <<endl<< endl;
	}

	void CleanTeapot()
	{
		if (this->State)
		{
			cout << "Error: turn off Teapot!!!" << endl;
			return;
		}
		
		cout <<endl<< "Start cleaning" << endl << "Process..." << endl << "Finish cleaning" <<endl<< endl;
	}
	
	//Geter's  ||  Setter's
	string GetModel()
	{
		return this->model;
	}

	double GetCapacity()
	{
		return this->capacity;
	}

	int* GetCableLenth()
	{
		return Cable_Lenth;
	}


	void SetModel(string model)
	{
		this->model = model;
	}

	void SetCapacity(int capacity)
	{
		this->capacity = capacity;
	}

	void SetCablelenth(int value)
	{
		this->Cable_Lenth= &value;
	}
};


int main()
{
	int lenth;
	Teapot teapot("Teapot 2k", 16, 4);
	lenth = *teapot.GetCableLenth();
	cout << endl << "========================================" << endl;

	teapot.StartBoiling(17);
	teapot.TurnOn();
	teapot.StartBoiling(17);
	teapot.StartBoiling(14);

	teapot.CleanTeapot();
	teapot.TurnOff();
	teapot.CleanTeapot();

	cout << endl << "========================================" << endl;
	return 0;
}