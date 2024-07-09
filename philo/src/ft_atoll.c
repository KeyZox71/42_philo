/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 17:29:13 by adjoly            #+#    #+#             */
/*   Updated: 2024/07/08 17:29:15 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long long	ft_atoll(const char	*nptr)
{
	char		sign;
	long long	nbr;

	sign = 1;
	nbr = 0;
	while ((*nptr >= 7 && *nptr <= 13) || *nptr == 32)
		nptr++;
	if (*nptr == '-')
	{
		sign *= -1;
		nptr++;
	}
	else if (*nptr == '+')
		nptr++;
	while (*nptr >= '0' && *nptr <= '9')
	{
		nbr = nbr * 10 + (*nptr - '0');
		nptr++;
	}
	return (nbr * sign);
}
