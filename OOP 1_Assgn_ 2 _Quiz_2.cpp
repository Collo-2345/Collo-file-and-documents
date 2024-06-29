#include <iostream>
#include<string>
#include<stdexcept>

using namespace std;

class EXAM {
public:
    string name, adm, subject;
    int examID;
 //exception handling
    int duration;
    void test(){
    cout<<"Enter duration time :";
	cin>>duration;
	if(duration <= 0) {
		throw
		("Invalid exam duration . Duration must be positive.");
	
	}
	}
	        //virtual ~Exam() = default;//destructor
	        virtual void gradeExam() = 0;// virtual function
};
class InvalidExamDuratonException : public std::runtime_error{
	public:
	InvalidExamDuratonException (const std::string message)	: std::runtime_error(message){}
};
class GradingErrorException : public std::runtime_error{
	public:
	GradingErrorException (const std::string message): std::runtime_error(message){}	
};
class multipleChoiceExam : public EXAM {
public:
    string QuizAns_1, QuizAns_2, QuizAns_3, QuizAns_4, QuizAns_5;
    int marks_1, marks_2, marks_3, marks_4, marks_5;
    int totalMarks;

    void gradeExam() override {
    	
        cout << "Enter your name: ";
        getline(cin, name);
        cout<<"\n";
        cout << "\nAdmission number (ADM): ";
        cin >> adm;
        cout << "\n";
        cin.ignore(); // Ignore newline left in buffer after cin
        cout << "\nEnter your exam ID number: ";
        cin >> examID;
        cout << "\n";
        test();
        cout << "\n";
        cin.ignore(); // Ignore newline left in buffer after cin
        cout << "\nExam Duration " << duration << " hours" << endl;
        cout << "\n";
        cout << "\nMultiple choice Exam: " << subject << endl;
        cout << "\n";
        cout << "\n\n ANSWER THE FOLLOWING QUESTIONS CORRECTLY...\n\n";

        // Question 1
        cout << "1) Which is the first search engine in internet ?\n";
        cout << "[1] Google\n";
        cout << "[2] Archie\n";
        cout << "[3] Wais\n";
        cout << "[4] Altavista\n";
        cout << "\nEnter Your Answer: ";
        cin >> QuizAns_1;
        cin.ignore(); // Ignore newline left in buffer after cin
        cout << "\n";
        marks_1 = (QuizAns_1 == "2") ? 3 : 0;

        // Question 2
        cout << "2) Which one is the first web browser invented in 1990?\n";
        cout << "[1] Internet explore\n";
        cout << "[2] Mozilla\n";
        cout << "[3] Nexus\n";
        cout << "[4] Mosaic\n";
        cout << "\nEnter Your Answer: ";
        cin >> QuizAns_2;
        cin.ignore(); // Ignore newline left in buffer after cin
        cout << "\n";
        marks_2 = (QuizAns_2 == "4") ? 3 : 0;

        // Question 3
        cout << "3) First computer virus is known as?\n";
        cout << "[1] Rabbit\n";
        cout << "[2] creeper virus\n";
        cout << "[3] SCA virus\n";
        cout << "[4] Elk cloner\n";
        cout << "\nEnter Your Answer: ";
        cin >> QuizAns_3;
        cin.ignore(); // Ignore newline left in buffer after cin
        cout << "\n";
        marks_3 = (QuizAns_3 == "2") ? 3 : 0;

        // Question 4
        cout << "4) Firewall in computer is use for?\n";
        cout << "[1] security\n";
        cout << "[2] Data transmission\n";
        cout << "[3] Monitoring\n";
        cout << "[4] Authentication\n";
        cout << "\nEnter Your Answer: ";
        cin >> QuizAns_4;
        cin.ignore(); // Ignore newline left in buffer after cin
        cout << "\n";
        marks_4 = (QuizAns_4 == "1") ? 3 : 0;

        // Question 5
        cout << "5) which of the following is not a data base management?\n";
        cout << "[1] Mysql\n";
        cout << "[2] Oracle\n";
        cout << "[3] Cobal\n";
        cout << "[4] Sybase\n";
        cout << "\nEnter Your Answer: ";
        cin >> QuizAns_5;
        cin.ignore(); // Ignore newline left in buffer after cin
        cout << "\n";
        marks_5 = (QuizAns_5 == "3") ? 3 : 0;

        totalMarks = marks_1 + marks_2 + marks_3 + marks_4 + marks_5;
        cout << "\nTotal Marks: " << totalMarks << "/15\n";
        if(totalMarks > 10 && totalMarks<=15){cout<<"Very good!!!\n";}
        else if(totalMarks > 4 && totalMarks<= 9){cout<<"Fair!!!\n";}
        else{cout<<"Fail\n";}
		
         cout << "\nAttempt Finished.\n";
        
    }
};

class essayExam : public EXAM {
public:
    string essaytopic;

    void gradeExam() override {
    	
        cout << "Enter your name: ";
        getline(cin, name);
        cout << "\nAdmission number (ADM): ";
        cin >> adm;
        cin.ignore(); // Ignore newline left in buffer after cin
        cout << "\nEnter your exam ID number: ";
        cin >> examID;
        cout << "\n";
        test();
        cin.ignore(); // Ignore newline left in buffer after cin
        cout<<"\n";
        cout << "\nExam Duration " << duration << " hours" << endl;
        cout << "\nEssay topic: " << essaytopic << endl;
        cout<<"The impact of online Exam on student performance";
        cout<<"\n";
        cout << "\nWrite your essay...\n";
        cin.ignore(); // Ignore the newline character after reading integer
        cout<<"Essay saved...";
        cout<<"\n";
        cout<<"submitted  for Grading sucessfully...";
        
    }
};
void quit();
void choose() {
    string choice;
    
    cout << "\n\n.. WELCOME TO ONLINE EXAMS..\n\n";
    cout << "Select choice to continue";
    cout << "\n";
    cout << "[1] MULTIPLE CHOICE EXAM\n";
    cout << "[2] ESSAY EXAM\n";
    cout << "[0] Quit/Exit\n";
    cout << "\n";
    cout << " Enter Choice: ";
    getline(cin, choice);
    cout << "\n";
    EXAM *Eptr;

    if (choice == "1") { 
	
	  multipleChoiceExam m;
	  Eptr = &m;
	  Eptr -> gradeExam();}
	 else if(choice == "2") 
	 {essayExam e;
	  Eptr = &e;
	  Eptr -> gradeExam();}
    else if (choice == "0") { quit(); } 
    else {cout << "Invalid choice...\n";}


}
 void quit(){
    	//quit function
    	_exit(1);
	}
 main() {
    choose();
    return 0;
}

