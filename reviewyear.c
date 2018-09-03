// 艾宾豪斯遗忘曲线，最好的复习时间是1、2、4、7、15天后
// 这个代码是为了计算当天要复习的笔记日期
// 为了解决1月这些进位问题，做了年份的处理

#include<stdio.h>
#include<time.h>

int cntdate(int year, int mon, int day, int n, int *pyear, int * pmon, int * pday);
int gettime(int *year, int *mon, int*day);

int main()
{
	int year, mon, day;
	int pyear, pmon, pday;

	year = 0;
	mon = 0;
	day = 0;
	pyear = 0;
	pmon = 0;
	pday = 0;

	gettime(&year, &mon, &day);

	int a[5] = {1,2,4,7,15};
	int i;

	printf("要复习的笔记日期有：\n");
	printf("\n");

	for(i = 0; i < 5; i++){
		cntdate(year, mon, day, a[i], &pyear, &pmon, &pday);
		printf("%d.%d天前：\t%d年%d月%d日\n", i+1, a[i], pyear, pmon, pday);
	}

	return 0;
}

int gettime(int *year, int *mon, int*day)
{
	time_t timep;
	struct tm *p;
	time (&timep);
	p=gmtime(&timep);

	*year = 1900+p->tm_year;
	*mon = 1+p->tm_mon;
	*day = p->tm_mday;

	return 0;
}

int cntdate(int year, int mon, int day, int n, int *pyear, int * pmon, int * pday)
{
	int premon;
	switch(mon){
		case 1:
		case 2:
		case 4:
		case 6:
		case 8:
		case 9:
		case 11:
			premon = 31;
			break;
		case 5:
		case 7:
		case 10:
		case 12:
			premon = 30;
			break;
		default:
			premon = 28;
			break;
	}

	*pyear = year;

	// if mon = 1, should move to the last year
	if(mon != 1){
		if(day - n  <= 0){
			*pmon = mon - 1;
			*pday = day + premon - n -1;
		}else{
			*pmon = mon;
			*pday = day -n;
		}
	}else{
		if(day - n  <= 0){
			*pyear = year - 1;
			*pmon = 12;
			*pday = day + premon - n -1;
		}else{
			*pmon = mon;
			*pday = day -n;
		}
	}


	return 0;
	
}

