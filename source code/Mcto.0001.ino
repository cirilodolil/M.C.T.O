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

//vento
int vento_pin =0;
float valor_vento= 0;
int direcao_vento = 0;

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


   valor_vento = analogRead(vento_pin)* (5.0 / 1023.0);

   
 
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

void verificarDirecaoVento()
{
  if (valor_vento <= 0.27) {
direcao_vento = 315;
}
else if (valor_vento <= 0.32) { 
direcao_vento = 270;
}
else if (valor_vento <= 0.38) { 
direcao_vento = 225;
}
else if (valor_vento <= 0.45) { 
direcao_vento = 180;
}
else if (valor_vento <= 0.57) { 
direcao_vento = 135;
}
else if (valor_vento <= 0.75) { 
direcao_vento = 90;
}
else if (valor_vento <= 1.25) {  
direcao_vento = 45;
}
else {  
direcao_vento = 000;
  
}
}

