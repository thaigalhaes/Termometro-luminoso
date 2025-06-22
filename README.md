# Termômetro Luminoso com Sensor DHT11 e LEDs

Este projeto utiliza o sensor de temperatura e umidade **DHT11** para medir a temperatura ambiente e exibir o resultado através de uma sequência de LEDs coloridos (verde, amarelo e vermelho). Conforme a temperatura aumenta, mais LEDs se acendem, indicando visualmente o nível de calor.

---

## Funcionalidades

- Leitura da temperatura ambiente usando o sensor DHT11.
- Indicação visual da temperatura em diferentes faixas usando LEDs.
- LEDs acendem em etapas progressivas, do verde ao vermelho.
- Feedback serial com valores da temperatura para monitoramento.

---

## Componentes Utilizados

| Quantidade | Componente                  | Descrição                                 |
|------------|-----------------------------|------------------------------------------ |
| 1          | Sensor DHT11                | Sensor de temperatura e umidade           |
| 2          | LED Verde                   | Indicador visual de temperatura baixa     |
| 2          | LED Amarelo                 | Indicador visual de temperatura média     |
| 2          | LED Vermelho                | Indicador visual de temperatura alta      |
| 6          | Resistor 220 Ω              | Limita corrente para os LEDs              |
| 1          | Resistor 10 kΩ              | Pull-up para o sensor DHT11               |
| 1          | Protoboard 400 pontos       | Placa para montagem sem solda             |
| 12         | Jumpers Macho-macho         | Cabos para conexões elétricas             |
| 1          | Cabo USB                    | Alimentação e programação do Arduino      |
| 1          | Placa Arduino Uno           | Microcontrolador para controle do sistema |

---

## Conexões

- **DHT11** conectado ao pino digital 2 do Arduino.
- LEDs conectados aos pinos digitais 6 e 7 (Verde), 8 e 9 (Amarelo), 10 e 11 (Vermelho).
- Cada LED deve ser conectado em série com resistor de 220 Ω para proteção.
- Resistor de 10 kΩ usado como pull-up para o sensor DHT11 (fio de dados).

---

## Código Principal

O código lê a temperatura e acende os LEDs conforme a faixa:

- ≤ 15 °C: todos LEDs apagados (muito frio)
- 16 a 20 °C: acende 1 LED verde
- 21 a 24 °C: acende 2 LEDs verdes
- 25 a 27 °C: acende 2 verdes + 1 amarelo
- 28 a 30 °C: acende 2 verdes + 2 amarelos
- 31 a 33 °C: acende 2 verdes + 2 amarelos + 1 vermelho
- > 33 °C: todos LEDs acesos (muito quente)

---
## Resultado Visual

Veja as imagens que mostram os diferentes estados dos LEDs conforme a temperatura:

<table>
  <tr>
    <td align="center"><strong>Todos LEDs Desligados</strong></td>
    <td align="center"><strong>Todos LEDs Verdes</strong></td>
    <td align="center"><strong>1 LED Amarelo</strong></td>
    <td align="center"><strong>1 LED Vermelho</strong></td>
  </tr>
  <tr>
    <td><img src="https://github.com/thaigalhaes/Termometro-luminoso/blob/main/LEDs%20Desligados.jpg" width="150"/></td>
    <td><img src="https://github.com/thaigalhaes/Termometro-luminoso/blob/main/LEDs%20Verdes.jpg" width="150"/></td>
    <td><img src="https://github.com/thaigalhaes/Termometro-luminoso/blob/main/LED%20Amarelo.jpg" width="150"/></td>
    <td><img src="https://github.com/thaigalhaes/Termometro-luminoso/blob/main/LED%20Vermelho.jpg" width="150"/></td>
  </tr>
</table>

