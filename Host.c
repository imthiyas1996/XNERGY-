#include <modbus_library.h>

#define SLAVEADRESS_One 0x01  // address of MCU A
#define SLAVEADRESS_Two 0x02  // address of MCU B
#define BOOT_COMMAND_One 0x10  // cmd for MCU A
#define BOOT_COMMAND_TWO 0x20  // cmd for MCU B


// Tx function to MCU A
void SendData_to_MCUA()
{

    uint8_t firmware_data[] = {0x01, 0x02, 0x03};  
    modbus_Tx(SLAVEADRESS_One, BOOT_COMMAND_One, firmware_data, sizeof(firmware_data));
    Delay(5000);
    modbus_Tx(SLAVEADRESS_Two, BOOT_COMMAND_TWO, firmware_data, sizeof(firmware_data));
}

ISR(TIMER1_OVF_vect) 
{

    Flag = 1
}


int main() {

    modbus_init();

    while (1)
    {
        if ( Flag ==1 ) 
        {
            SendData_to_MCUA();
        }
    }

    return 0;
}
