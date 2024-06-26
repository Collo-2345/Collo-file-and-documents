// A program for library management systerm.
// OOP concepts applied: classes and objects,Access specifiers,encapsulation
#include<iostream>
#include<conio.h>
#include<iostream>
using namespace std;

	
class Book{
	private:
		string isbn,title,author,edition,publication;// private variables
	public:
		    //setters - Assigning user values to private variables
	    	void setIsbn(string a){isbn = a;}
	    	void setTitle(string b){ title= b;}
	    	void setAuthor(string c){author = c;}
	    	void setEdition(string d){edition =d;}
	    	void setPublication(string e){publication =e;}
		    //getters - getting the values from private variables
		    string getIsbn(){return isbn;}
	     	string getTitle(){return title;}
	    	string getAuthor(){return author;}
	    	string getEdition(){return edition;}
		    string getPublication(){return publication;}
};


	

//intializing functions with counter as parameters
void addBook(int counter);
void deleteBook(int counter);
void editBook(int counter);
void searchBook(int counter);
void viewAllBooks(int counter);
void quit();

// counter for book array
int counter=0;

//function for increamenting counter
void increament(int a){
	a++;
	counter=a;
}
//function for decreamenting counter
void decreament(int a){
	a--;
	counter=a;
}
//book class array intialization
Book books[10];
// int main fuctions
int main() {
	
string choice;
  //main menu
system ("CLS");

cout<<" LIBRARY MANAGEMENT SYSTEM\n\n";
cout<<"BOOKS THAT ARE AVAILABLE:\n\n";
cout<<"Introduction to computer'Author Amit Garg' :\n";
cout<<"Publisher News letter Author Lalit Kumar:\n";
cout<<"Client Server Computing Author Gunjan Verma:\n";
cout<<"Data structure Using C :Author john.h.jennah\n";
cout<<"Computer Networks Author Osumpta.k.Matei:\n\n";
cout<<"BORROWED BOOKS:\n\n";
cout<<"Mobile Computing BY Fox wagen borrowed by Johnathan Koritch :\n";
cout<<"Computer Organization BY Osumpta.k.Matei borrowed Joseph otieno :\n";
cout<<"NET.Framework BYNelson.G.k borrowed by Victor njenga:\n\n";
cout<<"BOOKS RETURNED :\n\n";
cout<<"Object oriented programming return by Joel Kamau:\n";
cout<<"Operating system return by Philip awuero:\n";
cout<<"Descrete mathematics return by Stephen njnga:\n\n";
cout<<"YOU CAN ADD OTHER BOOKS INTO THE SYSTEM!!!:\n\n";
cout<<"\n Total Number of Books Added: "<<counter<<endl;
cout<<"\n";
cout<<"[1] ADD  BOOK\n";
cout<<"[2] DElETE BOOK \n";
cout<<"[3] EDIT BOOK \n";
cout<<"[4] SEARCH  BOOK\n";
cout<<"[5] VIEW ALL BOOKS\n";
cout<<"[6] QUIT\n\n";


cout<<"ENTER CHOICE: ";
getline(cin,choice);
system("CLS");

if(choice=="1"){
	addBook(counter);//function call
}
else if(choice=="2"){
	deleteBook(counter);//function call
}
else if(choice=="3"){
	editBook(counter);//function call
}
else if(choice=="4"){
	searchBook(counter);//function call
}
else if(choice=="5"){
	viewAllBooks(counter);//function call
}
else if(choice=="6"){
	quit();//function call
}
else{
	main();//function call to self(main)
}

_getch();
return 0;
}
//addBook function
void addBook(int counter){
   string isbn,title,author,edition,publication;
	cout<<"ADD BOOK\n\n";
	if(counter<10){
		//Book books[counter];
		cout<<"Enter ISBN:";
	    getline(cin,isbn);// getline - is like cin but include white spaces
		cout<<"Enter Title:";
		getline(cin,title);
		cout<<"Enter Author:";
		getline(cin,author);
		cout<<"Enter Edition:";
		getline(cin,edition);
		cout<<"Enter Publication:";
		getline(cin,publication);
	
		books[counter].setIsbn(isbn);//assigning the value entered to book object
		books[counter].setTitle(title);
		books[counter].setAuthor(author);
		books[counter].setEdition(edition);
		books[counter].setPublication(publication);
		increament(counter);
        cout<<"BOOK ADDED SUCCESSFULLY!\n\nPress any key to continue ...";
        _getch();
        main();
		}
	else{
	 cout<<"YOU HAVE REACHED MAXIMUM NUMBER OF BOOKS TO BE ADDED!\n\nPress any key to continue ...";
     _getch();
	 main();	
	}
}
 void deleteBook(int counter){
    string isbn;
    int choice;
 	cout<<"DELETE BOOK\n\n";
 	if(counter==0){
 		cout<<"There is NO book to delete!\nPress any key to continue ... ";
 		_getch();
 		main();
	 }
 	cout<<"Enter ISBN :\n";
 	getline(cin,isbn);
 	
 	for (int i = 0; i < counter; i ++){
 		//finding a match using for loop
 		if(books[i].getIsbn()==isbn){
 		   cout<<"\nBOOK FOUND\n\n";
 		   cout<<"Do you want to delete?\n[1]Yes\n[2]NO\n\nEnter choice:";
 		   cin>>choice;
 		   if(choice==1){
 		   	books[i].setIsbn("");//setting the value to none
		    books[i].setTitle("");
		    books[i].setAuthor("");
		    books[i].setEdition("");
		    books[i].setPublication("");
		    
		    for(int a=i;a<counter;a++){
		    	books[a] = books[a+1];//adjusting the value after deletion of data i.e data from book[4] copied to book[3]
			}
		    books[9].setIsbn("");//adjustment if the book are full(10 book)
		    books[9].setTitle("");
		    books[9].setAuthor("");
		    books[9].setEdition("");
		    books[9].setPublication("");
		    decreament(counter);//calling function to descrement
			cout<<"BOOK SUCCESSFULLY DELETED!\n\\n Press any key to continue ... ";	
			_getch();
			 main();
		 }
          else{
          	main();
          }
      }
  }
  cout<<"\nBOOK NOT FOUND!\n\nPress any key to continue ... ";
  _getch();
    main();
}
void editBook(int counter){
	system("CLS");
	string editIsbn,choice;
	string isbn,title,author,edition,publication;
	cout<<"\nEDIT BOOK\n\n";
	if(counter==0){
		
	cout<<"THERE IS NO BOOK TO EDIT\n\nPress any key to continue ...";
	_getch();
    main();	
	}
	cout<<"Enter ISBN:";
	getline(cin,editIsbn);
	for(int i=0; i<counter;i++){
		if(books[i].getIsbn()==editIsbn){
		cout<<"BOOK FOUND!\n\n"	;
		cout<<"ISBN: "<<books[i].getIsbn()<<endl;
		cout<<"TITLE: "<<books[i].getTitle()<<endl;	
		cout<<"AUTHOR: "<<books[i].getAuthor()<<endl;
		cout<<"EDITION: "<<books[i].getEdition()<<endl;
		cout<<"PUBLICATION: "<<books[i].getPublication()<<endl;
		cout<<"\nDo you want to edit?\n[1]Yes\n[2]NO\n\nEnter choice: ";
		getline(cin,choice);
		if(choice=="1"){
		     cout<<"Enter ISBN:";
			 getline(cin,isbn);	
			  cout<<"Enter Title:";
			 getline(cin,title);	
			  cout<<"Enter Author:";
			 getline(cin,author);	
			  cout<<"Enter Edition:";
			 getline(cin,edition);	
			  cout<<"Enter Publication:";
			 getline(cin,publication);	
			 books[i].setIsbn(isbn);
			 books[i].setTitle(title);
		     books[i].setAuthor(author);
		     books[i].setEdition(edition);
		     books[i].setPublication(publication);
		     cout<<"\nBOOK EDITED SUCCESSFULLY!\n\nPress any key to continue ...";
		     _getch();
			 editBook(counter);	//function call to self
		}
		else{
			main();
		}	
		}
	}
	cout<<"\nBOOK NOT FOUND!\n\nPress any key to continue ...";
	 _getch();
	 main();
}
   void searchBook(int counter) {
    	string isbn;
    	int choice;
    	bool print=false;//boolean expression decide which to print
    	cout<<"SEARCH BOOK\n\n";
    	if(counter==0){
    		cout<<"THERE IS NO BOOK TO SEARCH\n\nPress any key to continue ...";
    		_getch();
	         main();
		}
		cout<<"Enter ISBN: ";
	     getline(cin,isbn);
	     for(int i=0; i<counter;i++){
		if(books[i].getIsbn()==isbn){
			cout<<"\nBOOK FOUND!\n\n";
			cout<<"ISBN: "<<books[i].getIsbn()<<endl;
		    cout<<"TITLE: "<<books[i].getTitle()<<endl;	
	    	cout<<"AUTHOR: "<<books[i].getAuthor()<<endl;
	    	cout<<"EDITION: "<<books[i].getEdition()<<endl;
		    cout<<"PUBLICATION: "<<books[i].getPublication()<<endl;
		    print=true;
		}
	}
	if(print){
		cout<<"Press any key to continue ...";
		_getch();
	    main();
	}
	// if there's is no book found
	else{
		cout<<"\nBOOK NOT FOUND!\n\nPress any key to continue ...";
		_getch();
	    main();
	}
   }
   void viewAllBooks(int counter) {
   	//iterating all the value on the library using a book array
   	        cout<<"VIEW ALL BOOKS\n\n";
   	        for(int i=0; i<counter; i++){
   	        cout<<"BOOK DETAILS:\n\n";
			cout<<"ISBN: "<<books[i].getIsbn()<<endl;
		    cout<<"TITLE: "<<books[i].getTitle()<<endl;	
	    	cout<<"AUTHOR: "<<books[i].getAuthor()<<endl;
	    	cout<<"EDITION: "<<books[i].getEdition()<<endl;
		    cout<<"PUBLICATION: "<<books[i].getPublication()<<endl;
   }
    cout<<"Press any key to continue ... ";
    _getch();
	main();
}
    void quit(){
    	//quit function
    	_exit(1);
	}
    
    
    
    
    
    
    
    
		  

