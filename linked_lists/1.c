#include <stdlib.h>
#include <stdio.h>

/*
 *
 * This code does linked lists and stuff with them.
 * I currently prefer (*node).next instead of node->next because I'm a moron.
 * Update: I switched to ->.
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
                if (head->next != NULL) {
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

/* deletes some accurances of value */
void del_by_val(struct node *head, int val)
{
        struct node *last = head;
        struct node *prev = last;
        if (head->n == val) {
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

/* inserts new element from sdin after given value in list */
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

/* inserts at given posetion from stdin; now even supports first position */
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
                } else {
                        puts("no such position in list\n");
                last = (*last).next; 
                } 
        }
}

/* erases one element after given value */
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

int len(struct node *head)
{
        struct node *last = head;
        int len = 0;
        while ((*last).next != NULL)  {
                len++;
                last = (*last).next; 
        }
        return len;
}

void free_list(struct node *head)
{
        struct node *last = head->next;
        while (last != NULL)  {
                struct node *tmp = last; 
                last = (*last).next; 
                free(tmp);

        }
}


void delete_all_by_value(struct node *head, int val) 
{
        for (int i = 0; i < 3*len(head); i++)
                del_by_val(head, val);
}

int main(void)
{

        struct node head;
        struct node *phead = &head;
        puts("Inputting list of ints; do 0 to stop;");
        rinit(phead);

        print(phead);
        rprint(phead);

        puts("Inserting elements after value!\nInput value: ");
        int v;
        scanf("%d", &v);
        insert_after(phead, v);
        print(phead);

        puts("Insert by position!\njnput index: ");
        int i;
        scanf("%d", &i);
        insert_i(phead, i);
        print(phead);
        
        puts("Removing elements from list after value!\nInput value: ");
        scanf("%d", &v);
        erase_after(phead, v);
        print(phead);

        puts("Removing all elements of given value!\nInput value: ");


        scanf("%d", &v);
        delete_all_by_value(phead, v);
        print(phead);

        free_list(phead);

        return 0;
}











