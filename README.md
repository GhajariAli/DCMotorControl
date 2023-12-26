# DCMotorControl
I'll try to capture my Journey in getting a better understanding of a Motor Control, what's a best start other than a simple DC motor.

Here are the parts I've used:
- Swiss Maxon A-max 391116 Mini 22mm Coreless Motor DC 12V 24V 11000RPM High Speed (spoiler alert: it's max 2250rpm) [buy here](https://www.ebay.com/itm/263685368624)
  
 ![image](https://github.com/GhajariAli/DCMotorControl/assets/124516346/7c0a4250-3e2d-4988-8401-f7c0e607e05c)
- Rotary Encoder [buy here](https://www.aliexpress.com/item/4000094589182.html?spm=a2g0o.order_list.order_list_main.41.47f21802N3jsbi)

![image](https://github.com/GhajariAli/DCMotorControl/assets/124516346/febe3d8e-4f5e-4a88-bf8a-49c4e9f33ff9)
- Power Op-Amp [OPA548T](https://www.digikey.ca/en/products/detail/texas-instruments/OPA548T/266166)
- logic level Op-Amp for level shifting, Sallen-Key Filter, ... [LM324](https://www.digikey.ca/en/products/detail/texas-instruments/LM324N/277627)
- Nucleo STM32-F411RE dev board [buy here](https://www.digikey.ca/en/products/detail/stmicroelectronics/NUCLEO-F411RE/4866485)
- Resistors, Diodes, capacitors...

Here is the list of tools I had to use:
- RIGOL DHO804 oscilloscope
- Two 30V-10A DC power Supply ( you need two to get + and - voltage since I don't use bridge setup at first)
- Bambu Lab P1S 3D printer
- of course a computer to program (Duh!)
- A Taranis X7 Controller and its receiver to send commands ( you don't need this necessarily but it's fun!)
- Also I used this Awsome plotter software [get it here](https://github.com/mich-w/QtSerialMonitor)

Just to make things more fun I've started with the encoder mentioned above and made this setup: 

![image](https://github.com/GhajariAli/DCMotorControl/assets/124516346/012bbd8a-51e8-4239-bd87-f05b80f4a1af)


؛خع
