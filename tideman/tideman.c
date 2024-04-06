#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// stores the status of the node, whether visited or not
int state[MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

bool cyclePresent = false;
// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
} pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);
void merge(int l, int m, int r);
void mergeSort(int l, int r);
bool checkLoser(int i);
void dfs(int v);
void checkCycle(int startNode);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
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
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    // set all the elements of preferences array to 0
    for (int k = 0; k < candidate_count; k++)
    {
        for (int l = 0; l < candidate_count; l++)
        {
            preferences[k][l] = 0;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    // here loop runs for each voter
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
// this is called for each voter once only
bool vote(int rank, string name, int ranks[])
{
    // TODO

    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(name, candidates[i]) == 0)
        {
            ranks[rank] = i;
            return true;
        }
    }
    return false;
}

// Update preferences given one voter's ranks
// this is called for each voter once only
void record_preferences(int ranks[])
{
    // TODO

    // temp array to convert ranks to index and then use it
    int temp[candidate_count];

    // since the ranks array for any voter gives the voters i'th preference
    // we use it to get the index of the candidate

    for (int i = 0; i < candidate_count; i++)
    {
        // ranks array stores the index,
        // the value of it's elements is the index of the candidates depending on the ranks
        // temp converts this to an array in which the elements become ranks of the array based on
        // the index. so now we can use temp to compare different ranks
        temp[ranks[i]] = i;
    }

    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            if ((i != j) && (temp[i] < temp[j]))
            {
                preferences[i][j]++;
            }
        }
    }
    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    // TODO
    // iterate through all the candidates generating different pairs
    // where one candidate is preferred over another ignoring the ties.
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = i + 1; j < candidate_count; j++)
        {
            // compare the votes for the pair
            if (preferences[i][j] > preferences[j][i])
            {
                pairs[pair_count].winner = i;
                pairs[pair_count].loser = j;
                // keep updating the pair count every time you generate a pair
                // no need to generate a pair for ties.
                pair_count++;
            }
            else if (preferences[i][j] < preferences[j][i])
            {
                pairs[pair_count].winner = j;
                pairs[pair_count].loser = i;
                pair_count++;
            }
        }
    }
    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    // TODO
    // call the merge sort function on the pairs array
    // since it is global we don't need to explicitly pass it as argument
    // we only pass the left and right index
    mergeSort(0, pair_count - 1);
    return;
}

void mergeSort(int l, int r)
{
    // recursively calls on the pairs array to sort it
    if (l < r)
    {
        int m = l + (r - l) / 2;
        mergeSort(l, m);
        mergeSort(m + 1, r);
        merge(l, m, r);
    }
}

void merge(int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    // temp arrays to store the array elements temporarily
    // we need two arrays each for left and right subarrays
    // to store the winners and losers both
    int L_w[n1], L_l[n1], R_w[n2], R_l[n2];

    for (i = 0; i < n1; i++)
    {
        L_w[i] = pairs[i + l].winner;
        L_l[i] = pairs[i + l].loser;
    }
    for (j = 0; j < n2; j++)
    {
        R_w[j] = pairs[m + 1 + j].winner;
        R_l[j] = pairs[m + 1 + j].loser;
    }

    i = 0, j = 0;
    k = l;

    while (i < n1 && j < n2)
    {
        // do the placement of subarrays back into the original arrays
        // by comparing the votes stored in preferences array
        if (preferences[L_w[i]][L_l[i]] >= preferences[R_w[j]][R_l[j]])
        {
            pairs[k].winner = L_w[i];
            pairs[k].loser = L_l[i];
            i++;
        }
        else
        {
            pairs[k].winner = R_w[j];
            pairs[k].loser = R_l[j];
            j++;
        }
        k++;
    }

    // store the leftover elements as it is
    while (i < n1)
    {
        pairs[k].winner = L_w[i];
        pairs[k].loser = L_l[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        pairs[k].winner = R_w[j];
        pairs[k].loser = R_l[j];
        j++;
        k++;
    }
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    // TODO
    // before locking pairs check whether loser of pair was winner in previously locked pairs or not
    for (int i = 0; i < pair_count; i++)
    {
        // if the loser of the current pair has never been winner in previously locked pairs then
        // safely lock that pair
        if (!checkLoser(i))
        {
            locked[pairs[i].winner][pairs[i].loser] = true;
        }
        else
        {
            // first lock the pair so that adjacency matrix is formed
            locked[pairs[i].winner][pairs[i].loser] = true;

            // check for cycle from the winners node in this particular pair
            checkCycle(pairs[i].winner);

            if (cyclePresent)
            {
                // if cycle found unlock that pair again, if not then leave it locked
                locked[pairs[i].winner][pairs[i].loser] = false;
            }
        }
    }
}

bool checkLoser(int i)
{
    for (int j = 0; j < candidate_count; j++)
    {
        if (locked[pairs[i].loser][j] == true)
        {
            return true;
        }
    }
    return false;
}

// check cycle using depth first search traversal
void checkCycle(int startNode)
{
    cyclePresent = false; // reset this variable for every run of checkCycle

    for (int v = 0; v < candidate_count; v++)
    {
        state[v] = 0; // mark every node univisited
    }

    dfs(startNode); // start dfs traversal from the starting node
}

void dfs(int v)
{
    int i;
    state[v] = 1; // marking the node visited

    for (i = 0; i < candidate_count; i++)
    {
        if (locked[v][i] == true) // only to traverse the nodes which are locked in a pair
        {
            if (state[i] == 0)
            {
                dfs(i); // if the node is not visited before then recurse and visit that node
            }
            else if (state[i] == 1)
            {
                cyclePresent = true; // if visited node is reached then cycle is present
                return;
            }
        }
    }
}

// Print the winner of the election
void print_winner(void)
{
    // TODO
    // instead of checking that whether a particular candidate wins over all others
    // we should check whether the candidate loses to anyone or not
    // if the candidate never loses then that candidate will be the winner of tideman voting
    bool is_winner;
    for (int i = 0; i < candidate_count; i++)
    {
        is_winner = true;
        for (int j = 0; j < candidate_count; j++)
        {
            if (locked[j][i] == true)
            {
                is_winner = false;
                break;
            }
        }

        if (is_winner)
        {
            printf("%s\n", candidates[i]);
        }
    }
}
