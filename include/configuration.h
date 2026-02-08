/*
 * Hardware Configuration
 * M5Stack AtomS3 + Unit QRCode
 */

#ifndef CONFIGURATION_H
#define CONFIGURATION_H

// I2C Configuration
#define I2C_SDA_PIN 7
#define I2C_SCL_PIN 8
#define I2C_FREQUENCY 100000U

// QRCode Unit Configuration
#define QRCODE_I2C_ADDR 0x21

// Display Configuration
#define DISPLAY_ROTATION 1
#define DISPLAY_TEXT_SIZE 1

// Serial Configuration
#define SERIAL_BAUD_RATE 115200

// Buffer Configuration
#define SCAN_BUFFER_SIZE 512

// Timing Configuration
#define INIT_DELAY_MS 1000
#define SCAN_RESULT_DISPLAY_MS 200
#define LOOP_DELAY_MS 50

#endif // CONFIGURATION_H
