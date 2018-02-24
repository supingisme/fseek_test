#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <assert.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/time.h>

static unsigned int GetTimeMSec()
{
	struct timeval tv;
	gettimeofday(&tv, 0);	/* Get system time */
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

int main(int argc, char* argv[])
{
	FILE *fp;
	int size;
	int time_0, time_1;
	
	if(argc<2)
		return -1;
	
	printf("%s \n", argv[1]);
	fp = fopen(argv[1], "rb");
	if(fp)
	{
		printf("start to seek to end \n");
		time_0 = GetTimeMSec();
		fseek(fp, 0, SEEK_END);
		time_1 = GetTimeMSec();
		printf("end to seek to end, time cost %d ms\n", time_1-time_0);
		size = ftell(fp);
		printf("file size: %d \n", size);
		fclose(fp);
	}

	return 0;
}
