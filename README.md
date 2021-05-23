# Medidor-de-Temperatura-

# Links do Projeto

* <a href="https://github.com/brenosalata/Medidor-de-Temperatura-/blob/main/Diagrama%20do%20Circuito%20Eletroeletrônico.jpeg"> Diagrama do Circuito Eletroeltrônico</a>
* <a href="https://github.com/brenosalata/Medidor-de-Temperatura-/blob/main/Fluxograma.jpeg"> Fluxograma do Projeto</a>
* <a href="https://github.com/brenosalata/Medidor-de-Temperatura-/blob/main/Ilustração%20da%20Montagem.jpeg"> Ilustração da Montagem do Projeto</a>
* <a href="https://github.com/brenosalata/Medidor-de-Temperatura-/blob/main/MedidorTemperaturaMQTT.ino"> Código utilizado</a>

# Introdução

O projeto tem como objetivo detectar a temperatura do ambiente para ajudar e auxiliar agricultores no plantio.

  Ao detectar a temperatura acima de 30 graus no ambiente, uma lâmpada irá acender identificando que a temperatura está alta, caso contrário essa lâmpada irá continuar apagada. Utilizaremos também um aplicativo chamado MQTT Dash, ele terá o papel de receber os dados de temperatura e umidade atual, além de conter um botão para ativar ou desativar a lâmpada que define se ela fica acessa ou apagada levando em consideração sua regra de acender com certa temperatura.

![Projeto Final](https://github.com/brenosalata/Medidor-de-Temperatura-/blob/cbf12e8e2306d08e75e33b5e81af7880b989607d/Intro.jpeg)

# Componentes utilizados

* NodeMCU ESP8266
* Cabo Micro USB
* Sensor de temperatura e umidade DHT22
* 2 Protoboards de 830 e 400 pontos
* 5 Jumpers Macho-Fêmea
* 1 Jumpers Macho-Macho
* Módulo Relé 5V 10A
* Lâmpada 127V
* Soquete
* Cabo de força flexível com Plug
* Arduino IDE
* MQTT Box
* MQTT Dash
* 1 Resistor 220ohms

# Modo de Montagem

![Montagem](https://github.com/brenosalata/Medidor-de-Temperatura-/blob/2929517f98f99c64584ca48646160f7267422230/Montagem.png)

# Sobre o código

Para programar o que vamos desenvolver devemos primeiramente baixar o Arduino IDE e caso não tenha esse Software você pode fazer o download <a href="https://www.arduino.cc/en/software"> clicando aqui.</a>

Agora que já temos o Arduino IDE Instalado, vamos instalar dentro dele as bibliotecas necessárias, são elas:

* esp8266 by ESP8266 Community que permite que a placa NodeMcu seja reconhecida;
* PubSubClient que perimite a comunicação com o MQTT com seus tópicos publishers e subscribers tornando possível a utilização do mqtt;
* DHT Sensor Library da Adafruit que é responsável por fazer com que o sensor de temperatura funcione corretamente capturando a temperatura e umidade.

Após ter todas essas bibliotecas instaladas, o código em si fica fácil de ser compreendido:
Temos que configurar e instanciar as variáveis para fazer a conexão com o Wifi, a conexão do MQTT e o buzzer. O método loop() que será responsável por ler as váriaveis, printar valores no monitor especial e no MQTT.

No código disponibilizado é descrito o passo a passo do que foi feito, caso queira entender profundamente o que foi realizado,  <a href="https://github.com/brenosalata/Medidor-de-Temperatura-/blob/main/MedidorTemperaturaMQTT.ino"> clique aqui.</a>

# MQTT

No projeto desenvolvido utilizamos o MQTT Box e o MQTT Dash ambos para monitorar e controlar as publicações e subscrições dos tópicos, em ambos também fizemos a conexão com o broker público "broker.mqtt-dashboard.com".

No projeto utilizamos o MQTT Box para testar se as publicações e subscrições estavam funcionando, logo após os testes para identificar o funcionamento correto partimos para o MQTT Dash que além de permitir controlar essas publicações e subscrições ele permite uma automatização da ferramenta, foi através dele que incluimos um botão para ativar e desativar a lâmpada e um campo de texto que avisa esse status da lâmpada em tempo real. E por estar utilizando um celular para tal função conseguimos por longas distancias checar a temperatura, umidade e o status, além de controlar a lâmpada, isso tudo somente com a conexão wi-fi e o protocolo MQTT

# Vídeo Demonstrativo

Para detalhar ainda mais o que foi desenvolvido disponibilizamos um vídeo para melhor compreensão do passo a passo de criação até o funcionamento do projeto final.


<a href="https://youtu.be/cJ_ocS_aPRQ"> ![Video](https://github.com/brenosalata/Medidor-de-Temperatura-/blob/e5484b4178d0253f322f97da720fcd705a50b9a4/videos-youtube.jpg) </a>


<a> Para acessar o vídeo clique na imagem acima.</a>
