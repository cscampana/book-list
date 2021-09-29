/**
 * This program creates an archive of books, it uses an struct to hold the information and an auxiliary function to
 * provide the output to a file.
 * Version 0.1
 * Author: Caike Salles Campana
 * Email: csallesc@ucsd.edu
 */
#include <stdio.h>
#include <stdlib.h>

enum category{fiction, nonFiction, biography};
struct book {
    char *title;
    char *author;
    enum category bookCategory;
};
/**
 * Struct to hold information about the book.
 * @param title of the book.
 * @param author of the book.
 * @param bookCategory currently there are 3 choices (fiction, nonFiction, biography).
 * @return a struct.
 */
struct book createAuthor(char *title, char *author, enum category bookCategory){
    struct book newBook;
    struct book *pointerBook;
    pointerBook = &newBook;
    pointerBook -> title = title;
    pointerBook -> author = author;
    pointerBook -> bookCategory = bookCategory;
    return *pointerBook;
}
/**
 * Using fprintf, it outputs the contents of the struct book into a text file.
 * @param bookToWrite a struct with all the information of the book.
 */
void writeBooks(struct book bookToWrite){
    FILE *file;
    file = fopen("books.txt","a+");
    fprintf(file,"%s",bookToWrite.author);
    fclose(file);
}
/**
 * The main function acts as the interface between the data.
 * @return EXIT_SUCCESS in case the file was written correctly.
 */
int main() {
    struct book funcBook = createAuthor("1984", "George Orwell",fiction);
    writeBooks(funcBook);

    return EXIT_SUCCESS;
}


