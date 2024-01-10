#include <spi_library.h>


int main() 
{
    spi_init();
    while (1) 
    {
        if (spi_RX()) 
        {
            int data = spi_RX();
            if (data > 0)
            {
                // Trigger the MCU B to booting Stage and Extract and Flash the FW
            }else
            {
                // Do nothing
            }
        }
    }

    return 0;
}
