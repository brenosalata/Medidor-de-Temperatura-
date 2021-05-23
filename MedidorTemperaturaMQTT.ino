#include <ESP8266WiFi.h> // Inclusão de biblioteca do ESP8266 WiFi
#include <PubSubClient.h> // Inclusão da biblioteca de Publicador/Subscrito
#define MSG_BUFFER_SIZE (50) // Tamanho do buffer de recebimento
char msg[MSG_BUFFER_SIZE];                                                                        // A Mensagem será do tipo char e do tamanho definido pelo buffer de recebimento // 
#include <Adafruit_Sensor.h>
#include <DHT.h> // Biblioteca do sensor 
#include <DHT_U.h> 
#define DHTPIN 5 // Pino utilizado para o DHT, correspondente ao D1
#define DHTTYPE DHT22 // Define o tipo de DHT
DHT_Unified dht(DHTPIN, DHTTYPE);                                                                 // Considera valor do pino e do tipo de DHT
uint32_t delayMS;                                                                                 // Variável de atraso
const char* ssid = "Marco ";                                                                    // ID de conexão 
const char* password = "breno1breno1";                                                              // senha de conexão
const char* mqtt_server = "broker.mqtt-dashboard.com";                                            // endereço do broker
WiFiClient espClient;                                                                             // Cliente ESP WiFi
PubSubClient client(espClient);                                                                   // Cliente ESP Publicador/Subscrito
unsigned long lastMsg = 0;                                                                        // define última mensagem com valor inicial igual a zero
int value = 0;                                                                                    // variável de valor inteiro inicializada em zero
int ligado = 0;
char lampada;                                                                                    // inclui variável char de nome lampada /LED D7/

void setup() {                                                                                    // laço de configuração 
  
  dht.begin();                                                                                    // inicializa DHT
  Serial.println(F("Sensor DHT22"));                                                              // Printa "Sensor DHT22"
  sensor_t sensor;                                                                                // Sensor de temperatura
  
  /////////Sensor de Temperatura//////////
  dht.temperature().getSensor(&sensor);                                                           // imprime detalhes do sensor de temperatura
  Serial.println(F("------------------------------------"));                                      // Printa quebra de linha com ----
  Serial.println(F("Temperatura"));                                                               // Printa "Temperatura"
  Serial.print  (F("Sensor: ")); Serial.println(sensor.name);                                     // Printa o nome do sensor
  Serial.print  (F("Valor máximo: ")); Serial.print(sensor.max_value); Serial.println(F("°C")); //Printa valor máximo de temperatura em graus Celsius
  Serial.print  (F("Valor mínimo: ")); Serial.print(sensor.min_value); Serial.println(F("°C")); //Printa valor mínimo de temperatura em graus Celsius
  Serial.print  (F("Resolução: ")); Serial.print(sensor.resolution); Serial.println(F("°C"));    // Printa a resolução em graus Celsius
  Serial.println(F("------------------------------------"));                                      // quebra de linha com ----
 
  /////////Sensor de Umidade//////////
  dht.humidity().getSensor(&sensor);                                                              // imprime detalhes do sensor de umidade
   Serial.println(F("------------------------------------"));                                     // Printa quebra de linha com ----
  Serial.println(F("Umidade"));                                                                   // Printa "Umidade"
  Serial.print  (F("Sensor: ")); Serial.println(sensor.name);                                     // Printa o nome do sensor
  Serial.print  (F("Valor máximo: ")); Serial.print(sensor.max_value); Serial.println(F("%"));  // Printa o valor máximo de umidade em porcentagem
  Serial.print  (F("Valor mínimo: ")); Serial.print(sensor.min_value); Serial.println(F("%"));  // Printa o valor mínimo de umidade em porcentagem
  Serial.print  (F("Resolução: ")); Serial.print(sensor.resolution); Serial.println(F("%"));     // Printa a resolução em porcentagem
  Serial.println(F("------------------------------------"));                                      // quebra de linha com ----
  
  delayMS = sensor.min_delay / 1000;        

  
  lampada = 13;                                                                                  // define lampada como o LED ligado ao pin 13 (D7 do ESP8266)
 
  pinMode(lampada, OUTPUT);                                                                      // configura lampada como saída
  
  Serial.begin(115200);                                                                           // define baudrate da comunicação serial
  
  setup_wifi();                                                                                   // configuração WiFi
  client.setServer(mqtt_server, 1883);                                                            // seta servidor como mqtt de port 1883
  client.setCallback(callback);                                                                   // seta mensagem de retorno
}

void setup_wifi() {                                                                               // inicia laço de configuração WiFi

  delay(10);                                                                                      // atraso de 0,01S;
  Serial.println("");                                                                             // quebra de linha
  Serial.print("Conectando com ");                                                                // printa na serial "Conectado com"
  Serial.println(ssid);                                                                           // printa ID da rede

  WiFi.begin(ssid, password);                                                                     // inicializa o WiFi com o uso da ID de rede e da senha

  while (WiFi.status() != WL_CONNECTED) {                                                         // enquanto o WiFi não estiver conectado, printa na serial "."
    delay(500);                                                                                   // atraso de 0.5 para aparecimento de um novo "."
    Serial.print(".");                                    
  }                  

  Serial.println("");                                                                             // quebra de linha 
  Serial.println("WiFi conectado");                                                               // printa "WiFi conectado"
  Serial.println("IP: ");                                                                         // printa "IP:"
  Serial.println(WiFi.localIP());                                                                 // printa na serial o IP da conexão local
}

