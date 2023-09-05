## Air Control: Sistema de gestão de aparelhos de ar condicionado

Este projeto em linguagem C apresenta um protótipo de automação para ar condicionado que permite programar horários para ligar e desligar. Um vídeo ilustrativo pode ser visualizado abaixo, usando a ferramenta de simulação Workwi (https://wokwi.com/) para testes.

### Demonstração em Vídeo
![Simulacao_Air_Control](https://github.com/ltsilva23/Air_Control/assets/63319533/770478a7-7735-47c6-a31b-1e7b3b28cc6c)

### Configuração da Maquete para Simulação

Para realizar a simulação do protótipo através de uma maquete conectada ao notebook via USB, os seguintes materiais foram utilizados:

- **Arduino Uno:** Hardware central do projeto.
- **Cabo Serial para USB:** Para a conexão entre o Arduino e o notebook.
- **Protoboard:** Matriz de contato para suporte e montagem de protótipos.
- **Cabos de Conexão:** Para ligar os componentes à placa.
- **Dois LEDs:** Representando o estado ligado/desligado do ar condicionado.
- **Display LCD 16x2:** Mostra a data e horário do agendamento.
- **Dois Resistores:** Utilizados para controlar a corrente dos componentes.
- **RTC DS3231:** Relógio em tempo real com calendário completo para controle preciso do tempo.

### Como Executar

1. **Materiais Utilizados para Construir a Maquete:**
   - Conecte os componentes conforme o esquema na protoboard.
   - Certifique-se de conectar os LEDs, o display LCD e o RTC corretamente.
   - Use resistores para limitar a corrente nos LEDs e outros componentes.
   - Conecte o Arduino Uno ao notebook via cabo serial USB.

2. **Configuração do Ambiente:**
   - Tenha um notebook/desktop com acesso à internet.
   - Instale a Arduino IDE a partir de https://www.arduino.cc/en/software.
   - Importe as bibliotecas necessárias para o projeto.

3. **Executando a Simulação:**
   - Carregue o código-fonte fornecido no Arduino IDE.
   - Verifique e corrija, se necessário, as configurações do projeto.
   - Faça o upload do código para o Arduino Uno.
   - Observe a simulação em tempo real utilizando a ferramenta Workwi ou outro método.

### Contribuições

Contribuições e melhorias são bem-vindas! Fique à vontade para abrir um problema ou enviar um pull request.

### Licença

Este projeto é protegido pela seguinte licença:

Antes de utilizar, copiar, contribuir, mesclar ou publicar qualquer parte deste projeto, certifique-se de ler a licença completa disponível no arquivo [LICENSE](LICENSE) neste repositório. Ao continuar com qualquer ação relacionada a este projeto, você concorda em cumprir os termos e condições estabelecidos na licença.

Se você tiver alguma dúvida ou precisar de permissões adicionais que não estão abordadas na licença, entre em contato com o autor original do projeto.

