# Medidor-de-Temperatura-

# Links do Projeto

* <a href="https://github.com/brenosalata/Medidor-de-Temperatura-/blob/main/Diagrama%20do%20Circuito%20Eletroeletrônico.jpeg"> Diagrama do Circuito Eletroeltrônico</a>
* <a href="https://github.com/brenosalata/Medidor-de-Temperatura-/blob/main/Fluxograma.jpeg"> Fluxograma do Projeto</a>
* <a href="https://github.com/brenosalata/Medidor-de-Temperatura-/blob/main/Ilustração%20da%20Montagem.jpeg"> Ilustração da Montagem do Projeto</a>
* <a href="https://github.com/brenosalata/Medidor-de-Temperatura-/blob/main/MedidorTemperaturaMQTT.ino"> Código utilizado</a>

# Introdução

O projeto tem como objetivo detectar a temperatura do ambiente para ajudar e auxiliar agricultores no plantio.

  Ao detectar a temperatura acima de 30 graus no ambiente, uma lâmpada irá acender identificando que a temperatura está alta, caso contrário essa lâmpada irá continuar apagada. Utilizaremos também um aplicativo chamado MQTT Dash, ele terá o papel de receber os dados de temperatura e umidade atual, além de conter um botão p

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

![Montagem](https://github.com/brenosalata/Medidor-de-Temperatura-/blob/2b8228919a6943c7ee43e3e2473560f2743222dd/Ilustra%C3%A7%C3%A3o%20da%20Montagem.jpeg)

# Sobre o código

Para programar o que vamos desenvolver devemos primeiramente baixar o Arduino IDE e caso não tenha esse Software você pode fazer o download <a href="https://www.arduino.cc/en/software"> clicando aqui.</a>

Agora que já temos o Arduino IDE Instalado, vamos instalar dentro dele as bibliotecas necessárias, são elas:

* E

