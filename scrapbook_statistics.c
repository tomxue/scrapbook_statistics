#include <time.h>
#include <stdio.h>
#include <stdlib.h>

main(int argc, char *argv[])
{
	#define NumofDays 31
	#define NumofMons 12
	char *wday[]={"Sun","Mon","Tue","Wed","Thu","Fri","Sat"};	
	char myDate[9];	//20110723*
	char myCmd1[57] = "find /mnt/hgfs/Dropbox/ScrapBook/data/ -maxdepth 1 -name ";
	char myCmd2[8] = " | wc -l";
	char myCmd[75];	
	int i_mon, j_day, k, ret, bigNum;
	time_t timep;
	struct tm *p;
	FILE   *stream;
	char buf[4], num;

	myCmd[74] = 0;
	time(&timep);
	p=gmtime(&timep);
	for(i_mon=0;i_mon<NumofMons;i_mon++)
	{
		for(j_day=0;j_day<NumofDays;j_day++)
			{
				if( (p->tm_mon > i_mon) && (p->tm_mday > j_day) && (i_mon == 0) )
					sprintf(myDate, "%d%.2d%.2d", (1900+p->tm_year), (1+p->tm_mon), p->tm_mday - j_day);		
				else if( (p->tm_mon > i_mon) && (i_mon > 0) )
					sprintf(myDate, "%d%.2d%.2d", (1900+p->tm_year), (1+p->tm_mon-i_mon), 31 - j_day);	
				else
					break;

				//printf("Date: %s\n",myDate);
				ret = strcmp(myDate, "20110431");
				if( ret == 0 )
					return;
				myDate[8] = 42;//"*";
				//printf("Date: %.8s  - The number of items I learnt is below\n",myDate);	
				//printf("Date: %s\n",myDate);	
				sprintf(myCmd, "%.57s%.9s%.8s", myCmd1, myDate, myCmd2);		
				printf("\n");	//it is used to make the myCmd run in 1 line
				if(argc > 1)	
					system(myCmd);
				
				stream = popen( myCmd, "r" ); 	
				//printf( "kkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkk" );	
				memset(buf, 0, sizeof(buf));		
				fread( buf, sizeof(char), sizeof(buf), stream);
				//printf( "cmd result: %d\n", buf[0] );
				num = atoi(buf);
				//printf( "cmd result: %d\n", num );
				for(k=0;k<num;k++)
					printf( "+" );
				pclose(stream);
			}
				
	}	

	end:	printf("The end.\n");
		return;
}
