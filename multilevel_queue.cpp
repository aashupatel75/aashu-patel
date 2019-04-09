#include<conio.h>
#include<stdio.h>
int main()
{
	char pname[10];
	int atime[10],btime[10],priority[10],q,n,i,p,j,process[10],total_ttime,total_wtime;
	int s[10],wtime[10],ttime[10],f[10];
	float avg_total_ttime, avg_total_wtime;
	
	printf("Enter the total number  of process\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
	//	p=i;
	process[i]=i+1;
		printf("Enter the detail of process: %d\n",i+1);
		printf("Arival time\n");
		scanf("%d",&atime[i]);
		printf("Brust time\n");
		scanf("%d",&btime[i]);
		printf("priority \n");
		scanf("%d",&priority[i]);
	}
	printf("Process_name\t Arivel_time \t Brust_time\t priority \n");
	for(i=0;i<n;i++)
	{
		printf("%d\t\t%d\t\t%d\t\t%d\t\t\n",i+1,atime[i],btime[i],priority[i]);
	}
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
	{

		if(priority[j]>priority[j+1])
		{
			int z=priority[j+1];
			priority[j+1]=priority[j];
			priority[j]=z;
			
			int x=atime[j+1];
			atime[j+1]=atime[j];
			atime[j]=x;	
		
		int y=btime[j+1];
			btime[j+1]=btime[j];
			btime[j]=y;
			
		
			
		int a=process[j+1];
			process[j+1]=process[j];
			process[j]=a;
}
	    
	}
}
printf("Sorting according to priority \n");
	printf("Process_name\t Arivel_time \t Brust_time\t priority \n");
	for(i=0;i<n;i++)
	{
		printf("%d\t\t%d\t\t%d\t\t%d\t\t\n",process[i],atime[i],btime[i],priority[i]);
	}
	
	   for(i=0; i<n; i++)
 
    {
 
        if(i==0)
        {
            s[i]=atime[i];
            wtime[i]=s[i]-atime[i];
            f[i]=s[i]+btime[i];
            ttime[i]=f[i]-atime[i];
        }
        else
        {
            s[i]=f[i-1];
            wtime[i]=s[i]-atime[i];
            f[i]=s[i]+btime[i];
            ttime[i]=f[i]-atime[i];
        }
        total_wtime+=wtime[i];
        total_ttime+=ttime[i];
    }
    avg_total_wtime=(float)total_wtime/n;
    avg_total_ttime=(float)total_ttime/n;
    	printf("Process_name\t Arivel_time \t Brust_time\t priority\ttotal_wtime\ttotalttime \n");
    for(i=0; i<n; i++)
    {
    		printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",process[i],atime[i],btime[i],priority[i],wtime[i],ttime[i]);
	}

       printf("\nAverage waiting time is:%f",avg_total_wtime);
        printf("\nAverage tatime is:%f", avg_total_ttime);
	
	
}
