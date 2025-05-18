#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "my_allocator.h"

void menu() {
    printf("\nMenu:\n");
    printf("1. Allocate new array\n");
    printf("2. Free array\n");
    printf("3. Run Garbage Collector\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
}
int main() {
    void *allocated_array = NULL;
    int choice;
    size_t array_size = 0;

    printf("Custom Memory Allocator Test Program\n");
    print_menu();
    if (scanf("%d", &choice) != 1) {
      printf("Invalid input.\n");
      break;
      }

    switch (choice) {
          case 1:
              if (allocated_array != NULL) {
                  printf("Array already allocated. Please free it first.\n");
                  break;
                }

              printf("Enter array size: ");
                if (scanf("%zu",array_size == 0) {
                    printf("Invalid size.\n");
                    break;
                }

                allocated_array = my_malloc(array_size * sizeof(int));
                if (allocated_array == NULL) {
                    printf("Memory allocation failed.\n");
                } else {
                    printf("Memory allocated at %p\n", allocated_array);
                    add_ref(allocated_array);  
                }
                break;

            case 2:
                if (allocated_array != NULL) {
                    release_ref(allocated_array);  
                    allocated_array = NULL;
                    printf("Memory reference released.\n");
                } else {
                    printf("No memory to free.\n");
                }
                break;

            case 3:
                printf("Running garbage collector\n");
                gc_collect();
                break;

            case 4:
                printf("Exiting.\n");
                if (allocated_array != NULL) {
                    release_ref(allocated_array);
                    allocated_array = NULL;
                }
                gc_collect();
                return 0;

            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
        gc_collect();
    }
return 0;
}
