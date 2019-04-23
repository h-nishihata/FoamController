byte values[2] = {0, 0};
bool debugMode = false;

void setup()
{
  for (int outPin = 3; outPin <= 53; outPin++)
  {
    pinMode(outPin, OUTPUT);  // 出力に設定.
  }  
  Serial.begin(9600);
}

void loop()
{
  if (Serial.available() >= 2)
  {
    values [0] = Serial.read() ;
    values [1] = Serial.read() ;

    if((values [0] == 88) && (values [1] == 88))
      debugMode = true;
    else if((values [0] == 77) && (values [1] == 77))
      debugMode = false;

    if(debugMode)
    {
      Serial.print("pin number: ");
      Serial.println(values [0]);
      Serial.print("status: ");
      Serial.println(values [1]);
    }
    
    if (values[1] > 1)
      return;
      
    digitalWrite(values[0], values[1]);
  }
}
