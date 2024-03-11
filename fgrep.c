#include <stdio.h>

int
main(void)
{
	// Rule: no '\n' in the search string
	char needle[] = "bash";

	int c;
	int i = 0;
	int proceed_to_nl = 0;	// bool
	char line[1024] = {};
	size_t n = 0;

	while ((c = getchar()) != EOF) {

		if (n >= sizeof (line))
			return 1;

		line[n++] = c;

		if (c == '\n') {
#ifdef DEBUG
			printf("DEBUG: line: %s", line);
#endif
			if (proceed_to_nl) {
				line[n] = '\0';	// Bug. Can you spot it ?
				printf("%s", line);
				proceed_to_nl = 0;
			}
			n = 0;
			continue;
		}

		if (c == needle[i]) {
#ifdef DEBUG
			printf("DEBUG: got match (%c) at %zu\n", c, n);
#endif
			i++;
			if (i == (sizeof (needle) - 1)) {
#ifdef DEBUG
				printf("DEBUG: whole needle\n");
#endif
				proceed_to_nl = 1;
				i = 0;
			}
		} else {
			i = 0;
		}
	}
}
