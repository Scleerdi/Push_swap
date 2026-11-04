/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: sicleerd <sicleerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/10/30 13:54:41 by sicleerd      #+#    #+#                 */
/*   Updated: 2026/11/04 17:33:56 by sicleerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

typedef struct s_stack
{
	int				data;
	int				index;
	struct s_stack	*next;
}					t_stack;

typedef struct s_stacks
{
	int				size_a;
	int				size_b;
	t_stack			*a;
	t_stack			*b;
}					t_stacks;

# define OP_COUNT 11

typedef enum e_op
{
	e_sa,
	e_sb,
	e_ra,
	e_rb,
	e_rra,
	e_rrb,
	e_pa,
	e_pb,
	e_ss,
	e_rr,
	e_rrr,
}					t_op;

typedef void	(*t_operation)(t_stacks *);

int					push_swap(t_stacks *ab, int alg, double d);
int					sorted(t_stacks *ab);
int					stack_sorted(t_stack **stack);
int					arg_check(t_stack *a, char *str);
int					alg_check(char *str);
int					find_min(t_stack *stack);
int					find_min_position(t_stack *stack);
int					error_delete_all(t_stacks *ab);
int					value_exists(t_stack *a, int data);
char				*read_line(int fd);
void				execute(t_stacks *ab, t_op operation);
void				execute_c(t_stacks *ab, t_op operation);
void				del_stacks(t_stack **astack_a, t_stack **astack_b);
void				dup_stack(t_stacks const *ab, t_stacks *dup_ab);
void				printstacks(t_stacks *ab);
void				normalize(t_stack *a);
void				push_a(t_stacks *ab);
void				push_b(t_stacks *ab);
void				swap_a(t_stacks *ab);
void				swap_b(t_stacks *ab);
void				rotate_b(t_stacks *ab);
void				rotate_a(t_stacks *ab);
void				reverse_rotate_a(t_stacks *ab);
void				reverse_rotate_b(t_stacks *ab);
void				ss(t_stacks *ab);
void				rr(t_stacks *ab);
void				rrr(t_stacks *ab);
void				chunk_sort(t_stacks *ab);
void				move_min_to_top(t_stacks *ab);
void				push_min_to_b(t_stacks *ab);
void				sort_three(t_stacks *ab);
void				sort_simple(t_stacks *ab);
double				compute_disorder(t_stacks *ab);
t_stack				*create_node(int data);
void				push_stack(t_stack **dst, t_stack **src);

#endif