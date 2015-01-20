#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayUtil.h"

int areEqual( ArrayUtil array1, ArrayUtil array2){
	int i;
	int* base1 = array1.base;
	int* base2 = array2.base;
	if(array1.length == array2.length && array1.typeSize == array2.typeSize){
		for(i=0;i<array1.length;i++){
			if(base1[i] != base2[i])
				return 0;
			}
		return 1;
	}
	return 0;
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
	int new_length = (util.typeSize)*length;
	newArray = realloc(util.base,new_length);
	util.base = newArray;
	util.length = new_length;
	return util;
};

int findIndex(ArrayUtil util, void* element){
	int length = util.length;
	int i,j,count=0,index=-1;
	int* array = (int*) util.base;
	int* base_array = (int*) element;
	for(i=0;i<length;i++){
		 	if(array[i] == base_array[0]){
		 		count++;
		 	}
			if(count>0)
			index =i;
			count=0;
	}
	return index;
};









