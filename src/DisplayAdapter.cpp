/*
 * DisplayAdapter - Implementation
 */

#include "DisplayAdapter.h"

DisplayAdapter::DisplayAdapter() {
}

void DisplayAdapter::begin() {
    M5.Display.setRotation(DISPLAY_ROTATION);
    M5.Display.setTextSize(DISPLAY_TEXT_SIZE);
    M5.Display.fillScreen(BLACK);
}

void DisplayAdapter::showReadyScreen() {
    M5.Display.fillScreen(BLACK);
    M5.Display.setCursor(0, 0);
    M5.Display.setTextColor(WHITE);
    M5.Display.println("Ready to scan");
    M5.Display.println("");
    M5.Display.println("Press button");
    M5.Display.println("on QRCode unit");
    M5.Display.println("to scan");
}

void DisplayAdapter::showErrorScreen() {
    M5.Display.fillScreen(BLACK);
    M5.Display.setCursor(0, 0);
    M5.Display.setTextColor(RED);
    M5.Display.println("ERROR:");
    M5.Display.println("QRCode unit");
    M5.Display.println("not found!");
    M5.Display.println("");
    M5.Display.setTextColor(WHITE);
    M5.Display.println("Check I2C");
    M5.Display.println("connection");
}

void DisplayAdapter::showScanningScreen() {
    M5.Display.fillScreen(BLUE);
    M5.Display.setCursor(0, 0);
    M5.Display.setTextColor(WHITE);
    M5.Display.println("SCANNING...");
    M5.Display.println("");
    M5.Display.println("Point at code");
}

void DisplayAdapter::showScannedData(const String& data) {
    // Brief green flash
    M5.Display.fillScreen(GREEN);
    delay(SCAN_RESULT_DISPLAY_MS);

    // Show scanned data
    M5.Display.fillScreen(BLACK);
    M5.Display.setCursor(0, 0);
    M5.Display.setTextColor(GREEN);
    M5.Display.setTextSize(2);
    M5.Display.println("SCAN OK");
    M5.Display.setTextSize(DISPLAY_TEXT_SIZE);
    M5.Display.setTextColor(WHITE);
    M5.Display.println("");
    M5.Display.println(data);
}
