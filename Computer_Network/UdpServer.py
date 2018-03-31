from socket import *
serverPort = 12000
serverSocket = socket(AF_INET, SOCK_DGRAM)
serverSocket.bind(('',serverPort))
print('server ready')
while True:
	message, clientAddress = serverSocket.recvfrom(2048)
	modifiedMessage = message.decode('utf-8').upper()
	print(str(modifiedMessage))
	serverSocket.sendto(bytes(modifiedMessage.encode('utf-8')),clientAddress)
	