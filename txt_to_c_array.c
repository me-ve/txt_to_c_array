#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#define ARRAY_TYPE_INDEX 3
#define ARRAY_NAME_INDEX 4

int main(int argc, char **argv){
	if(argc != 5){
		fprintf(stderr, "Usage: %s <input> <output> <array_type> <array_name>\n", argv[0]);
		return ENOTSUP;
	}
	FILE *input = fopen(argv[1], "r");
	if(input == NULL){
		fprintf(stderr, "File %s doesn't exist.\n", argv[1]);
		return ENOENT;
	}
	FILE *output = fopen(argv[2], "w");
	if(output == NULL){
		fprintf(stderr, "File %s cannot be created.\n", argv[2]);
		return EIO;
	}
	char *line = NULL;
	char *c = NULL;
	size_t len = 0;
	ssize_t read;
	fprintf(output, "%s %s[] = {\n", argv[ARRAY_TYPE_INDEX], argv[ARRAY_NAME_INDEX]);
	while((read = getline(&line, &len, input) != -1)){
		c = strchr(line, '\n');
		if(c){
			*c = ',';
		}
		fprintf(output, "\t%s\n", line);
	}
	free(line);
	fprintf(output, "};\n");
	fclose(input);
	fclose(output);
	return 0;
}
