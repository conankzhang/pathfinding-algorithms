#include "ofApp.h"
#include "Entity/Flock.h"

#include "Behavior/basic-motion.h"
#include "Behavior/seek-steering.h"
#include "Behavior/DynamicLookWhereYouAreGoing.h"
#include "Behavior/DynamicFace.h"
#include "Behavior/wander-steering.h"
#include "Behavior/DynamicSeparation.h"
#include "Behavior/DynamicPathFollow.h"

#include "Pathfinding/DirectedWeightedGraph.h"
#include "Pathfinding/Pathfinding.h"
#include "Pathfinding/Heuristic.h"
#include "Pathfinding/TiledDivisionScheme.h"

//=======================================================================================================================
void ofApp::setup()
{
	ofBackground(ofColor::white);
	ofSetCircleResolution(50);

	Target.x = 0.0f;
	Target.y = 0.0f;

	TargetSize = 10.0f;

	Flock = new CFlock(1, FlockBehaviors, ofColor::black);
	FlockBehaviors.push_back(SWeightedBehavior(new CDynamicPathFollow(), 1));
	FlockBehaviors.push_back(SWeightedBehavior(new CDynamicLookWhereYouAreGoing(), 1));

	Graph = new CDirectedWeightedGraph(EGraph::PALLET, ofGetWindowWidth(), ofGetWindowHeight(), 10, 10);
	DivisionScheme = new CTiledDivisionScheme(10.0f, 10.0f, Graph);
	Heuristic = new CZeroEstimate(DivisionScheme);
}

//=======================================================================================================================
void ofApp::update()
{
	if (Flock)
	{
		Flock->Update(ofGetLastFrameTime());
	}
}

//=======================================================================================================================
void ofApp::draw()
{
	ofSetColor(ofColor::black);

	ofDrawBitmapString("Click anywhere to start pathfinding.", 50, 50);

	ofDrawRectangle(Target.x, Target.y, TargetSize, TargetSize);

	if (Flock)
	{
		Flock->Draw();
	}
}

//=======================================================================================================================
void ofApp::keyPressed(int key)
{

}

//=======================================================================================================================
void ofApp::mousePressed(int x, int y, int button)
{
	Target.x = x;
	Target.y = y;

	if (DivisionScheme && Flock)
	{
		int StartNode = DivisionScheme->Quantize(Flock->GetCenterOfMass());
		int GoalNode = DivisionScheme->Quantize(Target);

		Pathfinding::FindPath(StartNode, GoalNode, Graph, Heuristic, Path);
	}
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

//--------------------------------------------------------------k
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){

}