void callback(char* topic, byte* payload, unsigned int length) {                                  // inicializa mensagem de retorno (tópico, mensagem e comprimento) 
  Serial.print("Mensagem recebida [");                                                            // printa "Mensagem recebida ["
  Serial.print(topic);                                                                            // printa o nome do tópico que enviou a mensagem
  Serial.print("] ");                                                                             // fecha "]"
  for (int i = 0; i < length; i++) {                                                              // Para i = 0 e enquanto i for menor que o comprimento da mensagem, inclui um caractere
    Serial.print((char)payload[i]);                                                               // printa o conteúdo da mensagem
  }
  Serial.println("");                                                                             // quebra de linha
   Serial.println("");                                                                            // quebra de linha
   if ((char)payload[0] == 'b') {                                                                 // se a mensagem recebida for b (minúsculo)
    digitalWrite(lampada, HIGH);                                                                  // a lampada vai para o nível lógico alto, apagando a lampada
    ligado = 1;                                                                                   //variavel ligado ganha valor 1 para identificar lampada desativada.
    snprintf (msg, MSG_BUFFER_SIZE, "Lâmpada desativada!");                                       // aparece mensagem indicando que a lampada está desativada
    Serial.print("Publica mensagem: ");                                                           // printa "Publica mensagem:"
    Serial.println(msg);                                                                          // printa a mensagem
    client.publish("medidor/lamp", msg);                                                         // publica a mensagem no tópico "medidor/lamp"
    
  }
  if((char)payload[0] == 'c'){
    snprintf (msg, MSG_BUFFER_SIZE, "Lâmpada ativada!");                                          // aparece mensagem indicando que a lampada está ativada
    ligado = 0;                                                                                   //variavel ligado ganha valor 0 para identificar lampada ativada de novo
    Serial.print("Publica mensagem: ");                                                           // printa "Publica mensagem:"
    Serial.println(msg);                                                                          // printa a mensagem
    client.publish("medidor/lamp", msg);                                                         // publica a mensagem no tópico "medidor/lamp" 
  }
}

void reconnect() {                                                                                // laço para reconexão 
  while (!client.connected()) {                                                                   // enquanto não é estabelecida reconexão
    Serial.print("Aguardando conexão MQTT...");                                                   // printa no serial "Aguardando conexão MQTT..." 
    String clientId = "ESP8266Client";                                       
    clientId += String(random(0xffff), HEX);                                                      // cria uma identidade de cliente aleatória
    if (client.connect(clientId.c_str())) {                                                       // Se é realizada a conexão
      Serial.println("conectado");                                                                // printa "conectado" no serial 
      client.subscribe("medidor/publisher");                                                         // e realiza subscrição no tópico "medidor/publisher" 
    } else {                                                                                      // caso contrário
      Serial.print("falhou, rc=");                                                                // printa a mensagem "falhou, rc="
      Serial.print(client.state());                                                               // printa status do client
      Serial.println("tente novamente em 5s");                                                    // printa na serial "tente novamente em 5s" 
      delay(5000);                                                                                // atraso de 5s antes de reiniciar o laço void reconnect
    }
  }
}

void loop() {                                                                                     // laço de repetição 
  delay(delayMS);                                                                                 // atraso 
  sensors_event_t event;                                                                          // inicia evento de medições do sensor
  dht.temperature().getEvent(&event);                                                             // inicia evento de DHT temperatura
  if (isnan(event.temperature)) {                                                                 // se não ocorrer a leitura de temperatura
    Serial.println(F("Erro na leitura da temperatura!"));                                         // printa a mensagem "Erro na leitura da temperatura!"
  }
  else {                                                                                          // caso contrário
    Serial.print(F("Temperatura: "));                                                             // Printa "Temperatura:"
    Serial.print(event.temperature);                                                              // Imprime na serial a medição de temperatura
    Serial.println(F("°C"));                                                                      // Printa C°
    sprintf(msg,"%f",event.temperature);                                                          // Salva o valor de temperatura na mensagem
    client.publish("medidor/temperatura", msg);                                                      // Publica a mensagem no tópico medidor/temperatura
  }
    if(event.temperature > 30.00 && ligado == 0){                                                 //Verifica se temperatura está maior que 30 graus e se variavel ligado está com o valor de 0
      digitalWrite(lampada, LOW);                                                                 //Caso sim, liga a lampada
    }
   
   if(event.temperature < 30.00 && ligado == 0){                                                  //Verifica se temperatura está menor que 30 graus e se variavel ligado está com o valor 0 
      digitalWrite(lampada, HIGH);                                                                //Caso sim, apaga a lampada
    }
    
  dht.humidity().getEvent(&event);                                                                // inicia evento de DHT umidade
  if (isnan(event.relative_humidity)) {                                                           // se não ocorrer a leitura da umidade 
    Serial.println(F("Erro na leitura da umidade!"));                                             //printa a mensagem "Erro na leitura da umidade!"
  }
  else {                                                                                          // caso contrário
    Serial.print(F("Umidade: "));                                                                 // printa "Umidade:"
    Serial.print(event.relative_humidity);                                                        // Imprime na serial a medição de umidade
    Serial.println(F("%"));                                                                       // Printa %
    sprintf(msg,"%f",event.relative_humidity);                                                    // Salva o valor de umidade na mensagem
    client.publish("medidor/umidade", msg);                                                       // Publica a mensagem no tópico medidor/umidade
  }
  if (!client.connected()) {                                                                      // Se o cliente não se conectar
    reconnect();                                                                                  // vai para laço de reconexão
  }
  client.loop();                                                                                  // permitir o processamento e a publicação de mensagens e dados
}
