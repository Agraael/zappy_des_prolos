/*
** EPITECH PROJECT, 2018
** server
** File description:
** header
*/

#ifndef TAB_H_
	#define TAB_H_

#include "struct.h"
#include "fcts.h"

static const	t_functions g_tab[] = {
	{"-help", &help},
	{"-p", &check_port},
	{"-x", &check_width},
	{"-y", &check_height},
	{"-n", &check_names},
	{"-c", &check_client_nb},
	{"-f", &check_freq},
	{NULL, NULL}
};

#endif /* !TAB_H_ */
