/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coords.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchokri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 16:23:43 by lchokri           #+#    #+#             */
/*   Updated: 2022/11/12 18:44:24 by lchokri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "coords.h"
#include "../src/include/miniRT.h"

void  tuple_type(struct coords cd)
{
    if (cd.w == 1)
      printf("tuple is a point\n");
    else if (!cd.w)
      printf("tuple is a vector\n");
    else
      printf("this shit ain't a thing\n");
}

cdr addition(struct tuples tps)
{
  cdr ret;

  ret.x = tps.cdr_1->x + tps.cdr_2->x;
  ret.y = tps.cdr_1->y + tps.cdr_2->y;
  ret.z = tps.cdr_1->z + tps.cdr_2->z;
  ret.w = tps.cdr_1->w + tps.cdr_2->w;
  tuple_type(ret);

  return (ret);
}

cdr substraction(struct tuples tps)
{
  cdr ret;

  ret.x = tps.cdr_1->x - tps.cdr_2->x;
  ret.y = tps.cdr_1->y - tps.cdr_2->y;
  ret.z = tps.cdr_1->z - tps.cdr_2->z;
  ret.w = tps.cdr_1->w - tps.cdr_2->w;
  tuple_type(ret);
  return (ret);
}

float magnitude(cdr cd)
{
  return (sqrt(pow(cd.x, 2) + pow(cd.y, 2) + pow(cd.z, 2)));
}

cdr normalized_vec(cdr vec)
{
  float mag;
  cdr ret;

  mag = magnitude(vec);
  ret.x = vec.x / mag;
  ret.y = vec.y / mag;
  ret.z = vec.z / mag;
  return (ret);
}


int main()
{
  cdr cd1;
  cdr cd2;
  tps tuple;

  tuple.cdr_1 = &cd1;
  tuple.cdr_2 = &cd2;

  cd1.x = 1;
  cd1.y = -2.5;
  cd1.z = 3;
  cd1.w = 0;
  
  cd2.x = 1;
  cd2.y = 3;
  cd2.z = 2;
  cd2.w = 1;
 
  cdr returned_point = normalized_vec(cd2);
  printf("the returned pt is : x=%.2f  y=%.2f z=%.2f\n", returned_point.x, returned_point.y, returned_point.z);
 // substraction(tuple);
 // printf("magnitude = %f \n", magnitude(cd2));
}
