#ifndef MW_Servo_library_h
	#define MW_Servo_library_h
	
	#include "Arduino.h"
	
	#ifndef	PWM_FREQ
		#define PWM_FREQ 100
	#endif	
		
	#define mapF(x, in_min, in_max, out_min, out_max) ((float)x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min

//===========================================================================================================
//===========================================================================================================

	#if defined(ARDUINO_GENERIC_F411CBUX) || defined(ARDUINO_GENERIC_F411CBYX) ||\
	defined(ARDUINO_GENERIC_F411CCFX) || defined(ARDUINO_GENERIC_F411CCUX) ||\
    defined(ARDUINO_GENERIC_F411CCYX) || defined(ARDUINO_GENERIC_F411CDUX) ||\
    defined(ARDUINO_GENERIC_F411CDYX) || defined(ARDUINO_GENERIC_F411CEUX) ||\
    defined(ARDUINO_GENERIC_F411CEYX) || defined(ARDUINO_BLACKPILL_F411CC) ||\
	defined(ARDUINO_BLACKPILL_F411CE)

	#ifndef	SERVO_COUNT
		#define SERVO_COUNT 18
	#endif	
	
	#ifndef SMANAGER_TIMER
		#define SMANAGER_TIMER TIM9
	#endif

	const PinMap PinMap_TIM[] = {
	{PA_0_ALT1, TIM2,  STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF1_TIM2, 1, 0)},		// TIM2_CH1
	{PA_0,		TIM5,  STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF2_TIM5, 1, 0)},		// TIM5_CH1
	{PA_1_ALT1, TIM2,  STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF1_TIM2, 2, 0)}, 	// TIM2_CH2
	{PA_1,      TIM5,  STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF2_TIM5, 2, 0)}, 	// TIM5_CH2
	{PA_2_ALT1, TIM2,  STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF1_TIM2, 3, 0)}, 	// TIM2_CH3
	{PA_2,		TIM5,  STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF2_TIM5, 3, 0)},		// TIM5_CH3
	{PA_2_ALT2, TIM9,  STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF3_TIM9, 1, 0)}, 	// TIM9_CH1
	{PA_3_ALT1, TIM2,  STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF1_TIM2, 4, 0)}, 	// TIM2_CH4
	{PA_3,      TIM5,  STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF2_TIM5, 4, 0)}, 	// TIM5_CH4
	{PA_3_ALT2, TIM9,  STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF3_TIM9, 2, 0)}, 	// TIM9_CH2
	{PA_5,      TIM2,  STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF1_TIM2, 1, 0)}, 	// TIM2_CH1
	{PA_6,      TIM3,  STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF2_TIM3, 1, 0)}, 	// TIM3_CH1
	{PA_7_ALT1, TIM1,  STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF1_TIM1, 1, 1)}, 	// TIM1_CH1N
	{PA_7,		TIM3,  STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF2_TIM3, 2, 0)},		// TIM3_CH2
	{PA_8,      TIM1,  STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF1_TIM1, 1, 0)}, 	// TIM1_CH1
	{PA_9,      TIM1,  STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF1_TIM1, 2, 0)}, 	// TIM1_CH2
	{PA_10,     TIM1,  STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF1_TIM1, 3, 0)}, 	// TIM1_CH3
	{PA_11,     TIM1,  STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF1_TIM1, 4, 0)}, 	// TIM1_CH4
	{PA_15,     TIM2,  STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF1_TIM2, 1, 0)}, 	// TIM2_CH1
	{PB_0_ALT1, TIM1,  STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF1_TIM1, 2, 1)}, 	// TIM1_CH2N
	{PB_0,      TIM3,  STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF2_TIM3, 3, 0)}, 	// TIM3_CH3
	{PB_1_ALT1, TIM1,  STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF1_TIM1, 3, 1)}, 	// TIM1_CH3N
	{PB_1,      TIM3,  STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF2_TIM3, 4, 0)}, 	// TIM3_CH4
	{PB_3,      TIM2,  STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF1_TIM2, 2, 0)}, 	// TIM2_CH2
	{PB_4,      TIM3,  STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF2_TIM3, 1, 0)}, 	// TIM3_CH1
	{PB_5,      TIM3,  STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF2_TIM3, 2, 0)}, 	// TIM3_CH2
	{PB_6,      TIM4,  STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF2_TIM4, 1, 0)}, 	// TIM4_CH1
	{PB_7,      TIM4,  STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF2_TIM4, 2, 0)}, 	// TIM4_CH2
	{PB_8,      TIM4,  STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF2_TIM4, 3, 0)}, 	// TIM4_CH3
	{PB_8_ALT1, TIM10, STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF3_TIM10, 1, 0)},	// TIM10_CH1
	{PB_9,      TIM4,  STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF2_TIM4, 4, 0)}, 	// TIM4_CH4
	{PB_9_ALT1, TIM11, STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF3_TIM11, 1, 0)},	// TIM11_CH1
	{PB_10,     TIM2,  STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF1_TIM2, 3, 0)}, 	// TIM2_CH3
	{PB_13,     TIM1,  STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF1_TIM1, 1, 1)}, 	// TIM1_CH1N
	{PB_14,     TIM1,  STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF1_TIM1, 2, 1)}, 	// TIM1_CH2N
	{PB_15,     TIM1,  STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF1_TIM1, 3, 1)}, 	// TIM1_CH3N
	{NC,        NP,    0}
	};
