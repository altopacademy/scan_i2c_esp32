#include <Wire.h>
void setup()
{
Wire.begin();
Serial.begin(115200);
while (!Serial);
Serial.println("i2c Snaning");
}

 

void loop()
{
byte kode_eror, alamat;
int nDevices;
Serial.println("Scan");
nDevices = 0;
for(alamat = 1; alamat < 127; alamat++ )
{
Wire.beginTransmission(alamat);
kode_eror = Wire.endTransmission();
if (kode_eror == 0)
{
Serial.print("Alamat: ");
Serial.println(alamat,HEX);
nDevices++;
}
else if (kode_eror==4)
{
Serial.print("eror");
}
}
if (nDevices == 0)
Serial.println("tidak terdetek");
else
Serial.println("Selesai");
delay(5000);
}
