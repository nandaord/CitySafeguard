# Projetos 1 - Grupo 4 - Citysafeguard

CESAR School - CC e Design 2023.2 - Projetos 1 - Grupo 4

# Sistema de Monitoramento de Umidade com Comunicação Bluetooth

Este código Arduino foi desenvolvido para monitorar os níveis de umidade em edifícios-caixão usando um sensor de umidade do solo e transmissão dos resultados via Bluetooth. O sistema utiliza um LED RGB para representar visualmente os níveis de umidade e um módulo Bluetooth para transmitir os dados sem fio.

## Componentes Utilizados

    Placa Arduino
    Sensor de umidade do solo (conectado ao pino analógico A0)
    LED RGB
    Módulo Bluetooth (conectado aos pinos digitais 2 e 4)
  
## Bibliotecas

    SoftwareSerial: Esta biblioteca permite a comunicação com o módulo Bluetooth usando comunicação serial definida por software.

## Conexões

    Conecte o sensor de umidade do solo ao pino analógico A0 no Arduino.
    Conecte o módulo Bluetooth aos pinos digitais 2 (RX) e 4 (TX) no Arduino.
    Certifique-se de que o LED RGB está conectado adequadamente.

## Explicação do Código

### Inicialização de Variáveis

    cpp
    Copy code
    SoftwareSerial bluetooth(4, 2); // TX, RX Módulo Bluetooth
    const moisture(A0);
    
Define um objeto serial de software chamado "bluetooth" para a comunicação com o módulo Bluetooth e configura o sensor de umidade do solo no pino analógico A0.

### Função de Configuração

    cpp
    Copy code
    void setup()
    {
      Serial.begin(9600);
      bluetooth.begin(9600);
    }
    
Inicializa a comunicação serial com a placa Arduino e o módulo Bluetooth.

### Função de Loop

    cpp
    Copy code
    void loop()
    {
      int moisture = 0;
      moisture = analogRead(A0);
      
      delay(100);
      
Lê o nível de umidade do solo a partir do sensor e introduz um atraso para estabilidade.

    cpp
    Copy code
      // Define o LED RGB com base na leitura de umidade
      if (moisture < 200) {
        bluetooth.print("PERIGO Subito! ");
        bluetooth.println(moisture);
      } else if (moisture < 400) {
        bluetooth.print("PERIGO! ");
        bluetooth.println(moisture);
      } else if (moisture < 600) {
        bluetooth.print("Atenção! ");
        bluetooth.println(moisture);
      } else if (moisture < 800) {
        bluetooth.print("Pouco Úmido: ");
        bluetooth.println(moisture);
      } else {
        bluetooth.print("Seco: ");
        bluetooth.println(moisture);
      }
    }
    
## Instruções de uso
Coordenar um sensor de umidade do solo envolve monitorar, interpretar e, se necessário, agir com base nas leituras do sensor para garantir condições adequadas de umidade para as plantas. Aqui estão as instruções necessárias sobre como operar um sensor de umidade:

### 1. Instalação Física
Posicione o sensor de umidade no solo da sua planta, certificando-se de que as partes sensíveis estejam totalmente enterradas.
Evite posicionar o sensor perto de áreas que possam acumular água, pois isso pode afetar as leituras.

### 2. Conexão ao Arduino
Conecte o sensor de umidade ao pino analógico A0 do Arduino.
Conecte outros componentes, como módulo Bluetooth ou LED RGB, se estiver usando.

### 3. Carregando o Código
Utilize o código fornecido ou crie o seu próprio para ler as leituras do sensor e tomar ações com base nelas.
Certifique-se de ajustar os limiares de umidade no código de acordo com as necessidades das suas plantas.

### 4. Monitoramento Contínuo
Mantenha o Arduino alimentado para garantir a coleta contínua de dados.
Utilize o Monitor Serial no Arduino IDE para monitorar as leituras do sensor.

### 5. Interpretação das Leituras
Com base nas leituras do sensor, interprete os níveis de umidade no solo.
Personalize as condições de interpretação de acordo com as necessidades específicas das suas plantas.

### 6. Feedback Visual ou Remoto (Opcional)
Se estiver utilizando um LED RGB, observe a mudança de cor para uma representação visual dos níveis de umidade.
Se conectado a um módulo Bluetooth, monitore as leituras remotamente em um dispositivo pareado.

### 7. Tomada de Decisões
Estabeleça ações com base nas leituras. O monitoramento da umidade será contínuo para manter o arquivo dos dados e acompanhar possíveis evoluções do risco. Mesmo assim, as seguintes tomadas de decisões podem ser feitas: 
- Baixa umidade: Baixo risco. Manter alimentação do banco de dados de monitoramento de risco, sem mais ações. 
- Leve aumento da umidade: Médio risco. Envio de alerta a autoridades.
- Umidade Elevada: Envio de alerta a autoridades e alerta a moradores.

### 8. Ajustes e Calibração
Faça ajustes no código, se necessário, com base em observações contínuas.
Calibre o sensor conforme necessário para garantir leituras precisas.

### 9. Manutenção
Verifique regularmente o funcionamento do sensor e dos componentes relacionados.
Substitua a bateria, se aplicável, e resolva quaisquer problemas identificados.
Lembre-se de que a coordenação eficaz envolve entender as necessidades específicas das suas plantas, ajustar os parâmetros conforme necessário e estar atento às condições do solo ao longo do tempo.
### Equipe:
Ciências da Computação:<br>
1-Vinícius Diniz,<br>
2-Kauane Melo,<br>
3-Thais Aguiar,<br>
4-Igor Cubits,<br>
5-Maria Fernanda Ordonho,<br>
6-Lucas Sukar,<br>
7-Bernardo Heuer,<br>
8-Marcelo Henrique<br>
Design:<br>
9-Sophia Latache<br>
10-Maria Eduarda Ximenes<br>
11-Lucca Martins