#endif

//===========================================================================================================
//===========================================================================================================

class MServo {

public:

	MServo(uint8_t pin, uint16_t range = 180);
	MServo(uint8_t pin, uint16_t minP, uint16_t maxP, uint16_t range = 180);

	bool isEnabled() {return this->_enabled;}
	bool isJump = 0;
    bool isMoving = 0;
	
	int8_t move(float newPosition, uint16_t newSpeed = 0);
	int8_t moveBy(float deg, uint16_t newSpeed = 0);
	int8_t moveTime(float newPosition, uint16_t time);
	int8_t moveByTime(float deg, uint16_t time);
	int8_t jump(float newPosition);
	int8_t jumpBy(float deg);
	
	uint16_t getServoRange() {return this->_servoRange;}
	uint16_t speed;
	uint16_t position;
	uint16_t targetPosition;
	uint16_t getSpeed() {return this->speed;}
	
	uint32_t getChannel() {return this->_channel;}
	uint32_t getIndex() {return this->_index;}

	void setSpeed(uint16_t newSpeed);
	void enable();
	void disable();
	void Stop();
	
	HardwareTimer* getTimer(){return this->_Timer;}


private:

	bool _enabled = 0;

	uint8_t _servoPin;
	
	uint16_t _maxSpeed = 1200;
	uint16_t _minPWM;
	uint16_t _maxPWM;
	uint16_t _servoRange;

	uint32_t _index;
	uint32_t _channel;
	
	void timerConfig(uint16_t minP, uint16_t maxP);

	PinName  _servoPinName;
	HardwareTimer *_Timer;
};
//-----------------------------------------------------------------------------------------------------------

void MServo::enable(){
	
#ifdef SERVO_DEBUG
	Serial.printf("enable_START\r\n");
#endif

	this->_Timer->setCaptureCompare(this->_channel, this->position, RESOLUTION_16B_COMPARE_FORMAT);
	this->_enabled = 1;

#ifdef SERVO_DEBUG
	Serial.printf("enable_END\r\n");
#endif
}
//-----------------------------------------------------------------------------------------------------------

void MServo::disable(){
	
#ifdef SERVO_DEBUG
	Serial.printf("disable_START\r\n");
#endif

	this->_Timer->setCaptureCompare(this->_channel, 0, RESOLUTION_16B_COMPARE_FORMAT);
	this->_enabled = 0;
	
#ifdef SERVO_DEBUG
	Serial.printf("disable_END\r\n");
#endif
}
//-----------------------------------------------------------------------------------------------------------

MServo::MServo(uint8_t pin, uint16_t range){
	
#ifdef SERVO_DEBUG
	Serial.printf("MServo(pin= %d, range= %d)_START\r\n",pin, range);
#endif

	pinMode(pin, OUTPUT);
	digitalWrite(pin, 0);

	this->_servoPin = pin;
	this->_servoRange = range;
	this->_servoPinName = digitalPinToPinName(pin);
	this->timerConfig(500, 2500);
	
#ifdef SERVO_DEBUG
	Serial.printf("MServo(pin, range)_END\r\n");
#endif
}
//-----------------------------------------------------------------------------------------------------------

