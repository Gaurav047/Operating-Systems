// C++ program to implement FCFS scheduling

#include <iostream>
using namespace std;

// Function to find the waiting time for all processes
void findWaitingTime(int processes[], int n, int bt[], int wt[]){
    // waiting time for first process is 0
    wt[0] = 0;
    
    // calculating waiting time
    for ( int i=1; i<n ; i++ ){
        wt[i] = bt[i-1] + wt[i-1];
    }
}

// Function to calculate turn around time
void findTurnAroundTime( int processes[], int n, int bt[], int wt[], int tat[]){
    // Calculating turn around time by adding bt[i] + wt[i]
    for ( int i=0 ; i<n ; i++ ){
        tat[i] = bt[i] + wt[i];
    }
}

// Function to Calculate average time
void findAvgTime( int processes[], int n, int bt[]){
    int wt[n], tat[n], total_wt=0, total_tat=0;
    
    // Function to find waiting time of all processes
    findWaitingTime(processes, n, bt, wt);
    
    // Function to find turn around time for all processes
    findTurnAroundTime(processes, n, bt, wt, tat);
    
    // Display processes along with all details
    cout << "Processes" << "Burst time" << "Waiting time " << " Turn around time\n";
    
    // Calculate total waiting time and total turn around time
    for ( int i=0 ; i<n ; i++ ){
        total_wt +=wt[i];
        total_tat +=tat[i];
        cout << "  " << i+1 << "\t\t" << bt[i] << "\t   " << wt[i] << "\t\t   " << tat[i] << endl;
    }
    cout << "Avergare waiting time = " << (float)total_wt / (float)n;
    cout << "\nAvergae turn around time = " << (float)total_tat/(float)n;
    
}

int main(){
    // Process IDs
    int processes[] = {1, 2, 3};
    int n = sizeof(processes)/ sizeof(processes[0]);
    
    // Burst time of all processes
    int burst_time[] = {10, 5, 8};
    
    findAvgTime(processes, n, burst_time);
    return 0;
}