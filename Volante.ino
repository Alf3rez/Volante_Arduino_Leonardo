#include <UwUKeypad.h>
#include <Joystick.h>

// Introduccion de variables
int SENSOR0, SENSOR1, SENSOR2;
int RESET;
bool TeclasPresionadas[16];


// Create the Joystick
Joystick_ Joystick(JOYSTICK_DEFAULT_REPORT_ID,JOYSTICK_TYPE_GAMEPAD,
            18, 0,                    // Botones, Hat switches
            false, false, false,       //Ejes X, Y, Z
            false, false, false,      //Ejes RX, RY, RZ
            false, false,             //Rudder, Throtle
            true, true, true);     //Accelerator, Brake, Steering


// Crear el Keypad
UwUKeypad teclado = UwUKeypad(2, 3, 4, 5, 6, 7, 8, 9);

void setup()
{
  Serial.begin(9600);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(10,INPUT_PULLUP);
  pinMode(11,INPUT_PULLUP);

  Joystick.setAcceleratorRange(20, 1000);
  Joystick.setBrakeRange(20, 1000);
  Joystick.setSteeringRange(20, 1000);
  
  // Inicializo la emulación como Joystick
  Joystick.begin();
}

void loop()
{
  
  SENSOR0 = analogRead(A0);
  SENSOR1 = analogRead(A1);
  SENSOR2 = analogRead(A2);
  
  botones();
  botonesExtra();
  Joystick.setAccelerator(SENSOR0);
  Joystick.setBrake(SENSOR1);
  Joystick.setSteering(SENSOR2);
  
}

// Mapeo los botones
void botones()
{
  teclado.getKeysState(TeclasPresionadas);
  for(byte i = 0; i < 16; i++)
  {
    if(TeclasPresionadas[i])
    {
      Joystick.releaseButton(i);
    }
    else
    {
      Joystick.pressButton(i);
    }
  }
}

void botonesExtra()
{
  for(byte j = 10; j < 12; j++)
  {
    if(digitalRead(j) == LOW)
    {
      Joystick.pressButton(j+6); 
    }
    else
    {
      Joystick.releaseButton(j+6);
    }
  }
}
