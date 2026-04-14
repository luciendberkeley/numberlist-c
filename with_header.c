#include <stdio.h>
#include <stdlib.h>

typedef struct {
	size_t count;
	size_t capacity;
} Header;

size_t arrSize(int* arr) {
	return (((Header*) arr) - 1)->count;
}

int* arrPush(int* arr, int val) {
	if(arr == NULL) {
		// Initialize
		size_t initialCapacity = 256;

		Header* head = malloc(sizeof(Header) + initialCapacity * sizeof(int));

		head->count = 0;
		head->capacity = initialCapacity;

		arr = (int*) (head + 1);
	}

	Header* header = ((Header*) arr) - 1;

	if(header->count == header->capacity) {
		header->capacity *= 2;
		header = realloc(header, sizeof(Header) + header->capacity * sizeof(int));
	}

	arr[header->count] = val;
	header->count++;

	return (int*) (header + 1);
}

int main() {
	int *arr = NULL;

	arr = arrPush(arr, 3);
	arr = arrPush(arr, 5);
	
	for(size_t i=0; i < arrSize(arr); ++i) {
		printf("%d, ", arr[i]);
	}
	printf("\n");

	return 0;
}
