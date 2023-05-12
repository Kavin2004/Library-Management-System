#include <stdio.h>
#include <string.h>

struct book {
    char title[50];
    char author[50];
    int year;
    int copies;
    int borrowed;
};

struct borrower {
    char name[50];
    char book_title[50];
    int borrow_date;
    int return_date;
};

void add_book(struct book library[], int size);
void display_books(struct book library[], int size);
void borrow_book(struct book library[], struct borrower borrowers[], int size);
void return_book(struct book library[], struct borrower borrowers[], int size);
int headMessage();
int welcomeMessage(); 

int main()
{   int size = 0;
    struct book library[100];
    struct borrower borrowers[100];
    int choice;

    headMessage();
    welcomeMessage(); 

    do {
    	printf("\n  -------");
        printf("\n | Menu: |\n");
        printf("  -------\n");
        printf("    1. Add Book Details\n");
        printf("    2. Display the List of Books and its details\n");
        printf("    3. Borrow book\n");
        printf("    4. Return book\n");
        printf("    5. Exit\n");
        printf("\n   Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
		{   case 1:
                add_book(library, size);
                size++;
                break;
            case 2:
                display_books(library, size);
                break;
            case 3:
                borrow_book(library, borrowers, size);
                break;
            case 4:
                return_book(library, borrowers, size);
                break;
            case 5:
                printf("Thank you for using Library Management System\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 5);
    return 0;
	}

void add_book(struct book library[], int size)
{   printf("\nEnter book title: ");
    scanf("%s", library[size].title);

    printf("Enter book author: ");
    scanf("%s", library[size].author);

    printf("Enter publication year: ");
    scanf("%d", &library[size].year);

    printf("Enter number of copies: ");
    scanf("%d", &library[size].copies);

    library[size].borrowed = 0;
    printf("Book added successfully\n");
}

void display_books(struct book library[], int size)
{   if (size == 0)
	  printf("\nNo books in the library\n");
    else
	{   printf("\nBooks in the library:\n");
        for (int i = 0; i < size; i++)
		    printf("%s by %s, published in %d, %d copies available\n", library[i].title, library[i].author, library[i].year, library[i].copies);
        }}

void borrow_book(struct book library[], struct borrower borrowers[], int size)
{   
    char title[50];
    int i, j;

    printf("\nEnter book title: ");
    scanf("%s", title);

    for (i = 0; i < size; i++)
    {   
        if (strcmp(title, library[i].title) == 0)
        {  
            if (library[i].copies == 0) {
                printf("Sorry, the book is currently not available.\n");
                return;
            }

            printf("Enter borrower name: ");
            scanf("%s", borrowers[i].name);

            printf("Enter borrow date (YYYYMMDD): ");
            scanf("%d", &borrowers[i].borrow_date);

            library[i].copies--;
            library[i].borrowed++;

            printf("Book borrowed successfully\n");
            return;
        }}
    printf("Book not found\n");
}

void return_book(struct book library[], struct borrower borrowers[], int size)
{	char title[50];
	int i, j, days;
	float fine;
	printf("\nEnter book title: ");
	scanf("%s", title);

	for (i = 0; i < size; i++)
	{  if (strcmp(title, library[i].title) == 0)
	   {  break;
    }}

	if (i == size || library[i].borrowed == 0)
    	printf("Book not borrowed or not found\n");
	else
	{	library[i].copies++;
    	library[i].borrowed--;
    	printf("Book returned successfully\n");

    	for (j = 0; j < library[i].borrowed; j++)
		{   if (strcmp(borrowers[j].book_title, title) == 0)
			{  break;
        }}
		printf("Enter return date (YYYYMMDD): ");
    	scanf("%d", &borrowers[j].return_date);

   		days = borrowers[j].return_date - borrowers[j].borrow_date;
    	if (days > 30)
		{   fine = (days - 30) * 0.5;
            printf("Fine for late return: $%.2f\n", fine);
    		}
    	printf("Borrower details updated successfully\n");
	}}

int headMessage()
{
    printf("\n\t\t\t###########################################################################");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t############      Library management System Project in C       ############");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t###########################################################################");
    printf("\n\t\t\t---------------------------------------------------------------------------\n");
}

int welcomeMessage()
{
    printf("\n\n");
    printf("\n\t\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");
    printf("\n\t\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\t\t\t\t        =                 WELCOME                   =");
    printf("\n\t\t\t\t        =                   TO                      =");
    printf("\n\t\t\t\t        =                 LIBRARY                   =");
    printf("\n\t\t\t\t        =               MANAGEMENT                  =");
    printf("\n\t\t\t\t        =                 SYSTEM                    =");
    printf("\n\t\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\t\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");
    printf("\n\t\t\t---------------------------------------------------------------------------\n");
}