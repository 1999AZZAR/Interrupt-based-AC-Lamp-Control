# AC Light Control with PWM and MQTT

This program controls the brightness of an AC light using pulse width modulation (PWM) and an MQTT connection. The potentiometer is used to adjust the brightness of the light.

## Hardware
- Arduino board
- AC light
- Potentiometer
- MQTT server (e.g. Adafruit IO)

## Libraries
- Adafruit MQTT
- Adafruit MQTT Client

## Setup
1. Connect your Arduino board to your computer.
2. Upload the sketch to your Arduino board.
3. Connect the AC light to pin 11 on the Arduino board.
4. Connect the potentiometer to pin A0 on the Arduino board.
5. Connect the Arduino board to your Wi-Fi network.
6. Connect to the MQTT server and subscribe to the "light" feed.
7. Use the potentiometer to adjust the brightness of the light.
8. Use the "light" feed to adjust the brightness of the light remotely.

Note: 
- Make sure to replace the WiFi's credentials (ssid and password) with the ones that corresponds to your wifi network.
- Also make sure to replace the credentials (username, key, server and serverport) with the ones that corresponds to your adaruit.io account.

This code uses an interrupt service routine (ISR) to detect zero crossing and then turn on the light for a certain duration, determined by the dimming value. The dimming value can be set either by reading the potentiometer value or by getting the value from the MQTT feed. The dimming value is also published to the "light_value" feed so that it can be read by other devices connected to the same MQTT server.
