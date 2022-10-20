#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
    int x;
    char y[50];
    struct node *next;
    struct node *prev;
}*start=NULL,*end=NULL;

void create()
{
    int num,i;
    struct node *new_node,*current;
    printf("\n Enter the node num:");
    scanf("%d",&num);
    for(i=0; i<num; i++)
    {
        new_node=(struct node*)malloc(sizeof(struct node));
        printf("\nEnter value of x:\n");
        printf("Enter new phone number:");
        scanf("%d",&new_node->x);
        printf("Enter person name:");
        scanf("%s",&new_node->y);
        //  new_node->next=NULL;
        new_node->prev=NULL;
        if(start==NULL&&end==NULL)
        {
            start=new_node;
            end=new_node;
            current=new_node;
        }
        else
        {
            current->next=new_node;
            new_node->prev=current;
            end=new_node;
            current=new_node;
        }
    }


}

void f_insert()
{
    struct node *new_node,*current;
    new_node=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter First node value of x:\n");
    scanf("%d",&new_node->x);
    new_node->next=NULL;
    new_node->prev=NULL;
    current=start;
    start=new_node;
    new_node->next=current;
    current->prev=new_node;

}

void l_insert()
{
    struct node *new_node,*current;
    new_node=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter Last node value of x:\n");
    scanf("%d",&new_node->x);
    new_node->next=NULL;
    new_node->prev=NULL;
    current=end;
    current->next=new_node;
    new_node->prev=current;
    end=new_node;
}

int search(int s_key)
{
    int pos=0;
    struct node *current;
    current=start;
    while(current!=NULL)
    {
        pos++;
        if(current->x==s_key)
        {
            return pos;
        }

        current=current->next;

    }
    return -1;

}
int search_name(char s_key)
{
    int pos=0;
    struct node *current;
    current=start;
    while(current!=NULL)
    {
        pos++;
        if(current->y==s_key)
        {
            return pos;
        }

        current=current->next;

    }
    return -1;

}

void ma_insert()
{
    int akey,pos,i=0;
    struct node *new_node,*current,*temp;
    new_node=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter Middle(after) node value of x:\n");
    scanf("%d",&new_node->x);
    new_node->next=NULL;
    new_node->prev=NULL;
    printf("\nEnter the key after which the new node created:\n");
    scanf("%d",&akey);
    pos=search(akey);
    current=start;
    for(i=0; i<pos-1; i++)
    {
        current=current->next;
    }
    //printf("current=%d",*current);
    temp=current->next;
    current->next=new_node;
    new_node->prev=current;
    new_node->next=temp;
    temp->prev=new_node;

}
void mb_insert()
{
    int akey,pos,i=0;
    struct node *new_node,*current,*temp;
    new_node=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter Middle(before) node value of x:\n");
    scanf("%d",&new_node->x);
    new_node->next=NULL;
    new_node->prev=NULL;
    printf("\nEnter the key before which the new node created:\n");
    scanf("%d",&akey);
    pos=search(akey);
    current=start;
    for(i=0; i<pos-1; i++)
    {
        current=current->next;
    }
    //printf("current=%d",*current);
    temp=current->prev;
    temp->next=new_node;
    new_node->prev=temp;
    new_node->next=current;
    current->prev=new_node;


}

void delete_ll()
{
    int i,pos;
    char d_key[50];
    struct node *current,*temp1,*temp2;
    printf("\nEnter the value for deleting:\n");
    scanf("%s",&d_key);
    pos=search_name(d_key);
    current=start;
    for(i=0; i<pos-1; i++)
    {
        current=current->next;
    }
    //printf("\n\ncurrent=%d\npos=%d",current->x,pos);
    if(current==start)
    {
        temp1=current->next;
        start=temp1;
    }
    else if(current->next==NULL)
    {
        //printf("\n\nIN LAST NODE\n");
        current=start;
        for(i=0; i<pos-2; i++)
        {
            current=current->next;
        }
        current->next=NULL;

    }
    else
    {
        temp2=current->next;
        temp1=start;
        for(i=0; i<pos-2; i++)
        {
            temp1=temp1->next;
        }
        temp1->next=temp2;
    }

    printf("\nDELETE SUCCESSFULLY");

}
void Modify_ll()
{
    int i,pos;
    char d_key[50];
    struct node *current,*temp1,*temp2;
    printf("\nEnter the Name for Number modify:\n");
    scanf("%s",&d_key);
    pos=search_name(d_key);
    current=start;
    for(i=0; i<pos-1; i++)
    {
        current=current->next;
    }
    //printf("\n\ncurrent=%d\npos=%d",current->x,pos);
    printf("Enter new phone number:");
    scanf("%d",&current->x);


    printf("\nModify SUCCESSFULLY");

}

void count()
{
    struct node *current;
    int count=0;
    current=start;

    while(current!=NULL)
    {
        count++;
        current=current->next;

    }
    printf("\n\nThe total num of node is=%d",count);
}

void f_display_ll()
{
    struct node *current;
    current=start;
    printf("\n\nThe doubly ll from start:\n");
    while(current!=NULL)
    {
        printf("%d-->",current->y);
        current=current->next;

    }
    printf("NULL");
}
void BubbleSort(int n, int arr[])
{
    int i, j, temp;

    for(i=0; i<n-1; i++)
    {
        for(j=i+1; j<n; j++)
        {
            if(arr[i] > arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}


void main()
{
    int x;
    printf("\t\tPhoneBook \n1.ADD New contact\n2.Search Number \n3.Modify \n4.Delete \n5.Show All Contract 0.Exit\nEnter Your Choice :");
    scanf("%d",&x);
    int s_key,pos;
    if (x==1)
    {
        create();

    }
    else if(x==2)
    {
        printf("\nEnter the Number to search:");
        scanf("%d",&s_key);
        pos=search(s_key);
        if(pos==-1)
        {
            printf("\nNOT FOUND");
        }
        else
        {
            printf("\nFOUND at : %d location.\n",pos);
            struct node *current;
            int count=0;
            current=start;

            while(current!=NULL && count==pos)
            {
                current=current->next;
                count++;

            }
            printf(" the name : %s",current->y);
        }
    }
    else if (x==3)
    {
        Modify_ll();
    }

    else if (x==4)
    {
        delete_ll();
    }
    else if (x==5)
    {
        f_display_ll();
        count();
    }
    else if(x==0)
    {
        exit(0);
    }

    /* f_display_ll();
     b_display_ll();
     f_insert();
     f_display_ll();
     b_display_ll();
     l_insert();
     f_display_ll();
     b_display_ll();
     printf("\nEnter the search key value:");
     scanf("%d",&s_key);
     pos=search(s_key);
     if(pos==-1)
     {
         printf("\nNOT FOUND");
     }
     else
     {
         printf("\nFOUND at : %d location.\n",pos);
     }
     ma_insert();
     f_display_ll();
     b_display_ll();
     mb_insert();
     f_display_ll();
     b_display_ll();
     /*delete_ll();
     display_ll();

     count();*/

}
