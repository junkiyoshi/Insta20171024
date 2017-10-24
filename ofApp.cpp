#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	ofSetFrameRate(60);
	ofBackground(0);
	ofSetWindowTitle("Insta");

	this->font_size = 20;
	this->font_span = 27;

	this->font.loadFont("fonts/Kazesawa-Bold.ttf", this->font_size);
	this->moji = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {
	for (int x = this->font_span / 2; x < ofGetWidth() - this->font_span / 2; x += this->font_span) {
		for (int y = -this->font_size / 2; y < ofGetHeight() + this->font_span / 2; y += this->font_span) {
			float noise_value = ofNoise(x, y * 0.0025 - ofGetFrameNum() * 0.025);
			ofSetColor(0, 255 , 0, 255 * noise_value);
			this->font.drawString(this->moji.substr((x / this->font_span) % 26, 1), x, y);
		}
	}

	ofImage image;
	image.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
	image.saveImage(to_string(ofGetFrameNum()) + ".png");
}

//--------------------------------------------------------------
int main() {
	ofSetupOpenGL(1920, 1080, OF_WINDOW);
	ofRunApp(new ofApp());
}