//void query() {
//  bool is_true = SMSRequest();
//  if (is_true) {
//
//    sms_query();
//    delay(10);
//    Serial.println("donee");
//  }
//  //delay(10);
//}
//
//bool SMSRequest() {
//  if (SIM800.available() > 0) {
//    incomingString =  SIM800.readString();
//    Serial.println(incomingString);
//
//    if (incomingString.indexOf("STATE") >= 0)  {
//      incomingString = "";
//      return true;
//    }
//    incomingString = "";
//  }
//  return false;
//}
