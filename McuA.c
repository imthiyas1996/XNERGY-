#include <modbus_library.h>
#include <spi_library.h>

#define MCU_B_PIN 10  //MCU B Pin


#define BUFFER_SIZE 128  // buffer for Rx
uint8_t received_Data[BUFFER_SIZE];

#define SLAVEADRESS_One 0x01  // address of MCU A
#define SLAVEADRESS_Two 0x02  // address of MCU B
#define BOOT_COMMAND_One 0x10  // Modbus command for firmware update
#define BOOT_COMMAND_TWO 0x20  // Modbus command for firmware update


int main() 
{
    modbus_init();
    spi_init();

    while (1) 
    {
        int bytes_received = modbus_Rx(received_Data, BUFFER_SIZE);
        if (bytes_received > 0) 
        {
            uint8_t slave_address = modbus_slave_address(received_Data);
            uint8_t Cmd_code = modbus_cmd_code(received_Data);

            if (slave_address == SLAVEADRESS_One && Cmd_code == BOOT_COMMAND_One)
            {
                // Trigger the MCU A to booting stage , extract the data and flash the Firmware
            }else if (slave_address == SLAVEADRESS_Two && Cmd_code == BOOT_COMMAND_TWO)
            {
                // Store the Data in MCU A and Trigger the MCU B to booting stage from MCU A
                MCU_B_PIN = HIGH;
                spi_TX(data);
                MCU_B_PIN = LOW;
            }
        }
    }
    return 0;
}
