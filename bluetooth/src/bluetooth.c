#include <zephyr/zephyr.h>
#include <zephyr/device.h>
#include <zephyr/drivers/uart.h>

#define UART_DEVICE_NAME "uart"
#define RX_PIN 6
#define TX_PIN 4    
int Porcentaje_Carga = 0;
int tiempo_de_Carga = 0;
int Autonomía = 8;

void main(void) {
    const struct device *uart_dev;
    uint8_t rx_data;
    uint8_t tx_data;

    uart_dev = device_get_binding(UART_DEVICE_NAME);
    if (!uart_dev) {
        printk("No se pudo obtener el dispositivo UART\n");
        return;
    }

    int ret = uart_configure(uart_dev, NULL);
    if (ret < 0) {
        printk("Error al configurar el dispositivo UART: %d\n", ret);
        return;
    }

    // ret = uart_pin_configure(uart_dev, RX_PIN, NULL);
    // if (ret < 0) {
    //     printk("Error al configurar el pin de recepción: %d\n", ret);
    //     return;
    // }

    // ret = uart_pin_configure(uart_dev, TX_PIN, NULL);
    // if (ret < 0) {
    //     printk("Error al configurar el pin de transmisión: %d\n", ret);
    //     return;
    // }

    printk("Esperando datos...\n");

    while (1) {
        ret = uart_poll_in(uart_dev, &rx_data);
        if (ret < 0) {
            printk("Error al leer datos: %d\n", ret);
            continue;
        }

        printk("Dato recibido: %c\n", rx_data);

        // Utilizar estructura switch-case para tomar decisiones basadas en el dato recibido
        switch (rx_data) {
            case 'A':
                tx_data = Porcentaje_Carga;  // Dato a enviar por el pin de salida si se recibe 'A'
                break;
            case 'B':
                tx_data = tiempo_de_Carga;  // Dato a enviar por el pin de salida si se recibe 'B'
                break;
            case 'C':
                tx_data = Autonomía;  // Dato a enviar por el pin de salida si se recibe 'C'
                break;
            default:
                tx_data = 'E' ;  // Dato a enviar por el pin de salida en caso de otra entrada
                break;
        }

        printk("Enviando dato por el pin 2: %c\n", tx_data);
        uart_poll_out(uart_dev, tx_data);
    }
}
