#include<stdio.h> // Standard I/O

struct Job{ int id; int deadline; int profit; }; // Job structure

int main(){
    struct Job jobs[50], temp; // Job array and swap temp
    int n, maxDeadline = 0, totalProfit = 0; // Count, max deadline, accumulated profit
    printf("Enter number of jobs:"); scanf("%d", &n); // Read job count
    printf("Enter job id, deadline and profit:\n"); // Prompt
    for(int i = 0; i < n; i++){ // Read job details and track max deadline
        scanf("%d %d %d", &jobs[i].id, &jobs[i].deadline, &jobs[i].profit);
        if(jobs[i].deadline > maxDeadline) maxDeadline = jobs[i].deadline;
    }
    int slot[maxDeadline]; // Time slots array
    // Sort jobs by profit in descending order
    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            if(jobs[i].profit < jobs[j].profit){
                temp = jobs[i]; jobs[i] = jobs[j]; jobs[j] = temp;
            }
        }
    }
    for(int i = 0; i < maxDeadline; i++) slot[i] = -1; // Initialize slots as empty
    // Assign jobs to latest possible free slot
    for(int i = 0; i < n; i++){
        for(int j = jobs[i].deadline - 1; j >= 0; j--){
            if(slot[j] == -1){ // If slot is free
                slot[j] = i; // Assign job index to slot
                totalProfit += jobs[i].profit; // Add profit
                break; // Move to next job
            }
        }
    }
    printf("Selected job sequence:\n"); // Output header
    for(int i = 0; i < maxDeadline; i++){
        if(slot[i] != -1) printf("Job %d ", jobs[slot[i]].id); // Print scheduled jobs
    }
    printf("\nTotal Profit = %d\n", totalProfit); // Output total profit
    return 0;
}