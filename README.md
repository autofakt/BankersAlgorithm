# BankersAlgorithm
Resource Allocation and the Banker's Algorithm


Resource Allocation
-------------------
1) Enter parameters
2) Determine safe sequence
3) Quit program

Enter selection: 1
Enter number of processes: 5
Enter number of resources: 3
Enter number of units for resource r0: 10
Enter number of units for resource r1: 5
Enter number of units for resource r2: 7
Enter maximum number of units process p0 will request from resource r0: 7
Enter maximum number of units process p0 will request from resource r1: 5
Enter maximum number of units process p0 will request from resource r2: 3
Enter maximum number of units process p1 will request from resource r0: 3
Enter maximum number of units process p1 will request from resource r1: 2
Enter maximum number of units process p1 will request from resource r2: 2
Enter maximum number of units process p2 will request from resource r0: 9
Enter maximum number of units process p2 will request from resource r1: 0
Enter maximum number of units process p2 will request from resource r2: 2
Enter maximum number of units process p3 will request from resource r0: 2
Enter maximum number of units process p3 will request from resource r1: 2
Enter maximum number of units process p3 will request from resource r2: 2
Enter maximum number of units process p4 will request from resource r0: 4
Enter maximum number of units process p4 will request from resource r1: 3
Enter maximum number of units process p4 will request from resource r2: 3
Enter number of units of resource r0 allocated to process p0: 0
Enter number of units of resource r1 allocated to process p0: 1
Enter number of units of resource r2 allocated to process p0: 0
Enter number of units of resource r0 allocated to process p1: 2
Enter number of units of resource r1 allocated to process p1: 0
Enter number of units of resource r2 allocated to process p1: 0
Enter number of units of resource r0 allocated to process p2: 3
Enter number of units of resource r1 allocated to process p2: 0
Enter number of units of resource r2 allocated to process p2: 2
Enter number of units of resource r0 allocated to process p3: 2
Enter number of units of resource r1 allocated to process p3: 1
Enter number of units of resource r2 allocated to process p3: 1
Enter number of units of resource r0 allocated to process p4: 0
Enter number of units of resource r1 allocated to process p4: 0
Enter number of units of resource r2 allocated to process p4: 2

Resources: 
    r0  r1  r2
    10  5   7

Available: 
    r0  r1  r2
    3   3   2

Max claim: 
    r0  r1  r2  
p0    7   5   3   
p1    3   2   2   
p2    9   0   2   
p3    2   2   2   
p4    4   3   3   

Allocated: 
    r0  r1  r2  
p0    0   1   0   
p1    2   0   0   
p2    3   0   2   
p3    2   1   1   
p4    0   0   2   

Need: 
    r0  r1  r2  
p0    7   4   3   
p1    1   2   2   
p2    6   0   0   
p3    0   1   1   
p4    4   3   1   

Resource Allocation
-------------------
1) Enter parameters
2) Determine safe sequence
3) Quit program

Enter selection: 2
Checking p0: < 7 4 3 > <= < 3 3 2 >
Checking p1: < 1 2 2 > <= < 3 3 2 > :p1 safely sequenced
Checking p2: < 6 0 0 > <= < 5 3 2 >
Checking p3: < 0 1 1 > <= < 5 3 2 > :p3 safely sequenced
Checking p4: < 4 3 1 > <= < 7 4 3 > :p4 safely sequenced
Checking p0: < 7 4 3 > <= < 7 4 5 > :p0 safely sequenced
Checking p2: < 6 0 0 > <= < 7 5 5 > :p2 safely sequenced
