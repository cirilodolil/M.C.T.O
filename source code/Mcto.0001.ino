#include <Adafruit_BMP280.h>


#include <ESP8266WiFi.h> 

#define SSID_REDE     " " //NOME DA REDE
#define SENHA_REDE    "  "  //SENHA DA REDE

char EnderecoAPI[] = "";
String ChaveAPI = "";
long TempoConexao; 
Adafruit_BMP280 sensor_bmp;

//capitador de agua 
int clicks;
float volume;
int reed_switch_pin = 8;
boolean last_reed_switch_state = LOW;


WiFiClient client;
 
void setup() {
 
Serial.begin(9600);
pinMode(reed_switch_pin, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
FazConexaoWiFi();
}

void FazConexaoWiFi()
{
    client.stop();
    Serial.println("Conectando-se à rede WiFi...");
    Serial.println();  
    delay(1000);
    WiFi.begin(SSID_REDE, SENHA_REDE);
 
    while (WiFi.status() != WL_CONNECTED) 
    {
        delay(500);
        Serial.print(".");
    }
 
    Serial.println("");
    Serial.println("WiFi connectado com sucesso!");  
    Serial.println("IP obtido: ");
    Serial.println(WiFi.localIP());

   
 
    delay(1000);



    
}
void pressao()
{
    Serial.println(sensor_bmp.readPressure());
}

void pluviometro()
{
   int reed_switch_state = digitalRead(reed_switch_pin);

    if (last_reed_switch_state == LOW && reed_switch_state == HIGH) {
    clicks++;
    }

     volume = clicks * 7.02;
   
}

