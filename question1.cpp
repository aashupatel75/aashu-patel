#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
main()
{
	int i,j,tseek_time=0,n,queue[30],head,seek_time;
	printf("Enter the number  of cylinder\n");
	scanf("%d",&n);
	printf("Enter the cylinder number that you want to processed: ");
	for(i=1;i<=n;i++)
	{
		scanf("%d",&queue[i]);
		if(queue[i]>=5000 || queue[i]<=0)
		{
			i=i-1;
			printf("Invalid input.\n");
			printf("Enter Again.\n");
		}
	}
	printf("Enter the head position");
	scanf("%d",&head);
	queue[0]=head;
	printf("Cylinder number of processes :\n");
	for(i=0;i<=n;i++)
	{
	
		printf("\t%d",queue[i]);
	}
	printf("\n");
	for(i=0;i<n;i++)
	{
	seek_time=abs(queue[i+1]-queue[i]);
	printf("Move is from %d to %d with seek time %d\n",queue[i],queue[i+1],seek_time);
	tseek_time=tseek_time+seek_time;
    }
    printf("Total seek time : %d",tseek_time);	
}
