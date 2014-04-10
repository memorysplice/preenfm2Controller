/*
  ==============================================================================

    Enveloppe.cpp
    Created: 6 Apr 2014 2:32:14pm
    Author:  xhosxe

  ==============================================================================
 */

#include "../JuceLibraryCode/JuceHeader.h"
#include "Enveloppe.h"


//==============================================================================
Enveloppe::Enveloppe(int nrpnBase)
{

	this->nrpnBase = nrpnBase;
	EnveloppePoint* point0 = new EnveloppePoint(0,0,0,0);
	point0->setX(0);
	point0->setY(0);
    EnveloppePoint* point1 = new EnveloppePoint(0,16.0,0.0, 1.0);
    point1->setX(0.2);
    point1->setY(1.0);
    EnveloppePoint* point2 = new EnveloppePoint(0,16.0,0,1.0);
    point2->setX(0.2);
    point2->setY(0.6);
    EnveloppePoint* point3 = new EnveloppePoint(0,16.0,0, 1.0);
    point3->setX(0.4);
    point3->setY(0.8);
    EnveloppePoint* point4 = new EnveloppePoint(0,16.0,0, 1.0);
    point4->setX(1.0);
    point4->setY(0);
	pointList.append(point0);
    pointList.append(point1);
    pointList.append(point2);
    pointList.append(point3);
    pointList.append(point4);
}

Enveloppe::~Enveloppe()
{
}


void Enveloppe::paint (Graphics& g)
{
    EnveloppeAbstract::paint(g);


    static const String adsr[] = { "A", "D", "S", "R" } ;
    for (int v=0; v<4; v++) {

        g.setColour (Colours::black);
        g.drawText(adsr[v], getWidth() - RIGHT_TEXT_SIZE , 20 + v* 20, 50, 10, Justification::centred, true);

        if (draggingPointIndex == v + 1) {
            g.setColour (Colours::red);
        } else {
            g.setColour (Colours::black);
        }

        String posisionX = String(pointList[v+1].get()->getX(), 2);
        g.drawText(posisionX, getWidth() - RIGHT_TEXT_SIZE / 3 * 2 - 10, 20 + v* 20, 50, 10, Justification::centred, true);
        posisionX = String(pointList[v+1].get()->getY(), 2);
        g.drawText(posisionX, getWidth() - RIGHT_TEXT_SIZE / 3 - 10, 20 + v* 20, 50, 10, Justification::centred, true);
    }
}


void Enveloppe::handleIncomingNrpn(int param, int value) {
	int index = (param - nrpnBase) / 2;
	switch (param - nrpnBase) {
	case 0:
	case 2:
	case 4:
	case 6:
		// point 0 is not modifiable
		pointList[index+1].get()->setX((float)value / 100.0f);
		repaint();
		break;
	case 1:
	case 3:
	case 5:
	case 7:
		pointList[index+1].get()->setY((float)value / 100.0f);
		repaint();
		break;
	}
}

void Enveloppe::newXValue(int draggingPointIndex, float newX) {
	sendNrpn(nrpnBase + (draggingPointIndex - 1) * 2, newX * 100.0f);
}

void Enveloppe::newYValue(int draggingPointIndex, float newY) {
	sendNrpn(nrpnBase + (draggingPointIndex - 1) * 2 + 1, newY * 100.0f);
}
