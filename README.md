# MW_Servo_library

It's library for **STM32duino** analog servo motors with **speed control** using timer **interrupts** and hardware PWM for lower MCU usage.

## General info

- Will work only with **official STM32** core.
- Will work with **F411** MCU/board but timer assignments **limit number** of usable pins. To be able to use as many pins changes had been made to **PinMap_TIM[] array**.
- F411 boards can operate up to **19 servos** (WeAct "BlackPills").
- Library uses two diffrent **objects**, one for preparing data and movement for servo, and other to execute movement.

>[!IMPORTANT]
> We cannot assign dynamic function to interrupt so we must to create
> a static function which will use this object methode. It is impossible
> to use object methode without the same object name so we need to create
> new object SManager like this

![image](https://github.com/MisterWhite24/MW_Servo_library/blob/main/PNGs/Interrupt_example.png)

>[!NOTE] 
> - **newPosition** is in degrees.	
> - **time** is in miliseconds.
> - **speed** is in PWM steps for manager uptade.
> - Max **speed** is 1200, deafult **speed** is 0. 
> - Deafult **servo range** is 180 degrees.
> - Deafult servo **minimal  pulse** is 500 and **max pulse** is 2500.
> - Every servo is added to an **array** as diffrent **object** so first **servos number** is 0 not 1.

## List of functions for servo object

- In order to execute **functions** or get **data** from servo we must get them from **array** through manager,
 to do so we use `getServo(uint8_t servo number)` function.
 
![image](https://github.com/MisterWhite24/MW_Servo_library/blob/main/PNGs/howto_use_servoOBJ_functions.png)

### Functions for servo movement

`int8_t move(float newPosition, uint16_t newSpeed = 0)` Moves servo to defined **position** with defined **speed**.

`int8_t moveBy(float degrees, uint16_t newSpeed = 0)` Moves servo by defined **degrees** from actual **position** with defined **speed**.

`int8_t moveTime(float newPosition, uint16_t time)` Moves servo to defined **position** within defined **time**.

`int8_t moveByTime(float degrees, uint16_t time)` Moves servo by defined **degrees** from actual **position** within defined **time**.

`int8_t jump(float newPosition)` Moves servo to defined **position**.

`int8_t jumpBy(float degrees)` Moves servo by defined **degrees** from actual **position**.

`void Stop()` **Stops** servo in **actual position**.

`void enable()` Turns **on** servo.

`void disable()` Turns **off** servo.

`void setSpeed(uint16_t newSpeed)` **Changes** current speed to defined speed.

### Functions for getting servo informations

`uint16_t getServoRange()` Returns servo **range**.

`uint16_t getSpeed()` Returns servo **speed**.

`uint32_t getChannel()` Returns servo timer **channel**.

`uint32_t getIndex()` Returns servo timer **index**.

`getTimer()` Returns servo **timer**.

`bool isEnabled()` Returns 1 if servo is **on**, 0 if servo is **off**.

`isMoving` Shows servo movment **state**, 1 if servo still **moving**, 0 if servo **stopped**.

`isJump` Shows servo movment **state**, 1 if servo still in **jumping** phase, 0 if servo **stopped**.

## List of functions for manager

- In order to use functions or read data from manager we use **servoManager->** like this

![image](https://github.com/MisterWhite24/MW_Servo_library/blob/main/PNGs/manager_functions_use.png)

### Adding servo

`addServo(pin ,servo range in degrees = 180)` Check if this timer channel is used by only **one servo** and if so
 **adds** servo with defined pin, deafult minimal pulse, deafult max pulse and defined range
 (if range is **not** defined range value is **deafult**) to **array**.

`addServo(pin, minnimal pulse, max pulse, servo range in degrees = 180)` Check if this timer channel is used by
 only **one servo** and if so **adds** servo with defined pin, defined minimal pulse, defined max pulse and defined range
 (if range is **not** defined range value is **deafult**) to **array** and **maps** pulses to **16bit PWM**.

### Manager 

`void update()` This function is responsible for **executing** servo movment from servos objects.

`begin(1 or 0)` Turns **on** all servos if 1 and start **update()**, if 0 then all servos are **off** and **update()** stops.

`getServo(servo number)` We use this function to get **acces** to defined servo object in **servos array**.

`void disable()` Pauses **update()**.

`void enable()` Resumes **update()**.

## Debug/communication

>[!IMPORTANT]
> - Serial communication must be working! 
> - All informations wiil appear in serial port.

`#define COMUNICATION` When something is **inncorrectly** defined in functions, **messeges** like "Servo out of range!"
 or "Servo is disabled!" will be **sent**.

`#define SERVO_DEBUG` **Debug** all functions in library and **follow** current movment.

`#define SERVO_ISR_SPEEDTEST` **Check** how fast movement goes in processor **cycles**.

`#define PWM_FREQ` Define PWM **frequency** deafult 100Hz.

`#define SERVO_COUNT` Define how many **servo** will be used defult 18.

## Contact
Created by **MisterWhite24** -> feel free to contact me!

#### Status
In progress ;)
