#include <stdio.h>
#include "LC3parser.h"

int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		printf("Usage: %s <inputfile.asm>\n", argv[0]);
		return 1;
	}

	parse_source_file(argv[1]);
	return 0;
}
