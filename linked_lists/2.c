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
                head = (head->next);
        }

        while ((*prev).next) {
                last = (*prev).next;
                if (last->next != NULL) {
                        if ((*last).n == val) {
                                struct node *tmp = last;
                                (*prev).next = (*last).next;
                                free(tmp);
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
/*
o
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
*/
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

                newhead->next = tmp;
                newhead->next = head;
                *head = *newhead;
                free(newhead);
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
                        last = (*last).next; 
                } 
        }
}

void val_insert_i2(struct node *head, int i, int val)
{
        if (i < 1) {
                puts("sorry positions start with 1\n");
                return;
        }
        
        if (i == 1) {
                struct node *newhead = malloc(sizeof(struct node));
                //MEMORY LEAK
                ////!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
               // struct node *tmp =  malloc(sizeof(struct node));
                //*tmp = *head;


                newhead->n = val;
                //newhead->next = tmp;
                newhead->next = head;
                head = newhead;
                free(newhead);
                return;
        }

        int j = 1;
        struct node *last = head;
        while ((*last).next != NULL) {
                j++;
                if (j == i) {
                        struct node *tmp = (*last).next; 
                        (*last).next = malloc(sizeof(struct node));
                        (*(*last).next).n = val;
                        (*(*last).next).next = tmp;
                } else {
                        last = (*last).next; 
                } 
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



void val_insert_i3(struct node **head, int i, int val)
{
        if (i < 1) {
                return;
        }
        
        if (i == 1) {
                struct node *newhead = malloc(sizeof(struct node));
                newhead->n = val;
                newhead->next = *head;
                *head = newhead;
                return;
        }

        int j = 1;
        struct node *last = *head;
        while ((*last).next != NULL) {
                j++;
                if (j == i) {
                        struct node *tmp = (*last).next; 
                        (*last).next = malloc(sizeof(struct node));
                        (*(*last).next).n = val;
                        (*(*last).next).next = tmp;
                } else {
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
                                struct node *tmp = last->next;
                                (*last).next = (*(*last).next).next;
                                free(tmp);
                                puts("found your val!\n:");
                        }
                }
                last = (*last).next; 
        }
}


void free_list(struct node *head)
{
        struct node *last = head->next;
        while (last!= NULL)  {
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


/*{
    struct node *newNode;

    newNode = malloc(sizeof(struct node));

    if(newNode == NULL)
    {
        printf("Unable to allocate memory.");
    }
    else
    {
        newNode->n= data; // Link data part
        newNode->next = head; // Link address part

        head = newNode;          // Make newNode as first node

        printf("DATA INSERTED SUCCESSFULLY\n");
    }
}

*/




/*
void val_insert_i(struct node *head, int i, int val) 
{
        if (i < 1) {
                puts("sorry positions start with 1\n");
                return;
        }
        
        if (i == 1) {
*/
/*


                struct node *newhead = malloc(sizeof(struct node));
          //MEMORY LEAK here!!!

                newhead->n = val;
                newhead->next = head;
                head = newhead;
                return;

        int j = 1;
        struct node *last = head;
        while ((*last).next != NULL) {
                j++;
                if (j == i) {
                        struct node *tmp = (*last).next; 
                        (*last).next = malloc(sizeof(struct node));

                        last->next->n = val;

                        (*(*last).next).next = tmp;
                } else {
                        last = (*last).next; 
                } 
        }
        return;
}

*/

/*
void append2(struct node *head, int val)
{
        while ((*head).next->next != NULL) {
                head = (*head).next; 
        }
        
        head->next = malloc(sizeof(struct node));
        head->next->n = val;
        head->next->next =  malloc(16);
        head->next->next->next = NULL; 
        head->next->next->n= 0; 
}
*/


int append(int val, struct node *head)

{    
    struct node *current = head;
    struct node *newnode = malloc(16);


    newnode->n= val;
    newnode->next = NULL;

    while (current->next) {
        current = current->next;
    }    
    current->next = newnode;
    return 0;
}
int isin(struct node *head, int val)
{
        struct node *last = head;
        int is_in = 0;
        while ((*last).next != NULL) {
                if (last->n == val)
                        is_in = 1;
                last = (*last).next; 
        }
        return is_in;
}


struct node *set2(struct node *head)
{

        struct node *tmp = head;

        struct node *been = malloc(sizeof(struct node));
        been->next = NULL;

        while (tmp->next != NULL) {
                if (!isin(been, tmp->n)) {
                        append(tmp->n, been);
                }
                tmp = (*tmp).next; 
        }

        print(been);
        return been;
}

struct node *set(struct node *head)
{

        struct node *tmp = head;

        struct node *been = malloc(sizeof(struct node));
        been->next = NULL;

        while (tmp->next != NULL) {
                if (!isin(been, tmp->n)) {
                        append( tmp->n, been);
                }
                tmp = (*tmp).next; 
        }

        print(been);
        free_list(head);
        free(head);
        free(tmp);
        return been;
}

struct node *listcat(struct node *head1, struct node *head2)
{
        struct node *last = head1;
        while ((*last).next->next != NULL)  {
                last = (*last).next; 
        }
        last->next = head2;
        return head1;
}

struct node *united_sets(struct node *l1, struct node *l2)
{
        return listcat(set(l1), set(l2));
}


long long unsigned int LEAK = 0;

void myappend(struct node *h, int val)
{
        if (len(h) == 0) {
                static called = 0;
                h->n = val;
                h->next = calloc(16,1);

                if (called == 0)
                        LEAK = (long long unsigned int) ( h->next);
                printf("in appebd: %llx\n", (struct node *) h->next);
                puts("447");
                called++;
                return;
        }
        val_insert_i3(&h, len(h) + 1, val);

}


struct node *set3(struct node *h )
{
        struct node *lst = calloc(16,1);
        struct node *last = h;
        while ((*last).next != NULL)  {
               if( 0 ==  isin(lst, (*last).n)) {
                       myappend(lst, last->n);
               } else {
                       }
                last = (*last).next;
               
        }
        return lst;
}
        

struct node *solution(struct node *l1, struct node *l2)
{
        struct node *s1 = set3(l1);
        struct node *s2 = set3(l2);


        struct node *r = listcat(s1, s2);
        //print(s1);
       // free(s2);
        return r;
}



int main(void)
{

        struct node *head1 = malloc(sizeof(struct node));
        puts("Inputting first list of ints; do 0 to stop;");
        rinit(head1);
        print(head1);

        struct node *head2 = malloc(sizeof(struct node));
        puts("Inputting first list of ints; do 0 to stop;");
        rinit(head2);
        print(head2);
 
       /* struct node *head2 = malloc(sizeof(struct node));
        puts("Inputting second list of ints; do 0 to stop;");
        rinit(head2);
        print(head2);
*/
 //       val_insert_i3(&head1, 1,  1111);
        //print(head1);
/*
        val_insert_i3(&head1, 1,  1111);
        val_insert_i3(&head1, 2,  2222);
        print(head1);
 */  //     printf("%d", head1->n);

         struct node *hren = solution(head1, head2);
         
         print(hren);

         free_list(hren);
         free(hren);
         
 //      struct node *r = set3(head1);
  //     print(r);
   //    free_list(r);
    //   free(r);
//val_insert_i3(&head1, 1, 88);
//myappend(head1, 66);

//append3(head1, 99);
        
        free_list(head1);
  //      free_list(head2);
        free(head1);
   //     free(head2);
        free_list(head2);
  //      free_list(head2);
        free(head2);
/*
        struct node *s1 = (set3(head1));
        struct node *s2 = (set3(head2));


        struct node *r = listcat(s1, s2);
        print(r);

        print(s1);
        return 0; 
      
        free_list(s1);
        free_list(s2); */
        printf("leak: %llx\n", (struct node *) LEAK);
        if (LEAK)
                free((struct node *)LEAK);
        //if(leak)
          //      free(leak);


      return 0;
}
