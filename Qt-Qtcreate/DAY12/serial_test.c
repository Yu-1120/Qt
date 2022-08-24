#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <termios.h>

int serial_fd;
struct termios old_cfg;
struct termios new_cfg;


//调试串口初始化
void uart0_init()
{
	//1.打开串口设备文件
	serial_fd = open("/dev/ttySAC0",O_RDWR|O_NOCTTY);
	if(serial_fd==-1){
		perror("open");
		exit(-1);
	}
	
	//2.备份现有的串口配置
	if(-1==tcgetattr(serial_fd,&old_cfg)){
		perror("tcgetattr");
		exit(-1);
	}
	
	//3.原始模式
	new_cfg = old_cfg;
	cfmakeraw(&new_cfg);
	
	//4.配置波特率
	cfsetispeed(&new_cfg,B115200);
	cfsetospeed(&new_cfg,B115200);
	
	//5.设置控制标志
	new_cfg.c_cflag |= CREAD|CLOCAL;//使能数据接收和本地模式
	
	//6.设置帧结构
	new_cfg.c_cflag &= ~CSTOPB;//1位停止位
	new_cfg.c_cflag &= ~CSIZE;//去掉数据位屏蔽
	new_cfg.c_cflag |= CS8;//8位数据位
	new_cfg.c_cflag &= ~PARENB;//无校验	
	
	//7.设置阻塞模式
	tcflush(serial_fd,TCIOFLUSH);
	//收到1字节解除阻塞
	new_cfg.c_cc[VTIME] = 0;
	new_cfg.c_cc[VMIN] = 1;
	tcflush(serial_fd,TCIOFLUSH);
	
	//8.使能配置生效
	if(-1==tcsetattr(serial_fd,TCSANOW,&new_cfg)){
		perror("tcgetattr");
		exit(-1);
	}
}

int main()
{
	uart0_init();
	
	int i = 0;
	while(i<20){
		write(serial_fd,"A",1);
		sleep(1);
		i++;
	}
	
	//恢复配置
	if(-1==tcsetattr(serial_fd,TCSANOW,&old_cfg)){
		perror("tcgetattr");
		exit(-1);
	}
	
	close(serial_fd);
	return 0;
}
