// gcc -o test rbtree.o rbtree_util.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "rbtree.h"

#define TRUE	1
#define FALSE	0

#define offsetof(TYPE, MEMBER) ((size_t) &((TYPE *)0)->MEMBER)

#define container_of(ptr, type, member) ({          \
 const typeof( ((type *)0)->member ) *__mptr = (ptr);    \
 (type *)( (char *)__mptr - offsetof(type,member) );}) 

#define KEY_LEN_MAX	255
#define DATA_LEN_MAX 255

struct mytype {
	struct rb_node node;
	char keystring[100];
	char valuestring[100];
};


struct rb_root mytree = RB_ROOT;


struct mytype *my_search(struct rb_root *root, char *string)
{
	struct rb_node *node;
	struct mytype *data;
	int result;

	node = root->rb_node;

	while (node) {
		data = container_of(node, struct mytype, node);

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


int my_insert(struct rb_root *root, struct mytype *data)
{
	struct rb_node **new, *parent;
	struct mytype *this;
	
	int result;

	new = &(root->rb_node);
	parent = NULL;


	while (*new) {
		this = container_of(*new, struct mytype, node);
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

int ez_insert(const char *key, const char *value)
{
	struct mytype *data;
	int key_len, value_len;
	
	if (key == NULL || value == NULL) 
		return 0xF0000011;
	
	data = malloc(sizeof(struct mytype));
	if (!data) 
		return 0xF0000010;
	
	key_len = strnlen(key, KEY_LEN_MAX);
	if (!key_len) 
		return 0xF0000001;

 	strncpy(data->keystring, key, key_len);

	
	value_len = strnlen(value, DATA_LEN_MAX);
	if (!value_len) 
		return 0xF0000004;
		
	strncpy(data->valuestring, value, value_len);		
	
	my_insert(&mytree, data);
	
	return 0; // 성공
	
}

int ez_erase(const char *key)
{

	struct mytype *data;
		
	data = my_search(&mytree, (char *)key);

	if (data) {
		rb_erase(&data->node, &mytree);
//		free(data->keystring);
//		free(data->valuestring);
        free(data);
	}
}


int main (int argc, char *argv[])
{
	
	struct mytype *find;
	
	long i;
	char temp_buf[100];
	char temp_value[100];
	
	printf("program start!\n");

	
	for (i = 0; i < 10000000; i++) {
		sprintf(temp_buf, "aaa%8ld", i);
		sprintf(temp_value, "value%8ld", i);
		ez_insert((char *)temp_buf, (char *)temp_value);
	}
	
	for (i = 0; i < 10000000; i++) {
		sprintf(temp_buf, "aaa%8ld", i);
		ez_erase((char *)temp_buf);
	}	

		
/*	
	
	ez_insert("bbb", "456");

	find = my_search(&mytree, "aaa");
	if (find == NULL) {
		printf("not find\n");
	} else {
		printf("find value = %s\n", find->valuestring);
	}
	
	find = my_search(&mytree, "bbb");
	if (find == NULL) {
		printf("not find\n");
	} else {
		printf("find value = %s\n", find->valuestring);
	}
	
	ez_erase("aaa");
	
	find = my_search(&mytree, "aaa");
	if (find == NULL) {
		printf("not find\n");
	} else {
		printf("find value = %s\n", find->valuestring);
	}
	
	find = my_search(&mytree, "bbb");
	if (find == NULL) {
		printf("not find\n");
	} else {
		printf("find value = %s\n", find->valuestring);
	}	
*/
	exit(0);
}

