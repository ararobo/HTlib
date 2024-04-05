/*
 * mcp342x.cpp
 *
 *  Created on: 2023/11/9
 *      Author: Tanaka Haruto
 */

#include "MCP3424.hpp"

MCP3424::MCP3424(I2C_HandleTypeDef* pI2C) {
    init(pI2C);
}

void MCP3424::init(I2C_HandleTypeDef* pI2C) {
    pI2CHandle = pI2C;
}

int32_t MCP3424::readADC() {
    // Write the config register to set the resolution
    HAL_I2C_Mem_Read(pI2CHandle, (MCP3424add << 1), &configSet, 1, ADCdatarec, 5, 10);

    //Decode data
    HAL_I2C_Master_Receive(pI2CHandle, (MCP3424add << 1), ADCdatarec, 5, 10);

    switch (Resolution) {
        case 12:
            ADCval = 0;
            ADCval = (ADCdatarec[1] << 0) | (ADCdatarec[0] << 8);
            ADCval = (0x0800 & ADCval ? (int)(0x07FF & ADCval) - 0x0800 : ADCval);
            break;
        case 14:
            ADCval = (ADCdatarec[1] << 0) | (ADCdatarec[0] << 8);
            ADCval = (0x2000 & ADCval ? (int)(0x1FFF & ADCval) - 0x2000 : ADCval);
            break;
        case 16:
            ADCval = (ADCdatarec[1] << 0) | (ADCdatarec[0] << 8);
            ADCval = (0x8000 & ADCval ? (int)(0x7FFF & ADCval) - 0x8000 : ADCval);
            break;
        case 18:
            ADCval = (ADCdatarec[2] << 0) | (ADCdatarec[1] << 8) | (ADCdatarec[0] << 16);
            ADCval = (0x20000 & ADCval ? (int)(0x1FFFF & ADCval) - 0x20000 : ADCval);
            break;
    }

    return ADCval;
}
