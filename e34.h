#pragma once


#define CMD_SAVE_PARAMS_ON_PWR_DOWN     0xC0
#define CMD_GET_PARAMS                  0xC1
#define CMD_RESET_PARAMS_ON_PWR_DOWN    0xC2
#define CMD_GET_VERSION                 0xC3
#define CMD_RESET                       0xC4

#define PARAM_READ_HEADER       0xC0
#define VERSION_READ_HEADER     0xC3

#define PARAM_PERSISTANCE       CMD_RESET_PARAMS_ON_PWR_DOWN

#define PARLEN 6

#define NO_PARITY   0
#define ODD         1
#define EVEN        2

#define U1200 0
#define U2400 1
#define U4800 2
#define U9600 3
#define U19200 4
#define U38400 5
#define U57600 6
#define U115200 7

#define A250 0
#define A1M 1
#define A2M 2

#define TM_TRANSPARENT 0
#define TM_FIXED 1

#define IO_OC 0
#define IO_DEF 1

#define WOR250 0
#define WOR500 1
#define WOR750 2
#define WOR1000 3
#define WOR1250 4
#define WOR1500 5
#define WOR1750 6
#define WOR2000 7

#define FEC_OFF 0
#define FEC_ON 1

#define POWER_20dBm 0 // 20dBm for T100, 27dBm for T500, 30dBm for T1W
#define POWER_17dBm 1 // 17dBm for T100, 24dBm for T500, 27dBm for T1W
#define POWER_14dBm 2 // 14dBm for T100, 21dBm for T500, 24dBm for T1W
#define POWER_10dBm 3 // 10dBm for T100, 18dBm for T500, 21dBm for T1W

#define HEAD_REG_ADDR       0x00
#define ADDH_REG_ADDR       0x01
#define ADDL_REG_ADDR       0x02
#define SPED_REG_ADDR       0x03
#define CHAN_REG_ADDR       0x04
#define OPT_REG_ADDR        0x05

#define UART_PARITY_ADDR    0x06
#define UART_BAUD_ADDR      0x03
#define AIR_RATE_ADDR       0x00

#define TX_MODE_ADDR        0x07
#define IO_DRIVE_ADDR       0x06
#define TX_POWER_ADDR       0x00

#define TX_POWER_MASK       0x03
#define IO_DRIVE_MASK       0x40
#define TX_MODE_MASK        0x80
#define CHAN_MASK           0x1F
#define AIR_RATE_MASK       0x07
#define UART_BAUD_MASK      0x38
#define UART_PARITY_MASK    0xC0

#include <QMainWindow>
#include <QObject>

class e34
{
public:
    e34();
    uint8_t parameters[6];
    void setAddress(uint8_t* paramArray, uint8_t address_8b);
    void setParity(uint8_t* paramArray, uint8_t parity);
    void setUartSpeed(uint8_t* paramArray, uint8_t speed);
    void setAirSpeed(uint8_t* paramArray, uint8_t speed);
    void setRadioChannel(uint8_t* paramArray, uint8_t channel);
    void setTramsmissionMode(uint8_t* paramArray, uint8_t mode);
    void setIODriveMode(uint8_t* paramArray, uint8_t mode);
    void setWakeUpTime(uint8_t* paramArray, uint8_t wor);
    void setFEC(uint8_t* paramArray, uint8_t fec);
    void setPower(uint8_t* paramArray, uint8_t pwr);

    uint8_t getParity(uint8_t* paramArray);
    uint8_t getUartSpeed(uint8_t* paramArray);
    uint8_t getAirSpeed(uint8_t* paramArray);
    uint8_t getRadioChannel(uint8_t* paramArray);
    uint8_t getTramsmissionMode(uint8_t* paramArray);
    uint8_t getIODriveMode(uint8_t* paramArray);
    uint8_t getWakeUpTime(uint8_t* paramArray);
    uint8_t getFEC(uint8_t* paramArray);
    uint8_t getPower(uint8_t* paramArray);

private:

};
