<img src="https://github.com/damiancipolat/Planta_IOT_Arduino/blob/main/doc/uai.png?raw=true" width="250px" align="right" />

# :herb: :shamrock:	 Planta IOT Arduino :ear_of_rice: :seedling: 
Repositorio creado para la materia, paradigmas de robotica de UAI sede centro 2020.

El objetivo del proyecto que presentamos es crear un dispositivo electronico que atravez del uso de sensores pueda indicarnos el estado de la calidad de la tierra de una maceta
y comunicarlo atravez de luces y un display. Este dispositivo nos ayuda a estar al tanto de las necesidads de la planta, nos informa las siguientes situaciones:

- Exceso de temperatura, **temperatura > 20°c**.
- Exceso de agua.
- Regar la planta.

### Materiales utilizados:
- Arduino UNO.
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

**TODO**: cambiar arduino uno por NODEMCU para poder conectar a internet.

### Proceso de armado:
Lista de fotos, haga click en el link.

#### Estado final:
- [Estado final](https://github.com/damiancipolat/Planta_IOT_Arduino/blob/main/doc/final.jpeg?raw=true)

#### En proceso de armado:
- [En armado 1](https://github.com/damiancipolat/Planta_IOT_Arduino/blob/main/doc/armado_1.jpg?raw=true)
- [En armado 2](https://github.com/damiancipolat/Planta_IOT_Arduino/blob/main/doc/armado_2.jpg?raw=true)
- [En armado 3](https://github.com/damiancipolat/Planta_IOT_Arduino/blob/main/doc/armado_3.jpg?raw=true)
- [En armado 4](https://github.com/damiancipolat/Planta_IOT_Arduino/blob/main/doc/armado_4.jpg?raw=true)
- [En armado 5](https://github.com/damiancipolat/Planta_IOT_Arduino/blob/main/doc/armado_5.jpg?raw=true)

### Maquina de estados:
En el siguiente diagrama se detalla la maquina de estados creada para este proyecto.

<img src="https://github.com/damiancipolat/Planta_IOT_Arduino/blob/main/doc/diagram.png?raw=true" width="750px" align="center" />
