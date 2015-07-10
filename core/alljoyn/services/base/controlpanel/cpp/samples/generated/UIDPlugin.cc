#include "UIDPlugin.h"

using namespace UIDAddons;

UIDRPiGPIO *temp;

UIDRPiGPIO::UIDRPiGPIO()
{
}

UIDRPiGPIO::~UIDRPiGPIO()
{
}

int UIDRPiGPIO::Export(int pin)
{
    char buffer[BUFFER_MAX];
    ssize_t bytes_written;
    int fd;
 
    fd = open("/sys/class/gpio/export", O_WRONLY);
    if (-1 == fd) {
    	fprintf(stderr, "Failed to open export for writing!\n");
     	return(-1);
    }
 
    bytes_written = snprintf(buffer, BUFFER_MAX, "%d", pin);
    write(fd, buffer, bytes_written);
    close(fd);
    return(0);
}

int UIDRPiGPIO::Unexport(int pin)
{
    char buffer[BUFFER_MAX];
    ssize_t bytes_written;
    int fd;
 
    fd = open("/sys/class/gpio/unexport", O_WRONLY);
    if (-1 == fd) {
    fprintf(stderr, "Failed to open unexport for writing!\n");
    	return(-1);
    }
 
    bytes_written = snprintf(buffer, BUFFER_MAX, "%d", pin);
    write(fd, buffer, bytes_written);
    close(fd);
    return(0);
}

int UIDRPiGPIO::Direction(int pin, int dir)
{
    static const char s_directions_str[]  = "in\0out";
 
    char path[DIRECTION_MAX];
    int fd;
 
    snprintf(path, DIRECTION_MAX, "/sys/class/gpio/gpio%d/direction", pin);
    fd = open(path, O_WRONLY);
    if (-1 == fd) {
    	fprintf(stderr, "Failed to open gpio direction for writing!\n");
    	return(-1);
    }
 
    if (-1 == write(fd, &s_directions_str[IN == dir ? 0 : 3], IN == dir ? 2 : 3)) {
    	fprintf(stderr, "Failed to set direction!\n");
    	return(-1);
    }
 
    close(fd);
    return(0);     
}

int UIDRPiGPIO::Read(int pin)
{
    char path[VALUE_MAX];
    char value_str[3];
    int fd;
 
    snprintf(path, VALUE_MAX, "/sys/class/gpio/gpio%d/value", pin);
    fd = open(path, O_RDONLY);
    if (-1 == fd) {
    	fprintf(stderr, "Failed to open gpio value for reading!\n");
    	return(-1);
    }
 
    if (-1 == read(fd, value_str, 3)) {
    	fprintf(stderr, "Failed to read value!\n");
    	return(-1);
    }
 
    close(fd);
 
    return(atoi(value_str));    
}

int UIDRPiGPIO::Write(int pin, int value)
{
    static const char s_values_str[] = "01";
 
    char path[VALUE_MAX];
    int fd;
 
    snprintf(path, VALUE_MAX, "/sys/class/gpio/gpio%d/value", pin);
    fd = open(path, O_WRONLY);
    if (-1 == fd) {
    	fprintf(stderr, "Failed to open gpio value for writing!\n");
    	return(-1);
    }
 
    if (1 != write(fd, &s_values_str[LOW == value ? 0 : 1], 1)) {
    	fprintf(stderr, "Failed to write value!\n");
    	return(-1);
    }
 
    close(fd);
    return(0);
}

UIDBerryClip::UIDBerryClip()
{
    temp = new UIDRPiGPIO();

    temp->Export(LED1);
    temp->Export(LED2);
    temp->Export(LED3);
    temp->Export(LED4);
    temp->Export(LED5);
    temp->Export(LED6);
    temp->Export(BUZZER);
    temp->Export(SWITCH);

    sleep(1);

    temp->Direction(LED1,OUT);
    temp->Direction(LED2,OUT);
    temp->Direction(LED3,OUT);
    temp->Direction(LED4,OUT);
    temp->Direction(LED5,OUT);
    temp->Direction(LED6,OUT);
    temp->Direction(BUZZER,OUT);
    temp->Direction(SWITCH,IN);

    sleep(1);
}

UIDBerryClip::~UIDBerryClip()
{
    temp->Write(LED1,LOW);
    temp->Write(LED2,LOW);
    temp->Write(LED3,LOW);
    temp->Write(LED4,LOW);
    temp->Write(LED5,LOW);
    temp->Write(LED6,LOW);
    temp->Write(BUZZER,LOW);

    sleep(1);

    temp->Unexport(LED1);
    temp->Unexport(LED2);
    temp->Unexport(LED3);
    temp->Unexport(LED4);
    temp->Unexport(LED5);
    temp->Unexport(LED6);
    temp->Unexport(BUZZER);
    temp->Unexport(SWITCH);

    sleep(1);

    delete temp;
}

int UIDBerryClip::TurnOn(int pin)
{
    if(temp->Write(pin, HIGH)) {
	return -1;
    } else {
        return 0;
    } 
}

int UIDBerryClip::TurnOff(int pin)
{
    if(temp->Write(pin, LOW)) {
        return -1;
    } else {
        return 0;
    }
}

int UIDBerryClip::Status(int pin)
{
    int status;

    if((status = temp->Read(pin)) == -1) {
        return -1;
    } else {
        return status;
    }
}
