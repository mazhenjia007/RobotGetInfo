#include <iostream>

#include "Kinova.API.CommLayerUbuntu.h"
#include "KinovaTypes.h"
#include "KinovaMethod.h"

#define PI (3.14159265357)
#define sqr(x) ((x)*(x))

using namespace std;

int Display(CartesianPosition pNow){
  float X = pNow.Coordinates.X;
  float Y = pNow.Coordinates.Y;
  float Z = pNow.Coordinates.Z;
  float ThetaX = pNow.Coordinates.ThetaX;
  float ThetaY = pNow.Coordinates.ThetaY;
  float ThetaZ = pNow.Coordinates.ThetaZ;
  
  printf("X=%7.4f, Y=%7.4f, Z=%7.4f, ThetaX=%7.2f, ThetaY=%7.2f, ThetaZ=%7.2f",
	 X, Y, Z, ThetaX/PI*180, ThetaY/PI*180, ThetaZ/PI*180);
}

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

    MyGetCartesianPosition(pNow);
    float X = pNow.Coordinates.X;
    float Y = pNow.Coordinates.Y;
    float Z = pNow.Coordinates.Z;
    float ThetaX = pNow.Coordinates.ThetaX;
    float ThetaY = pNow.Coordinates.ThetaY;
    float ThetaZ = pNow.Coordinates.ThetaZ;
  
    printf("X=%7.4f, Y=%7.4f, Z=%7.4f, ThetaX=%7.2f, ThetaY=%7.2f, ThetaZ=%7.2f",
	   X, Y, Z, ThetaX/PI*180, ThetaY/PI*180, ThetaZ/PI*180);
    cout << endl;

    printf("Finger1=%7.4f, Finger2=%7.4f, Finger3=%7.4f",
	   pNow.Fingers.Finger1,
	   pNow.Fingers.Finger2,
	   pNow.Fingers.Finger3);
    cout << endl;
  }
  
  return 0;
}
