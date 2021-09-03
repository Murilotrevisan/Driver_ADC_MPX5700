# Driver ADC MPX5700
Repositório destinado ao driver do sensor de pressão ADC MPX5700 para uso no stm32
## Exemplo de uso
Configuração do sensor:
~~~
MPX5700_t mpx = {.adc = &hadc1};
MPX5700_init(mpx);
~~~
Leitura da pressão:
~~~
float pressao = MPX5700_get_pressure(mpx);
printf("valor de pressão = %f\r\n", pressao)
~~~
## Introdução
Este driver foi realizado como parte do sensoriamento das sondas estratosféricas e CubeSats do grupo Zenith EESC, a fim de realizar o treinamento em drivers de sensores ADC, este driver consiste em receber o valor do conversor ADC da STM32, utilizada nos projetos, as funções do ADC foram utilizadas a partir da biblioteca bsp.h, que pode ser encontrada no [repositório de Drivers do Zenith](https://github.com/zenitheesc/Drivers), no qual as funções são baseadas nas funções nativas da STM32 que são a HAL.
## Utilização do Driver
O driver consiste em fazer a leitura do ADC da placa STM32, e convertê-lo para o valor de pressão, para isto, inicialmente é feita a leitura do seu valor em 12 bits do ADC, gerando um valor entre 0 e 4095, porém, por características de hardware, este sensor opera em 5 V, e a STM32 em 3.3 V, sendo assim, foi utilizado um divisor de tensão em hardware, que leva a uma entrada do microcontrolador em 3.3 V quando o sensor possui em sua saída 5 V, desta forma, após converter o valor do ADC em tensão na entrada do microcontrolador, foi obtida a conversão para o valor de tensão de saída do sensor, analisando o [datasheet do MPX5700](https://www.nxp.com/docs/en/data-sheet/MPX5700.pdf), podemos obter a pressão lida pelo sensor através da tensão de saída do sensor via expressão `V_out = (V_Sensor / V_Source) * V_in ` onde , desta forma, a função `MPX5700_get_pressure` retorna o valor da pressão obtida pelo sensor.
## Notas
* ADC utilizado em modo contínuo, necessário para bsp.
* Valor de tensão máxima de saída do sensor e valor de tensão do ADC configuradas no driver.
* Por default, `V_Sensor = 5` e `V_Source = 3.3`, valores de alimentação do sensor MPX5700 e da STM32.
* Necessária a inclusão da biblioteca bsp.h para uso do driver.
* Driver feito utilizando a CubeIDE, visando facilitar a geração de códigos para a STM32.