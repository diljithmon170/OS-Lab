#include<stdio.h>
#include<stdlib.h>
int main()
{
int pno,arrt[5],bst[5],compt[5],tat[5],weit[5],n,i,j,at,aw;
printf("enter the no of process (max 5):- ");
scanf("%d",&n);
printf("enter the arraival time");
for(i=0;i<n;i++)
{
scanf("%d",&arrt[i]);
}
printf("enter the burst time");
for(i=0;i<n;i++)
{
scanf("%d",&bst[i]);
}
pno=1;
for(i=0;i<n;i++)
{
pno=pno+bst[i];
compt[i]=pno;
}
for(i=0;i<n;i++)
{
tat[i]=compt[i]-arrt[i];
}
for(i=0;i<n;i++)
{
weit[i]=tat[i]-bst[i];
}
printf("competion time\n");
for(i=0;i<n;i++)
{
printf("%d",compt[i]);
printf("\n");
}
printf("turn around time\n");
for(i=0;i<n;i++)
{
printf("%d",tat[i]);
printf("\n");
}
printf("waiting time\n");
for(i=0;i<n;i++)
{
printf("%d",weit[i]);
printf("\n");
}
at=0;
for(i=0;i<n;i++)
{
at+=tat[i];
}
aw=0;
for(i=0;i<n;i++)
{
aw+=weit[i];
}
printf("average TAT= %d",at/n);
printf("\n");
printf("average waiting time= %d",aw/n);
printf("\n");
}