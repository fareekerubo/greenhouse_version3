#include <LiquidCrystal_I2C.h>
#include <amt1001_ino.h>
#include <SoftwareSerial.h>
#include <OneWire.h> 
#include <DallasTemperature.h>
SoftwareSerial SIM800(10,11);
LiquidCrystal_I2C lcd(0x27, 16, 2);
#define ONE_WIRE_BUS 2
OneWire oneWire(ONE_WIRE_BUS); 
DallasTemperature sensors(&oneWire);

float temperature;
float temperature1;
float temperature4;

int tempPin = A0;
int tempPin1 = A2;
//int tempPin2 = A1;
//int ONE_WIRE_BUS = 2;

int gsm_reset = 9;

int state = 0;
String dataMessage = "";
String dataMessage1 = "";
String dataMessage2 = "";
String dataMessage3 = "";
String dataMessage4 = "";
String dataMessage5 = "";
// Create global varibales to store temperature and humidity

int upperLIMIT = 27;
int lowerLIMIT = 24;

const int ledPin = 8; //LED pins for temperature control
//const int ledPin2 = ;
const int ledPin3 = 6;

#define FLOAT_SENSOR  7    // the number of the pushbutton pin
#define LED           8

char incomingChar;
unsigned long current_time = 0;
unsigned long previous_time = 0;
float t1, t2, t3, t4, t5,t6,t7,t8,t9,t10,t11,t12;
float avg = 0;
float avg1 = 0;
uint16_t step;
uint16_t step1;
uint16_t step2;

//for the ds18b20 sensor
float average;// define a variable to store the average
float reading;// reading from  first sensor
float reading1;// reading from second senso

void setup() 
{
  Serial.begin(9600);
  sensors.begin(); 
  Serial.print("Initializing....");
 delay(20000);
  pinMode(tempPin, INPUT);
  pinMode(tempPin1, INPUT);
//   pinMode(tempPin2, INPUT);
  pinMode(gsm_reset, OUTPUT);
  pinMode(ledPin, OUTPUT);
  SIM800.begin(9600);
  lcd.begin();
  lcd.backlight();
  digitalWrite(gsm_reset, HIGH);
  pinMode(LED, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(FLOAT_SENSOR, INPUT_PULLUP);
  Serial.print("SIM800 ready...");
  // AT command to set SIM800 to SMS mode
  SIM800.print("AT+CMGF=1\r");
  delay(100);
  // Set module to send SMS data to serial out upon receipt
  SIM800.print("AT+CNMI=2,2,0,0,0\r");
  delay(100);
}

void loop() 
{
  read_sensor();
  // // temperature_control();
  // // pump_control();
  //  query();
}
