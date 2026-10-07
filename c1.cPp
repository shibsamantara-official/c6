#include <iostream>
#include <string>
using namespace std;

// Base Class
class CatalogItem {
protected:
    string title;
    string author;
public:
    void setCoreDetails(string t, string a) {
        title = t;
        author = a;
    }
    // Core formatting routine
    void printFormat() {
        cout << "Title: " << title << " | Author: " << author << endl;
    }
};

// Derived Class (Single Inheritance)
class EBook : public CatalogItem {
private:
    float fileSizeMB;
public:
    void setEBookDetails(string t, string a, float size) {
        setCoreDetails(t, a);
        fileSizeMB = size;
    }
    void displayListing() {
        cout << "[Digital E-Book Listing]" << endl;
        printFormat(); // Reusing core routine
        cout << "File Size: " << fileSizeMB << " MB\n" << endl;
    }
};

int main() {
    EBook myBook;
    myBook.setEBookDetails("Data Structures", "Shib", 15.5);
    myBook.displayListing();
    return 0;
}