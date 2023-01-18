#include <Adafruit_MQTT.h>
#include <Adafruit_MQTT_Client.h>

// Define the MQTT connection details
#define IO_USERNAME "your_username"
#define IO_KEY "your_key"
#define IO_SERVER "io.adafruit.com"
#define IO_SERVERPORT 1883

// Create an instance of the MQTT client
WiFiClient client;
Adafruit_MQTT_Client mqtt(&client, IO_SERVER, IO_SERVERPORT, IO_USERNAME, IO_KEY);

// Create an instance of the MQTT feed for the light
Adafruit_MQTT_Subscribe light_feed = Adafruit_MQTT_Subscribe(&mqtt, IO_USERNAME "/feeds/light");
// Create an instance of the MQTT feed for the light value
Adafruit_MQTT_Publish light_value = Adafruit_MQTT_Publish(&mqtt, IO_USERNAME "/feeds/light_value");

// Pin for controlling the light
const int LIGHT_PIN = 11;
// Variable for controlling the brightness of the light
int light_value_dim = 0;

// Function executed when the zero cross is detected
void zero_cross() {
  // Calculate the dimming time in microseconds
  int dimming_time = (200 * light_value_dim);

  // Wait for the dimming time
  delayMicroseconds(dimming_time);

  // Turn on the light for 10 microseconds
  digitalWrite(LIGHT_PIN, HIGH);
delayMicroseconds(10);
digitalWrite(LIGHT_PIN, LOW);
}

// Setup function, executed when the program starts
void setup() {
pinMode(LIGHT_PIN, OUTPUT); // Set the light pin as output
attachInterrupt(digitalPinToInterrupt(2), zero_cross, CHANGE); // Attach an interrupt to pin 2

// Connect to WiFi
WiFi.begin("your_ssid", "your_password");
while (WiFi.status() != WL_CONNECTED) {
delay(1000);
}

// Connect to the MQTT server
mqtt.subscribe(&light_feed);
}

// Loop function, executed continuously after setup is finished
void loop() {
// Read the value from the potentiometer
int data = analogRead(A0);
// Map the potentiometer value to the range of 10 to 49
int dim_val_scaled = map(data, 0, 1023, 10, 49);
// Set the light value
light_value_dim = dim_val_scaled;
// Publish the light value to the MQTT feed
light_value.publish(light_value_dim);

// Check for new MQTT data
Adafruit_MQTT_Subscribe *subscription;
while ((subscription = mqtt.readSubscription(10))) {
if (subscription == &light_feed) {
light_value_dim = atoi((char *)light_feed.lastread);
}
}
    // Keep the MQTT connection alive
  mqtt.ping();
}
