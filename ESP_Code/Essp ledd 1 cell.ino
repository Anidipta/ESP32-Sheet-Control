#include <WiFi.h>
#include <HTTPClient.h>. // to read data from google sheets

const int ledPin = 5;
// #include <Wire.h>
// #include <Adafruit_GFX.h>
// #include <Adafruit_SSD1306.h>

/****************************/
//Things to change
const char * ssid = "Your_wifi_name";
const char * password = "Your_wifi_credentials";
String GOOGLE_SCRIPT_ID = "spreadsheet script key";

const int sendInterval = 5000; 
/****************************/
// #define SCREEN_WIDTH 128 // OLED display width, in pixels
// #define SCREEN_HEIGHT 64 // OLED display height, in pixels

// // Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
// #define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
// Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// #define NUMFLAKES     10 // Number of snowflakes in the animation example

// #define LOGO_HEIGHT   16
// #define LOGO_WIDTH    16



WiFiClient client;

// void testdrawstyles(String str) {
//   display.clearDisplay();

//   display.setTextSize(2);             // Normal 1:1 pixel scale
//   display.setTextColor(SSD1306_WHITE);        // Draw white text
//   display.setCursor(0,0);             // Start at top-left corner
// //  display.println(F("GSheet C2:"));
// //  display.setCursor(0,1);             // Start at top-left corner
//   display.println(F(str.c_str()));
//   display.display();
//   delay(2000);
// }

void setup() {
  Serial.begin(115200);
  delay(1000);
  pinMode(ledPin, OUTPUT);
    // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  // if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for 128x64              //OLED Display initialisation
  //   Serial.println(F("SSD1306 allocation failed"));
  //   for(;;); // Don't proceed, loop forever
  // }
  // display.clearDisplay();
  // display.drawBitmap(0, 0, image_data_Image, 128, 64, 1);
  // display.display();
  // delay(2000); // Pause for 2 seconds
  // display.clearDisplay();


  WiFi.mode(WIFI_STA);                //Initialising the wifi communication
  WiFi.begin(ssid, password);

  Serial.println("Started");
  Serial.print("Connecting");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  
Serial.println("Ready to go");
//testdrawstyles();
}

void loop() {
  spreadsheet_comm();           //communicating with the spreadsheet
  delay(sendInterval);
}

void spreadsheet_comm(void) {
   HTTPClient http;
   String url="https://script.google.com/macros/s/"+GOOGLE_SCRIPT_ID+"/exec?read";
//   Serial.print(url);
	Serial.print("Making a request");
	http.begin(url.c_str()); //Specify the URL and certificate
  http.setFollowRedirects(HTTPC_STRICT_FOLLOW_REDIRECTS);
	int httpCode = http.GET();
  String payload;
    if (httpCode > 0) { //Check for the returning code
        payload = http.getString();
        
        Serial.println(httpCode);
        if (payload == "0")
          digitalWrite(ledPin, LOW);
        else if (payload == "1")
          digitalWrite(ledPin, HIGH);
        Serial.println(payload);
        //testdrawstyles(payload);
      }
    else {
      Serial.println("Error on HTTP request");
    }
	http.end();
}