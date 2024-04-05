/*
 * mcp342x.hpp
 *
 *  Created on:2023/11/9
 *      Author: Tanaka Haruto
 */

#ifndef MCP3424_HPP_
#define MCP3424_HPP_

#include "stm32f30xx_hal.h" //Change file by your environment

class MCP3424 {
public:
    MCP3424(I2C_HandleTypeDef* pI2C); // Constructor
    void init(I2C_HandleTypeDef* pI2C); // Initialization function
    int32_t readADC(); // Main function

private:
    I2C_HandleTypeDef* pI2CHandle;  // Pointer to the I2C handle

    uint8_t ADCdatarec[5] = {0}; // Array to store ADC data
    uint16_t MCP3424add = 0b0000000001101000; // Address of the MCP3424 device
    uint32_t ADCval = 0; // Variable to store ADC value
    int Resolution = 18; // Resolution of the ADC
    uint8_t configSet = 0b10011100; // Configuration settings for the ADC
};

#endif /* MCP3424_HPP_ */
