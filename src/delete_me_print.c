
#include "../includes/lem-in.h"

void		print_room(t_room *list)
{
	//	puts("PRINT_NODE");
	int 	nodes_amount = 8;

	printf("\tNODE: %p, name: |%s|, ants_in_room: %d, start: %d, end: %d, next: %p\n", list, list->room_name, list->ants_in_room, list->bool_start_room, list->bool_end_room, list->next);
	for (int i = 0; i < nodes_amount; i++) {
		if  (list->nearby_rooms[i])
			printf("\t    nearby node %d: name: |%s|, %p\n", i, list->nearby_rooms[i]->room_name, list->nearby_rooms[i]);
	}
	puts("\n");
}

void		print_list(t_room *room)
{
//	puts("PRINT_LIST");
	int 	nodes_amount = 8;

	while (room) {
		printf("\tNODE: %p, name: |%s|, ants_in_room: %d, start: %d, end: %d, next: %p\n", room, room->room_name, room->ants_in_room, room->bool_start_room, room->bool_end_room, room->next);
		for (int i = 0; i < nodes_amount; i++) {
			if  (room->nearby_rooms[i])
				printf("\t    nearby node %d: name: |%s|, %p\n", i, room->nearby_rooms[i]->room_name, room->nearby_rooms[i]);
		}
		room = room->next;
	}
	puts("\n\n");
}

void		print_ants(t_ant **ants)
{
//	puts("PRINT_ANTS");
	while (*ants)
	{
		printf("ANT: nbr: %d, at_end: %d\t\t", (*ants)->ant_number, (*ants)->finished);
		printf("CURR_NODE: name: |%s|, ants_in_room: %d, start: %d, end: %d\n", (*ants)->curr_room->room_name, (*ants)->curr_room->ants_in_room, (*ants)->curr_room->bool_start_room, (*ants)->curr_room->bool_end_room);
		ants += 1;
	}
	puts("\n\n");
}
