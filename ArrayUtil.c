#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayUtil.h"

int areEqual( ArrayUtil array1, ArrayUtil array2){
	int i;
	char* base1 = (char*)array1.base;
	char* base2 = (char*)array2.base;

	if(array1.length != array2.length || array1.typeSize != array2.typeSize)
		return 0;

	for(i=0;i<(array1.length)*array1.typeSize;i++){
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
	int i;
	util.base = realloc(util.base,length*util.typeSize);
	for(i=util.length;i<length;++i){
		((int*)util.base)[i]=0;
	}
	util.length = length;
	return util;
};


int findIndex(ArrayUtil util, void* element){
	int length = util.length;
	int i;
	char* array = (char*) util.base;
	char* base_array = (char*) element;
	for(i=0;i<length*util.typeSize;i=i+util.typeSize){
		 	if(array[i] == *base_array){
		 		return i/util.typeSize;
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

void* findFirst(ArrayUtil util,MatchFunc *match,void* hint){
	int i;
	char *base = (char*)util.base;
	for(i=0;i<(util.length*util.typeSize);i=i+util.typeSize){
		if(match(hint,(void*)&base[i])==1)
			return (void*)&base[i];
	}
	return NULL;
};


void* findLast(ArrayUtil util, MatchFunc *match, void* hint){
	int i;
	char *base = (char*)util.base;
	int length = (util.length*util.typeSize);
	for(i=length-util.typeSize;i >= 0;i=i-util.typeSize){
		if(match(hint,(void*)&base[i])==1)
			return (void*)&(base[i]);
	}
	return NULL;
}
