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

<summary>First Setup - Forward Direction Only</summary>

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

<summary>Second Setup - Bidirectional Control</summary>

in order to have both position and velocity control I moved to an absolute encodr and I made it myself!
[This branch](https://github.com/GhajariAli/DCMotorControl/tree/BidirectionSpeedandPosition) is the final branch with the new circuit that can control the motor direction and speed with the same power op-amp


![image](https://github.com/GhajariAli/DCMotorControl/assets/124516346/1d7c5da1-f85f-43ca-9fe2-f99b7e6cc64b)



Here is the absolute encoder disc I made :

![image](https://github.com/GhajariAli/DCMotorControl/assets/124516346/3a39aea4-c9a1-4ee9-b9cb-12f12a874bce)

it's an 8 bit ablsute encoder which is using gray code to have less error on reading the position.

I've used some cheap IR transmitter and receiver diodes and made some sort of a stand for it as below 

![image](https://github.com/GhajariAli/DCMotorControl/assets/124516346/d7253a9e-6cf3-47bf-94c1-d6eb6e021538)
![image](https://github.com/GhajariAli/DCMotorControl/assets/124516346/b9a6b2e8-80f2-4b77-b6c5-c1a1f589ade0)

The IR sensors can be purcahsed [here](https://www.aliexpress.com/item/1005005371811048.html?spm=a2g0o.order_list.order_list_main.21.61131802yJksCa)

and you can easily drive them with 1k resistor on transmitter and 10k on receiver ( no amplification or comparator needed for 3.3V logic level )

![image](https://github.com/GhajariAli/DCMotorControl/assets/124516346/4360179f-9dc4-40a9-8811-b82201a7bc36)


and of course you'll find all my 3d designs in the 3d model folder

![image](https://github.com/GhajariAli/DCMotorControl/assets/124516346/f2638fc8-4490-4602-8e82-0bcc4846bebf)


Position Control Results
![image](https://github.com/GhajariAli/DCMotorControl/assets/124516346/56048859-b444-448b-9eeb-58d91945d017)

Velocity Control Results
![image](https://github.com/GhajariAli/DCMotorControl/assets/124516346/aaca1e4a-abee-4351-b845-e73383a31e21)

mechanical parts not being perfect and low resolution of the encoder causes sthe fluctuations you see, otherwise it's controlling pretty good.


Watch Here:

[![Watch the video](https://github.com/GhajariAli/DCMotorControl/assets/124516346/60ce2fbe-5a5f-4591-ae94-699c1e67483c)](https://www.youtube.com/shorts/_Hv775r4zMI)
[![Watch the video](https://github.com/GhajariAli/DCMotorControl/assets/124516346/6c1456e1-f630-407c-bc6f-1cc9cc5b1091)](https://www.youtube.com/shorts/p1Zbr400qCg)

</details>


<details>

<summary>Improvements - Speed control by Voltage reading</summary>

[This](https://github.com/GhajariAli/DCMotorControl.git) is the branch for this feature. some improvement and correction in the main circuit that will be merged into the [main](https://github.com/GhajariAli/DCMotorControl.git) 

Here is the new circuit - you'll find it in the KiCAD folder MotorControl-V2

![Screenshot 2023-12-30 154358](https://github.com/GhajariAli/DCMotorControl/assets/124516346/9a8aefbf-4b26-46f2-9619-1ba71fb7877f)

Here is How it looks on the scope, I'm disabling the power op-amp for around 300 usec and read the voltage after some level shifting and clipping in channel 1 of the ADC. 
the big pulse is the op-amp enable pulse and the blue line is the motor voltage to condition and read by ADC:

![image](https://github.com/GhajariAli/DCMotorControl/assets/124516346/a5f18245-aee8-41d3-a7d2-d0fc13cc4237)

here is the speed reading results, red is the encoder feedback and blue is the voltage reading, notice it's clipped as I decided to not scale it down with voltage divider since it already had lots of fluctuation and noise. also some delay due the wait time in the mcu ( to let the self induce voltage caused by cutting motor current to dampen) 

![image](https://github.com/GhajariAli/DCMotorControl/assets/124516346/6d04716e-1fe5-472d-9075-7b38c0853c62)

as nice at it looks, I decided not to use this as a control feedback as the encoder works mych better:) but it's fun doing it.

</details>


Stay Tuned, AC Induction Motor is next!
