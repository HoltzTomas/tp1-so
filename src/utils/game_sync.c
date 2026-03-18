#include "game_sync.h"

void game_sync_reader_enter(GameSync *s)
{
    sem_wait(&s->master_starvation_guard);
    sem_post(&s->master_starvation_guard);

    sem_wait(&s->readers_count_mutex);
    s->readers_count++;
    if (s->readers_count == 1)
        sem_wait(&s->state_mutex);
    sem_post(&s->readers_count_mutex);
}

void game_sync_reader_exit(GameSync *s)
{
    sem_wait(&s->readers_count_mutex);
    s->readers_count--;
    if (s->readers_count == 0)
        sem_post(&s->state_mutex);
    sem_post(&s->readers_count_mutex);
}
