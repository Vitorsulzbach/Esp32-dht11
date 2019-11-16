/* ESP DHT11 Example

   This example code is in the Public Domain

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/

#include "driver/gpio.h"
#include <string.h>
#include <stdlib.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"
#include "esp_event.h"
#include "protocol_examples_common.h"
#include "nvs_flash.h"
#include "esp_tls.h"
#include "esp_http_client.h"
#include "esp_system.h"
#include "rom/ets_sys.h"
#include "sdkconfig.h"
#include "dht11.h"

void DHT_task(void *pvParameter)
{
   printf("Starting DHT measurement!\n");
   struct read r;
   while(1)
   {
	getData(&r);
    printf("Temperature reading %d\n", r.temperature);
    printf("Humidity reading %d\n", r.humidity);
    vTaskDelay(3000 / portTICK_RATE_MS);
   }
}

void app_main(void)
{
	esp_err_t ret = nvs_flash_init();
    if (ret == ESP_ERR_NVS_NO_FREE_PAGES || ret == ESP_ERR_NVS_NEW_VERSION_FOUND) {
      ESP_ERROR_CHECK(nvs_flash_erase());
      ret = nvs_flash_init();
    }
	setDHTPin(4);
    ESP_ERROR_CHECK(ret);
    vTaskDelay(1000 / portTICK_RATE_MS);
    xTaskCreate(&DHT_task, "DHT_task", 2048, NULL, 5, NULL);
    
}
