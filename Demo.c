/**
 * Demo program for ADT exercise.
 * 
 * Author: Evgeny Hershkovitch Neiterman
 * Since : 2023-02
 */

#include "AdptArray.h"
#include "book.h"
#include "Person.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

int main() {

	pbook b1 = creat_book("harry Potter",12345) ;
	pbook b2= creat_book("C intro", 45678) ;
	PAdptArray mybooks = CreateAdptArray(copy_book,delete_book,print_book);
	SetAdptArrayAt(mybooks,3,b1);
	SetAdptArrayAt(mybooks,5,b2);
	printf("the size is %d\n",GetAdptArraySize(mybooks));  //should print 6
	pbook b = GetAdptArrayAt(mybooks,4); // should return null;
	assert(b==NULL); // doesn't fail
	b = GetAdptArrayAt(mybooks,3);
	printf("the book is %s\n",b->name); //should print "Harry Potter"
	PrintDB(mybooks);

	pperson p1 = creat_person("Harry","Potter", 934);
	pperson p2 = creat_person("Ron","Weasley", 789);
	PAdptArray HP_caracters = CreateAdptArray(copy_person,delete_person,print_person);
	SetAdptArrayAt(HP_caracters,2,p1);
	SetAdptArrayAt(HP_caracters,8,p2);
	printf("the size is %d\n",GetAdptArraySize(HP_caracters)); // prints 9
	PrintDB(HP_caracters); // prints:
	//first name: Harry last name: Potter id: 934
        //first name: Ron last name: Weasley id: 789
	
	DeleteAdptArray(mybooks);
	DeleteAdptArray(HP_caracters);
	delete_book(b1);
	delete_book(b2);
	delete_book(b);
	delete_person(p1);
	delete_person(p2);
	return 0;
}
// #include "AdptArray.h"
// #include "book.h"
// #include "Person.h"
// #include <string.h>
// #include <stdlib.h>
// #include <stdio.h>
// #include <assert.h>

// int main() {
//     /*
//                                                 ################    BOOKS    ################
//     */

//     printf("\n-----------------------------------------------------------------------------------\n");

//     // Initializing an adaptive array which contains books.
//     pbook firstBook = creat_book("C Tutorial", 720491);
//     pbook secondBook = creat_book("A Tour Of C++", 288310);
//     PAdptArray books = CreateAdptArray(copy_book, delete_book, print_book);
    
//     if (books != NULL) {
//         printf("A new adaptive array dedicated for books has been successfully created.\n");
//         printf("Initial size is: %d.\n", GetAdptArraySize(books));
//         printf("\n");
//     }

//     // Inserting books into the adaptive array.
//     SetAdptArrayAt(books, 0, firstBook);
// 	SetAdptArrayAt(books, 2, secondBook);

//     int availableCells = 0;
//     pbook tempBook;
        
//     printf("Two books have been successfully added into the array!\n");
//     printf("\n");

//     // Checking that the books are in their correct indexes.
//     for (int i = 0; i < GetAdptArraySize(books); i++) {
//         tempBook = GetAdptArrayAt(books, i);

//         if (tempBook != NULL) {
//             printf("%s book is at index: %d.\n", tempBook->name, i);
//             delete_book(tempBook);
//         } else {
//             printf("No book was added at index %d yet.\n", i);
//             availableCells++;
//         }
//     }

//     printf("\n");
    

//     // Since the array is dynamic, its size must be updated.
//     printf("Our adaptive array's size is: %d.\n", GetAdptArraySize(books));
//     printf("%d out of %d cells are ready to receieve a new book.\n", availableCells, GetAdptArraySize(books));

//     printf("\n");
    
//     // Attempting to get the books we inserted.
//     pbook getBookAt_0 = GetAdptArrayAt(books, 0);
//     pbook getBookAt_2 = GetAdptArrayAt(books, 2);

