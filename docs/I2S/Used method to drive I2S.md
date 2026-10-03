# Used method to drive I2S

The standard ESP32xx hardware/firmware drivers are very eager to keep on transmitting.

To prevent glitches (esp when driving just a few Neopixels), for each transmission sequence this driver:

- preloads Neopixel data (1 or more DMA chunks) plus 1 DMA chunk with zeros
- enables the I2S channel, to start the transmission of the chunks
- disables the I2S channel again after transmission of all chunks
- wait 1ms (in a separate RTOS task) before a new sequence can be started

Normally only the intended DMA chunks are transmitted. However, when driving just a few Neopixels, on some ESP32xx chips the last DMA chunk (all zeros) is repeated multiple times before the I2S channel can be disabled. This is shown in the statistical data of the driver, but does not harm.
