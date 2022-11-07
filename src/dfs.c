/*
 * Search an expression using DFS.
 */

#include <stdio.h>		/* scanf, printf */
#include <stdlib.h>		/* abort */
#include <stdbool.h>		/* bool, true, false */
#include "dfs.h"

stack* head = NULL;

void DFT (node * root)
{
  stack *main = malloc(sizeof(stack));

  main-> next = NULL;

  main -> node = root;

  node current = *root;

  while (!isEmpty(main)){
    current = *top(main);
    main = pop(main);

  if (current.rchild != NULL){
    main = push(main, current.rchild);
  }
  if (current.lchild != NULL){
    main = push(main,current.lchild);
  }
  print_node(&current);
  }
}

node *make_node (int num, node * left, node * right)
{
	node *p = malloc(sizeof(node));
  p->lchild = left;
  p->rchild = right;
  p->num = num;
  p->visited = false;
	return p;

}

void free_node (node * p)
{
  if (p->lchild == NULL && p->rchild == NULL)
  {
    free(p);
  }
  else if (p->lchild != NULL)
  {
    free(p->lchild);
  }
  else if (p->rchild != NULL)
  {
    free(p->rchild);
  }
}


void print_node (node * p)
{
  if (p == NULL)
    printf ("NULL\n");
  else
    printf ("%d", p->num);
}


void print_tree (node * p, int depth)
{
  for (int i = 0; i < depth; i = i + 1)
    printf (" ");
  printf ("| ");

  if (p == NULL)
    printf ("NULL\n");
  else
    printf ("[%d]\n", p->num);


  if (p->lchild)
    {
      print_tree (p->lchild, depth + 1);
    }

  if (p->rchild)
    print_tree (p->rchild, depth + 1);
}

stack *push (stack * topp, node * node)
{
  stack *new = malloc(sizeof(stack));
  new -> next = topp; 
  topp = new;
  topp -> node = node;

	return topp;
}

bool isEmpty (stack * topp)
{
  if(topp == NULL){
    return true;
  }
  else
  return false;
}

node *top (stack * topp)
{
	return topp->node;
}

// Utility function to pop topp  
// element from the stack 

stack *pop (stack * topp)
{
  topp=topp->next;
  return topp;
	
}

void print_stack (stack * topp)
{
  struct stack *temp = topp;

  while (temp != NULL)
    {

      print_node (temp->node);
      printf ("\n");

      temp = temp->next;
    }

  printf ("====\n");

  return;
}
