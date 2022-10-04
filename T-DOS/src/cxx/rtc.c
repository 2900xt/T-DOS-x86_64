#define CURRENT_YEAR        2022                            // Change this each year!
#include <globl.h>

int century_register = 0x00;                                // Set by ACPI table parsing code if possible

Time_T currentTime;
 
enum {
      cmos_address = 0x70,
      cmos_data    = 0x71
};
 
int get_update_in_progress_flag() {
      outb(cmos_address, 0x0A);
      return (inb(cmos_data) & 0x80);
}
 
unsigned char get_RTC_register(int reg) {
      outb(cmos_address, reg);
      return inb(cmos_data);
}

Time_T read_rtc() {
      unsigned char century;
      unsigned char last_second;
      unsigned char last_minute;
      unsigned char last_hour;
      unsigned char last_day;
      unsigned char last_month;
      unsigned char last_year;
      unsigned char last_century;
      unsigned char registerB;
 
      // Note: This uses the "read registers until you get the same values twice in a row" technique
      //       to avoid getting dodgy/inconsistent values due to RTC updates
 
      while (get_update_in_progress_flag());                // Make sure an update isn't in progress
      currentTime.second = get_RTC_register(0x00);
      currentTime.minute = get_RTC_register(0x02);
      currentTime.hour = get_RTC_register(0x04);
      currentTime.day = get_RTC_register(0x07);
      currentTime.month = get_RTC_register(0x08);
      currentTime.year = get_RTC_register(0x09);
      if(century_register != 0) {
            century = get_RTC_register(century_register);
      }
 
      do {
            last_second = currentTime.second;
            last_minute = currentTime.minute;
            last_hour = currentTime.hour;
            last_day = currentTime.day;
            last_month = currentTime.month;
            last_year = currentTime.year;
            last_century = century;
 
            while (get_update_in_progress_flag());           // Make sure an update isn't in progress
            currentTime.second = get_RTC_register(0x00);
            currentTime.minute = get_RTC_register(0x02);
            currentTime.hour = get_RTC_register(0x04);
            currentTime.day = get_RTC_register(0x07);
            currentTime.month = get_RTC_register(0x08);
            currentTime.year = get_RTC_register(0x09);
            if(century_register != 0) {
                  century = get_RTC_register(century_register);
            }
      } while( (last_second != currentTime.second) || (last_minute != currentTime.minute) || (last_hour != currentTime.hour) ||
               (last_day != currentTime.day) || (last_month != currentTime.month) || (last_year != currentTime.year) ||
               (last_century != century) );
 
      registerB = get_RTC_register(0x0B);
 
      // Convert BCD to binary values if necessary
 
      if (!(registerB & 0x04)) {
            currentTime.second = (currentTime.second & 0x0F) + ((currentTime.second / 16) * 10);
            currentTime.minute = (currentTime.minute & 0x0F) + ((currentTime.minute / 16) * 10);
            currentTime.hour = (( (currentTime.hour & 0x0F) + (((currentTime.hour & 0x70) / 16) * 10) ) | (currentTime.hour & 0x80))-4;
            currentTime.day = (currentTime.day & 0x0F) + ((currentTime.day / 16) * 10);
            currentTime.month = (currentTime.month & 0x0F) + ((currentTime.month / 16) * 10);
            currentTime.year = (currentTime.year & 0x0F) + ((currentTime.year / 16) * 10);
            if(century_register != 0) {
                  century = (century & 0x0F) + ((century / 16) * 10);
            }
      }
 
      // Convert 12 hour clock to 24 hour clock if necessary
 
      if (!(registerB & 0x02) && (currentTime.hour & 0x80)) {
            currentTime.hour = ((currentTime.hour & 0x7F) + 12) % 24;
      }
 
      // Calculate the full (4-digit) year
 
      if(century_register != 0) {
            currentTime.year += century * 100;
      } else {
            currentTime.year += (CURRENT_YEAR / 100) * 100;
            if(currentTime.year < CURRENT_YEAR) currentTime.year += 100;
      }
    return currentTime;
}

void printTime(Time_T Now){
    cout("%d:%d:%d\n%d/%d/%d",Now.hour,Now.minute,Now.second,Now.month,Now.day,Now.year);
}
/*
void sleep(int seconds){
    int elapsed;
    seconds = seconds * 16384;
    Time_T oldTime = read_rtc();
    while (elapsed < seconds){
        if(read_rtc().second != oldTime.second + elapsed){
            elapsed++;
        }
    }
}*/

void sleep(int millis) {
    countDown = millis;
    while (countDown > 0) {
        
    }
}