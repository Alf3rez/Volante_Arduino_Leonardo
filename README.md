# Volante_Arduino_Leonardo

Proyecto para reparar un viejo volante mediante el uso de un Arduino Leonardo dado que la placa original está defectuosa.

Para realizarlo se va a emplear la librería creada por [LeonelAguilera](https://github.com/LeonelAguilera) adjunta también en el repositorio para poder agrupar 16 botones de una vez y reducir el número de pines empleados simulando una botonera en matriz de 16 botones.

Por otro lado se basa en el mismo código que el proyecto de [Freno de mano analógico](https://github.com/Alf3rez/Freno_de_mano_Arduino_Leonardo_con_Botonera) solamente adaptado al hardaware ya disponible en este volante, de forma que se generarán 20 botones para adecuarnos a los ya existentes y 3 ejes para definir el acelerador, el freno y la dirección del mismo, las cuales utiliza una serie de potenciómetros.

Se les otorgará una pequeña tolerancia en los extremos a todos los ejes para evitar los errores en los extremos.

Por otro lado será necesario a nivel físico diseñar una nueva placa soporte en la que acoplar los nuevos botones y el propio Arduino Leonardo, así como construir el puero micro-USB B que acoplar al conector USB ya existente para su correcto funcionamiento.