MServo::MServo(uint8_t pin, uint16_t minP, uint16_t maxP, uint16_t range){
	
#ifdef SERVO_DEBUG
	Serial.printf("MServo(pin= %d, minP= %d, maxP= %d, range= %d)_START\r\n",pin, minP, maxP, range);
#endif

	pinMode(pin, OUTPUT);
	digitalWrite(pin, 0);

	this->_servoPin = pin;
	this->_servoRange = range;
	this->_servoPinName = digitalPinToPinName(pin);
	this->timerConfig(minP, maxP);
	
#ifdef SERVO_DEBUG
	Serial.printf("MServo(pin, minP, maxP, range)_END\r\n");
#endif
}
//-----------------------------------------------------------------------------------------------------------

void MServo::timerConfig(uint16_t minP, uint16_t maxP){
	
#ifdef SERVO_DEBUG
	Serial.printf("timerConfig(minP= %d, maxP= %d)_START\r\n",minP, maxP);
#endif

	TIM_TypeDef *Instance = (TIM_TypeDef *)pinmap_peripheral(this->_servoPinName, PinMap_TIM);

	this->_index = get_timer_index(Instance);
	this->_channel = STM_PIN_CHANNEL(pinmap_function(this->_servoPinName, PinMap_TIM));

	if (HardwareTimer_Handle[this->_index] == NULL)
		HardwareTimer_Handle[this->_index]->__this = new HardwareTimer(Instance);

	this->_Timer = (HardwareTimer*)HardwareTimer_Handle[this->_index]->__this ;
	this->_Timer->pause();
	this->_Timer->setMode(this->_channel, TIMER_OUTPUT_COMPARE_PWM1, this->_servoPinName);
	this->_Timer->setOverflow(PWM_FREQ, HERTZ_FORMAT);
	this->_Timer->setCaptureCompare(this->_channel, 0, RESOLUTION_16B_COMPARE_FORMAT);
	this->_Timer->resume();
	
	this->speed = 1;
	this->_minPWM= (float)minP*PWM_FREQ/1000000*(1<<16);
	this->_maxPWM= (float)maxP*PWM_FREQ/1000000*(1<<16);
	this->targetPosition = (minP + maxP)/2;
	this->position = this->targetPosition;

#ifdef SERVO_DEBUG
	Serial.printf("_minPWM= %d	_maxPWM= %d \r\n",this->_minPWM, this->_maxPWM);
	Serial.printf("timerConfig(minP, maxP)_END\r\n");
#endif
}
//-----------------------------------------------------------------------------------------------------------

void MServo::setSpeed(uint16_t newSpeed){
	
#ifdef SERVO_DEBUG
	Serial.printf("setSpeed(newSpeed= %d)_START\r\n",newSpeed);
#endif

	if(newSpeed < 1)
		this->speed = 1;
	else if(newSpeed > this->_maxSpeed)
		this->speed = this->_maxSpeed;
	else
		this->speed = newSpeed;
	
#ifdef SERVO_DEBUG
	Serial.printf("setSpeed(newSpeed)_END\r\n");
#endif
}
//-----------------------------------------------------------------------------------------------------------

void MServo::Stop(){
	
#ifdef SERVO_DEBUG
	Serial.printf("Stop_START\r\n");
#endif

	this->targetPosition = this->position;
	isMoving = 0;
	
#ifdef SERVO_DEBUG
	Serial.printf("Stop_END\r\n");
#endif
}
//-----------------------------------------------------------------------------------------------------------

int8_t MServo::move(float newPosition, uint16_t newSpeed){
	
#ifdef SERVO_DEBUG
	Serial.printf("move(newPosition= %f, newSpeed= %d)_START\r\n",newPosition, newSpeed);
#endif

	if(this->_enabled)
	{
		uint16_t newPos = round(mapF(newPosition, 0, this->_servoRange, this->_minPWM, this->_maxPWM));

		if(newPos > this->_maxPWM	||	newPos < this->_minPWM)
		{
			#ifdef COMMUNICATION
				Serial.printf("Position out of range!\r\n"); 
			#endif
			return -1;
		}
		
		if(newSpeed > this->_maxSpeed)
			this->speed = this->_maxSpeed;
		else if(newSpeed > 0)
			this->speed = newSpeed;

		this->targetPosition = newPos;
		this->isMoving = 1;
	}
	else
	{
		#ifdef COMMUNICATION
			Serial.printf("Servo is disabled!\r\n");
		#endif
		return -2;
	}
	
#ifdef SERVO_DEBUG
	Serial.printf("move(newPosition, newSpeed)_END\r\n");
#endif	
	return 1;
}
//-----------------------------------------------------------------------------------------------------------

