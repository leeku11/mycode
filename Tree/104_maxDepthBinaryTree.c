#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct TreeNode{
    int             val;
    struct TreeNode *left;
    struct TreeNode *right;
}TreeNode_t;


typedef struct Queue{
    int front;
    int rear;
    int length;
    int cnt;
    void **element;
}Queue_t;

int testArray[] = {3, 9, 20, -1, -1, 15, 7};
bool isEmpty(Queue_t *q)
{
    return (q->cnt == 0);
}

Queue_t *createQ(int length)
{
    Queue_t *q;
    
    q           = malloc(sizeof(Queue_t));
    q->element  = malloc(sizeof(void *) * length);
    q->rear     = 0;
    q->front    = 0;
    q->length   = length;
    q->cnt      = 0;
    return q;
}

int enqueue(Queue_t *q, void *t)
{
    if(q->cnt == q->length)
    {
        printf("Q overflow \n");
        return -1;
    }else
    {
        q->element[q->rear] = t;
        
        q->rear++;
        if(q->rear == q->length)    // lapped around
        {
            q->rear = 0;
        }
        q->cnt++;
    }
    //printf("enQ : len %d, cnt %d, f %d, r, %d \n", q->length, q->cnt, q->front, q->rear);
    return 0;
}

void *dequeue(Queue_t *q)
{
    void *ret;
    if(q->cnt == 0)
    {
        printf("Q underflow \n");
        return NULL;
    }else
    {
        ret = q->element[q->front];
        
        q->front++;
        if(q->front == q->length)    // lapped around
        {
            q->front = 0;
        }
        q->cnt--;
    }
    //printf("deQ : len %d, cnt %d, f %d, r, %d \n", q->length, q->cnt, q->front, q->rear);

    return ret;
}

typedef struct Stack{
    int top;
    int bottom;
    int length;
    int cnt;
    int maxCnt;
    void **element; 
}Stack_t;

Stack_t *createStack(int length)
{
    Stack_t *s;
    
    s           = malloc(sizeof(Stack_t));
    s->element  = malloc(sizeof(void *) * length);
    s->top      = 0;
    s->bottom   = 0;
    s->length   = length;
    s->cnt      = 0;
    s->maxCnt   = 0;
    return s;
}

int push(Stack_t *s, void *t)
{
    if (s->cnt == s->length)
    {
        printf("Stack Overflow \n");
        return -1;
    }else
    {
        s->element[s->top] = t;
        
        s->top++;
        s->cnt++;
    }
    printf("push : top %d, cnt %d \n", s->top, s->cnt);
    return 0;
}

void* pop(Stack_t *s)
{
    int ret;
    if (s->cnt == 0)
    {
        printf("Stack Underflow \n");
        return -1;
    }else
    {
        s->top--;
        ret = s->element[s->top];
        s->cnt--;
    }

    printf("pop : top %d, cnt %d \n", s->top, s->cnt);
    return ret;
}

int getStackSize(Stack_t *s)
{
    return s->cnt;
}

TreeNode_t *createNode(int val)
{
    TreeNode_t *node;
    node        = malloc(sizeof(TreeNode_t));
    node->val   = val;
    node->left  = NULL;
    node->right = NULL;
    return node;
}



TreeNode_t *arrayToTree(int *nums, int length)
{
    int depth;
    int i;
    Queue_t *q;
    TreeNode_t *r, *t, *root;

    q = createQ(length);
    root = createNode(nums[0]);
    enqueue(q, (void *)root);

    printf("     -%d-\n", nums[0]);

    i = 1;
    while(!isEmpty(q) && i < length)
    {
        r = (TreeNode_t *)dequeue(q);
        if(nums[i] != -1)
        {
            t = createNode(nums[i]);
            r->left = t;
            enqueue(q, (void *)t);
            printf("%d -", t->val);
        }
        i++;
        if(nums[i] != -1)
        {
            t = createNode(nums[i]);
            r->right = t;
            enqueue(q, (void *)t);
            printf(" - %d", t->val);
        }
        i++;
        printf(" \n");
    }
    return root;
}

int maxDepth(TreeNode_t *root)
{
    Stack_t     *s;
    TreeNode_t  *t;
    s = createStack(sizeof(testArray)/sizeof(int));

    push(s,(void *) root);

    while(getStackSize(s) != 0)
    {
        t = (TreeNode_t *) pop(s);
        if(t->right != NULL)
        {
            push(s, (void *)t->right);
        }
        if(t->left != NULL)
        {
            push(s, (void *)t->left);
        }
    }
}

int main(int argc, char *argv[])
{
    TreeNode_t *root;
    int ret;

    root = arrayToTree(testArray, sizeof(testArray)/sizeof(int));

    ret = maxDepth(root);
    printf("maxDepth = %d \n", ret);

    return 0;
}