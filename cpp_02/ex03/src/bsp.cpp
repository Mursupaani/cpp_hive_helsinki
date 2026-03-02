/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpollan <anpollan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 13:35:28 by anpollan          #+#    #+#             */
/*   Updated: 2026/02/17 15:17:49 by anpollan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static Fixed cross(Point const u, Point const v)
{
	return (u.getX() * v.getY() - u.getY() * v.getX());
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Point v0 {a};
	Point v1 {b.getX() - a.getX(), b.getY() - a.getY()};
	Point v2 {c.getX() - a.getX(), c.getY() - a.getY()};
	Fixed detV1V2 = cross(v1, v2);

	if (detV1V2 == Fixed(0))
		return (false);
	Point v {point.getX() - a.getX(), point.getY() - a.getY()};
	Fixed detA = cross(v, v2);
	Fixed detB = cross(v, v1) * Fixed(-1);
	Fixed zero = Fixed(0);
	if (detV1V2 > zero)
		return (detA >= zero && detB >= zero && (detA + detB) < detV1V2);
	else
		return (detA <= zero && detB <= zero && (detA + detB) > detV1V2);
}
