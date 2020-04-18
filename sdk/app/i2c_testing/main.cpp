#include <unistd.h>				//Needed for I2C port
#include <fcntl.h>				//Needed for I2C port
#include <sys/ioctl.h>			//Needed for I2C port
#include <linux/i2c-dev.h>		//Needed for I2C port
#include <stdio.h>
#include <stdlib.h>
#include <iostream>



// bool write_buffer(float angle, float distance)
// {
// 	printf("Got to method!");
// 	int file_i2c;
// 	int length = 3;  //<<< Number of bytes to write
// 	int addr = 0x04;  //<<<<<The I2C address of the slave.
// 	unsigned char * buffer = {0};
// 	buffer[1] = 0x03;
// 	buffer[2] = 0x07;

// 	char *filename = (char*)"/dev/i2c-7";

// 	if ((file_i2c = open(filename, O_RDWR)) < 0)
// 	{
// 		printf("Error No. %d", file_i2c);
// 		//ERROR HANDLING: you can check errno to see what went wrong.
// 		printf("Failed to open the i2c bus");
// 		return false;
// 	}
	
// 	if (ioctl(file_i2c, I2C_SLAVE, addr) < 0)
// 	{
// 		printf("Failed to acquire bus access and/or talk to slave.\n");
// 		return false;
// 	}
// 	//write() returns the number of bytes actually written, if it doesn't match then an error occurred (e.g. no response from the device)
// 	if (write(file_i2c, buffer, length) != length)  
// 	{
// 		/* ERROR HANDLING: i2c transaction failed */
// 		printf("Failed to write to the i2c bus.\n");
// 		return false;
// 	}

// 	return true;
// }

int main(int argc, const char* argv[]) 
{

	printf("Hey");
	while (true);
		// write_buffer(10.2, 2.10);
}