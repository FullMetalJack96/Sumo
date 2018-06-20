#include "hFramework.h"
#include <DistanceSensor.h>
#include <Lego_Light.h>

using namespace hSensors;


bool obstacleLeft = false;
bool obstacleBack = false;
bool obstacleFront = false;
bool obstacleRight = false;
int platformHeight = 20;
int opponentDistance = 20;
int16_t blackColorValue = 000000;
void resetObstacleValues()
{
	obstacleLeft = false;
	obstacleBack = false;
	obstacleFront = false;
	obstacleRight = false;
	hLED1.off();
}

void pushTheFuckerOut(){
	hMot1.setPower(1000)
	hMot2.setPower(1000)
}

//krancowki przyciskające boki
//czujnik sensor.readRaw()
void killTheFkinOpponentTask()
{
	DistanceSensor sensorFrontCenter(hSens1.getBaseSens());
	DistanceSensor sensorFrontLeft(hSens2.getBaseSens());
	DistanceSensor sensorFrontRight(hSens3.getBaseSens());
	DistanceSensor sensorDownBack(hSens5.getBaseSens());
	Lego_Light sensor(hSens4);

	while (1)
	{
		int frontDist = sensorFrontCenter.getDistance();
		int downDistFront = sensorDownFront.getDistance();
		int downDistBack = sensorDownBack.getDistance();
		int leftDist = sensorFrontLeft.getDistance();
		int rightDist = sensorFrontRight.getDistance();

		int16_t colorValue;
		colorValue = sensor.readRaw();
		LED1.toggle();

		if(colorValue == blackColorValue){
				hMot1.setPower(-1000)
				hMot2.setPower(-1000)
				sys.delay(500)
		}

		if(downDistBack <= platformHeight){
				hMot1.setPower(1000)
				hMot2.setPower(1000)
				sys.delay(500)
		}

		if(frontDist < opponentDistance || leftDist < opponentDistance || rightDist < opponentDistance){
			pushTheFuckerOut();
		}

}

void hMain()
{
	sys.taskCreate(&killTheFkinOpponentTask);
}
