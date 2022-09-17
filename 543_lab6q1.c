
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int csum; 
void *runner(void *param);
int main(int argc, char *argv[]) {
	pthread_t tid;
	pthread_attr_t attr;
	if (argc != 2) {
		fprintf(stderr, "usage: pthread <integer value>\n");
		exit(1);
	}
	if (atoi(argv[1]) < 0) {
		fprintf(stderr, "number must be >=0\n");
		exit(2);
	}
	pthread_attr_init(&attr);
	pthread_create(&tid, &attr, runner, argv[1]);
	int upper = atoi(argv[1]);
	int msum = 0;
	if (upper > 0) {
		for (int i = 0; i <= upper; ++i) {
			msum += i;
		}
	}
	printf("msum = %d\n", msum);
	//pthread_join(tid, NULL);
	printf("csum = %d\n", csum);
    printf("csum - msum = %d\n", csum-msum);
    //ถ้าแม่ทำเสร็จไวกว่าลูกจะได้ผลต่างเป็น -15 (ในกรณีที่ Input = 5) เพราะว่าลุกทำไม่ทันแต่แม่ปริ้นออกมาก่อน
    //ถ้าลูกทำเสร็จก่อนแม่จะได้ผลต่างเป็น 40 (ในกรณีที่ Input = 5) เพราะลูกทำเสร็จแล้วแม่ก็ทำต่อปริ้นออกมาต่อ
}

void *runner (void *param) {
	int upper = atoi(param);
	csum = 0;
	if (upper > 0) {
		for (int i = 0; i <= upper*2; ++i) {
			csum += i;
		}
	}
	pthread_exit(0);
}