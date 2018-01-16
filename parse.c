#include <stdio.h>
#include <string.h>
int main () {
	FILE *fp;
	FILE *out;
	FILE *listFile;
	char read = 'r';
	char write = 'w';
	out = fopen ("output_1", &write);
	fp = fopen("output", &read);
	listFile = fopen ("list", &read);

	char buffer[256];
	char string[17];
	char addr[17];
	char* line;
	line = fgets(buffer, 256, fp);
	line = fgets (buffer, 256, fp);
	if (line == NULL) {
		printf("this bluetooth devide is not found!\n");
		return 0;
	}


	while(line){

		char* str = line + 1;
		//printf("str: %s\n", str);
		strncpy (string, str, 17);
		//printf("current string is: %s\n", string);	
		int result = strncmp(string, "DC:0C:5C:C1:24:D", 15);
		//printf("compare result: %d\n", result);
		if (result == 0) {
			printf("found device in C file\n");
			fprintf(out, "%d", 1);
			break;
		}	
		line = fgets(buffer, 256, fp);
	}
	fclose(fp);
	fclose(out);
	fclose(listFile);
	return 0;
}
