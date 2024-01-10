// modbus_library.h
#ifndef MODBUS_LIBRARY_H
#define MODBUS_LIBRARY_H

#include <stdint.h>

// initialize Modbus communication
void modbus_init();

// send Modbus message
void modbus_Tx(uint8_t slave_address, uint8_t function, uint8_t* data, uint8_t data_length);

// receive Modbus message
int modbus_Rx(uint8_t* buffer, uint8_t buffer_length);

// slave address from the received message
uint8_t modbus_slave_address(uint8_t* buffer);

// cmd code from the received message
uint8_t modbus_cmd_code(uint8_t* buffer);

#endif // MODBUS_LIBRARY_H

