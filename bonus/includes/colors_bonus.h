/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 10:09:21 by dcaetano          #+#    #+#             */
/*   Updated: 2026/09/07 15:53:32 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "../includes/tester_bonus.h"

#define RESET "\033[0m"
#define BOLD "\033[1m"

#define RGB(r, g, b) "\033[38;2;" #r ";" #g ";" #b "m"

#define CTEXT(text, color) RESET color text RESET
