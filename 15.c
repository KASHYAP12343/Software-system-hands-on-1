
/*
============================================================================
Name : 15.c
Author :  KASHYAP DHAMELIYA
Roll No : MT2025063
Description : 15. Write a program to display the environmental variable of the user (use environ).
Date: 24th Aug, 2025.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>

extern char **environ;

int main() {
    int i = 0;
    while (environ[i] != NULL) {
        printf("%s\n", environ[i]);
        i++;
    }
    return 0;
}
/*./a.out
SHELL=/bin/bash
SESSION_MANAGER=local/kashyapd-HP-Pavilion-Gaming-Laptop-15-ec1xxx:@/tmp/.ICE-unix/2372,unix/kashyapd-HP-Pavilion-Gaming-Laptop-15-ec1xxx:/tmp/.ICE-unix/2372
QT_ACCESSIBILITY=1
COLORTERM=truecolor
XDG_CONFIG_DIRS=/etc/xdg/xdg-ubuntu:/etc/xdg
XDG_MENU_PREFIX=gnome-
GNOME_DESKTOP_SESSION_ID=this-is-deprecated
GNOME_SHELL_SESSION_MODE=ubuntu
SSH_AUTH_SOCK=/run/user/1000/keyring/ssh
MEMORY_PRESSURE_WRITE=c29tZSAyMDAwMDAgMjAwMDAwMAA=
XMODIFIERS=@im=ibus
DESKTOP_SESSION=ubuntu
GTK_MODULES=gail:atk-bridge
PWD=/home/kashyapd/kashyap
LOGNAME=kashyapd
XDG_SESSION_DESKTOP=ubuntu
XDG_SESSION_TYPE=wayland
SYSTEMD_EXEC_PID=2406
XAUTHORITY=/run/user/1000/.mutter-Xwaylandauth.ACVCC3
HOME=/home/kashyapd
USERNAME=kashyapd
*/
