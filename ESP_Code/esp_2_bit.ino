
// #include <WiFi.h>
// #include <HTTPClient.h>. // to read data from google sheets

// const int ledPin1 = 5;
// const int ledPin2 = 18;


// const char * ssid = "Galaxy S22";
// const char * password = "Southpoint7867";
// String GOOGLE_SCRIPT_ID = "AKfycbxYf4XwZcndV2kNCv1gjNRGR3tBVTjvJYsafEYTlR_egYt8-r5mbMG484Vu2WfAdQdy";

// const int sendInterval = 3000; 




// WiFiClient client;


// void setup() {
//   Serial.begin(115200);
//   delay(1000);
//   pinMode(ledPin1, OUTPUT);pinMode(ledPin2, OUTPUT);

//   WiFi.mode(WIFI_STA);                //Initialising the wifi communication
//   WiFi.begin(ssid, password);

//   Serial.println("Started");
//   Serial.print("Connecting");
//   while (WiFi.status() != WL_CONNECTED) {
//     delay(1000);
//     Serial.print(".");
//   }
  
// Serial.println("Ready to go");
// //testdrawstyles();
// }

// void loop() {
//   spreadsheet_comm();           //communicating with the spreadsheet
//   delay(sendInterval);
// }

// void spreadsheet_comm(void) {
//    HTTPClient http;
//    String url="https://script.google.com/macros/s/"+GOOGLE_SCRIPT_ID+"/exec?read";
// //   Serial.print(url);
// 	Serial.print("Making a request");
// 	http.begin(url.c_str()); //Specify the URL and certificate
//   http.setFollowRedirects(HTTPC_STRICT_FOLLOW_REDIRECTS);
// 	int httpCode = http.GET();
//   String payload;
//     if (httpCode > 0) { //Check for the returning code
//         payload = http.getString();
        
//         Serial.println(httpCode);
//         if (payload == "0")
//           digitalWrite(ledPin, LOW);
//         else if (payload == "1")
//           digitalWrite(ledPin, HIGH);
//         Serial.println(payload);
//         //testdrawstyles(payload);
//       }
//     else {
//       Serial.println("Error on HTTP request");
//     }
// 	http.end();
// }

#include <WiFi.h>
#include <HTTPClient.h>  // to read data from google sheets

const int ledPin1 = 2;    // LED for C2
const int ledPin2 = 4;   // LED for D2

const char *ssid = "Biswas Family";
const char *password = "Biswas@2005";
String GOOGLE_SCRIPT_ID = "AKfycbxYf4XwZcndV2kNCv1gjNRGR3tBVTjvJYsafEYTlR_egYt8-r5mbMG484Vu2WfAdQdy";

const int sendInterval = 3000;

WiFiClient client;

void setup() {
  Serial.begin(115200);
  delay(1000);
  
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);

  WiFi.mode(WIFI_STA);                // Initializing Wi-Fi communication
  WiFi.begin(ssid, password);

  Serial.println("Started");
  Serial.print("Connecting");
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  
  Serial.println("Ready to go");
}



void spreadsheet_comm() {
  HTTPClient http;
  
  String url = "https://script.google.com/macros/s/" + GOOGLE_SCRIPT_ID + "/exec?read";
  Serial.print("Making a request");
  
  http.begin(url.c_str()); // Specify the URL and certificate
  http.setFollowRedirects(HTTPC_STRICT_FOLLOW_REDIRECTS);
  
  int httpCode = http.GET();
  String payload;
  
  if (httpCode >= 0) {  // Check for the returning code
    payload = http.getString();
    Serial.println(httpCode);
    Serial.println(payload);

    // Parse the response assuming it is in the form "C2_value,D2_value"
    int separatorIndex = payload.indexOf(',');  // Find the comma separating C2 and D2 values
    //Serial.print(separatorIndex);
    // if (separatorIndex !=-1) {
    //   String C2_value = payload.substring(0, separatorIndex);
    //   String D2_value = payload.substring(separatorIndex + 1);

    String C2_value = payload.substring(0, 1);
    String D2_value = payload.substring(1);
      Serial.println(C2_value);
      Serial.println(D2_value);
      // Control LED for C2
      if (C2_value == "0") {
        digitalWrite(ledPin1, LOW);
      } else  {
        digitalWrite(ledPin1, HIGH);
      }

      // Control LED for D2
      if (D2_value == " 0") 
      
        digitalWrite(ledPin2, LOW);
       else   
        digitalWrite(ledPin2, HIGH);
  }

  http.end();
}
void loop() {
  spreadsheet_comm();           // Communicating with the spreadsheet
  delay(1000);
}
