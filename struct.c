/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumjo <sumjo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 19:04:51 by sumjo             #+#    #+#             */
/*   Updated: 2023/07/14 21:35:21 by sumjo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct _stack{
    int value;
    st *next;
    st *prev;
}st;

typedef struct _headTail{
    int size;
    stack *top;
    stack *bottom;
}stack;


