/ Homework 5
// Created by Daivik Dinesh
// SID- 913296561
// ECS 030 Fall Quarter 2015
// words.c - Program to sort words existing in one or multiple files and display them with the number of times they appear in the file (count)

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

struct node //Structure to create linked list
{
        char *word; //Variable to hold the word
        int count;// Variable to count number of times a word occurs in file
        struct node *next; // Pointer pointing to next node of list
};

struct node *head = NULL; // Pointer pointing to first element of list

struct node* crnode(char* n) //Function to create node in linked list 
{
	struct node *p; // Declaring pointer of structure type node

        if(n == NULL) // Base case
                return NULL;

        if((p = malloc(sizeof(struct node))) == NULL) //To create node
                return (NULL);

        if((p->word = malloc(strlen(n)+1)) == NULL) //To create word
                return NULL;

        strcpy(p->word,n); //Initializing node 
        p->count = 1;// Sets count variable to 1
        p->next = NULL;

        return(p); //Pointer now points to the new node 
}

struct node *innode(struct node *new) //Function to insert  node and sort words
{
        //Started insertion sort algorithm in this block

        struct node *before, *temp;// Declaring pointers to structure
	if(head == NULL) //Head is put to point at top
        {
                return(new);
        }

        if(strcmp(head->word, new->word) > 0) //If head is before first node
        {
                new->next = head;
                return(new);
        }

        before = head;
        temp = head->next;

        while(temp != NULL && strcmp(temp->word, new->word) < 0)//To insert node
        {
                before = temp;
                temp = temp->next;// Points to next pointer
        }

        new->next = temp;// temp points to new->next
        before->next = new;// before->next is new node
	 return(head);
}

int check(char* y) //Function to check for repeating words to keep count
{
        struct node *p;// Structure pointer p

        for( p = head; p !=NULL; p =p->next) //To traverse through the list 
        {

                if (strcmp(p->word, y) == 0)// To compare extracted word and word in existing word
                {
                        p->count++; // Increments count
                        return 1;
                }

        }
return 0;
}

void printnode(struct node * p) // Function to print the members of list
{
	for( p = head; p != NULL; p = p->next) // To traverse through the list 
                printf("%5d %s\n", p->count, p->word);//Formatted print output
}

void readfile(FILE *fp)// Function to read through the file
{
        char line[2048];// Line of input
        char wrd[100];// Word to be pushed to list

        int i = 0;//Line number variable
        char*x;// Pointer used for line's position
        char*y;// Pointer used for word 

        struct node *n;// Structure pointer n


        while(fgets(line, 2048, fp) != NULL)// Reads the input line-by-line
        {
                i++;// Line number changing

                for( x = line; *x; )// Uses char pointer to read char in line
                {
			while(*x && !isalnum(*x))//If char is not alphanum
                                x++;// Continue

                        if(!(*x)) // Checks if char in the word is null or not (in order to continue traversing)
                                break;
                        *wrd='\0';
                        y = wrd;//Set word pointer to the starting index of wrd

                        while( isalnum(*x))//If alphanum char is encountered
                        {
                                *y++ = *x++;//Move along line AND word to insert

                        *y  = '\0';//Adding null statement at the end
                        }

                        if(*wrd=='\0') //To check for new words in the line 
                                continue;

                        if(check(wrd) != 1)//Checking for repeated words
                        {
                                if((n = crnode(wrd)) == NULL)// Check for not enough memory being allocated
				  {
                                        fprintf(stderr, "%s, file %s, line %d: ran out of memory\n", wrd, fp, i); // Prints out error for not allocating memory
                                        exit (1);
                                }
                                else
                                        head = innode(n);// Insert node function is invoked
                        }
                }
        }
}


int main(int argc, char *argv[])// Command line input declaration
{
        if(argc == 1)// Check for number of arguments
         return 0;


        FILE *fp;//File pointer
        int arg = 1;// Declaration of current argument variable

        for(; argv[arg] != NULL; arg++) // To traverse through the input 
        {
                if((fp = fopen(argv[arg], "r")) == NULL) // Command to read from file by opening file stream buffer
                {
                        perror(argv[arg]);// Error for file not being able to be read
                        return 1;
                }

                else
                {
                        readfile(fp);// Invokes function to traverse through file and extract words
                        fclose (fp);// To close the file stream buffer
                }
        }

printnode(head);// Invokes function to print out the formatted desired output

return (0);
}
