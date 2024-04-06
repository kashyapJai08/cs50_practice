#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
} candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);
void merge(candidate arr[], int l, int m, int r);
// void sort_candidate(void);
void mergeSort_candidate(candidate arr[], int l, int r);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    // TODO
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(name, candidates[i].name) == 0)
        {
            candidates[i].votes++;
            return true;
        }
    }
    return false;
}

// /* ************ IMPLEMENTATION OF BUBBLE SORT ************************ */

// // Print the winner (or winners) of the election
// // Bubble sort is used here to sort the candidates.
// // The 0 index candidate then becomes the one with highest number of votes.
// void print_winner(void)
// {
//     // TODO
//     int j = 0;
//     string temp_name;
//     int temp_vote;

//     // sort the candidates
//     while (j < candidate_count)
//     {
//         for (int i = 0; i < candidate_count - 1; i++)
//         {
//             if (candidates[i].votes < candidates[i + 1].votes)
//             {
//                 // swap names
//                 temp_name = candidates[i].name;
//                 candidates[i].name = candidates[i + 1].name;
//                 candidates[i + 1].name = temp_name;
//                 // swap votes
//                 temp_vote = candidates[i].votes;
//                 candidates[i].votes = candidates[i + 1].votes;
//                 candidates[i + 1].votes = temp_vote;
//             }
//         }
//         j++;
//     }

//     // print the winners
//     printf("%s\n", candidates[0].name);
//     for (int i = 1; i < candidate_count; i++)
//     {
//         if (candidates[i].votes == candidates[0].votes)
//         {
//             printf("%s\n", candidates[i].name);
//         }
//     }
//     return;
// }

// /* ************ IMPLEMENTATION OF MERGE SORT ************************ */


// void print_winner(void)
// {
//     // TODO
//     // sorts the candidates in descending order
//     mergeSort_candidate(candidates, 0, candidate_count - 1);

//     // print the winners
//     printf("%s\n", candidates[0].name);
//     for (int i = 1; i < candidate_count; i++)
//     {
//         if (candidates[i].votes == candidates[0].votes)
//         {
//             printf("%s\n", candidates[i].name);
//         }
//     }
//     return;
// }

// // i was passing int array but the type of candidates array
// // is candidate as we have defined a struct up top
// void mergeSort_candidate(candidate arr[], int l, int r)
// {
//     if (l < r)
//     {
//         // find the middle index
//         int m = l + (r - l) / 2;
//         // recursively divide the array in two halves left and right
//         mergeSort_candidate(arr, l, m);
//         mergeSort_candidate(arr, m + 1, r);
//         // after reaching the atomic element start merging and sorting them
//         merge(arr, l, m, r);
//     }
// }

// void merge(candidate arr[], int l, int m, int r)
// {
//     int i, j, k; // index which will be used later to sort the elements

//     // size of temp arrays
//     int n1 = m - l + 1; // size of left half
//     int n2 = r - m; // size of right half

//     int Lvotes[n1], Rvotes[n2]; // temp arrays to store vote counts
//     string Lname[n1], Rname[n2]; // temp arrays to store candidate names

//     // storing the left subarray in L temp array
//     for (i = 0; i < n1; i++)
//     {
//         Lvotes[i] = arr[l + i].votes;
//         Lname[i] = arr[l + i].name;
//     }
//     // storing the right subarray in R temp array
//     for (j = 0; j < n2; j++)
//     {
//         Rvotes[j] = arr[m + 1 + j].votes;
//         Rname[j] = arr[m + 1 + j].name;
//     }

//     // now we start sorting the elements
//     // we compare the two temp arrays
//     // and then put the elements back
//     // in the original array in the sorted order
//     i = 0, j = 0;
//     k = l;

//     while(i < n1 && j < n2)
//     {
//         if (Lvotes[i] >= Rvotes[j])
//         {
//             arr[k].votes = Lvotes[i];
//             arr[k].name = Lname[i];
//             i++;
//         }
//         else
//         {
//             arr[k].votes = Rvotes[j];
//             arr[k].name = Rname[j];
//             j++;
//         }
//         k++;
//     }

//     // store the remaining elements as it is
//     while (i < n1)
//     {
//         arr[k].votes = Lvotes[i];
//         arr[k].name = Lname[i];
//         i++;
//         k++;
//     }
//     while (j < n2)
//     {
//         arr[k].votes = Rvotes[j];
//         arr[k].name = Rname[j];
//         j++;
//         k++;
//     }
// }

/* ***************** Without Sorting ********************* */

void print_winner(void)
{
    int max_vote = 0; // set the max vote variable to zero

    // iterate through the list of candidates and keep updating the max_vote variable
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes > max_vote)
        {
            max_vote = candidates[i].votes;
        }
    }

    // again iterate over the candidates and keep printing the winners
    for (int j = 0; j < candidate_count; j++)
    {
        if (candidates[j].votes == max_vote)
        {
            printf("%s\n", candidates[j].name);
        }
    }
}
