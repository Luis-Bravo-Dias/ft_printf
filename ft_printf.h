/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleiria- <lleiria-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 12:02:45 by lleiria-          #+#    #+#             */
/*   Updated: 2022/01/24 12:16:23 by lleiria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define FT_PRINTF_H

#include "Libft/libft.h"
#include <stdarg.h>
#include <unistd.h>

int	ft_printf(const char *input, ...);

#endif