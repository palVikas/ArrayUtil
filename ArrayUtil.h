typedef struct arrayUtil{
  	void *base;
	int typeSize;
	int length;
} ArrayUtil;

typedef int(MatchFunc)(void*,void*);

int  areEqual(ArrayUtil array1, ArrayUtil array2);

ArrayUtil create(int typeSize, int length); 

ArrayUtil resize(ArrayUtil util, int length);

int findIndex(ArrayUtil util, void* element);

void dispose(ArrayUtil util);

void* findFirst(ArrayUtil util, MatchFunc *isEven, void* hint);


