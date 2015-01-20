#include <stdio.h>
#include <stdlib.h>
#include <string.h>

 struct book{
	char name[25];
	int price;
	int pages;
};

typedef struct{
	int length;
	int width;
}rectangle;

struct Books
{
   char  title[50];
   char  author[50];
   char  subject[100];
   int   book_id;
};


int add( struct book b1){
	return (b1.price+b1.pages);
}

int get_area(rectangle r1){
	return r1.length*r1.width;
}

void printBook( struct Books *book )
{
   printf( "Book title : %s\n", book->title);
   printf( "Book author : %s\n", book->author);
   printf( "Book subject : %s\n", book->subject);
   printf( "Book book_id : %d\n", book->book_id);
}

typedef struct telephone
	{
		char *name;
		int number;
	}TELEPHONE;

void my_function(TELEPHONE *ptr_myindex){
		printf("Name: %s\n", ptr_myindex[0].name);
		printf("Telephone number: %d\n", ptr_myindex[0].number);
}

int main(){
		TELEPHONE *ptr_myindex;
		ptr_myindex->name = " pal vikas";
		ptr_myindex->number = 67877865;
		my_function(ptr_myindex);
		
	// struct book b1={"hindi",56,200};
	// rectangle r1,r2;
 //   struct Books Book1 = {"history","vikasPal","chemistry",34};        /* Declare Book1 of type Book */
 //   struct Books Book2={"physics","vikaspal","manohar-ray",67};
	// int result1;
	// r1.length=20;
	// r1.width=30;
	// result1 = get_area(r1);
	// r2.length=40;
	// r2.width =67;
	//  printBook(&Book1);
	//  printBook(&Book2);

	// printf("result==%d\n",result1) ;
	// printf("========>%d\n",get_area(r2)) ;

	// printf("%d\n",add(b1) );
	// // printf("%d\n",get_area(r2) );



	// printf("%s\n",b1.name );
	// printf("%d\n",b1.price );
	// b1.price = 578;
	// printf("%d\n",b1.price );
	// printf("%d\n",b1.pages );
	return 0;
};