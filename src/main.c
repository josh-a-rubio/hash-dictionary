#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define TABLE_SIZE 26 //number of buckets

//node for linked list in each bucket
typedef struct node {
    char word[50]; //store the word
    struct node* next; //pointer to next node in bucket
} node;

//hash table: array of pointers to linked lists
node* table[TABLE_SIZE];

int hash(const char* word);
void insert(const char* word);
void lookup(const char* word);
void printAll(void);
void freeTable(void);

int main (void) {
    char input[50];

    while (1) {
        printf("Enter word (or type EXIT to quit): ");
        scanf("%49s", input);
        if (strcmp(input, "EXIT") == 0) {
            break;
        }

        insert(input);
        lookup(input);
        printAll();
    }
    freeTable();
    return 0;

}


//hash function
int hash(const char* word) {
    int sum = 0;
    for (int i = 0; word[i] != '\0'; i++) {
        sum += word[i]; //add ASCII values of letter
    }
    return sum % TABLE_SIZE; //bucket index
}

//insert word into hash table
void insert(const char* word){
    int index = hash(word); //find bucket
    node* cursor = table[index]; //head of linked list

    //check if word exists
    while (cursor != NULL) {
        if (strcmp(cursor->word, word) == 0){
            printf("Already exists: %s\n", word);
            return; //word already exits
        }
        cursor = cursor->next;
    }

    //create new node
    node* new_node = malloc(sizeof(node));
    if (!new_node) {
        printf("Memory error");
        return;
    }
    strcpy(new_node->word, word);
    new_node->next = table[index]; //insert at head
    table[index] = new_node;

    printf("Inserted: %s\n", word);
}

//lookup word in hashtable
void lookup(const char* word) {
    int index = hash(word);
    node* cursor = table[index];

    while (cursor != NULL) {
        if (strcmp(cursor->word, word) == 0) {
            printf("Found %s\n", word);
            return;
        }
        cursor = cursor->next;
    }
    printf("Not Found: %s\n", word);
}

//print entire hash tab;e
void printAll(void) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("Bucket %d: ", i);
        node* cursor = table[i];

        if (cursor == NULL) {
            printf("empty");
        }

        while (cursor != NULL) {
            printf("%s -> ", cursor->word);
            cursor = cursor ->next;
        }
        printf("\n");
    }
}

//free all memory 
void freeTable(void) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        node* cursor = table[i];
        while (cursor != NULL) {
            node* temp = cursor;
            cursor = cursor->next;
            free(temp);
        }
        table[i] = NULL;
    }
}

