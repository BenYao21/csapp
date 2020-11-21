/* 
 * Code for basic C skills diagnostic.
 * Developed for courses 15-213/18-213/15-513 by R. E. Bryant, 2017
 */

/*
 * This program implements a queue supporting both FIFO and LIFO
 * operations.
 *
 * It uses a singly-linked list to represent the set of queue elements
 */

#include <stdlib.h>
#include <stdio.h>

#include "harness.h"
#include "queue.h"

/*
  Create empty queue.
  Return NULL if could not allocate space.
*/
queue_t *q_new()
{
    queue_t *q = NULL;
	if((q = malloc(sizeof(queue_t)))) 
	{
		q->head = NULL;
		q->tail = NULL;
		q->size = 0;
		return q;
	}
    /* What if malloc returned NULL? */
    return NULL;
}

/* Free all storage used by queue */
void q_free(queue_t *q)
{
    /* How about freeing the list elements? */
    /* Free queue structure */
    if(q)
	{
		list_ele_t *i = q->head;
		while(i)
		{
			list_ele_t *tmp = i;
			i = i->next;
			free(tmp);
		}
	}
	free(q);
}

/*
  Attempt to insert element at head of queue.
  Return true if successful.
  Return false if q is NULL or could not allocate space.
 */
bool q_insert_head(queue_t *q, int v)
{
    list_ele_t *newh;
    /* What should you do if the q is NULL? */
    if(q)
	{
		if((newh = malloc(sizeof(list_ele_t))))
		{
			newh->value = v;
			newh->next = q->head;
			q->head = newh;
			if(!q->size)
			{
				q->tail = newh;
			}
			++q->size;
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
    /* What if malloc returned NULL? */
}


/*
  Attempt to insert element at tail of queue.
  Return true if successful.
  Return false if q is NULL or could not allocate space.
 */
bool q_insert_tail(queue_t *q, int v)
{
    /* You need to write the complete code for this function */
    /* Remember: It should operate in O(1) time */
    list_ele_t *newh;
	if(q)
	{
		if((newh = malloc(sizeof(list_ele_t))))
		{
			newh->value =v;
			newh->next = NULL;
			if(q->tail)
			{
				q->tail->next = newh;
				q->tail = newh;
				++q->size;
			}
			else
			{
				q->head = q->tail = newh;
				++q->size;
			}
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

/*
  Attempt to remove element from head of queue.
  Return true if successful.
  Return false if queue is NULL or empty.
  If vp non-NULL and element removed, store removed value at *vp.
  Any unused storage should be freed
*/
bool q_remove_head(queue_t *q, int *vp)
{
    /* You need to fix up this code. */
    if(!q || !q->size)
	{
		return false;
	}
	else
	{
		if(vp)
		{
			*vp = q->head->value;
		}
		list_ele_t *tmp = q->head;
		q->head = q->head->next;
		free(tmp);
		--q->size;
		return true;
	}
}

/*
  Return number of elements in queue.
  Return 0 if q is NULL or empty
 */
int q_size(queue_t *q)
{
    /* You need to write the code for this function */
    /* Remember: It should operate in O(1) time */
    return q->size;
}

/*
  Reverse elements in queue.

  Your implementation must not allocate or free any elements (e.g., by
  calling q_insert_head or q_remove_head).  Instead, it should modify
  the pointers in the existing data structure.
 */
void q_reverse(queue_t *q)
{
    /* You need to write the code for this function */
	if(q && q->size)
	{
		int cache[q->size];
		list_ele_t *tmp = q->head;
		for(int i = q->size - 1; (i >= 0) && (tmp != NULL); --i)
		{
			cache[i] = tmp->value;
			tmp = tmp->next;
		}
		tmp = q->head;
		for(int i = 0; (i < q->size) && (tmp != NULL); ++i)
		{
			tmp->value = cache[i];
			tmp = tmp->next;
		}
	}
}

