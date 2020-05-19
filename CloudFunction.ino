int sensorValue;
int sensor = A0;
int led = D6;

void myHandler(const char *event, const char *data);

void setup() {
    pinMode(sensor, INPUT);
    pinMode(led, OUTPUT);
    Particle.subscribe("Deakin_RIOT_SIT210_Photon_Buddy", myHandler);
}

void loop() {
    sensorValue = analogRead(sensor);
    if(sensorValue > 50)
    {
        Particle.publish("MyMock", "wave", PUBLIC);
    } else
    {
        Particle.publish("MyMock", "pat", PUBLIC);
    }

}

//we are going to publish the desired event through our CLI using Particle API to stimulate another system publishing it
void myHandler(const char *event, const char *data)
{
    if (strcmp(data, "wave") == 0)
    {
        digitalWrite(led, HIGH);
        delay(1000);
        digitalWrite(led, LOW);
        delay(1000);
        
        digitalWrite(led, HIGH);
        delay(1000);
        digitalWrite(led, LOW);
        delay(1000);
        
        digitalWrite(led, HIGH);
        delay(1000);
        digitalWrite(led, LOW);
        delay(1000);
    } else if (strcmp(data, "pat") == 0)
    {
        digitalWrite(led, HIGH);
        delay(1000);
        digitalWrite(led, LOW);
        delay(1000);
        
        digitalWrite(led, HIGH);
        delay(1000);
        digitalWrite(led, LOW);
        delay(1000);
    }
    
}