int8_t MServo::moveBy(float deg, uint16_t newSpeed){
	
#ifdef SERVO_DEBUG
	Serial.printf("moveBy(deg= %f, newSpeed= %d)_START\r\n",deg ,newSpeed);
#endif

	if(this->_enabled)
	{
		uint16_t newPos = this->position + round(mapF(deg, 0, this->_servoRange, 0, this->_maxPWM - this->_minPWM));

		if(newPos > this->_maxPWM	||	newPos < this->_minPWM)
		{
			#ifdef COMMUNICATION
				Serial.printf("Position out of range!\r\n"); 
			#endif
			return -1;
		}
		
		if(newSpeed > this->_maxSpeed)
			this->speed = this->_maxSpeed;
		else if(newSpeed > 0)
			this->speed = newSpeed;

		this->targetPosition = newPos;
		this->isMoving = 1;
	}
	else
	{
		#ifdef COMMUNICATION
			Serial.printf("Servo is disabled!\r\n");
		#endif
		return -2;
	}
	
#ifdef SERVO_DEBUG
	Serial.printf("moveBy(deg, newSpeed)_END\r\n");
#endif	
	return 1;
}
//-----------------------------------------------------------------------------------------------------------

int8_t MServo::moveTime(float newPosition, uint16_t time){
	
#ifdef SERVO_DEBUG
	Serial.printf("moveTime(newPosition= %f, time= %d)_START\r\n",newPosition ,time);
#endif

	if(this->_enabled)
	{
		uint16_t newPos = round(mapF(newPosition, 0, this->_servoRange, this->_minPWM, this->_maxPWM));
		
		if(newPos > this->_maxPWM	||	newPos < this->_minPWM)
		{
			#ifdef COMMUNICATION
				Serial.printf("Position out of range!\r\n"); 
			#endif
			return -1;
		}
		
		this->speed = abs(newPos - this->position)*1000/(time*PWM_FREQ);
		this->targetPosition = newPos;
		this->isMoving = 1;
	}
	else
	{
		#ifdef COMMUNICATION
			Serial.printf("Servo is disabled!\r\n");
		#endif
		return -2;
	}
	
#ifdef SERVO_DEBUG
	Serial.printf("moveTime(newPosition= %f, time= %d)_END\r\n",newPosition ,time);
#endif
	return 1;
}
//-----------------------------------------------------------------------------------------------------------

int8_t MServo::moveByTime(float deg, uint16_t time){
	
#ifdef SERVO_DEBUG
	Serial.printf("moveByTime(deg= %f, time= %d)_START\r\n",deg ,time);
#endif	 
	
	if(this->_enabled)
	{
		uint16_t newPos = this->position + round(mapF(deg, 0, this->_servoRange, 0, this->_maxPWM - this->_minPWM));

		if(newPos > this->_maxPWM	||	newPos < this->_minPWM)
		{
			#ifdef COMMUNICATION
				Serial.printf("Position out of range!\r\n"); 
			#endif
			return -1;
		}
		
		this->speed = abs(newPos - this->position)*1000/(time*PWM_FREQ);
		this->targetPosition = newPos;
		this->isMoving = 1;
	}
	else
	{
		#ifdef COMMUNICATION
			Serial.printf("Servo is disabled!\r\n");
		#endif
		return -2;
	}
	
#ifdef SERVO_DEBUG
	Serial.printf("moveByTime(deg= %f, time= %d)_END\r\n");
#endif
	return 1;
}
//-----------------------------------------------------------------------------------------------------------

int8_t MServo::jump(float newPosition){
	
#ifdef SERVO_DEBUG
	Serial.printf("jump(newPosition= %f)_START\r\n",newPosition);
#endif

	if(this->_enabled)
	{
		uint16_t newPos = round(mapF(newPosition, 0, this->_servoRange, this->_minPWM, this->_maxPWM));
		
		if(newPos > this->_maxPWM	||	newPos < this->_minPWM)
		{
			#ifdef COMMUNICATION
				Serial.printf("Position out of range!\r\n"); 
			#endif
			return -1;
		}
		
		this->targetPosition = newPos;
		this->isJump = 1;
	}
	else
	{
		#ifdef COMMUNICATION
			Serial.printf("Servo is disabled!\r\n");
		#endif
		return -2;
	}
	
#ifdef SERVO_DEBUG
	Serial.printf("jump(newPosition)_END\r\n");
#endif
	return 1;
}
//-----------------------------------------------------------------------------------------------------------

