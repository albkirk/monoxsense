// Declare and define here all Peripheral (sensors and actuators) used in this project.
// **** Periphericals definition here ...
// -- ADC PIN Definition --
#define GAS_ADC_PIN      1          // IO pin for Carbon Monoxide GAS ADC measurement.
#define Gas_Res_Div  false          // Do you have a Resistor divider (ence needs to calculate the proportion)?
#define Gas_Res_High   100          // High Resistor value (in KOhms)
#define Gas_Res_Lower  220          // Lower Resistor value (in KOhms)

// **** Libraries to include here ...
#include <buttons.h>
//#include <touch.h>
#include <ambient.h>
//#include <mygps.h>

// **** Peripherals and critical functions here ...
void on_wakeup() {
/*
    // Avoid full setup cycle if Humidity didn't changed since last read.
    if (ESPResetReason() == "Deep-Sleep Wake" && RTC_read() )) {  // If true, I can also assume rtc.ByteValue >= 0
        if ((rtcData.FloatValue - Humidity) <=3 && (rtcData.FloatValue - Humidity) >=-3 && rtcData.ByteValue <4) {              // No change on humidity, so back to deep-sleep
            rtcData.ByteValue ++;
            telnet_println("No big change on Humidity, back to deep-sleep for " + String(config.SLEEPTime) + " min, or until next event ... zzZz :) ");
            telnet_println("Total time ON: " + String(millis()) + " msec");
            GoingToSleep(config.SLEEPTime, rtcData.lastUTCTime);
        };
    };
*/
}

// One of the 1st functions to be called on main.cpp in order to initialize critical components,
// such as: GPIO config, sensors, actuators, wake-up validation...  
void peripherals_setup() {
// Output GPIOs
 
// Input GPIOs

// Setup functions
   // Start buttons
      buttons_setup();
      //touch_setup();    
  // Start Ambient devices
      ambient_setup();

// Wake-up validation
    on_wakeup();
    TIMER = 5;                              // Time interval to measure the Gas level
}

