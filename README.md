# Teremim Standart Library (TSL)
A _Teremim Standart Library_ oferece classes de sensores e atuadores prontos para uma maior agilidade na criação de robôs.
Esta biblioteca inclui as classes para:
- Acelerômetro
- Sensores de Cor (GY-31)
- Sensor Infravermelho
- LED
- Motores CC
- Sensores Ultrassônicos (HC-SR04)
## Como instalar
- Baixe o .zip
- Inclua a biblioteca na Arudino IDE

## Classes
#### Acelerometer
|Método|Argumentos|Tipo de retorno|Descrição|
| :------------: | :------------: | :------------: | :------------ |
|Acelerometer()   |x, y, z|*construtor\**|cria o objeto com os pinos dos eixos|
|start()          |--|void |inicializa o sensor, configura os pinos como entrada|
|getx()           |--|byte |lê o valor analógico do eixo X|
|gety()           |--|byte |lê o valor analógico do eixo Y|
|getz()           |--|byte |lê o valor analógico do eixo Z|
#### Color Sensor
|Método|Argumentos|Tipo de retorno|Descrição|
| :------------: | :------------: | :------------: | :------------ |
|ColorSensor()   |pinos, calibração|*construtor\**|inicializa pinos e valores de calibração|
|start()   |--|*construtor\**|cria o objeto com os pinos e valores de calibração|
|isWhite()        |--|bool |retorna ```true``` se a cor for branco|
|isBlack()        |--|bool |retorna ```true``` se a cor for preto|
|isRed()          |--|bool |retorna ```true``` se a cor for vermelho|
|isBlue()         |--|bool |retorna ```true``` se a cor for azul|
|isGreen()        |--|bool |retorna ```true``` se a cor for verde|
|readColors()     |--|void |lê os valores dos sensores e os guarda na memória|
|getRed()         |--|u_int|retorna a quantidade de vermelho, lendo os valores do sensores|
|getGreen()       |--|u_int|retorna a quantidade de verde, lendo os valores do sensores|
|getBlue()        |--|u_int|retorna a quantidade de azul, lendo os valores do sensores|
|retRed()         |--|u_int|retorna a quantidade de vermelho, usando os valores salvos na memória|
|retGreen()       |--|u_int|retorna a quantidade de verde, usando os valores salvos na memória|
|retBlue()        |--|u_int|retorna a quantidade de azul, usando os valores salvos na memória|
_confira os argumentos do contrutor na classe, a calibração é empírica._

#### InfraredSensor
|Método|Argumentos|Tipo de retorno|Descrição|
| :------------: | :------------: | :------------: | :------------ |
|InfraredSensor() |pin|*construtor\**|define qual pino o sensor está ligado|
|start()          |--|void |inicializa o sensor, configura o pino como entrada|
|isBlack()        |--|bool |retorna ```true``` se ler preto|

#### Led
|Método|Argumentos|Tipo de retorno|Descrição|
| :------------: | :------------: | :------------: | :------------ |
|Led()            |pin|*construtor\**|define em qual pino o LED está ligado|
|start()          |--|void |inicializa o LED, configura o pino como saída|
|getState()       |--|bool |retorna se o LED está ligado ou desligado (apenas via _software_)|
|setState()       |state|void |liga ou desliga o LED|
|setOn()          |state|void |liga o LED|
|isOn()           |--|bool |verifica se o LED está aceso|

#### Motor
|Método|Argumentos|Tipo de retorno|Descrição|
| :------------: | :------------: | :------------: | :------------ |
|Motor()          |pinos, dir, vel|*construtor\**|configura pinos, direção e velocidade inicial|
|start()          |--|void |inicializa os pinos do motor|
|setLeftPin()     |pin|void |altera o pino da esquerda|
|setRightPin()    |pin|void |altera o pino da direita|
|setEnablePin()   |pin|void |altera o pino de ativação (enable)|
|getLeftPin()     |--|byte |retorna o número do pino esquerdo|
|getRightPin()    |--|byte |retorna o número do pino direito|
|getEnablePin()   |--|byte |retorna o número do pino enable|
|setDirection()   |direction|void |define o sentido do giro|
|setVelocity()    |velocity|void |define a velocidade (0-255)|
|getDirection()   |--|bool |retorna a direção atual|
|getVelocity()    |--|byte |retorna a velocidade atual|
|toggleDirection()|--|void |inverte o sentido em que o motor está girando|
|run()            |--|void |liga o motor com as configurações atuais|
|stop()           |--|void |para o motor idependentemente da velocidade|

#### UltrasonicSensor
|Método|Argumentos|Tipo de retorno|Descrição|
| :------------: | :------------: | :------------: | :------------ |
|UltrasonicSensor()|trigger, echo|*construtor\**|define os pinos trigger e echo|
|start()          |--|void |inicializa os pinos do sensor|
|getDistance()    |--|double|calcula e retorna a distância em cm|
|getDistanceInMeters()|--|double|calcula e retorna a distância em metros|
