#include "layer.h"
#include "util.h"



Ai_Layer::Ai_Layer(int inputs, int nodes):_weights{inputs,nodes},_bias(nodes),_inputs{inputs},_nodes{nodes}{
        
    std::vector<float>& weights = _weights.get_matrix_vec();
    for (auto it = weights.begin(); it != weights.end(); ++it) {
        (*it) = 0.5;
    }
}


void Ai_Layer::set_weight(int node, int weight, float value){
    _weights.set(weight,node,value);
}

void Ai_Layer::set_weight(int node, std::vector<float> value){
    std::vector<float>& weights = _weights.get_matrix_vec();
    for (int i = 0; i < _inputs; i++) {
        weights[i+node*_inputs] = value[i];
    }
}

void Ai_Layer::adjust_weight(int node, int weight, float value){
    float val = _weights.get(weight,node);
    val += value;
    _weights.set(weight,node,val);
}

void Ai_Layer::adjust_weight(int node, std::vector<float> value){
    std::vector<float>& weights = _weights.get_matrix_vec();
    for (int i = 0; i < _inputs; i++) {
        weights[i+node*_inputs] += value[i];
    }
}

void Ai_Layer::set_bias(int node, float value){
    _bias[node] = value;
}

void Ai_Layer::set_bias(std::vector<float> value){
    for (int i = 0; i < _bias.size(); i++) {
        _bias[i] = value[i];
    }
}

void Ai_Layer::adjust_bias(int node, float value){
    _bias[node] += value;
}

void Ai_Layer::adjust_bias(std::vector<float> value){
    for (int i = 0; i < _bias.size(); i++) {
        _bias[i] += value[i];
    }
}

int Ai_Layer::get_inputs()const{
    return _inputs;
}

int Ai_Layer::get_nodes()const{
    return _nodes;
}

float& Ai_Layer::get_weight(int node, int weight){
    return _weights.get(weight,node);
}

float& Ai_Layer::get_bias(int node){
    return _bias[node];
}

std::vector<float> Ai_Layer::calc_layer(std::vector<float>& input){
    //object for node val
    std::vector<float> node(_bias);
    
    //add bias
    for (int i = 0; i < _bias.size(); i++) {
        node[i] = _bias[i];
    }

    //calc weight val and add to node
    std::vector<float>& weights = _weights.get_matrix_vec();
    for (int weights_i = 0; weights_i < weights.size(); weights_i++) {
        int node_i = weights_i%_nodes;
        int input_i = weights_i/_nodes;
        node[node_i] += weights[weights_i] * input[input_i];
    }


    //sigmoid function
    for (auto it = node.begin(); it != node.end(); ++it){
        (*it) = sigmoid(*it);
    }

    return node;
}