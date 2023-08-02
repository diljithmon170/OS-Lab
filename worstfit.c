#include <stdio.h>

void worstFit(int blockSize[],int m,int processSize[],int n)
{
    //Block allocations for process
    int allocation[n];

    //Initially allocate the index of -1 to all allocation blocks
    for (int i=0;i<n;i++)
    {
        allocation[i]=-1;
    }

    //Fetching the process
    for (int i=0;i<n;i++)
    {
        //Setting the index with maximal wastage
        int best_idx=-1;
        //Keeping the track of free space in best block
        int diff;
        
        //Running for-loop over blocksizes 
        for (int j=0;j<m;j++)
        {
            if (blockSize[j]>=processSize[i])
            {
                //Choosing first block as the best allocated block
                if (best_idx==-1)
                {
                    diff=blockSize[j]-processSize[i];
                    best_idx=j;
                }
                else
                {
                    int inter=blockSize[j]-processSize[i];
                    //Check if this free space is less than that of current best
                    if (diff<inter)
                    {
                        diff=inter;
                        best_idx=j;
                    }
                }
            }
        }

        if (best_idx==-1)
            continue;

        //At the end allot the block to process and re-calculate free-space
        blockSize[best_idx]=processSize[i];
        allocation[i]=best_idx;
    }
    
    //Now printing the allocation array
    printf("\nProcess No.\tProcess Size\tBlock no.\n");
	for (int i = 0; i < n; i++)
	{
		printf(" %i\t\t\t", i+1);
		printf("%i\t\t\t\t", processSize[i]);
		if (allocation[i] != -1)
			printf("%i", allocation[i] + 1);
		else
			printf("Not Allocated");
		printf("\n");
	}
}


int main() 
{ 
    int m,i; //number of blocks in the memory
	int n; //number of processes in the input queue
	printf("Enter the no of the block max=5 :- ");
	scanf("%d",&m);
	printf("enter the no of the process max=5 :- ");
	scanf("%d",&n);
	int blockSize[m];
	int processSize[n];
	printf("enter the size of the blocks :- ");
	for(i=0;i<m;i++)
	{
		scanf("%d",&blockSize[i]);
	}
	printf("enter the size of the processes :- ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&processSize[i]);
	}
  
    worstFit(blockSize, m, processSize, n); 
  
    return 0 ; 
} 