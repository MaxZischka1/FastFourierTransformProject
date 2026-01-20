#define MS 8
double timeDomain[MS] = {0,1,0,-1,0,1,0,-1};
double freqRE[MS];
double freqIM[MS];


void setup() {
  Serial.begin(9600);
  DFT(timeDomain,freqRE,freqIM);
}

void loop() {
}

void DFT(const double original[], double freqRE[], double freqIM[]){
  for(int k = 0; k < MS; k++){
    freqRE[k] = 0;
    freqIM[k] = 0;
  }
  for(int i = 0; i < MS; i++){
    for(int j = 0; j < MS; j++){
        double theta = (6.282*i*j)/MS;
        freqRE[i] += cos(theta)*original[j];
        freqIM[i] -= sin(theta)*original[j];
    }
  }
}
