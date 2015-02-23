#include <stdio.h>
#include <uuid/uuid.h>



int main(int argc, char *argv[])
{

	FILE *ff;
	int i = 0;
	uuid_t uuid;
	char uuid_str[37];      


	ff = fopen("./my_data.dat", "wb");
	
	for (i = 0; i < 100000; i++) {
		uuid_generate_time_safe(uuid);
        uuid_unparse_lower(uuid, uuid_str);
        
		fprintf(ff, "age=%10d, uuid=%s, rank=%c\n", random(), uuid_str, (char)((random() % 10L) + 'a'));
		
	}
	fclose(ff);

}
