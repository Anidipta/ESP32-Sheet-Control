# ESP32 & Google Sheets Integration Project 📡💡

## Overview 🌐

The project connects an **ESP32/ESP8266** microcontroller to a **Google Sheet** via Wi-Fi. It retrieves control values from the sheet to toggle an LED on or off, making it a simple IoT solution for remote control.

## Components 🛠️

- **ESP32/ESP8266**: Controls an LED based on data from the Google Sheet.
- **Google Sheets**: Stores control values.
- **Google Apps Script**: Handles HTTP requests to read/write data from/to the Google Sheet.
- **LED**: Optional, controlled based on Google Sheet values.

## Methodology 🔧

1. **ESP32/ESP8266** connects to Wi-Fi and sends a GET request to a Google Apps Script URL.
2. **Google Apps Script** retrieves data from the Google Sheet and returns it to the ESP32.
3. Based on the received value (e.g., `1` for LED on, `0` for LED off), the **ESP32** toggles the LED.

## Workflow 🔄

1. **ESP32** sends a GET request.
2. **Google Apps Script** fetches data from Google Sheets.
3. **ESP32** receives data and controls the LED accordingly.
4. The loop continues with periodic checks.

## Flowchat (Pipeline)

![Flowchart](ESP32-Sheet-Control/Untitled diagram-2025-01-01-152832.png)


## Impact & Applications 🌍

- **Remote Control**: Control devices like lights, fans, etc., via Google Sheets.
- **IoT Solutions**: Perfect for home automation and simple data logging.
- **Educational**: Great for learning IoT and cloud integration.

## Setup Instructions 📝

1. **Hardware**: Connect an LED to the ESP32/ESP8266.
2. **Google Sheets**: Set up a sheet and create a Google Apps Script to handle requests.
3. **Upload Code**: Replace Wi-Fi credentials and Script ID in the ESP32 code and upload it.
4. **Test**: Change values in Google Sheets and observe the LED response.
