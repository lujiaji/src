#include "dspl_upd.h" 

// Volatile variables for fraction of seconds (last four digits)
volatile int thousandths = 0;
volatile int hundredths = 0;
volatile int tenths = 0;

// Volatile variables for seconds (first four digits)
volatile int seconds = 0;
volatile int tens = 0;
volatile int hundreds = 0;
volatile int thousands = 0;

// Control flags
volatile int is_running = 1;  // Flag to indicate if the stopwatch is running
volatile int count_up_mode = 1;  // 1 = Count Up, 0 = Count Down

// Function to display the current stopwatch time
void display_stopwatch() {
    if (is_running) {  // Only update if running
        // Display fraction of seconds (last four digits)
        sevenseg_draw_digit(0, thousandths);
        sevenseg_draw_digit(1, thousandths);
        sevenseg_draw_digit(2, hundredths);
        sevenseg_draw_digit(3, tenths);
        
        // Display seconds (first four digits)
        sevenseg_draw_digit(4, seconds);
        sevenseg_draw_digit(5, tens);
        sevenseg_draw_digit(6, hundreds);
        sevenseg_draw_digit(7, thousands);
    }
}

// Function to update time for each increment, handles both count up and count down
void increment_time() {
thousandths++;
    if (thousandths > 9) {
        thousandths = 0;
        hundredths++;
    }
    if (hundredths > 9) {
        hundredths = 0;
        tenths++;
    }
    if (tenths > 9) {
        tenths = 0;
        seconds++;
    }
    if (seconds > 9) {
        seconds = 0;
        tens++;
    }
    if (tens > 9) {
        tens = 0;
        hundreds++;
    }
    if (hundreds > 9) {
        hundreds = 0;
        thousands++;
    }
}

void decrement_time() {
        if (thousandths == 0) {
            thousandths = 9;
            if (hundredths == 0) {
                hundredths = 9;
                if (tenths == 0) {
                    tenths = 9;
                    if (seconds == 0) {
                        seconds = 9;
                        if (tens == 0) {
                            tens = 9;
                            if (hundreds == 0) {
                                hundreds = 9;
                                if (thousands > 0) {
                                    thousands--;
                                }
                            } else {
                                hundreds--;
                            }
                        } else {
                            tens--;
                        }
                    } else {
                        seconds--;
                    }
                } else {
                    tenths--;
                }
            } else {
                hundredths--;
            }
        } else {
            thousandths--;
        }
}
void update_time() {
    if (is_running) {
        if (count_up_mode) {
            // Check if the limit is reached
            if (thousands == 9 && hundreds == 9 && tens == 9 && seconds == 9 &&tenths == 9 && hundredths == 9 && thousandths == 9)
            {
                is_running = 0;
                return;
            }
            increment_time();  // Increment the time
        }
        else {
            // Check if the time is 0
            if (thousands == 0 && hundreds == 0 && tens == 0 && seconds == 0 &&
                tenths == 0 && hundredths == 0 && thousandths == 0) {
                is_running = 0;
                return;
            }
            decrement_time();  // Decrement the time
        }
    }
}

// Function to start/stop the stopwatch
void toggle_start_stop() {
    is_running = !is_running;  // Toggle the running state
}

// Function to reset the stopwatch
void reset_stopwatch() {
    is_running = 0;  // Stop the stopwatch

    // Reset all time units
    thousandths = 0;
    hundredths = 0;
    tenths = 0;
    seconds = 0;
    tens = 0;
    hundreds = 0;
    thousands = 0;

    // Update the display with reset values
    display_stopwatch();
}

// Function to toggle between count up and count down mode
void toggle_mode() {
    count_up_mode = !count_up_mode;  // Toggle between count up (1) and count down (0)
}
void changeCountParas(unsigned int btn){
    // Control flags init
    is_running = 0;  // Flag to indicate if the stopwatch is running
    count_up_mode = 1;  // 1 = Count Up, 0 = Count Down
    if(btn == 16){
        // 中间：重置
xil_printf("middle %d \r\n", btn);
        thousandths = 0;
        hundredths = 0;
        tenths = 0;
        seconds = 0;
        tens = 0;
        hundreds = 0;
        thousands = 0;
    }
    if (btn == 1)
    {
        //上面：开始
        is_running = 1;
        xil_printf("up %d \r\n", btn);

    }
    if (btn == 8){
        //下面：暂停
        is_running = 0;
        xil_printf("down %d \r\n", btn);
    }
    if (btn == 2){
        //左边：向上数
        count_up_mode = 1;
        xil_printf("left %d \r\n", btn);
    }
    if (btn == 4){
        //右边：向下数
        count_up_mode = 0;
        xil_printf("right %d \r\n", btn);
    }
}
