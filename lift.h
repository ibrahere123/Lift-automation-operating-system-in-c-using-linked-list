#pragma once
#include<iostream>
using namespace std;
//Ibrahim naeem
//21i0512
class lift_floors {
public:
	int  floor;
	char floor_status;
	//bool isoperational;//A for active N for not active
	lift_floors* next;
	lift_floors* prev;
	lift_floors(int data) {
		this->floor = data;
		this->next = NULL;
		this->prev = NULL;
		this->floor_status = 'A';
		
	}
	
	lift_floors(){}
	
	
	~lift_floors(){}
};

void skip_floor(lift_floors*& head, lift_floors*& tail, int floorNo)
{

	// Search for the floor to be skipped
	lift_floors* current = head;
	while (current != NULL && current->floor != floorNo) {
		current = current->next;
	}
	//for (int i = 0; i < 12; i++);
	// 
	// 
	// 
	// If the floor is found, mark it as not active
	if (current != NULL) {
		current->floor_status = 'N';
	}
}
void add_floor(lift_floors*& head, lift_floors*& tail, lift_floors*& new_floor)
{
	if (head == NULL) {
		head = new_floor;
		tail = new_floor;
	}
	// Otherwise, add the new floor to the end of the list
	else {
		tail->next = new_floor;
		new_floor->prev = tail;
		tail = new_floor;
	}
}
void  iniitiallize(lift_floors*& head, lift_floors*& tail)
{
	lift_floors* current = head;
	for (int i = -1; i < 5; i++) {
		lift_floors* new_floor = new lift_floors(i);
		add_floor(head, tail, new_floor);
	}

}

int liftup(lift_floors* &current, lift_floors* &head, lift_floors* &tail, int requested_floor)
//{
//	i/*f (current->floor == requested_floor)
//	{
//		return current->floor;
//
//	}
//	else if (current->floor > requested_floor && current != tail)
//	{
//		return liftup(current->next, head, tail, requested_floor);
//	}
//	else if (current->floor < requested_floor && current != head)
//	{
//		return liftup(current->prev, head, tail, requested_floor);
//	}
//	else {
//		return current->floor;
//	}*/
{
	;
	if (current == nullptr) {
		throw runtime_error("IT IS NOT PRESENT: ");
		return -1;
	}
	if (current->floor == requested_floor) {
		cout << "You are at " <<current->floor<<" FLOOR" << endl;;
		return current->floor;
	}
	if (current->next->floor_status == 'N')
	{
		
		cout << "Skipped floor " << current->next->floor << "...." << endl;
		skip_floor(head, tail, current->next->floor);
		
		return liftup(current->next, head, tail, requested_floor);

	}
	if (current->next == nullptr)
	{
		cout << "next pointer is null"<<endl;
	}
	if (current == head)
	{
		cout << "Reached at head"<<endl;
	}
	if (current->floor < requested_floor) {
		
		cout << "Going up to floor " << current->next->floor << std::endl;
		
		return  liftup(current->next, head, tail, requested_floor);

	}
	if (current->floor > requested_floor) {
		//std::cout << "Going up to floor " << current->prev->floor << std::endl;
		cout << "Going up to floor " << current->prev->floor << std::endl;
		
		return liftup(current->prev, head, tail, requested_floor);

	}

}

//	if (current->next == NULL) {
//		cout <<
//			"already on top floor";
//		return 0;
//	}
//
//	if (current->next->floor_status == 'N') {
//		// next floor is not operational, skip it
//		cout << "Skipping floor " << current->next->floor << "..." << endl;
//		skip_floor(head, tail, current->next->floor);
//		//cout << "Moving up";
//		return liftup(current, head, tail, requested_floor);
//	}
//
//	current = current->next;
//
//	if (current->floor == requested_floor) {
//		cout << "ON the same floor";
//		return 0;
//	}
//
//	return liftup(current, head, tail, requested_floor);
//}


	//recurrsive funcation to take lift up

