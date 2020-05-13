#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;


int main()
{
	while (true)
	{
		cout << "Show data: click 1" << endl;
		cout << "Write data: click 2" << endl;
		cout << "Exit: click 3" << endl<<"::::";

		int ind, len =16, len_add=0;
		cin >> ind;

		if (ind == 1)
		{
			fstream fin("myFile.txt", ios::in);
			if (!fin.is_open())
			{
				cout << "File don't open!";
				break;
			}
			string name, circle_1, circle_2, circle_3, best_res, avg_res;
			char  chr;
			int flag_w=0, flag_i=0;  //flag_w - для виявлення того який елемент ми зчитуємо; flag_i - для позначення початку і кінця читання "значення"
			double arr[5];
			cout << "\n\n\n\n";
			cout.setf(ios::left);

			while (fin.get(chr))//"fin.get(chr)"-True якшо вдалось зчитати символ і False - уоли кінець файлу або не вдалося зчитати;
			{
				if (chr == ';')
				{
					flag_w++; 
					flag_i = 0;
				}

				if (flag_i == 1 && flag_w == 0)
				{
					name += chr;
				}
				if (flag_i == 1 && flag_w == 1)
				{
					circle_1 += chr;
				}
				if (flag_i == 1 && flag_w == 2)
				{
					circle_2 += chr;
				}
				if (flag_i == 1 && flag_w == 3)
				{
					circle_3 += chr;
				}
				if (flag_i == 1 && flag_w == 4)
				{
					avg_res += chr;
				}
				if (flag_i == 1 && flag_w == 5)
				{
					best_res += chr;
				}

				if (chr == ':')
				{
					flag_i = 1; 
				}
			
			}

			if (len < name.length())			//Для того, коли ім'я буде більше ніж 16 символів
			{
				len_add = name.length() + 4;
			}

			cout << setw(len+len_add) << "Name";
			cout << setw(len) << "First_c" << setw(len) << "Second_c" << setw(len) << "Third_c" << setw(len);
			cout << setw(len) << "Average_time" << setw(len) << "Best_time" << endl << endl;


			cout << setw(len+len_add) << name;
			cout << setw(len) << circle_1 << setw(len) << circle_2 << setw(len) << circle_3;
			cout << setw(len) << avg_res << setw(len) << best_res;

			fin.close();
			cout << "\n\n\n";
		}
		if (ind == 2)
		{
			cout << endl << endl;
			while (true)
			{
				string name;
				int arr[3];
				double best_r;

				fstream fout("myFile.txt", ios::out);

				if(!fout.is_open())
				{
					cout << "File not open.\n";
					break;
				} 
				
				cout << "\nEnter name of sportsman:";
				cin >> name;
				fout<<"Name:"<< name << ";"; 
				for (int i = 1; i <= 3; i++)
				{
					cout << "\nEnter a circle time #" << i << " in seconds::";
					cin >> arr[i - 1];
					fout << "\n" << i << "):" << arr[i - 1] << ";";
				}
				fout << "\n" << "APT:"<< (arr[0]+arr[1]+arr[2])/3 << ";";
				best_r = arr[0];
				for (int i = 1; i < 3; i++)
				{
					if (arr[i] > best_r) best_r=arr[i];
				}
				fout << "\n" << "Best_R:"<< best_r << ";";

				cout << "\n\n";
				fout.close();
				break;
			}

		}
		if (ind == 3)
		{
			break;
		}
	}
	return 0;
}