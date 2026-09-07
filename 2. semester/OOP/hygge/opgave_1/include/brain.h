#include <vector>
#include "layer.h"

#define default_mutation_mult 0.3

class Ai_Brain{
    public:
    Ai_Brain(int inputs, std::vector<int> layers, int outputs);

    void mutate(float weight_strength=default_mutation_mult, float bias_strength=default_mutation_mult);
    
    void brain_default();

    void brain_random();
    
    std::vector<float>& calc_brain(std::vector<float>& input);
    
    void copy_brain(Ai_Brain brain);

    int get_inputs()const;
    std::vector<float> get_outputs()const;

    int get_n_conf_output(int n)const;

    Ai_Layer& get_layer(int n);


    private:

    int _inputs;
    std::vector<Ai_Layer> _layers;
    std::vector<float> _raw_outputs;
    std::vector<int> output_order;

};