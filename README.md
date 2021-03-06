<img src="https://github.com/damiancipolat/Planta_IOT_Arduino/blob/main/doc/uai.png?raw=true" width="250px" align="right" />

# :herb: :shamrock:	 Planta IOT Arduino :ear_of_rice: :seedling: 
Repositorio creado para la materia, paradigmas de robotica de UAI sede centro 2020.

### Propuesta:
El objetivo del proyecto que presentamos es crear un dispositivo electronico que atravez del uso de sensores pueda indicarnos el estado de la calidad de la tierra de una maceta
y comunicarlo atravez de luces y un display enviando estos dos valores a un dashboard de **Adafruit.io**.

Este dispositivo nos ayuda a estar al tanto de las necesidads de la planta, nos informa las siguientes situaciones:
- Exceso de temperatura, **temperatura > 20°c**.
- Exceso de agua.
- Regar la planta.

<img src="https://github.com/damiancipolat/Planta_IOT_Arduino/blob/main/doc/muestra.jpeg?raw=true" width="500px" align="center" />

<img src="https://github.com/damiancipolat/Planta_IOT_Arduino/blob/main/doc/cover.jpeg?raw=true" width="500px" align="center" />

### Materiales utilizados:
- NODEMCU.
- Sensor de humedad de tierra.
- Sensor digital de temperatura Ds18b20.
- Display 0.96 OLED 128x64.
- Mini protoboard.
- Led rojo
- Cables.
- 6 seperadores de plaqueta.

### Librerias:
- Adafruit_GFX
- Adafruit_SSD1306
- OneWire
- DallasTemperature

### DASHBOARD
https://io.adafruit.com/damcipolat/dashboards/tp-final

<img src="https://github.com/damiancipolat/Planta_IOT_Arduino/blob/main/doc/dashboard.png?raw=true" width="500px" align="center" />

### Proceso de armado:
Lista de fotos, haga click en el link.

- [En armado 1](https://github.com/damiancipolat/Planta_IOT_Arduino/blob/main/doc/armado_1.jpg?raw=true)
- [En armado 2](https://github.com/damiancipolat/Planta_IOT_Arduino/blob/main/doc/armado_2.jpg?raw=true)
- [En armado 3](https://github.com/damiancipolat/Planta_IOT_Arduino/blob/main/doc/armado_3.jpg?raw=true)
- [En armado 4](https://github.com/damiancipolat/Planta_IOT_Arduino/blob/main/doc/armado_4.jpg?raw=true)
- [En armado 5](https://github.com/damiancipolat/Planta_IOT_Arduino/blob/main/doc/armado_5.jpg?raw=true)

En el siguiente link se puede descargar la presentación del proyecto:
https://github.com/damiancipolat/Planta_IOT_Arduino/blob/main/doc/Planta%20IOT.pptx

### Maquina de estados:
En el siguiente diagrama se detalla la maquina de estados creada para este proyecto..

<img src="https://github.com/damiancipolat/Planta_IOT_Arduino/blob/main/doc/diagram.png?raw=true" width="1300px" align="center" />

### Arquitectura:
Esta es la arquitectura creada para este proyecto, es una configuraión standard para proyectos IOT con arduino, en este caso creamos 2 feeds que son como queues MQ para envio de datos.

<img src="https://github.com/damiancipolat/Planta_IOT_Arduino/blob/main/doc/arquitectura.png?raw=true" width="1500px" align="center" />
