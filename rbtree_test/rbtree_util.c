// gcc -o test rbtree.o rbtree_util.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "rbtree.h"
#include "rbtree_util.h"

#define TRUE	1
#define FALSE	0

#define offsetof(TYPE, MEMBER) ((size_t) &((TYPE *)0)->MEMBER)

#define container_of(ptr, type, member) ({          \
 const typeof( ((type *)0)->member ) *__mptr = (ptr);    \
 (type *)( (char *)__mptr - offsetof(type,member) );}) 

#define KEY_LEN_MAX	255
#define DATA_LEN_MAX 255

struct rb_root keeptalk_tree = RB_ROOT;

struct rb_root *root = &keeptalk_tree;

struct keeptalk_node *keeptalk_search(char *string)
{
	struct rb_node *node;
	struct keeptalk_node *data;
	int result;

	node = root->rb_node;

	while (node) {
		data = container_of(node, struct keeptalk_node, node);

		result = strncmp(string, data->keystring, KEY_LEN_MAX);

		if (result < 0) {
			node = node->rb_left;
		} else if (result > 0) {
			node = node->rb_right;
		} else {
			return data;
		}
	}
	return NULL;
}


int keeptalk_insert(struct keeptalk_node *data)
{
	struct rb_node **new, *parent;
	struct keeptalk_node *this;
	
	int result;

	new = &(root->rb_node);
	parent = NULL;


	while (*new) {
		this = container_of(*new, struct keeptalk_node, node);
		result = strncmp(data->keystring, this->keystring, KEY_LEN_MAX);

		parent = *new;
		
		if (result < 0) {
			new = &((*new)->rb_left);
		} else if (result > 0) {
			new = &((*new)->rb_right);
		} else {
			return FALSE;
		}

       }

	/* Add new node and rebalance tree. */
	
	rb_link_node(&data->node, parent, new);
	rb_insert_color(&data->node, root);

	return TRUE;
}

int keeptalk_put(const char *key, const char *value)
{
	struct keeptalk_node *data;
	int key_len, value_len;
	
	if (key == NULL || value == NULL) 
		return 0xF0000011;
	
	data = malloc(sizeof(struct keeptalk_node));
	if (!data) 
		return 0xF0000010;
	
	key_len = strnlen(key, KEY_LEN_MAX);
	if (!key_len) 
		return 0xF0000001;

	data->keystring = (char *)malloc(key_len);
	if (!data->keystring) 
		return 0xF0000002;
		
//	printf("addr = %lx\n", (long)(data->keystring));
 
 	strncpy(data->keystring, key, key_len);
	
	value_len = strnlen(value, DATA_LEN_MAX);
	if (!value_len) 
		return 0xF0000004;
		
	data->valuestring = (char *)malloc(100);
	if (!data->valuestring)
		return 0xF0000008;
 
	strncpy(data->valuestring, value, value_len);		
	
	keeptalk_insert(data);
	
	return 0; // 성공
	
}

int keeptalk_erase(const char *key)
{

	struct keeptalk_node *data;
		
	data = keeptalk_search((char *)key);

	if (data) {
		
		rb_erase(&data->node, root);
		free(data->keystring);
		free(data->valuestring);
        free(data);
        
	} else {
		return FALSE;
	}
	
	return TRUE;
}

int ez_find(const char *key)
{

	struct keeptalk_node *data;
		
	data = keeptalk_search((char *)key);

}


int main (int argc, char *argv[])
{
	
	struct keeptalk_node *find;
	
	long i;
	char temp_buf[100];
	char temp_value[100];
	
	printf("program start! = %ld\n", sizeof(struct keeptalk_node));

	
	for (i = 0; i < 10000000; i++) {
		sprintf(temp_buf, "aaa%8ld", i);
		sprintf(temp_value, "value%8ld", i);
		keeptalk_put((char *)temp_buf, (char *)temp_value);
	}
	
	for (i = 0; i < 10000000; i++) {
		sprintf(temp_buf, "aaa%8ld", i);
		keeptalk_erase((char *)temp_buf);
	}	

		
/*	
	
	keeptalk_put("bbb", "456");

	find = keeptalk_search(&mytree, "aaa");
	if (find == NULL) {
		printf("not find\n");
	} else {
		printf("find value = %s\n", find->valuestring);
	}
	
	find = keeptalk_search(&mytree, "bbb");
	if (find == NULL) {
		printf("not find\n");
	} else {
		printf("find value = %s\n", find->valuestring);
	}
	
	keeptalk_erase("aaa");
	
	find = keeptalk_search(&mytree, "aaa");
	if (find == NULL) {
		printf("not find\n");
	} else {
		printf("find value = %s\n", find->valuestring);
	}
	
	find = keeptalk_search(&mytree, "bbb");
	if (find == NULL) {
		printf("not find\n");
	} else {
		printf("find value = %s\n", find->valuestring);
	}	
*/
	exit(0);
}

