#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;
class books{
    public:
    int count=10000,dues=0,currentCount,size,index = 0;
void add(){
    this->count--;
    this->dues++;
};
void remove(){
    this->count++;
    this->dues--;
}
};
class BookData{
    private:
    string bookName;
    string author;
    int yearOfPublish;

    public:
    void updateBookInfo(string bookName,string Author,int yr){
        bookName = bookName;
        author = Author;
        yearOfPublish = yr;
    
}
};
class operation:public books{
    vector<string>bookFile;
    public:
    string BookName,bookToBeRemoved;
    void addBook(string book,int size){
        this->size = size;
        this->BookName = book;
        bookFile.reserve(size);
        for(int i = 0;i<size;i++){
            bookFile.push_back(book);
        }
    }
    void removeBook(string book){
         this->bookToBeRemoved = book;
        for(int i = 0;i<bookFile.size();i++){
            if(book==bookFile.at(i)){
                bookFile.erase(bookFile.begin()+i);
            }
        }
    }
    
};

class StudentInfo:public operation{
    vector<string>Registration;
    vector<string>Student;
    public:
    string student;
    string RegNo;
    int stdCount;
  void addMember(int count,string student,string regNo){
    this->stdCount = count;
    Registration.reserve(count);
    for(int i = 0;i<Registration.size();i++){
        cout << "enter the student name:";
        cin >> this->student;
        Student.push_back(this->student);
        cout << "enter the student registration number:";
       cin >> this->RegNo;
       Registration.push_back(this->RegNo);
    }
  }
  void removeMember(string regNo,string student){
    cout << "enter the registration number:";
    cin >> regNo;
for(int i = 0;i<Registration.size();i++){
    if(regNo==Registration.at(i)){
        Registration.erase(Registration.begin()+i);
        Student.erase(Student.begin()+i);
    }
}
  }

};

    struct StdAndBook{
        string StudentName;
        string RegistrationNo;
        int bookCount;
        string bookName;
    
    };
    void addBookAndStd(string std,string Reg,int Cnt,string book,int stdCnt){
        StdAndBook student[stdCnt];
        for(int i = 0;i<stdCnt;i++){
            student[i].StudentName = std;
            student[i].RegistrationNo = Reg;
            student[i].bookCount = Cnt;
        }
        }
        
void removeBookAndStd(string std,string Reg,int Cnt,string book,int stdCnt){
    StdAndBook students[stdCnt];
    int found = 0;
    for(int i = 0;i<stdCnt;i++){
        if(std==students[i].StudentName&& Reg==students[i].RegistrationNo&&book==students[i].bookName){
            found = 1;
        }
        if(found!=1){
            students[i].StudentName = " ";
            students[i].RegistrationNo = " ";
            students[i].bookName = " ";

        }
        else{
            cout << "Student and book details not found."<<"\n"<<"Please Recheck it";
            break;
        }
        
    }
}
int main(){
    books bookCount;
    operation issueAndReturn;
    BookData book;
    StudentInfo StudentStats;
    string op;
    do{
        cout << "welcome to the library.Issue,Return or Exit??"<<endl;
        cin >> op;
        if(op=="issue"){
            cout << "enter the no of students for whom the books need to be issued:";
            cin >> StudentStats.stdCount;
            for(int i = 0;i<StudentStats.stdCount;i++){
                cout << "enter the student name:";
                cin >> StudentStats.student;
                cout << "enter the registration number of the student:";
                cin >> StudentStats.RegNo;
                StudentStats.addMember(StudentStats.stdCount,StudentStats.student,StudentStats.RegNo);
                cout << "enter the no of books to be added:";
                cin >> bookCount.size;
                for(int i = 0;i<bookCount.size;i++){
                    cout << "enter the book name:";
                cin >> issueAndReturn.BookName;
                addBookAndStd(StudentStats.student,StudentStats.RegNo,bookCount.size,issueAndReturn.BookName,StudentStats.stdCount);
                    issueAndReturn.addBook(issueAndReturn.BookName,bookCount.size);
                    cout << "you currently have  "<< issueAndReturn.BookName << "  Kindly return it before or exactly on the due date"<< "\n";
                    bookCount.add();
                }
             
            }
           
        
          
        }
        else if(op=="return"){
                cout << "enter the name of the student whose book needs to be returned:";
                cin >> StudentStats.student;
                cout << "enter the Registration number:";
                cin >> StudentStats.RegNo;
                StudentStats.removeMember(StudentStats.RegNo,StudentStats.student);
                cout << "enter the book Name:";
                cin >> issueAndReturn.bookToBeRemoved;
                removeBookAndStd(StudentStats.student,StudentStats.RegNo,bookCount.size,issueAndReturn.BookName,StudentStats.stdCount);
                issueAndReturn.removeBook(issueAndReturn.bookToBeRemoved);
                cout << "Thank you for returning the book"<< "\n";
                bookCount.remove();
        }
        else if(op=="exit"){
            cout << "Bye!\n";
            return 0;
        }
        else{
            cout<<"Invalid response\n";
        }
    }while(op!="exit");

    return 0;
}
