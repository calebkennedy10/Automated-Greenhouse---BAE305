# BAE305_Project_Greenhouse
## Summary
The purpose of this project is to utilize electronics and sensors to automate several greenhouse functions on a model scale as both a prototype for a full-size microcontroller-based automation system and as an educational model that can be used to demonstrate how an automated greenhouse works. Our team developed a sensor to detect light level and utilized an affordable off-the-shelf temperature and humidity sensor in order to direct automated heating, cooling, and lighting systems, as well as an automated irrigation system running on a timer. The main goals of the project were to create code that used sensor data to activate several of the systems both for demonstration purposes and actual utilizing of the greenhouse; to assemble a suitable greenhouse setup from a clear tub; and to organize the system in a way that would provide accurate data on greenhouse conditions. Each component was tested separately and as a whole, and the automated greenhouse was able to function as outlined in the project backlog.
## Design Description
### Supplies Needed
- SparkFun Electronics RedBoard DEV-13975
- Clear storage tub
- Adafruit 997 (Plastic Water Solenoid Valve - 12V -1/2" Nominal)
- ElectricSolenoidValves.com RSC-A2-12VDC (1/4" 12V DC Push Connect Plastic Solenoid Valve)
- MXC 1/4" Automatic Drip Mist Irrigation Kit (Model: GGOB)
- SparkFun Generic Servo Motors (ROB-09065)
- Bonsai wire
- Jumper wires (male-male and male-female)
- Electrical tape
- Plusivo Hook-up Wire Kit
- Photoresistor
- Ws2812 LED Matrix Panel
- DC 12V to 5V Converter
- 1/2" PVC pipe and various 1/2" fittings
- 10W 110V AC aquarium pump with 1/2" ID tubing output
- 1/2" ID tubing and barb fittings
- PVC cement and primer
- PLA filament
- 300W 12V power supply
- Solder
- Various crimp on electrical connectors (female disconnects, spade tongue, splices)
- 5 Gallon Bucket
- 2x Horizontal Float Switches
- 2x 12V PC fans
- Adafruit SHTC3 Temp and humidity sensor with wiring harness.
- 1/8W resistors (10K and 330)
- Fdit PTC Car Fan Air Heater for Small Room Space (12V 100W)
- TIP 31C Transistor 
- 12VDC, 30/40A Automotive Relay
- Bracket mount for relay

### 3D-Printed Components
All 3D printed componets are available via the "3D PRINTED PARTS" file in the repository.  They are available in their native SOLIDWORKS CAD formats.  Please refer to the assembly files in order to determine which parts are to be printed for each assembly and how the parts are assembled together.  3mm self tapping screws and 1/4"-20 bolts and nuts are the only pieces of hardware required to assemble each 3D printed assembly.  Parts can be printed out of several different materials and are designed to be printed on an FDM 3D printer.  Our team utilized Overture PLA Filament to print the parts; however, other common filaments types such as PETG, ABS, and ASA are acceptable if so desired.  All parts should be printed at a .2mm layer height with and infill density of 10%-15%.  It is advised to make spares of smaller parts such as the water emitters and servo attachments as these parts are easy to break during the assembly process.  Moving parts such as the vent flaps s will have to be sanded in order to allow for smooth rotation.  It is also recommended to drill out or sand holes where rotation will take place.  It is recommended to use a printer with a build plate area of at least 220mm x 220mm when printing large parts such as the vent flaps for the multivent.
### Circuit
While the circuit for this project is not overly complex, there is a lot of wiring involved.  Please refer to the schematic below when wiring up the system.  It is recommend that soldered connections with heat shrink coverings be utilized where possible in order to provide a water-tight seal around connections.  The power supply, voltage converter, microcontroller, breadboard, and relays should all be placed in a sealed container to protect them from the elements.  Our team utilized a 50W laser cutter to create a box to store all of these components.  If you have access to this type of tooling and wish to use our plans, the files for the box can be found in this repository.  Otherwise, any container or self-fabricated box will do as long as it provides adequate protection. 

![Circuit Diagram](/calebkennedy10/EE305_Project_Greenhouse/circuit(5).png)

### Greenhouse Assembly
#### Cooling System
(The plumbing instructions for this section are intentionally a little vague.  There are multiple ways to plumb this system, and our team believes that it is best for plumbing system to be custom fabricated for each application of this design.)

Two vent fan assemblies and one evaporative cooling system assembly are required to complete the cooling system.  As mentioned previously, please refer to the SOLIDWORKS assembly files in order ot determine all 3D printed parts of the required to complete these assemblies.  The vent fan assemblies will be mounted on one end of the greenhouse while the evaporative cooling assembly will be mounted on the other side.  Assemble all sub assemblies prior to installation using 3mm screws.  Use the mounting adapters for the all of the assemblies to mark the holes that will need to be drilled in the house to mount the components.  All mounting holes will use 1/4"-20 hardware to hold components in place

Use the 5 gallon bucket to make a water sump for the evaporative cooling system.  Mount the pump at the bottom of the bucket.  Then mount a horizontal float switch 1 to 2 inches above the pump and mount another float switch approximately 6 inches below the top of the bucket.  Mount the 1/2" solenoid valve to the side of the bucket or in a pemanent location close by.  An input line that accepts a pressurized water source, such as a garden hose, will need to fabricated based on application needs.  An output line that runs from the valve to the inside of the sump will also need to be made.

For the vent fan assemblies, try to mount them as close to the center as possible to allow room for the servo mounts on the inside of the house.  One mounting adapter, the fan mount, fan, and fan retainer go on the exterior of the house while the other adapter, vent assembly, and servo mount go on the interior.  Once the proper orientation of the fan is decided on, drill a 5/16" hole in the fan mount to allow for the wires to pass through the wall of the mount.  This mounting procedure is to be utilized for both vent fan assemblies.

![](https://github.com/calebkennedy10/EE305_Project_Greenhouse/blob/main/IMAGES/FAN%20ASSEMBLY%201.JPG)
(Fan Vent Assembly-Exterior View)
![](https://github.com/calebkennedy10/EE305_Project_Greenhouse/blob/main/IMAGES/FAN%202.JPG)
(Fan Vent Assembly-Interior View)

For the evaporative cooling system assembly, mount it as far to one side of the house as possible to allow for enough room for the servo mount on the inside.  The evaporative cooling wall assembly and one set of mounting adapters are mounted to the exterior of the greenhouse while the multi-vent assembly, servo mount, and last set of mounting adapters are mounted on the inside of the greenhouse.  The supply pipe for the evaporative cooling will need to fabricated using 1/2" PVC pipe, 15 Water Emitters, a PVC end cap, a slip joint-female thread pvc fitting, and male thread-1/2" barb fitting.  The 3/16 jig in the 3D printed parts folder can be used along with a cordless drill and 3/16" drill bit to drill the holes for the emitters.  The jig is used by inserting the peg into the first drilled hole and then drilling the next hole through the opening in the jig.  This process can be repeated for all 15 holes.  After drilling all of the holes, prep the pipe with primer, and insert the water emitters into the holes.  Use PVC cement on the emitter when placing them on the pipe to adhere them to the pipe and create a water tight seal.  Then slide the 3D printed pipe mounts onto both ends of the pipe.  Mount the pipe on the greenhouse and cut the ends to your desired length.  Then use the primer and cement to put on the rest of the fittings. 1/2" tubing will have to be ran from the pipe to the pump in the water sump; therefore, the last fitting on the pipe whould be a 1/2" barb fitting with a hose clamp
![](https://github.com/calebkennedy10/EE305_Project_Greenhouse/blob/main/IMAGES/EVAP_SYSTEM_ASSEMBLY.JPG)
(Evaporative Cooling Assembly)
![](https://github.com/calebkennedy10/EE305_Project_Greenhouse/blob/main/IMAGES/EVAPORATIVE%20COOLING%20WALL%20ASSEMBLY.JPG)
(Evaporative Cooling Wall)
![](https://github.com/calebkennedy10/EE305_Project_Greenhouse/blob/main/IMAGES/MULTI_VENT_ASSEMBLY.JPG)
(Multi-Vent Assembly)

Finally, use an Arduino to set three servo motors to 30 degrees.  Then press a servo arm into three 3D printed servo attachments.  Put the servo attachments on the ends of the vent flaps.  For the multi-vent assembly, a servo attachment will need to be added to both the lower and upper vent flap.  All three attachments will have to be connected using the vent links in the orientation shown by the picture above.  Once the links are in place, use a soldering iron to melt and expad the ends of the links to keep them from slipping out of the servo attachements.  Finally, mount all three servos using the servo mounts.
#### Heating System
The heater was purchased from amazon and consists of two parts: the electric heating element and fan. To simplify the wiring and to ensure that the fan and heating element would be on at the same time, the ground and power wires for each component were spliced together. The heater was mounted to the middle of the tub perpendicular to the cooling system using nuts and bolts, which allows for the cooling system to have ample space. Other components associated with system was a TIP 31C transistor, 1kΩ resistor, and an automotive relay (12 VDC, 40A) and are housed in the electronics housing. The automotive relay’s 85 output pin is wired to the transistor's middle pin on the breadboard and then the transistor's base pin is wired to the Arduino so that the heating system can be controlled. The system required various crimp on electrical connectors such as female disconnects, splices, and spade tongues to wire these components together. This system is wired according to the provided schematic above.
#### Lights
The parts needed for the lighting system are the Ws2812 LED matrix panel, DC 12V to 5V converter, photoresistor, wires, a resistor, 12V power supply, and Arduino. The voltage converter and Arduino are placed in the electronics housing. The LED matrix is or glued in place on the top exterior of the greenhouse. Two 1/16-inch holes are drilled into the top of the of the electronics housing. The two photoresistor wire ends are put through these two holes with the light sensing part of the photoresistor on the exterior. The other resistor is placed on the Arduino breadboard. All the components are wired according to the schematic.
#### Sensors
#### Irrigation
The irrigation system consists of a 1/4" 12V DC plastic solenoid valve, as well 15 feet of 1/4" diameter tubing, 18 adjustable mister nozzles, 20 flat tee fittings, and a 3/4"-1/4" faucet adapter from the MXC Automatic Drip Mist Irrigation Kit. It is split into three lines across the length of the ceiling of the greenhouse, which are attached via twelve loops of bonsai wire strung through pairs of holes drilled into the ceiling. Each line contains 6 mister nozzles, which are attached to flat tees with 1/2" lengths of tubing; tubing is also used to string the flat tees together in order to create an irrigation line. 2 other flat tees are used to connect the lines to each other and to the tubing that goes to the solenoid valve. All connection of tubing to tees should be done using a butane torch to soften the tubing for easier insertion. The solenoid valve can also be connected to the faucet adapter via a portion of tubing, and then wired to the power supply and relay using male-to-female jumper wires. The wires should be soldered to the tabs on the valve: the left wire to power and the right to the relay. The faucet adapter should be used to connect the irrigation to an outside water supply, such as a faucet or hose.

### Code

#### Automation Code

This is the true automation code for the greenhouse.  This code builds off of the demo code’s logic to create an automated system by utilizing sensor readings to control subsystems rather than utilizing a manual input from the operator.  Once again, the sensors that are utilized are the Adafruit SHTC3 temperature and humidity sensor, which operates using the I2C communication protocol, and a voltage divider circuit that utilizes a photoresistor to vary the analog input read by the Arduino according to the exterior lighting conditions.  The data collected from these sensors are stored in integer variables that are applied to logic base if, else if, and else statements to determine whether the cooling, heating, and lighting systems come on.  The irrigation system was automated through the use of a simple algorithm that use the milllis() Arduino function to turn on the irrigation system for one minute every six hours.  These intervals can easily be changed by modifying a couple of variables at the start of the code.  All variables that are utilized within in this code use a naming scheme that allows the operator to easily determine the data that is stored in the variable in order to allow for quick modifications to be made to the code in order to meet the operator’s needs.

`// variable setup`

`#include <Servo.h>`

`#include "Adafruit_SHTC3.h"`

`Adafruit_SHTC3 shtc3 = Adafruit_SHTC3();`

`#include <Adafruit_NeoPixel.h>`

`#ifdef __AVR__`

  `#include <avr/power.h>`
  
`#endif`

`#define LED_PIN 3`

`#define NUMPIXELS 64`

`Adafruit_NeoPixel pixels(NUMPIXELS, LED_PIN, NEO_GRB + NEO_KHZ800);`

`#define DELAYVAL 500`

`int tempSensPin = A0;
`
`int RHSensPin = A1;`

`int lightSensPin = A2;`

`int irrigationTime = 1;`

`int irrigationInterval = 360;`

`int irrigationStatus = 0;`

`int hours = 0;`

`int minutes1 = 0;`

`int minutes2 = 0;`

`int timePast = 0;`

`int lightThreshold = 550;`

`int temperature = 70;
`
`int humidity1 = 60;`

`int lowWaterPin = 2;`

`int highWaterPin = 4;`

`int refillValve = 5;`

`int heaterPin = 7;`

`int pumpPin = 8;`

`int fanPin = 12;`

`int irrigationPin = 13;`

`int ventOne = 9;`

`Servo servoOne;`



`void setup() {`

  `// put your setup code here, to run once:`
  
  `#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)`
  
  `clock_prescale_set(clock_div_1);`
  
  `#endif`
  
  `pixels.begin();`
  
  `pinMode(lowWaterPin, INPUT_PULLUP);`
  
  `pinMode(highWaterPin, INPUT_PULLUP);`
  
  `pinMode(refillValve, OUTPUT);`
  
  `pinMode(heaterPin, OUTPUT);`
  
  `pinMode(pumpPin, OUTPUT);`
  
  `pinMode(fanPin, OUTPUT);`
  
  `pinMode(irrigationPin, OUTPUT);`

  `digitalWrite(refillValve, HIGH);
  `
  `digitalWrite(heaterPin, LOW);`
  
  `digitalWrite(pumpPin, HIGH);
  `
  `digitalWrite(fanPin, HIGH);`
  
  `digitalWrite(irrigationPin, HIGH);`
  
  `servoOne.attach(ventOne);`


  `servoOne.write(120);`

  `Serial.begin(9600);`

  `while (!Serial)`
  
  `delay(10);     // will pause Zero, Leonardo, etc until serial console opens`

  `Serial.println("SHTC3 test");`
  
  `if (! shtc3.begin()) {`
  
  `Serial.println("Couldn't find SHTC3");`
  
  `while (1) delay(1);`
  
  `}`
  
  `Serial.println("Found SHTC3 sensor");`
  
  `Serial.println(irrigationInterval);`
`
}`


`void loop() {`

`// put your main code here, to run repeatedly:`

  `sensors_event_t humidity, temp;`

`shtc3.getEvent(&humidity, &temp);// populate temp and humidity objects with fresh data`

`lightSensPin = analogRead(A2); `

`Serial.println(lightSensPin);`

  
  `if (lightSensPin < lightThreshold){`

`pixels.fill(pixels.Color(255, 0, 255), 0, 64);`

`pixels.show(); `

`}`

`else {`

`pixels.fill(pixels.Color(0, 0, 0), 0, 64);`

`pixels.show();`

`}`


`if (lowWaterPin == HIGH) {`

`digitalWrite(refillValve, LOW);`

`while (highWaterPin== HIGH) {`

`delay(1000);`

`}`

`digitalWrite(refillValve, HIGH);  `

`}`

`temperature = temp.temperature;`

`humidity1 = humidity.relative_humidity;`

`Serial.println(temperature);`

`Serial.println(humidity1);`
   
`if (temperature > 29) {`
   
   `servoOne.write(30);`
   
   `delay(2500);`
   
   `digitalWrite(fanPin, LOW);`
   
   `digitalWrite(pumpPin, LOW);`
   
   `digitalWrite(heaterPin, LOW);`
   
   `}`
   `else if (temperature> 24 & humidity1 < 50){`
   
   `servoOne.write(30);`
   
   `delay(2500);`
   
   `digitalWrite(fanPin, LOW);`
   
   `digitalWrite(pumpPin, LOW);`
   
   `digitalWrite(heaterPin, LOW);`
   
   `}`
   
   `else if (temperature> 24) {`
   
   `servoOne.write(30);`
   
   `delay(2500);`
   
   `digitalWrite(fanPin, LOW); `
   
   `digitalWrite(heaterPin, LOW);`
   
   `digitalWrite(pumpPin, HIGH);`
   
   
   `}`
   
   `else if (temperature < 22) {`
   
   `servoOne.write(120);`
   
   `delay(2500);`
   
   `digitalWrite(heaterPin, HIGH);`
   
   `digitalWrite(pumpPin, HIGH);`
   
   `digitalWrite(fanPin, HIGH);`
   
   `}`
   
   `else{`
   
   `servoOne.write(75);`
   
   `delay(2500);`
   
   `digitalWrite(fanPin, HIGH);`
   
   `digitalWrite(heaterPin, LOW);`
   
   `digitalWrite(pumpPin, HIGH);`
   
   `}`

  `minutes1 = millis()/60/1000-minutes2;`
`
Serial.println(minutes1);`

`if(minutes1 >= irrigationInterval & irrigationStatus == 0) {`

`minutes2 = minutes2+360;`

`irrigationStatus =1;`

`digitalWrite(irrigationPin, LOW);`

`}`

`else if(minutes1>=irrigationTime & irrigationStatus == 1) {`

`minutes2 = minutes2+1;`

`irrigationStatus=0;`

`digitalWrite(irrigationPin, HIGH);`

`}`
 

    
`}`
## Testing Description
Early testing consisted of examining every component separately in order to ensure basic functionality, such as whether valves would open,servo motors would turn, fans would blow air, and the heater would get hot when instructed to by the code. The components were then tested in combination, when they were wired up as they would be for the greenhouse. 
### Equipment
- Laptop
- USB connector (Arduino to laptop)
- Access to a faucet/water supply
- Access to electrical outlet
### Procedure
- Plug 12V power supply into an outlet and attach the irrigation system to a hose faucet
- Use demonstration code to activate each aspect of the greenhouse individually
## Design Decision Discussion
#### Power Supply
The first power supply we selected was 12V/120W. It was assumed that this would be sufficient to run all the components associated with this project. This changed once the heating system was finally selected and required 100W alone. Since this took up so much of the power supply’s capacity, it was realized that it may not be able to handle every component, so the power supply was upgraded to 12V/240W.
#### Heating System
The objective for the heating system was to provide heat for when the temperature system decides that the conditions inside are too cold. Originally, building a heater was considered by using a ripple heating plate as the heating element, making a housing for said element, and utilizing a computer fan. This changed when a heater that already contained these components, was assembled for virtually the same cost, and achieved the goal of the system was found.
#### Irrigation
The objective for the irrigation system was that it would be able to spray a tray of seedlings evenly. To this end, the MIXC Mist Irrigation Kit was chosen because it contained 1/4" tubing and associated misters, tees, and adapters, which would allow the irrigation setup to be small enough to place in three rows against the ceiling of the greenhouse. This would allow the irrigation system to provide even coverage of the inside of the greenhouse. The 1/4" DC push valve was chosen because it could connect directly to the tubing and also to the adapters, and because other components of the project were already using a 12V power supply and relay module which would allow for easy activation of the valve. The irrigation system functions best when the water supply is turned on slowly, and not at full strength.
#### Exterior Walls and Encasing
The exterior of the greenhouse was made using a clear plastic tub from the hardware supply store. For a more clean looking design with more precise mounting of the additional components, a clear acrylic would be a great decision to use. For the sake of the project budget, as well as simplicity, the team chose to use the clear plastic tub for this itteration of the design. This did mean that for mounting of the components such as the heating and cooling system, the team had to make cuts to remove material from the tub. A few different problems were encountered in that process. One issue was with using a regular drill, often times the material would crack of chip, creating variations and deviation from the initial design goal. Another issue was once things began being mounted on the sides, there were a few stress fractures that were made. These are likely attributed to the weight addition outside of traditional expectation for this type of tub. It was discovered that a hot blade was the best solution for removing material. If acrylic were to be used in a different iteration of this design, the material could be easily removed using a traditional laser cutting machine.
#### Circuitry and Wiring
To house the arduino and power supply, a wooden box was made. This box was placed ontop of a lattice above the water bucket, but could be easily relocated. The goal with placing it above the water supply was to have the lid encasement be one of the highest points on the design so that the photoresistor could be placed in the lid and get a more accurate reading to know when to turn on the lighting. Additionally, this meant the photoresistor did not have to be wired far away, and prevented the need for a PCB circuit. For this first iteration of design, the team did not elect to make an additional wire encasement for the wires that had to leave the circuit box and run to the greenhouse itself. While discussions were had about each of these design components, the decision was made to leave these add-on options for future models. 

### Design/System Limitations
There are a few limitations to this design that would need to be addressed in order implement it on a larger scale application.
1. The power supply is a 12V 300W power supply.  While this works for small scale applications, larger applications with more powerful hvac systems and lighting systems would require this component to be upgraded.
2. The SHTC3 only has one I2C address associated with it. Therefore, in order to utilize more than one of these sensors, a module such as an I2C multiplexer would need ot be utilized.
3. The size of this greenhouse only supports starting seedlings or growing smaller herbs.  The overall scale of the system would have to be increased if completing an entire plant lifecycle was desired.
4. The temperature output does not modulate so in order for precise temperature control on a larger scale, more complex modifications would have to be implemented like VFD incorporation. Also due to the lack of modulation, the equipment will cycle more so the equipment will not last as long. When dealing with larger, more expensive equipment, this would be an issue.
5. A different exterior wall and encasement would be a neccessary upgrand when scaling this product. The tub exterior works, but it is also not the most visually appealing exterior and for long term continued use, the acrylic or alternative material exterior would be ideal. Another option would be a wooden frame, with each piece attached via the frame, and then encasing everything in a clear plastic tarp like material and tacking it down on the sides, making cut outs where needed for the subsystem. This would be a more budget friendly option, and would be easily replaceable if damage were to occur to the wall encasing, but would lose a lot of the stability factors that the solid plastic offers.
6. Circuitry and wiring could easily be adjusted for larger scale applications. A circuits box on one end of the green house would allow for housing of the various components (also note limitation #1 and #4), as well as a more intentional routing of the wiring, would be neccessary. If the exterior is changed in a manner similar to something suggested in limitation #5, it would be relatively simple to add wire housing along the base of the exterior. 

## Test Results Discussion
The greenhouse is best suited for trays of small plants or seedlings. This is beneficial also for starting your plants earlier in the season before weather is fully conducive for growth, allowing them to mature fully at the desired time independent of mother nature's cooperation. 

## Testing Results
The irrigation system was testing by running a small amount of water from the external hose/faucet, then opening and closing the valve to test whether the water would shut off in the greenhouse. The testing found that the irrigation system could be operated fully automatically, with minimal leaking from the mister nozzles.
