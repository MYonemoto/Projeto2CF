#include <SPI.h>
#include <Ethernet.h>
#include <Ultrasonic.h>

//inet 172.16.1.74  netmask 255.255.255.192  broadcast 172.16.1.127
//a4:5d:36:2a:58:81

byte mac[] = { 
  0xA4, 0x5D, 0x36, 0x2A, 0x58, 0x81 };
IPAddress ip(172, 16, 1, 74);
IPAddress gateway(172, 16, 1, 127);
IPAddress subnet(255, 255, 255, 192);

// Enter a MAC address for your controller below.
// Newer Ethernet shields have a MAC address printed on a sticker on the shield
char serverName[] = "YOUR_APP.com";    // name address of your domain

// Set the static IP address to use if the DHCP fails to assign
int serverPort = 80;
EthernetClient client;
char pageAdd[64];

char sensor[]="erro\0";
char ativou = 'f';

#define pino_trigger 4
#define pino_echo 5
Ultrasonic ultrasonic(pino_trigger, pino_echo);
#define pinomovimento 7
int pinolaser = 5;
int pinolaser2 = 4;
int pinoluminosidade1 = 0;
int pinoluminosidade2 = 1;

void setup() {
  Serial.begin(9600);

  pinMode(pinomovimento, INPUT);

  // Start ethernet
  Serial.println(F("Starting ethernet..."));
  if (Ethernet.begin(mac) == 0) {
    Serial.println("Failed to configure Ethernet using DHCP");
    // no point in carrying on, so do nothing forevermore:
    // try to congifure using IP address instead of DHCP:
    Ethernet.begin(mac, ip);
  }

  Serial.println(Ethernet.localIP());

  delay(2000);
  Serial.println(F("Ready"));
}

void loop()
{  
  //sensor ultrassonico
  float cmMsec, inMsec;
  long microsec = ultrasonic.timing();
  cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);
  //Serial.print("Distancia em cm: ");
  //Serial.print(cmMsec);
  if (cmMsec < 30.0)
  {
    Serial.println("sensor ultrassonico acionado");
    strcpy(sensor, "ultra1\0");
    ativou = 't';
  }

  //sensor movimento
  int valormovimento = digitalRead(pinomovimento);
  if (valormovimento == HIGH)
  {
    Serial.println("sensor de movimento acionado");
    strcpy(sensor, "mov1\0");
    ativou = 't';
  }

  //sensor luminosidade1
  int valorluminosidade1 = analogRead(pinoluminosidade1);
  //Serial.print("luminosidade: ");
  //Serial.println(valorluminosidade1);
  if(valorluminosidade1 < 700){
    Serial.println("sensor laser acionado");
    strcpy(sensor, "laser1\0");
    ativou = 't';
  }

  //salvar no banco
  if(ativou == 't'){
    sprintf(pageAdd,"/firebaseTest.php?arduino_data=%s",sensor);
    if(!getPage(serverName,serverPort,pageAdd)) Serial.print(F("Fail "));
    else Serial.print(F("Pass "));

    strcpy(sensor, "erro\0");
    ativou = 'f'; 
  }
  
  delay(1000);
}

byte getPage(char *ipBuf,int thisPort, char *page)
{
  int inChar;
  char outBuf[128];

  Serial.print(F("connecting..."));

  if(client.connect(ipBuf,thisPort))
  {
    Serial.println(F("connected"));

    sprintf(outBuf,"GET %s HTTP/1.1",page);
    client.println(outBuf);
    sprintf(outBuf,"Host: %s",serverName);
    client.println(outBuf);
    client.println(F("Connection: close\r\n"));
  } 
  else
  {
    Serial.println(F("failed"));
    return 0;
  }

  // connectLoop controls the hardware fail timeout
  int connectLoop = 0;

  while(client.connected())
  {
    while(client.available())
    {
      inChar = client.read();
      Serial.write(inChar);
      // set connectLoop to zero if a packet arrives
      connectLoop = 0;
    }

    connectLoop++;

    // if more than 10000 milliseconds since the last packet
    if(connectLoop > 10000)
    {
      // then close the connection from this end.
      Serial.println();
      Serial.println(F("Timeout"));
      client.stop();
    }
    // this is a delay for the connectLoop timing
    delay(1);
  }

  Serial.println();

  Serial.println(F("disconnecting."));
  // close client end
  client.stop();

  return 1;
}
