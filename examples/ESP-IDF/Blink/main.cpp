/*
***************************************************************************************************
    Example of using the ESP32xx Neopixel Driver - Blink one pixel

    Copyright (c) 2026 Erik Boskieft. All rights reserved.
    Released under the MIT License, see the LICENSE file for details.
***************************************************************************************************
*/
#include <stdio.h>
#include <string.h>
#include "sdkconfig.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "driver/gpio.h"
#include "esp_log.h"

#include "neopixel.h"

#define TAG "MAIN"

NeopixelDriver<PixelType::GRB_SEQ3> npx;
#define PIXEL_COUNT 1

/*
-------------------------------------------------------------------------------
    Set the GPIO pins based on the target chip selected when building

    Should match your actual hardware (wiring) configuration, adapt as needed.
-------------------------------------------------------------------------------
*/
gpio_num_t dataPin = GPIO_NUM_NC;

bool setGPIO(void) {
    gpio_num_t enablePin = GPIO_NUM_NC; // optional pin to enable the 3v3/5V level shifter output
    if (strcmp(CONFIG_IDF_TARGET, "esp32") == 0) {
        dataPin = GPIO_NUM_19;
        enablePin = GPIO_NUM_26;
    } else if (strcmp(CONFIG_IDF_TARGET, "esp32s2") == 0) {
        dataPin = GPIO_NUM_9;
        enablePin = GPIO_NUM_5;
    } else if (strcmp(CONFIG_IDF_TARGET, "esp32s3") == 0) {
        dataPin = GPIO_NUM_17;
        enablePin = GPIO_NUM_16;
    } else if (strcmp(CONFIG_IDF_TARGET, "esp32c3") == 0) {
        dataPin = GPIO_NUM_5;
        enablePin = GPIO_NUM_10;
    } else if (strcmp(CONFIG_IDF_TARGET, "esp32c6") == 0) {
        dataPin = GPIO_NUM_2;
        enablePin = GPIO_NUM_21;
    }

    if (dataPin == GPIO_NUM_NC) {
        ESP_LOGE(TAG, "No dataPin configured for Chip=%s", CONFIG_IDF_TARGET);
        return (false);
    }

    ESP_LOGI(TAG, "Chip=`%s`, using dataPin=%d", CONFIG_IDF_TARGET, dataPin);
    if (enablePin != GPIO_NUM_NC) {
        ESP_LOGI(TAG, "Switching On enablePin=%d", enablePin);
        gpio_set_direction(enablePin, GPIO_MODE_OUTPUT);
        gpio_set_level(enablePin, 1);
    } else {
        ESP_LOGI(TAG, "Optional enablePin is NOT configured");
    }
    return true;
}

/*
-------------------------------------------------------------------------------
    Start the Neopixel ring
-------------------------------------------------------------------------------
*/
bool startNeopixelRing(void) {
    if (!setGPIO()) {
        return (false);
    }

    ESP_LOGI(TAG, "Initializing Neopixel on pin=%d", dataPin);
    npx.begin(PIXEL_COUNT, dataPin);
    //@@@TODO: error handling

    npx.setAllPixels(neopixelBlack); // set all pixels to black
    npx.show();                      // send the data to the Neopixel ring
    npx.brightness = 0x10;           // medium brightness
    return (true);
}

/*
===============================================================================
    Main
===============================================================================
*/
extern "C" void app_main(void) {
    vTaskDelay(5000 / portTICK_PERIOD_MS); // allow serial monitor to connect

    for (;;) {
        npx.setPixel(0, neopixelRed);
        npx.show();
        vTaskDelay(100 / portTICK_PERIOD_MS); // just for visibility: without delays, the Neofixel will flash 500x/sec

        npx.setPixel(0, neopixelBlack);
        npx.show();
        vTaskDelay(100 / portTICK_PERIOD_MS);
    }
}
