# MonoxSense - CO Gas Monitor

ESP32-C3 based Carbon Monoxide (CO) monitoring system using MQ7 gas sensor. The device continuously monitors CO levels and provides alerts through buzzer and MQTT notifications.

## Features:
	 1. Real-time CO gas monitoring using calibrated MQ7 sensor
	 2. Audible alerts via active buzzer when CO levels exceed safety thresholds
	 3. Remote configuration and monitoring via MQTT
	 4. Over-the-Air (OTA) firmware updates
	 5. Local Flash storage for device configuration
	 6. MQTT telemetry data publishing:
		- CO levels in PPM
		- Battery status
		- Device health metrics
	 7. USB PSU powered 
	 8. Remote debugging via Telnet
	 9. Web interface for initial setup and configuration
	10. NTP time synchronization

## Hardware Requirements:
	- ESP32-C3 microcontroller
	- MQ7 Carbon Monoxide sensor
	- Active buzzer for alerts
	- USB Power supply
	- USB-C cable

## Safety Features:
	1. Configurable CO warning thresholds
	2. Automatic alerts when dangerous levels detected
	3. Fail-safe operation during power or network outages
