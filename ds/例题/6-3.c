#include <stdio.h>
void Towers(int n, char fromPeg, char toPeg, char auxPeg)
{
	if(n == 1)
	{
		printf("%s%c%s%c\n", "move disk 1 from peg ", fromPeg, "to peg ", toPeg);
		return;
	}
	Towers(n - 1, fromPeg, auxPeg, toPeg);
	printf("%s%c%s%c\n", "move disk 1 from peg ", fromPeg, "to peg ", toPeg);
	Towers(n - 1, auxPeg, toPeg, fromPeg);
}

void main()
{
	Towers(4, 'A', 'C', 'B');
}
