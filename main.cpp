#include <iostream>

#include "Kinova.API.CommLayerUbuntu.h"
#include "KinovaTypes.h"
#include "KinovaMethod.h"

#define PI (3.14159265357)
#define sqr(x) ((x)*(x))

using namespace std;

int main(){
  int result;
  // CartesianPosition pNow;

  AngularPosition pNow;

  if (LoadAPI()==1){
    result = MyInitAPI();
    KinovaDevice list[MAX_KINOVA_DEVICE];
    int deviceCount = MyGetDevices(list, result);

    if (deviceCount==0){
      cout << " *** No Availiable Device Found *** " << endl;
      return 0;
    }

    MySetActiveDevice(list[0]);

    // MyGetCartesianPosition(pNow);

    MyGetAngularPosition(pNow);

    float a1 = pNow.Actuators.Actuator1;
    float a2 = pNow.Actuators.Actuator2;
    float a3 = pNow.Actuators.Actuator3;
    float a4 = pNow.Actuators.Actuator4;
    float a5 = pNow.Actuators.Actuator5;
    float a6 = pNow.Actuators.Actuator6;

    printf("A1=%7.2f, A2=%7.2f, A3=%7.2f, A4=%7.2f, A5=%7.2f, A6=%7.2f",
	   a1, a2, a3,
	   a4, a5, a6);
    cout << endl;

    printf("Finger1=%7.4f, Finger2=%7.4f, Finger3=%7.4f",
	   pNow.Fingers.Finger1,
	   pNow.Fingers.Finger2,
	   pNow.Fingers.Finger3);
    cout << endl;
  }
  
  return 0;
}
