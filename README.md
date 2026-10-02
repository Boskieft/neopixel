# Neopixel driver for ESP32xx using I2S

Reliable ESP32xx driver for Neopixels, using I2S with DMA.

Features:

- **ESP32xx family:** Tested on ESP32, ESP32-S2, ESP32-S3, ESP32-C3 and ESP32-C6.
- **ESP-IDF:** Works with and without the Arduino framework.
- **I2S:**, using standard I2s driver of ESP-IDF 5.5:
  - DMA for minimal processor load
  - Optimal DMA config
- **RGB/RGBW:** Configurable for RGB (3 colors) or RGBW (3 colors + white) Neopixels.
- **SEQ3/SEQ4:** Configurable for best match on your Neopixel's timing:
  - 3 bit sequence, period=1200ns, dutycycle: Off=33%, On=67%
  - 4 bit sequence, period=1200ns, dutycycle: Off=25%, On=50%
- **1...N:** drives 1 upto many thousants of Neopixels, only limited by the available RAM.
- **Single buffer:** no unneccesary copy, saving RAM memory.
- **Fast:** driver waits for transmission completion in seperate task.
- **Rotate:** in-memory left or right rotation
- **Fill:** in-memory color filling for a range of Neopixels (or all of them)
- **Logging:** via standard ESP_LOGx(), activate Debug for more
- **Statistics:** on timing and errors

## Tested ESP32xx devices

Tested successfully on the ESP32xx devices listed below.

| ESP32xx module           | Free heap | Largest free block | Loops/sec |
|:-------------------------|:---------:|:------------------:|:---------:|
| ESP32 (D1 mini)          | 226960    | 110580             | 38200     |
| ESP32-C3 (Mini Pro)      | 195920    | 114676             | 61900     |
| ESP32-C6 (Seeed)         | 314428    | 294900             | 56300     |
| ESP32-S2 (Wemos S2 Mini) | -         | -                  | -         |
| ESP32-S3 (Lilygo T7)     | 258796    | 217076             | 54400     |

> It's unclear why the "Largest free block" of ESP32 and ESP32-C3 is relatively small.  
Also checked directly after startup: same picture, so not due to the application.

## Build environment

Visual Studio Code (VSC), latest version (currently 1.131.0), with next Extensions:

- C/C++ and CMake extensions:
  - C/C++
  - C/C++ DevTools
  - C/C++ Extension Pack
  - C/C++ Themes
  - CMake
  - CMake Tools
- ESP Crash Decoder
- GitHub Repositories
- markdownlint (eg for this file)
- ESP-IDF -or- pioarduino IDE
- Prettier - Code formatter
- Prettier-Standard - JavaScript formatter
- Python
- Python Debugger
- Python Environments

GitLens -  Git supercharged, free ("Community") edition.  
In Settings I switched Off `[_]` the "Plus Features enabled" to avoid getting nagged about upgrading to Pro.  

Git for Windows, latest x64 version (currently 2.55.0) from [Git](https://www.git-scm.com)
