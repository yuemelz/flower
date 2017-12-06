#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
//    theta = 0;
    serial.listDevices();
    vector <ofSerialDeviceInfo> deviceList = serial.getDeviceList();
    
    int baud = 9600;
    serial.setup(1, 9600);
//    serial.setup("/dev/cu.usbmodem1421", 9600);
    int numFlower = 4;
    for(int i = 0; i < numFlower; i++){
        Flower temp = Flower();
        temp.img.load(ofToString(i+1)+".png");
        flowers.push_back(temp);
    }
    
    flowers[0].setup(30, 70, 0.03);
    flowers[1].setup(150, 190, 0.01);
    flowers[2].setup(400, 440, 0.05);
    flowers[3].setup(590, 620, 0.1);
}

//--------------------------------------------------------------
void ofApp::update(){
    if (serial.available()) {
        int value = serial.readByte();
        cout << "value is: "<<value<<endl;
        if (serial.available() == 2){
            start = true;
        }
    }
    
    if(start == true){
        for (int i = 0; i < flowers.size(); i ++){
            flowers[i].update();
            cout<<"flower["<<i<<": " << flowers[i].position.x << ", " <<flowers[i].position.y<<endl;
            if (flowers[i].position.x > ofGetWidth()){
                flowers[i].position.x = 0;
            }
        }
    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(255);
    for (int i = 0; i < flowers.size(); i++) {
        flowers[i].draw();
    }
//    flower.draw(position.x, position.y);
//    ofPushMatrix();
//    ofRotate(30);
//    image.draw(xPos, yPos*5, 90, 90);
//    ofPopMatrix();
//
//    image2.draw(xPos, yPos2*3, 60, 60);
//
//    ofPushMatrix();
//    ofRotate(10);
//    image3.draw(xPos3, yPos3*7, 40, 40);
//    ofPushMatrix();
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
