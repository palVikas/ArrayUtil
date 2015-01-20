#include "expr_assert.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "ArrayUtil.h"

void test_for_the_array_util_for_int_are_equall(){
	int first_array[]={1,2,3,4,5};
	int second_array[]={1,2,3,4,5,6};

	ArrayUtil array1;
	ArrayUtil array2;

	array1.base = first_array;
	array1.typeSize = sizeof(int);
	array1.length = 5;

	array2.base = second_array;
	array2.typeSize = sizeof(int);
	array2.length = 6;

    assertEqual(areEqual(array1, array2),0);
};
void test_for_the_ArrayUtil_for_int_are_equall2(){
	int first_array[]={1,2,3,4};
	int second_array[]={1,2,3,4};

	ArrayUtil array1;
	ArrayUtil array2;

	array1.base = first_array;
	array1.typeSize = sizeof(int);
	array1.length = 4;

	array2.base = second_array;
	array2.typeSize = sizeof(int);
	array2.length = 4;

    assertEqual(areEqual(array1, array2),1);
};

void test_for_the_ArrayUtil_for_float_are_equall(){
	float first_array[]={1.0,2.6,3.2,4.1};
	float second_array[]={1.0,2.6,3.2,4.1};

	ArrayUtil array1;
	ArrayUtil array2;

	array1.base = first_array;
	array1.typeSize = sizeof(float);
	array1.length = 4;

	array2.base = second_array;
	array2.typeSize = sizeof(float);
	array2.length = 4;

    assertEqual(areEqual(array1, array2),1);
};

void test_for_the_ArrayUtil_for_float_are_not_equall(){
	float first_array[]={1.0,2.6,3.2,4.1};
	float second_array[]={1.0,2.9,3.2,4.1};

	ArrayUtil array1;
	ArrayUtil array2;

	array1.base = first_array;
	array1.typeSize = sizeof(float);
	array1.length = 4;

	array2.base = second_array;
	array2.typeSize = sizeof(float);
	array2.length = 4;

    assertEqual(areEqual(array1, array2),0);
};

void test_for_the_ArrayUtil_for_charecter_and_float_are_equal(){
	char first_array[]={'c','d','e','f'};
	int second_array[]={2,5,8,4};

	ArrayUtil array1;
	ArrayUtil array2;

	array1.base = first_array;
	array1.typeSize = sizeof(char);
	array1.length = 4;

	array2.base = second_array;
	array2.typeSize = sizeof(int);
	array2.length = 4;

    assertEqual(areEqual(array1, array2),0);
};
void test_for_create_new_array_of_integertype(){
	ArrayUtil newArray;
	newArray = create(sizeof(int),5);
    assertEqual(newArray.typeSize,4);
    assertEqual(newArray.length,5);
}

void test_for_create_new_array_of_charectertype(){
	ArrayUtil array;
	array = create(sizeof(char),6);
    assertEqual(array.typeSize,1);
    assertEqual(array.length,6);
};

void test_for_create_new_array_of_StringType(){
	ArrayUtil array;
	array = create(sizeof(char*),6);
    assertEqual(array.typeSize,4);
    assertEqual(array.length,6);
};

void test_ArrayUtil_resize_array_shoud_give_0_at_index5(){
	int *resArray;
	ArrayUtil array,resizeArray;
	array = create(sizeof(int),5);
	resizeArray=resize(array,4);
	resArray = resizeArray.base;
	assertEqual(resArray[2],0);
	assertEqual(resArray[4],0);
	assertEqual(areEqual(array,resizeArray),0);
};



void test_ArrayUtil_to_find_indexOf_3_element(){
	int x=3,index;
	int arr[] = {2,4,3,7};
	ArrayUtil array;
	array.base = arr;
	array.typeSize = sizeof(int);
	array.length = 4;
	index = findIndex(array, &x);
	assertEqual(index,2);
};

void test_ArrayUtil_to_find_indexOf__non_existing_value(){
	int x=7,index;
	int arr[] = {2,4,3,7,7,7,8,8};
	ArrayUtil array;
	array.base = arr;
	array.typeSize = sizeof(int);
	array.length = 8;
	index = findIndex(array, &x);
	assertEqual(index,2);
};