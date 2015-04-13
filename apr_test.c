
// gcc -o apr_test apr_test.c -I/usr/local/apache2/include/ -I/usr/local/apache2/include -lapr-1 -L/usr/local/apache2/lib



#include <stdio.h>
#include <stdlib.h>

#include "apr.h"
#include "apr_lib.h"
#include "apr_strings.h"

#include "apr_pools.h"
#include "apr_errno.h"


int apr_open(void)
{
	apr_status_t ret;
	
	ret = apr_pool_initialize();
	
	return ret;
	
}



void apr_close(void)
{
	apr_pool_terminate();
	
}



int main(int argc, char *argv[])
{
	apr_pool_t *p;
	apr_status_t ret;
	char *t;
	
	printf("hello world\n");
	
	ret = apr_open();
	
	if (ret) {
		printf("apr_open error\n");
		exit(1);
	}
	
	ret = apr_pool_create(&p, NULL);
	
	if (ret) {
		printf("pool create error\n");
		exit(1);		
	}
	
	
	
	t = apr_psprintf(p, "%s, %d\n", "helllllll! world!", 4885);
	
	printf("t = %s\n", t);
	
	
	
	apr_pool_destroy(p);
	
	apr_close();
	
	exit(0);
}

