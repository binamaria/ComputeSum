 /** author: bina maria
  *  created on: 09/29/2017
  */

 #include <stdio.h>
 #include <stdlib.h>
 #include <unistd.h>
 #include <signal.h>
 #include <sys/types.h>
 #include <sys/wait.h>

 
int pid;
void timeout();
int  main(int argc, char *argv[])
 {
char  *childname = "slave";
char  *childpath = "/home/os/slave";
   int i, currentstat;   
int size = argc-1;
int ifoddflag = 0;

// Checks if odd number of inputs, then array size is changed and the variable ifoddflag is set.
  if ( ( (argc-1) % 2 ) != 0 )
  {
	size = argc; 
	ifoddflag = 1; 
  } 

int numbers[size];

//Input values are added to the array
for (i=0; i < argc-1; i++) 
{
	numbers[i] = atoi(argv[i+1]);
}

//For odd number, 0 is added to the array
if (ifoddflag == 1) 
{
	numbers[size-1] = 0;
}

int countflag = 0;

//Loop through all the values in the array
 for (i =0; i < size; i=i+2) 
{

signal(SIGALRM,timeout);
alarm(3);

   //To create a child process
   pid = fork();

   //Check if child
   if (pid == 0) 
   {    
	
	char vara[30];
	sprintf(vara, "%d", numbers[i]);
	char varb[30];
	sprintf(varb, "%d", numbers[i+1]);
        execl(childpath, childname, vara, varb,NULL);      
        perror("execl error : failed to run slave program");
        exit(1);
    }
     else if (pid > 0 ) // Check if parent
     {
	waitpid(pid, &currentstat, 0); 
        alarm(0);
	currentstat = currentstat >> 8;
	printf("PID is %d Intermediate sum is %d \n", pid, currentstat); 
        //clearing the array
	numbers[i] = 0; 
	numbers[i+1] = 0;
        //populating array with the sum
        numbers[countflag] = currentstat; 
	countflag++;
     }
     else
        {
          printf("No child, fork call failed\n");
          exit(-1);
        }
        //Check if final sum
	if (size == 2) 
	{
		printf("Total: %d \n", currentstat);
	}
        //Check if end of loop
	if(i >= size-2) 
	{
        //Check if more sums are there to be done or not
		if (size > 2) 
		{
                       //Check if next group of sums needs 0 added
			if ( ( size % 2 ) != 0 ) 
  			{
				size++;
				size = size/2; 
			}
			else
			{
				size = size/2;
			}
			countflag = 0; 
			i = -2; 
		}
	}
	
}
 }

void timeout()
{
printf("Time out - Child terminated \n");
kill(pid, SIGTERM);
}
