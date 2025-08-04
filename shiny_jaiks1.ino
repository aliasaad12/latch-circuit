#define TRIG_PIN 9
#define ECHO_PIN 10
#define TEMP_PIN A0

void setup() {
  pinMode(TRIG_PIN, OUTPUT);    // Set TRIG_PIN as an OUTPUT
  pinMode(ECHO_PIN, INPUT);     // Set ECHO_PIN as an INPUT
  pinMode(TEMP_PIN, INPUT);     // Set TEMP_PIN for TMP36 sensor
  Serial.begin(9600);           // Start the Serial Monitor at 9600 baud rate
}

void loop() {
  // Ultrasonic Sensor: Sending a pulse
  digitalWrite(TRIG_PIN, LOW); // Ensure trigger pin is low initially
  delayMicroseconds(2);        // Wait for a moment
  digitalWrite(TRIG_PIN, HIGH); // Send a 10 microsecond pulse to trigger the sensor
  delayMicroseconds(10);       // Pulse duration
  digitalWrite(TRIG_PIN, LOW); // End pulse
  
  // Read the response from the Echo pin
  long duration = pulseIn(ECHO_PIN, HIGH);  // Get the pulse duration
  long distance = (duration / 2) * 0.0343; // Calculate distance in cm
  
  // TMP36: Read the temperature
  int tempValue = analogRead(TEMP_PIN); // Read analog value from TMP36
  float voltage = (tempValue / 1024.0) * 5.0; // Convert the value to voltage
  float temperatureC = (voltage - 0.5) * 100; // Convert voltage to temperature in Celsius

  // Print data to Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.print(" cm, ");
  Serial.print("Temperature: ");
  Serial.print(temperatureC);
  Serial.println(" C");

  delay(500); // Wait for half a second before the next reading
}
