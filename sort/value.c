#include "stack.h"

int	value(t_pile *pile, int n)
{
	int	i;

	i = pile->top;
	while (--n > 0)
		i = next_down(pile, i);
	return (pile->array[i]);
}
