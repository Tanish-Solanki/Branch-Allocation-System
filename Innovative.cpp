#include<bits/stdc++.h>
using namespace std;

class Student{
public:
    int rank;
    string name,rollNumber,gender,dob,category,contactNumber,email;
    vector<string> branchPreferences;
    string allocatedBranch;

    Student(int r,string& n,string& roll,string& gen,string& dob,
            string& cat,string& contact,string& mail,vector<string>& prefs)
        :rank(r),name(n),rollNumber(roll),gender(gen),dob(dob),
         category(cat),contactNumber(contact),email(mail),
         branchPreferences(prefs),allocatedBranch("Not Allocated"){}
};

struct CompareRank{
    bool operator()(Student& s1,Student& s2){
        return s1.rank>s2.rank;
    }
};

class Branch{
public:
    string name;
    int totalSeats,allocatedSeats;
    Branch(string n,int s):name(n),totalSeats(s),allocatedSeats(0){}
};

class BranchSystem{
    priority_queue<Student,vector<Student>,CompareRank> studentQueue;
    vector<Branch> branches;
    vector<Student> allocatedStudents;
    vector<string> branchNames={
        "Computer Science Engg.","Information Technology","Electronics and Comm.",
        "Electrical Engineering","Mechanical Engineering","Civil Engineering",
        "Chemical Engineering","Biotechnology Engg."
    };

public:
    void setupBranches(){
        cout<<"\nWelcome to the Branch Allocation System\n";
        cout<<"\nAvailable branches:\n";
        for(size_t i=0;i<branchNames.size();++i){
            cout<<i+1<<". "<<branchNames[i]<<endl;
        }

        cout<<"\nEnter seats available for each branch:\n";
        for(string& branchName:branchNames){
            int seats;
            cout<<"Seats for "<<branchName<<": ";
            cin>>seats;
            branches.push_back(Branch(branchName,seats));
        }
    }

    void addStudent(){
        int numStudents;
        cout<<"\nEnter the number of students: ";
        cin>>numStudents;

        for(int i=0;i<numStudents;++i){
            string name,roll,gender,dob,category,contact,email;
            int rank;
            vector<string> preferences;

            cout<<"\n--- Entering details for student "<<i+1<<" ---\n";

            cout<<"Name: ";
            cin.get();
            getline(cin,name);

            cout<<"Roll Number: ";
            cin>>roll;

            cout<<"Rank: ";
            cin>>rank;

            cout<<"Gender (Male/Female/Other): ";
            cin>>gender;

            cout<<"Date of Birth (dd/mm/yyyy): ";
            cin>>dob;

            cout<<"Category (General/OBC/SC/ST): ";
            cin>>category;

            while(true){
                cout<<"Contact Number (10 digits): ";
                cin>>contact;
                if(contact.length()==10 && all_of(contact.begin(),contact.end(),::isdigit))break;
                cout<<"Invalid contact number.\n";
            }

            regex emailPattern("^[\\w.-]+@[\\w.-]+\\.[a-zA-Z]{2,}$");
            while(true){
                cout<<"Email: ";
                cin>>email;
                if(regex_match(email,emailPattern))break;
                cout<<"Invalid email format.\n";
            }

            cout<<"\nEnter branch preferences by number:\n";
            for(size_t j=0;j<branchNames.size();++j){
                cout<<j+1<<". "<<branchNames[j]<<endl;
            }

            int numPreferences;
            cout<<"\nNumber of preferences: ";
            cin>>numPreferences;

            cout<<"Enter preferences: ";
            for(int j=0;j<numPreferences;++j){
                int branchNum;
                cin>>branchNum;
                if(branchNum>=1 && branchNum<=(int)branchNames.size()){
                    preferences.push_back(branchNames[branchNum-1]);
                }else{
                    cout<<"Invalid branch number.\n";
                    j--;
                }
            }

            studentQueue.push(Student(rank,name,roll,gender,dob,category,contact,email,preferences));
        }
    }

    void allocateBranches(){
        cout<<"\n--- Branch Allocation ---\n";
        while(!studentQueue.empty()){
            Student student=studentQueue.top();
            studentQueue.pop();

            for(string& pref:student.branchPreferences){
                for(Branch& branch:branches){
                    if(branch.name==pref && branch.allocatedSeats<branch.totalSeats){
                        student.allocatedBranch=branch.name;
                        branch.allocatedSeats++;
                        allocatedStudents.push_back(student);
                        goto allocated;
                    }
                }
            }
            allocated:;
        }
    }

    void printBranchSummary(){
        cout<<"\n--- Final Branch Allocation Summary ---\n";
        for(Branch& branch:branches){
            cout<<branch.name<<" | "<<branch.allocatedSeats<<"/"<<branch.totalSeats<<endl;
        }
    }

    void printCandidateRankList(){
        cout<<"\n--- Candidate List by Rank ---\n";
        for(Student& student:allocatedStudents){
            cout<<student.rank<<" "<<student.name<<" "<<student.rollNumber<<endl;
        }
    }
};

int main(){
    BranchSystem system;
    system.setupBranches();
    system.addStudent();
    system.allocateBranches();
    system.printBranchSummary();
    system.printCandidateRankList();
    return 0;
}
