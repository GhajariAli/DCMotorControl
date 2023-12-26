# DCMotorControl
I'll try to capture my Journey in getting a better understanding of a Motor Control, what's a best start other than a simple DC motor.

<details>
  
<summary>Parts I've used</summary>

- Swiss Maxon A-max 391116 Mini 22mm Coreless Motor DC 12V 24V 11000RPM High Speed (spoiler alert: it's max 2250rpm) [buy here](https://www.ebay.com/itm/263685368624)
  
 ![image](https://github.com/GhajariAli/DCMotorControl/assets/124516346/7c0a4250-3e2d-4988-8401-f7c0e607e05c)
- Rotary Encoder [buy here](https://www.aliexpress.com/item/4000094589182.html?spm=a2g0o.order_list.order_list_main.41.47f21802N3jsbi)

![image](https://github.com/GhajariAli/DCMotorControl/assets/124516346/febe3d8e-4f5e-4a88-bf8a-49c4e9f33ff9)
- Power Op-Amp [OPA548T](https://www.digikey.ca/en/products/detail/texas-instruments/OPA548T/266166)
- logic level Op-Amp for level shifting, Sallen-Key Filter, ... [LM324](https://www.digikey.ca/en/products/detail/texas-instruments/LM324N/277627)
- Nucleo STM32-F411RE dev board [buy here](https://www.digikey.ca/en/products/detail/stmicroelectronics/NUCLEO-F411RE/4866485)
- Resistors, Diodes, capacitors...

</details>

<details>

<summary>Tools I've used</summary>

- RIGOL DHO804 oscilloscope
- Two 30V-10A DC power Supply ( you need two to get + and - voltage since I don't use bridge setup at first)
- Bambu Lab P1S 3D printer
- of course a computer to program (Duh!)
- A Taranis X7 Controller and its receiver to send commands ( you don't need this necessarily but it's fun!)
- Also I used this Awsome plotter software [get it here](https://github.com/mich-w/QtSerialMonitor)

</details>

<details>

<summary>First Setup</summary>

Just to make things more fun I've started with the encoder mentioned above and made this setup: 

![image](https://github.com/GhajariAli/DCMotorControl/assets/124516346/012bbd8a-51e8-4239-bd87-f05b80f4a1af)

later on moved to this to have it more stable:

![image](https://github.com/GhajariAli/DCMotorControl/assets/124516346/d773ddff-e61b-49a1-8954-0c61c7e40d9b)

All models can be find in the 3D model folder

Basic circuit for this setup (you can find it in the KiCAD folder):
![image](https://github.com/GhajariAli/DCMotorControl/assets/124516346/33acaf40-8d13-43b6-b633-c8054bc4c1a9)

This can do forward direction only for speed control with relative encodr

</details>

<details>

<summary>Second Setup</summary>

All branches before this ![image](https://github.com/GhajariAli/DCMotorControl/assets/124516346/a504411a-46da-4903-9714-701d4b92ca65) is more of a MCU feature 

</details>
<details>

<summary>Tools I've used</summary>

### You can add a header

You can add text within a collapsed section. 

You can add an image or a code block, too.

```ruby
   puts "Hello World"
```

</details>
