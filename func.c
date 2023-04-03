#include <stdio.h>
/**/
void header_func(FILE* c_file, FILE* f) {
	int s = 0;
	char str[255];
	char* triggers[] = { "void", "int", "char", "long", "short", "double", "float", "struct" };
	char* no_func[] = { "main", "for", "while", "\"", "//", ";"};
	fprintf(f, "#pragma once\n");
	while (!feof(c_file)) {
	next:
		s = 0;
		fgets(str, 255, c_file);
		for (int i = 0; i < 8; i++) {
			if (find_v2(str, triggers[i])) {
				for (int i = 0; i < 6; i++) {
					s += no_func_check(str, no_func[i]);
				}
				if (s == 0) {
					if (symbol_check(str)) {
						printf("%s", str);
						fprintf(f, "%s", str);
						break;
					}
					else {
						printf("%s", str);
						fprintf(f, "%s", str);
						for (int i = 0; str[i] != '\0'; i++) {
							fgets(str, 255, c_file);
							if (!(symbol_check(str))) {
								printf("%s", str);
								fprintf(f, "%s", str);
							}
							else {
								printf("%s", str);
								fprintf(f, "%s", str);
								goto next;
							}
						}

					}
				}
				else break;
			}
		}
	}
}


int symbol_check(char str[]) {
	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] == '{') {
			str[i] = ';';
			return 1;
		}
	}
	return 0;
}

int no_func_check(char str[], char no_func[]) {
	int count = 0, count2 = 0, count3 = 4, w = 0;

	for (int i = 0; no_func[i] != '\0'; i++) {
		count++;
	}

		for (int i = 0, j = 0; str[i] != '\0'; i++) {
			if (str[i] == no_func[j]) {
				for (int k = 0, m = i; k < count; k++, m++) {
					if (str[m] == no_func[k]) {
						count2++;
					}
				}
				if (count == count2) {
					return 1;
				}
				else count2 = 0;
			}
		}
		return 0;
	}

int find_v2(char str[], char ptr[]) {
	int count = 0, count2 = 0;

	for (int i = 0; ptr[i] != '\0'; i++)
		count++;

	for (int i = 0, j = 0; str[i] != '\0'; i++) {
		if (str[i] == ptr[j]) {
			for (int k = 0, m = i; k < count; k++, m++) {
				if (str[m] == ptr[k]) {
					count2++;
				}
			}
			if (count == count2) {
				return 1;
			}
			else
				goto end;
		}
		else
			count2 = 0;
	}
end:
	return 0;
}




/*
int find(char str[], char ptr[]) {
	char* no_func[] = {"main", "for", "while", "\""};
	int count = 0, count2 = 0, symbol = 0, s = 0;

	for (int i = 0; ptr[i] != '\0'; i++)
		count++;

	if (symbol_check(str)) {
		for (int i = 0, j = 0; str[i] != '\0'; i++) {
			if (str[i] == ptr[j]) {
				for (int k = 0, m = i; k < count; k++, m++) {
					if (str[m] == ptr[k]) {
						count2++;
					}
				}
				if (count == count2) {
					for (int h = 0; h < 4; h++)
						s += no_func_check(str, no_func[h]);
					if (s == 0) {
						for (int q = 0; str[q] != '\0'; q++) {
							if (str[q] == '{') {
								str[q] = ';';
							}
						}
						return 1;
					}
					else goto end;
				}
				else
					count2 = 0;
			}
		}
	}
	end:
	return 0;
}

int find_v2(char str[], char ptr[]) {
	int count = 0, count2 = 0;

	for (int i = 0; ptr[i] != '\0'; i++)
		count++;

		for (int i = 0, j = 0; str[i] != '\0'; i++) {
			if (str[i] == ptr[j]) {
				for (int k = 0, m = i; k < count; k++, m++) {
					if (str[m] == ptr[k]) {
						count2++;
					}
				}
				if (count == count2) {
					return 1;
				}
				else
					goto end;
			}
			else
				count2 = 0;
		}
	end:
	return 0;
}*/