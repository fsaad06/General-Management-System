//Importing the basic libraries
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <ctime>
#include <windows.h>
#include <stdio.h>

//user defined header files
#include "./include/Admin.h"
#include "./include/Cabin.h"
#include "./include/Vehicle.h"

//Using standard namespace
using namespace std;
#pragma warning(disable:4996)

//Function prototypes
void print_heading();
void initial_setup();
time_t time_seconds();
void clear_screen();
void main_options();
void display_admin_options();
void non_existant_file();
void print_current_config(int no_cabs, cabin cab[]);
void system_choices();

//main function begins here
int main(void)
{

	//system color
	initial_setup();

	//object of class class vehicle_data
	vehicle_data set_vehicle;
	set_vehicle.check_vehicle_file();//to check the existant of file

	cabin_data set_cabin;
	set_cabin.check_data_file();//to check the existant of file

	bool access = true;
	while (access)
	{
		int choice;
	start:
		system("cls");//clear screen
		print_heading();
		main_options();//display screen

		cin >> choice;

		if (choice == 1)
		{
			system("cls");
			int pass;
			print_text(2, 5, "Enter Password :");//prompts the user to enter passowrd
			cin >> pass;

			if (admin::verify_password(pass))//verify passowrd
			{
				//goto statement 
			admin_start:
				system("cls");

				//dyanmic memory allocation
				admin* adm = new admin;
				adm->check_admin_file();
				display_admin_options();

				int choice;
				cin >> choice;
				system("cls");

				switch (choice)
				{
				case 1:
					//admin to edit the properties
					adm->edit_admin_file();
					break;

				case 2:
					//view vehicle record
					adm->read_to_vector();
					break;

				case 3:
					//total money stored in the system
					print_text(1, 5, "Total money is : " + to_string(adm->calc_money()));
					break;

				case 4:
				{
					//view admin properties
					adm->read_admin_file();
					break;
				}

				case 5:
					//re write the setup
					adm->operator-();
					break;

				default:
					delete adm;
					goto start;
					break;
				}

				delete adm;
				goto admin_start;
			}
			else
			{
				//wrong password
				print_text(1, 5, "You have entered wrong password");
				clear_screen();
				goto start;
			}
			access = false;
		}
		else if (choice == 2)
		{
			//checking wheteher the file exists or not
			system("cls");
			fstream file;
			//opens file in write mode
			file.open("setup_data", ios::in);
			if (!file)
			{
				non_existant_file();
				goto start;

			}
			else
			{
				parking pr = make_parking_profile();
				car c1;
				bike b1;

				int no_cabs = pr.get_cabins();
				cabin c[10];
				cabin_data cabs;
				cabin* cab;

				bool run = 1;
				while (run)
				{
					system("cls");
					cab = cabs.read_file_to_array(c);

					print_current_config(no_cabs, cab);


					int current_cabin = cab[0].cabin_num;
					system_choices();
					int choice;
					cin >> choice;
					print_text(1, 5, "________________________________");

					switch (choice)
					{
					case 1:
					{
						bool up = true;
						bool down = false;
						bool space = true;
						int counter = 0;
						//checking space
						while (cab[counter].parked && space)
						{

							if (up)
							{
								if (counter < no_cabs)
								{
									counter++;
								}
								else
								{
									counter = current_cabin;
									up = false;
									down = true;
								}
							}

							if (down)
							{
								if (counter > 0)
								{
									counter--;
								}
								else
								{
									print_text(1, 5, "No empty space");
									cout   << endl;
									space = false;
								}
							}

						}

						if (space)
						{
							print_text(1, 5, "Vehicle type is: (1 for car, other for bike)");
							 
							int type;
							cin >> type;
							vehicle* add_vehicle;
							if (type == 1)
							{
								car c;
								add_vehicle = &c;
							}
							else
							{
								bike b;
								add_vehicle = &b;
								type = 0;
							}

							print_text(0, 5, "Enter vehicle num : ");
							 
							int num;
							cin >> num;
							int status = cabs.search_by_num(num);
							while (status != -1)
							{
								print_text(0, 5, "Number plate exists. Enter vehicle num : ");
								 
								cin >> num;
								status = cabs.search_by_num(num);
							}
							add_vehicle->set_num_plate(num);
							add_vehicle->set_park_time();
							add_vehicle->set_cabin(counter);

							print_text(1, 5, "Do you want to enter car (1 for yes) :");
							 
							int choice;
							cin >> choice;
							if (choice)
							{
								cabin* temp = new cabin[no_cabs];
								temp[no_cabs - 1] = cabin(cab[counter].cabin_num, 1, type, add_vehicle->get_plate(), add_vehicle->get_park_time());
								int count = 0;
								for (int x = 0; x < no_cabs - 1; x++) {
									if (counter < no_cabs)
									{
										temp[x] = cab[++counter];
									}
									else
									{
										temp[x] = cab[count];
										count++;
									}
								}
								for (int x = 0; x < no_cabs; x++) {
									cab[x] = temp[x];
								}
								cabs.edit_cabin_data(cab, no_cabs);

								delete[] temp;
							}
						}

						break;
					}

					case 2:
					{
						print_text(1, 5, "Enter vehicle plate number : ");
						int cab1;
						cin >> cab1;
						int status = cabs.search_by_num(cab1);
						if (status == -1)
						{
							print_text(1, 5, "Could not find vehicle");
							 
						}

						else
						{

							print_text(2, 5, to_string(status) + "<-status");

							int parked_time = cab[status].time;
							int vehicle_type = cab[status].type;
							int cabin_current = cab[status].cabin_num;

							vehicle* parked_vehicle;
							if (vehicle_type == 1)
							{
								car c;
								parked_vehicle = &c;
							}
							else						
							{
								bike b;
								parked_vehicle = &b;
							}							

							parked_vehicle->set_values(pr);
							parked_vehicle->set_custom_park_time(parked_time);
							parked_vehicle->set_exit_time();
							//
							int get_exit = parked_vehicle->get_exit_time();

							int fee = parked_vehicle->calculate_fee();

							int fine = parked_vehicle->calculate_fine();

							print_text(1, 5, "Your fee is Rs " + to_string(fee));

							if (fine != 0)
							{
								print_text(1, 5, "Your fine is Rs " + to_string(fine));
								fee += fine;
							}

							print_text(1, 5, "Enter amount of Rs" + to_string(fee));
							print_text(1, 5, "Entered fee: ");

							int entered_fee;
							cin >> entered_fee;

							if (entered_fee >= fee)
							{
								set_vehicle.edit_vehicle_file(to_string(cab1), to_string(vehicle_type), to_string(parked_time), to_string(get_exit)
									, to_string(fee), to_string(fine));
								cabin* temp2 = new cabin[no_cabs];
								temp2[0] = cabin(cab[status].cabin_num, 0, -1, -1, -1);

								int count = 0;
								for (int x = 1; x < no_cabs; x++) {
									if (status < no_cabs - 1)
									{
										temp2[x] = cab[++status];
									}
									else
									{
										temp2[x] = cab[count];
										count++;
									}
								}

								for (int x = 0; x < no_cabs; x++) {
									cab[x] = temp2[x];
								}

								delete[] temp2;

								cabs.edit_cabin_data(cab, no_cabs);
								print_text(1, 5, "Returing change: " + entered_fee - fee);
							}
						}
						break;
					}

					default:
						goto start;
					}

				}

			}
			file.close();
			access = false;
		}
		else if (choice == 3)
		{
			clear_screen();
			return 0;
		}
		else
		{
			print_text(1, 5, "Enter a valid choice: ");
		}
	}
	clear_screen();
	return 0;
}


