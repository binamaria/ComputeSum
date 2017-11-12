  /** author: bina maria
  *  created on: 09/29/2017
  */

 #include <stdio.h>
 #include <stdlib.h>
 #include <sys/types.h>
 
 
int  main(int argc, char *argv[])
 {
        int firstnum  = atoi(argv[1]);
	int secondnum = atoi(argv[2]);
	int sum = firstnum + secondnum;         // Sum calculation
	int pid = getpid();
	printf("PID is %d : %d + %d = %d \n", pid, firstnum, secondnum, sum);	   
        exit(sum); 
 }

