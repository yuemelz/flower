//
//  Flower.hpp
//  flower
//
//  Created by Z on 12/5/17.
//

#ifndef Flower_hpp
#define Flower_hpp

#include <stdio.h>
#include "ofMath.h"
#include "ofMain.h"

#endif /* Flower_hpp */

class Flower{
public:
    
    Flower();
    
    void setup( int _min, int _max, float _freq);
    void setPosition(ofVec2f _pos);
    void update();
    void draw();
    ofImage img;
    
  
    ofVec2f position;
    int min;
    int max;
    float freq;
    float theta = 0;
};
