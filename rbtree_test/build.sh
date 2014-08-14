#/bin/sh
rm *.o
gcc -c rbtree.c
gcc -c rbtree_util.c
gcc -o test rbtree.o rbtree_util.o
echo hello world

