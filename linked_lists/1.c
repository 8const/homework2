#include <stdlib.h>
#include <stdio.h>

/*
 *
 * This code does linked lists and stuff with them.
 * I currently prefer (*node).next instead of node->next because I'm a moron.
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
		printf("%d\n", (*head).n);
		rprint((*head).next);
	}
}

/* recursive filling from stdin */
void rinit(struct node *head)
{
        static int c = 0;
        int a;
        printf("list[%d] = ",c );
        scanf("%d", &a);
        c++;

        (*head).n = a;
        if (a == 0) {
                (*head).next = NULL;
        } else {
                (*head).next = malloc(sizeof(struct node));
                rinit((*head).next);

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
        printf("[");
        while ((*last).next != NULL) {
                printf("%d, ", (*last).n);
                last = (*last).next; 
        }

        printf("%d", (*last).n);
        printf("]\n");
}

/* inserts after given value */
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

/* inserts at given posetion from stdin */
void insert_i(struct node *head, int i)
{
        int j = 1 ;
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
        puts("enteres erase");
        int j = 0;

        struct node *last = head;
        while ((*last).next != NULL) {
                puts("in loop");
                j++;
                printf("%d", j);
                if ((*last).n == val) {
                        (*last).next = NULL;
                        puts("NULLED after 5");
                        break;
                }
                last = (*last).next; 
                puts("check");
        }
}


void del_by_val(struct node *head, int val)
{
        struct node *last = head;
        struct node *prev = last;
        while ((*prev).next != NULL) {
                last = (*prev).next;
                if ((*last).n == val) {
                        (*prev).next = (*last).next;
                }
                prev = (*prev).next; 
        }
}



int main(void)
{
        struct node head2;
        init(&head2, 10);
        del_by_val(&head2, 5);
        print(&head2);
        return 0;
}
