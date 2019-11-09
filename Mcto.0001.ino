

#include <ESP8266WiFi.h> 

#define SSID_REDE     " " //NOME DA REDE
#define SENHA_REDE    "  "  //SENHA DA REDE

char EnderecoAPI[] = "";
String ChaveAPI = "";
long TempoConexao; 
WiFiClient client;
 
void setup() {
 
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
FazConexaoWiFi();
}

void FazConexaoWiFi(void)
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
