#include "brain.h"


class Ai{

    public:
    Ai(int inputs, std::vector<int> layers, int outputs);

    int calc_ai(std::vector<float>& input);
    int calc_ai(std::vector<float> input, bool save);

    int get_n_output(int n)const;

    Ai_Brain& get_brain();

    void set_score(int new_score);
    void add_score(int new_score);

    bool operator<(const Ai& other)const;
    bool operator>(const Ai& other)const;

    private:

    int _score;

    Ai_Brain _brain;

};