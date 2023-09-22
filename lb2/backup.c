#include <stdio.h>

int main(int argc, char* argv[]){
	if(argc <= 1){
		printf("%s : the wrong file\n", argv[0]);
	}else{
		FILE* f = fopen(argv[1], "r");
		if(f){
			printf("%s: %s file is open\n", argv[0], argv[1]);
			char str[64];
			while(fgets(str, sizeof(str), f)){
				printf("%s", str);
			}
			fclose(f);
		}else{
			printf("%s: %s file not open", argv[0], argv[1]);
		}
	}
	return 0;
}
