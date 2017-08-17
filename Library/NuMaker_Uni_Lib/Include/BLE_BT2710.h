// ITON_DM command through UART
//|------------------------------------------------------------------------------------------|
//| Bytes | Description | Values |
//|--------------+------------------------------+-------------------------------------------|
//| 1~4 | CommandClass_t |(CMD_TYPE1~ CMD_TYPE4) |
//|--------------+------------------------------+-------------------------------------------|
//| 5 | Command_t | |
//|--------------+------------------------------+-------------------------------------------|
//| 6 | Payload Length | 0x00-0xFF |
//|--------------+------------------------------+-------------------------------------------|
//| 7->N | Data | bytes N >= 0 |
//|--------------+------------------------------+-------------------------------------------|
//| N+1 | checksum | checksum |
//|--------------+------------------------------+-------------------------------------------|

typedef enum {
//Command Type = 0x69 74 63 7A
CMD_TYPE1 = 'i',
CMD_TYPE2 = 't', 
CMD_TYPE3 = 'c', 
CMD_TYPE4 = 'z', 
// Response Type = 0x69 74 61 7A
ACK_TYPE1 = 'i', 
ACK_TYPE2 = 't', 
ACK_TYPE3 = 'a', 
ACK_TYPE4 = 'z', 
UNKNOW_TYPE = 0xff
} CommandClass_t;

// Command of Device/Module
typedef enum {
CMD_TEST = 0,              // Device Test
CMD_VERSION = 1,           // Obtain Firmware Version
CMD_RESET = 2,             // Reset Module
CMD_ORGL = 3,              // go to default value (enter standby mode)
// CMD_HIDorSPP = 4,       //  query device state
// CMD_ADCN = 5,           // obtain paired list device number
// CMD_ADLS = 6,           // obtain paired list device address list
// CMD_RMSAD = 7,          // clear the selected device in the paired list
// CMD_RMAAD = 8,          // delete the selected device in the paired list 
// CMD_FSAD = 9,           // search the selected device in the paired list
CMD_MRAD = 10,             // obtain recent connected bluetooth device address
CMD_STATE = 11,            // obtain bluetooth operationi state
// CMD_HIDCODE = 12,       // transmit code
CMD_DISCOVERABLE = 13,     // discoverable state control
// CMD_RECONNECT = 14,     // command module to reconnect to smartphone
CMD_DISC = 15,             // disconnect modudle from smartphone
CMD_SPPDATA = 16,          // transmit & receive SPP data
// CMD_EJECT = 17,         // transnmit iOS soft keyboard
CMD_BATMEAS = 18,          // query battery power 
CMD_POWERDOWN = 19,        // powerdown
CMD_READADDR = 20,         // read bluetooth module address
CMD_ATTDATA = 21,          // transmit & receive LE data
CMD_REENDISCOVERABLE = 22, // control disconnect auto-enter discoverable state
CMD_LEADVPARAMS = 23,      // set LE broadcast period
CMD_RSSI = 24,             // obtain connect signal strength
CMD_LECONPARAMS = 25,      // set LE connect signal period
CMD_UARTBAUD = 26,         // set UART baud rate
CMD_RENAME = 27,           // modify device name
CMD_MODBTADDR = 28,        // modify bluetooth address
CMD_MODSVCNAME = 29,       // modify LE master service name
CMD_ONLYBRIDGEMODE = 30,   // enter complete transparent transmitting mode
CMD_UNKNOW = 31           // unknown command
} Command_t;

// Response of Device/Module
typedef enum {
ACK_FAIL,      // Fail
ACK_TRUE,      // Succeed
ACK_PENDING,   // command received, prepare to execute command
ACK_UNKNOWCMD, // command not received
NONE
} Response_t;