//To clear screen and print the heading
void print_heading()
{
	system("cls");

	for (int x1 = 0; x1 < 120; x1++)
	{
		position(x1, 2);
		printf("%c", 219);
	}
	position(42, 4);
	print_text(0, 0, "Parking Management System");

	for (int x2 = 0; x2 < 120; x2++)
	{
		position(x2, 6);
		printf("%c", 219);
	}
	line(2);
}

void initial_setup()
{
	system("color 0E");
}
//time function
time_t time_seconds()
{
	time_t now = time(nullptr);
	return now;
}

void clear_screen()
{
	system("pause");
	getchar();
}

void main_options()
{
	print_text(1, 5, ">> Admin Access: 1");
	print_text(1, 5, ">> Run System  : 2");
	print_text(1, 5, ">> Exit        : 3");
	print_text(2, 5, ">> Your choice : ");
}

void display_admin_options()
{
	system("cls");
	print_text(1, 5, "Edit properties: 1");
	print_text(1, 5, "Vehicle Record : 2");
	print_text(1, 5, "Calculate Money: 3");
	print_text(1, 5, "View properties: 4");
	print_text(1, 5, "Rewrite setup  : 5");
	print_text(1, 5, "Exit           : Any");
	print_text(1, 5, "Enter your choice : ");

}

void non_existant_file()
{
	print_text(1, 5, " System Error .. !!");
	clear_screen();
}

void print_current_config(int no_cabs, cabin cab[])
{
	print_text(1, 5, "________________________________");
	print_text(1, 5, "Current configuration");

	for (int x = 0; x < no_cabs; x++) 
	{
		cout << endl;
		cout << "\t\t\t\t\t";
		cout << cab[x].cabin_num << "," << cab[x].parked;
		if (x == 0)
		{
			cout << " <-- Entry point";
		}
	}
	print_text(1, 5, "________________________________");
}

void system_choices()
{
	print_text(2, 5, "|#| Enter vehicle: 1");
	print_text(1, 5, "|#| Exit vehicle : 2");
	print_text(1, 5, "|#| Exit System  : Any");
	print_text(1, 5, "|#| Enter your choice : ");
}