int8_t MServo::jumpBy(float deg){
	
#ifdef SERVO_DEBUG
	Serial.printf("jumpBy(deg= %f)_START\r\n",deg);
#endif

	if(this->_enabled)
	{
		uint16_t newPos = this->position + round(mapF(deg, 0, this->_servoRange, 0, this->_maxPWM - this->_minPWM));
		
		if(newPos > this->_maxPWM	||	newPos < this->_minPWM)
		{
			#ifdef COMMUNICATION
				Serial.printf("Position out of range!\r\n"); 
			#endif
			return -1;
		}
		
		this->targetPosition = newPos;
		this->isJump = 1;
	}
	else
	{
		#ifdef COMMUNICATION
			Serial.printf("Servo is disabled!\r\n");
		#endif
		return -2;
	}
	
#ifdef SERVO_DEBUG
	Serial.printf("jumpBy(deg)_END\r\n");
#endif	
	return 1;
}

//===========================================================================================================
//===========================================================================================================

class  SManager	{

public:
	
	SManager(void (*ISR)(),TIM_TypeDef *tim = SMANAGER_TIMER);
	~SManager();

	int8_t begin(bool en);
	int8_t addServo(uint8_t pin, uint16_t range=180);
	int8_t addServo(uint8_t pin, uint16_t minP, uint16_t maxP, uint16_t range=180);

	uint8_t getServosCount(){return _servosCount;}

	void enable()	{this->_servoTimer->resume(); this->_enabled = 1;}
	void disable()	{this->_servoTimer->pause(); this->_enabled = 0;}
	void update();

	MServo* getServo(uint8_t i){return this->_servos[i];}

private:
	
	bool _initialized = 0;
	bool _enabled = 0;
	
	uint8_t _servosCount = 0;
	
	MServo* _servos[SERVO_COUNT];
	HardwareTimer *_servoTimer;
};
//-----------------------------------------------------------------------------------------------------------

SManager::SManager(void (*ISR)(),TIM_TypeDef *tim){
	
#ifdef SERVO_DEBUG
	Serial.printf("Smanger_START\r\n");
#endif
	
	uint32_t TIndex = get_timer_index(SMANAGER_TIMER);
	if(TIndex != UNKNOWN_TIMER)
	{
		if (HardwareTimer_Handle[TIndex] == NULL)
			HardwareTimer_Handle[TIndex]->__this = new HardwareTimer(SMANAGER_TIMER);

		this->_servoTimer = (HardwareTimer*)HardwareTimer_Handle[TIndex]->__this;
		this->_servoTimer->setMode(1, TIMER_DISABLED);
		this->_servoTimer->setOverflow(PWM_FREQ,HERTZ_FORMAT);
		this->_servoTimer->attachInterrupt(ISR);
		this->_servoTimer->pause();
	}
	
#ifdef SERVO_DEBUG
	else
		Serial.printf("Timer do not exist!\r\n");
	Serial.printf("Smanger_END\r\n");
#endif
}
//-----------------------------------------------------------------------------------------------------------

SManager::~SManager(){
	
#ifdef SERVO_DEBUG
	Serial.printf("~Smanger_START\r\n");
#endif

	for(uint8_t i=0; i < this->_servosCount; i++)
		if(this->_servos[i] != NULL)
			delete this->_servos[i];

#ifdef SERVO_DEBUG
	Serial.printf("~Smanger_END\r\n");
#endif
}
//-----------------------------------------------------------------------------------------------------------

int8_t SManager::addServo(uint8_t pin, uint16_t range){
	
#ifdef SERVO_DEBUG
	Serial.printf("addServo(pin= %d, range= %d)_START\r\n",pin, range);
#endif

	addServo(pin, 500, 2500, range);

#ifdef SERVO_DEBUG
	Serial.printf("addServo(pin, range)_END\r\n");
#endif	
	return 1;
}
//-----------------------------------------------------------------------------------------------------------

