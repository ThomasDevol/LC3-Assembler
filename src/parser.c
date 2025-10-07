#include <stdio.h>

void parse_source_file(const char *filename)
{
	// create pointer to file imported
	FILE *file_pointer = fopen(filename, "r");

	// NULL protection
	if (file_pointer == NULL)
	{
		printf("Error: Invalid, unable to open file %s\n", filename);
		return;
	}

	// declare buffer
	char line[256];
	while (fgets(line, sizeof(line), file_pointer) != NULL)
	{
		int len = sizeof(line);
		int out_line = 0;
		int i = 0; // tracks the index within the line

		while (line[i] == ' ' || line[i] == '\t')
		{
			i++;
		} // skip the rest if it is null or the termination char is found

		if (line[i] == '\0' || line[i] == ';')
		{
			continue;
		}

		for (int i = 0; line[i] != '\0'; i++)
		{ // semicolon dictates if an entire line is done (with a comment it ends immediately)
			if (line[i] == ';')
			{
				break;
			} // ignores EMBEDED spaces and tabs (forgor how to spell)
			if (line[i] != ' ' && line[i] != '\t')
			{
				printf("%c", line[i]);
				out_line = 1;
			}
		}
		if (out_line)
		{
			putchar('\n');
		}
	}
	fclose(file_pointer);
}
