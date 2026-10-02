# Neopixel driver for ESP32xx using I2S

Low level driver for Neopixels, using I2S on ESP32xx chips.
Features:

- **ESP-IDF** No need for Arduino framework (but works perfectly fine with in)
- **I2S**, using standard I2s driver of ESP-IDF 5.5:
  - DMA for minimal processor load
  - Automatic optimal config
- **RGB/RGBW** Configurable for RGB (3 colors) or RGBW (3 colors + white) Neopixels
- **SEQ3/SEQ4** Configurable for best match on your Neopixel timing:
  - 3 bit sequence, dutycycle: Off=33%, On=67%
  - 4 bit sequence, dutycycle: Off=25%, On=50%
- **1...N** drives 1 upto many thousants of Neopixels, only limited by the available RAM
- **Single buffer** no unneccesary copy, saving RAM memory
- **Fast**, driver waits for transmission completion in seperate task
- **Rotate** fast
- **Fill** fast
- **logging** via standard ESP_LOGx(), activate Debug for more
- **Statistics** on timing and errors

## Tested ESP32xx devices

@@@@@

| ESP32xx module           | Free heap | Largest free block | Loops/sec |
|:-------------------------|:---------:|:------------------:|:---------:|
| ESP32 (D1 mini)          | 226960    | 110580             | 38200     |
| ESP32-C3 (Mini Pro)      | 195920    | 114676             | 61900     |
| ESP32-C6 (Seeed)         | 314428    | 294900             | 56300     |
| ESP32-S2 (Wemos S2 Mini) | -         | -                  | -         |
| ESP32-S3 (Lilygo T7)     | 258796    | 217076             | 54400     |

> It's unclear why the "Largest free block" of ESP32 and ESP32-C3 is relatively small.  
Also checked directly after startup: same picture, so not due to the application.
>
> I do have an ESP32-S2, but I cannot get the console logging to work.  
Have seen this before, also at others. Giving up for now.

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
- pioarduino IDE
- Prettier - Code formatter
- Prettier-Standard - JavaScript formatter
- Python
- Python Debugger
- Python Environments

GitLens -  Git supercharged, free ("Community") edition.  
In Settings I switched Off `[_]` the "Plus Features enabled" to avoid getting nagged about upgrading to Pro.  

Git for Windows, latest x64 version (currently 2.55.0) from [Git](https://www.git-scm.com)
