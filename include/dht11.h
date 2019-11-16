#include "driver/gpio.h"
#include <string.h>
#include <stdlib.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

typedef struct read{
	int humidity;
	int temperature;
};

void sendStart();
void setDHTPin(int pin);
void getData(struct read *r);
