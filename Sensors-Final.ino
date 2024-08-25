#include <WiFi.h>
#include <WiFiAP.h>
#include <DHT.h>
#define MOISTURE_SENSOR_PIN 12
#define DHT_SENSOR_PIN 14

const char *ssid = "MYESP32";
const char *password = "ESP32Pass";

WiFiServer server(80);
DHT dht(DHT_SENSOR_PIN, DHT11);


#define ENA 0
#define IN1 5
#define IN2 18
#define IN3 19
#define IN4 21
#define ENB 2

int motorState = 0;
int Speed = 0;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(MOISTURE_SENSOR_PIN, INPUT);
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENB, OUTPUT);

  Serial.begin(115200);
  Serial.println("Configuring access point...");

  if (!WiFi.softAP(ssid, password)) {
    Serial.println("Soft AP creation failed.");
    while (1);
  }

  IPAddress myIP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(myIP);
  server.begin();
  dht.begin();
  Serial.println("Server started");
}

void loop() {
  
  WiFiClient client = server.available();

  if (client) {
    Serial.println("New Client.");
    String currentLine = "";

    while (client.connected()) {
      if (client.available()) {
        char c = client.read();
        Serial.write(c);

        if (c == '\n') {
          if (currentLine.length() == 0) {
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println();
            
            client.println("<html><body>");
            client.println("<h1>Motor Control and Sensor Data</h1>");
            client.print("Moisture: ");
            client.print(analogRead(MOISTURE_SENSOR_PIN));
            client.println("<br>");
            client.print("Temperature (°C): ");
            client.print(dht.readTemperature());
            client.println("<br>");

            client.println("<h1>Motor Control</h1>");
            client.println("<p><a href=\"/forward\"><button>Right</button></a></p>");
            client.println("<p><a href=\"/reverse\"><button>Left</button></a></p>");
            client.println("<p><a href=\"/left\"><button>Forward</button></a></p>");
            client.println("<p><a href=\"/right\"><button>Backward</button></a></p>");

            client.println("</body></html>");
            client.println();
            break;
          } else {
            currentLine = "";
          }
        } else if (c != '\r') {
          currentLine += c;
        }

        if (currentLine.endsWith("GET /forward")) {
          motorForward();
        }
        if (currentLine.endsWith("GET /reverse")) {
          motorReverse();
        }
        if (currentLine.endsWith("GET /left")) {
          motorLeft();
        }
        if (currentLine.endsWith("GET /right")) {
          motorRight();
        }
      }
    }
    client.stop();
    Serial.println("Client Disconnected.");
  }
}

void motorForward() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  motorState = 1;
}

void motorReverse() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  motorState = -1;
}

void motorLeft() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  motorState = 0; // You may need to set a different value for left.
}

void motorRight() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  motorState = 0; // You may need to set a different value for right.
}

