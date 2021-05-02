// This #include statement was automatically added by the Particle IDE.
#include <JsonParserGeneratorRK.h>

// This #include statement was automatically added by the Particle IDE.
#include <Grove_Temperature_And_Humidity_Sensor.h>



DHT dht(D3);

double temp;
double hum;

void postResult(double temp, double hum){
    JsonWriterStatic<256> jw;
    {
        JsonWriterAutoObject boj(&jw);
        jw.insertKeyValue("temp", temp);
        jw.insertKeyValue("hum", hum);
    }
    Particle.publish("DHT11", jw.getBuffer(), PRIVATE);
}

void setup() {
    dht.begin();
    pinMode(D3, INPUT);
}

void loop() {
    temp = dht.getTempCelcius();
    hum = dht.getHumidity();
    postResult(temp, hum);
    delay(10000);
}