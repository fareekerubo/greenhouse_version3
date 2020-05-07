boolean read_sensor()
{
  current_time = millis() / 1000;
  // Serial.print("Interval:"); Serial.print((current_time - previous_time));Serial.println("  ");
  if ((current_time - previous_time) <= 1800) //1800
  {
    step = analogRead(tempPin);
    step1 = analogRead(tempPin1);
    //step2 = analogRead(tempPin2);
    Serial.println(current_time);
    float  temperature2 = amt1001_gettemperature(step);
    float  temperature3 = amt1001_gettemperature(step1);
    float t_vol = (temperature2 + temperature3)/2;
     ds18b20_sensor();
    temperature4 = average; //variable ground temp
    humidity_sensor();
    hum_temperature = humidity_average;
    Serial.println("......................................");
    Serial.println("starting to read");
    dataMessage2 = (" FARM:    NG001 \n Ambient  Temp:" + String(t_vol) + "*C " );
    dataMessage3 = ("Ground Temp:" + String(temperature4) + "*C " );
    hum_datamessage = (" Humidity : "  + String (hum_temperature) + "%");
    Serial.println(dataMessage2);
    //Serial.print("          ");
    Serial.println(dataMessage3);
   // Serial.print("          ");
    Serial.println( hum_datamessage);
    

    digitalWrite(ledPin, HIGH);
    delay(50);
    digitalWrite(ledPin, LOW);
    delay(50);

    if ((current_time - previous_time) == 300) //300
    {
      //temperature = amt1001_gettemperature(step);
     // temperature1 = amt1001_gettemperature(step1);
     // t1 = (temperature + temperature1) / 2;
      delay(50);
     t1=t_vol;
      delay(50);
      t7 = temperature4;
      h2 = hum_temperature;
      Serial.print("first value:");
      Serial.print(t1);   Serial.print("      "); Serial.print(t7); Serial.print("      "); Serial.print(h2);
      Serial.println("  ");
      delay(50);
    }
    else if ((current_time - previous_time) == 600) //600
    {
      //temperature = amt1001_gettemperature(step);
      //temperature1 = amt1001_gettemperature(step1);
      //t2 = (temperature + temperature1) / 2;
      delay(50);
     t2=t_vol;
      delay(50);
      t8 = temperature4;
      h3 = hum_temperature;
      Serial.print("second value: ");
      Serial.print(t2); Serial.print("      "); Serial.print(t8); Serial.print("      "); Serial.print(h3);
      Serial.println("  ");
      delay(50);
    }
    else if ((current_time - previous_time) == 900) //900
    {
      //temperature = amt1001_gettemperature(step);
      //temperature1 = amt1001_gettemperature(step1);
      //t3 = (temperature + temperature1) / 2;
      delay(50);
     t3=t_vol;
      delay(50);
      t9 = temperature4;
      h4 = hum_temperature;
      Serial.print("third value: ");
      Serial.print(t3); Serial.print("      "); Serial.print(t9); Serial.print("      "); Serial.print(h4);
      Serial.println("  ");
      delay(50);
    }
    else if ((current_time - previous_time) == 1200) //1200
    {
     // temperature = amt1001_gettemperature(step);
     // temperature1 = amt1001_gettemperature(step1);
     // t4 = (temperature + temperature1) / 2;
      delay(50);
     t4=t_vol;
      delay(50);
      t10 = temperature4;
      h5 = hum_temperature;
      Serial.print("forth value: ");
      Serial.print(t4); Serial.print("      "); Serial.print(t10); Serial.print("      "); Serial.print(h5);
      Serial.println("  ");
      delay(50);
    }
    else if ((current_time - previous_time) == 1500) //1500
    {
      //temperature = amt1001_gettemperature(step);
      //temperature1 = amt1001_gettemperature(step1);
      //t5 = (temperature + temperature1) / 2;
      delay(50);
     t5=t_vol;
      delay(50);
      t11 = temperature4;
      h6 = hum_temperature;
      Serial.print("fifth value:  ");
      Serial.print(t5); Serial.print("      "); Serial.print(t11); Serial.print("      "); Serial.print(h6);
      Serial.println("  ");
      delay(50);
    }

    else if ((current_time - previous_time) == 1800) //1800
    {
     // temperature = amt1001_gettemperature(step);
     // temperature1 = amt1001_gettemperature(step1);
     // t6 = (temperature + temperature1) / 2;
      delay(50);
     t6=t_vol;
      delay(50);
      t12 = temperature4;
      h7 = hum_temperature;
      Serial.print("sixth value:  ");
      Serial.print(t6); Serial.print("      "); Serial.print(t12); Serial.print("      "); Serial.print(h7);
      dataMessage1 = ("Ambient Inst. Temp:" + String(t6) + "*C " );
      // dataMessage4 = ("Ground Inst. Temp:" + String(t12) + "*C " );
      delay(50);

    }

  }
  else {
    digitalWrite(ledPin2,HIGH);
    digitalWrite(ledPin,LOW);
    Serial.println("........................... ");
    Serial.print("Fifth minute value:"); Serial.print(t1); Serial.print("      "); Serial.print(t7); Serial.print("   "); Serial.print(h2); Serial.println(" ");
    Serial.print("Tenth minute value:"); Serial.print(t2); Serial.print("      "); Serial.print(t8); Serial.print("   "); Serial.print(h3); Serial.println(" ");
    Serial.print("Fifteenth minute value:"); Serial.print(t3); Serial.print("      "); Serial.print(t9); Serial.print("  "); Serial.print(h4); Serial.println(" ");
    Serial.print("Twentieth minute value:"); Serial.print(t4); Serial.print("      "); Serial.print(t10); Serial.print("  "); Serial.print(h5); Serial.println(" ");
    Serial.print("Twenty-Fifth minute value:"); Serial.print(t5); Serial.print("      "); Serial.print(t11); Serial.print(" "); Serial.print(h6); Serial.println(" ");
    Serial.print("Thirtieth minute value:"); Serial.print(t6); Serial.print("      "); Serial.print(t12); Serial.print("  "); Serial.print(h7); Serial.println(" ");

    Serial.println("  ");
    delay(1000);
    avg = (t1 + t2 + t3 + t4 + t5 + t6) / 6;
    avg1 = (t7 + t8 + t9 + t10 + t11 + t12) / 6;
    avg2 = (h2 + h3 + h4 + h5 + h6 + h7) / 6;
    Serial.print("Avarage:  ");
    Serial.print(avg);  Serial.print(">>>--<<<"); Serial.print(avg1); Serial.print(">>>--<<<"); Serial.print(avg2); Serial.println("");
    delay(1000);
    dataMessage = (" FARM:      NG001(6/30) \n Ambient  Temp: " + String(avg) + "*C " );
    dataMessage5 = (" Ground    Temp: " + String(avg1) + "*C " );
    dataMessage6 = (" Humidity: " + String(avg2) + "% " );
                    Serial.print(dataMessage); Serial.print(">>>--<<<"); Serial.print(dataMessage5); Serial.print(">>>--<<<");
                    Serial.print(dataMessage6); //Serial.print(">>>--<<<"); Serial.print(dataMessage6);
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
                    digitalWrite(ledPin2,LOW);
                    Serial.println("    "); delay(500);
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
