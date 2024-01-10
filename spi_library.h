// spi_library.h
#ifndef SPI_LIBRARY_H
#define SPI_LIBRARY_H

#include <stdint.h>

void spi_init();
void spi_send(uint8_t data);
uint8_t spi_receive();

#endif // SPI_LIBRARY_H

