#include <iostream>
using namespace std;

double double_gpa_AI[] = {0,1.7,2,2.4,2.7,3,3.3,3.7,4};
string letter_gpa_AI[] = {"F","D","D+","C","C+","B","B+","A","A+"};

double GPA_calculator(){
    double total_crd=0,total_gpa=0,n;
    cout<<"Enter the number of subjects in this term : "; cin>>n;
    for(int i=0;i<n;i++){
        int credit;
        string l_grade;
        cout<<"Enter the number of credits (hours) of the subject : "; cin>>credit;
        cout<<"Enter your letter grade : "; cin>>l_grade;
        total_crd+=credit;
        for(int j=0;j<9;j++){
            if(letter_gpa_AI[j]==l_grade)
                total_gpa+=double_gpa_AI[j]*credit;
        }
    }
    double gpa = total_gpa/total_crd;
    return gpa;
}

void Instruc(){
    cout<<"***************Instructions**************"<<endl<<"- Enter the letter grade with Capital letters ."<<endl
        <<"- letter grades : [ F , D , D+ , C , C+ , B , B+ , A , A+ ] ."<<endl<<"- Don't count the non-credits subjects . "<<endl;
}
void system_GPA(){
    Instruc();
    int n_terms;
    double gpa = GPA_calculator(),cumul_gpa;
    cumul_gpa=gpa;
    string choice;
    cout<<"Is there is any other terms ? [ yes , no ] : "; cin>>choice;
    if(choice=="yes"){
        cout<<"Enter the number of the terms you have done (excluding the last one): "; cin>>n_terms;
        int n=n_terms;
        while(n--){
            double pre_gpa;
            cout<<"Enter a GPA of the term "<<n+1<<" : "; cin>>pre_gpa;
            cumul_gpa+=pre_gpa;
        }
        n_terms++;
    }
    else{ n_terms = 1;}
    cout<<"Your GPA of this term is "<<gpa<<endl;
    cout<<"Your cumulative GPA is "<<cumul_gpa/n_terms<<endl;
}
int main(){
    system_GPA();
    return 0;
}