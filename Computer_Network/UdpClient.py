from socket import *
import time
serverName = '192.168.123.87'
serverPort = 12000
clientSocket = socket(AF_INET, SOCK_DGRAM)
message = input('Input lower case sentence:')
while True:
    clientSocket.sendto(bytes(message.encode('utf-8')),(serverName,serverPort))
    time.sleep(1)
    modifiedMessage, serverAddress = clientSocket.recvfrom(2048)
    print(modifiedMessage.decode('utf-8'))
clientSocket.close()
