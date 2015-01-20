#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayUtil.h"

int areEqual( ArrayUtil array1, ArrayUtil array2){
	int i;
	char* base1 = array1.base;
	char* base2 = array2.base;
	int max_length = (array1.length < array2.length) ?(array2.length*array2.typeSize) 
	:( array1.length*array1.typeSize);

	if(array1.length != array2.length || array1.typeSize != array2.typeSize)
		return 0;

	for(i=0;i<max_length;i++){
			if(base1[i] != base2[i])
				return 0;
			}

	return 1;
};

ArrayUtil create(int typeSize, int length){
	void *newArray;
	ArrayUtil array1;
	newArray = calloc(length,typeSize);
	array1.base = newArray;
	array1.length = length;
	array1.typeSize = typeSize;
	return array1;
};

ArrayUtil resize(ArrayUtil util, int length){
	void *newArray;
	newArray = realloc(util.base,length);
	util.base = newArray;
	util.length = length;
	return util;
};

int findIndex(ArrayUtil util, void* element){
	int length = util.length;
	int i;
	int* array = (int*) util.base;
	int* base_array = (int*) element;
	for(i=0;i<length;i++){
		 	if(array[i] == *base_array){
		 		return i;
		 	}
	}
	return -1;
};

void dispose(ArrayUtil util){
	free(util.base);
	util.length=0;
	util.typeSize=0;
	util.base =0;
};









