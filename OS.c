#include <stdio.h>

struct Process {
  int pid; // Process ID
  int bt; // Burst time
  int remaining_bt; // Remaining burst time
  int wt; // Waiting time
  int tat; // Turnaround time
};

void findWaitingTime(struct Process proc[], int n, int quantum) {
  int time = 0;
  int flag = 0;

  while (flag == 0) {
    flag = 1;
    for (int i = 0; i < n; i++) {
      if (proc[i].remaining_bt > 0) {
        flag = 0;
        if (proc[i].remaining_bt <= quantum) {
          time += proc[i].remaining_bt;
          proc[i].remaining_bt = 0;
          proc[i].wt = time - proc[i].bt;
        } else {
          proc[i].remaining_bt -= quantum;
          time += quantum;
        }
      }
    }
  }
}

void findTurnAroundTime(struct Process proc[], int n) {
  for (int i = 0; i < n; i++) {
    proc[i].tat = proc[i].bt + proc[i].wt;
  }
}

void printProcessTable(struct Process proc[], int n) {
  printf("Processes                                           Burst Time  Waiting Time      Turnaround Time\n");
  for (int i = 0; i < n; i++) {
    printf("Process %d                                         %d             %d                  %d \n", proc[i].pid, proc[i].bt, proc[i].wt, proc[i].tat);
  }
}

void findAverageTime(struct Process proc[], int n, int quantum) {
  findWaitingTime(proc, n, quantum);
  findTurnAroundTime(proc, n);

  float total_wt = 0;
  float total_tat = 0;

  for (int i = 0; i < n; i++) {
    total_wt += proc[i].wt;
    total_tat += proc[i].tat;
  }

  float avg_wt = total_wt / n;
  float avg_tat = total_tat / n;

  printf("Average waiting time = %f\n", avg_wt);
  printf("Average turnaround time = %f\n", avg_tat);
}

void printGanttChart(struct Process proc[], int n, int quantum) {
  int time = 0;
  printf("Gantt Chart:\n");
  printf("Execution Order:");

  for (int i = 0; i < n; i++) {
    findWaitingTime(proc, n, quantum);
    for (int j = time; j < (time + proc[i].remaining_bt); j++) {
      printf(" P%d", proc[i].pid);
    }
    time += proc[i].remaining_bt;
  }
  printf("\n");
}

int main() {
  int n;
  int quantum;

  printf("Enter number of processes: ");
  scanf("%d", &n);

  struct Process proc[n];

  for (int i = 0; i < n; i++) {
    proc[i].pid = i + 1;
    printf("Enter burst time for process %d: ", i + 1);
    scanf("%d", &proc[i].bt);
    proc[i].remaining_bt = proc[i].bt;
  }

  printf("Enter time quantum: ");
  scanf("%d", &quantum);

  printf("\n");
  findAverageTime(proc, n, quantum);
  printProcessTable(proc, n);
  printGanttChart(proc, n, quantum);

  return 0;
}

