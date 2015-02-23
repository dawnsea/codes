/* 출제 : 신진철 매니저

응시 대상 : C/C++ 응시 대상자로 한정함.


다음과 같은 문자열로 구성된 벌크 데이터가 있다.

age=1056799309, uuid=98955660-bb29-11e4-85b7-64e599f47bf6, rank=g

age는 10바이트, uuid는 36바이트, rank는 1바이트이다.
각 공백은 공백문자이며, 문자열의 끝은 \n으로 구분된다.


출제자는 이렇게 구성한 데이터 파일을 제공하며 레코드 수는 10만개이다.

해당 파일에서 rank가 소문자 "g"인 레코드의 age와 uuid를 출력하라.
단, 최대 성능을 고려한다.

각 상수, pre calculation이 필요한 부분은 상수 처리해도 무방하다.
입력 변수에 대한 실행 파라미터 처리는 필요없다.
각종 예외 처리는 무시한다.



note)

먼저 어떻게 풀 것인지를 출제자에게 제안하면 출제자는 해당 api에 대한 명세 또는 예제에 대한 힌트를 줄 수 있다.
(예, man 페이지 또는 코드 조각)


랭킹 구분
S, A (합격)
B, C (불합격)

1) 못 푼경우 : 탈락
2) 파일 시스템 콜을 사용한 경우 B 등급이며 심화 질문에 따라 A등급을 부여할 수 있다.
3) mmap을 이용하여 푼 경우 : A등급
4) mmap과 시스템 콜, 성능 상의 차이점을 설명 가능 : A+등급
5) 기타 자료 구조를 동원한 서칭 알고리즘을 사용 : S등급


*/
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

typedef struct {
	
	char dummy_1[4];
	char age[10];
	char dummy_2[7];
	char uuid[36];
	char dummy_3[7];
	char rank;
	char dummy_4[1];
} my_data_t;


int main(int argc, char *argv[])
{

	int i;
	int fd;
	struct stat sb;
	char *addr;
	char *p;
	char temp[37];
	
	my_data_t *mp;
		
    fd = open("./my_data.dat", O_RDONLY);
    
    fstat(fd, &sb);
        
    addr = mmap(NULL, sb.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
	
	mp = (my_data_t *)addr;

	for (i = 0; i < 100000; i++) {
		
		if (mp->rank == 'g') {
			memcpy(temp, mp->age, 10);
			temp[10] = 0;
			printf("age is %s, ", temp);
			
			memcpy(temp, mp->uuid, 36);
			temp[36] = 0;
			printf("uuid is %s\n", temp);		
		}
		
		mp++;
		
	}
  
	munmap(addr, sb.st_size);
	
	close(fd);
}
