// This code runs the Sensors of the Kidney Kiosk for Otsuka.
// It reads three linear sensors into a moving average and then
// transmits the results over serial to a connected PC.
//
// contact: info@devicist.com


#include <movingAvg.h>

movingAvg x(6);
movingAvg y(6);
movingAvg z(6);

void setup()
{
  Serial.begin(115200);
  x.begin();
  z.begin();
  y.begin();
}

void loop()
{
  int xAverage = x.reading(analogRead(A0));
  int yAverage = y.reading(analogRead(A1));
  int zAverage = z.reading(analogRead(A2));

  Serial.print(xAverage);
  Serial.print(',');
  Serial.print(yAverage);
  Serial.print(',');
  Serial.println(zAverage);

  delay(25);
}
