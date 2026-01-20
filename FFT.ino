#define MS 8
double timeDomain[MS] = {0,1,0,-1,0,1,0,-1};
double timeDomainNew[MS];
double freqRE[MS];
double freqIM[MS];
const int16_t W8[MS][2] PROGMEM = //implement something new for this aswell.
    {{0x7FFF,0x0000},
    {0x5A82,0x5A82},
    {0x0000,0x8000},
    {-0x5A82,0x5A82 },
    {-0x7FFF,0x0000},
    {-0x5A82, -0x5A82},
    {0x0000,-0x7FFF},
    {0x5A82,-0x5A82}};

void setup() {
  Serial.begin(9600);
  sortTimeDomain();
  FFT(timeDomainNew, freqRE, freqIM, 0, MS);
  printFFT(freqRE, freqIM);
}

void loop() {
}
void FFT(const double original[], double freqRE[], double freqIM[], int left, int right){
  if(left==right){
    freqRE[left] = original[left];
    freqIM[left] = 0.0;
  }
  else{
    int mid = (left+(right-left)/2);

    FFT(original, freqRE, freqIM, left, mid);
    FFT(original, freqRE, freqIM, mid+1, right);
    
    int N = (right-left) + 1;
    int halfN = N/2;

    for(int i = 0; i < halfN; i++){
      double angle = (-2*M_PI * (i))/N;

      double twiddleRE = cos(angle);
      double twiddleIM = sin(angle);

      double T_RE = twiddleRE*freqRE[mid+i+1] - twiddleIM*freqIM[mid+i+1];
      double T_IM = twiddleRE*freqIM[mid+i+1] + twiddleIM*freqRE[mid+i+1];

      double freqR = freqRE[left+i];
      double freqI = freqIM[left+i];

      freqRE[left+i] = freqR + T_RE;
      freqRE[1+i+mid] = freqR - T_RE;

      freqIM[left+i] = freqI + T_IM;
      freqIM[1+i+mid] = freqI - T_IM;

    }
  }
}

void printFFT(double freqRE[], double freqIM[]){
    for(int k = 0; k < MS; k++){
      Serial.print(freqRE[k]);
      Serial.print(" ");
      Serial.println(freqIM[k]);
      delay(10);
    }
}

void sortTimeDomain() {  
  //find a way to generalize this function
  int bitSize = log2(MS);
  for (int h = 0; h < MS; h++) {
    int c = bitReversal(h, bitSize);
    timeDomainNew[c] = timeDomain[h];
  }
}
int bitReversal(int initial, int bits) {
  int reverse;
  for (int i = 0; i < bits; i++) {
    reverse = (reverse << 1) | (initial >> i) & 1;
  }
  return reverse;
}
double log2(int num){
  return (log10(num)/log10(2));
}
// ISR(ADC_vect) {
//   timeDomain[sampleCount] = ADCH;
//   Serial.println(timeDomain[sampleCount]);
//   sampleCount++;
//   if (sampleCount >= MAX_SAMPLES){
//     ADCSRA &= ~((1 << ADATE) | (1 << ADIE));
//     flag = 1;
//   }
// }
// cli();
  // TCCR1B |= (1 << CS12);
  // OCR1A = 49087;
  // OCR1B = 49087;
  // ADMUX |= (1 << REFS0) | (1 << ADLAR);                                                                           //using analog reference internally(ADMUX set to 0 for ADC0), left adjustment for only 8-bits
  // ADCSRA |= (1 << ADEN) | (1 << ADSC) | (1 << ADATE) | (1 << ADIE) | (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);  //enables ADC, sets clock prescaler between 200kHz and 50kHz, sets ADC to run on interrupt
  // ADCSRB |= (1 << ADTS2) | (1 << ADTS0);                                                                          //set for Timer1 Compare Match to B DIDR0 |= (1 << ADC0D);//disable digital usage of A0 
  // sei();