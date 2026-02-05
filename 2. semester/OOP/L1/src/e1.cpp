#include <iostream>
#include <vector>

using namespace std;

void initialMessage(const int (&)[7]);
void userInputLoop(vector<int>&,const int (&)[7]);
[[nodiscard]]bool validateGrade(const int&,const int (&)[7]);
void printResults(vector<int>&);



int main() {
    int validGrades[7]{-3,0,2,4,7,10,12};
    vector<int> grades{};

    initialMessage(validGrades);

    userInputLoop(grades,validGrades);

    printResults(grades);

}

void initialMessage(const int (&_validGrades)[7]) {
    cout<<"--This is a grade input app--"<<endl<<endl;
    cout<<"valid grades are:"<<endl;
    for (int i : _validGrades) {
        cout<<i<<((i<10)?", ":(i==10)?" og ":"");
    }
    cout<<endl;
    cout<<"type in a grades"<<endl;
}



void userInputLoop(vector<int> &grades,const int (&_validGrades)[7]) {
    while (1) {
        int grade;
        cin>>grade;

        if (grade == -99)return;

        bool pass = validateGrade(grade,_validGrades);
        if (!pass) {
            cout<<"your grade is not a valid grade"<<endl;
            continue;
        }

        grades.push_back(grade);
    }
}


[[nodiscard]]bool validateGrade(const int &grade, const int (&_validGrades)[7]) {
    for (const int i : _validGrades) {
        if (grade == i)return true;
    }
    return false;
}

void printResults(vector<int> &_grades) {
    cout<<"your inputted grades are:"<<endl;
    for (int i : _grades) {
        cout<<i<<"  ";
    }

    //calculate average
    int sum{};
    for (int i : _grades)sum+=i;
    cout<<"the sum is:"<<endl;
    cout<<sum<<endl;

    float average = (float)sum/_grades.size();
    cout<<"the average is:"<<endl;
    cout<<average<<endl;
}