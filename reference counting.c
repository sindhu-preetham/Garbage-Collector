#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int count;
    void *data;
} RefCount;

RefCount* create(void *data) {
    RefCount *ref = malloc(sizeof(RefCount));
    if (ref) {
        ref->count = 1;
        ref->data = data;
    }
    return ref;
}

void add(RefCount *ref) {
    if (ref) {
        ref->count++;
    }
}

void release(RefCount *ref) {
    if (ref && --ref->count == 0) {
        free(ref->data);
        free(ref);
    }
}

void* get_data(RefCount *ref) {
  if (ref){
    return ref->data;
}
return NULL;
}

int main() {
    int *num = malloc(sizeof(int));
    *num = 45;

    RefCount *ref = create(num);
    printf("Data: %d\n", *get_data(ref));

    add(ref);
    release(ref); 
    release(ref); 

    return 0;
}