int8_t SManager::addServo(uint8_t pin, uint16_t minP, uint16_t maxP, uint16_t range){

#ifdef SERVO_DEBUG
	Serial.printf("addServo(pin= %d, minP= %d, maxP= %d, range= %d)_START\r\n",pin, minP, maxP, range);
#endif

	PinName pn = digitalPinToPinName(pin);

	if(pin_in_pinmap(pn, PinMap_TIM))
	{
		TIM_TypeDef *Instance = (TIM_TypeDef *)pinmap_peripheral(pn, PinMap_TIM);
		uint32_t index = get_timer_index(Instance);
		uint32_t channel = STM_PIN_CHANNEL(pinmap_function(pn, PinMap_TIM));

		for(uint8_t i=0; i < this->_servosCount; i++)
		{
			if(index == this->_servos[i]-> getIndex())
			{
				if(channel == this->_servos[i]->getChannel())
				{
					#ifdef COMMUNICATION
						Serial.println("On this timer channel servo already exist!"); 
					#endif
					return -1;
				}
			}
		}
		this->_servos[this->_servosCount] = new MServo(pin, minP, maxP, range);
		this->_servosCount++;
		return this->_servosCount-1;
	}
	else
#ifdef SERVO_DEBUG
	Serial.printf("addServo(pin, minP, maxP, range)_END\r\n");
#endif
return -1;
}
//-----------------------------------------------------------------------------------------------------------

int8_t SManager::begin(bool en){
	
#ifdef SERVO_DEBUG
	Serial.printf("begin()_START\r\n");
#endif

	if(en)
		for(uint8_t i=0; i < this->_servosCount; i++)
			this->_servos[i]->enable();
	else
		for(uint8_t i=0; i < this->_servosCount; i++)
			this->_servos[i]->disable();
	
	this->_enabled = 1;
	this->_servoTimer->resume();
	this->_initialized = 1;

#ifdef SERVO_DEBUG
	Serial.printf("begin()_END\r\n");
#endif
	return this->_initialized;
}
//-----------------------------------------------------------------------------------------------------------

void SManager::update(){

#ifdef SERVO_ISR_SPEEDTEST
	uint32_t TimeEND = 0;
	uint32_t TimeSTART = DWT->CYCCNT;
#endif

	if(this->_enabled)
	{	
		for(uint8_t i=0; i < this->_servosCount; i++)
		{
			if(this->_servos[i]->isEnabled())
			{
//**************************----JUMP----**************************************
				if(this->_servos[i]->isJump)
				{
#ifdef SERVO_DEBUG
	Serial.printf("jump = %d \r\n",i);
#endif
					this->_servos[i]->position = this->_servos[i]->targetPosition;
					this->_servos[i]->getTimer()->setCaptureCompare(this->_servos[i]->getChannel(), this->_servos[i]->position, RESOLUTION_16B_COMPARE_FORMAT);
					this->_servos[i]->isJump = 0;

#ifdef SERVO_DEBUG
	Serial.printf("pos = %d \r\n",this->_servos[i]->position);
#endif	
				}
//**************************----MOVE+----**************************************
				else if(this->_servos[i]->isMoving)
				{
#ifdef SERVO_DEBUG
	Serial.printf("move = %d \r\n",i);
#endif
					if(this->_servos[i]->targetPosition > this->_servos[i]->position)
					{
						this->_servos[i]->position += this->_servos[i]->speed;
						if(this->_servos[i]->position >= this->_servos[i]->targetPosition)
						{
							this->_servos[i]->position = this->_servos[i]->targetPosition;
							this->_servos[i]->isMoving = 0;
						}
						
						this->_servos[i]->getTimer()->setCaptureCompare(this->_servos[i]->getChannel(), this->_servos[i]->position, RESOLUTION_16B_COMPARE_FORMAT);

#ifdef SERVO_DEBUG
	Serial.printf("pos = %d \r\n",this->_servos[i]->position);
#endif
					}
//**************************----MOVE-----**************************************
					else
					{
#ifdef SERVO_DEBUG
	Serial.printf("move = %d \r\n",i);
#endif
						this->_servos[i]->position -= this->_servos[i]->speed;
						if(this->_servos[i]->position <= this->_servos[i]->targetPosition)
						{
							this->_servos[i]->position = this->_servos[i]->targetPosition;
							this->_servos[i]->isMoving = 0;
						}
					
						this->_servos[i]->getTimer()->setCaptureCompare(this->_servos[i]->getChannel(), this->_servos[i]->position, RESOLUTION_16B_COMPARE_FORMAT);

#ifdef SERVO_DEBUG
	Serial.printf("pos = %d\r\n",this->_servos[i]->position);
#endif
					}
				}
			}
		}
	}
	else
	{
		#ifdef COMMUNICATION
			Serial.printf("Manager is disabled!\r\n"); 
		#endif
	}
#ifdef SERVO_ISR_SPEEDTEST
	TimeEND = DWT->CYCCNT;
	Serial.printf("ISR update time = %5d cycles\r\n",TimeEND-TimeSTART);
#endif
}
#endif
