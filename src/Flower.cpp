//
//  Flower.cpp
//  flower
//
//  Created by Z on 12/5/17.
//

#include "Flower.hpp"

Flower::Flower(){
    
}

void Flower::setup( int _min, int _max, float _freq){

    min = _min;
    max = _max;
    freq = _freq;
}

void Flower::setPosition(ofVec2f _pos){
    position.x = _pos.x;
    position.y = _pos.y;
//    if (position.x > ofGetWidth()){
//        position.x = 0;
//    }
}

void Flower::update(){
    position.x ++;
    theta ++;
    position.y = ofMap(sin(theta * freq), -1, 1, min, max);
}

void Flower::draw(){
    img.draw(position.x, position.y);
}
