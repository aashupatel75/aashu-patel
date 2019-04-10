#include<conio.h>
#include<stdio.h>
int main()
{
	int n1;
	printf("1. Priority scheduling\n");
	printf("2. Round robin scheduling\n");
	printf("Enter the choice\n");
	scanf("%d",&n1);
	char pname[10];
	int atime[10],btime[10],priority[10],q,n,i,p,j,process[10],total_ttime,total_wtime;
	int s[10],wtime[10],ttime[10],f[10];
	float avg_total_ttime, avg_total_wtime;
	int k,n3,time,left,flag=0,time_quantum,a[10]; 
    float wait_time=0,turnaround_time=0;
	switch(n1)
	{
	case 1:
	
	
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
        break;
    case 2:
  	printf("Enter the total number  of process\n");
	scanf("%d",&n3);
	left=n3;
	for(k=0;k<n3;k++)
	{
        process[k]=k+1;
		printf("Enter the detail of process: %d\n",k+1);
		printf("Arival time\n");
		scanf("%d",&atime[k]);
		printf("Brust time\n");
		scanf("%d",&btime[k]);
		a[k]=btime[k]; 
	}
        printf("Enter Time Quantum:\t"); 
        scanf("%d",&time_quantum); 
        printf("\n\nProcess\t Turnaround Time Waiting Time\n\n"); 
  for(time=0,k=0;left!=0;) 
  { 
//  printf("hello");
    if(a[k]<=time_quantum &&a[k]>0) 
    { 
      time+=a[k]; 
      a[k]=0; 
      flag=1; 
    } 
    else if(a[k]>0) 
    { 
      a[k]-=time_quantum; 
      time+=time_quantum; 
    } 
    if(a[k]==0 && flag==1) 
    { 
      left--; 
      printf("%d\t\t%d\t\t%d\n",k+1,time-atime[k],time-atime[k]-btime[k]); 
      wait_time+=time-atime[k]-btime[k]; 
      turnaround_time+=time-atime[k]; 
      flag=0; 
    } 
    if(k==n-1) 
      k=0; 
    else if(atime[k+1]<=time) 
      k++; 
    else 
      k=0; 
  } 
  printf("\nAverage_Waiting _Time= %f\n",wait_time/n3); 
  printf("Average _Turnaround _time = %f",turnaround_time/n3); 
  break;

   default:
   	printf("default");

}

	
}
