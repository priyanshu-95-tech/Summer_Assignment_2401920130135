//Design a Library Management System with Book and Library classes.

#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Book {
public:
    string title,author,isbn;
    bool isAvailable;
    Book(string t,string a,string i) : title(t),author(a),isbn(i),isAvailable(true){}
};
class Library {
private:
    vector<Book> books;
public:
    void addBook(Book b){
        books.push_back(b);
    }
    void issueBook(string isbn){
        for(auto &book : books){
            if(book.isbn==isbn && book.isAvailable){
                book.isAvailable=false;
                cout<<"Book '"<<book.title<<"' issued."<<endl;
                return;
            }
        }
        cout<<"Book not found or unavailable."<<endl;
    }
    void returnBook(string isbn){
        for(auto &book : books){
            if(book.isbn==isbn){
                book.isAvailable=true;
                cout<<"Book '"<<book.title<<"' returned."<<endl;
                return;
            }
        }
        cout<<"Book not found."<<endl;
    }
};
int main(){
    Library myLib;
    myLib.addBook(Book("The Great Gatsby","F. Scott Fitzgerald","12345"));
    myLib.issueBook("12345");
    myLib.returnBook("12345");
    return 0;
}