# ESP-IDF dht11 library made for ESP32

Original made by [samrjohnston](https://github.com/samrjohnston/ESP32Projects) end edited by [lemonhall](https://github.com/lemonhall/esp32_dht11).

Redited again to make it work with newer versions of ESP-IDF, also the checksum had to be removed due to inconsistence. Other simple changes were made only for personal code methodology and organization.

## Including

Suposing that you have followed the instructions of the [Getting Started](https://docs.espressif.com/projects/esp-idf/en/latest/get-started/index.html) page of ESP-IDF documentation, Download or clone it to `~/esp/esp-idf/componentes/` folder and have fun.

## Usage

1. Use `setDHTPin(int pin);` to select the pin of the sensor.
2. Create a `Struct read` that will store the reading.
3. Send the adress of it to `getData(struct read *r);`.
4. The struc now contains the value of humidity in `read.humidity` and the value of temperature(in ºC) in `read.temperature`.
5. If you want the temperature in ºF just make the conversion.

## Example

The [example](https://github.com/Vitorsulzbach/Esp32-dht11/blob/master/example/dht11_ESP32_example.c) on de folder `example` make the reading of temperature and humidity in a loop.

### Wiring

```
ESP32        DHT11
VIN   --->   VCC
D4    --->   DATA
GND   --->   GND
```
