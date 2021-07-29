#include <stddef.h>
#include "ll_cycle.h"

int ll_has_cycle(node *head) {
   if (head == NULL) {
     return 0;
   } else if (head -> next == NULL) {
     return 0;
   } else if (head -> next -> next == NULL) {
     return 0;
   }
   node* fast_ptr = head -> next -> next;
   node* slow_ptr = head -> next;
   while (fast_ptr != slow_ptr) {
     if (fast_ptr -> next == NULL) {
       return 0;
     } else if (fast_ptr -> next -> next == NULL) {
       return 0;
     } else {
       fast_ptr = fast_ptr -> next -> next;
       slow_ptr = slow_ptr -> next;
     }
   }
   return 1;

}
