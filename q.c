#include <stdio.h>
#include <stdlib.h>

struct q_t {

	int data;
	struct q_t *next;
};

struct qm_t {

	struct q_t 		*qh;
	struct q_t 		*qt;
};


int add_q(int data, struct qm_t *m)
{
	struct q_t *n, *aq;
	
	n = malloc(sizeof(struct q_t));
	
	if (!m->qh) {
		m->qh = n;
		m->qt = n;
		
		n->next = NULL;
		n->data = data;
		
	} else {
	
		m->qt->next = n;
		n->data = data;
		m->qt = n;
	
	}
}

int get_q(int *data, struct qm_t *m)
{
	struct q_t *dq;
	
	if (m->qh) {
		*data = m->qh->data;
		dq = m->qh;
		m->qh = m->qh->next;
		free(dq);
		
		if (m->qh == NULL) {
			m->qt = NULL;
		}
			
		return 1;
	}
	
	return 0;

}

int main(int argc, char *argv[])
{
	int k;
	int ret;
	
	struct qm_t mq;
	
	mq.qh = NULL;
	mq.qt = NULL;

	add_q(33, &mq);
	
	printf("%p, %p\n", mq.qh, mq.qt);
	add_q(44, &mq);
	printf("%p, %p\n", mq.qh, mq.qt);
	
	add_q(55, &mq);
	printf("%p, %p\n", mq.qh, mq.qt);
	
	get_q(&ret, &mq);
	printf("%p, %p\n", mq.qh, mq.qt);
	printf("%d\n", ret);
	
	get_q(&ret, &mq);
	printf("%p, %p\n", mq.qh, mq.qt);
	printf("%d\n", ret);
	
	
	get_q(&ret, &mq);
	printf("--%p, %p\n", mq.qh, mq.qt);
	printf("%d\n", ret);
	
	
	
	add_q(66, &mq);
	
	get_q(&ret, &mq);
	printf("--%p, %p\n", mq.qh, mq.qt);
		
	printf("%d\n", ret);

	int yy = get_q(&ret, &mq);
	printf("--%p, %p, %d\n", mq.qh, mq.qt, yy);
	
//	printf("ql = %d\n", get_qlen(&mq));
	
	exit(0);

}

	
