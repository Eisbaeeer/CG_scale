/*
  -----------------------------------------------------------
            Settings 
  -----------------------------------------------------------
  General settings for the CG scale.
*/

// **** Loadcell hardware settings ****

#define NUMBER_LOADCELLS                3       // if set to 2, the parameters of loadcell 3 are ignored

#define DISTANCE_X1                     30      // mm
#define DISTANCE_X2                     350     // mm
#define DISTANCE_X3                     220     // mm

#define LOADCELL1_CALIBRATION_FACTOR    900     // user set calibration factor
#define LOADCELL2_CALIBRATION_FACTOR    900     // user set calibration factor
#define LOADCELL3_CALIBRATION_FACTOR    900     // user set calibration factor

/*
CG scale with 2 Loadcells:


<-         ||=== Loadcell 1 ========== Loadcell 2
                
            |        |                     |
            |---X1---|---------X2----------|



CG scale with 3 Loadcells:

       --   ||   Loadcell 1
       |    ||      ||
       |    ||      ||
       |    ||      ||
<-    X3    ||      ||================ Loadcell 2
       |    ||      ||
       |    ||      ||
       |    ||      ||
       --   ||   Loadcell 3 
                
            |        |                     |
            |---X1---|---------X2----------|
*/


#ifdef __AVR__                        // if CPU is ATmega32u4 or Atmega328, use this pins
#define PIN_LOADCELL1_DOUT            A2
#define PIN_LOADCELL1_PD_SCK          A3

#define PIN_LOADCELL2_DOUT            A0
#define PIN_LOADCELL2_PD_SCK          A1
  
#define PIN_LOADCELL3_DOUT            A9
#define PIN_LOADCELL3_PD_SCK          A10
#endif

#ifdef ARDUINO_ESP8266_NODEMCU        // if CPU is ESP8266, use this pins
#define PIN_LOADCELL1_DOUT            D6
#define PIN_LOADCELL1_PD_SCK          D5

#define PIN_LOADCELL2_DOUT            D2
#define PIN_LOADCELL2_PD_SCK          D1
  
#define PIN_LOADCELL3_DOUT            D8
#define PIN_LOADCELL3_PD_SCK          D7
#endif



// **** Measurement settings ****

#define STABILISINGTIME               3000     // ms

#define UPDATE_INTERVAL_OLED_MENU     500      // ms
#define UPDATE_INTERVAL_LOADCELL      100      // ms

#define SMOOTHING_LOADCELL1           0.4     // IIR filter: smoothing value from 0.00-1.00
#define SMOOTHING_LOADCELL2           0.4     // IIR filter: smoothing value from 0.00-1.00
#define SMOOTHING_LOADCELL3           0.4     // IIR filter: smoothing value from 0.00-1.00

#define MINIMAL_CG_WEIGHT             10      // g     if lower, no CG is displayed (0mm)
#define MINIMAL_TOTAL_WEIGHT          1       // g     if lower, weight = 0 is displayed



// **** Calibration settings ****

#define REF_WEIGHT                    1500     // g
#define REF_CG                        100      // mm



// **** Display settings ****

// Please UNCOMMENT the display used

#ifdef __AVR__                        // if CPU is ATmega32u4 or Atmega328, use this display
U8G2_SH1106_128X64_NONAME_1_HW_I2C oledDisplay(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);
//U8G2_SSD1306_128X64_NONAME_1_HW_I2C oledDisplay(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);
#endif

#ifdef ARDUINO_ESP8266_NODEMCU        // if CPU is ESP8266, use this display
U8G2_SH1106_128X64_NONAME_1_HW_I2C oledDisplay(U8G2_R0, /* reset=*/ U8X8_PIN_NONE, /* clock=*/ D3, /* data=*/ D4);
//U8G2_SSD1306_128X64_NONAME_1_HW_I2C oledDisplay(U8G2_R0, /* reset=*/ U8X8_PIN_NONE, /* clock=*/ D3, /* data=*/ D4);
#endif


// **** Voltage measurement settings ****

// Enable voltage measurement
#define ENABLE_VOLTAGE                true

// analog input pin
#ifdef __AVR__                        // if CPU is ATmega32u4 or Atmega328, use this pin
#define VOLTAGE_PIN                   A7
#endif

#ifdef ARDUINO_ESP8266_NODEMCU        // if CPU is ESP8266, use this pin
#define VOLTAGE_PIN                   A0
#endif

// supply voltage
#define V_REF                         5000     // set supply voltage from 1800 to 5500mV

// voltage divider
#define RESISTOR_R1                   10000    // ohm
#define RESISTOR_R2                   10000    // ohm

/*
                  voltage input
                     |
                     |
                    | |
                    | |  R1
                    | |
                     |
  analog Pin  <------+
                     |
                    | |
                    | |  R2
                    | |
                     |
                     |
                    GND
*/



// **** Web server settings ****

// Wifi works as an access point
const char* ssid =                  "CG scale";   // wifi name
const char* password =              "";           // wifi password

const char ip[4] =                  {1,1,1,1};    // default IP address

#define REFRESH_TIME                3             // [s], reload the main page