int liftdown(lift_floors*& current, lift_floors* &head, lift_floors* &tail, int requested_floor)
{/*
	if (current == nullptr) {
		cout << "Error: Lift is already at the lowest floor" << endl;
		return tail->floor;
	}
	current = current->prev;
	if (current == nullptr) {
		cout << "Error: Lift is already at the lowest floor" << endl;
		return tail->floor;
	}
	return current->floor;
	if (current == nullptr)
	{
		
		return -1;
	}*/
	int counter = 0;
	if (current->floor == requested_floor)
	{
		
		return current->floor;
	}
	if (current->prev->floor_status == 'N') {
		// previous floor is not operational, skip it
		
		cout << "Skipping floor " << current->prev->floor << " cannot go to this floor" << endl;
	  skip_floor(head, tail, current->prev->floor);
 return liftdown(current->prev, head, tail, requested_floor);
	}
	if (current->floor > requested_floor && current != head)
	{
		
		cout << "Going down to floor " << current->prev->floor << std::endl;
		return liftdown(current->prev, head, tail, requested_floor);
	}
	if (current->floor < requested_floor && current != tail)
	{
		cout << "Going down to floor " << current->prev->floor << std::endl;
		return liftdown(current->next, head, tail, requested_floor);
	}
	if (current == nullptr) {
		cout << "Error: Lift is already at the lowest floor" << endl;
		return tail->floor;
	}
	current = current->prev;
	if (current == nullptr) {
		cout << "Error: Lift is already at the lowest floor" << endl;
		return tail->floor;
	}
	return current->floor;
}
//	if (current->prev == NULL) {
//		cout << " already on basement";
//		return 0;
//	}
//
//	if (current->prev->floor_status == 'N') {
//		// previous floor is not operational, skip it
//		cout << "Skipping floor " << current->prev->floor << "..." << endl;
//		skip_floor(head, tail, current->prev->floor);
//		return liftdown(current, head, tail, requested_floor);
//	}
//
//	current = current->prev;
//
//	if (current->floor == requested_floor) {
//		return 0;
//	}
//
//	return liftdown(current, head, tail, requested_floor);
//}
	/*else
	{
		return requested_floor;
	}*/
	/*if (current == nullptr) {
		return -1;
	}
	if (current->next->floor == requested_floor) {
		return requested_floor;
	}
	if (current->next->floor > requested_floor) {
		std::cout << "Going down to floor " << current->prev->floor << std::endl;
		return liftdown(current->prev, head, tail, requested_floor);
	}
	std::cout << "Going down to floor " << current->next->floor << std::endl;
	return liftdown(current->next, head, tail, requested_floor);*/
	//recurrsive funcation to bring the lift down


