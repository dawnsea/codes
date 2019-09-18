#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct q_t {

	int data;
	struct q_t *next;
};

struct q_t *init_q(void)
{
	struct q_t *qhead = malloc(sizeof(struct q_t));
	
	return qhead;
}

int add_q(int data, struct q_t **qhead)
{
	struct q_t *qp;
	
	qp = *qhead;
	
	while(qp->next) {
		qp = qp->next;
	};
	
	qp->next = malloc(sizeof(struct q_t));
	memset(qp->next, 0, sizeof(struct q_t));
	
	qp->next->data = data;
}

int get_q(int *data, struct q_t **qhead)
{
	struct q_t *del_q;
	
	if ((*qhead)->next) {
	
		*data = (*qhead)->next->data;
	
		del_q = *qhead;
		*qhead = (*qhead)->next;
	
		free(del_q);
		return 1;
	}
	
	return 0;

}

int get_qlen(struct q_t **qhead)
{
	int len = 0;
	
	struct q_t *qp;
	
	qp = *qhead;
	
	while(qp->next) {
		qp = qp->next;
		len++;
	}
	
	return len;
}


int main(int argc, char *argv[])
{
	struct q_t *qhead;
	int k;
	int ret;

	qhead = init_q();
	
		
	add_q(33, &qhead);
	printf("ql = %d\n", get_qlen(&qhead));
	add_q(44, &qhead);
	printf("ql = %d\n", get_qlen(&qhead));
	
	if (get_q(&ret, &qhead)) {
		printf("--%d\n", ret);
		printf("ql = %d\n", get_qlen(&qhead));
	}

	if (get_q(&ret, &qhead)) {
		printf("--%d\n", ret);
		printf("ql = %d\n", get_qlen(&qhead));
	}
	
	if (get_q(&ret, &qhead)) {
		printf("--%d\n", ret);
		printf("ql = %d\n", get_qlen(&qhead));
	}
		
	add_q(55, &qhead);
	printf("ql = %d\n", get_qlen(&qhead));
		
	add_q(66, &qhead);
	printf("ql = %d\n", get_qlen(&qhead));		
	

	if (get_q(&ret, &qhead)) {
		printf("--%d\n", ret);
		printf("ql = %d\n", get_qlen(&qhead));
	}

	
}

	
