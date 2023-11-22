double kp = 40; //1,9
double kd = 0.6; //1,16
double ki = 0.05; //2,17

int OUTMAX = 170;
int OUTMIN = -170;



double SetPoint = -16.2;

float lastInput = 0.0;

double ITerm = 0.0;

double Compute(double input){

  double erro = SetPoint - input;

  ITerm += (ki*erro);

  if(ITerm > OUTMAX){
    ITerm = OUTMAX;
  }else if(ITerm <= OUTMIN){
    ITerm = OUTMIN;
  }

  double dInput = input - lastInput;

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