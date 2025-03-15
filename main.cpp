#include<iostream>
#include<cstdlib>
#include<cmath>
#include "coordinate.h"

using namespace std;

int coord_counter=1; //Global counter for ID
void add_coordinate(Coordinate*& list_end, float x, float y)
{
	Coordinate *new_coord=new Coordinate{x, y, coord_counter++, nullptr, list_end};
	if(list_end)
	{
		list_end->next =new_coord;
	}
		list_end =new_coord;
}

void forward_display(Coordinate *list_beginning)
{
	while(list_beginning)
	{
		cout<<"ID: "<<list_beginning->coord_id<<"("<<list_beginning->x<<","<<list_beginning->y<<")\n";
		list_beginning=list_beginning->next;
	}
}

void backward_display(Coordinate *list_end)
{
	while(list_end)
	{
		cout<<"ID:"<<list_end->coord_id<<"("<<list_end->x<<","<<list_end->y<<")\n";
		list_end= list_end->previous;
	}
}

void delete_coordinate(Coordinate *list_beginning, int coord_id_to_delete)
{
	Coordinate *current = list_beginning;
	while (current) {
		if (current->coord_id == coord_id_to_delete) {
			if (current->previous) current->previous->next = current->next;
			if (current->next) current->next->previous = current->previous;
			if (current == list_beginning) list_beginning = current->next;
			delete current;
			cout << "Coordinate ID " << coord_id_to_delete << " deleted.\n";
			return;
		}
		current=current->next;
	}
	cout << "Coordinate ID not found.\n";
}

int list_length(Coordinate *list_beginning) {
	 int count = 0;
	 while (list_beginning){
	 	count++;
		list_beginning=list_beginning->next;
	}
	return count;
}

void closest_to(Coordinate *list_beginning, float x, float y){
	Coordinate *closest=list_beginning;
	float min_distance=sqrt(pow(x-list_beginning->x,2) +pow(y-list_beginning->y,2));

	while(list_beginning)
	{
		float distance=sqrt(pow(x-list_beginning->x,2));
		if(distance<min_distance)
		{
			min_distance=distance;
			closest=list_beginning;
		}
		list_beginning=list_beginning->next;
	}

	cout <<"Closest point is ID:"<<closest->coord_id<<"at ("<<closest->x<<", " << closest->y << ") with distance " << min_distance << "\n";
	}

int main(int argc, char *argv[]) {
	if (argc != 2) {
		cerr << "Usage: " << argv[0] << " <number_of_coordinates>\n";
		return 1;
	}

	int num_coords=atoi(argv[1]);
	Coordinate *head=nullptr, *tail=nullptr;

	srand(time(nullptr));
	for(int i=0; i<num_coords; i++)
	{
		float x = static_cast<float>(rand()) / RAND_MAX * 100;
		float y = static_cast<float>(rand()) / RAND_MAX * 100;
		if (!head)
		{
			head=new Coordinate{x, y, coord_counter++, nullptr, nullptr};
			tail=head;
		}
		else
		{
			add_coordinate(tail, x, y);
		}
	}

	cout <<"Forward Display:\n";
	forward_display(head);

	cout<<"\n Backward Display:\n";
	backward_display(tail);

	cout<<" Total number of coordinates:"<<list_length(head)<<"\n";

	delete_coordinate(head, 2);//Example deletion
	cout<<"\nAfter Deletion:\n";
	forward_display(head);

	closest_to(head, 50.0f, 50.0f); // Example closest point search

	return 0;
}
