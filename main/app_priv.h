/*
   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/
#pragma once
#include <stdint.h>
#include <stdbool.h>

#define DEFAULT_POWER  true
typedef enum{
    APP_DRIVER_STATE_CHANGE = 0,
    APP_DRIVER_SET_SERVO_ON_LEVEL,
    APP_DRIVER_SET_SERVO_OFF_LEVEL,
}app_driver_evt_type_t;

typedef struct {
    app_driver_evt_type_t event_type;
    int event_value;
}app_driver_evt_t;
#define DEFAULT_LIMIT_UP  90
#define DEFAULT_LIMIT_DOWN 10
extern esp_rmaker_device_t *switch_device;
void app_indicator_set(bool state);
void app_driver_init(void);
int app_driver_set_state(bool state);
bool app_driver_get_state(void);
esp_err_t app_homekit_start(bool init_state);
esp_err_t app_homekit_update_state(bool state);
