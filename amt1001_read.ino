boolean read_sensor()
{
  current_time = millis() / 1000;
 // Serial.print("Interval:"); Serial.print((current_time - previous_time));Serial.println("  "); 
  if ((current_time - previous_time) <= 180) //1800
  {
    step = analogRead(tempPin);
    step1 = analogRead(tempPin1);
    //step2 = analogRead(tempPin2);
    Serial.println(current_time);
 float  temperature2 = amt1001_gettemperature(step);
 float  temperature3= amt1001_gettemperature(step1);
 ds18b20_sensor();
 temperature4= average;//variable ground temp
   float t_vol=(temperature2+temperature3)/2;
   Serial.println("......................................");
    Serial.println("starting to read");
       dataMessage2 = ("FARM: NGONG\nBLOCK: 1OF2\nGH NO:  001\nAmbient Temperature:" + String(t_vol) + "*C " );
       dataMessage3 = ("Ground Temperature:" + String(temperature4) + "*C " );
    Serial.print(dataMessage2);
    Serial.print("          ");
      Serial.print(dataMessage3);
      digitalWrite(ledPin, HIGH);
      delay(100);
      digitalWrite(ledPin, LOW);
      delay(100);
      
    if ((current_time - previous_time) == 30) //300
    {
      temperature = amt1001_gettemperature(step);
      temperature1 = amt1001_gettemperature(step1);
      t1 = (temperature + temperature1) / 2;
      t7=temperature4;
      Serial.print("first value:");
      Serial.print(t1);   Serial.print("      ");Serial.print(t7);
      Serial.println("  ");
      delay(200);
    }
    else if ((current_time - previous_time) == 60) //600
    {
      temperature = amt1001_gettemperature(step);
      temperature1 = amt1001_gettemperature(step1);
      t2 = (temperature + temperature1) / 2;
       t8=temperature4;
      Serial.print("second value: ");
      Serial.print(t2);Serial.print("      ");Serial.print(t8);
      Serial.println("  ");
      delay(200);
    }
    else if ((current_time - previous_time) == 90) //900
    {
      temperature = amt1001_gettemperature(step);
      temperature1 = amt1001_gettemperature(step1);
      t3 = (temperature + temperature1) / 2;
       t9=temperature4;
      Serial.print("third value: ");
      Serial.print(t3);Serial.print("      ");Serial.print(t9);
      Serial.println("  ");
      delay(200);
    }
    else if ((current_time - previous_time) == 120) //1200
    {
      temperature = amt1001_gettemperature(step);
      temperature1 = amt1001_gettemperature(step1);
      t4 = (temperature + temperature1) / 2;
       t10=temperature4;
      Serial.print("forth value: ");
      Serial.print(t4);Serial.print("      ");Serial.print(t10);
      Serial.println("  ");
      delay(200);
    }
    else if ((current_time - previous_time) == 150) //1500
    {
      temperature = amt1001_gettemperature(step);
      temperature1 = amt1001_gettemperature(step1);
      t5 = (temperature + temperature1) / 2;
       t11=temperature4;
      Serial.print("fifth value:  ");
      Serial.print(t5);Serial.print("      ");Serial.print(t11);
      Serial.println("  ");
      delay(200);
    }

     else if ((current_time - previous_time) == 180) //1800
    {
      temperature = amt1001_gettemperature(step);
      temperature1 = amt1001_gettemperature(step1);
      t6 = (temperature + temperature1) / 2;
       t12=temperature4;
      Serial.print("sixth value:  ");
      Serial.print(t6);Serial.print("      ");Serial.print(t12);
     dataMessage1 = ("Ambient Inst. Temp:" + String(t6) + "*C " );
    // dataMessage4 = ("Ground Inst. Temp:" + String(t12) + "*C " );
      delay(200);
      
    }

  }
  else {
      Serial.println("........................... ");
    Serial.print("Fifth minute value:"); Serial.print(t1);Serial.print("      ");Serial.print(t7); Serial.println(" ");
    Serial.print("Tenth minute value:");Serial.print(t2);Serial.print("      ");Serial.print(t8); Serial.println(" ");
    Serial.print("Fifteenth minute value:");Serial.print(t3); Serial.print("      ");Serial.print(t9);Serial.println(" ");
    Serial.print("Twentieth minute value:");Serial.print(t4); Serial.print("      ");Serial.print(t10);Serial.println(" ");
    Serial.print("Twenty-Fifth minute value:");Serial.print(t5);Serial.print("      ");Serial.print(t11); Serial.println(" ");
    Serial.print("Thirtieth minute value:");Serial.print(t6);Serial.print("      ");Serial.print(t12); Serial.print(" ");
    Serial.println("  ");
    delay(1000);
    avg = (t1 + t2 + t3 + t4 + t5+t6) / 6;
     avg1 = (t7 + t8 + t9 + t10 + t11+t12) / 6;
    Serial.print("Avarage:  ");
    Serial.print(avg);  Serial.print(">>>--<<<");Serial.print(avg1); Serial.println("");
    delay(1000);
      dataMessage = (" FARM:    NGONG \n   GH NO:  001 \n Ambient Avg. Temp(6/30min):" + String(avg) + "*C " );
      dataMessage5 = ("Ground Avg. Temp(6/30min):" + String(avg1) + "*C " );
    Serial.print(dataMessage);Serial.print(">>>--<<<");Serial.print(dataMessage1);Serial.print(">>>--<<<");
    Serial.print(dataMessage5);Serial.print(">>>--<<<");Serial.print(dataMessage4);
    delay(500);
    Serial.println("........................... ");
    //Send sms here
    Serial.println("Sending SMS..............");
    sms();
    delay(2000);
   sms1();
    delay(2000);
    previous_time = current_time;
    delay(50);
    Serial.print("Resuming temperature scanning...........");
     Serial.println("    ");delay(500);
  }
  return true;

}

//boolean read_sensor2() {
//  uint16_t step2 = analogRead(A2);
//  //uint16_t step2 = analogRead(tempPin2);
//  float temperature2 = amt1001_gettemperature(step2);
//
//
//  return true;

//}
