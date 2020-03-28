/* \t Date */
// 28-03-20 19:24
/* ==================================
    Name : Anand Guptra
    Section : K18KH
    Roll no : B41
    Registration no : 11803419
  ===================================
*/

// Header Files
#include<stdio.h>

// Main Function
int main()
{

 int TS,TAT[10];
 int n , i , j, numOfPs, p_id[10], waiting_Time[10], need[10];
 int BT[10],flag[10],TTAT=0,TWT=0;
 float AWT,ATAT;
printf("=================================================\n\t ROUND ROBIN SCHEDULING ALGORITHM \n================================================="); 
printf("\nEnter the number of process in CPU \n"); 
 scanf("%d",&numOfPs);   // Taking input of number of process that run in cpu
 n = numOfPs;
 printf("\nEnter the Timeslice \n");
 scanf("%d",&TS);  // Input of Timeslice
 for(i=1;i <= numOfPs;i++)  // Loop for taking input of processes
{
printf("\n Enter the process ID for Process%d\n",i);
scanf("%d",&p_id[i]);    // Input of Process Id
printf("\n Enter the Burst Time for the process%d\n",i);
scanf("%d",&BT[i]);  // Input of Burst Time of the process
need[i] = BT[i];
}
for(i=1;i <= numOfPs;i++)
{
  flag[i]=1;
  waiting_Time[i]=0;
 }
while(numOfPs != 0)
 {
   for(i=1;i <= numOfPs;i++)
   {
     if(need[i] >= TS)
     {
   for(j=1;j <= numOfPs;j++)
       {
    if((i != j) && (flag[i] == 1) && (need[j]!=0))
    waiting_Time[j] += TS;
       }
 need[i] -= TS;
 if(need[i]== 0)
{
flag[i]=0;
numOfPs--;
}
}
else
{
  for(j=1;j <= numOfPs;j++)
      {
    if((i != j) && (flag[i] == 1) && (need[j] != 0))
    waiting_Time[j] += need[i];
       }
need[i]=0;
numOfPs--;
flag[i]=0;
}
 }
}
for(i=1;i <= n;i++)
{
TAT[i] = waiting_Time[i] + BT[i];
TWT = TWT + waiting_Time[i];
TTAT = TTAT + TAT[i];
}
AWT = (float)TWT/n;
ATAT = (float)TTAT/n;

// Final output after the calculating the values of Waiting  Time  and Turnaround Time

printf("\n\n ROUND ROBIN SCHEDULING ALGORITHM \n\n");
printf("\n\n Process \t Process ID  \t BurstTime \t Waiting Time \t TurnaroundTime \n ");
for(i=1;i <= n;i++)
{
printf("\n %5d \t %5d \t\t %5d \t\t %5d \t\t %5d \n", i,p_id[i],BT[i],waiting_Time[i],TAT[i]);
}
printf("\n The average Waiting Time=4.2f",AWT);
printf("\n The average Turn around Time=4.2f",ATAT);
return 0;
} 
