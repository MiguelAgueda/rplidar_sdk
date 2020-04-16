#include <unistd.h>				//Needed for I2C port
#include <fcntl.h>				//Needed for I2C port
#include <sys/ioctl.h>			//Needed for I2C port
#include <linux/i2c-dev.h>		//Needed for I2C port

int file_i2c;
int length;
unsigned char buffer[3] = { 0 };

#define MCU_ADDR 0x04
#define FORWARD_FLAG 0x02
#define BACKWARD_FLAG 0x03
#define STOP_FLAG 0x04
#define LEFT_FLAG 0x05
#define RIGHT_FLAG 0x06
#define CENTER_FLAG 0x07
#define TERMINATE_FLAG 254

class I2C_Comm
{
	//char * I2C_PORT;
	//byte COMM_ADDR;

public:
	I2C_COMM::connect(char port, int addr)
	{
		char* filename = (char*)port;
		if ((file_i2c = open(filename, O_RDWR)) < 0)
		{
			printf("Failed to open the i2c bus");
			return;
		}

		if (ioctl(file_i2c, I2C_SLAVE, addr) < 0)
		{
			printf("Failed to acquire bus access and/or talk to slave.\n");
			return;
		}
	}

	I2C_COMM::write(int bytes_to_write)
	{
		//----- WRITE BYTES -----
		buffer[0] = 0x00;
		buffer[1] = CENTER_FLAG;
		buffer[2] = STOP_FLAG;
		length = 3;			//<<< Number of bytes to write
		if (write(file_i2c, buffer, length) != length)		//write() returns the number of bytes actually written, if it doesn't match then an error occurred (e.g. no response from the device)
		{
			/* ERROR HANDLING: i2c transaction failed */
			printf("Failed to write to the i2c bus.\n");
		}
	}
};