//coordinate.h
#ifndef COORDINATE_H
#define COORDINATE_H

struct _coordinate
{
	float x;
	float y;
	int coord_id;
	struct _coordinate *next;
	struct _coordinate *previous;
};
typedef struct _coordinate Coordinate;
//add a new coord to the end of the list
void add_coordinate(Coordinate *list_end, float x, float y);
//deletes a coord with the given ID from the list
void delete_coordinate(Coordinate *list_beginning, int coord_id_to_delete);
//display the list in the forward order
void forward_display(Coordinate *list_beginning);
//display the list in backward order
void backward_display(Coordinate *list_end);
//retunrs the length of the list
int list_length(Coordinate *list_beginning);
//find and prints the coord closes to the given(x, y)
void closest_to(Coordinate *list_beginning, float x, float y);
//fress all nodes in the coordinate list, preventng memory leaks
void free_coordinate_list(Coordinate* list_beginning);
#endif//COORDINATE_H
