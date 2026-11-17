#ifndef PARKING_H
#define PARKING_H
#include <stddef.h>
#define MAX_SPACES 256
#define MAX_DRIVERS 256
#define MAX_RESERVATIONS 512
#define NAME_LEN 48
typedef struct { int id; char zone[NAME_LEN]; int capacity; int occupied; double hourly_rate; int x; int y; } ParkingSpace;
typedef struct { int id; char name[NAME_LEN]; int accessible; int max_price; } Driver;
typedef struct { int id; int driver_id; int space_id; int start_minute; int end_minute; int active; } Reservation;
typedef struct { ParkingSpace spaces[MAX_SPACES]; size_t space_count; Driver drivers[MAX_DRIVERS]; size_t driver_count; Reservation reservations[MAX_RESERVATIONS]; size_t reservation_count; } ParkingLot;
void parking_init(ParkingLot *lot);
int parking_add_space(ParkingLot *lot, ParkingSpace space);
int parking_add_driver(ParkingLot *lot, Driver driver);
int parking_reserve(ParkingLot *lot, int driver_id, int space_id, int start, int end);
void parking_print(const ParkingLot *lot);
int parking_allocate_nearest(ParkingLot *lot, int driver_id, int x, int y, int start, int end);
#endif
