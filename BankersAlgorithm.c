#include <stdio.h>
#include <stdlib.h>

int *resource = NULL;
int *available = NULL;
int *max_claim = NULL;
int *allocated = NULL;
int *need = NULL;

int num_processes;
int num_resources;

/***********************************************************/
void
printResources ()
{
  int i;
  printf ("\nResources: \n");
  for (i = 0; i < num_resources; i++)
    printf ("\tr%d", i);
  printf ("\n");

  for (i = 0; i < num_resources; i++)
    printf ("\t%d", resource[i]);
  printf ("\n");
  return;
}


/***********************************************************/
void
printAvaliableResources ()
{
  
  int i;
  printf ("\nAvailable Resources: \n");
  for (i = 0; i < num_resources; i++)
    printf ("\tr%d", i);
  printf ("\n");

  for (i = 0; i < num_resources; i++)
    printf ("\t%d", available[i]);
  printf ("\n");
  return;
}


/***************************************************************/
void
printMax ()
{
  printf ("\nMax Claim: \n");
  int c;
  for (c = 0; c < num_resources; c++)
    printf ("\tr%d", c);
  int i, j;
  for (i = 0; i < num_processes; i++)
    {
      printf ("\nP%d\t", i);
      for (j = 0; j < num_resources; j++)
	{
	  printf ("%d\t", max_claim[i * num_resources + j]);
	}
    }

  return;
}


/***************************************************************/
void
printAllocation ()
{
  printf ("\n\nAllocated: \n");
  int c;
  for (c = 0; c < num_resources; c++)
    printf ("\tr%d", c);
  int i, j;
  for (i = 0; i < num_processes; i++)
    {
      printf ("\nP%d\t", i);
      for (j = 0; j < num_resources; j++)
	{
	  printf ("%d\t", allocated[i * num_resources + j]);
	}
    }

  return;
}

/***************************************************************/
void
printNeed ()
{
  printf ("\n\nNeed: \n");
  int c;
  for (c = 0; c < num_resources; c++)
    printf ("\tr%d", c);
  int i, j;
  for (i = 0; i < num_processes; i++)
    {
      printf ("\nP%d\t", i);
      for (j = 0; j < num_resources; j++)
	{
	  printf ("%d\t", need[i * num_resources + j]);
	}
    }

  return;
}


/****************************************************************/
void
option1 ()
{
  /* prompt for number of processes and number of resources */
  /* allocate memory for arrays and arrays: resource, available, max_claim, allocated, need */
  /* for each resource, prompt for number of units, set resource and available arrays indices */
  /* for each process, for each resource, prompt for maximum number of units requested by process, update max_claim and need arrays */
  /* for each process, for each resource, prompt for number of resource units allocated to process */
  /* call procedures to print resource array, available array, max_claim array, allocated array, need array */

  printf ("Enter number of processes: ");
  scanf ("%d", &num_processes);
  printf ("Enter number of resources: ");
  scanf ("%d", &num_resources);

  resource = (int *) malloc (num_resources * sizeof (int));
  available = (int *) malloc (num_resources * sizeof (int));
  max_claim = (int *) malloc (num_processes * num_resources * sizeof (int));
  allocated = (int *) malloc (num_processes * num_resources * sizeof (int));
  need = (int *) malloc (num_processes * num_resources * sizeof (int));

  int i;
  int units;
  for (i = 0; i < num_resources; i++)
    {
      printf ("Enter number of units for resource r%d: ", i);
      scanf ("%d", &units);
      resource[i] = units;
      available[i] = units;
    }

  //max_claim
  int j;
  for (i = 0; i < num_processes; i++)
    for (j = 0; j < num_resources; j++)
      {
	printf
	  ("Enter maximum number of units process p%d will request from resource r%d: ",
	   i, j);
	scanf ("%d", &units);
	max_claim[i * num_resources + j] = units;
	need[i * num_resources + j] = units;
      }

  //allocated
  for (i = 0; i < num_processes; i++)
    for (j = 0; j < num_resources; j++)
      {
	printf
	  ("Enter number of units of resource r%d allocated to process p%d: ",
	   j, i);
	scanf ("%d", &units);
	allocated[i * num_resources + j] = units;
	need[i * num_resources + j] -= units;
	available[j] -= units;
      }

  printResources ();
  printAvaliableResources ();
  printMax ();
  printAllocation ();
  printNeed ();
  printf ("\n");
  return;
}


/********************************************************************/
void
option2 ()
{

  int done = 0;
  int less_than;
  int i, j;
  int *sequenced = (int *) calloc (num_processes, sizeof (int));

  while (done < num_processes)
    {
      for (i = 0; i < num_processes; i++)
	{			// main for
	  less_than = 1;
	  if (sequenced[i] == 0)
	    {			//if sequence
	      printf ("Checking p%d: ", i);
	      printf ("< ");
	      for (j = 0; j < num_resources; j++)
		printf (" %d", need[i * num_resources + j]);

	      printf (" > <= < ");

	      for (j = 0; j < num_resources; j++)
		printf (" %d", available[j]);

	      printf (" > ");

	      for (j = 0; j < num_resources; j++)
		{
		  less_than =
		    less_than & (need[i * num_resources + j]) <= available[j];
		}

	      if (less_than == 1)
		{

		  printf (" :p%d safetly sequenced", i);
		  sequenced[i] = 1;

		  for (j = 0; j < num_resources; j++)
		    {
		      available[j] += allocated[i * num_resources + j];
		      allocated[i * num_resources + j] = 0;
		      need[i * num_resources + j] =
			max_claim[i * num_resources + j];
		    }
		  done++;
		}		// if
	      printf ("\n");
	    }			// if sequence
	}			// main for
    }				//while loop
  printf ("\n");

  free (sequenced);
  return;
}


/********************************************************************/
void
option3 ()
{
  /* free memory for all arrays and arrays is not NULL */
  if (max_claim != NULL)
    free (max_claim);
  return;
}


/***************************************************************/
int
main ()
{
  int userSelection;
  do
    {
      printf ("\nResource Allocation\n");
      printf ("--------------------------------\n");
      printf ("1) Enter parameters\n");
      printf ("2) Determine safe sequence\n");
      printf ("3) Quit program and free memory\n");

      printf ("\nEnter Selection: ");
      scanf ("%d", &userSelection);
      switch (userSelection)
	{
	case 1:
	  option1 ();
	  break;
	case 2:
	  option2 ();
	  break;
	case 3:
	  option3 ();
	  break;
	}

    }
  while (userSelection != 3);
  printf ("BYE BYE");
  return 0;
}
