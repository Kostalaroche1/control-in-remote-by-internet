
#include <WiFi.h>
#include <PubSubClient.h>

const char *ssid = "InfinixHOT11Play";
const char *password = "mbokostagab";

const char *mqttServer = "8c76becae14d4eb19dbf3c77e33024f2.s1.eu.hivemq.cloud";
const char *mqttUser = "hivemq.webclient.1766752674162";
const char *mqttPass = "3%7r:lRno.CDK4wkI#5N";

WiFiClient espClient;
PubSubClient client(espClient);

int relays[] = {2, 4, 5, 18, 19};

void callback(char *topic, byte *payload, unsigned int length)
{
  String msg;
  for (int i = 0; i < length; i++)
    msg += (char)payload[i];

  int index = msg.charAt(5) - '1';
  if (index >= 0 && index < 5)
    digitalWrite(relays[index], msg.endsWith("ON") ? HIGH : LOW);
}

void setup()
{
  Serial.begin(115200);
  for (int i = 0; i < 5; i++)
    pinMode(relays[i], OUTPUT);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)
    delay(500);

  client.setServer(mqttServer, 8883);
  client.setCallback(callback);
}

void loop()
{
  if (!client.connected())
  {
    client.connect("esp32cam", mqttUser, mqttPass);
    client.subscribe("home/lights");
  }
  client.loop();
}
