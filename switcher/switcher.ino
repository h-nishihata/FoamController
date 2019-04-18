byte values[2] = {0, 0};

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
    
    Serial.print("value 0: ");
    Serial.println(values [0]);
    Serial.print("value 1: ");
    Serial.println(values [1]);
    
    if (values[1] > 1)
      return;
    digitalWrite(values[0], values[1]);
  }
}
