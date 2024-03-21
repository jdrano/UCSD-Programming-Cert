//
// Jose Medrano, U09845800
// jcdrano@gmail.com
// C/C++ Programming II : Dynamic Memory and File I/O Concepts
// 177752, Prof. Mitchell
// 02/18/24
// C2A6E4_List.c
// Win10
// Visual Studio 2022
//
// File contains functions that creates a Linked List (Nodes), prints them, 
// and then frees all memory associated with the List.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "C2A6E4_List-Driver.h"

#define BUFSIZE 256

List *CreateList(FILE *fp)
{
    char str[BUFSIZE];
    List *head = NULL;

    // Read from file until we reach EOF
    while (fscanf(fp, "%255s", str) != EOF)
    {
        size_t length = strlen(str) + 1;
        bool matched = false;
        List *prev = head;
        List *tmp = head;

        // Search List for same string
        while (tmp)
        {
            // Match found, increment count and read new string
            if (strcmp(tmp->str, str) == 0)
            {
                tmp->count++;
                matched = true;
                break;
            }

            prev = tmp;
            tmp = tmp->next;
        }

        // Add node to the end if there no match found
        if (!matched)
        {
            List *newNode = (List *)malloc(sizeof(List));

            // Check for out of memory error
            if (newNode == NULL)
            {
                fprintf(stderr, "Memory allocation failed");
                exit(EXIT_FAILURE);
            }

            // Initialize values
            newNode->str = (char *)malloc(length);

            // Check for out of memory error
            if (newNode->str == NULL)
            {
                fprintf(stderr, "Memory allocation failed");
                exit(EXIT_FAILURE);
            }

            memcpy(newNode->str, str, length);
            newNode->next = NULL;
            newNode->count = 1;

            // Establish head if non-existent
            if (!head)
            {
                head = newNode;
            }
            else
            {
                prev->next = newNode;
            }
        }
    }

    return head;
}

List *PrintList(const List *head)
{
    // Print out every single node
    for (const List *tmp = head; tmp != NULL; tmp = tmp->next)
    {
        printf("%-13s %2d ea\n", tmp->str, tmp->count);
    }

    return (List *)head;
}

void FreeList(List *head)
{
    // Constantly free head of List and adjust new head for deletion
    while (head != NULL)
    {
        List *tmp = head;
        head = head->next;
        free(tmp->str);
        free(tmp);
    }
}
