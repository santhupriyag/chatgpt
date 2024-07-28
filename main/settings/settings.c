/*
 * SPDX-FileCopyrightText: 2023 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: Unlicense OR CC0-1.0
 */

#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"
#include "esp_wifi.h"
#include "esp_check.h"
#include "bsp/esp-bsp.h"
#include "nvs_flash.h"
#include "nvs.h"
#include "settings.h"
#include "esp_ota_ops.h"

static const char *TAG = "settings";
const char *uf2_nvs_partition = "nvs";
const char *uf2_nvs_namespace = "configuration";
static nvs_handle_t my_handle;

static sys_param_t g_sys_param = {
    .ssid = "Enter your wifi name here",
    .password = "Enter your password here",
    .key = "enter your openai api key here",
    .url = "https://api.openai.com/v1/"
};

esp_err_t settings_factory_reset(void)
{
    const esp_partition_t *update_partition = esp_partition_find_first(ESP_PARTITION_TYPE_APP, ESP_PARTITION_SUBTYPE_APP_OTA_0, NULL);
    ESP_LOGI(TAG, "Switch to partition UF2");
    esp_ota_set_boot_partition(update_partition);
    esp_restart();
    return ESP_OK;
}

esp_err_t settings_read_parameter_from_nvs(void)
{
    // Directly log the stored parameters
    ESP_LOGI(TAG, "Stored ssid:%s", g_sys_param.ssid);
    ESP_LOGI(TAG, "Stored password:%s", g_sys_param.password);
    ESP_LOGI(TAG, "Stored OpenAI key:%s", g_sys_param.key);
    ESP_LOGI(TAG, "Stored Base URL:%s", g_sys_param.url);
    return ESP_OK;
}

sys_param_t *settings_get_parameter(void)
{
    return &g_sys_param;
}
