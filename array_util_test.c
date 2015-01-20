#include "expr_assert.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "array_util.h"

void test_for_the_array_util_for_int_are_equall(){
	int first_array[]={1,2,3,4};
	int second_array[]={1,2,3,4};

	array_util array1;
	array_util array2;

	array1.base = first_array;
	array1.typeSize = sizeof(int);
	array1.length = 5;

	array2.base = second_array;
	array2.typeSize = sizeof(int);
	array2.length = 6;

    assertEqual(areEqual(array1, array2),1);
};


