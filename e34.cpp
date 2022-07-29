#include "e34.h"
#include <iostream>

e34::e34()
{

}

void e34::setAddress(uint8_t* paramArray, uint8_t address_8b)
{
    paramArray[ADDL_REG_ADDR]|= address_8b;
}


void e34::setParity(uint8_t* paramArray, uint8_t parity)
{
    if (parity<=EVEN) paramArray[SPED_REG_ADDR]|= (parity<<UART_PARITY_ADDR);
}

void e34::setUartSpeed(uint8_t* paramArray, uint8_t speed)
{
    if (speed<=U115200) paramArray[SPED_REG_ADDR]|= (speed<<UART_BAUD_ADDR);
    else paramArray[SPED_REG_ADDR] = U9600<<UART_BAUD_ADDR; 
}

void e34::setAirSpeed(uint8_t* paramArray, uint8_t speed)
{
    if (speed<=A2M) paramArray[SPED_REG_ADDR]|= speed;
    else paramArray[SPED_REG_ADDR]|= A250<<AIR_RATE_ADDR;
}

void e34::setRadioChannel(uint8_t* paramArray, uint8_t channel)
{
    if (channel<0x20) paramArray[CHAN_REG_ADDR] = channel;
    else paramArray[CHAN_REG_ADDR] = 0;
}

void e34::setTramsmissionMode(uint8_t* paramArray, uint8_t mode)
{
    if (mode) paramArray[OPT_REG_ADDR]|= mode<<TX_MODE_ADDR; // set Transmission Mode bit to FIXED
}

void e34::setIODriveMode(uint8_t* paramArray, uint8_t mode)
{
    if (mode<=1) paramArray[OPT_REG_ADDR]|= mode<<IO_DRIVE_ADDR; 
}

void e34::setWakeUpTime(uint8_t* paramArray, uint8_t wor)
{
    //paramArray[OPT_REG_ADDR]&= 0xC7; // reset WOR Time Bits 5,4,3
    //if (wor<=7) paramArray[OPT_REG_ADDR]|= (wor<<3);
}

void e34::setFEC(uint8_t* paramArray, uint8_t fec)
{
    //if (fec==0) paramArray[OPT_REG_ADDR]&= 0xFB; // switch FEC off by resetting bit 2
    //else paramArray[OPT_REG_ADDR]|= 0x04; // switch FEC on by setting bit 2
}

void e34::setPower(uint8_t* paramArray, uint8_t pwr)
{
    if (pwr<=POWER_10dBm) paramArray[OPT_REG_ADDR]|= pwr;
}

uint8_t e34::getParity(uint8_t* paramArray)
{
    uint8_t parity;
    parity = ((paramArray[SPED_REG_ADDR]&UART_PARITY_MASK)>>UART_PARITY_ADDR);
    return parity;
}

uint8_t e34::getUartSpeed(uint8_t* paramArray)
{
    uint8_t speed;
    speed = ((paramArray[SPED_REG_ADDR]&UART_BAUD_MASK)>>UART_BAUD_ADDR);
    return speed;
}

uint8_t e34::getAirSpeed(uint8_t* paramArray)
{
    uint8_t speed;
    speed = (paramArray[SPED_REG_ADDR]&AIR_RATE_MASK);
    return speed;
}

uint8_t e34::getRadioChannel(uint8_t* paramArray)
{
    uint8_t channel;
    channel = (paramArray[CHAN_REG_ADDR]&CHAN_MASK);
    return channel;
}

uint8_t e34::getTramsmissionMode(uint8_t* paramArray)
{
    if (paramArray[OPT_REG_ADDR]&TX_MODE_MASK) return 1;
    else return 0;
}

uint8_t e34::getIODriveMode(uint8_t* paramArray)
{
    if (paramArray[OPT_REG_ADDR]&IO_DRIVE_MASK) return 1;
    else return 0;
}

uint8_t e34::getWakeUpTime(uint8_t* paramArray)
{
    uint8_t wor;
    wor = ((paramArray[OPT_REG_ADDR]&0x18)>>3);
    return wor;
}

uint8_t e34::getFEC(uint8_t* paramArray)
{
    uint8_t fec;
    fec = ((paramArray[OPT_REG_ADDR]&0x04)>>2);
    return fec;
}

uint8_t e34::getPower(uint8_t* paramArray)
{
    uint8_t pwr;
    pwr = (paramArray[OPT_REG_ADDR]&TX_POWER_MASK);
    return pwr;
}
