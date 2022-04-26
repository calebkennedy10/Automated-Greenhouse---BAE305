# EE305_Project_Greenhouse
Master code for running greenhouse
## Summary
The purpose of this project is to utilize electronics and sensors to automate several greenhouse functions on a model scale as both a prototype for a full-size microcontroller-based automation system and as an educational model that can be used to demonstrate how an automated greenhouse works. Our team developed sensors for relative humidity, temperature, and light level in order to direct automated heating, cooling, and lighting systems, as well as an automated irrigation system running on a timer. The main goals of the project were to create code that used sensor data to activate several of the systems both for demonstration purposes and actual utilizing of the greenhouse; to assemble a suitable greenhouse setup from a clear tub; and to organize the system in a way that would provide accurate data on greenhouse conditions. Each component was tested separately and as a whole, and the automated greenhouse was able to function as outlined in the project backlog.
## Design Description
### Supplies Needed
- SparkFun Electronics RedBoard DEV-13975
- Clear tub
- Adafruit 997 (Plastic Water Solenoid Valve - 12V -1/2" Nominal)
- ElectricSolenoidValves.com RSC-A2-12VDC (1/4" 12V DC Push Connect Plastic Solenoid Valve)
- MXC 1/4" Automatic Drip Mist Irrigation Kit (Model: GGOB)
- SparkFun Generic Servo Motors (ROB-09065)
- Bonsai wire
- Jumper wires (male-male and male-female)
- Electrical tape
- 
### 3D-Printed Components
### Circuit
### Greenhouse Assembly
#### Cooling System
#### Heating System
#### Lights
#### Sensors
#### Irrigation
The irrigation system consists of a 1/4" 12V DC plastic solenoid valve, as well 15 feet of 1/4" diameter tubing, 18 adjustable mister nozzles, 20 flat tee fittings, and a 3/4"-1/4" faucet adapter from the MXC Automatic Drip Mist Irrigation Kit. It is split into three lines across the length of the ceiling of the greenhouse, which are attached via twelve loops of bonsai wire strung through pairs of holes drilled into the ceiling. Each line contains 6 mister nozzles, which are attached to flat tees with 1/2" lengths of tubing; tubing is also used to string the flat tees together in order to create an irrigation line. 2 other flat tees are used to connect the lines to each other and to the tubing that goes to the solenoid valve. All connection of tubing to tees should be done using a butane torch to soften the tubing for easier insertion. The solenoid valve can also be connected to the faucet adapter via a portion of tubing, and then wired to the power supply and relay using male-to-female jumper wires. The wires should be soldered to the tabs on the valve-- the left wire to power and the right to the relay.
### Code

## Testing Description
Early testing consisted of examining every component separately in order to ensure basic functionality, such as whether valves would open, or servo motors would turn when instructed to by the code. The components were then tested in combination, when they were wired up as they would be for the greenhouse. 
### Equipment
- Laptop
- USB connector (Arduino to laptop)
- Access to a faucet/water supply
### Procedure
## Design Decision Discussion
## Test Results Discussion
### System Limitations
## Testing Results
## Project Future
