# Blockchain_Aed
Proyecto de Algoritmos y Estructura de Datos  - Blockchain
## Integrantes:
- Sebastián Loza Mendoza
- Diana Ñañez Andrés
- Jaime Ramos Talla
- Carlos Flores Godos

## Introducción:
Según el IBM el "Blockchain es un libro mayor compartido e inalterable que facilita el proceso de registro de transacciones y de seguimiento de activos en una red de negocios"(¿Qué es la tecnología Blockchain? - IBM Blockchain | IBM, s. f.). 
En otras palabras, este permite el intercambio de información de forma transparente, inmutable y sin la necesidad de intermediarios. Su impacto potencial abarca una amplia gama de industrias y sectores, desde las finanzas y la economía, hasta la logística, la atención médica y más.

El objetivo de este proyecto es explorar y desarrollar un blockchain funcional, brindando una comprensión más profunda de esta tecnología y su aplicación práctica. A través de la creación de un blockchain propio, podremos analizar y experimentar con los diferentes elementos que lo componen, como la estructura de bloques, la criptografía, la verificación de transacciones y la descentralización.

## Caso de Estudio:
**Blockchain en las Transferencias Bancarias**

Este, se trata de un registro digital seguro, que permite realizar las transferencias de manera eficaz, rápida y sin intermediarios, además utiliza la criptografía para que la integridad de los datos no se pierda, además esta tecnología nos brinda poder seguir el rastro de una transacción financiera, desde su origen hasta su destino final.

![Fuente: IDB INVEST](imagenes/tf.png)

## Importancia del Blockchain:

El blockchain es importante en las transferencias bancarias debido a:

- Eficiencia y rapidez: Elimina intermediarios y permite transacciones directas y rápidas, reduciendo los tiempos de liquidación y retrasos.

- Reducción de costos: Al eliminar intermediarios y automatizar procesos, se reducen las tarifas de procesamiento y comisiones asociadas.

- Seguridad y autenticidad: Utiliza criptografía avanzada para garantizar la seguridad de las transacciones y prevenir el fraude.

- Transparencia y trazabilidad: Proporciona un registro transparente y público de todas las transacciones, permitiendo mayor trazabilidad de los fondos y previniendo actividades ilícitas.

- Transferencias internacionales simplificadas: Superan desafíos como tiempos de liquidación largos y conversiones de moneda costosas, facilitando pagos internacionales directos y rápidos.

- Inclusión financiera: Permite transferencias rápidas y seguras sin la necesidad de una cuenta bancaria tradicional, beneficiando a regiones con acceso limitado a servicios financieros.


## Estructura de Datos en el Blockchain:
-Proof of work:



## Estructura de Datos Implementadas:
- Hash: Usamos una tabla hash para que cada que ingresemos un registro, 
- Heap: Implemtentamos la funcion del max-heap, funciona con cada registro que se va añadiendo, eso creará nodos, el cual cada uno de ellos tiene un monto(valor asociado al nodo), además dentro de ellos hay un forwad-list, donde se guardarán los emisores con el mismo monto, esto se hizo para evitar repeticiones, con la función hepify_up colocaremos al mayor monto en la primera posición , esta implementación fue con la finalidad de que nos permita acceder a los emisores con el mayor monto de las transacciones. 


## Notación Big O de los métodos del Blockchain:
-Métodos de insertar y buscar:
  
-Tabla comparativa de Blockchain con índices vs sin índices:

## Conclusion:

A lo largo de este proyecto, nos enfocaremos en desarrollar un blockchain básico, pero sólido, que demuestre los principios fundamentales de esta tecnología. También consideraremos cómo podríamos expandir y mejorar nuestro blockchain en el futuro, y cómo podría aplicarse en casos de uso específicos para que pueda ofrecer soluciones innovadoras a problemas existentes en diferentes áreas, al proporcionar una infraestructura confiable y transparente para el intercambio de datos y activos.

En resumen, a través de este proyecto seguiremos experimentado la potencia y las posibilidades del blockchain. Hemos comprendido su importancia en la transformación digital, que el blockchain tiene el potencial de cambiar la forma en que interactuamos y realizamos transacciones en el futuro, lo cuál seguiremos implementando las funcionalidades necesarias para que nuestro blockchain funcione y sea seguro.

## Referencias bibliográficas:
¿Qué es la tecnología Blockchain? - IBM Blockchain | IBM. (s. f.). https://www.ibm.com/es-es/topics/blockchain

IDB Invest (s. f.). https://www.google.com/search?q=como+funciona+un+blockchain&rlz=1C5CHFA_enPE823PE823&sxsrf=APwXEdeLzvfT8Hs1dNmYUJNd8NKizuBJKw:1685506631809&source=lnms&tbm=isch&sa=X&ved=2ahUKEwj5wbjA2Z7_AhUkqZUCHejdCuUQ_AUoAnoECAEQBA&biw=1422&bih=765&dpr=1.8#imgrc=i9wLTn2vFb7pgM




## Lista de actividades concluidas por cada integrante del grupo:

## Librerías:

-Usaremos wxWidgets
Para desccargarlo ingresar al siguiente link:
https://www.wxwidgets.org/downloads/

-Para Hash
Para descargar el respositorio:
https://github.com/stbrumme/hash-library.git


