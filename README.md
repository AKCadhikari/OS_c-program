 C program that simulates the Round Robin scheduling and calculates the
waiting time, turnaround time for each process, and also represents the execution order
using a Gantt chart.
Program Requirements
1. Input:
Number of processes.
Burst time for each process.
Time quantum.
2. Output:
 Waiting time for each process.
Turnaround time for each process.
Average waiting time.
Average turnaround time.
Execution order (Gantt chart).
Steps to Implement the Program
1. Define a Structure for Process:
Process ID.
Burst time.
Remaining burst time.
Waiting time.
Turnaround time.
2. Calculate Waiting Time:
Use the remaining burst time to simulate process execution.
Track the execution order.
3. Calculate Turnaround Time:
Turnaround time is the sum of burst time and waiting time.
4. Print Results:
Print waiting time, turnaround time for each process.
Print average waiting and turnaround times.
Print the Gantt chart representing the execution order.
