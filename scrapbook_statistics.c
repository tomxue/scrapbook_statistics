#include <time.h>
#include <stdio.h>
#include <stdlib.h>
main()
{
	char *wday[]={"Sun","Mon","Tue","Wed","Thu","Fri","Sat"};	
	char myDate[9];
	char myCmd1[57] = "find /mnt/hgfs/Dropbox/ScrapBook/data/ -maxdepth 1 -name ";
	char myCmd2[8] = " | wc -l";
	char myCmd[74];
	time_t timep;
	struct tm *p;

	time(&timep);
	p=gmtime(&timep);
	//printf("%d%.2d%d\n", (1900+p->tm_year), (1+p->tm_mon), p->tm_mday);
	//printf("%d%.2d%d\n", (1900+p->tm_year), (1+p->tm_mon), p->tm_mday - 1);
	sprintf(myDate, "%d%.2d%d", (1900+p->tm_year), (1+p->tm_mon), p->tm_mday);
	myDate[8] = 42;//"*";
	//printf("%s\n", myDate);
	printf("Date: %.8s  - The number of items I learnt is below\n",myDate);
	sprintf(myCmd, myCmd1, myDate, myCmd2);
	system(myCmd);
	//system("find /mnt/hgfs/Dropbox/ScrapBook/data/ -maxdepth 1 -name myDate | wc -l");
	//system("find /mnt/hgfs/Dropbox/ScrapBook/data/ -maxdepth 1 -name \"20110724*\" | wc -l");
	//printf("%s%d;%d;%d\n", wday[p->tm_wday], p->tm_hour, p->tm_min, p->tm_sec);
}
