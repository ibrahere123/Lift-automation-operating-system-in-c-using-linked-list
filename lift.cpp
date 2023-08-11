#include "pch.h"
#include<iostream>
#include"Header.h"
using namespace std;

int main()
{  //Ibrahimnaeem_21i0512_Ass_02
	lift_floors* head = NULL;
	lift_floors* tail = NULL;


	int total_floors = 6; // total number of floors
	int current_floor = -1; // starts with basement
	int requested_service; //choice of user
	int requested_floor; //floor the lift goes on
	char status = 'W'; //W for working , H for halted

	//initialize everything and poplate the link list based on above data.
	//use add floor to add all the floors in the list

		/*lift_floors* new_lift = new lift_floors(-1);

		add_floor(head, tail, new_lift);
		lift_floors* newlift1 = new lift_floors(0);
		add_floor(head, tail, newlift1);

		lift_floors* newlift2 = new lift_floors(1);
		add_floor(head, tail, newlift2);
		lift_floors* newlift3 = new lift_floors(2);
		add_floor(head, tail, newlift3);
		lift_floors* newlift4 = new lift_floors(3);
		add_floor(head, tail, newlift4);
		lift_floors* newlift5 = new lift_floors(4);
		add_floor(head, tail, newlift5)*/

	for (int i = -1; i < 5; i++) {
		lift_floors* new_floor = new lift_floors(i);
		add_floor(head, tail, new_floor);
	}
	/*
	for (int i =1; i < 5; i++)
	{
		lift_floors* new_floor = new lift_floors(i);
		add_floor(head, tail, new_floor);

	}
	*/
	lift_floors* current = head;
	int choice = -1;
	lift_floors* temp=head;
	int i = 0;
	while (choice!=7)
	{

		cout << "Please select a funcation of your choice";
		cout << endl << "1. Go to a specific floor";
		cout << endl << "2. Halt Lift";
		cout << endl << "3. Unhalt Lift";
		cout << endl << "4. Add floor";
		cout << endl << "5. Skip floor";
		cout << endl << "6. Make floor operational";
		cout << endl << "7. Exit";
		cout << endl;
		cin >> choice;


		switch (choice)
		{
		case 1:
		{
			cout << "Enter Floor of choice ";
			cin >> requested_floor;
			//if (requested_floor <-1) {
			//	break;
			//}

			//// Update the current floor pointer to the requested floor
			//while (current && current->floor != requested_floor) {
			//	current = current->next;
			//}
			//if (!current) {
			//	cout << "Invalid floor number. Please try again." << endl;
			//	current = head; // Reset current to basement
			//	continue;
			//}
			
			current_floor = lift_operating_system(requested_floor, current, head, tail, status);
		/*	while ((current && current->floor != requestedflooor)) {
				if (current == nullptr) {
					if (requested_floor < temp->floor) {
						current = temp;
					}
					else {
						current = tail;
					}
				}
				else
				{
					current = current->next;
				}
			}*/

			
			//cout << "You are moved to this " << current_floor << endl;
			//current = current->next;
			break;
			

			//	lift_operating _system();//add arguments 
				//your code here
		}
		case 2:
		{
			status = halt_lift(status);
			cout << "Lift status... " << status << endl;
			break;
		}
		case 3:
		{
			status = un_halt_lift(status);
			cout << "Lift status... " << status << endl;
			break;
		}
		case 4:
		{

			int n1;
			cout << "Enter the floor number you want to add :-" << endl;
			cin >> n1;
			lift_floors* new_floor = new lift_floors(n1);
			add_floor(new_floor, head, tail);
			cout << "Floor" << n1 << "added to the building..." << endl;
			break;

		}

		case 5:
		{
			int skip;
			cout << "Enter the floor you want to skip.... " << endl;
			cin >> skip;
			skip_floor(head, tail, skip);
			cout << "Floor" << skip << " has been skipped.." << endl;
			break;
		}
		case 6: {
			int floor_number_to_make_operational;
			cout << endl << "Enter floor number to make operational: ";
			cin >> floor_number_to_make_operational;
			make_floor_operational(head, tail, floor_number_to_make_operational);
			cout << endl << "Floor " << floor_number_to_make_operational << " is now operational." << endl;
			break;
		}
		case 7:
		{
			cout << "Exiting the lift.... ";
			break;
		}
		default:
		{
			cout << "Invalid choice" << endl;
			break;
		}

		}
		//	i++;


	}

	return 0;
}