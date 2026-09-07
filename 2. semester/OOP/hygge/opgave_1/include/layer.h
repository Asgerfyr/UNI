#include <vector>
#include "matrix.h"


class Ai_Layer{

    public:
    Ai_Layer(int inputs, int nodes);

    void set_weight(int node, int weight, float value);
    void set_weight(int node, std::vector<float> value);
    void adjust_weight(int node, int weight, float value);
    void adjust_weight(int node, std::vector<float> value);

    void set_bias(int node, float value);
    void set_bias(std::vector<float> value);
    void adjust_bias(int node, float value);
    void adjust_bias(std::vector<float> value);

    int get_inputs()const;
    int get_nodes()const;

    float& get_weight(int node, int weight);
    float& get_bias(int node);

    

    std::vector<float> calc_layer(std::vector<float>& input);


    private:
    Matrix<float> _weights;
    std::vector<float> _bias;
    int _inputs;
    int _nodes;
};