#include <stdio.h>
#include <stdlib.h>

typedef struct {
	size_t count;
	size_t capacity;
} Header;

#define ARR_INITIAL_CAPACITY 256
#define arrSize(arr) (((Header*) (arr)) - 1)->count

#define arrPush(arr, val) do { \
	if(arr == NULL) { \
		Header* header = malloc(sizeof(Header) + ARR_INITIAL_CAPACITY * sizeof(*arr)); \
		header->count = 0; \
		header->capacity = ARR_INITIAL_CAPACITY; \
		arr = (void*) (header + 1); \
	} \
	\
	Header* header = (Header*) (arr) - 1; \
\
	if(header->count >= header->capacity) { \
		header->capacity *= 2; \
		header = realloc(header, sizeof(Header) + header->capacity * sizeof(*arr)); \
		arr = (void*) (header + 1); \
	} \
\
	(arr)[header->count++] = (val); \
} while(0)

#define arrFree(arr) free((Header*) (arr) - 1)

int main() {
	int *arr = NULL;

	arrPush(arr, 3);
	arrPush(arr, 5);
	
	printf("[");
	for(size_t i=0; i < arrSize(arr); ++i) {
		printf("%d%s", arr[i], i == arrSize(arr) - 1 ? "" : ", ");
	}
	printf("]");
	printf("\n");

	arrFree(arr);

	return 0;
}
