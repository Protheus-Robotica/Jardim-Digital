double kp = 5.0; //35
double kd = 15.0; //0.7
double ki = 10.0; // 0.01

int OUTMAX = 255;
int OUTMIN = -255;



double SetPoint = -14.5; // -14.5

float lastInput = 0.0;

double ITerm = 0.0;

const double IMax = 100.0;
const double IMin = -100.0;

uint16_t lastTime = 0;

double Compute(double input){

  double erro = SetPoint - input;

  ITerm += (ki*erro);

  if(ITerm > IMax){
    ITerm = IMax;
  }else if(ITerm <= OUTMIN){
    ITerm = IMax;
  }


  uint16_t dt = millis() - lastTime;
  lastTime = millis();

  double dInput = (input - lastInput) / dt;

  double output = kp*erro + ITerm + kd*dInput;

  // if (output > 0) {
  //   output *= 1.5;
  // }

  if(output > OUTMAX){
    output = OUTMAX;
  }else if(output <= OUTMIN){
    output = OUTMIN;
  }

  lastInput = input;
  
  return output;
}