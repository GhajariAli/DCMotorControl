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

This can do forward direction only for speed control with relative encoder.
List of Branches:
- [This branch](https://github.com/GhajariAli/DCMotorControl/tree/VelocityControl_GPIO_Encoder) is to read the encoder with normal GPIO 
- [This branch](https://github.com/GhajariAli/DCMotorControl/tree/InterruptEncoder_VelocityControl) is to read the encoder with Interrupt 
- [This branch](https://github.com/GhajariAli/DCMotorControl/tree/VelocityControl_TimerEncoderMode) is to read the encoder with Timer in Encoder Mode ( this is easiest and probably best way, the other two was just to practive and for fun of it) 

</details>

<details>

<summary>Second Setup</summary>

in order to have both position and velocity control I moved to an absolute encodr and I made it myself!
[This branch](https://github.com/GhajariAli/DCMotorControl/tree/BidirectionSpeedandPosition) is the final branch with the new circuit that can control the motor direction and speed with the same power op-amp

![image](https://github.com/GhajariAli/DCMotorControl/assets/124516346/ca79caab-8a6e-41de-89c6-7366266dfb4b)


Here is the absolute encoder disc I made :

![image](https://github.com/GhajariAli/DCMotorControl/assets/124516346/3a39aea4-c9a1-4ee9-b9cb-12f12a874bce)

it's an 8 bit ablsute encoder which is using gray code to have less error on reading the position.

I've used some cheap IR transmitter and receiver diodes and made some stand for it as below 

![image](https://github.com/GhajariAli/DCMotorControl/assets/124516346/d7253a9e-6cf3-47bf-94c1-d6eb6e021538)
![image](https://github.com/GhajariAli/DCMotorControl/assets/124516346/b9a6b2e8-80f2-4b77-b6c5-c1a1f589ade0)

and of course you'll find all my 3d designs in the 3d model folder

![image](https://github.com/GhajariAli/DCMotorControl/assets/124516346/f2638fc8-4490-4602-8e82-0bcc4846bebf)


</details>
