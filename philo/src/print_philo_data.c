#include "philo.h" 
#include <stdio.h>

void	print_philo_data(t_pdata data)
{
	if (data.error == true)
	{ 		
		printf("error = true\n"); 
		return ;
	}
	else
		printf("error = false\n");
	printf("die_time = %u\n", data.die_time);
	printf("sleep_time = %u\n", data.sleep_time);
	printf("eat_time = %u\n", data.eat_time);
	printf("philo_nbr = %u\n", data.philo_nbr);
	printf("meal_nbr = %u\n", data.meal_nbr);
}
