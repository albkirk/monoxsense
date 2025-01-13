// WRITE HERE all the Project's logic / Flow.
// **** Project definitions here ...

// **** Libraries to include here ...
#include <telemetry.h>


// **** Project code functions here ...
void before_GoingToSleep() {
    yield();
}

void project_setup() {
}

void project_loop() {
  // Ambient handing
    if (millis() > 30000) if ((millis()) % (TIMER * 60000) < 3) {  // After 30sec uptime, execute on every TIMER minutes
        send_Telemetry();     
        if ( Gas > config.UPPER_LEVEL) Buzz(10, 2000);
    }

  // Button handling
        if (A_COUNT >= 1 && A_STATUS && (millis() - Last_A > 5000)) {
            mqtt_publish(mqtt_pathtele, "PushButton", "Holded");
            telnet_println("PushButton HOLDED for 5 seconds!!!");
            flash_LED(20);
            global_reset();
            A_COUNT = 0;
        }


        if (A_COUNT >= 1 && !A_STATUS && (millis() - Last_A > Butt_Interval)) {
            mqtt_publish(mqtt_pathtele, "PushButton", String(A_COUNT));
            flash_LED(A_COUNT);
            if (A_COUNT == 3) global_restart();

            if (A_COUNT == 5) {
                config.TELNET = false;
                config.OTA = false;
                config.WEB = false;
                config.APMode = false;
                config.LED = false;
                if (BattPowered) config.DEEPSLEEP = true;
                storage_write();
                web_setup();                // needed to clean the ON extender time.
                telnet_setup();
            }
            A_COUNT = 0;
        }

}
