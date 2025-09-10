#include <stdio.h>

// Add your is_digit implementation here
int	is_digit(const char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (str[i] == '\0')
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	main(void)
{
	const char *tests[] = {
		"42",        // valid
		"-42",       // valid
		"+42",       // valid
		"0",         // valid
		"0001",      // valid
		"",          // invalid: empty
		"+",         // invalid
		"-",         // invalid
		"--3",       // invalid
		"3-4",       // invalid
		"12a",       // invalid
		" 3",        // invalid (leading space)
		"3 ",        // invalid (trailing space)
		"1\t2",      // invalid (tab inside)
		NULL
	};

	int i = 0;
	while (tests[i] != NULL)
	{
		printf("Input: \"%s\" -> %d\n", tests[i], is_digit(tests[i]));
		i++;
	}

	// Explicit NULL test
	printf("Input: NULL -> %d\n", is_digit(NULL));

	return (0);
}