//     // Printing out each book.
//     printf("All Books Full Details:\n");

//     for (int i = 0; i < GetAdptArraySize(books); i++) {
//         tempBook = GetAdptArrayAt(books, i);

//         if (tempBook != NULL) {
//             printf("Book at index %d ==>  ", i);
//             print_book(tempBook);
//             delete_book(tempBook);
//         }
//     }


//     printf("-----------------------------------------------------------------------------------\n");

//     /*
//                                                 ################    PEOPLE    ################
//     */

//     printf("\n-----------------------------------------------------------------------------------\n");


//     // Initializing an adaptive array which contains people.
//     pperson firstPerson = creat_person("yogi", "yo", 322509357);
//     pperson secondPerson = creat_person("messi", "lionel", 123456789);
//     PAdptArray people = CreateAdptArray(copy_person, delete_person, print_person);
    
//     if (people != NULL) {
//         printf("A new adaptive array dedicated for people has been successfully created.\n");
//         printf("Initial size is: %d.\n", GetAdptArraySize(people));
//         printf("\n");
//     }

//     // Inserting people into the adaptive array.
//     SetAdptArrayAt(people, 2, firstPerson);
// 	SetAdptArrayAt(people, 4, secondPerson);

//     availableCells = 0;
//     pperson tempPerson;

//     printf("Two people have been successfully added into the array!\n");
//     printf("\n");

//     // Checking that the people are in their correct indexes.
//     for (int i = 0; i < GetAdptArraySize(people); i++) {
//         tempPerson = GetAdptArrayAt(people, i);

//         if (tempPerson != NULL) {
//             printf("%s %s is at index: %d.\n", tempPerson->first_name, tempPerson->last_name, i);
//             delete_person(tempPerson);
//         } else {
//             printf("No one was added at index %d yet.\n", i);
//             availableCells++;
//         }
//     }

//     printf("\n");

//     // Since the array is dynamic, its size must be updated.
//     printf("Our adaptive array's size is: %d.\n", GetAdptArraySize(people));
//     printf("%d out of %d cells are ready to receieve a new person.\n", availableCells, GetAdptArraySize(people));

//     printf("\n");
    
//     // Attempting to get the people we inserted.
//     pperson getPersonAt_2 = GetAdptArrayAt(people, 2);
//     pperson getPersonAt_4 = GetAdptArrayAt(people, 4);

//     // Printing out each book.
//     printf("All People Full Details:\n");

//     for (int i = 0; i < GetAdptArraySize(people); i++) {
//         tempPerson = GetAdptArrayAt(people, i);

//         if (tempPerson != NULL) {
//             printf("Person at index %d ==>  ", i);
//             print_person(tempPerson);
//             delete_person(tempPerson);
//         }
//     }


//     printf("-----------------------------------------------------------------------------------\n");

//     /*
//                                                 ################    DATA SUMMARY    ################
//     */

//     printf("\n-----------------------------------------------------------------------------------\n");


//     printf("Data Summary:\n\n");
//     printf("~ THE BOOKS ARE: \n");
//     PrintDB(books);
//     printf("\n~ THE PEOPLE ARE: \n");
//     PrintDB(people);


//     printf("-----------------------------------------------------------------------------------\n");

//     /*
//                                                 ################    DEALLOCATION    ################
//     */

//     printf("\n-----------------------------------------------------------------------------------\n");


//     // Deallocating all objects.
//     DeleteAdptArray(books);
//     DeleteAdptArray(people);

//     delete_book(firstBook);
//     delete_book(secondBook);
//     delete_book(getBookAt_0);
//     delete_book(getBookAt_2);

//     delete_person(firstPerson);
//     delete_person(secondPerson);
//     delete_person(getPersonAt_2);
//     delete_person(getPersonAt_4);

//     printf("All objects have been successfully deallocated.\n");
//     printf("-----------------------------------------------------------------------------------\n");

// 	return 0;
// }
