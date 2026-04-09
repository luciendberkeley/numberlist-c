#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int *data;
	int end;
	int dataSize;
} NumberList;

void listInit(NumberList* list) {
	(*list).end = -1;
	(*list).dataSize = 4;
	(*list).data = (int*) malloc((*list).dataSize * sizeof(int));
}

void listAdd(NumberList* list, int val) {
	int next = (*list).end + 1;
	if(next < (*list).dataSize) {
		(*list).data[next] = val;
		(*list).end += 1;
	} else {
		(*list).dataSize *= 2;
		(*list).data = realloc((*list).data, (*list).dataSize * sizeof(int));
		listAdd(list, val);
	}
}

int listSize(NumberList* list) {
	return (*list).end + 1;
}

int listGet(NumberList* list, int index) {
	if(index >= listSize(list) || index < 0) {
		printf("Index out of bounds\n");
		exit(1);
	}

	return (*list).data[index];
}

void listPrint(NumberList* list) {
	int size = listSize(list);

	printf("[");
	for(int i=0; i < listSize(list); i++) {
		printf("%i", listGet(list, i));
		if(i != size - 1) printf(", ");
	}

	printf("]\n");
}

int main() {
	NumberList list;
	listInit(&list);

	listAdd(&list, 5);
	listAdd(&list, 83);
	listAdd(&list, 12389);

	listPrint(&list);

	printf("Index: %i, Value: %i\n", 2, listGet(&list, 2));

	return 0;
}
