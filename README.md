# Medidor-de-Temperatura-

# Membros do Projeto 

* Breno Salata da Silva - 31917641
* Bianca Maciel Matos - 31936873

# Descrição de Uso e Funcionamento

O projeto tem como objetivo detectar a temperatura do ambiente para ajudar e auxiliar agricultores no plantio.

  Ao detectar a temperatura acima de 30 graus no ambiente, uma lâmpada irá acender identificando que a temperatura está alta, caso contrário essa lâmpada irá continuar apagada. Utilizaremos também um aplicativo chamado MQTT Dash, ele terá o papel de receber os dados de temperatura e umidade atual, além de conter um botão para ativar ou desativar a lâmpada que define se ela fica acessa ou apagada, levando em consideração sua regra de acender com certa temperatura.

Para melhor compreender o que foi desenvolvido disponibilizamos um vídeo demonstrativo no Youtube. 
<a href="https://youtu.be/cJ_ocS_aPRQ"> Clique aqui</a> para ser redirecionado para o vídeo.

# Hardware Utilizados

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

Agora que temos todos os Materias, vamos montar nosso protótipo.

Colocamos o metado do NodeMCU em uma protoboard (830 pontos) e o sensor de temperatura conectado em outro protoboard (430 pontos)

Ligamos os jumpers (2 Macho-Macho e 1 Macho-Fêmea) do NodeMCU com o sensor DHT22, utilizando um resistor pegando o sinal do pino VCC para o pino OUT do sensor DHT22.

Ligamos também os jumpers (3 Macho-Macho) do NodeMCU para o módulo relé, e conectamos os cabos fléxiveis no módulo relé.

Conectamos os cabos flexíveis e energia no soquete e plugamos a lâmpada no soquete.

Podemos acompanhar melhor o que foi dito acima atráves do <a href="https://github.com/brenosalata/Medidor-de-Temperatura-/blob/main/Diagrama%20do%20Circuito%20Eletroeletrônico.jpeg"> diagrama do circuito eletroeletrônico. </a>


Para melhor compreender como fica o resultado final do projeto montado, segue imagem abaixo:

![Projeto Final](https://github.com/brenosalata/Medidor-de-Temperatura-/blob/cbf12e8e2306d08e75e33b5e81af7880b989607d/Intro.jpeg)

# Software desenvolvido

Para programar o que vamos desenvolver devemos primeiramente baixar o Arduino IDE e caso não tenha esse Software você pode fazer o download <a href="https://www.arduino.cc/en/software"> clicando aqui.</a>

Após a instalação do Arduino IDE, vamos instalar dentro dele as bibliotecas necessárias. O esp8266 by ESP8266 Community que permite que o microcontrolador NodeMcu seja reconhecido, além disso vamos utilizar também o PubSubClient que perimite a comunicação com o MQTT, tópicos publishers e subscribers, tornando possível a utilização do mqtt e por fim iremos instalar o DHT Sensor Library da Adafruit que é responsável por fazer com que o sensor de temperatura funcione corretamente capturando a temperatura e umidade.

Após ter todas essas bibliotecas instaladas, vamos para parte do código:

Temos que configurar as variáveis para fazer a conexão com o Wifi, a conexão do MQTT e etc.. 

Vamos definir no código o DHT22, configurar os pin conectados no microcontrolador, definir o ID e senha de conexão para conectar no wi-fi e criar o Client ESP Publicador/Subscrito. 

No código disponibilizado é descrito o passo a passo do que foi feito com comentarios de cima abaixo, caso queira entender com mais detalhes o que foi realizado,  <a href="https://github.com/brenosalata/Medidor-de-Temperatura-/blob/main/MedidorTemperaturaMQTT.ino"> clique aqui.</a>

# Protocolo MQTT - MQTT Box & MQTT Dash

No projeto desenvolvido utilizamos o MQTT Box e o MQTT Dash ambos para monitorar e controlar as publicações e subscrições dos tópicos, em ambos também fizemos a conexão com o broker público "broker.mqtt-dashboard.com".

O MQTT Box é uma instenção do browser que viabiliza a conexão com diversos brokers Mqtt de forma simultânea, caso ainda não tenha essa instenção instalada, <a href="https://chrome.google.com/webstore/detail/mqttbox/kaajoficamnjijhkeomgfljpicifbkaf"> clique aqui.</a>

Utilizamos o MQTT Box para testar se as publicações e subscrições, fizemos a conexão identificando o broker (mesmo que utilizamos no código) e o nosso protocolo que é mqtt/tcp. Já o MQTT Dash foi nosso principal meio de interação para fazer com que o protótipo funcione do jeito esperado, pois ele além de permitir controlar essas publicações e subscrições ele permite uma automatização da ferramenta, foi nele que inserimos um botão para ativar e desativar a lâmpada e um campo de texto que avisa esse status da lâmpada, além de mostrar também a temperatura e a umidade, tudo isso em tempo real.

Tudo isso foi feito atráves de um celular, permitindo uma maior usabilidade para o usuário podendo controlar tudo na palma da sua mão apenas utilizando wi-fi e mqtt. 


# Links Utilizados no Projeto

* <a href="https://github.com/brenosalata/Medidor-de-Temperatura-/blob/main/Diagrama%20do%20Circuito%20Eletroeletrônico.jpeg"> Diagrama do Circuito Eletroeltrônico.</a>
* <a href="https://github.com/brenosalata/Medidor-de-Temperatura-/blob/main/Fluxograma.jpeg"> Fluxograma do Projeto.</a>
* <a href="https://github.com/brenosalata/Medidor-de-Temperatura-/blob/main/Ilustração%20da%20Montagem.jpeg"> Ilustração da Montagem do Projeto.</a>
* <a href="https://github.com/brenosalata/Medidor-de-Temperatura-/blob/main/MedidorTemperaturaMQTT.ino"> Código utilizado.</a>
