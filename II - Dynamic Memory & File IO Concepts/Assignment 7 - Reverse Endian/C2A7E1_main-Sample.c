#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE_LEN 256                // size of input buffer
#define BUFFMT "%255"               // field width for input buffer scan

void* SafeMalloc(size_t size)
{
    void* vp;

    if ((vp = malloc(size)) == NULL)
    {
        fputs("Out of memory\n", stderr);
        exit(EXIT_FAILURE);
    }
    return(vp);
}

FILE* OpenFile(const char* fileName)
{
    FILE* fp;

    if ((fp = fopen(fileName, "r")) == NULL)
    {
        fprintf(stderr, "File \"%s\" didn't open.\n", fileName);
        perror(fileName);
        exit(EXIT_FAILURE);
    }
    return fp;
}

/***************************************************************************
                                    (Hashing)
 ***************************************************************************/

#define MIN_ARGS 3                     // fewest command line arguments
#define FILE_ARG_IX 1                  // index of file name argument
#define BINS_ARG_IX 2                  // index of bin count argument

typedef struct Node NODE;
struct Node                            // type of each list node
{
    char* strng;                        // string for this node
    size_t count;                       // occurrences of this string
    NODE *left, *right;                         // next node in list
};

typedef struct                         // type of table array elements
{
    size_t nodes;                       // # of list nodes for this bin
    NODE *firstNode;                    // 1st node in this bin's list
} BIN;

typedef struct                         // type of hash table descriptor
{
    size_t bins;                        // bins in hash table
    BIN *firstBin;                      // first bin
} TABLE;

int HashFunction(const char* key, size_t bins)  // get bin value from key
{
    return((int)(strlen(key) % bins));           // value is length % bins
}

// CreateTable creates and initializes the hash table and its bins
TABLE* CreateTable(size_t bins)
{
    TABLE* hashTable;
    BIN* bin, * end;

    hashTable = (TABLE *)SafeMalloc(sizeof(TABLE));             // alloc desc struct
    hashTable->bins = bins;                            // how many bins
    // alloc bins
    hashTable->firstBin = (BIN *)SafeMalloc(bins * sizeof(BIN));
    end = hashTable->firstBin + bins;                  // end of bins

    for (bin = hashTable->firstBin; bin < end; ++bin)  // initialize bins
    {
        bin->nodes = 0;                                 // no list nodes
        bin->firstNode = NULL;                          // no list
    }
    return(hashTable);
}

//
// BuildList searches bin bp of the list for a node representing the string in
// str.  If found, its string count will be incremented.  If not found, a new
// node for that string will be created, put at the top of the list, and its
// string count set to 1.
//
NODE* BuildList(BIN* bp, const char* str, size_t num_bins)
{
    NODE* pNode = bp->firstNode;                 

    if (pNode == NULL)                           // no matching node
    {
        size_t length = strlen(str) + 1;          // characters in string

        pNode = SafeMalloc(sizeof(NODE));         // allocate new node
        pNode->strng = SafeMalloc(length);        // storage for string
        memcpy(pNode->strng, str, length);        // store string
        pNode->count = 1;                         // set string count
        pNode->next = bp->firstNode;              // insert new node...
        bp->firstNode = pNode;                    // ...first in list
        ++bp->nodes;                              // update node count
    }
    else                                         // found matching node
        ++pNode->count;                           // increment string count
}

// PrintTable prints the hash table.
void PrintTable(const TABLE* hashTable)
{
    BIN* bin, * end;

    end = hashTable->firstBin + hashTable->bins;       // end of bins
    for (bin = hashTable->firstBin; bin < end; ++bin)  // visit bins
    {
        NODE* node;
        printf("%zu entries for bin %d:\n",
            bin->nodes, (int)(bin - hashTable->firstBin));
        // Visit nodes
        for (node = bin->firstNode; node != NULL; node = node->next)
            printf("%4zu  %s\n", node->count, node->strng);
    }
}

// FreeTable frees the hash table.
void FreeTable(TABLE* hashTable)
{
    BIN* bin, * end;

    end = hashTable->firstBin + hashTable->bins;       // end of bins
    for (bin = hashTable->firstBin; bin < end; ++bin)  // visit bins
    {
        NODE* node;
        for (node = bin->firstNode; node != NULL;)      // visit nodes
        {
            NODE* pNode = node;                          // save NODE pointer
            node = node->next;                           // point to next node
            free(pNode->strng);                          // free the string
            free(pNode);                                 // free the node
        }
    }
    free(hashTable->firstBin);                         // free all bins
    free(hashTable);                                   // free table descriptor
}

int main(int argc, char* argv[])
{
    char buf[LINE_LEN];                                // word string buffer
    char fileName[LINE_LEN];                           // file name buffer
    int howManyBins;                                   // bins to create
    TABLE* hashTable;                                  // pointer to hash table
    FILE* fp;

    // Read file name from command line.
    if (argc < MIN_ARGS || sscanf(argv[FILE_ARG_IX], BUFFMT "s", fileName) != 1)
    {
        fprintf(stderr, "No file name specified on command line\n");
        return EXIT_FAILURE;
    }
    fp = OpenFile(fileName);

    // Read bin count from command line.
    if (sscanf(argv[BINS_ARG_IX], "%d", &howManyBins) != 1)
    {
        fprintf(stderr, "No bin count specified on command line\n");
        return EXIT_FAILURE;
    }
    hashTable = CreateTable((size_t)howManyBins);   // allocate table array

    //
    // The following loop will read one string at a time from stdin until EOF is
    // reached.  For each string read the BuildList function will be called to
    // update the hash table.
    //
    while (fscanf(fp, BUFFMT "s", buf) != EOF)      // get string from file
    {
        // Find appropriate bin.
        BIN* bin = &hashTable->firstBin[HashFunction(buf, (size_t)howManyBins)];
        BuildList(bin, buf, bin->nodes);                         // put string in list
    }
    fclose(fp);
    PrintTable(hashTable);                          // print all strings
    FreeTable(hashTable);                           // free the table
    return(EXIT_SUCCESS);
}
