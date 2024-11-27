#include <iostream>
#include <string>

using namespace std;

class Library;

class LibraryManager{
public:
    static void updateCost(double &cost, double newCost){
        cost = newCost;
    }
};

class Book{
private:
    int accessionNumber;
    string author;
    string title;
    int yearOfPublication;
    string publisherName;
    double cost;

public:
    Book(): 
        accessionNumber(0), author("Unknown"), title("Unknown"), yearOfPublication(0), publisherName("Unknown"), cost(0.0){}

    Book(int accessionNumber, string author, string title, int yearOfPublication, 
         string publisherName, double cost): 
            accessionNumber(accessionNumber), author(author), title(title), yearOfPublication(yearOfPublication), publisherName(publisherName), cost(cost){}

    Book(Book &book){
        accessionNumber = book.accessionNumber;
        author = book.author;
        title = book.title;
        yearOfPublication = book.yearOfPublication;
        publisherName = book.publisherName;
        cost = book.cost;
    }

    ~Book(){
        cout << "Destroying Book Object: " << title << endl;
    }

    void updateBookCost(double newCost){
        LibraryManager::updateCost(cost, newCost);
    }

    static void displayLibraryInfo(){
        cout << "Library: The Great Central Library" << endl;
    }

    void displayBookDetails(){
        cout << "Accession Number: " << accessionNumber << endl;
        cout << "Author: " << author << endl;
        cout << "Title: " << title << endl;
        cout << "Year of Publication: " << yearOfPublication << endl;
        cout << "Publisher: " << publisherName << endl;
        cout << "Cost: $" << cost << endl;
    }

    friend class Library;

    void* operator new(size_t size){
        cout << "Allocating memory for Book object\n";
        void* p = ::operator new(size);
        return p;
    }

    void operator delete(void* p){
        cout << "Deallocating memory for Book object\n";
        ::operator delete(p);
    }
};

class Library{
public:
    void setBookDetails(Book &book){
        cout << "Enter Accession Number: ";
        cin >> book.accessionNumber;
        cout << "Enter Author Name: ";
        cin.ignore();
        getline(cin, book.author);
        cout << "Enter Title of the Book: ";
        getline(cin, book.title);
        cout << "Enter Year of Publication: ";
        cin >> book.yearOfPublication;
        cout << "Enter Publisher's Name: ";
        cin.ignore();
        getline(cin, book.publisherName);
        cout << "Enter Cost of the Book: ";
        cin >> book.cost;
    }
};

int main(){
    Book::displayLibraryInfo();

    Book* book1 = new Book;

    Library library;
    library.setBookDetails(*book1);

    book1->displayBookDetails();

    double newCost;
    cout << "Enter new cost for the book: ";
    cin >> newCost;
    book1->updateBookCost(newCost);

    cout << "Updated Book Details:" << endl;
    book1->displayBookDetails();

    delete book1;

    return 0;
}
