#include <iostream>
#include <string>
#include "Die.h"

using namespace std;

void e1();
void e2();

int main() {

    e2();

}


void e1() {

    Die die;

    cout << "rools:" << endl;
    for (int i{}; i < 10; i++) {
        die.roll();
        cout << die.get_value() << "   ";
    }
    cout << endl;
    cout << die.get_total() << endl;


    cout << die.get_total_throws() << endl;

    std::vector<double> frequency = die.get_frequency();

    cout << endl;
    int i{};
    for (double x : frequency) {
        cout << "frequency of " << i+1 << "is 1 in every ";
        cout << std::to_string(x);
        cout << " throws";
        i++;
        cout << endl;
    }

    die.reset_total();

    cout << endl << endl << endl << endl;
    cout << " test of mean over 100000 throws" << endl << endl;

    for (int i{}; i < 1000;i++) {
        for (int j{}; j < 1000;j++) {
            die.roll();
        }
        cout << "mean after " << i+1 << "000 throws is " << die.get_mean()<< endl;
    }

}

double calculate(const double&, const char&, const double&);

struct Test_data_struct {
    double val1;
    char operation;
    double val2;
    double result;
};

void e2() {

    vector<Test_data_struct>input = {
        Test_data_struct{5,'+',8,13},
        Test_data_struct{0.3,'-',4,-3.7},
        Test_data_struct{0.5,'*',2,1},
        Test_data_struct{0.5,'/',2,0.25},
        Test_data_struct{0.5,'g',2,0.25},
        Test_data_struct{0.5,'/',0,0.25}
    };

    int failed = 0;
    int j{};
    for (Test_data_struct i : input) {
        j++;
        try {
            if (abs(calculate(i.val1,i.operation,i.val2) - i.result) > 1e-8) {

                string error_message = "The calculator did not result in the right value:\n";
                error_message += "The result was:\n";
                error_message += to_string(calculate(i.val1,i.operation,i.val2));
                error_message += "\n";
                error_message += "The result should have been:\n";
                error_message += to_string(i.result);
                throw logic_error{error_message};
            }
        }catch (const exception &e) {
            cout << "The test is: test" << j << endl << endl << e.what() << endl << endl  << "The parameters where" << endl << to_string(i.val1) << endl << i.operation << endl << to_string(i.val2) << endl << endl << endl << endl;
            failed++;
        }
    }

    cout << "Total amount of failed test: " << failed << endl;

}


double add(const double&,const double&);
double sub(const double&,const double&);
double mult(const double&,const double&);
double div(const double&,const double&);


struct Operations_struct {
    char operation;
    double(*func)(const double&, const double&);
};

double calculate(const double &val1, const char &opr,const double &val2) {
    vector<Operations_struct> operations{
        Operations_struct{'+',add},
        Operations_struct{'-',sub},
        Operations_struct{'*',mult},
        Operations_struct{'/',div},
    };

    for (Operations_struct x : operations) {
        if (opr == x.operation) return x.func(val1,val2);
    }

    throw invalid_argument{"The operator is not a valit operator"};


}

double add(const double &val1,const double &val2) {
    return val1 + val2;
}
double sub(const double &val1,const double &val2) {
    return val1 - val2;
}
double mult(const double &val1,const double &val2) {
    return val1 * val2;
}
double div(const double &val1,const double &val2) {
    if (val2 == 0)throw invalid_argument{"Cannot devide by 0, check value 2"};
    return val1 / val2;
}
