#include "c_p_algo.h"

void	test1(t_data *a_start, t_data *b_start)
{
	command_solo_s(&a_start);
	printf("sa\n");
	print_data(a_start, b_start);
	printf("\n\n");
	printf("pa\n");
	command_solo_p(&b_start, &a_start);
	print_data(a_start, b_start);
	printf("\n\n");
	printf("pa\n");
	command_solo_p(&b_start, &a_start);
	print_data(a_start, b_start);
	printf("\n\n");
	printf("pa\n");
	command_solo_p(&b_start, &a_start);
	print_data(a_start, b_start);
	printf("\n\n");
	printf("pb\n");
	command_solo_p(&a_start, &b_start);
	print_data(a_start, b_start);
	printf("\n\n");
	printf("pb\n");
	command_solo_p(&a_start, &b_start);
	print_data(a_start, b_start);
	printf("\n\n");
	command_solo_s(&b_start);
	printf("sb\n");
	print_data(a_start, b_start);
	printf("\n\n");
	printf("pb\n");
	command_solo_p(&a_start, &b_start);
	print_data(a_start, b_start);
	printf("\n\n");
	printf("pb\n");
	command_solo_p(&a_start, &b_start);
	print_data(a_start, b_start);
	printf("\n\n");
	command_solo_s(&b_start);
	printf("sb\n");
	print_data(a_start, b_start);
	printf("\n\n");
	printf("pb\n");
	command_solo_p(&a_start, &b_start);
	print_data(a_start, b_start);
	printf("\n\n");
	printf("pa\n");
	command_solo_p(&b_start, &a_start);
	print_data(a_start, b_start);
	printf("\n\n");
	command_solo_s(&b_start);
	printf("sb\n");
	print_data(a_start, b_start);
	printf("\n\n");
	printf("pa\n");
	command_solo_p(&b_start, &a_start);
	print_data(a_start, b_start);
	printf("\n\n");
}

void	test2(t_data *a_start, t_data *b_start)
{
	printf("ra\n");
	command_solo_r(&a_start);
	print_data(a_start, b_start);
	printf("\n\n");

	printf("rb\n");
	command_solo_r(&b_start);
	print_data(a_start, b_start);
	printf("\n\n");

	printf("pb\n");
	command_solo_p(&a_start, &b_start);
	print_data(a_start, b_start);
	printf("\n\n");

	printf("ra\n");
	command_solo_r(&a_start);
	print_data(a_start, b_start);
	printf("\n\n");


	printf("pb\n");
	command_solo_p(&a_start, &b_start);
	print_data(a_start, b_start);
	printf("\n\n");

	printf("ra\n");
	command_solo_r(&a_start);
	print_data(a_start, b_start);
	printf("\n\n");
	printf("rb\n");
	command_solo_r(&b_start);
	print_data(a_start, b_start);
	printf("\n\n");

	printf("pa\n");
	command_solo_p(&b_start, &a_start);
	print_data(a_start, b_start);
	printf("\n\n");
	printf("ra\n");
	command_solo_r(&a_start);
	print_data(a_start, b_start);
	printf("\n\n");
	printf("rb\n");
	command_solo_r(&b_start);
	print_data(a_start, b_start);
	printf("\n\n");
	printf("pb\n");
	command_solo_p(&a_start, &b_start);
	print_data(a_start, b_start);
	printf("\n\n");
	printf("pb\n");
	command_solo_p(&a_start, &b_start);
	print_data(a_start, b_start);
	printf("\n\n");
		printf("rb\n");
	command_solo_r(&b_start);
	print_data(a_start, b_start);
	printf("\n\n");printf("rb\n");
	command_solo_r(&b_start);
	print_data(a_start, b_start);
	printf("\n\n");
}

void	test3(t_data *a_start, t_data *b_start)
{

	printf("rra\n");
	command_solo_rr(&a_start);
	print_data(a_start, b_start);
	printf("\n\n");

	printf("rra\n");
	command_solo_rr(&a_start);
	print_data(a_start, b_start);
	printf("\n\n");


	printf("rra\n");
	command_solo_rr(&a_start);
	print_data(a_start, b_start);
	printf("\n\n");


	printf("rra\n");
	command_solo_rr(&a_start);
	print_data(a_start, b_start);
	printf("\n\n");


	printf("rra\n");
	command_solo_rr(&a_start);
	print_data(a_start, b_start);
	printf("\n\n");


	printf("rra\n");
	command_solo_rr(&a_start);
	print_data(a_start, b_start);
	printf("\n\n");


	printf("rra\n");
	command_solo_rr(&a_start);
	print_data(a_start, b_start);
	printf("\n\n");


	printf("rra\n");
	command_solo_rr(&a_start);
	print_data(a_start, b_start);
	printf("\n\n");


	printf("rra\n");
	command_solo_rr(&a_start);
	print_data(a_start, b_start);
	printf("\n\n");


	printf("rra\n");
	command_solo_rr(&a_start);
	print_data(a_start, b_start);
	printf("\n\n");

	printf("rrb\n");
	command_solo_rr(&b_start);
	print_data(a_start, b_start);
	printf("\n\n");

	printf("rrb\n");
	command_solo_rr(&b_start);
	print_data(a_start, b_start);
	printf("\n\n");


	printf("rrb\n");
	command_solo_rr(&b_start);
	print_data(a_start, b_start);
	printf("\n\n");


	printf("rrb\n");
	command_solo_rr(&b_start);
	print_data(a_start, b_start);
	printf("\n\n");


	printf("rrb\n");
	command_solo_rr(&b_start);
	print_data(a_start, b_start);
	printf("\n\n");


	printf("rrb\n");
	command_solo_rr(&b_start);
	print_data(a_start, b_start);
	printf("\n\n");


	printf("rrb\n");
	command_solo_rr(&b_start);
	print_data(a_start, b_start);
	printf("\n\n");


}