int lift_operating_system(int& requested_floor, lift_floors*& current, lift_floors*& head, lift_floors*& tail, char lift_status)
{
	//current = head;
	/*if (requested_floor < -1 || requested_floor > 4) {
		cout << "Invalid floor request.\n";
		return current->floor;
	}

	if (lift_status == 'H')
	{
		cout << "LIFT IS BEING HALTED......" << endl;
		return current->floor;
	}
	if (requested_floor < tail->floor || requested_floor > head->floor)
	{
		cout << "INVALID REQUEST......" << endl;

		return current->floor;
	}
	if (requested_floor == current->floor)
	{
		return current->floor;
	}

	if (requested_floor > current->floor)
	{
		return liftup(current, head, tail, requested_floor);
	}
	if (requested_floor < current->floor)
	{
		return liftdown(current, head, tail, requested_floor);

//	}*/
/*
*
if (lift_status == 'H') {
	cout << "Lift is currently halted. Cannot perform lift operations." << endl;
	return current->floor;
}

if (requested_floor == current->floor) {
	cout << "Lift is already on the requested floor." << endl;
	return current->floor;
}
int i = 0;

if (requested_floor > current->floor) {
	cout << "Moving up  the floor...." << endl;
	i++;
	return liftup(current, head, tail, requested_floor);
	cout << i;
}
else {
	cout << "Moving down the floor... " << endl;
	return liftdown(current, head, tail, requested_floor);
}*/

/*while (current && current->floor != requested_floor) {
	current = current->next;
}*/

	if (current == nullptr)
	{
		cout << "Exception  ";
		return -1;
	}
	if (lift_status == 'H')
	{
		cout << "Lift is halted... " << endl;
		return current->floor;
	}
	/*if (!current->isoperational && requested_floor != current->floor) {
		cout << "Lift cannot stop on this floor.\n";
		return current->floor;
	}*/
	/*if (current->isoperational == true)
	{
		cout << "Skipped... " << endl;
		return current->floor;
	///*}*/
	//lift_floors* temp = head;
	/*while (temp != NULL) {
		if (temp->floor == requested_floor && temp->floor_status == 'A') {
			break;
		}
		temp = temp->next;
	}
	if (temp == NULL) {
		cout << "Invalid or inactive floor requested.\n";
		return 0;
	}*/
	//current = temp;
	/*while (current && current->floor != requested_floor) {
		current = current->next;
	}*/


	/*if (current->floor == 'N' )
	{


		cout << "Floor is skipped..." << endl;
	}*/

	if (requested_floor < -1 || requested_floor > tail->floor) {
		cout << "Invalid floor request" << endl;
		return current->floor;
	}
	if (requested_floor == current->floor && current->floor_status != 'N') {
		//	/*while (current && current->floor != requested_floor) {
		//		current = current->next;
		//	}*/
			cout << "Already on floor " << requested_floor << endl;
			return current->floor;
		}
		if (requested_floor < current->floor && lift_status != 'H') {
			/*while ((current && current->floor != requested_floor)) {
				if (current == nullptr) {
					if (requested_floor < head->floor) {
						current = head;
					}
					else {
						current = tail;
					}
				}
				else
				{
					current = current->prev;
				}
			}*/
			cout << "Lift moving down  " << endl;//<<requested_floor << endl;
			cout << "You are at  " << requested_floor << " Floor" << endl;
			return liftdown(current, tail, head, requested_floor);
		}

		if (requested_floor > current->floor && lift_status != 'H') {
			/*while (current && current->floor != requested_floor) {
				current = current->next;
			}*/
			while ((current && current->floor != requested_floor)) {
				if (current == nullptr) {
					if (requested_floor < head->floor) {
						current = head;
					}
					else {
						current = tail;
					}
				}
				else
				{
					current = current->next;
				}
			}
			cout << "Lift moving up  " << endl;
			//cout << "You are at  " << current->floor << " Floor" << endl;
			 return liftup(current, tail, head, requested_floor);
			//cout << "You are at  " << current->next << " Floor" << endl;

		}
		cout << "Lift has arrived at floor " << current->floor << "." << endl;

		return current->floor;

	}




	//if (current == nullptr) {
	//	// if current is null, set it to the head of the linked list
	//	current = head;
	//	cout << "ffff";
	//}
	//if(lift_status == 'H') {
	//	return current->floor;
	//}

	// Check if the requested floor is invalid or not operational
	//bool valid_floor = false;
	//bool operational_floor = true;
	//lift_floors* temp = head;
	//while (temp != nullptr) {
	//	if (temp->floor == requested_floor) {
	//		valid_floor = true;
	//		operational_floor = temp->isoperational;
	//		break;
	//	}
	//	temp = temp->next;
	//}

	

	char halt_lift(char status)
	{
		status = 'H';
		return status;

		//halts the lift, no up and down operation can be performed. Stored H for halting

	}
	char un_halt_lift(char status)
	{
		status = 'W';
		return status;
		//Unhatls the lift. Store W which represents that the lift is working

	}
	void deleteNode(lift_floors** head_ref, lift_floors* del) {
		if (*head_ref == NULL || del == NULL) {
			return;
		}
		if (*head_ref == del) {
			*head_ref = del->next;
		}
		if (del->next != NULL) {
			del->next->prev = del->prev;
		}
		if (del->prev != NULL) {
			del->prev->next = del->next;
		}
		free(del);
		return;
	}

	void print_all_the_floors(lift_floors* head, lift_floors* tail)
	{
		lift_floors* temp = head;
		while (temp->next != NULL)
		{
			cout << temp->floor << endl;
			temp = temp->next;
		}

	}	
	void make_floor_operational(lift_floors*& head, lift_floors*& tail, int floorNo)
		{



			lift_floors* current = head;
			while (current != NULL && current->floor != floorNo) {
				current = current->next;
			}

			// If the floor is found, mark it as active
			if (current != NULL) {
				current->floor_status = 'A';
			}
		}
	//void add_floor( lift_floors * &head, lift_floors * &tail,lift_floors* &new_floor)
	//{
	////	lift_floors* curr = head;

	////	// find the correct position to insert the new floor
	////	while (curr != nullptr && curr->next < new_floor->next) {
	////		curr = curr->next;
	////	}

	////	// insert the new floor
	////	new_floor->next-> = curr;
	////	new_floor->prev = curr->prev;
	////	if (curr->prev != nullptr) {
	////		curr->prev->next = new_floor;
	////	}
	////	else {
	////		head = new_floor;
	////	}
	////	curr->prev = new_floor;

	////	// update the tail of the list if necessary
	////	if (new_floor->next == nullptr) {
	////		tail = new_floor;
	////	}
	//	/*new_floor->prev = tail->prev;
	//new_floor->next = tail;
	//tail->prev->next = new_floor;
	//tail->prev = new_floor;*/
	//	//add a lift floor;
	//	if (head == NULL) {
	//		head = new_floor;
	//		tail = new_floor;
	//	}
	//	// Otherwise, add the new floor to the end of the list
	//	else {
	//		tail->next = new_floor;
	//		new_floor->prev = tail;
	//		tail = new_floor;
	//	}
	//}
	
void skip_floor1(lift_floors*& head, lift_floors*& tail, int floorNo)
{

	// Search for the floor to be skipped
	lift_floors* current = head;
	while (current != NULL && current->floor != floorNo) {
		current = current->next;
	}

	// If the floor is found, mark it as not active
	if (current != NULL) {
		current->floor_status = 'N';
	}
}

	//add logic to make lift skip a certian floor

//void make_floor_operational(lift_floors*& head, lift_floors*& tail, int floorNo)
//{
//	
//
//	
//	lift_floors* current = head;
//	while (current != NULL && current->floor != floorNo) {
//		current = current->next;
//	}
//
//	// If the floor is found, mark it as active
//	if (current != NULL) {
//		current->floor_status = 'A';
//	}
//}
	//add logic to make lift operational on a certain floor

void deleteNode1(lift_floors** head_ref, lift_floors* del) {
	if (*head_ref == NULL || del == NULL) {
		return;
	}
	if (*head_ref == del) {
		*head_ref = del->next;
	}
	if (del->next != NULL) {
		del->next->prev = del->prev;
	}
	if (del->prev != NULL) {
		del->prev->next = del->next;
	}
	free(del);
	return;
}