/* Hello World Example

   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "nvs_flash.h"

#include "nimble/nimble_npl.h"
#include "nimble/nimble_port.h"

#include "services/gap/ble_svc_gap.h"
#include "services/gatt/ble_svc_gatt.h"
#include "services/ans/ble_svc_ans.h"
#include "services/ias/ble_svc_ias.h"
#include "services/lls/ble_svc_lls.h"
#include "services/tps/ble_svc_tps.h"

void nimble_demo_start(void);
void ble_hci_uart_init(void);
void ble_store_ram_init(void);

int app_main(void)
{
    nvs_flash_init();
    nimble_port_init();
    ble_hci_uart_init();
    
    /* This example provides GATT Alert service */
    ble_svc_gap_init();
    ble_svc_gatt_init();
    ble_svc_ans_init();    
    ble_svc_ias_init();
    ble_svc_lls_init();
    ble_svc_tps_init();

    nimble_demo_start();
    return 0;
}
