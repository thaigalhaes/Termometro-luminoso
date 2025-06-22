//---------------- Inclui as bibliotecas necessárias ----------------

#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

//---------------- Define tipo do sensor e pino de dados ----------------

#define DHTTYPE DHT11
int pinoDHT = 2;

//---------------- Define os pinos dos LEDs ----------------

int pinoLedVerde1 = 6;
int pinoLedVerde2 = 7;
int pinoLedAmarelo1 = 8;
int pinoLedAmarelo2 = 9;
int pinoLedVermelho1 = 10;
int pinoLedVermelho2 = 11;

//---------------- Instancia o sensor DHT ----------------

DHT_Unified dht(pinoDHT, DHTTYPE);

//---------------- Função para apagar todos os LEDs ----------------

void apagaTodosLEDs() {
  digitalWrite(pinoLedVerde1, LOW);
  digitalWrite(pinoLedVerde2, LOW);
  digitalWrite(pinoLedAmarelo1, LOW);
  digitalWrite(pinoLedAmarelo2, LOW);
  digitalWrite(pinoLedVermelho1, LOW);
  digitalWrite(pinoLedVermelho2, LOW);
}

//---------------- Função para acender os LEDs em etapas ----------------

void acendeLEDsPorEstagio(bool v1, bool v2, bool a1, bool a2, bool vm1, bool vm2) {
  digitalWrite(pinoLedVerde1, v1);
  delay(300);
  digitalWrite(pinoLedVerde2, v2);
  delay(300);
  digitalWrite(pinoLedAmarelo1, a1);
  delay(300);
  digitalWrite(pinoLedAmarelo2, a2);
  delay(300);
  digitalWrite(pinoLedVermelho1, vm1);
  delay(300);
  digitalWrite(pinoLedVermelho2, vm2);
}

//---------------- Setup do sistema ----------------

void setup() {
  Serial.begin(9600);
  dht.begin();

  pinMode(pinoLedVerde1, OUTPUT);
  pinMode(pinoLedVerde2, OUTPUT);
  pinMode(pinoLedAmarelo1, OUTPUT);
  pinMode(pinoLedAmarelo2, OUTPUT);
  pinMode(pinoLedVermelho1, OUTPUT);
  pinMode(pinoLedVermelho2, OUTPUT);

  apagaTodosLEDs();
}

//---------------- Loop principal ----------------

void loop() {
  delay(1500);

  sensors_event_t event;
  dht.temperature().getEvent(&event);

  if (isnan(event.temperature)) {
    Serial.println(F("Erro lendo a temperatura"));
    return;
  }

  float temp = event.temperature;

  Serial.print("Temperatura: ");
  Serial.print(temp);
  Serial.println(" °C");

  //---------------- Faixas de temperatura ajustadas ----------------

  if (temp <= 15) {
    apagaTodosLEDs();  // Muito frio: tudo desligado

  } else if (temp <= 20) {
    acendeLEDsPorEstagio(HIGH, LOW, LOW, LOW, LOW, LOW);  // Verde 1

  } else if (temp <= 24) {
    acendeLEDsPorEstagio(HIGH, HIGH, LOW, LOW, LOW, LOW); // Verde 1 e 2

  } else if (temp <= 27) {
    acendeLEDsPorEstagio(HIGH, HIGH, HIGH, LOW, LOW, LOW); // + Amarelo 1

  } else if (temp <= 30) {
    acendeLEDsPorEstagio(HIGH, HIGH, HIGH, HIGH, LOW, LOW); // + Amarelo 2

  } else if (temp <= 33) {
    acendeLEDsPorEstagio(HIGH, HIGH, HIGH, HIGH, HIGH, LOW); // + Vermelho 1

  } else {
    acendeLEDsPorEstagio(HIGH, HIGH, HIGH, HIGH, HIGH, HIGH); // Muito quente: tudo aceso
  }
}
