
// gcc -o apr_test apr_test.c -I/usr/local/apache2/include/ -I/usr/local/apache2/include -lapr-1 -L/usr/local/apache2/lib -lmemcached



#include <stdio.h>
#include <stdlib.h>

#include "apr.h"
#include "apr_lib.h"
#include "apr_strings.h"

#include "apr_pools.h"
#include "apr_errno.h"

#include "libmemcached/memcached.h"


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


memcached_st *memc_open(void)
{
	memcached_server_st *servers = NULL;
	memcached_st *memc;
	memcached_return rc;
	
	memc = memcached_create(NULL);

	servers = memcached_server_list_append(servers, "localhost", 11211, &rc);
	rc = memcached_server_push(memc, servers);

	if (rc == MEMCACHED_SUCCESS)
		printf("Added server successfully\n");
	else
		printf("Couldn't add server: %s\n",memcached_strerror(memc, rc));
		
	memcached_server_list_free(servers);
		
	return memc;
 	
	
}



int main(int argc, char *argv[])
{
	apr_pool_t *p;
	apr_status_t ret;
	char *t;
	const char *getv;
	size_t vlen;
	memcached_st *memc;
	memcached_return rc;
	
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
	
	
	memc = memc_open();
	
	rc = memcached_set(memc, "hell", 4, "world", 5, (time_t)0, (uint32_t)0);
	
	
	
	getv = memcached_get(memc, "hell", 4, &vlen, NULL, NULL);
	
	
	t = apr_psprintf(p, "%s, %d\n", getv, 4885);
	
	printf("t = %s\n", t);
		
	
	memcached_free(memc);
	
	apr_pool_destroy(p);
	
	apr_close();
	
	exit(0);
}

