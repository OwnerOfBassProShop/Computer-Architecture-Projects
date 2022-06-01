#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

// Struct to hold data and the pointer to the next element.
struct node {
    char data;
    struct node* next;
};

// Append the new element to the start of the stack
struct node* push (struct node* stack, char data) {
    struct node* newElement = (struct node*)malloc(sizeof(struct node));

    newElement->data = data;
    newElement->next = stack;
    stack = newElement;


    return stack;
}

bool equal(char topElement, char popElement){

    if(topElement == '(' && popElement == ')'){
        return true;

    }else if(topElement == '[' && popElement == ']'){
        return true;

    }else if(topElement == '{' && popElement == '}'){
        return true;

    }else if(topElement == '<' && popElement == '>'){
        return true;

    }else{
        return false;
    }


}

// Remove element from the top of the stack
char pop ( struct node** stack ) {
    struct node* temp;
    char tmp;

    if (*stack != NULL) {
        temp = *stack;
        tmp = temp->data;
        *stack = temp->next;
        free(temp);

        return tmp;
    } else {
        return '\0';
    }
}

int main(int argc, char* argv[]) {

    FILE* fp = fopen(argv[1], "r");
    if (!fp) {
        perror("fopen failed");
        return EXIT_FAILURE;
    }

    struct node* root = NULL;
    bool balanced = true;

    char buff;
    while ( fscanf(fp, "%c", &buff) == 1 ) {

        switch(buff) {
            case '<' :
                root = push(root, buff);
                break;

            case '(' :
                root = push(root, buff);
                break;

            case '[' :
                root = push(root, buff);
                break;

            case '{' :
                root = push(root, buff);
                break;
            
            case '>' :
                if (!equal(pop(&root), buff)){
                    balanced = false;
                }
                break;

            case ')' :
                if (!equal(pop(&root), buff)){
                    balanced = false;
                }
                break;

            case ']' :
                if (!equal(pop(&root), buff)){
                    balanced = false;
                }
                break;

            case '}' :
                if (!equal(pop(&root), buff)){
                    balanced = false;
                }
                break;

            default :
                printf("Invalid character\n" );
        }
    }

    printf ( balanced ? "yes" : "no" );
    fclose(fp);
    return 0;
}