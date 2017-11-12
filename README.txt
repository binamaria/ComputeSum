Author:  Bina Maria
The program contains two types of processes:
I) A set of "slaves" processes: Each slave process gets two small integers from its argv, computes its sum and returns the result using the exit system call. So, a slave process is created for every sum.
II) A "master" process: This process is responsible for creating the slave processes, and coordinating the computation. Here all the computation is done by the "slave" processes. All the numbers are provided in the command line argv. 
The code for master process is compiled separately and its executable code is called master. The executable code for the slave process is called slave. So, to compute the sum of the numbers 1 through 7, the command line will look like 
master 1 2 3 4 5 6 7
Since the results are passed around by exit system call, keep the numbers small (single digit). Each slave process prints its process id, its operands, and their sum. Each time the master gets a result from a slave, it prints the pid of the slave and the partial sum.
The program can be tested for the following cases:
master 1
master 1 2 3 4 5
master 1 2 3 4 5 6 7 8
