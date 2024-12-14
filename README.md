# **Citysafeguard: Sistema de Monitoramento de Umidade com Comunicação Bluetooth**

## 🌟**Introdução**
O Citysafeguard é um sistema projetado para monitorar os níveis de umidade em edifícios-caixão utilizando sensores de solo. Ele ajuda a identificar riscos de infiltração ou alagamento, alertando moradores e autoridades através de um módulo Bluetooth e um sistema visual com LED RGB.

---

## 🛠️**Componentes e Ferramentas**
- **Hardware:**
  - Placa Arduino
  - Sensor de umidade do solo (A0)
  - LED RGB
  - Módulo Bluetooth (pinos digitais 2 e 4)
- **Software:**
  - IDE Arduino
  - Biblioteca `SoftwareSerial` para comunicação Bluetooth  

---

## 🔌**Conexões e Configuração** 
| Componente        | Pino Arduino       |  
|--------------------|--------------------|  
| Sensor de Umidade | A0                 |  
| Módulo Bluetooth  | RX -> 4, TX -> 2   |  
| LED RGB           | Pinos digitais (configurar no código) |

**Nota:** Verifique a polaridade e siga as especificações dos fabricantes.

---

## ⚙️**Funcionamento do Sistema** 
O sistema monitora a umidade do solo em tempo real e realiza:  
- Transmissão das leituras via Bluetooth.  
- Indicação visual de níveis de umidade com um LED RGB:  
  - Vermelho: Umidade crítica (PERIGO).  
  - Amarelo: Alerta (Atenção).  
  - Verde: Nível seguro (Pouco Úmido).  

---

## 🖥️**Estrutura do Código** 

```cpp
#include <SoftwareSerial.h>

SoftwareSerial bluetooth(4, 2); // TX, RX para comunicação Bluetooth
const int moisturePin = A0;     // Pino do sensor de umidade

void setup() {
  Serial.begin(9600);
  bluetooth.begin(9600);
}

void loop() {
  int moisture = analogRead(moisturePin);  // Leitura do sensor

  if (moisture < 200) {
    bluetooth.print("PERIGO SÚBITO! ");
  } else if (moisture < 400) {
    bluetooth.print("PERIGO! ");
  } else if (moisture < 600) {
    bluetooth.print("ATENÇÃO! ");
  } else if (moisture < 800) {
    bluetooth.print("UMIDADE BAIXA: ");
  } else {
    bluetooth.print("SECO: ");
  }
  bluetooth.println(moisture);
  delay(100); // Estabiliza a leitura
}
```

---

## 📋**Instruções de Uso** 
### 1. 🛠️Instalação Física 
- Posicione o sensor de umidade no local desejado, certificando-se de que as partes sensíveis estejam totalmente enterradas.
- Evite áreas que possam acumular água em excesso.

### 2. 🔗Conexão ao Arduino 
- Conecte o sensor de umidade ao pino analógico A0.
- Conecte o módulo Bluetooth e o LED RGB conforme especificado na seção de conexões.

### 3. 🚀Carregando o Código 
- Carregue o código no Arduino utilizando o IDE Arduino.
- Ajuste os limiares de umidade no código, se necessário.

### 4. 📡Monitoramento Contínuo 
- Utilize o Monitor Serial ou um dispositivo Bluetooth para visualizar os dados.
- Observe o LED RGB para uma indicação visual dos níveis de umidade.

### 5. 🧰Manutenção 
- Verifique regularmente o funcionamento do sensor e dos componentes.
- Substitua baterias e calibres conforme necessário.

---

## 👥**Equipe** 
**Ciências da Computação:**  
- Bernardo Heuer, Igor Cubits, Kauane Melo, Lucas Sukar, Marcelo Henrique, Maria Fernanda Ordonho, Thais Aguiar e Vinícius Diniz  

**Design:**  
- Lucca Martins, Maria Eduarda Ximenes e Sophia Latache
