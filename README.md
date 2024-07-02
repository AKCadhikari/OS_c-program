 C program that simulates the Round Robin scheduling and calculates the
waiting time, turnaround time for each process, and also represents the execution order
using a Gantt chart.
Program Requirements
1. Input:
o Number of processes.
o Burst time for each process.
o Time quantum.
2. Output:
o Waiting time for each process.
o Turnaround time for each process.
o Average waiting time.
o Average turnaround time.
o Execution order (Gantt chart).
Steps to Implement the Program
1. Define a Structure for Process:
o Process ID.
o Burst time.
o Remaining burst time.
o Waiting time.
o Turnaround time.
2. Calculate Waiting Time:
o Use the remaining burst time to simulate process execution.
o Track the execution order.
3. Calculate Turnaround Time:
o Turnaround time is the sum of burst time and waiting time.
4. Print Results:
o Print waiting time, turnaround time for each process.
o Print average waiting and turnaround times.
o Print the Gantt chart representing the execution order.
