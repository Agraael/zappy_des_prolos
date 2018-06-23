/*
** EPITECH PROJECT, 2018
** loop
** File description:
** server
*/

#include "struct.h"
#include "fcts.h"
#include <pthread.h>

void live_alone(t_env *e)
{
        for (int i = 0; i < MAX_FD; i++)
            if (e->fd_type[i] == FD_CLIENT) {
                printf("[%d->%d]\n", i, (int)e->inventory[i].food);
                e->inventory[i].food -= 1;
            }
}

void *timer(void *argument)
{
    thread_t *arg = (thread_t *)argument;

    arg->e->fd_type[arg->fd] = FD_FREE;
    usleep(arg->time * 1000000);
    arg->e->fd_type[arg->fd] = FD_CLIENT;
    pthread_exit(NULL);
}

void gest_time(float time, t_env *e, int fd)
{
       pthread_t thread_timer;
       thread_t argument;

       e->inventory[fd].food -= time;
       argument.e = e;
       argument.fd = fd;
       argument.time = time;
       if(pthread_create(&thread_timer, NULL, timer, (void *)&argument) == -1)
           return ;
        if (pthread_join(thread_timer, NULL)) {
            return ;
    }
}