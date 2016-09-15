#!/usr/bin/python
 
import asyncore
import socket
import select
import subprocess
import os
import time
 
gpio.pinMode(7, 'out')
gpio.pinMode(8, 'out')
gpio.pinMode(9, 'out')
gpio.pinMode(10, 'out')

 
class Client(asyncore.dispatcher_with_send):
    def __init__(self, socket=None, pollster=None):
        asyncore.dispatcher_with_send.__init__(self, socket)
        self.data = ''
        if pollster:
            self.pollster = pollster
            pollster.register(self, select.EPOLLIN)
    def handle_close(self):
        if self.pollster:
            self.pollster.unregister(self)
    def handle_read(self):
        receivedData = self.recv(8192)
        if not receivedData:
            self.close()
            return
        receivedData = self.data + receivedData
        while '\n' in receivedData:
            line, receivedData = receivedData.split('\n',1)
            self.handle_command(line)
			self.data = receivedData
			self.close()
		
		
		
    def handle_command(self, line):
	
		switch (line){
		case "FORWARD";
			gpio.digitalWrite(7,1)
			time.sleep(.25)
			gpio.digitalWrite(7,0)
		break;
		case "BACKWARD":
			gpio.digitalWrite(8,1)
			time.sleep(.25)
			gpio.digitalWrite(8,0)
		break;
		case "LEFT":
			gpio.digitalWrite(9,1)
			time.sleep(.25)
			gpio.digitalWrite(9,0)
		break;
		case "RIGHT":
			gpio.digitalWrite(10,1)
			time.sleep(.25)
			gpio.digitalWrite(10,0)
		break;
		case "STOP":
		default:
				gpio.digitalWrite(7,0)
				gpio.digitalWrite(8,0)
				gpio.digitalWrite(9,0)
				gpio.digitalWrite(10,0)
		break;
	
	}	
			
			
			
			
class Server(asyncore.dispatcher):
    def __init__(self, listen_to, pollster):
        asyncore.dispatcher.__init__(self)
        self.pollster = pollster
        self.create_socket(socket.AF_INET, socket.SOCK_STREAM)
        self.bind(listen_to)
        self.listen(5)
    def handle_accept(self):
        newSocket, address = self.accept()
        print "Connected from", address
        Client(newSocket,self.pollster)
def readwrite(obj, flags):
    try:
        if flags & select.EPOLLIN:
            obj.handle_read_event()
        if flags & select.EPOLLOUT:
            obj.handle_write_event()
        if flags & select.EPOLLPRI:
            obj.handle_expt_event()
        if flags & (select.EPOLLHUP | select.EPOLLERR | select.POLLNVAL):
            obj.handle_close()
    except socket.error, e:
        if e.args[0] not in asyncore._DISCONNECTED:
            obj.handle_error()
        else:
            obj.handle_close()
    except asyncore._reraised_exceptions:
        raise
    except:
        obj.handle_error()
class EPoll(object):
    def __init__(self):
        self.epoll = select.epoll()
        self.fdmap = {}
    def register(self, obj, flags):
        fd = obj.fileno()
        self.epoll.register(fd, flags)
        self.fdmap[fd] = obj
    def unregister(self, obj):
        fd = obj.fileno()
        del self.fdmap[fd]
        self.epoll.unregister(fd)
    def poll(self):
        evt = self.epoll.poll()
        for fd, flags in evt:
            yield self.fdmap[fd], flags
if __name__ == "__main__":
    pollster = EPoll()
    pollster.register(Server(("",54321),pollster), select.EPOLLIN)
    while True:
        evt = pollster.poll()
        for obj, flags in evt:
            readwrite(obj, flags)
