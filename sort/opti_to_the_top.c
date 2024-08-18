#include "stack.h"

void	chunk_to_the_top(t_stack *stack, t_chunk *to_sort)
{
	if (to_sort->loc == BOTTOM_B && current_size(&stack->b) == to_sort->size)
		to_sort->loc = TOP_B;
	if (to_sort->loc == BOTTOM_A && current_size(&stack->a) == to_sort->size)
		to_sort->loc = TOP_A;
}

void	easy_sort(t_stack *stack, t_chunk *to_sort)
{
	while (to_sort->loc != TOP_A && to_sort->size) /* Mientras loc no sea TOP_A y haya algo en el chunk */
	{}
}