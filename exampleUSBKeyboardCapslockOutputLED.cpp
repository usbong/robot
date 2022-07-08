/*
# Usbong Halimbawa: Computer to Hardware Output
# where: Hardware Output : USB Keyboard Capslock LED
#
# C++ Computer Language
#
# Compile and Link Multiple Source Files
#
# @company: USBONG
# @author: SYSON, MICHAEL B.
# @date created: 20220704
# @last updated: 20220704
#
# References:
# 1) https://www3.ntu.edu.sg/home/ehchua/programming/cpp/gcc_make.html;
# last accessed: 20200930
#
# 2) https://stackoverflow.com/questions/38894697/how-can-i-turn-on-off-caps-lock-scroll-lock-num-lock-key-programatically-on-li;
# last accessed: 20220704
# answer by: BiagioF, 20160811; edited by CommunityBot, 20200620
#
# Additional Notes:
# 1) compile: 
#    g++ -c exampleUSBKeyboardCapslockOutputLED.cpp 
#	 g++ -o exampleUSBKeyboardCapslockOutputLED exampleUSBKeyboardCapslockOutputLED.o 
#
# 2) execute: sudo ./exampleUSBKeyboardCapslockOutputLED
# --> output: Capslock (and Numlock) Light Emitting Diodes (LED) shall BLINK;
--> reminder: LIGHT = 1;  NO LIGHT = 0;
#
# Recommended Reading:
# 1) https://www.asahi.com/articles/ASQ6N6GSBQ6NULFA001.html; last accessed: 20220704; from 20220621
# --> アマゾン、西日本最大の倉庫を報道陣に公開　最新技術で出荷増
#--> AMAZON, ipinahayag itong BALITA: Sa Kanlurang Hapon, ang pinakamalaking LALAGYAN;
#
*/

// Linux header, no portable source

#include <sys/ioctl.h>
#include <fcntl.h>
#include <unistd.h>
#include <iostream>


int main(int argc, char* argv[]) {
  int fd_console = open("/dev/console", O_WRONLY);
  if (fd_console == -1) {
    std::cout << "Error opening console file descriptor\n";
    //exit(-1);
    return -1;
  }
  
  // turn on caps lock
  ioctl(fd_console, 0x4B32, 0x04);

  // turn on num block 
  //ioctl(fd_console, 0x4B32, 0x02);
  
  // turn off 
  ioctl(fd_console, 0x4B32, 0x0);
  
  close(fd_console);
  return 0;
}
