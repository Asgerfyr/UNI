#include <algorithm>
#include <numeric>

#include "random.h"

#include "brain.h"


Ai_Brain::Ai_Brain(int inputs, std::vector<int> layers, int outputs):
        _inputs{inputs}, 
        _raw_outputs(outputs), 
        output_order(outputs)
        {

    
    _layers.reserve(layers.size());
	
	int layer_inputs = inputs;
    
    for(auto it = layers.begin(); it != layers.end(); ++it){
        int index = std::distance(layers.begin(), it);
        _layers.emplace_back(Ai_Layer(layer_inputs,(*it)));
		layer_inputs = (*it);
    }

}



void Ai_Brain::mutate(float weight_strength, float bias_strength){
    float w_min = -1*weight_strength;
    float w_max = 1*weight_strength;
    float b_min = -1*bias_strength;
    float b_max = 1*bias_strength;
    
    for(auto it = _layers.begin(); it != _layers.end(); ++it){
		int nodes = (*it).get_nodes();
        for (int i_node = 0; i_node < nodes; i_node++){
            int inputs = (*it).get_inputs();
            for (int i_input = 0; i_input < inputs; i_input++){
                (*it).adjust_weight(i_node,i_input,Random::get_float(w_min,w_max));
            }

            (*it).adjust_bias(i_node,Random::get_float(b_min,b_max));
        }
    }
}

void Ai_Brain::brain_default(){
    for(auto it = _layers.begin(); it != _layers.end(); ++it){
		int nodes = (*it).get_nodes();
        for (int i_node = 0; i_node < nodes; i_node++){
            int inputs = (*it).get_inputs();
            for (int i_input = 0; i_input < inputs; i_input++){
                (*it).set_weight(i_node,i_input,0.5);
            }

            (*it).set_bias(i_node,0);
        }
    }
}

void Ai_Brain::brain_random(){
    float w_min = -1;
    float w_max = 1;
    float b_min = -0.5;
    float b_max = 0.5;
    
    for(auto it = _layers.begin(); it != _layers.end(); ++it){
		int nodes = (*it).get_nodes();
        for (int i_node = 0; i_node < nodes; i_node++){
            int inputs = (*it).get_inputs();
            for (int i_input = 0; i_input < inputs; i_input++){
                (*it).set_weight(i_node,i_input,Random::get_float(w_min,w_max));
            }

            (*it).set_bias(i_node,Random::get_float(b_min,b_max));
        }
    }
}

// void Ai_Brain::copy_brain(Ai_Brain brain){
//     int layer = 0;
//     for(int layer_i = 0; layer_i < _layers.size(); layer_i++){
// 		_layers[layer]._weights = brain._layers[layer]._weights;  // Bulk copy
//         _layers[layer]._bias = brain._layers[layer]._bias;
        
//         layer++;
//     }
// }


void Ai_Brain::copy_brain(Ai_Brain brain){
    int layer = 0;
    for(auto it = _layers.begin(); it != _layers.end(); ++it){
		int nodes = (*it).get_nodes();
        for (int i_node = 0; i_node < nodes; i_node++){
            int inputs = (*it).get_inputs();
            for (int i_input = 0; i_input < inputs; i_input++){
                (*it).set_weight(i_node,i_input,brain.get_layer(layer).get_weight(i_node,i_input));
            }

            (*it).set_bias(i_node,brain.get_layer(layer).get_bias(i_node));
        }
        
        layer++;
    }
}


std::vector<float>& Ai_Brain::calc_brain(std::vector<float>& input){
    std::vector<float>& last_result = input;

    for(auto it = _layers.begin(); it != _layers.end(); ++it){
		last_result = (*it).calc_layer(last_result);
    }
    _raw_outputs = last_result;

    std::iota(output_order.begin(), output_order.end(),0);
    std::sort(output_order.begin(), output_order.end(),
        [&](float a, float b){
            return _raw_outputs[a] > _raw_outputs[b];
        });
    
    return _raw_outputs;
}



int Ai_Brain::get_inputs()const{
    return _inputs;
}

std::vector<float> Ai_Brain::get_outputs()const{
    return _raw_outputs;
}

int Ai_Brain::get_n_conf_output(int n)const{
    return output_order[n];
}

Ai_Layer& Ai_Brain::get_layer(int n){
    return _layers[n];
}


