# EE305_Project_Greenhouse
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
- DC 12V 24V to 5V 10A Converter
- 1/2" PVC pipe and various 1/2" fittings
- 10W 110V AC aquarium pump with 1/2" ID tubing output
- 1/2" ID tubing and barb fittings
- PVC cement and primer
- PLA filament
- 300W 12V power supply
- Solder
- Various crimp on electrical connectors.
- 5 Gallon Bucket
- 2x Horizontal Float Switches
- 2x 12V PC fans
### 3D-Printed Components
All 3D printed componets are available via the "3D PRINTED PARTS" file in the repository.  They are available in their native SOLIDWORKS CAD formats.  Please refer to the assembly files in order to determine which parts are to be printed for each assembly and how the parts are assembled together.  3mm self tapping screws and 1/4"-20 bolts and nuts are the only pieces of hardware required to assemble each 3D printed assembly.  Parts can be printed out of several different materials and are designed to be printed on an FDM 3D printer.  Our team utilized Overture PLA Filament to print the parts; however, other common filaments types such as PETG, ABS, and ASA are acceptable if so desired.  All parts should be printed at a .2mm layer height with and infill density of 10%-15%.  It is advised to make spares of smaller parts such as the water emitters and servo attachments as these parts are easy to break during the assembly process.  Moving parts such as the vent flaps s will have to be sanded in order to allow for smooth rotation.  It is also recommended to drill out or sand holes where rotation will take place.  It is recommended to use a printer with a build plate area of at least 220mm x 220mm when printing large parts such as the vent flaps for the multivent.
### Circuit
While the circuit for this project is not overly complex, there is a lot of wiring involved.  Please refer to the schematic below when wiring up the system.  It is recommend that soldered connections with heat shrink coverings be utilized where possible in order to provide a water-tight seal around connections.  The power supply, voltage converter, microcontroller, breadboard, and relays should all be placed in a sealed container to protect them from the elements.  Our team utilized a 50W laser cutter to create a box to store all of these components.  If you have access to this type of tooling and wish to use our plans, the files for the box can be found in this repository.  Otherwise, any container or self-fabricated box will do as long as it provides adequate protection. 
### Greenhouse Assembly
#### Cooling System
Two vent fan assemblies and one evaporative cooling system assembly are required to complete the cooling system.  As mentioned previously, please refer to the SOLIDWORKS assembly files in order ot determine all 3D printed parts of the required to complete these assemblies.  The vent fan assemblies will be mounted on one end of the greenhouse while the evaporative cooling assembly will be mounted on the other side.  Assemble all sub assemblies prior to installation using 3mm screws.  Use the mounting adapters for the all of the assemblies to mark the holes that will need to be drilled in the house to mount the components.  All mounting holes will use 1/4"-20 hardware to hold components in place
For the vent fan assemblies, try to mount them as close to the center as possible to allow room for the servo mounts on the inside of the house.  One mounting adapter, the fan mount, fan, and fan retainer go on the exterior of the house while the other adapter, vent assembly, and servo mount go on the interior.  Once the proper orientation of the fan is decided on, drill a 5/16" hole in the fan mount to allow for the wires to pass through the wall of the mount.  This mounting procedure is to be utilized for both vent fan assemblies.
For the evaporative cooling system assembly, mount it as far to one side of the house as possible to allow for enough room for the servo mount on the inside.  The evaporative cooling wall assembly and one set of mounting adapters are mounted to the exterior of the greenhouse while the multi-vent assembly, servo mount, and last set of mounting adapters are mounted on the inside of the greenhouse.  The supply pipe for the evaporative cooling will need to fabricated using 1/2" PVC pipe, 15 Water Emitters, a PVC end cap, a slip joint-female thread pvc fitting, and male thread-1/2" barb fitting.  The 3/16 jig in the 3D printed parts folder can be used along with a cordless drill and 3/16" drill bit to drill the holes for the emitters.  The jig is used by inserting the peg into the first drilled hole and then drilling the next hole through the opening in the jig.  This process can be repeated for all 15 holes.  After drilling all of the holes, prep the pipe with primer, and insert the water emitters into the holes.  Use PVC cement on the emitter when placing them on the pipe to adhere them to the pipe and create a water tight seal.  Then slide the 3D printed pipe mounts onto both ends of the pipe.  Mount the pipe on the greenhouse and cut the ends to your desired length.  Then use the primer and cement to put on the rest of the fittings.
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
- Plug 12V power supply into an outlet and attach the irrigation system to a hose faucet
- Use demonstration code to activate each aspect of the greenhouse individually
- 
## Design Decision Discussion
### Irrigation
The objective for the irrigation system was that it would be able to spray a tray of seedlings evenly. To this end, the MIXC Mist Irrigation Kit was chosen because it contained 1/4" tubing and associated misters, tees, and adapters, which would allow the irrigation setup to be small enough to place in three rows against the ceiling of the greenhouse. This would allow the irrigation system to provide even coverage of the inside of the greenhouse. The 1/4" DC push valve was chosen because it could connect directly to the tubing and also to the adapters, and because other components of the project were already using a 12V power supply and relay module which would allow for easy activation of the valve.
## Test Results Discussion
The greenhouse is best suited for watering trays of small plants or seedlings. 

## Testing Results

