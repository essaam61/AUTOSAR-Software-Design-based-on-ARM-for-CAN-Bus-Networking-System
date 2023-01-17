# AUTOSAR-Software-Design-based-on-ARM-for-CAN-Bus-Networking-System
Implemented a CAN bus system that allows centralized control over ECUs that are connected to the network so that controlling ECUs becomes easy using Arm Cortex M4 Tiva C board as microcontroller. The first ECU functions as main ECU to control the output state of other ECUs by sending a command on the CAN network based on the on-board switches’ states. Other ECUs receive the commands sent on the bus and execute them using output LEDs. All ECUs are restricted with specific timing constraints during their functionality. 

More over, this was applied by the AUTOSAR standard to standardize the software architecture of ECUs, improve complexity management of integrated E/E architectures, facilitate portability, composability, integration of SW components. The AUTOSAR Port & Dio drivers requirements were also applied in this project.


![connec](https://user-images.githubusercontent.com/109050863/197553813-882c1d68-0067-4748-8433-ef5dbeb1214a.PNG)


You can also find catalogue for a SDD document to describe the software architecture, its requirements using some UML tools and classified it for each ECU separately.
