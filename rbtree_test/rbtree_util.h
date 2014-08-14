#ifndef __rbtree_util_h__
#define __rbtree_util_h__

struct keeptalk_node {
	struct rb_node node;
	char *keystring;
	char *valuestring;
};

struct keeptalk_node *keeptalk_search(char *string);
int keeptalk_insert(struct keeptalk_node *data);
int keeptalk_erase(const char *key);


#endif
