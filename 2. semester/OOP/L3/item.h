//
// Created by Asger on 12/02/2026.
//
#ifndef L3_ITEM_H
#define L3_ITEM_H



class Item {
public:
    const int id_;
    const std::string name_;
    const double price_;



    Item(const int& _id, const std::string& _name, const double& _price);


    std::string to_string() const;

};


#endif //L3_ITEM_H