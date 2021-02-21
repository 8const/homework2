#include <stdlib.h>
#include <stdio.h>

/*
 *
 * This code does linked lists and stuff with them.
 * I currently prefer (*node).next instead of node->next because I'm a moron.
 *
 * many files
 * check correctness
 * in erase after only erase 1 el after not all elms
 * exclude 0 from list
 *
 *
 */

struct node {
        int n;
        struct node *next;
};

/* recursive print from head to end */
void rprint(struct node *head)
{
	if (head == NULL)
		printf("NULL\n");
	else {
                if ( /*(*head).n != 0 ||*/  head->next != NULL) {
	        	printf("%d\n", (*head).n);
		        rprint((*head).next);
                }
        }
}

/* recursive filling from stdin */
void rinit(struct node *head)
{
        static int c = 0;
        int a;
        printf("list[%d] = ", c);
        scanf("%d", &a);
        if (a == 0) {
               (*head).next = NULL;
               head = NULL;
               return;
        } else {
                c++;
                (*head).n = a;
                (*head).next = malloc(sizeof(struct node));
                rinit((*head).next);

        }
}

void del_by_val(struct node *head, int val)
{
        struct node *last = head;
        struct node *prev = last;
        if (head->n == val) {
                puts("!!!");
                *head = *(head->next);
        }

        while ((*prev).next) {
                last = (*prev).next;
                if (last->next != NULL) {
                        if ((*last).n == val) {
                                (*prev).next = (*last).next;
                        
                                }
                        }
                prev = (*prev).next; 
        }
}



void insert_after(struct node *head, int val)
{
        struct node *last = head;
        while ((*last).next != NULL) {
                if ((*last).n == val) {
                        struct node *tmp = (*last).next; 
                        (*last).next = malloc(sizeof(struct node));
                        puts("found your val!\ninsert new el after it:");
                        scanf("%d", &((*(*last).next).n));
                        (*(*last).next).next = tmp;
                }
                last = (*last).next; 
        }
}



/* init with natural numbers */
void init(struct node *head, int len)
{ 
        struct node *last = head;
        for (int i = 0; i < len-1; i++) {
                (*last).n = i;
                (*last).next = malloc(sizeof(struct node));
                last = (*last).next;
        }
        
        (*last).n = len-1; 
        (*last).next = NULL; 
}

/* normal print of all elements in list */
void print(struct node *head)
{
        struct node *last = head;
        printf("[ ");
        while ((*last).next != NULL)  {
                printf("%d ", (*last).n);
                last = (*last).next; 
        }
        printf("]\n\n\n\n");
}



/* inserts at given posetion from stdin */
void insert_i(struct node *head, int i)
{
        if (i < 1) {
                puts("sorry positions start with 1\n");
                return;
        }
        
        if (i == 1) {
                struct node *newhead = malloc(sizeof(struct node));
                struct node *tmp =  malloc(sizeof(struct node));
                *tmp = *head;

                puts("found your index!\ninsert new el in it:");
                int v;
                scanf("%d", &v);

                newhead->n = v;
                newhead->next = tmp;
                *head = *newhead;
                return;
        }

        int j = 1;
        struct node *last = head;
        while ((*last).next != NULL) {
                j++;
                if (j == i) {
                        struct node *tmp = (*last).next; 
                        (*last).next = malloc(sizeof(struct node));
                        puts("found your index!\ninsert new el after it:");
                        scanf("%d", &((*(*last).next).n));
                        (*(*last).next).next = tmp;
                }
                last = (*last).next; 
        }
}

/* erases fter given value */
void erase_after(struct node *head, int val)
{
        struct node *last = head;
        while ((*last).next != NULL) {
                if ((*last).n == val) {
                        if ((*(*last).next).next) {
                                (*last).next = (*(*last).next).next;
                                puts("found your val!\n:");
                        }
                }
                last = (*last).next; 
        }
}


int main(void)
{

        struct node head;
        struct node *phead = &head;
        puts("inputting list until you input 0 as element:");
        rinit(phead);

        print(phead);
        rprint(phead);

        puts("let's insert after value!\ninput value: ");
        int v;
        scanf("%d", &v);
        insert_after(phead, v);
        print(phead);

        puts("let's insert by position!\ninput index: ");
        int i;
        scanf("%d", &i);
        insert_i(phead, i);
        print(phead);
        
        puts("let's eraise el in list after value!\ninput value: ");
        scanf("%d", &v);
        erase_after(phead, v);
        print(phead);
 
        puts("let's eraise element by value!\ninput value: ");
        scanf("%d", &v);
        del_by_val(phead, v);
        print(phead);

        return 0;
}











