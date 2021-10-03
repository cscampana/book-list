/**
 * This program creates an archive of books, it uses an struct to hold the information and an auxiliary function to
 * provide the output to a file.
 * Version 0.1
 * Author: Caike Salles Campana
 * Email: csallesc@ucsd.edu
 */
#include <stdio.h>
#include <stdlib.h>

enum category {
    fiction, nonFiction, biography
};
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
struct book createAuthor(char *title, char *author, enum category bookCategory) {
    struct book newBook;
    struct book *pointerBook;
    pointerBook = &newBook;
    pointerBook->title = title;
    pointerBook->author = author;
    pointerBook->bookCategory = bookCategory;
    return *pointerBook;
}

/**
 * Using fprintf, it outputs the contents of the struct book into a text file.
 * @param bookToWrite  a struct with all the information of the book.
 */
void writeBooks(struct book bookToWrite) {
    FILE *file;
    file = fopen("books.txt", "a+");
    fprintf(file, "Title: %s \n"
                  "Author: %s \n"
                  "Category: %u \n", bookToWrite.title, bookToWrite.author, bookToWrite.bookCategory);
    fclose(file);
}

struct book inputBook() {
    char title[64];
    char author[64];
    int bookType;
    enum category bookCategory;
    printf("--New book--\n"
           "Title of the book: ");
    fgets(title, 64, stdin);
    printf("Author of the book: ");
    fgets(author, 64, stdin);
    printf("Type a number that correspond to the correct book category:\n"
           "0 - fiction \n"
           "1 - nonFiction \n"
           "2 - biography \n"
           "Type of book: ");
    char temp[sizeof(int)];
    char *ptr;
    selectType:
    fgets(temp, sizeof(int), stdin);
    bookType = (int) strtol(temp, &ptr, 10);
    if (bookType < 0 || bookType > 2) {
        printf("Please, select an appropriate option");
        goto selectType;
    } else {
        bookCategory = bookType;
    }

    return createAuthor(title, author, bookCategory);
}

/**
 * The main function acts as the interface between the data.
 * @return EXIT_SUCCESS in case the file was written correctly.
 */
int main() {
    writeBooks(inputBook());
    return EXIT_SUCCESS;
}


