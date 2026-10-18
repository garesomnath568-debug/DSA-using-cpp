
#include <iostream>
#include <string>
using namespace std;

struct Book
{
    int id;
    string name;
    Book* next;
};

Book* head = NULL;

void insertBook()
{
    Book* newBook = new Book;

    cout << "Enter Book ID: ";
    cin >> newBook->id;

    cin.ignore();
    cout << "Enter Book Name: ";
    getline(cin, newBook->name);

    newBook->next = NULL;

    if (head == NULL)
    {
        head = newBook;
    }
    else
    {
        Book* temp = head;

        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newBook;
    }

    cout << "Book inserted successfully!\n";
}

void deleteBook()
{
    int id;
    cout << "Enter Book ID to delete: ";
    cin >> id;

    Book* temp = head;
    Book* prev = NULL;

    while (temp != NULL && temp->id != id)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        cout << "Book not found!\n";
        return;
    }

    if (prev == NULL)
        head = temp->next;
    else
        prev->next = temp->next;

    delete temp;
    cout << "Book deleted successfully!\n";
}

void searchBook()
{
    int id;
    cout << "Enter Book ID to search: ";
    cin >> id;

    Book* temp = head;

    while (temp != NULL)
    {
        if (temp->id == id)
        {
            cout << "Book Found!\n";
            cout << "Book ID: " << temp->id << endl;
            cout << "Book Name: " << temp->name << endl;
            return;
        }

        temp = temp->next;
    }

    cout << "Book not found!\n";
}

void displayBooks()
{
    if (head == NULL)
    {
        cout << "No book records available.\n";
        return;
    }

    Book* temp = head;

    cout << "\n--- Library Book Records ---\n";

    while (temp != NULL)
    {
        cout << "Book ID: " << temp->id << endl;
        cout << "Book Name: " << temp->name << endl;
        cout << "-----------------------\n";

        temp = temp->next;
    }
}

int main()
{
    int choice;

    do
    {
        cout << "\n=== Library Management System ===\n";
        cout << "1. Insert Book\n";
        cout << "2. Delete Book\n";
        cout << "3. Search Book\n";
        cout << "4. Display Books\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                insertBook();
                break;

            case 2:
                deleteBook();
                break;

            case 3:
                searchBook();
                break;

            case 4:
                displayBooks();
                break;

            case 5:
                cout << "Exiting program.\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 5);

    // Free remaining nodes
    while (head != NULL)
    {
        Book* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
