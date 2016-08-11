#include <stdio.h>
#include <errno.h>
#include <stdlib.h>

#include "BH1750.h"

int main()
{
	int fd = wiringPiI2CSetup(BH1750_ADDR);
	if (0 > fd)
	{
		fprintf(stderr, "ERROR: Unable to access RabbitMax light sensor: %s\n", strerror (errno));
		exit(-1);
	}

	int lux = getLux(fd);
	if (0 > lux)
	{
		fprintf(stderr, "ERROR: RabbitMax light sensor not found\n");
		exit(-1);
	}

	printf("RabbitMax Light Sensor\n");
	printf("Lux: %d \n", lux);
	return 0;
}
