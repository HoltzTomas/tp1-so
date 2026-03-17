#ifndef GAME_SYNC_H
#define GAME_SYNC_H

#include <semaphore.h>
#include "constants.h"

typedef struct
{
    sem_t view_update_ready;
    sem_t view_print_done;
    sem_t master_starvation_guard;
    sem_t state_mutex;
    sem_t readers_count_mutex;
    unsigned int readers_count;
    sem_t player_can_move[MAX_PLAYERS];
} GameSync;

void game_sync_reader_enter(GameSync *sync);
void game_sync_reader_exit(GameSync *sync);

#endif
