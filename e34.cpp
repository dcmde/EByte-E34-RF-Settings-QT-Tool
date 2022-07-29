#include "e34.h"

e34::e34()
{

}

void e34::setParity(uint8_t* paramArray, uint8_t parity)
{
    paramArray[3]&= 0x3F; // reset Parity Bits 7,6
    if ((parity==1)|(parity==2)) paramArray[3]|= (parity<<6);
}

void e34::setUartSpeed(uint8_t* paramArray, uint8_t speed)
{
    paramArray[3]&= 0xC7; // reset UART Speed Bits 5,4,3
    if (speed<8) paramArray[3]|= (speed<<3);
    else paramArray[3] = 0x18; // set default 9600 UART baudrate by bits 4,3 "1"
}

void e34::setAirSpeed(uint8_t* paramArray, uint8_t speed)
{
    paramArray[3]&= 0xF8; // reset Air Speed Bits 2.1.0
    if (speed<=5) paramArray[3]|= speed;
    else if (speed<=7) paramArray[3]|= 0x07; // set 19200 with all bits "1"
    else paramArray[3]|= 0x02; // set default 2400 Air baudrate by bit 1 "1"
}

void e34::setRadioChannel(uint8_t* paramArray, uint8_t channel)
{
    paramArray[4] = 0;
    if (channel<0x20) paramArray[4] = channel;
    else paramArray[4] = 0x17; // set default 433.0MHz channel
}

void e34::setTramsmissionMode(uint8_t* paramArray, uint8_t mode)
{
    paramArray[5]&= 0x7F; // reset Transmission Mode bit 7 to TRANSPARENT
    if (mode) paramArray[5]|= 0x80; // set Transmission Mode bit to FIXED
}

void e34::setIODriveMode(uint8_t* paramArray, uint8_t mode)
{
    if (mode==0) paramArray[5]&= 0xBF; // reset IO Drive mode bit 6 to OpenCollector
    else paramArray[5]|= 0x40; // reset IO Drive mode bit 6 to default PP/PU
}

void e34::setWakeUpTime(uint8_t* paramArray, uint8_t wor)
{
    paramArray[5]&= 0xC7; // reset WOR Time Bits 5,4,3
    if (wor<=7) paramArray[5]|= (wor<<3);
}

void e34::setFEC(uint8_t* paramArray, uint8_t fec)
{
    if (fec==0) paramArray[5]&= 0xFB; // switch FEC off by resetting bit 2
    else paramArray[5]|= 0x04; // switch FEC on by setting bit 2
}

void e34::setPower(uint8_t* paramArray, uint8_t pwr)
{
    paramArray[5]&= 0xFC; // reset bits 1,0 to default - maximum power
    if (pwr<=3) paramArray[5]|= pwr;
}

uint8_t e34::getParity(uint8_t* paramArray)
{
    uint8_t parity;
    parity = ((paramArray[3]&0xC0)>>6);
    return parity;
}

uint8_t e34::getUartSpeed(uint8_t* paramArray)
{
    uint8_t speed;
    speed = ((paramArray[3]&0x38)>>3);
    return speed;
}

uint8_t e34::getAirSpeed(uint8_t* paramArray)
{
    uint8_t speed;
    speed = (paramArray[3]&0x07);
    return speed;
}

uint8_t e34::getRadioChannel(uint8_t* paramArray)
{
    uint8_t channel;
    channel = (paramArray[4]&0x1F);
    return channel;
}

uint8_t e34::getTramsmissionMode(uint8_t* paramArray)
{
    if (paramArray[5]&0x80) return 1;
    else return 0;
}

uint8_t e34::getIODriveMode(uint8_t* paramArray)
{
    if (paramArray[5]&0x40) return 1;
    else return 0;
}

uint8_t e34::getWakeUpTime(uint8_t* paramArray)
{
    uint8_t wor;
    wor = ((paramArray[5]&0x18)>>3);
    return wor;
}

uint8_t e34::getFEC(uint8_t* paramArray)
{
    uint8_t fec;
    fec = ((paramArray[5]&0x04)>>2);
    return fec;
}

uint8_t e34::getPower(uint8_t* paramArray)
{
    uint8_t pwr;
    pwr = (paramArray[5]&0x03);
    return pwr;
}
