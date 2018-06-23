/*
** EPITECH PROJECT, 2018
** loop
** File description:
** server
*/

#include "struct.h"
#include "fcts.h"
#include <pthread.h>

void *live_alone(void *argument)
{
    int b = 0;
    int max = 0;
    thread_t *arg = (thread_t *)argument;

    while (!b)
    {
        max = 0;
        sleep(1);
        for (int i = 0; i < MAX_FD; i++)
            if (arg->e->fd_type[i] == FD_CLIENT) {
                arg->e->inventory[i].food -= 1;
                //printf("le joueur %d a %d food\n", i, (int)arg->e->inventory[i].food);
            }
    }
    pthread_exit(NULL);
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