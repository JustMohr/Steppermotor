#define PIN_IN1 25  // blue
#define PIN_IN2 26  // pink
#define PIN_IN3 27 // yellow
#define PIN_IN4 28 // orange

unsigned int lowSpeed  = 10000; // max: 16000
unsigned int highSpeed =  1000;

void setup()
{
    pinMode(PIN_IN1, OUTPUT);
    pinMode(PIN_IN2, OUTPUT);
    pinMode(PIN_IN3, OUTPUT);
    pinMode(PIN_IN4, OUTPUT);
}

void loop()
{
    unsigned long n = millis() / 3000; // 3 seconds

    switch(n % 8) {
        case 0: stopMotor();            break;
        case 1: rotateRight(lowSpeed);  break;
        case 2: stopMotor();            break;
        case 3: rotateLeft(lowSpeed);   break;
        case 4: stopMotor();            break;
        case 5: rotateRight(highSpeed); break;
        case 6: stopMotor();            break;
        case 7: rotateLeft(highSpeed);  break;
    }
}

void rotateRight(unsigned int motorSpeed)
{
    setMotor(LOW, LOW, LOW, HIGH, motorSpeed);
    setMotor(LOW, LOW, HIGH, HIGH, motorSpeed);
    setMotor(LOW, LOW, HIGH, LOW, motorSpeed);
    setMotor(LOW, HIGH, HIGH, LOW, motorSpeed);
    setMotor(LOW, HIGH, LOW, LOW, motorSpeed);
    setMotor(HIGH, HIGH, LOW, LOW, motorSpeed);
    setMotor(HIGH, LOW, LOW, LOW, motorSpeed);
    setMotor(HIGH, LOW, LOW, HIGH, motorSpeed);
}

void rotateLeft(unsigned int motorSpeed)
{
    setMotor(HIGH, LOW, LOW, LOW, motorSpeed);
    setMotor(HIGH, HIGH, LOW, LOW, motorSpeed);
    setMotor(LOW, HIGH, LOW, LOW, motorSpeed);
    setMotor(LOW, HIGH, HIGH, LOW, motorSpeed);
    setMotor(LOW, LOW, HIGH, LOW, motorSpeed);
    setMotor(LOW, LOW, HIGH, HIGH, motorSpeed);
    setMotor(LOW, LOW, LOW, HIGH, motorSpeed);
    setMotor(HIGH, LOW, LOW, HIGH, motorSpeed);
}

void stopMotor()
{
    setMotor(LOW, LOW, LOW, LOW, 0);
}

void setMotor(byte in1, byte in2, byte in3, byte in4, unsigned int motorSpeed)
{
    digitalWrite(PIN_IN1, in1);
    digitalWrite(PIN_IN2, in2);
    digitalWrite(PIN_IN3, in3);
    digitalWrite(PIN_IN4, in4);
    delayMicroseconds(motorSpeed);
}
